import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {

    public static boolean isOpenBucket(char curr) {
        return (curr == '(' || curr == '[');
    }

    public static boolean isCloseBucket(char curr) {
        return (curr == ')' || curr == ']');
    }

    public static boolean isSetBucket(char curr, char previousBucket) {
        if (previousBucket == '[' && curr == ']') {
            return true;
        }
        if (previousBucket == '(' && curr == ')') {
            return true;
        }
        return false;
    }

    public static boolean isBalanced(String line) {
        Stack<Character> stack = new Stack<>();
        int n = line.length();
        for (int i = 0; i < n; i++) {
            char curr = line.charAt(i);
            if (isOpenBucket(curr)) {
                stack.push(curr);
            }
            if (isCloseBucket(curr)) {
                if (stack.isEmpty()) {
                    return false;
                }
                char previousBucket = stack.pop();
                if (!isSetBucket(curr, previousBucket)) {
                    return false;
                }
            }
        }
        if (!stack.isEmpty()) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line;
        while(!(line = br.readLine()).equals(".")) {
            if (isBalanced(line)) {
                bw.write("yes\n");
            } else {
                bw.write("no\n");
            }
        }

        bw.flush();

        br.close();
        bw.close();
    }
}
