package algo_2019061;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 2019-06-01
 * @author wj.kim
 * 알고리즘: BFS
 * 미로탐색 
 * 
 */
public class p2178 {
	static int N;
	static int M;
	static int[][] map;
	static int[] dx= {-1,1,0,0};
	static int[] dy= {0,0,-1,1};
	static int result;
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		map=new int[N+1][M+1];
		for(int i=1;i<N+1;i++) {
			String line=sc.next();
			for(int j=0;j<M;j++) {
				map[i][j+1]=line.charAt(j)-'0';
			}
		}
		
		result=bfs();
		System.out.println(result);
		
		sc.close();
	}
	
	private static int bfs() {
		int row=1;
		int col=1;
		int cnt=1;
		Queue<Integer> qq=new LinkedList<Integer>();
		qq.add(row);
		qq.add(col);
		qq.add(cnt);
		
		while(!qq.isEmpty()) {
			row=qq.remove();
			col=qq.remove();
			cnt=qq.remove();
			
			if(row==N&&col==M) {
				return cnt;
			}
			
			for(int i=0;i<4;i++) {
				int rrow=row+dx[i];
				int ccol=col+dy[i];
				
				if(rrow>0&&rrow<N+1&&ccol>0&&ccol<M+1&&map[rrow][ccol]==1) {
					map[rrow][ccol]=2;
					qq.add(rrow);
					qq.add(ccol);
					qq.add(cnt+1);
				}
			}
		}
		
		return 0;
	}

	public static void print() {
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<M+1;j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}

}
