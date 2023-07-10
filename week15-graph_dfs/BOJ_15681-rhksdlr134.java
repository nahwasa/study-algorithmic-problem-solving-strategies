import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static int N, R, Q;
    static int dp[];
    static LinkedList<Integer> list[];
    static StringTokenizer st;

    static int dfs(int now, int parent) {
        dp[now] = 1;
        for(Integer i : list[now]) {
            if(parent == i) continue;
            dp[now] += dfs(i, now);
        }
        return dp[now];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        dp = new int[N+1];
        list = new LinkedList[N+1];
        for(int i = 1; i<=N; i++) {
            list[i] = new LinkedList<Integer>();
        }
        for(int i = 0; i<N-1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            list[a].add(b);
            list[b].add(a);
        }
        dfs(R, 0);
        for(int i = 0; i<Q; i++)
            bw.write(dp[Integer.parseInt(br.readLine())] + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}