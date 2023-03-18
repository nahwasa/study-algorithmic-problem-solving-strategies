import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final int DR[][] = {{1, 1, 0, 0}, {1, 1, 1, 1}};
    private static final int DC[][] = {{0, 0, 1, 1}, {-1, 1, 1, 0}};
    private boolean[][] arr = new boolean[20][20];
    int r, c;


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
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        int remain = setupBoard();
        if (!isRemainModBy3(remain)) {
            return 0;
        }
        return coverBoard(remain / 3, 0);
    }

    private int setupBoard() throws IOException {
        int remain = 0;
        for (int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], true);
        }
        for (int i = 1; i <= r; i++) {
            String s = br.readLine();
            for (int j = 1; j <= c; j++) {
                arr[i][j] = s.charAt(j-1) == '#' ? true : false;
                if (!arr[i][j])
                    remain++;
            }
        }
        return remain;
    }

    private boolean isRemainModBy3(int remain) {
        return remain%3 == 0;
    }

    private int coverBoard(int remain, int sr) {
        if (remain == 0) {
            return 1;
        }

        for (int i = sr; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                if (arr[i][j]) continue;

                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nr1 = i+ DR[0][dir];
                    int nc1 = j+ DC[0][dir];
                    int nr2 = i+ DR[1][dir];
                    int nc2 = j+ DC[1][dir];
                    if (arr[nr1][nc1]||arr[nr2][nc2]) continue;

                    arr[nr1][nc1] = true;
                    arr[nr2][nc2] = true;
                    arr[i][j] = true;
                    cnt += coverBoard(remain-1, i);
                    arr[nr1][nc1] = false;
                    arr[nr2][nc2] = false;
                    arr[i][j] = false;
                }
                return cnt;

            }
        }
        return 0;
    }
}
