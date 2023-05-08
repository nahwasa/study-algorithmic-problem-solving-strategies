import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    private static final int LIMIT = 8030 * 1000;

    public static void main(String[] args) throws Exception {
        int t = Integer.parseInt(br.readLine());
        while (t-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Sign[] arr = new Sign[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());

            arr[i] = new Sign(l, g, m);
        }

        int lo = -1;
        int hi = LIMIT+1;
        int answer = LIMIT;
        while (lo <= hi) {
            int mid = (lo+hi)/2;

            if (k <= cntSign(arr, mid)) {
                answer = Math.min(answer, mid);
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }

        sb.append(answer).append('\n');
    }

    private int cntSign(Sign[] arr, int mid) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            if (mid < arr[i].l - arr[i].m) continue;

            sum += (Math.min(mid, arr[i].l) - (arr[i].l - arr[i].m)) / arr[i].g + 1;
        }
        return sum;
    }
}

class Sign {
    int l, g, m;
    public Sign(int l, int g, int m) {
        this.l = l;
        this.g = g;
        this.m = m;
    }
}
