import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final StringBuilder answer = new StringBuilder();
    private static final int BOARD_SIZE = 5;
    private static final int A_TO_Z = 'Z'-'A'+1;

    private char[][] board;
    private boolean[] chk;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        Main main = new Main();
        while (c-->0) main.solution();
        System.out.print(answer);
    }

    public void solution() throws Exception {
        initializeBoard();

        int n = Integer.parseInt(br.readLine());
        while (n-->0) {
            String str = br.readLine();
            answer.append(str).append(' ');
            answer.append(isPossibleToFind(str) ? "YES" : "NO").append('\n');
        }
    }
    
    private void initializeBoard() throws Exception {
        board = new char[BOARD_SIZE][BOARD_SIZE];
        chk = new boolean[A_TO_Z];
        
        for (int i = 0; i < BOARD_SIZE; i++) {
            String row = br.readLine();
            for (int j = 0; j < BOARD_SIZE; j++) {
                char c = row.charAt(j);
                chk[atoi(c)] = true;
                board[i][j] = c;
            }
        }
    }

    private boolean isPossibleToFind(String str) {
        for (int i = 0; i < str.length(); i++) {
            if (!chk[atoi(str.charAt(i))])
                return false;
        }

        char first = str.charAt(0);
        boolean[][][] v = new boolean[BOARD_SIZE][BOARD_SIZE][str.length()];
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != first || !find(str, v,1, i, j)) continue;
                return true;
            }
        }
        return false;
    }

    private boolean find(String str, boolean[][][] v, int idx, int r, int c) {
        if (idx == str.length())
            return true;

        char next = str.charAt(idx);
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i==0 && j==0) continue;
                int nr = r+i;
                int nc = c+j;
                if (nr<0 || nr>=BOARD_SIZE || nc<0 || nc>=BOARD_SIZE || board[nr][nc] != next || v[nr][nc][idx])
                    continue;

                v[nr][nc][idx] = true;
                if (find(str, v, idx+1, nr, nc))
                    return true;
            }
        }

        return false;
    }

    private int atoi(char c) {
        return c-'A';
    }
}
