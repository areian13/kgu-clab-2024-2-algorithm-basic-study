import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int countGreaterOrEqualNumbers(long k, long[] A) {
        int start = 0;
        int end = A.length - 1;
        int result = A.length;

        while(start <= end) {
            int mid = (start + end) / 2;
            if (A[mid] < k) {
                start = mid + 1;
            } else if (A[mid] >= k) {
                result = mid;
                end = mid - 1;
            }
        }

        return A.length - result;
    }

    public static int countGreaterNumbers(long k, long[] A) {
        int start = 0;
        int end = A.length - 1;
        int result = A.length;

        while(start <= end) {
            int mid = (start + end) / 2;
            if (A[mid] <= k) {
                start = mid + 1;
            } else if (A[mid] > k) {
                result = mid;
                end = mid - 1;
            }
        }

        return A.length - result;
    }

    public static int countBetweenNumbers(long a, long b, long[] A) {
        int cntA = countGreaterOrEqualNumbers(a, A);
        int cntB = countGreaterNumbers(b, A);
        return cntA - cntB;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long[] A = new long[n];
        for (int i = 0; i < n; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(A);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int queryType = Integer.parseInt(st.nextToken());
            long a = Long.parseLong(st.nextToken());
            int cnt = 0;
            if (queryType == 1) {
                cnt = countGreaterOrEqualNumbers(a, A);
            } else if (queryType == 2) {
                cnt = countGreaterNumbers(a, A);
            } else if (queryType == 3) {
                long b = Long.parseLong(st.nextToken());
                cnt = countBetweenNumbers(a, b, A);
            }
            bw.write(cnt + "\n");
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
