import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        int c = Integer.parseInt(br.readLine());
        while (c-->0) new Main().solution();
        System.out.print(sb);
    }

    private void solution() throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Trie trie = new Trie();

        while (n-->0) {
            st = new StringTokenizer(br.readLine());
            trie.insert(st.nextToken(), Integer.parseInt(st.nextToken()));
        }

        int answer = m-1;
        st = new StringTokenizer(br.readLine());
        while (m-->0) {
            String s = st.nextToken();
            int findCnt = trie.find(s);
            answer += findCnt;
        }

        sb.append(answer).append('\n');
    }
}

class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String s, int cnt) {
        TrieNode iter = root;
        Word word = new Word(s, cnt);

        for (int i = 0; i < s.length(); i++) {
            iter = iter.retrieveChild(s.charAt(i));
            iter.add(word);
        }
    }

    public int find(String s) {
        TrieNode iter = root;

        for (int i = 0; i < s.length(); i++) {
            iter = iter.retrieveChild(s.charAt(i));

            if (iter.pq.isEmpty())
                return s.length();

            if (!iter.pq.peek().word.equals(s))
                continue;

            return min(s.length(), i+2);
        }

        return s.length();
    }
}

class TrieNode {
    TrieNode[] child;
    PriorityQueue<Word> pq;

    public TrieNode() {
        child = new TrieNode[26];
        pq = new PriorityQueue<>();
    }

    public void add(Word word) {
        pq.add(word);
    }

    public TrieNode retrieveChild(char c) {
        if (child[c-'A'] == null) {
            child[c-'A'] = new TrieNode();
        }
        return child[c-'A'];
    }
}

class Word implements Comparable<Word> {
    String word;
    int cnt;

    public Word(String word, int cnt) {
        this.word = word;
        this.cnt = cnt;
    }

    @Override
    public int compareTo(final Word o) {
        if (this.cnt == o.cnt)
            return this.word.compareTo(o.word);
        return o.cnt - this.cnt;
    }
}
