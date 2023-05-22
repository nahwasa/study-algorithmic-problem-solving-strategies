import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {

        int c = Integer.parseInt(br.readLine().trim());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        String s = br.readLine().trim();
        Deque<Integer> brackets = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case '[' : brackets.addLast(0); break;
                case '(' : brackets.addLast(1); break;
                case '{' : brackets.addLast(2); break;
                case ']' : if (brackets.isEmpty() || brackets.removeLast() != 0) {no(); return;} break;
                case ')' : if (brackets.isEmpty() || brackets.removeLast() != 1) {no(); return;} break;
                case '}' : if (brackets.isEmpty() || brackets.removeLast() != 2) {no(); return;} break;
            }
        }
        
        if (brackets.isEmpty()) yes();
        else no();
    }

    private void yes() {
        sb.append("YES").append('\n');
    }

    private void no() {
        sb.append("NO").append('\n');
    }
}
