#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

  int memo[2001][2001];
  int a[2001];

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int n, h, l, r;
  cin>>n>>h>>l>>r;

  for(int i = 0; i < n; i++) {
    cin>>a[i];
  }

  for(int i = n - 1; i >= 0; i--) {
    for(int j = h - 1; j >= 0; j--) {
      //cout << "Calculating " << i << ","<<j<<endl;
      memo[i][j] = (l<=j && j <= r)?1:0;
      //cout << "init " <<memo[i][j]<<endl;
      if (i != n - 1) {

        memo[i][j] += max(memo[i + 1][(j + a[i+1])%h], memo[i + 1][(j + a[i+1] - 1)%h]);
        //cout << "now " << memo[i][j] <<endl;
      }
    } 
  }

  cout << max(memo[0][a[0]], memo[0][a[0]-1]) << "\n";

}


