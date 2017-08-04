#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
  char item[1010], price[1010];
  double sum = 0;
  while(scanf("%[^0-9]",item)!=EOF){
    if(!isalpha(item[0])) break;
    scanf("%[^a-z\n]",price);
    double val = 0;
    int len = strlen(price);
    //printf("%s %s\n",item,price);
    if(price[len-3] == '.'){
      sscanf(price+len-2,"%lf",&val);
      val /= 100.0;
      len = len-2;
    }
    //printf("Len=%d\n",len);
    for(int i = len-1, j = 1; i >= 0; i--, j*=10){
      if(!j) j = 1;
      //printf("Evaluating %c * %d\n",price[i],j);
      if(price[i] == '.') {
        j /= 10;
        continue;
      }
      val += (price[i]-'0')*j;
    }
    //printf("Price of %s: %lf\n",item,val);
    sum += val;
  }
  //printf("Sum: %lf\n",sum);
  stack<char> st;
  if(((ll)(sum*100.0))%100){
    sum = floor(100LL*sum);
    //cout << sum << endl;
    string ans = to_string((int)(sum));
    //cout << ans << endl;
    while(ans.size() < 3){
      ans = "0"+ans;
    }
    st.push(ans[ans.size()-1]);
    st.push(ans[ans.size()-2]);
    st.push('.');
    for(int i = ans.size()-3, j = 0; i >= 0; i--, j++){
      if(j == 3){
        j = 0;
        st.push('.');
      }
      st.push(ans[i]);
    }
  }
  else {
    string ans = to_string((int)sum);
    for(int i = ans.size()-1, j = 0; i >= 0; i--, j++){
      if(j == 3){
        j = 0;
        st.push('.');
      }
      st.push(ans[i]);
    }
  }
  while(!st.empty()){
    printf("%c",st.top());
    st.pop();
  }
  cout << endl;
  return 0;
}
