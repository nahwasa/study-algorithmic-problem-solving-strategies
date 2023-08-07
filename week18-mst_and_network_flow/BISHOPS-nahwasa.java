import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    private static final int[] MAIN_DIAGONAL_DR = {-1, 1};
    private static final int[] MAIN_DIAGONAL_DC = {-1, 1};
    private static final int[] ANTI_DIAGONAL_DR = {-1, 1};
    private static final int[] ANTI_DIAGONAL_DC = {1, -1};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1<<16);
    static StringBuilder output = new StringBuilder();


    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(output);
    }

    public void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());

        boolean[][] map = new boolean[n+2][n+2];
        for (int i = 1; i <= n; i++) {
            String row = br.readLine();
            for (int j = 1; j <= n; j++) {
                map[i][j] = row.charAt(j-1)=='.';
            }
        }

        int[][] mainDiagonalMap = new int[n+2][n+2];
        int mainDiagonalCnt = 0;
        for (int[] row : mainDiagonalMap) Arrays.fill(row, -1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!map[i][j] || mainDiagonalMap[i][j] != -1) continue;

                mainDiagonalMap[i][j] = mainDiagonalCnt;
                for (int d = 0; d < 2; d++) {
                    int nr = i;
                    int nc = j;
                    while (true) {
                        nr += MAIN_DIAGONAL_DR[d];
                        nc += MAIN_DIAGONAL_DC[d];
                        if (!map[nr][nc]) break;
                        mainDiagonalMap[nr][nc] = mainDiagonalCnt;
                    }
                }
                mainDiagonalCnt++;
            }
        }

        int[][] antiDiagonalMap = new int[n+2][n+2];
        int antiDiagonalCnt = 0;
        for (int[] row : antiDiagonalMap) Arrays.fill(row, -1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!map[i][j] || antiDiagonalMap[i][j] != -1) continue;

                antiDiagonalMap[i][j] = antiDiagonalCnt;
                for (int d = 0; d < 2; d++) {
                    int nr = i;
                    int nc = j;
                    while (true) {
                        nr += ANTI_DIAGONAL_DR[d];
                        nc += ANTI_DIAGONAL_DC[d];
                        if (!map[nr][nc]) break;
                        antiDiagonalMap[nr][nc] = antiDiagonalCnt;
                    }
                }
                antiDiagonalCnt++;
            }
        }

        ArrayList<Integer>[] edges = new ArrayList[mainDiagonalCnt];
        for (int i = 0 ; i < mainDiagonalCnt; i++) edges[i] = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!map[i][j]) continue;
                try {
                    edges[mainDiagonalMap[i][j]].add(antiDiagonalMap[i][j]);
                } catch (Exception e) {
                    System.out.println();
                }
            }
        }

        int answer = getAnswer(mainDiagonalCnt, antiDiagonalCnt, edges);
        output.append(answer).append('\n');
    }

    private int getAnswer(int from, int to, List<Integer>[] edges) {
        int[] matched = new int[to];
        Arrays.fill(matched, -1);
        int answer = 0;
        for (int i = 0; i < from; i++) {
            boolean[] v = new boolean[to];
            if (matching(i, edges, v, matched))
                answer++;
        }
        return answer;
    }

    private boolean matching(int cur, List<Integer>[] edges, boolean[] v, int[] matched) {
        for (int next : edges[cur]) {
            if (v[next]) continue;
            v[next] = true;
            if (matched[next] == -1 || matching(matched[next], edges, v, matched)) {
                matched[next] = cur;
                return true;
            }
        }
        return false;
    }
}
