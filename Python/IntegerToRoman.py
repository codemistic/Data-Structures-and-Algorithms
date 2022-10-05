"""
https://leetcode.com/problems/integer-to-roman/
Given an integer, convert it to a roman numeral.
"""
class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        pattern = [("M",1000),
                  ("CM",900),
                  ("D",500),
                  ("CD",400),
                  ("C",100),
                  ("XC",90),
                  ("L",50),
                  ("XL",40),
                  ("X",10),
                  ("IX",9),
                  ("V",5),
                  ("IV",4),
                  ("I",1)]
        output = ""
        for roman, corresonding_number in pattern:
            output += roman * (num//corresonding_number)
            num = num % corresonding_number
        return output
