#include<bits/stdc++.h>
using namespace std;

void T(int n,char A,char B,char C)
{
    if(n==1)
    {
        cout<<"Moved disk 1 from "<<A<<" to "<<B<<'\n';
        return;
    }
    T(n-1,A,C,B);// moves top n-1 disks from source to auxiliary pole 
    cout<<"Moved disk "<<n<<" from "<<A<<" to "<<B<<'\n'; // moving nth disk from source to destination
    T(n-1,C,B,A); // moves n-1 disks from auxilary to destination pole
}
int main()
{
    T(3,'A','B','C');
}