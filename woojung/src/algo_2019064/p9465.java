package algo_2019064;

import java.util.Scanner;

/**
 * 2019-06-15
 * @author wj_kim
 * 알고리즘: DP
 * 스티커
 *
 */
public class p9465 {
	public static int T;
	public static int N;
	public static int[][] sticker;
	public static int[][] score;
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		T=sc.nextInt();
		for(int i=0;i<T;i++) {
			N=sc.nextInt();
			sticker= new int[3][N+1];
			score= new int[3][N+1];
			for(int j=1;j<=2;j++) {
				for(int k=1;k<=N;k++) {
					sticker[j][k]=sc.nextInt();
				}
			}
			
			for(int j=1;j<=N;j++) {
				score[0][j]=Math.max(score[1][j-1], score[2][j-1])+sticker[0][j];
				score[1][j]=Math.max(score[0][j-1], score[2][j-1])+sticker[1][j];
				score[2][j]=Math.max(score[0][j-1], score[1][j-1])+sticker[2][j];
			}
			System.out.println(Math.max(score[0][N],Math.max(score[1][N], score[2][N])));

		}
		
	}
	

}
