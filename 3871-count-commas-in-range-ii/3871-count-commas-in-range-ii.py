class Solution(object):
    def countCommas(self, n):
        """
        :type n: int
        :rtype: int
        """
        return sum(max(0, n-1000**i+1) for i in range(1,6))
        