#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    /*
    cin.tie(0)->sync_with_stdio(0);
    int n=5;
    cout<<"the value of n is: "<<n<<endl;
    int *ptr = &n; //created a pointer and give the address of n
                   //always initialize the pointer data type 
    cout<<"the address of 5 is: "<<&n<<endl;//& is used to show address of any data(it has hexa decimal value
    cout<<&(*ptr);
    int *p=0;
    p=&n;// we can also initialize it like this | while initializing like this never use '*' again
    cout<<"before increasing "<<*p<<endl;
    (*p)++;
    cout<<"after increasing "<<*p<<endl;
    int x;
    x=3;
    int a;
    a=x;
    a++;
    cout<<"using direct int variable : "<<x;

    int *z=&x;
    (*z)++;
    cout<<endl;
    cout<<"using pointer variable :"<<x<<endl;
    int *pt=z;
    cout<<pt<<" - "<<z<<endl;
    cout<<*pt<<" - "<<*z<<endl;
    z++;
    cout<<z<<endl;//if variable is int then addresss will increase with 4 bitss
    double ff=9;
    double *pff=&ff;
    cout<<"before increasing "<<pff<<endl;
    pff=pff+1;// the address will increase by 8 bits
    cout<<"after increasing "<<pff<<endl; 
    // the size of a pointer is always 8 bits since it only store the address the type of variable will not affect the size of variable
    cout<<"size of int "<<sizeof(x)<<" size of its pointer "<<sizeof(z)<<endl;
    cout<<"size of double "<<sizeof(ff)<<" size of its pointer "<<sizeof(pff)<<endl;


*/
    //TYPES OF POINTERS
    //1. NULL POINTER
    int *p;//return garbage value of address
    int *q= NULL;
    int *r= 0;
    
    //2.DOUBLE POINTER
    int a=9;
    int *b=&a;
    int **c=&b;
    // double pointer store the address of the pointer i.e b

    //3. VOID POINTER
    void *d;
    //it cannot be dereference. however it can be type cast and used
    /*
     void *ptr;
     int i=0;
     ptr=&i;

     */ 
    //4. WILD POINTER
    int *P;
    //if the pointer is not initialized then it is called wild pointer


    // 5. DANGLING POINTER

    return 0;
}

