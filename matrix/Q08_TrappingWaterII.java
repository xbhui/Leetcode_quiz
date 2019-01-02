package part1_basic_lesson.s12_queue_heap;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by mengzhou on 7/19/17.
 */
public class Q08_TrappingWaterII {

    public int trapRainWater(int[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0) return 0;
        
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(o -> matrix[o[0]][o[1]]));
        boolean[][] visited = new boolean[matrix.length][matrix[0].length];

        // step 2: add four border into dp
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[0].length; j++) {
                if(i == 0 || j == 0 || i == matrix.length - 1 || j == matrix[0].length - 1) {
                    minHeap.add(new int[]{i, j});
                    visited[i][j] = true;
                }
            }
        }
        int res = 0;
        // step 3: travel the matrix
        while(!minHeap.isEmpty()) {
            int[] cur = minHeap.poll();
            visited[cur[0]][cur[1]] = false;
            res += dfs(matrix, visited, cur, cur[0], cur[1], minHeap);
        }
        return res;
    }

    public int dfs(int[][] matrix, boolean[][] visited, int[] cur, int x, int y, PriorityQueue<int[]> minHeap) {
        if(x < 0 || x >= matrix.length || y < 0 || y >= matrix[0].length) return 0;
        if(visited[x][y]) return 0;

        if(cur[0] != x || cur[1] != y) minHeap.add(new int[]{x, y});
        visited[x][y] = true;

        if(matrix[x][y] > matrix[cur[0]][cur[1]]) return 0;

        int temp = matrix[cur[0]][cur[1]] - matrix[x][y];
        temp += dfs(matrix, visited, cur, x + 1, y, minHeap);
        temp += dfs(matrix, visited, cur, x - 1, y, minHeap);
        temp += dfs(matrix, visited, cur, x, y + 1, minHeap);
        temp += dfs(matrix, visited, cur, x, y - 1, minHeap);

        return temp;
    }

    public static void main(String[] args) {
        Q08_TrappingWaterII app = new Q08_TrappingWaterII();
        System.out.println(app.maxTrapped(new int[][]{
                { 2, 3, 4, 2 },
                { 3, 1, 2, 3 },
                { 4, 3, 0, 4 },
                { 6, 4, 6, 5 }
        }));
        System.out.println(app.maxTrapped(new int[][]{
                {1, 9, 2, 5, 8, 4},
                {2, 4, 5, 1, 3, 2},
                {7, 1, 3, 5, 6, 6},
                {8, 5, 9, 3, 3, 4},
                {5, 2, 1, 7, 5, 7}
        }));
    }

    public static class TrappingWaterII {

        public static void main(String[] args) {
            TrappingWaterII app = new TrappingWaterII();
            /*System.out.println(app.trapRainWater(new int[][] {
                    { 1, 4, 3, 1, 3, 2 },
                    { 3, 2, 1, 3, 2, 4 },
                    { 2, 3, 3, 2, 3, 1 }}));*/
            System.out.println(app.trapRainWater(new int[][] {
                    { 1, 3, 4, 2 },
                    { 3, 1, 2, 3 },
                    { 4, 3, 5, 4 }}));
        }

        static class Cell {
            int x;
            int y;
            int h;

            public Cell(int x, int y, int h) {
                this.x = x;
                this.y = y;
                this.h = h;
            }
        }

        public int trapRainWater(int[][] map) {
            if(map.length < 3 || map[0].length < 3) return 0;

            boolean[][] flag = new boolean[map.length][map[0].length];
            PriorityQueue<Cell> queue = new PriorityQueue<>((Cell x, Cell y) -> (x.h - y.h));
            for(int i = 0; i < map.length; i++) {
                for(int j = 0; j < map[0].length; j++) {
                    if(i * j != 0 && i != map.length - 1 && j != map[0].length - 1) continue;
                    queue.add(new Cell(i, j, map[i][j]));
                    flag[i][j] = true;
                }
            }

            int res = 0;
            while(!queue.isEmpty()) {
                Cell cell = queue.poll();
                res += bfs(queue, cell.x, cell.y - 1, cell.h, map, flag);
                res += bfs(queue, cell.x, cell.y + 1, cell.h, map, flag);
                res += bfs(queue, cell.x - 1, cell.y, cell.h, map, flag);
                res += bfs(queue, cell.x + 1, cell.y, cell.h, map, flag);
            }

            return res;
        }

        public int bfs(PriorityQueue<Cell> queue, int x, int y, int h, int[][] map, boolean[][] flag) {
            if(x < 0 || x >= map.length || y < 0 || y >= map[0].length) return 0;
            if(flag[x][y]) return 0;

            queue.add(new Cell(x, y, Math.max(h, map[x][y])));
            flag[x][y] = true;

            return Math.max(0, h - map[x][y]);
        }

    }
}
