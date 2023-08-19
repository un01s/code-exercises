###
/*
 * leetcode 2814
 * minimum time takes to reach destination without drowning
 *
 * https://www.youtube.com/watch?v=TjQc2cCfc_8
 * https://www.youtube.com/@codeyao9796
 * Code-Yao
 *
 * nxm 0-indexed grid land
 * - S: start cell
 * - D: destination cell
 * - . empty cell
 * - X stone cell, obstacle
 * - * flooded cell, obstacle
 *
 * at each second, you can move to a cell shares a side with your current cell
 * at each second, every empty cell that shares a side with a flooded cell 
 *   becomes flooded as well.
 *
 * you can't step on stone cells
 * you can't step on flooded cells
 * you can't step on a cell that will be flooded at the same time as you step on
 *
 * return the minimum time it takes you to reach the destination in second,
 * or -1 if it is impossible
 *
 * Destination will never be flooded.
 * only one S and only one D
 *
 * 
 * input: land = [["D", ".", "*"],[".", ".", "."],[".", "S", "."]]]
 * output: 3
 *
 * BFS, Dijkstra's algo
 *
 * first, BFS to get the time for each empty cell to be flooded
 * second, BFS to find minimum time 
 */

###

// python
class Solution:
    def minimumSeconds(self, land: List[List[str]]) -> int:
        m, n = len(land), len(land[0])
        start, dest, obstacles, water, empties = None, None, set(), set(), set()
        for i in range(m):
            for j in range(n):
                if land[i][j] == "S":
                    start = (i, j)
                elif land[i][j] == "D":
                    dest = (i, j)
                elif land[i][j] == ".":
                    empties.add((i, j))
                elif land[i][j] == "X":
                    obstacles.add((i, j))
                else:
                    water.add((i, j))
        #
        # first BFS: empty can be flooded
        #
        empties.add(start)
        q = collections.deque([(i, j, 0) for i, j in water])
        visited = collections.defaultdict()
        while q:
            i, j, t = q.popleft()
            if (i, j) not in visited:
                visited[i, j] = t;
                for r, c in {(i-1, j), (i+1, j), (i, j-1), (i, j+1)}:
                    if (r, c) in empties and (r, c) not in visited:
                        q.append((r, c, t+1))
        #
        # 2nd BFS
        if start in water:
            return -1;
        #
        q = collections.deque([(*start, 0)])
        seen = set()
        while q:
            i, j, t = q.popleft()
            if (i, j) == dest:
                return t;
            if (i, j) not in seen:
                seen.add((i, j))
                for r, c in {(i-1, j), (i+1, j), (i, j-1), (i, j+1)}:
                    if (r,c) in empties and (r,c) not in seen and ((r,c) not in visited or t+1 < visited[r, c]):
                        q.append((r,c,t+1))
                    if (r,c)==dest and ((r,c) not in visited or t+1 < visited[r, c]):
                        return t+1;
        return -1;

