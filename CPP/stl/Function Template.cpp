#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//general syntax for templates
template <typename T>

//funcation creation with templates
T maxi(T a,T b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main() 
{
	cout<<maxi<int>(3,6)<<endl;
	cout<<maxi<float>(3.5,6.2)<<endl;
    return 0;
}
