import java.util.Scanner;

public class Main {
	
	public static int[] arr;
	public static int N;
	public static int count = 0;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N];
		
		nQueen(0);
		System.out.println(count);

	}//main
	
	public static void nQueen(int depth) {
		//모든 원소를 다 채운 상태면 count 증가 및 return
		if(depth == N) {
			count++;
			return;
		}
		
		for(int i=0; i<N; i++) {
			arr[depth] = i;
			//놓을 수 있는 위치일 경우 재귀호출
			if(Possibility(depth)) {
				nQueen(depth+1);
			}
		}
		
	}
	
	public static boolean Possibility(int col) {
		
		for(int i=0; i<col; i++) {
			//해당 열의 행과 i열의 행이 일치할 경우 (같은 행에 존재할 경우)
			if(arr[col] == arr[i]) {
				return false;
			}
			
			/*
			 * 대각선 상에 놓여 있는 경우
			 * (열의 차와 행의 차가 같을 경우가 대각선에 놓여있는 경우다)
			 */
			else if(Math.abs(col-i) == Math.abs(arr[col]-arr[i])) {
				return false;
			}
		}
		
		return true;
	}

}//end class

////행을 다 채우면 카운트를 1 증가시키고 리턴시킨다.
//		if(depth == N) {
//			count ++;
//			return;
//		}
//		
//		for(int i=0; i<N; i++) {
//			arr[depth] = i;
//			
//			//Possibility() 해당 열에서 i번째 행에 놓을 수 있는 지를 검사하는 함수
//			if(Possibility(depth)) {
//				nQueen(depth+1);
//			}
//		}
