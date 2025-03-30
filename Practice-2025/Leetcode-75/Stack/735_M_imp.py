def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for ast in asteroids:
            cancel =0
            if ast >= 0:
                stack.append(ast)
            else:
                if len(stack) == 0 or stack[-1] < 0:
                    stack.append(ast)
                    continue
                while len(stack) != 0:
                    if stack[-1] > 0 and stack[-1] < abs(ast):
                        stack.pop()
                    elif stack[-1] > 0 and stack[-1] == abs(ast):
                        stack.pop()
                        cancel = 1
                        break
                    elif stack[-1] < 0:
                        stack.append(ast)
                        break
                    else: break
                if not cancel and len(stack) == 0:
                    stack.append(ast)
        return stack