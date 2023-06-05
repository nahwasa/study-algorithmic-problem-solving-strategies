import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static final int MOD = 1000000007;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        if (n <= 2) {
            sb.append(0).append('\n');
            return;
        }

        int[] arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;

        for (int i = 3; i <= n; i++) {
            arr[i] = (arr[i-2] + arr[i-1]) % MOD;
        }

        long answer = arr[n];
        if ((n%2==0)) {
            answer -= arr[n/2] + arr[n/2-1];
            answer += 2*MOD;
        } else {
            answer -= arr[(n-1)/2];
            answer += MOD;
        }

        answer%=MOD;

        sb.append(answer).append( '\n');
    }
}
