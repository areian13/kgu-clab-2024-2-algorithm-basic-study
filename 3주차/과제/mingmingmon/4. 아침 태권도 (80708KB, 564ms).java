import java.util.*;
import java.io.*;
public class Main{

    public static class Position {
        boolean isPositive;
        double inclination;

        Position(boolean isPositive, double inclination) {
            this.isPositive = isPositive;
            this.inclination = inclination;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Position other = (Position) o;

            return other.isPositive == this.isPositive && other.inclination == this.inclination;
        }

        @Override
        public int hashCode() {
            int h1 = Double.hashCode(inclination);
            int h2 = Boolean.hashCode(isPositive);
            return h1 ^ (h2 << 1);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        HashSet<Position> students = new HashSet<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            double direction = x / (double)y;
            // 0에 대한 처리를 생각하지 못했습니다. 다만 출력해보니 자바 자체에서 Infinity라는 값으로 내부처리 해주는 것 같습니다.
            students.add(new Position(x > 0, direction));
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int result = students.size();
        bw.write(Integer.toString(result));
        bw.flush();
    }
}
