import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static int N;
    private static int M;
    private static final int CARD_COUNT = 3;
    private static int max = Integer.MIN_VALUE;

    private static void dfs(int start, int count, int sum, int[] arr) {
        if (count == CARD_COUNT) {
            if (max < sum) {
                max = sum;
            }
            return;
        }

        for (int i = start + 1; i < arr.length; i++) {
            if (sum + arr[i] <= M) {
                dfs(i, count + 1, sum + arr[i], arr);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        int[] arr = new int[N];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < arr.length; i++) {
            dfs(i, 1, arr[i], arr);
        }
        System.out.println(max);
    }
}