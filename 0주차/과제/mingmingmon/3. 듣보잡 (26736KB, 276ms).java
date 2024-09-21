import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashMap<String, Boolean> unHeard = new HashMap<>();
        for (int i = 0; i < n; i++) {
            unHeard.put(br.readLine(), true);
        }

        List<String> unseenAndUnheard = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String unSeen = br.readLine();
            if (unHeard.containsKey(unSeen)) {
                unseenAndUnheard.add(unSeen);
            }
        }

        Collections.sort(unseenAndUnheard);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int numberOfUnseenAndUnHeard = unseenAndUnheard.size();
        bw.write(numberOfUnseenAndUnHeard + "\n");
        for (int i = 0; i < numberOfUnseenAndUnHeard; i++) {
            bw.write(unseenAndUnheard.get(i) + "\n");
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
