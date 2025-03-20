## https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        left = 0
        right = 1
        global_profit = 0
        local_profit = 0
        while right < len(prices):
            if prices[right]<prices[right-1]:
                global_profit += prices[right-1] - prices[left]
                left = right

            right += 1
        if left != right-1:
            global_profit += prices[right-1] - prices[left]
        return global_profit