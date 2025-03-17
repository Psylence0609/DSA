## https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(gas) < sum(cost):
            return -1
        current = 0
        start = 0
        for i in range(len(gas)):
            current += gas[i] - cost[i]
            if current < 0:
                current = 0
                start = i + 1
        return start