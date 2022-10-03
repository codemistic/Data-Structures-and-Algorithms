#include <bits/stdc++.h>
using namespace std;


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code hereint rs = 0;
    vector<int> v;    
    int cs = 0;
    int rs = 0;
    int re = r-1;
    int ce = c-1;
    while(rs<=re || cs<=ce){
        if(rs<=re){
        for(int col = cs;col<=ce;col++){
            v.push_back(matrix[rs][col]);
        }}
        rs++;
        if(cs<=ce){
        for(int row = rs;row <=re;row++){
            v.push_back(matrix[row][ce]);
        }}
        ce--;
        if(rs<=re){
            for(int col = ce;col>=cs;col--){
                v.push_back(matrix[re][col]);
            }
        }
        re--;
        if(cs<=ce){
            for(int row = re;row>=rs;row--){
                v.push_back(matrix[row][cs]);
            }
        }
        cs++;
    } 
    return v;
    }
};


int main() {
	int t;
	cin>>t;

	while(t--)
	{
		int r, c;

		cin>>r>>c;

		vector<vector<int> > matrix(r);

		for(int i=0; i<r; i++)

		{
			matrix[i].assign(c, 0);
			for( int j=0; j<c; j++)
			{
				cin>>matrix[i][j];
			}
		}


		Solution ob;

		vector<int> result = ob.spirallyTraverse(matrix, r, c);

		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<" ";

		cout<<endl;

	}

	return 0;

}
