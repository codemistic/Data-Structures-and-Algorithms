int Solution::solve(vector<int> &A, int B) {

int n=A.size();
int maxsum=0;
int j=n-1;
for(int i=n-B;i<n;i++){
    maxsum+=A[i];
    j--;
}
j++;
int currsum=maxsum;
int i=0;
while(B--){
    currsum+=A[i]-A[j];//a simpler way to check;
    maxsum=max(maxsum,currsum);
    i++;j++;
}
return maxsum;
}
