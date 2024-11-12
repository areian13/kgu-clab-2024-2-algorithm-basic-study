import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static boolean isNumeric(String string) {
        int n = string.length();
        for (int i = 0; i < n; i++) {
            char curr = string.charAt(i);
            if ('0' <= curr && curr <= '9') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        HashMap<String, Integer> nameToNumber = new HashMap<>();
        List<String> numberToName = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        numberToName.add("");
        for (int i = 1; i <= n; i++) {
            String name = br.readLine();
            nameToNumber.put(name, i);
            numberToName.add(name);
        }

        for (int i = 0; i < m; i++) {
            String line = br.readLine();
            if (isNumeric(line)) {
                int number = Integer.parseInt(line);
                bw.write(numberToName.get(number) + "\n");
            } else {
                bw.write(nameToNumber.get(line) + "\n");
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
