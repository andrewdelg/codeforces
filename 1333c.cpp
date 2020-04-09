#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n; cin>>n;
  unordered_map<ll, ll> m;

  ll sum = 0;
  ll ans = 0;
  ll right = 0;

  for(int i = 1; i <= n; i++) {
    ll tmp; cin >> tmp;
    m[sum] = i;
    sum += tmp;

    if (right < m[sum]) {
      right = m[sum];
    } 

    ans += (i - right );

  }
  cout << ans << "\n";
  return 0;
}