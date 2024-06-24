import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K =  sc.nextInt();
		int[] numbers = new int[N];
		int ans = 0;
		
		for(int i=0; i<N; i++) {
			numbers[i] = sc.nextInt();
		}
		
		for(int i=N-1; i>=0; i--) {
			if(K/numbers[i] >= 1) {
				ans += K/numbers[i];
				K = K%numbers[i];
			}
		}
		System.out.println(ans);

	}//main

}//end class
