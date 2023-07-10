import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static int cnt = 0;
    static int map[][];
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};
    static Map<Integer, Point> cheese;

    static void setOutsideAir(Point start) {
        Queue<Point> q = new LinkedList<Point>();
        q.add(start);
        map[start.y][start.x] = -1;
        while(!q.isEmpty()) {
            Point now = q.poll();
            for(int i = 0; i < 4; i++) {
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M || map[ny][nx] != 0) continue;
                map[ny][nx] = -1;
                q.add(new Point(ny, nx));
            }
        }
    }

    static boolean canMelted(Point point) {
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int ny = point.y + dy[i];
            int nx = point.x + dx[i];
            if(map[ny][nx] == -1) cnt++;
        }
        if(cnt >= 2) return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        cheese = new HashMap<Integer, Point>();
        Queue<Point> air = new LinkedList<Point>();
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 1) {
                    cheese.put(cnt++, new Point(i, j));
                }
            }
        }

        setOutsideAir(new Point(0, 0));
        int time = 0;
        while(cnt > 0) {
            while(!air.isEmpty()) {
                Point p = air.poll();
                if(map[p.y][p.x] != -1)
                    setOutsideAir(p);
            }

            List<Integer> keys = new ArrayList<Integer>();
            for(Integer key : cheese.keySet()) {
                Point val = cheese.get(key);
                if(map[val.y][val.x] == 1) {
                    boolean result = canMelted(val);
                    if(result) {
                        keys.add(key);
                        map[val.y][val.x] = 0;
                        air.add(val);
                    }

                }
            }
            for(Integer key : keys) {
                cheese.remove(key);
                cnt--;
            }

            time++;
        }
        bw.write(time + "");
        bw.flush();
        bw.close();
        br.close();
    }

    static class Point {
        int y;
        int x;
        public Point (int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}