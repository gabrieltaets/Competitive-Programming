#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii >   vii;

#define pb push_back 
#define mp make_pair 
#define pq priority_queue
#define F first
#define S second
#define INF 0x3f3f3f3f

////////////////////////////////////////////////////////////////////////////////
void curso(){
	#ifdef JUDGE
    	freopen("stacks.in", "rt", stdin);
    	freopen("stacks.out", "wt", stdout);
	#endif

}
/////////////////////////////////////////////////////////////////////////////////

char str[100035];
int tot,n,t[100035],p[100035],b[100035],first[100035];



void montar(){
	int aux,l=strlen(str);
	t[0]=1;
	for(int i=1;i<l;i++){
		aux=i-1;
		while(aux>=0 && str[i]!=str[aux])
			aux--;
		if(aux!=-1)
			t[i]=i-aux;
		else
			t[i]=i+1;
	}
	
	l=n;
	p[0]=1;
	for(int i=1;i<l;i++){
		aux=i-1;
		while(aux>=0 && first[i]!=first[aux])
			aux--;


		if(aux!=-1)
			p[i]=i-aux;
		else
			p[i]=i+1;

	}

}	


void kmpPreprocess(){
	int i=0,j =-1;
	b[0]=-1;
	while(i<n){
		while(j>=0 && p[i]!=p[j])j=b[j];
		i++;
		j++;
		b[i]=j;
	}
  
  printf("B: ");
  for(int i = 0; i <= n; i++){
    printf("%d ",b[i]);
  }
  printf("\n");
}

void kmpSearch(){
	int i=0,j=0;
	while(str[i]){
    int x = t[i];
    if(t[i] > j) t[i] = j+1;
    printf(">t[%d](%d) - p[%d](%d)\n",i,t[i],j,p[j]);
		while(j>=0 && t[i] != p[j]) {
      j= b[j];
    }
    i++;
		j++;
		if(j==n){
      printf("match at %d\n",(i-j));
			tot++;
			j=b[j];
		}
	}

}


int main(){
	scanf(" %s",str);
	scanf("%d",&n);
	tot=0;
	for(int i=0;i<n;i++)
		scanf("%d",first+i);

	montar();
  for(int i = 0; str[i]; i++){
    printf("%d ",t[i]);
  }
  putchar('\n');
  for(int i = 0; i < n; i++){
    printf("%d ",p[i]);
  }
  putchar('\n');
	kmpPreprocess();
  kmpSearch();

	printf("%d\n",tot);
	return 0;
}