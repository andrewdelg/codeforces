#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  for(int i = 0; i < t; i++) {
    ll n, x;
    cin>>n>>x;
    vector<ll> d;
    for(int j =0; j <n; j++) {
      ll tmp;
      cin>> tmp;
      d.push_back(tmp);
    }
    sort(d.begin(), d.end(), greater<>());

    ll total = 0;
    ll count = 0;

    for(auto v: d) {
      if(total + v >= (x * (count+1))) {
        total += v;
        count++;
      } else {
        break;
      }
    }

    cout<<count<<"\n";

  }

  return 0;
}