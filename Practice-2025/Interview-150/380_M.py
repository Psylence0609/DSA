## https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

import random
class RandomizedSet(object):

    def __init__(self):
        self.set_dict = {}
        self.lst = []
        

    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val in self.set_dict:
            return False
        self.lst.append(val)
        self.set_dict[val] = len(self.lst) - 1
        return True
        

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if not val in self.set_dict:
            return False
        index = self.set_dict[val]
        self.lst[index] = self.lst[-1]
        self.set_dict[self.lst[-1]] = index
        self.lst.pop()
        del self.set_dict[val]
        return True
        

    def getRandom(self):
        """
        :rtype: int
        """
        return random.choice(self.lst)