import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int t = Integer.parseInt(br.readLine());
        while (t-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        String d = st.nextToken();
        int n = Integer.parseInt(st.nextToken());
        int remain = Integer.parseInt(st.nextToken());

        int[] digits = sortedDigits(d);
        List<Integer> startPoints = getStartPoints(n+remain, digits);
        if (ifFinish(startPoints, n+remain)) return;

        int[] from = new int[n];
        int[] select = new int[n];
        boolean[] v = new boolean[n];
        Queue<Integer> q = new ArrayDeque<>();

        // init queue using startPoints
        for (int cur : startPoints) {
            int mod = cur % n;
            if (mod == remain) {
                sb.append(cur).append('\n');
                return;
            }

            if (v[mod]) continue;
            v[mod] = true;
            q.add(mod);
            from[mod] = cur;
            select[mod] = -1;
        }

        // bfs
        int pt = -1;
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == remain) {
                pt = cur;
                break;
            }

            for (int digit : digits) {
                int next = cur*10+digit;
                next %= n;

                if (v[next]) continue;
                v[next] = true;
                q.add(next);
                from[next] = cur;
                select[next] = digit;
            }
        }

        if (pt == -1) {
            sb.append("IMPOSSIBLE").append('\n');
            return;
        }

        // make answer
        StringBuilder tmp = new StringBuilder();
        while (select[pt] != -1) {
            tmp.append(select[pt]);
            pt = from[pt];
        }
        tmp.reverse();

        sb.append(from[pt]).append(tmp).append('\n');
    }

    private boolean ifFinish(final List<Integer> startPoints, final int target) {
        if (startPoints.isEmpty()) {
            sb.append("IMPOSSIBLE").append('\n');
            return true;
        }

        if (startPoints.get(0) == target) {
            sb.append(target).append('\n');
            return true;
        }

        return false;
    }

    private static int[] sortedDigits(final String d) {
        int[] digits = new int[d.length()];
        for (int i = 0; i < d.length(); i++) digits[i] = -(d.charAt(i)-'0');
        Arrays.sort(digits);
        for (int i = 0; i < d.length(); i++) digits[i] = -digits[i];
        return digits;
    }

    private List<Integer> getStartPoints(final int limit, final int[] digits) {
        Set<Integer> v = new HashSet<>();
        List<Integer> result = new ArrayList<>();

        Queue<Integer> q = new ArrayDeque<>();
        q.add(0);
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur >= limit) {
                result.add(cur);
                continue;
            }

            for (int digit : digits) {
                int next = cur*10+digit;
                if (v.contains(next)) continue;

                v.add(next);
                q.add(next);
            }
        }

        Collections.sort(result);
        return result;
    }
}
