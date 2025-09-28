import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static int[] stack = new int[10001];
    public static int size = 0;

    public static void push(int n){
        stack[size] = n;
        size++;
    }

    public static int pop(){
        if(size==0){
            return -1;
        }
        return stack[--size];
    }

    public static int empty(){
        if(size==0) return 1;
        else return 0;
    }

    public static int top(){
        if(size==0) return -1;
        else return stack[size-1];
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = in.nextInt();
        for(int i=0; i<n; ++i){
            String str = in.next();
            switch (str){

                case "push":
                    push(in.nextInt());
                    break;

                case "pop":
                    sb.append(pop()).append('\n');
                    break;

                case "size":
                    sb.append(size).append('\n');
                    break;

                case "empty":
                    sb.append(empty()).append('\n');
                    break;

                case "top":
                    sb.append(top()).append('\n');
                    break;
            }
        }
        System.out.println(sb);
    }
}