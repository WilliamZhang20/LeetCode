class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        n = len(heightMap)
        m = len(heightMap[0])
        ok = lambda i, j: 0 <= i < n and 0 <= j < m and (i, j) not in vis
        enclosingHeight = deepcopy(heightMap)
        minPq = []
        for i in range(n):
            minPq.append((heightMap[i][0], i, 0))
            minPq.append((heightMap[i][m-1], i, m-1))
        for j in range(m):
            minPq.append((heightMap[0][j], 0, j))
            minPq.append((heightMap[n-1][j], n-1, j))
        heapify(minPq)
        vis = set()
        ans = 0
        while minPq:
            h, i, j = heappop(minPq)
            if (i, j) in vis:
                continue
            vis.add((i, j))
            ans += enclosingHeight[i][j] - h
            for di, dj in ((0, 1), (1, 0), (0, -1), (-1, 0)):
                if not ok(i+di, j+dj): continue
                heappush(minPq, (heightMap[i+di][j+dj], i+di, j+dj))
                enclosingHeight[i+di][j+dj] = max(enclosingHeight[i+di][j+dj], enclosingHeight[i][j])
        return ans