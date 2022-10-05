# Problem Link -: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
# Problem -: Numbers At Most N Given Digit Set
# Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
# Return the number of positive integers that can be generated that are less than or equal to a given integer n.



# Python Digit DP Solution
def atMostNGivenDigitSet(self, D: List[str], N: int) -> int:
        D = list(map(int, D))
        N = list(map(int, str(N)))

        @functools.lru_cache(None)
        def dp(i, isPrefix, isBigger):
            if i == len(N):
                return not isBigger
            if not isPrefix and not isBigger:
                return 1 + len(D) * dp(i + 1, False, False)
            return 1 + sum(dp(i + 1, isPrefix and d == N[i], isBigger or (isPrefix and d > N[i])) for d in D)

        return dp(0, True, False) - 1
