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

map<pair<pair<int,int>,pair<int,int> >, int > qry;

int main(){
  int n;
  cin >> n;
  int x11=1, x12=n, y11=1, y12=n, x21=1, x22=n, y21=1, y22=n;
  int lo = 1, hi = n;
  int temp = n;
  int xcut = INF, ycut = INF;
  while(lo <= hi){
    int mid = (lo+hi)/2, q;
    printf("? %d %d %d %d\n",1,1,mid,n);
    fflush(stdout);
    scanf("%d",&q);
    if(q == 1){
      printf("? %d %d %d %d\n",mid+1,1,n,n);
      fflush(stdout);
      scanf("%d",&q);
      if(q == 1) {
        xcut = mid;
        break;
      }
      hi = mid -1;
      continue;
    }
    if(q == 2){
      hi = mid-1;
    }
    else {
      lo = mid+1;
    }
  }
  lo = 1, hi = n;
  if(xcut == INF) while(lo <= hi){
    int mid = (lo+hi)/2, q;
    printf("? %d %d %d %d\n",1,1,n,mid);
    fflush(stdout);
    scanf("%d",&q);
    if(q == 1){
      printf("? %d %d %d %d\n",1,mid+1,n,n);
      fflush(stdout);
      scanf("%d",&q);
      if(q == 1) {
        ycut = mid;
        break;
      }
      hi = mid-1;
      continue;
    }
    if(q == 2){
      hi = mid-1;
    }
    else {
      lo = mid+1;
    }
  }
  
  if(xcut != INF){
    lo = 1, hi = xcut;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x11,y11},{mid,y12}}];
      if(!q){
        printf("? %d %d %d %d\n",x11,y11,mid,y12);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x11,y11},{mid,y12}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    x12 = temp;
    temp = n;
    lo = 1, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x11,y11},{x12,mid}}];
      if(!q){
        printf("? %d %d %d %d\n",x11,y11,x12,mid);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x11,y11},{x12,mid}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    y12 = temp;
    
    temp = n;
    lo = 1, hi = x12;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{mid,y11},{x12,y12}}];
      if(!q){
        printf("? %d %d %d %d\n",mid,y11,x12,y12);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{mid,y11},{x12,y12}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    x11 = temp;
    temp = n;
    lo = 1, hi = y12;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x11,mid},{x12,y12}}];
      if(!q){
        printf("? %d %d %d %d\n",x11,mid,x12,y12);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x11,mid},{x12,y12}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    y11 = temp;
    
    temp = n;
    lo = xcut+1, hi = n;  
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{mid,y21},{x22,y22}}];
      if(!q){
        printf("? %d %d %d %d\n",mid,y21,x22,y22);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{mid,y21},{x22,y22}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    x21 = temp;
    temp = n;
    lo = 1, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x21,mid},{x22,y22}}];
      if(!q){
        printf("? %d %d %d %d\n",x21,mid,x22,y22);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x21,mid},{x22,y22}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    y21 = temp;
    
    temp = n;
    lo = x21, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x21,y21},{mid,y22}}];
      if(!q){
        printf("? %d %d %d %d\n",x21,y21,mid,y22);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x21,y21},{mid,y22}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    x22 = temp;
    temp = n;
    lo = y21, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x21,y21},{x22,mid}}];
      if(!q){
        printf("? %d %d %d %d\n",x21,y21,x22,mid);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x21,y21},{x22,mid}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    y22 = temp;
      
  }
  else {
    lo = 1, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x11,y11},{mid,ycut}}];
      if(!q){
        printf("? %d %d %d %d\n",x11,y11,mid,ycut);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x11,y11},{mid,ycut}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    x12 = temp;
    temp = n;
    lo = 1, hi = ycut;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x11,y11},{x12,mid}}];
      if(!q){
        printf("? %d %d %d %d\n",x11,y11,x12,mid);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x11,y11},{x12,mid}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    y12 = temp;
    
    temp = n;
    lo = 1, hi = x12;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{mid,y11},{x12,y12}}];
      if(!q){
        printf("? %d %d %d %d\n",mid,y11,x12,y12);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{mid,y11},{x12,y12}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    x11 = temp;
    temp = n;
    lo = 1, hi = y12;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x11,mid},{x12,y12}}];
      if(!q){
        printf("? %d %d %d %d\n",x11,mid,x12,y12);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x11,mid},{x12,y12}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    y11 = temp;
    
    temp = n;
    lo = 1, hi = n;  
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{mid,ycut+1},{x22,y22}}];
      if(!q){
        printf("? %d %d %d %d\n",mid,ycut+1,x22,y22);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{mid,ycut+1},{x22,y22}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    x21 = temp;
    temp = n;
    lo = ycut+1, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x21,mid},{x22,y22}}];
      if(!q){
        printf("? %d %d %d %d\n",x21,mid,x22,y22);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x21,mid},{x22,y22}}] = ++q;
      }
      if(q>1){
        temp = mid;
        lo = mid+1;
      }
      else {
        hi = mid-1;
      }
    }
    y21 = temp;
    
    temp = n;
    lo = x21, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x21,y21},{mid,y22}}];
      if(!q){
        printf("? %d %d %d %d\n",x21,y21,mid,y22);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x21,y21},{mid,y22}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    x22 = temp;
    temp = n;
    lo = y21, hi = n;
    while(lo <= hi){
      int mid = (lo+hi)/2, q;
      q = qry[{{x21,y21},{x22,mid}}];
      if(!q){
        printf("? %d %d %d %d\n",x21,y21,x22,mid);
        fflush(stdout);
        scanf("%d",&q);
        qry[{{x21,y21},{x22,mid}}] = ++q;
      }
      if(q>1){
        temp = mid;
        hi = mid-1;
      }
      else {
        lo = mid+1;
      }
    }
    y22 = temp;
      
  }
  
  printf("! %d %d %d %d %d %d %d %d\n",x11,y11,x12,y12,x21,y21,x22,y22);
  fflush(stdout);
  
  return 0;
}
