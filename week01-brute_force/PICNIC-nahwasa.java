import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private int n, cnt, v;
    private List<Integer>[] edges;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine().trim());
        Main main = new Main();

        StringBuilder answer = new StringBuilder();
        while (c-- > 0) {
            answer.append(main.solution()).append('\n');
        }
        System.out.print(answer);
    }

    private int solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        init(Integer.parseInt(st.nextToken()));
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            edges[a].add(b);
            edges[b].add(a);
        }

        for (int i = 0; i < n; i++) {
            if (edges[i].isEmpty()) {
                return 0;
            }
        }
        search(0, 0);
        return cnt;
    }

    private void init(int num) {
        n = num;
        edges = new ArrayList[n];
        for (int i = 0; i < n; i++)
            edges[i] = new ArrayList<>();
        cnt = v = 0;
    }

    private void search(int idx, int startIdx) {
        if (idx == n / 2) {
            cnt++;
            return;
        }
        for (int i = startIdx; i < n; i++) {
            if ((v & (1 << i)) != 0) continue;
            v |= 1 << i;
            for (int next : edges[i]) {
                if (next < i) continue;
                if ((v & (1 << next)) != 0) continue;
                v |= 1 << next;
                search(idx + 1, i + 1);
                v ^= 1 << next;
            }
            v ^= 1 << i;
        }
    }
}
