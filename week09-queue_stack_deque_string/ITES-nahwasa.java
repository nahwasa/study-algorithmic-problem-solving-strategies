import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    private static final long MOD = 1L<<32;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine().trim());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        long signal = 1983;
        int cnt = 0;

        Queue<Integer> q = new ArrayDeque<>();
        q.add(inputSignal(signal));
        int sum = q.peek();
        if (sum == k) {
            cnt++;
            sum -= q.poll();
        }

        while (n-->0) {
            signal = nextSignal(signal);
            int inputSignal = inputSignal(signal);
            sum += inputSignal;
            q.add(inputSignal);

            if (sum == k) {
                cnt++;
            }

            while (sum >= k) {
                sum -= q.poll();
                if (sum == k) {
                    cnt++;
                }
            }
        }

        sb.append(cnt).append('\n');
    }

    private long nextSignal(final long signal) {
        long result = signal * 214013 + 2531011;
        result %= MOD;
        return result;
    }

    private int inputSignal(final long signal) {
        return (int) (signal % 10000 + 1);
    }
}
