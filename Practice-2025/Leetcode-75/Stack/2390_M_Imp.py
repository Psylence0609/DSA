def removeStars(self, s: str) -> str:
        s1 = ""
        ct = 0
        for i in range(len(s) - 1, -1 , -1):
            if s[i] == '*':
                ct += 1
            elif s[i] != '*' and ct == 0:
                s1 += s[i]
            else: 
                ct -= 1
        return s1[::-1]

def removeStars(self, s: str) -> str:
        stack = []
        for ch in s:
            if ch != '*':
                stack.append(ch)
            else:
                stack.pop()
        return "".join(stack)