#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long t;
  cin >> t;

  for (long long j = 0; j < t; j++) {
    long long n, m;
    cin >> n >> m;
    for(long long k = 0; k < n; k++) {
      for(long long r = 0; r < m; r++) {
        if (k==0) {
          if (r==0) {
            cout<<"B";
          } else {
            cout<<"W";
          }
        } else if(k!=n-1) {
          if(r==m-1) {
            cout<<"W";
          } else {
            cout<<"B";
          }
        } else {
          cout<<"B";
        }
      }
      cout<<"\n";
    }
  }

  return 0;
}