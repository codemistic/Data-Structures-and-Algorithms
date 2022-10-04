#include<iostream>
using namespace std;

int binExpRec(int a, int b){

  if(b==0){
    return 1;
  }

  long long r = binExpRec(a,b/2);

  if(b & 1){
    return (a * r * r);
  }
  else{
    return r * r;
  }

}

int main(){
  int a,b;

  cout<<"Enter the number and its power: ";
  cin>>a>>b;

  int finalAns = binExpRec(a,b);
  cout<< a << " to the power " << b << " = " << finalAns;

    return 0;
}
