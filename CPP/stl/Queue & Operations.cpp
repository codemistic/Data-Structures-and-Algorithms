#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	queue<int>q;
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	
	//remove 1st element from front
	q.pop();
	
	//show the front or 1st element
	cout<<q.front()<<endl;
	
	//show the last element
	cout<<q.back()<<endl;
	
	//diplay the size of array
	cout<<q.size()<<endl;
	
	//checking if queue is empty or not
	if (q.empty())
	{
		cout<<"Yes Empty"<<endl;
	}
	else
	{
		cout<<"No Not Empty"<<endl;
	}
	
	return 0;
}
