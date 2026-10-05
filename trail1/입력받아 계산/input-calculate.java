import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Please write your code here.
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        String[] str=br.readLine().split(" ");
        int a=Integer.parseInt(str[0]);
        bw.write(a+2+"");
        bw.newLine();
        bw.flush();
        bw.close();
    }
}