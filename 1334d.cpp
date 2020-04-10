#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll m = 998244353;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll d; cin >> d;
  ll q; cin >> q;
  unordered_map<ll, unordered_map<ll, ll, ch>, ch> factors;
  set<ll> primes;

  ll cur = 1;
  unordered_map<ll, ll, ch> tmp;
  while (d % 2 == 0) {
    prime.insert(2);
    d = d/2;
    cur *= 2;
    if(tmp.count(2) > 0) {
      tmp[2] += 1;
    } else {
      tmp[2] = 1;
    }

    factors[cur] = unordered_map(tmp);
  }

  for(ll i = 3; i <= sqrt(d); i = i + 2) {
    while(d % i == 0) {
      primes.insert(i);
      d = d/i;
    cur *= i;
    if(tmp.count(i) > 0) {
      tmp[i] += 1;
    } else {
      tmp[i] = 1;
    }

    factors[cur] = unordered_map(tmp);
    }
  }

  if(d > 2) 
  {
    tmp[d] = 1;
    factors[d] = unordered_map(tmp);
  }

  for(ll i = 0; i < q; i++) {
    ll a;
    ll b;
    cin>>a>>b;

    af = factors[a];
    bf = factors[b];

    vector<ll> difs;
    ll sum = 0;
    ll divide = 1;

    for(auto p: primes) {
      ll c = 0;
      ll d = 0;
      if(af.count(p) > 0) {
        c = af[p];
      }

      if(bf.count(p) > 0) {
        d = bf[p];
      }

      ll dif = abs(c -d);
      sum += dif;

    for(int i = 1; i <=dif; ++i)
    {
        divide *= i;
    }

    }

    ll ans = 1;
     for(int i = 1; i <=sum; ++i)
    {
        ans *= i;
    }
    ll aa = (ans/divide)%m;
    cout<<a<<"\n";
  }

}


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
