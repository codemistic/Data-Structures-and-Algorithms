"""
https://leetcode.com/problems/spiral-matrix/
Given an m x n matrix, return all elements of the matrix in spiral order.
"""
class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m=len(matrix)
        n=len(matrix[0])
        left=0
        right=n-1
        top=0
        down=m-1
        dir=0
        x=[]
        while top<=down and left<=right:
            if dir==0:
                for i in range(left,right+1):
                    x.append(matrix[top][i])
                top+=1
            if dir==1:
                for i in range(top,down+1):
                    x.append(matrix[i][right])
                right-=1
            if dir==2:
                for i in range(right,left-1,-1):
                    x.append(matrix[down][i])
                down-=1
            if dir==3:
                for i in range(down,top-1,-1):
                    x.append(matrix[i][left])
                left+=1
            dir=(dir+1)%4
        return x
