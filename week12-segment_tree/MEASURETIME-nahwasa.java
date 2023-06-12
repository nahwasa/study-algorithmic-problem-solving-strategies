import java.io.DataInputStream;
import java.io.IOException;

public class Main extends FastInput {
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        initFI();
        int c = nextInt();
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private int[] bit;
    int total = 0;

    private int query(int val) {
        return total - getPrefixSum(val);
    }

    private int getPrefixSum(int ith) {
        int answer = 0;
        while (ith > 0) {
            answer += bit[ith];
            ith -= ith&-ith;
        }
        return answer;
    }

    private void update(int ith) {
        while (ith < bit.length) {
            bit[ith] += 1;
            ith += ith&-ith;
        }
    }

    private void solution() throws Exception {
        int n = nextInt();
        int[] base = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            base[i] = nextInt();
            max = Math.max(max, base[i]);
        }

        bit = new int[max+2];
        total = 0;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = base[i] + 1;

            sum += query(cur);
            update(cur);
            total++;
        }

        sb.append(sum).append('\n');
    }
}

class FastInput {
    private static final int DEFAULT_BUFFER_SIZE = 1 << 16;
    private static DataInputStream inputStream;
    private static byte[] buffer;
    private static int curIdx, maxIdx;

    protected static void initFI() {
        inputStream = new DataInputStream(System.in);
        buffer = new byte[DEFAULT_BUFFER_SIZE];
        curIdx = maxIdx = 0;
    }

    protected static int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = (c == '-');
        if (neg) c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
        if (neg) return -ret;
        return ret;
    }

    private static byte read() throws IOException {
        if (curIdx == maxIdx) {
            maxIdx = inputStream.read(buffer, curIdx = 0, DEFAULT_BUFFER_SIZE);
            if (maxIdx == -1) buffer[0] = -1;
        }
        return buffer[curIdx++];
    }
}
