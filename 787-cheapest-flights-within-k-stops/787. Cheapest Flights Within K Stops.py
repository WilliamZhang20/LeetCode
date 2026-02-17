from collections import defaultdict
import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, w in flights:
            graph[u].append((v, w))
        INF = float('inf')
        stops = [INF] * n
        min_heap = [(0, src, 0)]
        while min_heap:
            curr_dist, node, steps = heapq.heappop(min_heap)
            
            if steps >= stops[node] or steps > k + 1:
                continue

            stops[node] = steps

            if node == dst:
                return curr_dist

            for neighbor, weight in graph[node]:
                heapq.heappush(min_heap, (curr_dist + weight, neighbor, steps+1))

        return -1