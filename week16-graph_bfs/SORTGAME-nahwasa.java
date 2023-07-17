import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    private Map<Integer, Integer>[] answer = new Map[9];

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    private void solution() throws Exception {
        init();
        int c = Integer.parseInt(br.readLine());
        while (c-->0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            sb.append(answer[n].get(compressedNum(n, arr))).append('\n');
        }
        System.out.print(sb);
    }

    private int compressedNum(int n, int[] arr) {
        int[] tmp = Arrays.copyOf(arr, arr.length);
        Arrays.sort(tmp);

        Map<Integer, Integer> compress = new HashMap<>();
        int to = 1;
        for (int cur : tmp)
            compress.put(cur, to++);

        int base = 0;
        for (int i = 0; i < n; i++) {
            base *= 10;
            base += compress.get(arr[i]);
        }

        return base;
    }

    private void init() {
        for (int i = 1; i <= 8; i++)
            answer[i] = new HashMap<>();

        for (int i = 1; i <= 8; i++) {
            int base = 0;
            for (int j = 1; j <= i; j++) {
                base *= 10;
                base += j;
            }

            preComputation(i, answer[i], base);
        }
    }

    private void preComputation(final int len, Map<Integer, Integer> result, final int base) {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{base, 0});
        result.put(base, 0);

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int num = cur[0];
            int dist = cur[1];

            for (int s = 0; s < len-1; s++) {
                for (int e = s+1; e < len; e++) {
                    int next = rangeReverse(num, len, s, e);

                    if (result.containsKey(next)) continue;
                    result.put(next, dist+1);
                    q.add(new int[]{next, dist+1});
                }
            }
        }
    }

    private int rangeReverse(int num, final int len, final int s, final int e) {
        int pre = 1;
        for (int i = 0; i < len-s; i++) pre*=10;

        int post = 1;
        for (int i = 0; i < len-e-1; i++) post*=10;

        return (num/pre*pre + reverse(num%pre/post)*post) + num%post;
    }

    private int reverse(int num) {
        int result = 0;

        while (num != 0) {
            result *= 10;
            result += num % 10;
            num /= 10;
        }

        return result;
    }
}
