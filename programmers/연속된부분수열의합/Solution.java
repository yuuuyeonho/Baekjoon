class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0, 0};
        int start = 0, end = 0;
        
        int sum = 0;
        int min = 1000001;
        
        while (start < sequence.length){
            while(sum < k && end < sequence.length) {
                sum += sequence[end];
                end++;
            }
            if (sum == k) {
                if ((end - start) < min) {
                    min = end - start;

                    answer[0] = start;
                    answer[1] = end - 1;
                }
            }
            
            sum -= sequence[start];
            start++;
        }
        
        return answer;
    }
}