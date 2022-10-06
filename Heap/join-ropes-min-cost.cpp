typedef long long ll;
class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        ll minC = 0;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        for (ll i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
        }

        while (minHeap.size() != 1)
        {
            ll r1 = minHeap.top();
            minHeap.pop();
            ll r2 = minHeap.top();
            minHeap.pop();
            minC += r1 + r2;
            minHeap.push(r1 + r2);
        }
        return minC;
    }
};