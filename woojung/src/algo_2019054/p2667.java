package algo_2019054;
import java.util.Arrays;
import java.util.Scanner;

/**
 * 
 * @author wj.kim
 * 알고리즘: DFS
 * 단지번호 붙이기 
 * 
 */
public class p2667 {
	
	static int N;
	static int[][] map;
	static int[][] visited;
	static int[] cntList;
	static int[] cntResult;
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,-1,0,1};
	static int cnt;
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		map=new int[N+2][N+2];
		visited=new int[N+2][N+2];
		cntList=new int[1000];
		cnt=0;
		for(int i=1;i<N+1;i++) {
			String line=sc.next();
			for(int j=0;j<N;j++) {
				map[i][j+1]=line.charAt(j)-'0';
			}
		}

		for(int i=1;i<N+1;i++) {
			for(int j=1;j<N+1;j++) {
				if(map[i][j]==1&&visited[i][j]==0) {
					cnt+=1;
					dfs(i,j,cnt);
				}
			
			}
		}
		cntResult=new int[cnt+1];
		System.out.println(cnt);
		for(int i=1;i<=cnt;i++) {
			cntResult[i]=cntList[i];
		}
		Arrays.sort(cntResult);
		for(int i=1;i<=cnt;i++) {
			System.out.println(cntResult[i]);
		}
		
		sc.close();
	
	}

	public static void dfs(int row, int col,int cnt ) {
		
		visited[row][col]=1;
		cntList[cnt]+=1;
		for(int i=0;i<4;i++) {
			int rrow=row+dx[i];
			int ccol=col+dy[i];
			if(rrow>0&&ccol>0&&rrow<N+1&&ccol<N+1&&map[rrow][ccol]==1&&visited[rrow][ccol]==0) {
				dfs(rrow,ccol,cnt);
			}
		}
		
		
	}

}
