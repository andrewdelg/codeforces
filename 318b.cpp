#include <iostream>
#include <string>
using namespace std;


int main() {

  string in;
  cin >> in;
  long long s_length = in.size();
  long long mult = 0;
  long long ans = 0;
  for(long long i = 0; i < s_length-4; i++) {
   if (in[i] == 'h') {
    if(in[i+1]=='e' && in[i+2]=='a'&& in[i+3]=='v' && in[i+4]=='y') {
      mult++;
    }
   } else if(in[i] == 'm') {
    if(in[i+1]=='e'&& in[i+2]=='t' && in[i+3]=='a' && in[i+4]=='l') {
      ans += mult;
    }
   }
  }
  cout << ans<< endl;
  return 0;
}