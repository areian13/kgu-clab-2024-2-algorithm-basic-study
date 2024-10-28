import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> {
            if (Math.abs(o1) == Math.abs(o2)) {
                return o1 - o2;
            }
            return Math.abs(o1) - Math.abs(o2);
        });
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int number = Integer.parseInt(br.readLine());
            if (number == 0) {
                int result = pq.isEmpty() ? 0 : pq.poll();
                bw.write(result + "\n");
            } else {
                pq.add(number);
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
