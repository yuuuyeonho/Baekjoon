import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    private static int N;
    private static int[] board;
    private static int result = 0;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        board = new int[N];

        back(0);

        System.out.println(result);
    }

    static void back(int n) {
        if(n == N){
            result++;
            return;
        }

        for(int i = 0; i < N; ++i) {
            board[n] = i;
            
            if(isPossible(n)){
                back(n+1);
            }
        }
    }

    static boolean isPossible(int n) {
        for(int i = 0; i < n; ++ i){
            if(board[i] == board[n]){
                return false;
            } else if (Math.abs(i - n) == Math.abs(board[i] - board[n])) {
                return false;
            }
        }
        return true;
    }
}
