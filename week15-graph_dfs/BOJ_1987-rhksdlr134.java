import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int R, C;
    static int cnt = 1;
    static int ans = 1;
    static char[][] map;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    static void dfs(int y, int x, boolean[] visit) {
        visit[map[y][x] - 'A'] = true;
        for(int dir = 0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C || visit[map[ny][nx] - 'A']) continue;
            ans = Math.max(++cnt, ans);
            dfs(ny, nx, visit);
        }
        cnt--;
        visit[map[y][x] - 'A'] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        map = new char[R][C];
        boolean[] visit = new boolean[26];
        for(int i = 0; i<R; i++) {
            String tmp = br.readLine();
            for(int j = 0; j<C; j++)
                map[i][j] = tmp.charAt(j);
        }
        dfs(0, 0, visit);
        System.out.println(ans);

    }

}