import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        for (int i = 0; i < tc; i++) {
            HashMap<String, Integer> hm = new HashMap<>();
            int n = Integer.parseInt(br.readLine());
            for (int j = 0; j < n; j++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String name = st.nextToken();
                String kind = st.nextToken();
                int cnt = hm.containsKey(kind) ? hm.get(kind) + 1 : 1;
                hm.put(kind, cnt);
            }
            int result = 1;
            for (Map.Entry<String, Integer> entry : hm.entrySet()) {
                result *= entry.getValue() + 1;
            }
            result--;
            bw.write(result + "\n");
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
