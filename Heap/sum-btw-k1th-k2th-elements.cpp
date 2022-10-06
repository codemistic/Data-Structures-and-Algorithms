typedef long long ll;

ll sumBetweenTwoKth(ll a[], ll n, ll k1, ll k2)
{
    ll sum = 0;
    priority_queue<pair<ll, ll>> maxHeap;
    unordered_map<ll, ll> fz;
    if (k1 > k2)
        swap(k1, k2);

    for (ll i = 0; i < n; i++)
        fz[a[i]]++;

    for (auto i = fz.begin(); i != fz.end(); i++)
    {
        maxHeap.push(make_pair(i->first, i->second));
        if (maxHeap.size() >= k2)
            maxHeap.pop();
    }

    while (maxHeap.size() > k1)
    {
        for (ll j = 0; j < maxHeap.top().second; j++)
        {
            sum += maxHeap.top().first;
        }
        maxHeap.pop();
    }

    return sum;
}