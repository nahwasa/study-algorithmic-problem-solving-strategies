import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

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
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (n-->0) pq.add(Integer.parseInt(st.nextToken()));

        int sum = 0;
        while (pq.size() != 1) {
            int joinCost = pq.poll() + pq.poll();
            sum += joinCost;
            pq.add(joinCost);
        }

        sb.append(sum).append('\n');
    }
}
