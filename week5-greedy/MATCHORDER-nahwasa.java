import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine().trim());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        TreeSet<Integer> korean = new TreeSet<>();
        int[] cnt = new int[4001];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int cur = Integer.parseInt(st.nextToken());
            cnt[cur]++;
            korean.add(cur);
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            Integer matching = korean.ceiling(arr[i]);
            if (matching != null) answer++;
            else matching = korean.ceiling(0);

            if (--cnt[matching] == 0)
                korean.remove(matching);
        }

        sb.append(answer).append('\n');
    }
}
