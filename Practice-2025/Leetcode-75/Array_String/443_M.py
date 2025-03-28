def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        if len(chars) == 1:
            return 1
        num_index = 0
        i = 0

        while i < len(chars):
            ref = chars[i]
            count = 1
            i += 1
            while i < len(chars) and chars[i] == ref:
                count += 1
                i += 1
            chars[num_index] = ref
            num_index += 1
            if count > 1:
                num_array = [ch for ch in str(count)]
                chars[num_index:num_index + len(num_array)] = num_array
                num_index += len(num_array)
        return num_index