import java.util.*;

class Solution {
    private boolean[] completed;
    
    ArrayList<Integer> ans = new ArrayList<>();
    
    public int[] solution(int[] progresses, int[] speeds) {
        completed = new boolean[progresses.length];
        
        job(progresses, speeds);
        int[] answer = new int[ans.size()];
        for(int i = 0; i < ans.size(); i++) {
            answer[i] = ans.get(i).intValue();
        }
        return answer;
    }
    
    public void job(int[] progresses, int[] speeds) {
        int cur = 0, end = progresses.length - 1;
        while (cur <= end) {
            for (int i = cur; i <= end; i++) {
                if (completed[i] == true) continue;
                progresses[i] += speeds[i];
                if (progresses[i] >= 100) completed[i] = true;
            }
            
            if(completed[cur] == true) {
                int i;
                int cnt = 0;
                for(i = cur; i <= end; i++) {
                    if(completed[i] == true) {
                        cnt++;
                    } else {
                        break;
                    }
                }
                ans.add(cnt);
                cur = i;
            }
        }
    }
}