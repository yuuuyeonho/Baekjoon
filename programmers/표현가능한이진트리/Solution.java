class Solution {
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        String[] binaryNumStrs = toBinaryNumStrs(numbers);        
        
        for (int i = 0; i < numbers.length; i++) {
            answer[i] = dfs(binaryNumStrs[i]) ? 1 : 0;
        }
        
        return answer;
    }
    
    public boolean dfs(String str) {
        if (str.length() == 1) return true;
        int mid = str.length() / 2;
        String front = str.substring(0,mid);
        String back = str.substring(mid + 1);
    
        if (str.charAt(mid) == '0') {
            if (front.contains("1") ||
            back.contains("1")) {
                return false;
            }
        } 
        return dfs(front) && dfs(back);
    }
    
    public String[] toBinaryNumStrs(long[] numbers) {
        String[] binaryNumStrs = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            binaryNumStrs[i] = Long.toBinaryString(numbers[i]);
            int len = binaryNumStrs[i].length();
            int tmp = 2;
            while(len > tmp - 1) {
                tmp *= 2;
            }
            int diff = tmp - 1 - len;
            for (int j = 0; j < diff; j++) {
                binaryNumStrs[i] = "0" + binaryNumStrs[i];
            }
        }
        return binaryNumStrs;
    }
}