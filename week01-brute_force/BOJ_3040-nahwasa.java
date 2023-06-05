import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final int N = 9;

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    public void solution() throws Exception {
        int[] arr = new int[N];
        int sum = 0;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            sum += arr[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || sum - arr[i] - arr[j] != 100) continue;

                printAnswer(arr, i, j);
                return;
            }
        }
    }

    private void printAnswer(final int[] arr, final int i, final int j) {
        StringBuilder sb = new StringBuilder();
        for (int k = 0; k < N; k++) {
            if (k == i || k == j) continue;
            sb.append(arr[k]).append('\n');
        }
        System.out.print(sb);
    }
}
