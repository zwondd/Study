package algo_2019061;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * 2019-06-02
 * @author wj_kim
 * 알고리즘: BFS
 * 스타트링크
 *
 */
public class p5014 {
	static final int MAX=1000000;
	static int F;
	static int S;
	static int G;
	static int U;
	static int D;
	static int visited[];
	static boolean flag;

	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		F=sc.nextInt();
		S=sc.nextInt();
		G=sc.nextInt();
		U=sc.nextInt();
		D=sc.nextInt();
		visited=new int[MAX+1];
		flag=false;
		
		Queue<Integer> qq=new LinkedList<Integer>();
		qq.add(S);
		qq.add(0);
		visited[S]=1;
		while(!qq.isEmpty()) {
			int stair= qq.remove();
			int cnt=qq.remove();
			
			if(stair==G) {
				System.out.println(cnt);
				flag=true;
				break;
			}
			
			int nStair;
		
			for(int i=0;i<2;i++) {
				if(i==0) {
					nStair=stair+U;
				}
				else {
					nStair=stair-D;
				}
				if(nStair>0&&nStair<=F&&visited[nStair]==0) {
					qq.add(nStair);
					qq.add(cnt+1);
					visited[nStair]=1;
				}
			}
		}
		
		if(flag==false) System.out.println("use the stairs");
	}

	
	
	
	
	
	
	
	
}
