import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static int[] dirRow = {-1, 0, 1, 0};
    public static int[] dirCol = {0, 1, 0, -1};

    public static class Point {
        int row;
        int col;

        Point(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    public static int getTimeForAllTomatoesToRipen(int n, int m, int[][] box, List<Point> ripenedTomatoes) {
        Queue<Point> q = new LinkedList<>();
        for (Point ripenedTomato : ripenedTomatoes) {
            q.add(ripenedTomato);
        }

        int day = -1;

        while(!q.isEmpty()) {
            int numberOfNewlyRipenedTomatoes = q.size();
            for (int i = 0; i < numberOfNewlyRipenedTomatoes; i++) {
                Point currTomato = q.poll();
                int currRow = currTomato.row;
                int currCol = currTomato.col;

                for (int j = 0; j < 4; j++) {
                    int nextRow = currRow + dirRow[j];
                    int nextCol = currCol + dirCol[j];
                    if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) {
                        continue;
                    }
                    if (box[nextRow][nextCol] == -1) {
                        continue;
                    }
                    if (box[nextRow][nextCol] == 1) {
                        continue;
                    }
                    box[nextRow][nextCol] = 1;
                    q.add(new Point(nextRow, nextCol));
                }
            }
            day++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (box[i][j] == 0)
                    return -1;
            }
        }

        return day;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[][] box = new int[n][m];
        List<Point> ripenedTomatoes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int curr = Integer.parseInt(st.nextToken());
                box[i][j] = curr;
                if (curr == 1) {
                    ripenedTomatoes.add(new Point(i, j));
                }
            }
        }

        int allTomatoesRipenedDate = getTimeForAllTomatoesToRipen(n, m, box, ripenedTomatoes);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(allTomatoesRipenedDate));
        bw.flush();

        br.close();
        bw.close();
    }
}
