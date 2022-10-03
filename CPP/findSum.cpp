#include <bits/stdc++.h>
using namespace std;
	
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>>v;
        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                if(A[i]+B[j]==X){
                    v.push_back({A[i],B[j]});
                }
            }
        }  
        sort(v.begin(),v.end());
        return v;
    }
};

	
int main()
{
	int t;
	cin>>t;

	while(t--){
		int N ,M, X;
		cin >> N >> M >> X;
		int A[N], B[M];

		for(int i = 0;i<N;i++)
			cin >> A[i];

		for(int i = 0;i<M;i++)
			cin >> B[i];

		Solution ob;
		vector<pair<int, int>> vp = ob.allPairs(A, B, N, M, X);
		int sz = vp.size();

 

		if(sz==0)
			cout<<-1<<endl;
		else{
			for(int i =0; i<sz;i++){
				if(i==0)
				cout<<vp[i].first<<" "<<vp[i].second;
				else
				cout<<", "<<vp[i].first<<" "<<vp[i].second;
			}
			cout<<endl;
		}
	}

return 0;
}
