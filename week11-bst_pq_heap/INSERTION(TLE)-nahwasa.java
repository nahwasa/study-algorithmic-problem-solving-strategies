import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class Main extends FastInput {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        initFI();
        int c = nextInt();
        while (c-->0) new Main().solution();
        bw.write(sb.toString());
        bw.flush();
    }

    private void solution() throws Exception {
        int n = nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i+1;
        }

        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = nextInt();
        }

        while (n-->1) {
            int tmp = cnt[n];

            for (int i = n; cnt[n] > 0; i++, cnt[n]--) {
                int idx = i - tmp;
                int swapTmp = arr[idx];
                arr[idx] = arr[idx+1];
                arr[idx+1] = swapTmp;
            }
        }

        for (int cur : arr) {
            sb.append(cur).append(' ');
        }
        sb.append('\n');
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
