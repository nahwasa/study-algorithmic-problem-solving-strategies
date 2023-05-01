import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int t = Integer.parseInt(br.readLine());
        while (t-->0) new Main().solution();
        System.out.print(sb);
    }

    int n, m, answer;
    List<Integer>[] eat, eatBy;
    int[] v;

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        answer = m;

        Map<String, Integer> nameToIdx = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nameToIdx.put(st.nextToken(), i);
        }

        eat = new List[n];
        eatBy = new List[m];
        for (int i = 0; i < n; i++) eat[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) eatBy[i] = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            while (cnt-->0) {
                String cur = st.nextToken();
                eat[nameToIdx.get(cur)].add(i);
                eatBy[i].add(nameToIdx.get(cur));
            }
        }

        v = new int[n];
        search(0);
        sb.append(answer).append('\n');
    }

    private void search(int cnt) {
        if (answer <= cnt) return;

        int idx = 0;
        for (; idx < n; idx++) {
            if (v[idx] == 0) break;
        }

        if (idx == n) {
            answer = cnt;
            return;
        }

        for (int foodNum : eat[idx]) {
            for (int friendNum : eatBy[foodNum]) v[friendNum]++;

            search(cnt + 1);

            for (int friendNum : eatBy[foodNum]) v[friendNum]--;
        }
    }
}
