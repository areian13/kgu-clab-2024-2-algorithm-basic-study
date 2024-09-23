import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] scores = new int[n];
        int max = -1;
        for (int i = 0; i < n; i++) {
            scores[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, scores[i]);
        }

        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (double)scores[i] / max * 100;
        }

        double average = sum / (double)n;

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Double.toString(average));
        bw.flush();

        br.close();
        bw.close();
    }
}
