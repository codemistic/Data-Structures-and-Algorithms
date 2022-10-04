# date: 2022-10-04

def lcs(X, Y):
    m = len(X)
    n = len(Y)
    lcs_suff = [[0 for k in range(n+1)] for l in range(m+1)]
    length = 0

    for i in range(m + 1):
        for j in range(n + 1):
            if (i == 0 or j == 0):
                lcs_suff[i][j] = 0
            elif (X[i-1] == Y[j-1]):
                lcs_suff[i][j] = lcs_suff[i-1][j-1] + 1
                length = max(length, lcs_suff[i][j])
            else:
                lcs_suff[i][j] = 0
    return length

s1 = input("String1 : ")
s2 = input("String2 : ")


print('Length of LCS :', lcs(s1, s2))