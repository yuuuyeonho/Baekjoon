class Solution {
    private int[][] map;
    private int[][] dp;

    public int solution(int m, int n, int[][] puddles) {
        map = new int[n+1][m+1];
        dp = new int[n+1][m+1];

        map[1][1] = -1;
        for (int[] puddle : puddles) {
            int r = puddle[1];
            int c = puddle[0];
            map[r][c] = -1;
        }

        dp[1][1] = 1;

        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m+1; j++) {
                if(map[i][j] == -1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j]%=1000000007;
            }
        }
        return dp[n][m];
    }
}