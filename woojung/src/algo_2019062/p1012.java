package algo_2019062;

import java.util.Scanner;

/**
 * 2019-06-02
 * @author wj_kim
 * 알고리즘: DFS
 * 유기농배추
 *
 */
public class p1012 {
	static int T;
	static int M;//가로
	static int N;//세로
	static int K;//벌레 개수
	static int[][] map;
	static int[][] visited;
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,-1,0,1};
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		T=sc.nextInt();
		for(int i=0;i<T;i++) {
			M=sc.nextInt();
			N=sc.nextInt();
			K=sc.nextInt();
			map= new int[M][N];
			visited= new int[M][N];
			int result=0;
			
			for(int j=0;j<K;j++) {
				map[sc.nextInt()][sc.nextInt()]=1;
			}
			
			for(int j=0;j<M;j++) {
				for(int z=0;z<N;z++) {
					if(map[j][z]==1&&visited[j][z]==0) {
						dfs(j,z);
						result+=1;
					}
				}
			}
			System.out.println(result);

	}
		sc.close();
	}
	
	private static void dfs(int row, int col) {
		visited[row][col]=1;
		
		for(int i=0;i<4;i++) {
			int rrow=row+dx[i];
			int ccol=col+dy[i];
			if(rrow>=0&&ccol>=0&&rrow<M&&ccol<N&&map[rrow][ccol]==1&&visited[rrow][ccol]==0) {
				dfs(rrow,ccol);
			}
		}
		
	}


}
