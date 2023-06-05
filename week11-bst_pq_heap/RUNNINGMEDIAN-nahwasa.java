import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    private static final long MOD = 20090711L;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        int base = 1983;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (i%2==0) maxHeap.add(base);
            else minHeap.add(base);

            if (!maxHeap.isEmpty() && !minHeap.isEmpty() && maxHeap.peek() > minHeap.peek()) {
                maxHeap.add(minHeap.poll());
                minHeap.add(maxHeap.poll());
            }

            answer += maxHeap.peek();
            answer %= MOD;

            base = next(base, a, b);
        }

        sb.append(answer).append('\n');
    }

    private int next(final int base, final int a, final int b) {
        long tmp = 1l*base*a+b;
        return (int) (tmp%MOD);
    }
}
