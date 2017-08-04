#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int main(){
  int T, N;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    int A[N];
    for(int i = 0; i < N; i++){
      scanf("%d",&A[i]);
    }
    int maxsum = (int)-1e9, sum = 0, m = 0, maxv = (int)-1e9, ini = 0, fim = 0;
    vii intervals;
    for(int i = 0; i <= N; i++){
      if(i < N) {
        sum += A[i];
        maxv = max(maxv,A[i]);
      }
      if(sum < 0 || i == N) {
        sum = 0;
        if(ini != i) intervals.push_back(ii(ini,i));
        ini = i+1;
      }
    }
    for(int i = 0; i < intervals.size(); i++){
      sum = m = 0;
      maxsum = (int)-1e9;
      int values[intervals.size()];
      for(int j = intervals[i].first; j < intervals[i].second; j++){
        m = min(m,A[j]);
        sum += A[j];
      }
      printf("Sum [%d,%d) = %d\n",intervals[i].first,intervals[i].second,sum);
      sum -= m;
      maxsum = max(maxsum,sum);
    }
    if(maxsum < 0) maxsum = maxv;
    cout << maxsum << endl;
  }
  return 0;
}