import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
//        makeTester();
//        if (1==1) return;

        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private static void makeTester() {
        int tc = 1000;
        System.out.println(tc);
        Random rand = new Random(System.currentTimeMillis());

        while (tc-->0) {
            int n = rand.nextInt(10)+1;
            int k = rand.nextInt(n+1);
            int m = rand.nextInt(10)+1;
            int l = rand.nextInt(10)+1;

            System.out.println(n + " " + k + " " + m + " " + l);
            for (int i = 0; i < n; i++) {
                int r = rand.nextInt(n);
                System.out.print(r + " ");
                boolean[] v = new boolean[n];
                for (int j = 0; j < r; ) {
                    int tmp = rand.nextInt(n);
                    if (j == tmp || v[tmp]) continue;
                    v[tmp] = true;
                    System.out.print(tmp + " ");
                    j++;
                }
                System.out.println();
            }

            for (int i = 0; i < m; i++) {
                int c = rand.nextInt(Math.min(n, 10))+1;
                System.out.print(c + " ");
                boolean[] v = new boolean[n];
                while (c > 0) {
                    int tmp = rand.nextInt(n);
                    if (v[tmp]) continue;
                    v[tmp] = true;
                    System.out.print(tmp + " ");
                    c--;
                }
                System.out.println();
            }
        }
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        int[] pre = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            while (r-->0) pre[i] |= 1<<Integer.parseInt(st.nextToken());
        }

        int[] semester = new int[m];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            while (c-->0) semester[i] |= 1<<Integer.parseInt(st.nextToken());
        }

        Queue<Pos> q = new ArrayDeque<>();
        q.add(new Pos(0, 0, 0, 0));
        int answer = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            Pos cur = q.poll();

            if (cur.cnt >= k) {
                answer = Math.min(answer, cur.answer);
                continue;
            }
            if (cur.semesterIdx >= m) continue;

            q.add(new Pos(cur.subject, cur.semesterIdx+1, cur.cnt, cur.answer));    // 이번학기 패스하는 경우

            List<Candidate> candidates = candidates(pre, n, l, cur.subject, semester[cur.semesterIdx]);
            for (Candidate next : candidates) {
                if (next.cnt == 0) continue;

                int nextSubject = cur.subject|next.subjects;

                q.add(new Pos(nextSubject, cur.semesterIdx+1, cur.cnt+next.cnt, cur.answer+1));
            }
        }

        sb.append(answer == Integer.MAX_VALUE ? "IMPOSSIBLE" : answer).append('\n');
    }

    private List<Candidate> candidates(int[] pre, int n, int l, int subject, int semesterNum) {
        List<Integer> valid = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if ((semesterNum&1<<i) == 0 || (subject&1<<i) != 0 || !validPreSubject(n, pre[i], subject)) continue;

            valid.add(i);
        }

        List<Candidate> result = new ArrayList<>();
        if (valid.size() <= l) {
            int res = 0;
            for (Integer tmp : valid)
                res|=1<<tmp;
            result.add(new Candidate(res, valid.size()));
            return result;
        }

        choice(result, valid, l, 0, 0, 0);

        return result;
    }

    private void choice(List<Candidate> result, List<Integer> valid, int l, int cnt, int idx, int cur) {
        if (l-cnt > valid.size()-idx) return;   // 선택 가능한 수가 더 적은 경우
        if (cnt == l) {
            result.add(new Candidate(cur, cnt));
            return;
        }

        choice(result, valid, l, cnt, idx+1, cur);
        choice(result, valid, l, cnt+1, idx+1, cur|1<<valid.get(idx));
    }

    private boolean validPreSubject(int n, int pre, int subject) {
        for (int i = 0; i < n; i++) {
            int pt = 1<<i;
            if ((pre&pt)!=0 && (subject&pt)==0) return false;
        }
        return true;
    }
}

class Pos {
    int subject, semesterIdx, cnt, answer;

    public Pos(int subject, int semesterIdx, int cnt, int answer) {
        this.subject = subject;
        this.semesterIdx = semesterIdx;
        this.cnt = cnt;
        this.answer = answer;
    }
}

class Candidate {
    int subjects, cnt;

    public Candidate(int subjects, int cnt) {
        this.subjects = subjects;
        this.cnt = cnt;
    }
}
