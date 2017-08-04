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
int a[100035];
int main(){
int n, n1, n2;
cin >> n >> n1 >> n2;
for(int i = 0; i < n; i++){
  scanf("%d",a+i);
}
sort(a,a+n);
ll s1 = 0, s2 = 0;
int q1 = 0, q2 = 0;
double m1 = 0, m2 = 0;
for(int i = n-1; i >= 0; i--){
  if(q1 == n1 && q2 == n2) break;
  if(q2 == n2){
    s1 += a[i];
    q1++;
    continue;
  }
  if(q1 == n1){
    s2 += a[i];
    q2++;
    continue;
  }
  double t1 = (double)(s1 + a[i])/(q1+1);
  double t2 = (double)(s2 + a[i])/(q2+1);
  if(m1 + t2 == m2 + t1){
    if(n1 > n2){
      s2 += a[i];
      q2++;
    }
    else {
      s1 += a[i];
      q1++;
    }
  }
  else if(m1 + t2 > m2 + t1){
    s2 += a[i];
    q2++;
  }
  else {
    s1 += a[i];
    q1++;
  }
}
printf("%lf\n",(double)s1/n1+(double)s2/n2);
return 0;
}
