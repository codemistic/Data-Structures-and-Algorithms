#include<bits/stdc++.h>

using namespace std;
typedef long long int ll; 
typedef long double ld;
typedef pair < ll, ll > iii; 
const ll mod = 1e9 + 7;

ll n, q;
struct node {
  ll x;
  ll ad;
  ll lazy;
  node() {
    x = 0;
    ad = 0;
    lazy = 0;
  }
};
vector < ll > v;
vector < node > g;

inline node merge(node a, node b) {
  node temp;
  temp.x = a.x + b.x;
  temp.ad = 0;
  temp.lazy = 0;
  return (temp);
}

inline void build(ll index, ll l, ll r) {
  if (l == r) {
    g[index].ad = 0;
    g[index].lazy = 0;
    g[index].x = v[l];
    return;
  }

  ll mid;
  mid = (l + r) / 2;
  build(2 * index, l, mid);
  build(2 * index + 1, mid + 1, r);
  g[index] = merge(g[2 * index], g[2 * index + 1]);

}

inline void push(ll index, ll l, ll r) {
  if (g[index].lazy > 0) {
    g[index].x = (r + 1 - l) * g[index].lazy;
    g[2 * index].lazy = g[index].lazy;
    g[2 * index + 1].lazy = g[index].lazy;
    g[2 * index].ad = 0;
    g[2 * index + 1].ad = 0;
    g[index].lazy = 0;

  }

  if (g[index].ad > 0) {
    g[index].x = g[index].x + (r + 1 - l) * g[index].ad;
    g[2 * index].ad += g[index].ad;
    g[2 * index + 1].ad += g[index].ad;
    //g[2*index].lazy=0;
    //g[2*index+1].lazy=0;
    g[index].ad = 0;
  }

  return;
}

inline ll findsum(ll index, ll l, ll r, ll lq, ll rq) {
  push(index, l, r);
  if (l > rq || r < lq)
    return 0;

  if (l >= lq && r <= rq)
    return (g[index].x);

  ll mid;
  mid = (l + r) / 2;

  return (findsum(2 * index, l, mid, lq, rq) + findsum(2 * index + 1, mid + 1, r, lq, rq));

}

inline void update2(ll index, ll l, ll r, ll lq, ll rq, ll x) {
  push(index, l, r);

  if (l > rq || r < lq)
    return;

  if (l >= lq && r <= rq) {
    g[index].lazy = x;
    push(index, l, r);
    return;
  }

  ll mid;
  mid = (l + r) / 2;
  update2(2 * index, l, mid, lq, rq, x);
  update2(2 * index + 1, mid + 1, r, lq, rq, x);
  g[index] = merge(g[2 * index], g[2 * index + 1]);

}

inline void update1(ll index, ll l, ll r, ll lq, ll rq, ll x) {
  push(index, l, r);

  if (l > rq || r < lq)
    return;

  if (l >= lq && r <= rq) {
    g[index].ad += x;
    push(index, l, r);
    return;
  }

  ll mid;
  mid = (l + r) / 2;
  update1(2 * index, l, mid, lq, rq, x);
  update1(2 * index + 1, mid + 1, r, lq, rq, x);
  g[index] = merge(g[2 * index], g[2 * index + 1]);

}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;

  v.resize(n + 1);
  g.resize(8 * n + 4);

  ll i;
  for (i = 1; i <= n; i++)
    cin >> v[i];

  build(1, 1, n);

  while (q--) {
    ll t, a, b, x;
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> x;

      update1(1, 1, n, a, b, x);

    }
    if (t == 2) {
      cin >> a >> b >> x;

      update2(1, 1, n, a, b, x);

    }

    if (t == 3) {
      cin >> a >> b;
      cout << findsum(1, 1, n, a, b) << endl;

    }
  }

  return 0;
}
