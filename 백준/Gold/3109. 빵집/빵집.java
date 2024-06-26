import java.util.*;

public class Main {
	static int R,C,cnt;
	static char[][] board;
	static int[] dx = {-1,0,1};
	static int[] dy = {1,1,1};
	static boolean finished;
			
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringTokenizer st = new StringTokenizer(sc.nextLine()," ");
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		board = new char[R][C];
		for (int i = 0; i < R; i++) {
			board[i] = sc.nextLine().toCharArray();
		}
		
        //출발지점에서 각각 DFS(백트래킹)을 실행합니다.
		for (int i = 0; i < R; i++) {
			finished = false;
			board[i][0] = '@'; // 눈으로 변화를 확인하기 위해 넣은 코드입니다. 
			BackT(i,0);

		}
		System.out.println(cnt);
		
	}
	
	public static void BackT(int x, int y) {
		//전체 진행과정을 확인하기 위한 코드입니다.		
		//System.out.println();
		//for (int j = 0; j < board.length; j++) {
		//	System.out.println(Arrays.toString(board[j]));
		//}
		//System.out.println();
		
		if(y == C-1) { // 마지막 행에 도달했다면 경로가 완성된 것입니다.
			finished = true; //해당 출발지에서 도달가능한 경로를 찾았기 때문에
    		// 재귀예정인 탐색을 모두 취소하게 합니다.            
			cnt++;
			return;
		}
		
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i]; //dy값은 다 1이기 때문에 y+1을 해도 상관없습니다.
            // 답이될수 없는 경우의 수는 가지치기(pruning)합니다.
			if(nx<0 || nx>=R || ny>=C || board[nx][ny] == 'x' || board[nx][ny] == '@') continue;
            // 해당 출발지에서 갈 수 있는 최적경로가 등장했다면 더 이상 재귀적인 탐색을 하지 않습니다.
			if(finished) continue;
            // 여기까지 왔다는 건 아직 최적의 경로가 등장하지 않았다는 뜻입니다.
			board[nx][ny] = '@';
			BackT(nx,ny);
		}
		
	}
}