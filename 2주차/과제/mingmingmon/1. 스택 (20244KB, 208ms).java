import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> stack = new Stack<>();
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String command = st.nextToken();

            switch(command) {
                case "push" :
                    int number = Integer.parseInt(st.nextToken());
                    stack.push(number);
                    break;
                case "pop" :
                    int pop = stack.isEmpty() ? -1 : stack.pop();
                    bw.write(pop + "\n");
                    break;
                case "size" :
                    bw.write(stack.size() + "\n");
                    break;
                case "empty" :
                    int result = stack.isEmpty() ? 1 : 0;
                    bw.write(result + "\n");
                    break;
                case "top" :
                    int top = stack.isEmpty() ? -1 : stack.peek();
                    bw.write(top + "\n");
                    break;
            }
        }
        bw.flush();

        br.close();
        bw.close();
    }
}
