import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int t = Integer.parseInt(br.readLine().trim());
        while (t-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        LunchBox[] lunchBoxes = initLunchBox(n);
        Arrays.sort(lunchBoxes);

        int answer = 0;
        int mSum = 0;
        for (int i = 0; i < n; i++) {
            mSum += lunchBoxes[i].m;
            answer = Math.max(answer, mSum + lunchBoxes[i].e);
        }

        sb.append(answer).append('\n');
    }

    private LunchBox[] initLunchBox(final int n) throws Exception {
        LunchBox[] lunchBoxes = new LunchBox[n];
        for (int i = 0; i < n; i++) {
            lunchBoxes[i] = new LunchBox();
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            lunchBoxes[i].m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            lunchBoxes[i].e = Integer.parseInt(st.nextToken());

        return lunchBoxes;
    }
}

class LunchBox implements Comparable<LunchBox> {
    int m, e;

    @Override
    public int compareTo(final LunchBox o) {
        if (this.e == o.e) {
            return this.m - o.m;
        }
        return o.e - this.e;
    }
}
