class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        ans = []
        full = set()
        pq = []
        idxs = defaultdict(deque)
        for i, lake in enumerate(rains):
            if lake:
                idxs[lake].append(i)
        for lake in rains:
            if lake:
                if lake in full:
                    return []
                idxs[lake].popleft()
                if idxs[lake]:
                    next_idx = idxs[lake][0]
                    heappush(pq, (next_idx, lake))
                full.add(lake)
                ans.append(-1)
            else:  # Dry
                if pq:
                    _, to_remove = heappop(pq)
                else:
                    to_remove = 1  # It doesn't matter
                full.discard(to_remove)
                ans.append(to_remove)

        return ans