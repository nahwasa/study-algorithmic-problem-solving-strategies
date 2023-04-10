import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());

        boolean[][] edges = new boolean[n][n];
        int[] edgeCnt = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                if (st.nextToken().charAt(0) == '0') continue;

                edgeCnt[i]++;
                edges[i][j] = edges[j][i] = true;
            }
        }

        double[] percentage = new double[n];
        percentage[p] = 1d;

        while (d-->0) {
            double[] tmp = new double[n];
            for (int i = 0; i < n; i++) {
                if (percentage[i] == 0) continue;

                for (int to = 0; to < n; to++) {
                    if (!edges[i][to]) continue;

                    tmp[to] += percentage[i] / edgeCnt[i];
                }
            }
            percentage = tmp;
        }

        int t = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        while (t-->0) {
            int q = Integer.parseInt(st.nextToken());
            sb.append(percentage[q]).append(' ');
        }
        sb.append('\n');
    }
}
