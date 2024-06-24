import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static int K;
	static int[] dp;
	static int[] coin;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		K = sc.nextInt();
		coin = new int[N];
		dp = new int[K+1];
		Arrays.fill(dp, 100001); //배열 초기화, 배열 채우기
		
		for(int testCase=0; testCase<N; testCase++) {
			coin[testCase] = sc.nextInt();
		}
		
		solve();

	}//main
	
	public static void solve() {
		
		dp[0] = 0;
		
		for(int index=0; index<coin.length; index++) {
			for(int i=coin[index]; i<=K; i++) {
				dp[i] = Math.min(dp[i], dp[i-coin[index]]+1);
			}
		}
		
		if(dp[K] == 100001) {
			dp[K] = -1;
		}
		
		System.out.println(dp[K]);
	}
}//end class
