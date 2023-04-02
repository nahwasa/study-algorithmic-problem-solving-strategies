import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static List<String> ans;
    int pt1, pt2;
    String w, cur;
    boolean chk;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
    }

    private void solution() throws Exception {
        String w = br.readLine();
        w = compressContinuousAsterisk(w);
        ans = new ArrayList<>();

        int n = Integer.parseInt(br.readLine());
        while (n-->0) {
            String cur = br.readLine();
            if (isMatch(w, cur))
                ans.add(cur);
        }

        Collections.sort(ans);
        StringBuilder sb = new StringBuilder();
        for (String cur : ans) {
            sb.append(cur).append('\n');
        }
        System.out.print(sb);
    }

    private String compressContinuousAsterisk(String w) {
        while (w.indexOf("**") != -1) {
            w = w.replace("**", "*");
        }
        return w;
    }

    private boolean isMatch(String w, String cur) {
        this.w = w;
        this.cur = cur;
        chk = false;
        pt1 = pt2 = 0;

        match();

        return chk;
    }

    private void match() {

        if (chk) return;

        while (pt1 < w.length() && pt2 < cur.length() && (w.charAt(pt1) == '?' || w.charAt(pt1) == cur.charAt(pt2))) {
            pt1++;
            pt2++;
        }

        if (pt1 == w.length() - 1 && w.charAt(pt1) == '*') {
            chk = true;
            return;
        }

        if (pt1 == w.length()) {
            chk = pt2 == cur.length();
            return;
        }

        if (w.charAt(pt1) != '*')
            return;

        pt1++;
        int pt1Tmp = pt1;
        for (int i = pt2; !chk && i < cur.length(); i++) {

            if (w.charAt(pt1Tmp) == '?' || w.charAt(pt1Tmp) == cur.charAt(i)) {
                pt1 = pt1Tmp;
                pt2 = i;
                match();
            }
        }
    }
}
