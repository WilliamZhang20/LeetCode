class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        level = [-1] * n
        parent = [-1] * n
        low = [float('inf')] * n

        graph = defaultdict(list)

        for connection in connections:
            a = connection[0]
            b = connection[1]
            graph[a].append(b)
            graph[b].append(a)
        
        self.output = []
        self.time = 0

        def dfs(cur):
            level[cur] = self.time
            low[cur] = self.time

            self.time += 1

            for neighbor in graph[cur]:
                if level[neighbor] == -1: # not already seen
                    parent[neighbor] = cur
                    dfs(neighbor)
                    low[cur] = min(low[cur], low[neighbor])

                    if low[neighbor] > level[cur]: # no backedge
                        self.output.append([cur, neighbor])

                elif neighbor != parent[cur]: # backedge
                    low[cur] = min(low[cur], level[neighbor])
        
        dfs(0)
        
        return self.output