import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import static java.lang.Math.*;

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
        Base[] arr = new Base[n];

        ArrayList<Edge>[] edges = new ArrayList[n];
        for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = new Base(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken()));
            for (int j = 0; j < i; j++) {
                double dist = arr[i].distance(arr[j]);
                edges[i].add(new Edge(j, dist));
                edges[j].add(new Edge(i, dist));
            }
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] v = new boolean[n];
        pq.add(new Edge(0, 0));

        double answer = 0.0;
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (v[cur.to]) continue;
            v[cur.to] = true;
            answer = max(answer, cur.dist);

            for (Edge next : edges[cur.to]) {
                if (!v[next.to]) {
                    pq.add(next);
                }
            }
        }

        sb.append(String.format("%.2f\n", answer));
    }
}

class Base {
    double x, y;

    public Base(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(Base other) {
        return sqrt(pow(this.x-other.x, 2) + pow(this.y-other.y, 2));
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
        return this.dist - o.dist < 0 ? -1 : this.dist==o.dist ? 0 : 1;
    }
}
