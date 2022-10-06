class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s)==Counter(t)
#         d={}
#         for i in s:
#             if i not in d:
#                 d[i]=1
#             else:
#                 d[i]+=1
#         for i in t:
#             if i in d:
#                 d[i]-=1
#             else:
#                 d[i]=1
#             if d[i]==0:
#                 d.pop(i)
#         return len(d)==0
            
        