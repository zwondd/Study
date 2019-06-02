package algo_2019061;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p7562 {
	static int T;
	static int N;
	static int startX;
	static int startY;
	static int endX;
	static int endY;
	static int result;
	static int[][] map;
	static int[] dx= {2,1,-2,-1,2,1,-2,-1};
	static int[] dy= {1,2,1,2,-1,-2,-1,-2};
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		T=sc.nextInt();
		for(int i=0;i<T;i++) {
			N=sc.nextInt();
			startX=sc.nextInt();
			startY=sc.nextInt();
			endX=sc.nextInt();
			endY=sc.nextInt();
			map=new int[N][N];
			result=dfs();
			System.out.println(result);
		}
		sc.close();
	}
	
	public static int dfs() {
		Queue<Integer> qq=new LinkedList<Integer>();
		map[startX][startY]=1;
		qq.add(startX);
		qq.add(startY);
		qq.add(0);
		
		while(!qq.isEmpty()) {
			int row=qq.remove();
			int col=qq.remove();
			int cnt=qq.remove();
			if(row==endX&&col==endY) {
				return cnt;
			}
			
			for(int i=0;i<8;i++) {
				int rrow=row+dx[i];
				int ccol=col+dy[i];
				if(rrow>=0&&rrow<N&&ccol>=0&&ccol<N&&map[rrow][ccol]!=1)
				{
					map[rrow][ccol]=1;
					qq.add(rrow);
					qq.add(ccol);
					qq.add(cnt+1);
				}
			}
		}
		return 0;
	}
}






