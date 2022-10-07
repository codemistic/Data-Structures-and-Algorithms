class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        """
        :type boxTypes: List[List[int]]
        :type truckSize: int
        :rtype: int
        """
        boxTypes.sort(key = lambda x: x[1], reverse=1)
        s=0
        for i,j in boxTypes:
            i=min(i,truckSize)
            s+=j*i
            truckSize-=i
            if truckSize<1:
                break
        return s
                
        