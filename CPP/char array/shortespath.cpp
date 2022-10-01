#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mod 1000000007
#define endl '\n'

int main(){
    cin.tie(0)->sync_with_stdio(0);
    char s[1000];
    cin.getline(s,1000);
    int x,y;
    x=0;
    y=0;
   for (int i = 0; s[i] !='\0'; i++) {
       switch(s[i]){
           case 'N':
               y++;
               break;
           case 'S':
               y--;
               break;
            case 'E':
               x++;
               break;
            case 'W':
               x--;
               break;
       }

       
   }
   cout<<"the value of x and y is:"<<x<<" "<<y<<endl;
    if(x>=0 && y>=0){
        while(x--){cout<<"E";}
        while(y--){cout<<"N";
        }
    }
    else if(x<=0 && y>=0){
        while(x--){cout<<"W";}
        while(y--){cout<<"N";}
    }
    else if(x<=0 && y<=0){
        while(x--){cout<<"W";}
        while(y--){cout<<"S";}
    }
    else
    {
        while(x--){cout<<"E";}
        while(y--){cout<<"S";}
    }

    return 0;
}

