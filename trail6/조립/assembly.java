import java.util.*;

public class Main {
  static int n;
  // graph[x][y] = x 1개에 필요한 y 개수
  static int[][] graph;
  // need[x][b] = x 1개에 드는
  //   기본 부품 b의 개수
  static int[][] need;
  static boolean[] done;

  static int[] count(int part) {
    if (done[part]) return need[part];

    boolean isBasic = true;
    for (int sub = 0; sub < n; sub++) {
      int k = graph[part][sub];
      if (k == 0) continue;
      isBasic = false;

      int[] subNeed = count(sub);
      for (int b = 0; b < n; b++) {
        need[part][b] += k * subNeed[b];
      }
    }
    // 재료가 없으면 기본 부품: 자기 1개
    if (isBasic) need[part][part] = 1;

    done[part] = true;
    return need[part];
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();
    int m = sc.nextInt();

    // 행마다 새 배열이 생김
    graph = new int[n][n];
    need = new int[n][n];
    done = new boolean[n];

    for (int i = 0; i < m; i++) {
      int x = sc.nextInt() - 1; // 만들 것
      int y = sc.nextInt() - 1; // 재료
      int k = sc.nextInt();     // 개수
      graph[x][y] = k;
    }

    int[] answer = count(n - 1);
    for (int b = 0; b < n; b++) {
      if (answer[b] == 0) continue;
      System.out.println(
          (b + 1) + " " + answer[b]);
    }
  }
}