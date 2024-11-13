import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        HashMap<String, Boolean> hm = new HashMap<>();
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String status = st.nextToken();
            if (status.equals("enter")) {
                hm.put(name, true);
            } else {
                hm.put(name, false);
            }
        }

        List<String> names = new ArrayList<>();
        for (Map.Entry<String, Boolean> entry : hm.entrySet()) {
            if (entry.getValue()) {
                names.add(entry.getKey());
            }
        }

        Collections.sort(names, Collections.reverseOrder());

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (String name : names) {
            bw.write(name + "\n");
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
