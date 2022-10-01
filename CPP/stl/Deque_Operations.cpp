#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print (const deque<int>& dq)
{
	cout<<"Deque Elements are:";
	for (auto it=dq.begin();it!=dq.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main()
{
	deque<int> dq;
	dq.push_back(4);
	dq.push_back(2);
	dq.push_back(1);
	dq.push_back(5);
	dq.push_back(3);
	
	cout<<"Deque contains:"<<dq.size()<<" elements"<<endl;
	
	if (dq.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Empty"<<endl;
	}
	
	//calling the function to print before sorting
	print(dq);
	//sorting the deque
	sort(dq.begin(),dq.end());
	//calling the function to print after sorting
	print(dq);
	
	//finding position of element with value 3
	auto it1=find(dq.begin(),dq.end(),3);
	//Inserting element on a particular position of deque
	//element gets inserted on previous position of it1
	dq.insert(it1,0);
	print(dq);
	
	//removing the 1st element of deque
	dq.erase(dq.begin());
	print(dq);
	
	dq.clear();
	cout<<"Deque contains:"<<dq.size()<<" elements"<<endl;
	if(dq.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Not Empty"<<endl;
	}
	
	return 0;
}
