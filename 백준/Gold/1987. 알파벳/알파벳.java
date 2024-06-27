import java.util.Scanner;

public class Main {
	static int max=0;
	public static void Alph(char[][] arr, boolean[] check, int idx, int count){
		
		int x=idx/arr[0].length;
		int y=idx%arr[0].length;
		

			if(max<count) //최장경로 업데이트
				max=count;

		
	
			
			if(x>0  && check[(int)(arr[x-1][y])-65]==false){//위로 갈 수 있는지?
				 check[(int)(arr[x-1][y])-65]=true;
				 Alph(arr,check, idx-arr[0].length, count+1);
				 check[(int)(arr[x-1][y])-65]=false;
			}
			if(y<arr[0].length-1 && check[(int)(arr[x][y+1])-65]==false){//오른쪽으로 갈 수 있는지?
				 check[(int)(arr[x][y+1])-65]=true;
				 Alph(arr,check, idx+1, count+1);
				 check[(int)(arr[x][y+1])-65]=false;
			}
			if(y>0 && check[(int)(arr[x][y-1])-65]==false){//왼쪽으로 갈 수 있는지?
				 check[(int)(arr[x][y-1])-65]=true;
				 Alph(arr,check, idx-1, count+1);
				 check[(int)(arr[x][y-1])-65]=false;
			}
			if(x<arr.length-1 && check[(int)(arr[x+1][y])-65]==false){//아래로 갈 수 있는지?
				 check[(int)(arr[x+1][y])-65]=true;
				 Alph(arr,check, idx+arr[0].length, count+1);
				 check[(int)(arr[x+1][y])-65]=false;
			}
		

	}

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int R=scan.nextInt();
		int C=scan.nextInt();
		scan.nextLine();
		char[][] arr=new char[R][C];
		
		for(int i=0; i<R; i++){
			String line=scan.nextLine();
			for(int j=0; j<C; j++){
				arr[i][j]=line.charAt(j);
			}
		}
		
		boolean[] check=new boolean[26];
		check[(int)(arr[0][0])-65]=true;
		Alph(arr,check, 0, 1);
		System.out.println(max);

	}

}