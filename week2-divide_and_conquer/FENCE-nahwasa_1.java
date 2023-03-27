import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n, max;
    int[] fence;
    Deque<Integer> stack;

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (c-->0) {
            sb.append(new Main().solution()).append('\n');
        }
        System.out.print(sb);
    }

    int solution() throws Exception {
        n = Integer.parseInt(br.readLine());
        fence = new int[n];
        max = 0;
        stack = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            fence[i] = Integer.parseInt(st.nextToken());

            if (stack.isEmpty() || fence[stack.peek()] <= fence[i]) {
                stack.push(i);
                continue;
            }

            popBelow(i);
            stack.push(i);
        }
        popBelow(n);
        
        return max;
    }

    void popBelow(int curIdx) {
        int height = curIdx == n ? 0 : fence[curIdx];
        
        while (!stack.isEmpty() && fence[stack.peek()] > height) {
            int h = fence[stack.pop()];
            int w = stack.isEmpty() ? curIdx : curIdx - stack.peek() - 1;
            max = Math.max(max, h * w);
        }
    }
}
