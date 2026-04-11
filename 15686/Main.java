import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<int[]> house;
    static ArrayList<int[]> chicken;
    static ArrayList<int[]> picked;
    static int N, M;
    static int result = Integer.MAX_VALUE;
    static boolean[] visited;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[][] map = new int[N][N];
        for(int i=0; i<N; ++i){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; ++j){
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 1){
                    house.add(new int[]{i,j});
                } else if (map[i][j] == 2){
                    chicken.add(new int[]{i,j});
                }
            }
        }

        visited = new boolean[chicken.size()];

        back(0,0);

        System.out.println(result);
    }

    static void back(int x, int m){
        if(m == M){
            int sum = 0; // 도시의 치킨 거리
            for(int[] h : house){
                int min = Integer.MAX_VALUE;
                for(int[] p : picked){
                    int distance = Math.abs(h[0] - p[0]) + Math.abs(h[1] - p[1]);
                    min = Math.min(distance, min); //각 집의 치킨 거리 찾기
                }
                sum += min; // 각 집의 치킨 거리의 합을 거해서 도시의 치킨 거리 
            }
            result = Math.min(result, sum);
            return;
        }

        for(int i = x; i < chicken.size(); ++i){
            if(!visited[i]){
                visited[i] = true;
                picked.add(chicken.get(i));
                back(i+1, m+1);
                visited[i] = false;
                picked.remove(picked.size()-1);
            }
        }
    }
}
