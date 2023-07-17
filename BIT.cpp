/****************************************************
         ❤ Bsmellah El Rahman El Rahim ❤
****************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
using ll = long long;
typedef vector<ll> vll;
#define LSOne(x) ((x) & (-x))
#define endl "\n"

struct BIT {
private:
  vll v;

public:
  BIT(int n) { v.assign(n + 1, 0); }
  BIT(const vi &arr) { build(arr); }

  void build(const vi &arr) {
    int m = (int)arr.size(); // note v[0] is always 0
    v.assign(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
      v[i] += arr[i - 1];
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


signed main() {
  vi v{0, 1, 2, 3, 4, 5, 6};
  BIT ft(v);
  cout << ft.rsq(3, 6) << endl;
  ft.update(3, 6);
  cout << ft.rsq(3, 6);
  return 0;
}
