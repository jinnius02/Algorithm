import java.util.Scanner;

public class Main {
   public static void main(String[] args) {
	  Scanner sc = new Scanner(System.in);
	  int N=sc.nextInt();//색종이의 장수
	  
	  int[][]map= new int[1001][1001];//색종이가 놓일 평면 
	  
	  //데이터 입력
//	  for(int k=0; k<N; k++) {//색종이의 수만큼
	  for(int k=1; k<=N; k++) {//색종이의 수만큼 (색종이 번호를 표현)
		  int col= sc.nextInt(); //열 인덱스 시작점
		  int row= sc.nextInt(); //행 인덱스 시작점
		  int width= sc.nextInt(); //너비 (열과 관계)
		  int height= sc.nextInt();//높이 (행과 관계)
		  
		  //색종이 번호를 배열에 출력
		  for(int i=row; i<row+height; i++) {//행인덱스
			  for(int j=col; j<col+width; j++) {//열인덱스
				  map[i][j]= k;  //색종이 번호를 출력
			  }
		  }
	  }
	  
	  //색종이 번호를 카운트 ==> 1차원 배열의 인덱스 번호를 사용해서 풀이
	  int []cnt = new int[N+1]; //0번지 버림!!(0번 색종이가 없으므로)
	  for (int i = 0; i < 1001; i++) {
		 for (int j = 0; j < 1001; j++) {
		   	 if(map[i][j]>0) //색종이에 대해서만 카운트
		      cnt[  map[i][j]    ]++;
		 }
	  }
	  
      //카운트 된 색종이의 값을 출력 ==> 각 색종이의 면적을 출력
	  for (int i = 1; i <= N; i++) {
		  System.out.println(cnt[i]);
	  }
	  
	  
	  sc.close();
   }//main
}