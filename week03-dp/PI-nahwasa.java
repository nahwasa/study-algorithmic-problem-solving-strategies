import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

import static java.lang.Math.min;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static final int INF = Integer.MAX_VALUE;
    int[] number;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine().trim());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        String str = br.readLine().trim();
        number = new int[str.length()+1];
        for (int i = 1; i <= str.length(); i++) {
            number[i] = str.charAt(i-1)-'0';
        }

        int len = str.length();
        int[] dp = new int[len+1];
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for (int i = 3; i <= len; i++) {
            for (int cut = 2; cut <= 4; cut++) {
                if (i-cut < 0 || (i-cut-1 >= 0 && dp[i-cut-1] == INF)) continue;

                dp[i] = min(dp[i], (i-cut-1<0 ? 0 : dp[i-cut-1]) + score(i-cut, i));
            }
        }

        sb.append(dp[len]).append('\n');
    }

    private int score(int from, int to) {
        // rule 1
        for (int i = from+1; i <= to; i++) {
            if (number[i] != number[from]) break;
            if (i == to) return 1;
        }

        // rule 2
        for (int i = from+1; i <= to; i++) {
            if (number[i]-1 != number[i-1]) break;
            if (i == to) return 2;
        }
        for (int i = from+1; i <= to; i++) {
            if (number[i]+1 != number[i-1]) break;
            if (i == to) return 2;
        }

        // rule 3
        for (int i = from+2; i <= to; i++) {
            if (number[i] != number[i-2]) break;
            if (i == to) return 4;
        }

        // rule 4
        int gap = number[from+1] - number[from];
        for (int i = from+2; i <= to; i++) {
            if (number[i]-gap != number[i-1]) break;
            if (i == to) return 5;
        }

        // rule 5
        return 10;
    }
}
