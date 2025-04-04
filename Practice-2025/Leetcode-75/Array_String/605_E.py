def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        for i in range(len(flowerbed)):
            l = i == 0 or flowerbed[i-1] == 0
            r = i == len(flowerbed) - 1 or flowerbed[i + 1] == 0
            if l and r and flowerbed[i] == 0:
                flowerbed[i] = 1
                n -= 1
            if n <= 0:
                return True
        return False