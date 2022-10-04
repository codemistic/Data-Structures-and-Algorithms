//Hackerrank Problem - Circular Palindromes
// Level - Hard
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define type(x) __typeof((x).begin())
#define foreach(i, x) for(type(x) i = (x).begin(); i != (x).end(); i++)
#define hash ___hash

typedef long long ll;
typedef pair < int, int > ii;

const int inf = 1e9 + 333;
const ll linf = 1e18 + 333;

const int N = 2e6 + 5;

int n;
char s[N];
bool h[N];
int go_odd[N], go_even[N], tmp[N << 1], rad[N << 1], ans[2][N];

void manacher() {
    memset(tmp, 0, sizeof(tmp));
    memset(rad, 0, sizeof(rad));
    int m = n * 2 + 1;
    for(int i = 0; i < m; i++)
        tmp[i] = '#';
    for(int i = 0; i < n; i++)
        tmp[i * 2 + 1] = s[i + 1];
    int i = 0, j = 0;
    while(i < m) {
        while(i - j >= 0 and i + j < m and tmp[i - j] == tmp[i + j])
            j++;
        rad[i] = j;
        int k = 1;
        while(rad[i - k] < rad[i] - k) {
            rad[i + k] = rad[i - k];
            k++;
        }
        i += k;
        j = max(0, j - k);
    }
    for(int i = 1; i <= n; i++)
        go_odd[i] = rad[(i - 1) * 2 + 1] / 2;//abcba --> go_odd[3] = 3
    for(int i = 1; i <= n; i++)
        go_even[i - 1] = rad[(i - 1) * 2] / 2;//abccba --> go_even[3] = 3
}

void solveOdd(bool w) {
    int oth = 0;
    set < ii > go;
    for(int i = 1; i <= (n + 1) / 2; i++) {
        go.insert({go_odd[i], i});
    }
    for(int i = 1; i <= n; i++) {
        while(go.size()) {
            int x = go.rbegin() -> first;
            int id = go.rbegin() -> second;
            if(id < i) {
                go.erase(*go.rbegin());
                continue;
            }
            int mx = (id - i + 1) * 2 - 1;
            if(x > mx) {
                oth = max(oth, id);
                go.erase(*go.rbegin());
                continue;
            }
            break;
        }
        if(go.size())
            ans[w][i] = max(ans[w][i], go.rbegin() -> first);
        if(oth >= i)
            ans[w][i] = max(ans[w][i], (oth - i + 1) * 2 - 1);
        //printf("ans[%d] = %d oth = %d\n", i, ans[w][i]);
        int add = (n + 1) / 2 + i;
        go.insert({go_odd[add], add});
    }
}

int get(int x, int y) {
    y -= x - 1;
    return min(y, n - y) * 2;
}

void solveEven(bool w) {
    int oth = 0;
    set < ii > go;
    for(int i = 1; i <= (n + 1) / 2; i++) {
        go.insert({go_even[i], i});
    }
    for(int i = 1; i <= n; i++) {
        while(go.size()) {
            int x = go.rbegin() -> first;
            int id = go.rbegin() -> second;
            if(id < i) {
                go.erase(*go.rbegin());
                continue;
            }
            int mx = get(i, id);
            if(x > mx) {
                oth = max(oth, id);
                go.erase(*go.rbegin());
                continue;
            }
            break;
        }
        if(go.size())
            ans[w][i] = max(ans[w][i], go.rbegin() -> first);
        if(oth >= i)
            ans[w][i] = max(ans[w][i], get(i, oth));
        //printf("ans[%d] = %d\n", i, ans[w][i]);
        int add = (n + 1) / 2 + i;
        go.insert({go_even[add], add});
    }
}


int main () {
    
    scanf("%d %s", &n, s + 1);
    
    for(int i = 1; i <= n; i++)
        s[i + n] = s[i];
    
    
    n *= 2;
    manacher();
    n /= 2;
    
    for(int i = 1; i <= n + n; i++) {
        go_odd[i] *= 2;
        go_odd[i] -= 1;
        go_even[i] *= 2;
    }
    
    solveOdd(0);
    solveEven(0);
    
  
    
    reverse(s + 1, s + n * 2 + 1);
    
    n *= 2;
    manacher();
    n /= 2;
    
    for(int i = 1; i <= n + n; i++) {
        go_odd[i] *= 2;
        go_odd[i] -= 1;
        go_even[i] *= 2;
    }
    
    solveOdd(1);
    solveEven(1);
   
    printf("%d\n", max(ans[0][1], ans[1][1]));
    
    for(int i = 2; i <= n; i++) {
        printf("%d\n", max(ans[0][i], ans[1][n + 2 - i]));
    }
    
    return 0;
    
}







