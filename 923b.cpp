#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    long n;
    cin >> n;

    
    long long P[100002] = {0};
    long long F[100002] = {0};
    long long T[100002] = {0}; 
    long long M[100002] = {0};

    for(int i = 1; i < n + 1; i++) {
      cin >> P[i];
    }

    for(int i = 1; i < n + 1; i++) {
      cin >> T[i];
      T[i] = T[i] + T[i-1];
    }

    for (int i = 1; i < n + 1; i++) {
      long long to_find = P[i] + T[i-1];

      int index = upper_bound(T+1, T + n + 1, to_find) - T;
      if (index <=n) {
        M[index] = M[index] + (to_find - T[index-1]);    
      }
      
      
      F[i] = F[i] + 1;
      F[index] = F[index] - 1;
      
    }

    for(int i = 1; i < n + 1; i++) {
      F[i] = F[i] + F[i-1];
      cout<< (T[i]-T[i-1]) * F[i] + M[i] << " ";
    }

    cout << endl;

    return 0;
}