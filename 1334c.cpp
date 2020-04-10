#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  for(ll i = 0; i < t; i++) {
    ll n; cin>>n;
    vector<pair<ll,ll>> d;
    ll bullets = 0;
    ll carry = 0;

    ll ans = 0;
    for(ll j = 0; j < n; j++) {
      ll a, b;
      cin>>a>>b;
      d.push_back(make_pair(a,b));

      if(a - carry <= 0) {
        carry = b;
      } else {
        bullets += a-carry;
        carry = b;
      }
    }

    ans = bullets;

    for(ll j = 1; j < n; j++) {
      bullets -= d[j-1].first;

      if(d[j-1].second < d[j].first) {
        bullets += d[j-1].second;
      } else {
        bullets += d[j].first;  
      }
      
      if(d[j-1].first<d[ (n+j - 2) % n].second) {
        bullets += 0;
      } else {
        bullets += (d[j-1].first - d[ (n+ j - 2) % n].second);
      }

      ans = min(ans, bullets);
    }

    cout << ans << "\n";


  }

  return 0;
}