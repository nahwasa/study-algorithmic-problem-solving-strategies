import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1<<16);
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }


    int[] parents;
    int[][] pos;

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        parents = new int[n];
        Arrays.fill(parents, -1);

        pos = new int[n][2];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) pos[i][0] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) pos[i][1] = Integer.parseInt(st.nextToken());

        while (m-->0) {
            st = new StringTokenizer(br.readLine());
            union(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        double[][] edges = new double[n][n];
        for (double[] row : edges) Arrays.fill(row, Double.POSITIVE_INFINITY);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = find(i);
                int b = find(j);
                if (a==b) continue;

                edges[a][b] = edges[b][a] = Math.min(edges[a][b], dist(i, j));
            }
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] v = new boolean[n];
        pq.add(new Edge(find(0), 0d));
        double answer = 0d;
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (v[cur.to]) continue;
            v[cur.to] = true;

            answer += cur.dist;

            for (int next = 0; next < n; next++) {
                if (next == cur.to || v[next] || edges[cur.to][next] == Double.POSITIVE_INFINITY) continue;

                pq.add(new Edge(next, edges[cur.to][next]));
            }
        }

        sb.append(answer).append('\n');
    }

    private double dist(int a, int b) {
        return Math.sqrt(pow(pos[a][0]-pos[b][0])+pow(pos[a][1]-pos[b][1]));
    }

    private int pow(int num) {
        return num*num;
    }

    private int find(int a) {
        if (parents[a] < 0) return a;
        return parents[a] = find(parents[a]);
    }

    private void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        int hi = parents[a]<parents[b]?a:b;
        int lo = parents[a]<parents[b]?b:a;

        parents[hi] += parents[lo];
        parents[lo] = hi;
    }
}

class Edge implements Comparable<Edge> {
    int to;
    double dist;
    public Edge(int to, double dist) {
        this.to = to;
        this.dist = dist;
    }

    @Override
    public int compareTo(final Edge o) {
        if (dist > o.dist) return 1;
        if (dist < o.dist) return -1;
        return 0;
    }
}
