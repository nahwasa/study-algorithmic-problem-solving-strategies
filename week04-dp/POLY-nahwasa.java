import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static final long MOD = 10000000;
    long[][] memoization;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        memoization = new long[n+1][n+1];
        long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += bf(n-i, i);
        }
        sb.append(sum%MOD).append('\n');
    }

    private long bf(int remain, int bf) {
        if (memoization[remain][bf] != 0) {
            return memoization[remain][bf];
        }

        if (remain == 0) {
            return 1;
        }

        long result = 0l;
        for (int i = 1; i <= remain; i++) {
            long tmp = bf+i-1;
            tmp *= bf(remain-i, i);
            tmp %= MOD;
            result += tmp;
            result %= MOD;
        }

        return memoization[remain][bf] = result;
    }
}
