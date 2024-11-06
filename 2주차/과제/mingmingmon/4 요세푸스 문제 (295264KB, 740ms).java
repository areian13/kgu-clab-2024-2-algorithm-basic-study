import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int[] makeJosephusPermutation(int n, int k) {
        int[] josephusPermutation = new int[n];
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            q.add(i);
        }

        int index = 0;
        while(!q.isEmpty()) {
            for (int i = 1; i < k; i++) {
                int a = q.poll();
                q.add(a);
            }
            josephusPermutation[index] = q.poll();
            index++;
        }

        return josephusPermutation;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] josephusPermutation = makeJosephusPermutation(n, k);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();
        sb.append("<");
        for (int i = 0; i < n; i++) {
            sb.append(josephusPermutation[i] + ", ");
        }
        for (int i = 0; i < 2; i++) {
            sb.deleteCharAt(sb.length() - 1);
        }
        sb.append(">");
        bw.write(sb.toString());

        bw.flush();

        br.close();
        bw.close();
    }
}
