class SegmentTree:           # Every node has an index and a segment range
    def __init__(self,arr):
        self.arr=arr
        self.seg=[0]*(4*len(arr))
        
    def build(self,ind,low,high):                   # [low,high] = segment range
        if low==high:
            self.seg[ind]=self.arr[low]
            return
        mid=(low+high)//2
        self.build(2*ind+1,low,mid)
        self.build(2*ind+2,mid+1,high)
        self.seg[ind]=max(self.seg[2*ind+1],self.seg[2*ind+2])   # changes
        
    def update(self,ind,low,high,i,val):         # i in arr and idx in seg
        if low==high:
            self.arr[i]=val
            self.seg[ind]=val
            return 
        mid=(low+high)//2
        if low<=i<=mid:
            self.update(2*ind+1,low,mid,i,val)
        else:
            self.update(2*ind+2,mid+1,high,i,val)
        self.seg[ind]=max(self.seg[2*ind+1],self.seg[2*ind+2])
        
    def query(self,ind,low,high,l,r):               # [l,r] = query range
        if l<=low and high<=r:          # if s range is completely inside q range
            return self.seg[ind]
        if high<l or r<low:             # if s range is completely outside q range
            return -float('inf')        # changes
        mid=(low+high)//2
        left=self.query(2*ind+1,low,mid,l,r)
        right=self.query(2*ind+2,mid+1,high,l,r)
        return max(left,right)                    # changes
    
    
t=SegmentTree([2,3,1,4,0,7,4,9,3,0])
n=10
t.build(0,0,n-1)
t.update(0,0,n-1,4,5)
q=[(0,9),(1,4),(4,4),(4,8)]
for l,r in q:
    print(t.query(0,0,n-1,l,r))
