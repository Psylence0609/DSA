def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr_dict = {}
        freq_dict = {}
        for i in arr:
            arr_dict[i] = arr_dict.get(i, 0) + 1
        for i in arr_dict:
            if arr_dict[i] in freq_dict:
                return False
            else:
                freq_dict[arr_dict[i]] = 1
        return True