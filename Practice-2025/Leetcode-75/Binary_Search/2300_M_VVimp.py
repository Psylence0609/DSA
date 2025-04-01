def search(self, potions: List[int], target): ## returns the indexwhose value is greater than or equal to target
        low = 0
        high = len(potions)
        while low < high:
            mid = low + (high - low) // 2
            if potions[mid] >= target:
                high = mid
            else:
                low = mid + 1
        return low
        

def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
    potions.sort()
    result = []
    n_potions = len(potions)
    for spell in spells:
        min_potion_needed = (success + spell - 1) // spell
        first_successful_potion_index = self.search(potions, min_potion_needed)
        # The number of successful pairs for the current spell is the number of potions
        # that are greater than or equal to the minimum needed.
        result.append(n_potions - first_successful_potion_index)
    return result