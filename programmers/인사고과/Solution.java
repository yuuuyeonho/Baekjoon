
class Solution {
    private int maxScore = 100000;

    public int solution(int[][] scores) {
        int[] maxPrScores = new int[maxScore + 2];

        for (int[] score : scores) {
            int wa = score[0];
            int pr = score[1];
            if (maxPrScores[wa] < pr) maxPrScores[wa] = pr;
        }

        for (int i = maxScore; i > 0; i--) {
            if (maxPrScores[i - 1] < maxPrScores[i]) maxPrScores[i - 1] = maxPrScores[i];
        }

        int WanhoWa = scores[0][0];
        int WanhoPr = scores[0][1];
        int WanhoScore = WanhoWa + WanhoPr;

        if (WanhoPr < maxPrScores[WanhoWa + 1]) {
            return -1;
        }

        int rank = 1;

        for (int[] score : scores) {
            int wa = score[0];
            int pr = score[1];
            if (wa + pr > WanhoScore && pr >= maxPrScores[wa + 1]) {
                rank++;
            }
        }
    
        return rank;
    }
}