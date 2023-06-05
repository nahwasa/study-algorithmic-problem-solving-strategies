import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        TreeMap<Integer, Integer> candidates = new TreeMap<>();
        int answer = 0;

        while (n-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());

            if (!putAvailable(candidates, p, q)) {
                answer += candidates.size();
                continue;
            }

            candidates.put(p, q);
            removeNotNerd(candidates, p, q);
            answer += candidates.size();
        }

        sb.append(answer).append('\n');
    }

    private boolean putAvailable(final TreeMap<Integer, Integer> candidates, final int p, final int q) {
        Entry<Integer, Integer> entry = candidates.higherEntry(p);
        if (entry == null)
            return true;

        return q > entry.getValue();
    }

    private void removeNotNerd(final TreeMap<Integer, Integer> candidates, final int p, final int q) {
        int pt = p;

        while (true) {
            Entry<Integer, Integer> entry = candidates.lowerEntry(pt);
            if (entry == null) break;
            if (entry.getValue() < q) {
                candidates.remove(entry.getKey());
                pt = entry.getKey();
                continue;
            }

            break;
        }
    }
}
