// You are given a 2D string array A of dimensions N x 2,

// where each row consists of two strings: first is the name of the student, second is their marks.

// You have to find the maximum average mark. If it is a floating point, round it down to the nearest integer less than or equal to the number.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> A(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> A[i][0] >> A[i][1];
    }

    map<string, int> m;
    map<string, int> count;
    for (int i = 0; i < n; i++)
    {
        m[A[i][0]] += stoi(A[i][1]);
        cout << m[A[i][0]] << endl;
        count[A[i][0]]++;
    }
    int max = 0;
    string name;
    for (auto i : m)
    {
        // cout << i.first << " " << i.second << endl;
        // cout << i.first << " " << round(i.second / count[i.first]) << endl;
        if (round (1.0 * i.second / count[i.first]) > max)
        {
            max = round(i.second / count[i.first]);
            name = i.first;
        }
    }
    cout << name << " " << max << endl;
    
  return 0;
}

