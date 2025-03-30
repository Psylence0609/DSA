def predictPartyVictory(self, senate: str) -> str:
        rad = []
        dire = []
        for i in range(len(senate)):
            if senate[i] == 'R':
                rad.append(i)
            else: dire.append(i)
        count = len(senate)
        i = 0
        while i < len(rad) and i < len(dire):
            if rad[i] < dire[i]:
                rad.append(count)
            else:
                dire.append(count)
            count += 1
            i += 1
        if i == len(rad):
            return "Dire"
        else: return "Radiant"