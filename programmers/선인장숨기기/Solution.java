import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class Solution {
    public int[] solution(int m, int n, int h, int w, int[][] drops) {
        int[][] arr = new int[m][n];
        for (int[] r : arr) {
            Arrays.fill(r, Integer.MAX_VALUE);
        }

        for(int i = 0; i < drops.length; ++i){
            int x = drops[i][0];
            int y = drops[i][1];

            arr[x][y] = i+1; //빗방울 순서
        }

        int[] answer = sliding(m, n, h, w, arr);
        return answer;
    }
    
    private int[] sliding(int m, int n, int h, int w, int[][] arr){
        Deque<Integer> dq = new ArrayDeque<>();
        int nn = n - w + 1;
        int[][] row_sliding = new int[m][nn];

        //가로 슬라이딩
        for(int i = 0; i < m; ++i){
            dq.clear();
            for(int j = 0; j < n; ++j){
                while(!dq.isEmpty() && arr[i][dq.getLast()] >= arr[i][j]){
                    dq.removeLast();
                }
                dq.addLast(j);
                if(dq.getFirst() <= j - w){
                    dq.removeFirst();
                }
                if(j >= w - 1) {
                    row_sliding[i][j-w+1] = arr[i][dq.getFirst()];
                }
            }
        }

        int max = 0;
        int[] result = {0,0};

         //세로 슬라이딩
        for (int i = 0; i < nn; ++i) {
            dq.clear();
            for (int j = 0; j < m; ++j){
                while (!dq.isEmpty() && row_sliding[dq.getLast()][i] >= row_sliding[j][i]) {
                    dq.removeLast();
                }
                dq.addLast(j);
                if (dq.getFirst() <= j - h) {
                    dq.removeFirst();
                }
                if (j >= h - 1) {
                    int cur = row_sliding[dq.getFirst()][i];
                    int tmpRow = j - h + 1;

                    if (max < cur) {
                        max = cur;
                        result[0] = tmpRow;
                        result[1] = i;
                    } else if (max == cur) {
                        if (tmpRow < result[0]) {
                            result[0] = tmpRow;
                            result[1] = i;
                        } else if (tmpRow == result[0]) {
                            if (i < result[1]) {
                                result[0] = tmpRow;
                                result[1] = i;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
}