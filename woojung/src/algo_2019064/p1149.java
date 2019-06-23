package algo_2019064;

import java.util.Scanner;

/**
 * 2019-06-15
 * @author wj_kim
 * 알고리즘: DP
 * RGB거리
 *
 */
public class p1149 {
	static int houseCnt;
	static int[][] cost;
	static int[][] d;
	static int minVal=1000;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		houseCnt=sc.nextInt();
		cost= new int [houseCnt+1][4];
		d= new int [houseCnt+1][4];
		for(int i=1;i<=houseCnt;i++) {
			for(int j=1;j<=3;j++){
				d[i][j]=sc.nextInt();
			}	
		}

		for(int i=1;i<=houseCnt;i++) {
			cost[i][1]=Math.min(cost[i-1][2], cost[i-1][3])+d[i][1];
			cost[i][2]=Math.min(cost[i-1][1], cost[i-1][3])+d[i][2];
			cost[i][3]=Math.min(cost[i-1][1], cost[i-1][2])+d[i][3];
		}
	
		System.out.println(Math.min(Math.min(cost[houseCnt][1], cost[houseCnt][2]),cost[houseCnt][3]));

}

}
