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

        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0)
                break;

            HashMap<Integer, Boolean> cd = new HashMap<>();
            for (int i = 0; i < n; i++) {
                cd.put(Integer.parseInt(br.readLine()), true);
            }

            int numberOfSameCd = 0;
            for (int i = 0; i < m; i++) {
                int sy = Integer.parseInt(br.readLine());
                if (cd.containsKey(sy)) {
                    numberOfSameCd++;
                }
            }
            bw.write(numberOfSameCd + "\n");
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
