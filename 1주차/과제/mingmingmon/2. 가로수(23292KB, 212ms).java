import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    public static int getGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return getGCD(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] trees = new int[n];
        for (int i = 0; i < n; i++) {
            trees[i] = Integer.parseInt(br.readLine());
        }

        int[] gap = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            gap[i] = trees[i + 1] - trees[i];
        }

        int resultGap = gap[0];
        for (int i = 0; i < n - 1; i++) {
            resultGap = getGCD(resultGap, gap[i]);
        }

        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            result += gap[i] / resultGap - 1;
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(result));
        bw.flush();

        br.close();
        bw.close();
    }
}
