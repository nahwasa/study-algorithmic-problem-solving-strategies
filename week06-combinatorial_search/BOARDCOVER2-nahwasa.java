import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int t = Integer.parseInt(br.readLine());
        while (t-->0) new Main().solution();
        System.out.print(sb);
    }

    int h, w, r, c, fillCnt, answer, dLimit;
    boolean[][] map;
    boolean[][][] block;

    private void solution() throws Exception {
        answer = fillCnt = 0;
        initInput();
        search(0, 0, 0);
        sb.append(answer).append('\n');
    }

    private void search(int curR, int curC, int cnt) {
        answer = max(answer, cnt);

        int remain = (h-curR-1)*w + (w-curC-1);
        if (cnt + remain/fillCnt <= answer) return;

        int nextR = curR;
        int nextC = curC+1;
        if (nextC == w) {
            nextC = 0;
            nextR++;
        }

        for (int d = 0; d < dLimit; d++) {
            boolean[][] curBlock = block[d];
            if (curR + curBlock.length - 1 >= h || curC + curBlock[0].length -1 >= w) continue;

            List<int[]> candidate = new ArrayList<>(fillCnt);
            boolean chk = true;

            for (int i = 0; chk && i < curBlock.length; i++) {
                for (int j = 0; chk && j < curBlock[0].length; j++) {
                    if (map[curR+i][curC+j] && curBlock[i][j]) chk = false;
                    if (!map[curR+i][curC+j] && curBlock[i][j]) candidate.add(new int[] {curR+i,curC+j});
                }
            }

            if (!chk) continue;

            for (int[] pos : candidate) {
                map[pos[0]][pos[1]] = true;
            }

            search(nextR, nextC, cnt+1);

            for (int[] pos : candidate) {
                map[pos[0]][pos[1]] = false;
            }
        }

        search(nextR, nextC, cnt);
    }

    private void initInput() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        map = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            String row = br.readLine();
            for (int j = 0; j < w; j++) {
                if (row.charAt(j) == '#')
                    map[i][j] = true;
            }
        }

        boolean[][] baseBlock = new boolean[r][c];
        for (int i = 0; i < r; i++) {
            String row = br.readLine();
            for (int j = 0; j < c; j++) {
                if (row.charAt(j) == '#')
                    baseBlock[i][j] = true;
            }
        }

        initBlock(baseBlock);
    }

    private void initBlock(boolean[][] baseBlock) {
        baseBlock = compactBaseBlock(baseBlock);
        block = new boolean[4][][];

        for (int i = 0; i < 4; i++) {
            block[i] = baseBlock;
            if (i != 3) baseBlock = rotateArr(baseBlock);
        }

        boolean chk = true;
        for (int i = 0; chk && i < block[0].length; i++) {
            for (int j = 0; chk && j < block[0][0].length; j++) {
                if (block[0][i][j] != block[2][i][j]) chk = false;
            }
        }

        dLimit = chk?2:4;
    }

    private boolean[][] rotateArr(boolean[][] arr) {
        boolean[][] result = new boolean[arr[0].length][arr.length];

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                result[i][j] = arr[arr.length-1-j][i];
            }
        }

        return result;
    }

    private boolean[][] compactBaseBlock(boolean[][] baseBlock) {
        int r1 = 10, c1 = 10, r2 = 0, c2 = 0;
        for (int i = 0; i < baseBlock.length; i++) {
            for (int j = 0; j < baseBlock[0].length; j++) {
                if (!baseBlock[i][j]) continue;

                fillCnt++;
                r1 = min(r1, i);
                c1 = min(c1, j);
                r2 = max(r2, i);
                c2 = max(c2, j);
            }
        }

        boolean[][] result = new boolean[r2-r1+1][c2-c1+1];
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                result[i-r1][j-c1] = baseBlock[i][j];
            }
        }

        return result;
    }
}
