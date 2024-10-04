import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    public static char intToChar(int n) {
        if (0 <= n && n <= 9) {
            return (char)(n + '0');
        }
        return (char)(n + 'A' - 10);
    }

    public static String reverseString(String string) {
        int n = string.length();
        StringBuilder sb = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            sb.append(string.charAt(i));
        }
        return sb.toString();
    }

    public static String getNumberInBase(int n, int b) {
        StringBuilder sb = new StringBuilder();

        while(n != 0) {
            int mod = n % b;
            char charMod = intToChar(mod);
            sb.append(charMod);
            n /= b;
        }

        return reverseString(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        String result = getNumberInBase(n, b);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(result);
        bw.flush();

        br.close();
        bw.close();
    }
}
