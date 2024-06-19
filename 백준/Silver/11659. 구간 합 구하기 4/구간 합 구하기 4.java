import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(System.in);
		
		//수의 개수 N과 합을 구해야 하는 횟수 M 입력 받기
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] Arr = new int[N+1]; //N+1개의 숫자 배열
		int[] Arr2 = new int[N+1]; // N+1의 누적합 배열
		int[] Sum = new int[M]; //M개의 구간합 배열 저장
		int result = 0; //구간합
		
		// 수 N개 입력
		for(int i=1; i<=N; i++) {
			Arr[i] = sc.nextInt();
			Arr2[i] = Arr2[i-1] + Arr[i];
		}
		
		//합을 구해야 하는 구간 입력
		for(int i=0; i<M; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			//구간합 구하기
//			for(int j=a; j<=b; j++) {
//				result += Arr[j];
//			}
			
			//누적합 구하기
			result = Arr2[b] - Arr2[a-1];
			
			//Sum 배열에 구간합 저장
			Sum[i] = result;
			result = 0;
		}
		//구간합 출력(구간합을 저장한 Sum 배열 출력)
		for(int i=0; i<M; i++) {
			System.out.println(Sum[i]);
		}
		sc.close();
	}//main

}//end class
