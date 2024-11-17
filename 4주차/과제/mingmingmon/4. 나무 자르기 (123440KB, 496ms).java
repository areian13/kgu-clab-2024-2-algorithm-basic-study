import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    // 입력 범위를 보아하니 long을 써야 될 것 같다!
    // h 높이가 커질 수록 잘라가는 나무의 길이는 작아짐. m을 만족하는 최소의 h를 구하고자 함.

    public static boolean isLonger(int height, int m, long[] trees) {
        long sum = 0;
        for (long tree : trees) {
            sum += Math.max(tree - height, 0);
        }
        return sum >= m;
    }

    public static long getMaxHeight(int n, int m, long[] trees) {
        int start = 0;
        int end = 1_000_000_000;
        int result = 0;
        while(start <= end) {
            int mid = (start + end) / 2;
            if (isLonger(mid, m, trees)) {
                result = Math.max(mid, result);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long[] trees = new long[n];
        for (int i = 0; i < n; i++) {
            trees[i] = Integer.parseInt(st.nextToken());
        }

        long maxHeight = getMaxHeight(n, m, trees);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Long.toString(maxHeight));
        bw.flush();

        br.close();
        bw.close();
    }
}
