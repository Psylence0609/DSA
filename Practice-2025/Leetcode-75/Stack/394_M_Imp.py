def decodeString(self, s: str) -> str:
        stack = []
        answer = ""
        for ch in s:
            if ch.isalnum() or ch == '[':
                stack.append(ch)
                continue
            if ch == ']':
                word = ""
                while len(stack)!= 0 and stack[-1]!= '[':
                    word = stack[-1] + word
                    stack.pop()
                stack.pop()
                num = ""
                while len(stack)!= 0 and stack[-1].isnumeric():
                    num = stack[-1] + num
                    stack.pop()
                stack.append("".join([word] * int(num)))
        # print(stack)
        for i in stack:
            answer += i
        return answer