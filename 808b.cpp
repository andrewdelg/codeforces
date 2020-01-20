#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  double n, k, a, temp;
  cin>> n >> k;

  a = 0;
  double weeks = n - k + 1;
  long long mmax = (k<n-k+1)?k:n-k+1;
  long long mult = 1;
  for(long long i = 0; i < n; i++) {
    cin >> temp;
    a += (mult/weeks) * temp;
    //cout<<mult<<",";
    if(i >=  n-mmax ) {
      mult--;
    } else if(mult != mmax) {
      mult++;
    } 

  }


  /*double aa = 1;
  aa = double(a)/double(n-k+1);
  cout << aa << endl;*/
  printf("%.6f\n", a);
  return 0;
}