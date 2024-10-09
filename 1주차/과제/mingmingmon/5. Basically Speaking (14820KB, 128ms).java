import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    public static int charToInt(char c) {
        if ('0' <= c && c <= '9') {
            return c - '0';
        }
        return c - 'A' + 10;
    }

    public static int getDecimal(String string, int b) {
        int n = string.length();
        int deciaml = 0;
        int power = 1;
        for (int i = n - 1; i >= 0; i--) {
            char currChar = string.charAt(i);
            int currInt = charToInt(currChar);
            deciaml += currInt * power;
            power *= b;
        }
        return deciaml;
    }

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
        do {
            int mod = n % b;
            char charMod = intToChar(mod);
            sb.append(charMod);
            n /= b;
        } while(n != 0);
        return sb.reverse().toString();
    }

    public static String convertBase(String givenString, int fromBase, int toBase) {
        int decimal = getDecimal(givenString, fromBase);
        return getNumberInBase(decimal, toBase);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line;
        while((line = br.readLine()) != null && !line.isEmpty()) {
            StringTokenizer st = new StringTokenizer(line);
            String givenString = st.nextToken();
            int fromBase = Integer.parseInt(st.nextToken());
            int toBase = Integer.parseInt(st.nextToken());

            String result = convertBase(givenString, fromBase, toBase);
            result = result.length() > 7 ? "ERROR" : result;

            bw.write(String.format("%7s\n", result));
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
