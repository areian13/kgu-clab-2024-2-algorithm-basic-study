import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static final int SIZE = 10000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());

        boolean[] isPrime = new boolean[SIZE + 1];
        Arrays.fill(isPrime, true);

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= SIZE; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j <= SIZE; j += i) {
                isPrime[j] = false;
            }
        }

        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int i = m; i <= n; i++) {
            if (isPrime[i]) {
                sum += i;
                min = Math.min(min, i);
            }
        }

        String result = sum == 0 ? "-1" : sum + "\n" + min;

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(result);
        bw.flush();

        br.close();
        bw.close();
    }
}
