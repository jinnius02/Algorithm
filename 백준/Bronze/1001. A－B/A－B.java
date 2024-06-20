import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception{
		//입력도수 : Scanner, BufferedReader
		//A a = new A (); ==> A클래스의 멤버를 사용할 준비
		  BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //==> A클래스의 멤버를 사용할 준비
		  
		  //입력 데이터 => 1 2
		  String str = br.readLine(); //str = "1 2"
		  
		  StringTokenizer tokens = new StringTokenizer(str, " ");
		                  //tokens=["1", "2"]
		  
		  int su1 = Integer.parseInt(tokens.nextToken()); //Integer.parseInt("1") = > 1
		  int su2 = Integer.parseInt(tokens.nextToken()); //Integer.parseInt("2") = > 2
		  
//		  int su1 = scan.nextInt(); //엔터, 공백, 스페이스를 구분자로 사용 => next 사용
//		  int su2 = scan.nextInt();
//		  
//		  System.out.println(su1+su2);

		  
		  System.out.println(su1 - su2);
		  
		  br.close(); // 입출력 객체 자원 반환

	}//main

}//end class