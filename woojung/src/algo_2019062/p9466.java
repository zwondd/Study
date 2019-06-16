package algo_2019062;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/**
 * 2019-06-09
 * @author wj_kim
 * 알고리즘: DFS
 * 텀프로젝트
 *
 */

public class p9466 {
	static int T;
	static int N;
	static int[] partner;
	static int[] visited;
	static int[] startStd;
	static int result;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] line = in.readLine().split(" ");
		T=Integer.parseInt(line[0]);
		for(int i=0;i<T;i++) {
			line = in.readLine().split(" ");
			N=Integer.parseInt(line[0]);
			partner=new int[N+1];
			visited=new int[N+1];
			startStd=new int[N+1];
			result=0;
			line = in.readLine().split(" ");
			for(int j=1;j<N+1;j++) {
				partner[j]=Integer.parseInt(line[j-1]);
			}
			
			for(int j=1;j<N+1;j++) {
				//방문하게되면 j가 첫번째 노드 
				if(visited[j]==0)
					result+=dfs(j,j,1);
			}
			
			System.out.println(N-result);
		
		}
	}
	private static int dfs(int j, int firstStd, int cnt) {
		//visited에 cnt 저장
		visited[j]=cnt;
		startStd[j]=firstStd;
		
		//cycle이 끝난경우 
		if(visited[partner[j]]!=0&&startStd[j]==startStd[partner[j]]) {
			return (visited[j]-visited[partner[j]]+1);
		}
		if(visited[partner[j]]==0)
			return dfs(partner[j],firstStd,cnt+1);
		return 0;
	}
	
	
}
