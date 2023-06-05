import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    private static final int LIMIT = 8030 * 1000;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        for (int i = 2; i <= n; i++) {
            List<Integer> candidates = new ArrayList<>();
            for (int j = 1; j <= n; j++) {
                candidates.add(j);
            }

            int die = 0;
            while (candidates.size() > 2) {
                if (candidates.remove(die) == i) break;
                die += k-1;
                die %= candidates.size();
            }

            if (candidates.size() != 2) continue;

            sb.append(candidates.get(0)).append(' ').append(candidates.get(1)).append('\n');
            break;
        }
    }
}
