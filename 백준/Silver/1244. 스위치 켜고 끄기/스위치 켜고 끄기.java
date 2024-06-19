import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
	  int N = scan.nextInt();//스위치 개수      
//      int[] switchArry = new int[N];   
      int[] switchArry = new int[N+1];//스위치정보를 담을 배열   
	  //입력되는 스위치 정보가 1부터 사용되기 때문에  
	  // ==> 배열의 0번지를 버림으로써  입력값과 배열번지를 일치시켜준다!!
      
//      for (int i = 0; i < N; i++) {
      for (int i = 1; i <= N; i++) {
		  switchArry[i] = scan.nextInt();//스위치정보 입력		
	  }

      //데이터 입력 확인
//      System.out.println(Arrays.toString(switchArry));

	  int stuNum = scan.nextInt();//학생수
	  
	  for(int i=0; i<stuNum; i++) {//학생수만큼 반복
		  int gender = scan.nextInt();//학생의 성별
		  int startNum = scan.nextInt();//스위치 시작번호
		  
		  if(gender==1) {//남학생 : 시작번호를 기준해서 배수를 스위치
			  for(int j=startNum; j<=N; j+=startNum) {//j++  j=j+1
				                     //j+=startNum  j=j+startNum
				 if(switchArry[j]==0) //현재 스위치 값이 0이라면
				  switchArry[j]=1;
				 else
				  switchArry[j]=0;
				  
			  }
		  }else {//여학생: 시작번호를 기준해서 (좌우)대칭되는 가장 가까운 수부터 스위치, 비대칭 전까지
			  //좌우 비교할 길이가 다를 수 있으므로 최소 비교 길이를 구하자!!
			  int limit=startNum;
			  if(N-startNum+1  < startNum) {
				  limit = N-startNum+1;
			  }					  

			  //1.선택된 스위치는 무조건 변경
			  if(switchArry[startNum] == 0) switchArry[startNum] = 1;
			  else switchArry[startNum] = 0;
			  
			  for(int j=0,left=startNum-1,  right=startNum+1;  
					  j<limit-1;  
					  j++, left--, right++) {
				  //반복횟수j, 좌우인덱스 left,right
				  // 왼쪽으로 진행형대칭 left,  오른쪽으로 진행형대칭 right,  전체비교횟수 j
				  
				  if(switchArry[left] != switchArry[right]) break; //좌우 대칭이지 않다면 종료
				  
				  if(switchArry[left] == 0) switchArry[left] = 1;
				  else switchArry[left] = 0;
				  
				  if(switchArry[right] == 0) switchArry[right] = 1;
				  else switchArry[right] = 0;
				  
			  }
		  }//여학생 스위치
		  
		  
		  
	  }//for
	  
	  //스위칭 결과를 출력
	  for(int i=1; i<=N; i++) {//스위치 인덱스 표현
		  System.out.print(switchArry[i]+" ");
//		  if(i==20)System.out.println();//줄바꿈
//		  if(i==40)System.out.println();//줄바꿈
//		  if(i==60)System.out.println();//줄바꿈
		  if(i%20==0)System.out.println();//줄바꿈
	  }
      scan.close();
	}//main

}//end class