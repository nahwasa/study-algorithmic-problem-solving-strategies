import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }

    private void solution() throws Exception {
        int n = Integer.parseInt(br.readLine());
        int[] inputData = new int[n];
        ArrayList<Integer> bs = new ArrayList<>();
        int[] idxOrder = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int cur = Integer.parseInt(st.nextToken());
            inputData[i] = cur;
            if (bs.isEmpty() || bs.get(bs.size()-1) < cur) {
                idxOrder[i] = bs.size();
                bs.add(cur);
                continue;
            }
            int idx = Collections.binarySearch(bs, cur);
            idxOrder[i] = idx>=0?idx:-idx-1;
            bs.set(idxOrder[i], cur);
        }

        int[] result = new int[bs.size()];
        int resultIdx = 0;
        int idx = n;
        n = bs.size();
        while (n-->0) {
            while (--idx>=0) {
                if (idxOrder[idx] == n) {
                    result[resultIdx++] = inputData[idx];
                    break;
                }
            }
        }

        StringBuilder answer = new StringBuilder();
        answer.append(bs.size()).append('\n');
        for (int i = result.length-1; i >= 0; i--)
            answer.append(result[i]).append(' ');
        System.out.println(answer);
    }
}
