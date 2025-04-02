def minFlips(self, a: int, b: int, c: int) -> int:
        count = 0
        while a != 0 or b != 0 or c != 0:
            or_op = a % 2 or b % 2
            if or_op == 0 and c % 2 == 1:
                count += 1
            elif or_op == 1 and c % 2 == 0:
                if a%2 == 1 and b%2 == 1: count += 2
                else: count += 1
            a = a // 2
            b = b // 2
            c = c // 2
            print(count)
        return count