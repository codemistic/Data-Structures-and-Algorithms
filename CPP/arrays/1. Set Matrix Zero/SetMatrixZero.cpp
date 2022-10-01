#include <bits/stdc++.h>
using namespace std; 


void setZeroes(vector<vector<int>> &matrix) {
    
    //unordered_set <int> row;  
    //unordered_set <int> col; 
    
    int n=matrix.size(); 
    int m=matrix[0].size(); 
    int col0=1; 
    
    for  (int i=0; i<n; i++){
        if (matrix[i][0]==0) col0=0; 
        for (int j=1; j<m; j++){
            if (matrix[i][j]==0){
                matrix[i][0]=0; 
                matrix[0][j]=0; 
            }
        }
    }
    
    for (int i=n-1; i>=0; i--){
        
        for (int j=m-1; j>=1; j--){
            if (matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0; 
            }
        }
        if (col0==0) matrix[i][0]=0;
    }
 
}

int main(){

	int N; 
	cin >>N; 
	int M; 
	cin >>M; 
	vector<vector<int>> matrix(N,vector <int> (M)); 

	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin >> matrix[i][j]; 
		}
	}

	setZeroes(matrix); 

	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cout << matrix[i][j] << " "; 
		}
		cout << endl; 
	}

	return 0; 
}
