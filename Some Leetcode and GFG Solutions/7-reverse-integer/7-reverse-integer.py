class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign=1 if x>0 else -1
        x=sign*(int(str(abs(x))[::-1]))
        return x if pow(-2,31)<= x<=(pow(2,31)-1) else 0