import java.util.*;

class Solution {
    private int cnt = 0;
    private boolean[] isVisited;
    
    public int solution(int n, int[][] computers) {
        isVisited = new boolean[n];
        
        findNetwork(n, computers);
        
        return cnt;
    }
    
    public void findNetwork(int n, int[][] computers) {
        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                bfs(i, n, computers);
                cnt++;
            }
        }
    }
    
    public void bfs(int c, int n, int[][] computers) {
        Deque<Integer> dq = new ArrayDeque<>();
        
        dq.add(c);
        while(!dq.isEmpty()) {
            int cur = dq.poll();
            isVisited[cur] = true;
            for (int i = 0; i < n; i++) {
                if (computers[cur][i] == 1 && !isVisited[i]) {
                    dq.add(i);
                }
            }
        }
    }
}