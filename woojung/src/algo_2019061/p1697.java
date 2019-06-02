package algo_2019061;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 2019-06-01
 * @author wj.kim
 * 알고리즘: BFS
 * 숨바꼭질
 *
 */
public class p1697 {

	static final int MAX=100000;
	static int N;
	static int K;
	static int[] dx= {-1,1,2};
	static int[] visited;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		visited=new int[MAX+1];
		N=sc.nextInt();
		K=sc.nextInt();
		Queue<Integer> qq=new LinkedList<Integer>();
		visited[N]=1;
		qq.add(N);
		qq.add(0);
		
		while(!qq.isEmpty()) {
			int nN=qq.remove();
			int cnt=qq.remove();
			if(nN==K) {
				System.out.println(cnt);	
				break;
			}
			
			for(int i=0;i<3;i++) {
				int nnN;
				if(i==2) nnN=dx[i]*nN;
				else nnN=dx[i]+nN;
				
				if(nnN>=0&&nnN<=MAX&&visited[nnN]!=1) {
					qq.add(nnN);
					qq.add(cnt+1);
					visited[nnN]=1;
				}
				
			}
		}
		sc.close();
	}
	
}
