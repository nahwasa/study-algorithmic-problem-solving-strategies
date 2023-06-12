import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    class SegNode {
        int min, max;
        public SegNode(int min, int max) {
            this.min = min;
            this.max = max;
        }
        public SegNode(int num) {
            min=max=num;
        }
    }

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int h = (int)Math.ceil(Math.log(n) / Math.log(2));

        int[] arr = new int[n];
        SegNode[] seg = new SegNode[1<<(h+1)];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        init(arr, seg, 1, 0, n-1);

        while (q-->0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int[] result = result(seg, 1, 0, n-1, a, b);
            sb.append(result[1] - result[0]).append('\n');
        }
    }

    private SegNode init(int[] arr, SegNode[] seg, int n, int s, int e) {
        if (s==e)
            return seg[n]=new SegNode(arr[s]);
        SegNode sn1 = init(arr,seg,n*2,s,(s+e)/2);
        SegNode sn2 = init(arr,seg,n*2+1,(s+e)/2+1,e);
        return seg[n] = new SegNode(Math.min(sn1.min, sn2.min), Math.max(sn1.max, sn2.max));
    }

    private int[] result(SegNode[] seg, int n, int s, int e, int l, int r) {
        if (l>e || r<s)    return new int[] {Integer.MAX_VALUE, Integer.MIN_VALUE};
        if (l<=s && e<=r)    return new int[] {seg[n].min, seg[n].max};
        int[] sn1 = result(seg,n*2,s,(s+e)/2,l,r);
        int[] sn2 = result(seg,n*2+1,(s+e)/2+1,e,l,r);

        return new int[] {Math.min(sn1[0], sn2[0]), Math.max(sn1[1], sn2[1])};
    }
}
