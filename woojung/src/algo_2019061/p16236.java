package algo_2019061;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p16236 {
	static int N;
	static int[][] map;
	static int skSize; //��� size
	static Queue<Integer> fishQq; //���� ����̵Ǵ� ����� queue
	static int[] dx= {-1,1,0,0};
	static int[] dy= {0,0,-1,1};
	//����� ã�ư��� �� dfs�� ���� queue
	static Queue<Integer> qq=new LinkedList<Integer>();
	static int[][] visited= new int[N+1][N+1];
	static int result=0;
	static Fish shark;
	
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		N=sc.nextInt();
		map=new int[N+1][N+1];
		fishQq= new LinkedList<Integer>();
		skSize=2;
		fishQq= new LinkedList<Integer>();
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				map[i+1][j+1]=sc.nextInt();
				if(map[i+1][j+1]==9) {
					shark= new Fish(i+1,j+1,2);
				}else if(map[i+1][j+1]!=0) {
					new Fish(i+1,j+1,2);
				}
			}
		}
		
		checkFish();
		System.out.println(fishQq.size());
		
		while(!fishQq.isEmpty()) {
			int ccnt=0;
			int fishRow=fishQq.remove();
			int fishCol=fishQq.remove();
			int fishSize=fishQq.remove();
			System.out.println("�߰��� fish "+fishRow+" "+fishCol+" "+fishSize+" ");
			System.out.println("����ġ "+qq.peek()+" "+qq.peek());
			
			ccnt=dfs(fishRow,fishCol);
			System.out.println("cnt"+ccnt);
			result+=ccnt;
			map[fishRow][fishCol]=0;
			qq.add(fishRow);
			qq.add(fishCol);
			qq.add(fishSize);
		}
		System.out.println(result);
		sc.close();
	}
	
	public static int dfs(int fishRow, int fishCol) {
		//�̵� ��ġ X,Y,CNT ����
		int cnt=0;
		while(!qq.isEmpty()) {
			int row=qq.remove();
			int col=qq.remove();
			cnt=qq.remove();
			int rrow;
			int ccol;			
			
			if(row==fishRow&&col==fishCol) {
				qq.clear();
				break;
			}
			
			for(int i=0;i<4;i++) {
				rrow=row+dx[i];
				ccol=col+dy[i];
				//�̵��� �� �ִ� ���̸�, ���� �۰ų� ���� ����Ⱑ ���� �� 
				if(rrow>0&&rrow<=N&&ccol>0&&ccol<=N&&map[rrow][ccol]<=skSize) {
					qq.add(rrow);
					qq.add(ccol);
					qq.add(cnt+1);
				}
			}
		}
		return cnt;
	}
	
	
	// ����� �ϳ� �ٸ��� ������ visited �ʱ�ȭ
	public static void initVisited(int[][] visited ) {
			for(int i=1;i<N+1;i++) {
			for(int j=1;j<N+1;j++) {
				visited[i][j]=0;
			}
	
		}
	}
	
	
	public static void print() {
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<N+1;j++) {
				System.out.print(map[i][j]);
			}
			System.out.println();
		}
	}
	
	//���� �� �ִ� ����� check�ؼ� fish Queue�� ���� (X,Y,���� �������)
	public static void checkFish() {		
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<N+1;j++) {
				if(map[i][j]<skSize&&map[i][j]!=0) {
					fishQq.add(i); 
					fishQq.add(j);
					fishQq.add(map[i][j]); 
				} 
			}
		}
		
	}
	
	
}

class Fish{
	int row;
	int col;
	int size;
	public Fish(int row, int col, int size) {
		super();
		this.row = row;
		this.col = col;
		this.size = size;
	}
	public int getRow() {
		return row;
	}
	public void setRow(int row) {
		this.row = row;
	}
	public int getCol() {
		return col;
	}
	public void setCol(int col) {
		this.col = col;
	}
	public int getSize() {
		return size;
	}
	public void setSize(int size) {
		this.size = size;
	}
	
	
}

