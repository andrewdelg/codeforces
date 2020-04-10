#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

   ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;

  for(int i =0; i < t; i++) {
    ll prevp = 0;
    ll prevc = 0;
    ll n;
    cin>>n;
    bool good = true;
    for(int j = 0; j < n; j++) {
      ll a, b;
      cin >> a >> b;
      if(a >= b && a >= prevp && b >= prevc && (b-prevc) <= (a-prevp) ){
        prevp = a;
        prevc = b;
        continue;
      } else {
        good = false;
      }
    }

    if(good) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }

  return 0;
}