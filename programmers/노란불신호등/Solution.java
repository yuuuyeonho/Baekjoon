/**
 * 각 신호등 주기의 최소공배수 구하기
 * 최소공배수까지 노란불이 나오는지 확인 -> 각 신호등마다 노란불 시간에 +1
 * 최소공배수까지 모두 노란불이 없으면 -1 반환
 */
class Solution {
    public int solution(int[][] signals) {
        int n = signals.length; 

        int[] cycle = new int[n];
        for(int i = 0; i < n; ++i) {
            cycle[i] = signals[i][0] + signals[i][1] + signals[i][2];
        }

        int lcm = getLCM(cycle, n);

        int[] timeList = new int[lcm + 1]; // 문제에서 시간이 1부터 시작

        for(int i = 0; i < n; ++i) {
            int g = signals[i][0];
            int y = signals[i][1];
            int c = cycle[i];
            for(int j = 1; j <= lcm; j += c) {
                for(int k = j + g; k < j + g + y; ++k) {
                    timeList[k]++;
                }
            }
        }

        for(int i = 1; i <= lcm; ++i) {
            if(timeList[i] == n) {
                return i;
            }
        }
        return -1;
    }

    public int getLCM(int[] list, int n) {
        if(n == 1) return list[0];

        int gcd = getGCD(list[0], list[1]);
        int lcm = (list[0] * list[1]) / gcd;

        for(int i = 2; i < n; ++i) {
            gcd = getGCD(lcm, list[i]);
            lcm = (lcm * list[i]) / gcd;
        }

        return lcm;
    }

    public int getGCD(int a, int b) {
        if(a % b == 0) {
            return b;
        }
        return getGCD(b, a % b);
    }
}