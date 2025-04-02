def maxProfit(self, prices: List[int], fee: int) -> int:
        t1 = 0
        t2 = float('-inf')
        for price in prices:
            told = t1
            t1 = max(t1, t2 + price)
            t2 = max(t2, told - price - fee)
        return t1