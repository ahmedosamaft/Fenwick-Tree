/****************************************************
         ❤ Bsmellah El Rahman El Rahim ❤
****************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ZA7med ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef vector<int> vi;
typedef vector<char> vc;
using ll = long long;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int, int> mii;
typedef set<int> si;
#define pb(x) push_back(x)
#define LSOne(x) ((x) & (-x))
#define ss second
#define ff first
#define endl "\n"
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x)
void FRead() {}
#endif
// ==============================================================================================
const ll N = 1e5 + 5, OO = 1000000000, mod = 1e9 + 7, LOO = 1e18;
enum { UNVISITED = -1, VISITED = 1, EXPLORED = 2 };
const int dx8[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int dy8[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
struct BIT {
private:
  vll v;

public:
  BIT(int n) { v.assign(n + 1, 0); }
  BIT(const vi &arr) { build(arr); }

  void build(const vi &arr) {
    int m = (int)arr.size() - 1; // note f[0] is always 0
    v.assign(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
      v[i] += arr[i];
      if (i + LSOne(i) <= m)     // i has parent
        v[i + LSOne(i)] += v[i]; // add to that parent
    }
  }
  
  void update(int i, int val) {
    for (; i < v.size(); i += LSOne(i))
      v[i] += val;
  }

  ll rsq(int j) {
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += v[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};

void solve() {
  vi v{0, 1, 2, 3, 4, 5, 6};
  BIT ft(v);
  cout << ft.rsq(3, 6) << endl;
  ft.update(3, 6);
  cout << ft.rsq(3, 6);
}

signed main() {
  //  =============================================================================
  ZA7med;
  FRead();
  //  =============================================================================
  int TC = 1;
  // cin >> TC;
  while (TC--)
    solve();
  return 0;
}
