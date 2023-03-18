import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final int[][] MAPPING = {
            {0, 1, 2},
            {3, 7, 9, 11},
            {4, 10, 14, 15},
            {0, 4, 5, 6, 7},
            {6, 7, 8, 10, 12},
            {0, 2, 14, 15},
            {3, 14, 15},
            {4, 5, 7, 14, 15},
            {1, 2, 3, 4, 5},
            {3, 4, 5, 9, 13}
    };
    private static int[] clocks = new int[16];
    private int min;

    public static void main(String[] args) throws Exception {
        Main main = new Main();
        int c = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (c-->0) {
            sb.append(main.solution()).append('\n');
        }
        System.out.print(sb);
    }

    private int solution() throws Exception {
        setupClocks();
        synchronizeClocks(0, 0);

        return min == Integer.MAX_VALUE ? -1 : min;
    }

    private void setupClocks() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        min = Integer.MAX_VALUE;

        for (int i = 0; i < 16; i++) {
            clocks[i] = Integer.parseInt(st.nextToken());
        }
    }

    private void synchronizeClocks(int cnt, int mappingIdx) {
        if (mappingIdx == 10) {
            if (min > cnt && isAllClocks12()) {
                min = cnt;
            }
            return;
        }

        synchronizeClocks(cnt, mappingIdx+1);
        for (int i = 1; i <= 3; i++) {
            pressSwitch(mappingIdx, i, true);
            synchronizeClocks(cnt+i, mappingIdx+1);
            pressSwitch(mappingIdx, i, false);
        }
    }

    private void pressSwitch(int mappingIdx, int nth, boolean isClockwise) {
        for (int i = 0; i < MAPPING[mappingIdx].length; i++) {
            if (isClockwise) {
                clocks[MAPPING[mappingIdx][i]] += 3 * nth;
                if (clocks[MAPPING[mappingIdx][i]] > 12)
                    clocks[MAPPING[mappingIdx][i]] -= 12;
            } else {
                clocks[MAPPING[mappingIdx][i]] -= 3 * nth;
                if (clocks[MAPPING[mappingIdx][i]] <= 0)
                    clocks[MAPPING[mappingIdx][i]] += 12;
            }
        }
    }

    private boolean isAllClocks12() {
        for (int i = 0; i < 16; i++) {
            if (clocks[i] != 12) return false;
        }
        return true;
    }
}
