#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct ch {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n; cin>>n;
  unordered_map<ll, ll, ch> m;

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

