import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    // 블루레이의 크기가 커질 수록 수용 가능한 녹화 길이가 커진다. 증가 그래프
    // m개의 블루레이에 모든 강의를 담을 수 있는 최소 블루레이 크기

    public static boolean canRecord(int size, int n, int m, int[] times) {
        int index = 0;
        int sum = 0;
        while(m > 0) {
            if (index == times.length) {
                break;
            }
            if (sum + times[index] > size) {
                sum = 0;
                m--;
            } else {
                sum += times[index++];
            }
        }
        return index == times.length;
    }

    public static int getMinBlueRay(int n, int m, int[] times) {
        int start = 0;
        int end = 1000_000;
        int result = Integer.MAX_VALUE;

        while(start <= end) {
            int mid = (start + end) / 2;
            if (canRecord(mid, n, m, times)) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
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
        int[] times = new int[n];
        for (int i = 0; i < n; i++) {
            times[i] = Integer.parseInt(st.nextToken());
        }

        int minSize = getMinBlueRay(n, m, times);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(minSize));
        bw.flush();

        br.close();
        bw.close();
    }
}
