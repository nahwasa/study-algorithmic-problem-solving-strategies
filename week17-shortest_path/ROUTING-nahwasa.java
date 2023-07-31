import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1<<16);
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        Main main = new Main();
        while (c-->0) main.solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Node>[] edges = new List[n];
        for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
        while (m-->0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            double c = Double.parseDouble(st.nextToken());

            edges[a].add(new Node(b, c));
            edges[b].add(new Node(a, c));
        }

        double[] dist = new double[n];
        Arrays.fill(dist, Double.MAX_VALUE);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(0, 1.0));
        dist[0] = 1.0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            double curDist = cur.c;

            if (dist[cur.to] < curDist) continue;

            for (Node next : edges[cur.to]) {
                int to = next.to;
                double nextDist = curDist * next.c;

                if (dist[to] > nextDist) {
                    dist[to] = nextDist;
                    pq.add(new Node(to, nextDist));
                }
            }
        }

        sb.append(String.format("%.10f", dist[n-1])).append('\n');
    }
}

class Node implements Comparable<Node> {
    int to;
    double c;

    public Node(int to, double c) {
        this.to = to;
        this.c = c;
    }

    @Override
    public int compareTo(final Node o) {
        double tmp = c-o.c;
        return tmp<0?-1:tmp>0?1:0;
    }
}
