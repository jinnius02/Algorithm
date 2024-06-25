import java.util.Scanner;

public class Main {
	
	static int[] num;
	private static int N; //정수의 개수
	private static int S; //정수의 합
	private static int answer = 0;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt(); //정수의 개수
		S = sc.nextInt(); //정수의 합
		num = new int[N];
		
		
		for(int i=0; i<N; i++) {
			num[i] = sc.nextInt();
		}
		
		dfs(0, 0);
		if (S == 0) {
			System.out.println(answer - 1);
			//S 0일때 전체 합이 0일 때랑 겹치기 때문에 -1을 해주어야 한다.
			//위의 사진에 공집합이 0이라고 볼 수 있다.
		}else {
			System.out.println(answer);
		}
		
	}//main
	
	private static void dfs(int depth, int sum) {
		if(depth == N) {
			if(sum == S) answer++;
			return;
		}
		//tree를 생각해서 직접 그려보면 이해하기가 쉽다.
		dfs(depth+1, sum+num[depth]);
		dfs(depth+1, sum);
	}

}//end class
