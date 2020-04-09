#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  cin>>n;

  long long gf2_sum = 0;

  for(long long i = 0; i < n; i++) {
    for(long long j = 0; j < n; j++) {
      long long tmp;
      cin>> tmp;
      if (i == j) {
        gf2_sum += tmp;
        gf2_sum = gf2_sum % 2;
      }
    }
  }

  long long nq;
  cin>>nq;

  for(long long i = 0; i < nq; i++) {
    int tmp;
    cin>> tmp;
    if (tmp == 3) {
      cout<<gf2_sum;
    } else {
      cin >> tmp;
      gf2_sum = 1 - gf2_sum;
    }
  }
  return 0;
}