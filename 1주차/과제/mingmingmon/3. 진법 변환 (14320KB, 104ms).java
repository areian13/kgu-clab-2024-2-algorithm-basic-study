import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

    public static int charToInt(char currChar) {
        if ('0' <= currChar && currChar <= '9') {
            return currChar - '0';
        }
        return currChar - 'A' + 10;
    }

    public static int getDecimal(String string, int b) {
        int n = string.length();
        int decimal = 0;
        int power = 1;
        for (int i = n - 1; i >= 0; i--) {
            char currChar = string.charAt(i);
            int currInt = charToInt(currChar);
            decimal += currInt * power;
            power *= b;
        }
        return decimal;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String n = st.nextToken();
        int b = Integer.parseInt(st.nextToken());

        int decimal = getDecimal(n, b);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(decimal));
        bw.flush();

        br.close();
        bw.close();
    }

}
