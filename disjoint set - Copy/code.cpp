// This section is for Disjoint set data structure
// when we find parent of any number in worst case we go O(n) so if for all the numbers on the path we directly make their parent as root
// so when we make M number of operations and take thier average complexity that is alpha(n) which <= 4 for even biggest values
// their is no difference in code except the part where we find parent there we add one more line for changing parent of every node on
// the path

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

int find(vector<int> &parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    parent[x] = find(parent, parent[x]);
    return parent[x];
}

void union_num(vector<int> &parent, vector<int> &rank, int num1, int num2)
{
    int fparent = find(parent, num1);
    int sparent = find(parent, num2);
    if (fparent == sparent)
    {
        return;
    }
    if (rank[fparent] < rank[sparent])
    {
        parent[fparent] = sparent;
    }
    else if (rank[fparent] > rank[sparent])
    {
        parent[sparent] = fparent;
    }
    else
    {
        parent[fparent] = sparent;
        rank[sparent]++;
    }
}

void solve()
{
    int n = 8; // 0 - 7
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int total;
    cin >> total;
    while (total--)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            // union
            int num1, num2;
            cin >> num1 >> num2;
            union_num(parent, rank, num1, num2);
        }
        else
        {
            // find
            int num1, num2;
            cin >> num1 >> num2;
            int fparent = find(parent, num1), sparent = find(parent, num2);

            if (fparent == sparent)
            {
                cout << "They are in same group!!" << endl;
            }
            else
            {
                cout << "They are not in same group!!" << endl;
            }
        }

        cout << "Check parent array: " << endl;
        for (int i = 0; i < parent.size(); i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
        cout << "Check Rank array: " << endl;
        for (int i = 0; i < rank.size(); i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}