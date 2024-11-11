import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        HashSet<Double> upStudent = new HashSet<>();
        HashSet<Double> downStudent = new HashSet<>();

        int result = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            double direction = x / (double)y;

            if(x < 0){
                if(!downStudent.contains(direction)) {
                    result++;
                    downStudent.add(direction);
                }
            }

            else{
                if(!upStudent.contains(direction)){
                    result++;
                    upStudent.add(direction);
                }
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(Integer.toString(result));
        bw.flush();
    }
}
