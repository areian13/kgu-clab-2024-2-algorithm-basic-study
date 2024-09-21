import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static final int SIZE = 4000000;

    public static void checkPrime (boolean[] isPrime) {
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= SIZE; i++) {
            for (int j = 2; 2 <= i * j && i * j <= SIZE; j++) {
                isPrime[i * j] = false;
            }
        }
    }

    public static int getNextPrime(int currentPrime, boolean[] isPrime) {
        for (int i = currentPrime + 1; i <= SIZE; i++) {
            if (isPrime[i])
                return i;
        }
        return -1;
    }

    public static boolean canMakeNWithPrimeSumSequenceFromI(int currentPrime, int n, boolean[] isPrime) {
        long sum = currentPrime;
        while(true) {
            if (sum == n) {
                return true;
            }
            if (sum > n) {
                return false;
            }

            currentPrime = getNextPrime(currentPrime, isPrime);
            if (currentPrime == -1)
                return false;
            sum += currentPrime;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean[] isPrime = new boolean[SIZE + 1];
        Arrays.fill(isPrime, true);
        checkPrime(isPrime);

        int n = Integer.parseInt(br.readLine());
        int result = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                result += canMakeNWithPrimeSumSequenceFromI(i, n, isPrime) ? 1 : 0;
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(result));
        bw.flush();

        br.close();
        bw.close();
    }
}
