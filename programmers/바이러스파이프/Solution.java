import java.util.*;

class Solution {
    private int max;
    private Map<Integer, List<int[]>> map;

    public int solution(int n, int infection, int[][] edges, int k) {
        boolean[] isInfected = new boolean[n + 1];
        isInfected[infection] = true;

        map = new HashMap<>();
        for (int i = 1; i < n+1; ++i) {
            map.put(i, new ArrayList<>());
        }

        for (int[] edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int type = edge[2];
            
            map.get(x).add(new int[]{y, type});
            map.get(y).add(new int[]{x, type});
        }

        for (int i = 1; i <= 3; i++) {
                dfs(isInfected, i, 0, k);
        }

        return max;
    }

    public void dfs(boolean[] isInfected, int type, int cur, int k) { 
        if (cur == k) {
            calculateMax(isInfected);
            return;
        }

        boolean[] curInfected = infection(isInfected, type);

        for(int i = 1; i <= 3; i ++) {
            dfs(curInfected, i, cur + 1, k);
        }
    }

    public boolean[] infection(boolean[] isInfected, int type) {
        boolean[] result = isInfected.clone();
        Deque<Integer> dq = new ArrayDeque<>();

        for (int i = 0; i < isInfected.length; i++) {
            if (isInfected[i]) {
                dq.add(i);
            }
        }

        while (!dq.isEmpty()) {
            int tmp = dq.poll();
            for (int[] next : map.get(tmp)) {
                int nnode = next[0];
                int edgeType = next[1];

                if (edgeType == type && !result[nnode]) {
                    result[nnode] = true;
                    dq.add(nnode);
                }
            }
        }
        
        return result;
    }

    public void calculateMax(boolean[] isInfected) {
        int cnt = 0;
        for (boolean b : isInfected) {
            if (b) cnt++;
        }
        max = Math.max(max, cnt);
    }
}