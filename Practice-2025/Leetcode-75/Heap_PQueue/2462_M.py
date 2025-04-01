heap = [] # empty heap
        total_cost = 0 # total cost set to zero
        for i in range(candidates): # for every candidate in candidates
            heapq.heappush(heap, (costs[i],i)) # pushing the value in heap with cost and index
        front_end = i # assign frontend to i
        back_end = max(front_end + 1, len(costs) - candidates) # calculating max and assigning it to be backend
        for j in range(back_end, len(costs)): # for every elmt from backend to length of cost
            heapq.heappush(heap, (costs[j], j)) #pushing it to heap with cost and index

        while k > 0: # while k is greater than 0
            cost, i = heapq.heappop(heap) # popping the next smallest cost from heap
            total_cost += cost # appending the cost to total cost
            k -= 1 # decrementing k
            if front_end < back_end - 1: # if frontend is less than backend -1
                if i <= front_end: # and if is also less than or equal to front_end
                    front_end += 1 # increment frontend
                    heapq.heappush(heap, (costs[front_end], front_end)) # appending frontend to heap with cost and index
                else: # if i is not less than frontend
                    back_end -= 1 # decrement backend
                    heapq.heappush(heap, (costs[back_end], back_end)) # appending backend to heap with cost and index
        return total_cost # returning total cost as output