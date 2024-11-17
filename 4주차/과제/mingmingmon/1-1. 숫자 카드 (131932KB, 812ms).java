import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashSet<Integer> cards = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int curr = Integer.parseInt(st.nextToken());
            cards.add(curr);
        }

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int curr = Integer.parseInt(st.nextToken());
            if (cards.contains(curr)) {
                bw.write("1 ");
            } else {
                bw.write("0 ");
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
