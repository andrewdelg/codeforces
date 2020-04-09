#include <iostream>
#include <cstdlib>

using namespace std;

int main() {


  long long t;
  cin>>t;

  for(int i = 0; i < t; i++) {
    long long up = 0;
    long long down = 0;
    long long a[100005];
    long long b[100005];

    long long n;
    cin >> n;
    for(long long j = 0; j < n; j++) {
      cin>>a[j];
      if (a[j] == 1) {
        up++;
      } else if (a[j] == -1) {
        down++;
      }
    }

    for(long long j = 0; j < n; j++) {
      cin>>b[j];
    }
    bool good = true;
    for(long long j = n-1; j >=0; j--) {
      if (a[j] == 1) {
        up--;
      } else if (a[j] == -1) {
        down--;
      }

      if(b[j]==a[j]) {
        continue;
      } else if(b[j] > a[j] && up > 0) {
        continue;
      } else if(b[j] < a[j] && down >0) {
        continue;
      } else {
        good = false;
        
        break;
      }
    }
    if (good) {
      cout<<"YES"<<"\n";
    } else {
      cout<<"NO"<<"\n";
    }
    

  }
  return 0;
}