import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        HashMap<String, Integer> nameToNumber = new HashMap<>();
        HashMap<Integer, String> numberToName = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            String name = br.readLine();
            nameToNumber.put(name, i);
            numberToName.put(i, name);
        }

        for (int i = 0; i < m; i++) {
            String line = br.readLine();
            try {
                int number = Integer.parseInt(line);
                bw.write(numberToName.get(number) + "\n");
            } catch (Exception e) {
                bw.write(nameToNumber.get(line) + "\n");
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
