package algo_2019054;
import java.util.Scanner;
/**
 * 
 * @author wj.kim
 * 알고리즘: DFS
 * 바이러스
 * 
 */
public class p2606 {
	static int N;
	static int T;
	static int[][] map;
	static int[] visited;
	static int cnt;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		T=sc.nextInt();
		map= new int[N+1][N+1];
		visited= new int[N+1];
		cnt=-1;
		for(int i=0;i<T;i++) {
			int a= sc.nextInt();
			int b= sc.nextInt();
				map[a][b]=1;
				map[b][a]=1;
		}
		dfs(1);
		System.out.println(cnt);
		sc.close();
	}
	
	public static void dfs(int p) {
		visited[p]=1;
		cnt+=1;
		for(int i=1;i<N+1;i++) {
			if(i!=p&&visited[i]==0&&map[p][i]==1) {
				visited[i]=1;
				dfs(i);	
			}
		}
	}
}
