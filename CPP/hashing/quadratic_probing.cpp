#include <iostream>
using namespace std;
int hashfunction(int key)
{
    return key % 13;
}
int main()
{
    int a[] = {26, 28, 31, 34, 35, 25, 31, 31, 31, 25};
    int h[13];
    int n = 13;
    for (int i = 0; i < 13; i++)
        h[i] = -999;
    for (int i = 0; i < 10; i++)
    {
        if (h[hashfunction(a[i])] != -999)
        {
            int j = 1;
            int pcount = 1;
            int k;
            k = hashfunction(a[i]);
            while (pcount < n / 2 && h[(k + j) % 13] != -999)
            {
                k = (k + j) % 13;
                cout << a[i] << "->" << k << " ";
                j = j + 2;
                pcount++;
            }
            cout << endl;
            if (h[(k + j) % 13] == -999)
                h[(k + j) % 13] = a[i];
        }
        else
            h[hashfunction(a[i])] = a[i];
    }
    for (int i = 0; i < 13; i++)
        cout << h[i] << " ";
}