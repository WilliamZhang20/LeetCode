class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        while l < r:
            mid = (l + r) // 2
            hour_spent = 0
            for pile in piles:
                hour_spent += math.ceil(pile / mid)
            if hour_spent > h:
                l = mid + 1
            else:
                r = mid
        return l