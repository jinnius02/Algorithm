import java.util.Scanner;

public class Main {
	static int n,s,b;
	static int[][] a;
	static int ans=Integer.MAX_VALUE;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		a=new int[n][2];
		for (int i = 0; i <n; i++) {
			a[i][0]=sc.nextInt();
			a[i][1]=sc.nextInt();
		}
		subset(0,1,0,0);
		System.out.println(ans);
	}
	private static void subset(int cnt,int sour,int bitter,int c) {
		if(cnt==n) {
			if(ans>Math.abs(sour-bitter) && c!=0) {
				ans=Math.abs(sour-bitter);
			}
			return;
		}
	
			subset(cnt+1,sour*a[cnt][0],bitter+a[cnt][1],c+1);
			subset(cnt+1,sour,bitter,c);
		
	}

}