#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<int>s;
	//add elements
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	
	//remove elements from last
	s.pop();
	
	//display the top most elements
	cout<<s.top()<<endl;
	
	//display the size of the stack
	cout<<s.size()<<endl;
	
	//checking if stack is empty or not
	if (s.empty())
	{
		cout<<"Yes Empty"<<endl;
	}
	else
	{
		cout<<"No Not Empty"<<endl;
	}
	
	return 0;
}
