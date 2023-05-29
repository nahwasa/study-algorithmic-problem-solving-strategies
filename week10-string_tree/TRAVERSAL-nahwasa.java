import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    int n;
    int[] preorder, inorder;

    private void solution() throws Exception {
        n = Integer.parseInt(br.readLine());
        preorder = new int[n];
        inorder = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) preorder[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) inorder[i] = Integer.parseInt(st.nextToken());

        postorder(0, n-1, 0, n-1);
        sb.append('\n');
    }

    private void postorder(int preS, int preE, int inS, int inE) {
        if (preE < preS || inE < inS){
            return;
        }
        
        int root = preorder[preS];
        int rootPos = 0;
        for (int i = inS; i <= inE; i++) {
            if (root != inorder[i]) continue;
            rootPos = i;
            break;
        }
        rootPos-=inS;

        postorder(preS+1, preS+rootPos, inS, inS+rootPos-1);
        postorder(preS+rootPos+1, preE, inS+rootPos+1, inE);
        sb.append(root).append(' ');
    }
}
