package algo_2019063;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * 2019-06-15
 * @author wj_kim
 * 알고리즘: 시뮤레이션
 * 미세먼지여 안녕!
 *
 */
public class p17144 {
	static int R;
	static int C;
	static int T;
	static int[][] map;
	static int[][] add;
	static int[] dx= {-1,1,0,0};
	static int[] dy= {0,0,-1,1};
	static int lastCleaner=0;
	static int result=0;
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] line = in.readLine().split(" ");
		R=Integer.parseInt(line[0]);
		C= Integer.parseInt(line[1]);
		T= Integer.parseInt(line[2]);
		map= new int[R+1][C+1];
		add= new int[R+1][C+1];
		for(int i=0;i<R;i++) {
			line = in.readLine().split(" ");
			for(int j=0;j<C;j++) {
				map[i+1][j+1]=Integer.parseInt(line[j]);
				if(map[i+1][j+1]==-1) {
					lastCleaner=i+1;					
				}
					
			}
		}

		for(int i=0;i<T;i++) {
			diffusion();
			airCleaner();
		}
		
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				result+=map[i][j];
			}
		}
		int result2=result+2;
		System.out.println((result2));
	}
	
	public static void diffusion() {
		int difVal=0;
		int rrow=0;
		int ccol=0;
		int cnt=0;
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				//미세먼지 발견시 
				if(map[i][j]>=1) {
					cnt=0;
					difVal=map[i][j]/5;
					for(int z=0;z<4;z++) {
						rrow=i+dx[z];
						ccol=j+dy[z];
						if(rrow>0&&ccol>0&&rrow<=R&&ccol<=C&&map[rrow][ccol]!=-1) {
							add[rrow][ccol]+=difVal;
							cnt++;
						}
					}
					map[i][j]-=difVal*cnt;
				}
			}
		}
		
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				map[i][j]+=add[i][j];
			}
		}
		addInit();
	}
          
	
	
	public static void airCleaner() {
		//[청정기row][마지막 column]값 저장
		int temp[]={map[lastCleaner-1][C],map[lastCleaner][C]};
		//왼 -> 오 
		for(int i=C-1;i>1;i--) {
			map[lastCleaner-1][i+1]=map[lastCleaner-1][i];
			map[lastCleaner][i+1]=map[lastCleaner][i];
		}
		//공기청정기옆 0으로
		map[lastCleaner-1][2]=0;
		map[lastCleaner][2]=0;
		//col=1 아래 ->위
		for(int i=lastCleaner+1;i<R;i++) {
			map[i][1]=map[i+1][1];
		}
		//col=1 위 ->아래
		for(int i=1;i<lastCleaner-2;i++) {
			map[i+1][1]=map[i][1];
		}
		//오 -> 왼
		for(int i=1;i<C;i++) {
			map[1][i]=map[1][i+1];
			map[R][i]=map[R][i+1];
		}
		for(int i=R-1;i>lastCleaner;i--) {
			map[i+1][C]=map[i][C];
		}
		for(int i=lastCleaner-2;i>1;i--) {
			map[i-1][C]=map[i][C];
		}
		map[lastCleaner-2][C]=temp[0];
		map[lastCleaner+1][C]=temp[1];
	}
	
	public static void addInit() {
		for(int i=1;i<=R;i++) {
			Arrays.fill(add[i], 0);
		}
		
	}
	public static void print() {
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}
		
}
