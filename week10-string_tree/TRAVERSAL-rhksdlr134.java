import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * 1. 문제 링크: https://www.algospot.com/judge/problem/read/TRAVERSAL
 * 2. 풀이
 *  - 전위 순회의 첫 번째 요소는 현재 탐색중인 트리의 루트이며,
 *    중위 순회에서 루트 인덱스를 찾으면 해당 인덱스의 왼쪽까지가 좌측 트리의 사이즈 오른쪽 끝까지가 우측 트리의 사이즈
 */
public class Traversal {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        Traversal main = new Traversal();

        int testCases = Integer.parseInt(br.readLine());
        while (testCases-- > 0) {
            main.solve();
        }

        bw.close();
        br.close();
    }

    private void solve() throws Exception {
        br.readLine();

        List<Integer> preOrder = getSequence();
        List<Integer> inOrder = getSequence();

        StringBuilder sb = new StringBuilder();

        postOrder(preOrder, inOrder, sb);

        bw.write(sb.toString().trim() + "\n");
    }

    private void postOrder(List<Integer> preOrder, List<Integer> inOrder, StringBuilder sb) {
        if (preOrder == null || preOrder.size() == 0) {
            return;
        }

        final int N = preOrder.size();
        final int root = preOrder.get(0);

        int rootIndex = inOrder.indexOf(root);
        postOrder(preOrder.subList(1, rootIndex + 1), inOrder.subList(0, rootIndex), sb);

        postOrder(preOrder.subList(rootIndex + 1, N), inOrder.subList(rootIndex + 1, N), sb);

        sb.append(root).append(" ");
    }

    private List<Integer> getSequence() throws Exception {
        return Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());
    }

}
