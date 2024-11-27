import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int getIndexOfCards(int number, int[] cards) {
        int start = 0;
        int end = cards.length - 1;

        while(start <= end) {
            int mid = (start + end) / 2;
            if (cards[mid] == number) {
                return mid;
            }
            if (cards[mid] < number) {
                start = mid + 1;
            } else if (cards[mid] > number) {
                end = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] cards = new int[n];
        for (int i = 0; i < n; i++) {
            cards[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(cards);

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int curr = Integer.parseInt(st.nextToken());
            if (getIndexOfCards(curr, cards) == -1) {
                bw.write("0 ");
            } else {
                bw.write("1 ");
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
