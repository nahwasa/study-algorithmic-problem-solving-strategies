import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private double getAverageFee(int[] prefixSum, int i, int j) {
        int sum = prefixSum[j] - prefixSum[i-1];
        return (double)sum / (j-i+1);
    }
    private void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (c-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int[] prefixSum = new int[n+1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                prefixSum[i] = prefixSum[i-1] + Integer.parseInt(st.nextToken());
            }
            double answer = Double.MAX_VALUE;
            for (int i = 1; i <= n-l+1; i++) {
                for (int j = i+l-1; j <= n; j++) {
                    double curAverage = getAverageFee(prefixSum, i, j);
                    if (answer > curAverage)
                        answer = curAverage;
                }
            }
            sb.append(String.format("%.8f\n", answer));
        }
        System.out.print(sb);
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
