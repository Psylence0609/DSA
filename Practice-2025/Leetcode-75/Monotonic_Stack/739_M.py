def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        res = [0] * len(temperatures)
        for i in range(len(temperatures)):
            while st and temperatures[i] > temperatures[st[-1]]:
                index = st.pop()
                res[index] = i - index
            st.append(i)
        return res\