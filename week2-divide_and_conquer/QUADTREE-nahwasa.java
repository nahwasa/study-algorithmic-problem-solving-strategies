import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final char SPLIT = 'x';

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();
        while (c-->0)
            answer.append(new QuadTree(br.readLine()).answer()).append('\n');
        System.out.print(answer);
    }

    static class QuadTree {
        String picture;
        int idx;

        public QuadTree(String picture) {
            this.picture = picture;
            this.idx = 0;
        }

        public String answer() {
            StringBuilder result = new StringBuilder();
            idx++;

            if (picture.charAt(idx-1) != SPLIT) {
                return result.append(picture.charAt(idx-1)).toString();
            }

            String[] quadrant = new String[5];
            for (int i = 1; i <= 4; i++) {
                quadrant[i] = answer();
            }

            return result.append('x')
                    .append(quadrant[3])
                    .append(quadrant[4])
                    .append(quadrant[1])
                    .append(quadrant[2])
                    .toString();
        }
    }
}
