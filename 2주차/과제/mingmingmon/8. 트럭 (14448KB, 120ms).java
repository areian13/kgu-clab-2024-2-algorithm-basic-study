import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static class Truck {
        int weight;
        int startTime;

        Truck(int weight, int startTime) {
            this.weight = weight;
            this.startTime = startTime;
        }

        boolean isArrivedAtEnd(int currTime, int w){
            return(currTime - startTime == w);
        }
    }

    public static int getMinAcrossTime(int n, int w, int l, int[] trucks) {
        Queue<Truck> q = new LinkedList<>();
        int time = 0;
        int sumOfWeight = 0;
        int index = 0;

        while(!q.isEmpty() || index < n) {
            time++;
            if (!q.isEmpty() && q.peek().isArrivedAtEnd(time, w)) {
                sumOfWeight -= q.poll().weight;
            }
            if (index < n && sumOfWeight + trucks[index] <= l && q.size() < w) {
                q.offer(new Truck(trucks[index], time));
                sumOfWeight += trucks[index++];
            }
        }

        return time;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        int[] trucks = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            trucks[i] = Integer.parseInt(st.nextToken());
        }

        int minTime = getMinAcrossTime(n, w, l, trucks);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(minTime));
        bw.flush();

        br.close();
        bw.flush();
    }
}
