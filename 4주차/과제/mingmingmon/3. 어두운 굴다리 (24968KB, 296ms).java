import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    // 가로등의 높이가 높아질 수록 (x값이커질수록) 돈이 많이 든다 (y값이 커진다) 증가 그래프.
    // n을 커버할 수 있는 최소의 y일 때 x값을 구하자.
    public static boolean canCover(int height, int n, int m, int[] spots) {
        int curr = 0;
        for (int i = 0; i < m; i++) {
            int spot = spots[i];
            int start = Math.max(spot - height, 0);
            if (curr < start) {
                return false;
            }
            int end = Math.min(spot + height, n);
            curr = end;
        }
        if (curr != n) {
            return false;
        }
        return true;
    }

    public static int getMinHeight(int n, int m, int[] spots) {
        int start = 0;
        int end = 100_001;
        int result = Integer.MAX_VALUE;
        while(start <= end) {
            int mid = (start + end) / 2;
            if (canCover(mid, n, m, spots)) {
                //System.out.println(mid + "가능");
                result = Math.min(result, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int[] spots = new int[m];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            spots[i] = Integer.parseInt(st.nextToken());
        }

        int minHeight = getMinHeight(n, m, spots);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(minHeight));
        bw.flush();

        br.close();
        bw.close();
    }
}
