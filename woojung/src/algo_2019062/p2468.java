package algo_2019062;


import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * 2019-06-02
 * @author wj_kim
 * 알고리즘: DFS
 * 안전영역
 *
 */
public class p2468 {
	static int N;
	static int[][] map;
	static int[][] visited;
	static int maxResult=1;
	static int max=1;
	static int min=100;
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,-1,0,1};
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		map=new int[N+1][N+1];
		visited=new int[N+1][N+1];
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<N+1;j++) {
				map[i][j]= sc.nextInt();
				if(map[i][j]>max) max=map[i][j];
				if(map[i][j]<min) min=map[i][j];
			}	
		}
		
		for(int i=min;i<=max;i++) {
			init();
			int cnt=0;
			for(int j=1;j<N+1;j++) {
				for(int z=1;z<N+1;z++) {
					if(visited[j][z]==0&&map[j][z]>i) {
						dfs(j,z,i);
						cnt++;
					}
				}
			}
			if(maxResult<cnt) maxResult=cnt;
		}
	System.out.println(maxResult);
	}

	
	private static void init() {
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<N+1;j++) {
				visited[i][j]= 0;
			}	
		}
		
	}


	private static void dfs(int row, int col, int height) {
		visited[row][col]=1;
		for(int i=0;i<4;i++) {
			int rrow=row+dx[i];
			int ccol=col+dy[i];
			if(rrow>0&&ccol>0&&rrow<N+1&&ccol<N+1&&map[rrow][ccol]>height&&visited[rrow][ccol]==0) {
				dfs(rrow,ccol,height);
			}
		}
		
	}

}
