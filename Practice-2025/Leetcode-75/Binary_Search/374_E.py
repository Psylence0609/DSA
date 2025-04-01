def guessNumber(self, n: int) -> int:
        low = 1
        while low <= n:
            mid = low + (n - low) // 2
            # print(mid)
            api = guess(mid)
            if api == 0:
                return mid
            elif api == -1:
                n = mid - 1
            else:
                low = mid + 1
        return -1