#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {

  int n;
  cin >> n;
  unordered_map<int, pair<int,int>> list;
  vector<int> starts;

  for(int i = 0; i < n; i++) {

    int a, b;
    cin >> a >> b;
    if (a == 0) {
      starts.push_back(i + 1);
    }

    list[i+1]=make_pair(a,b);
  }

  sort(starts.begin(), starts.end());

  for(int i = 0; i < starts.size() - 1; i++) {
    int current = starts[i];
    //cout<<"Looking at " << current << endl;
    while(list[current].second != 0) {
      current = list[current].second;
    }
    //cout<< "Linking " << current <<  " to "<< starts[i+1] << endl;
    list[current].second = starts[i + 1];
    list[starts[i + 1]].first = current;

  }


  for(int i = 1; i < n + 1; i++) {
    cout<<list[i].first<<" "<<list[i].second<<endl;
  }





  return 0;
}