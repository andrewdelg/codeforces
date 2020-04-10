#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  vector<ll> a;
  vector<ll> b;

  cin >> n;
  for(int i = 0; i < n; i++) {
    ll tmp;
    cin>>tmp;
    a.push_back(tmp);
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    ll tmp;
    cin>>tmp;
    b.push_back(tmp);
  }

  int l1 = 0, l2 = 0;
  int r1 = 1, r2 = 1;
  ll s1 = a[0], s2 = b[0];

  int matches = 0;

  while(r1 <= n && r2 <= m) {
    // cout<<l1<<" "<<r1<<"\n";
    // cout<<l2<<" "<<r2<<"\n";
    // cout<<"----------"<<"\n";
    if(s1 == s2) {
      matches++;

      l1 = r1;
      l2 = r2;

      r1 = l1 + 1;
      r2 = l2 + 1;

      s1 = a[r1-1];
      s2 = b[r2-1];

      if (l1 == n && l2 == m) {
        cout << matches << "\n";
        return 0;
      }
    } else {
      if (s1 < s2) {
        r1++;
        s1+=a[r1-1];
      } else {
        r2++;
        s2+=b[r2-1];
      }
    }

  }

  cout << -1 << "\n";

  return 0;

}