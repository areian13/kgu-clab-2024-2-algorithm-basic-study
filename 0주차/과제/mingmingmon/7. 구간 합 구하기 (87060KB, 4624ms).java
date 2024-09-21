package BaekJoon.Gold.G1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
/*
무지성 구현으로 풀리는 것 같은데, 괜찮은건가요..?
*/
public class G1_2042 {

    public static void changeNumber(long[] numbers, long b, long c) {
        numbers[(int)b] = c;
    }

    public static long getSum(long[] numbers, long b, long c) {
        long sum = 0;
        for (int i = (int)b; i <= c; i++) {
            sum += numbers[i];
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        long[] numbers = new long[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = Long.parseLong(br.readLine());
        }

        for (int i = 0; i < m + k; i++) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            if (a == 1) {
                changeNumber(numbers, b - 1, c);
            }
            else if (a == 2) {
                long sum = getSum(numbers, b - 1, c - 1);
                bw.write(sum + "\n");
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
