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
int tot,n,t[100035],p[100035],first[100035], lps[100035];
int ls[300];


void montar(){
	int aux,l=strlen(str);
  memset(ls,-1,sizeof ls);
	t[0]=-1;
	for(int i=0;i<l;i++){
		aux=ls[str[i]];
    ls[str[i]] = i;
		if(aux!=-1)
			t[i]=i-aux;
		else
			t[i]=-1;
	}
	
	l=n;
	p[0]=-1;
	for(int i=0;i<l;i++){
		aux=ls[first[i]];
    ls[first[i]] = i;
		if(aux!=-1)
			p[i]=i-aux;
		else
			p[i]=-1;
	}
}	


void kmpPreprocess(){
    
    int M = n;
    
    // length of the previous longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (first[i] == first[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar 
            // to search step.
            if (len != 0)
            {
                len = lps[len-1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(){

    int M = n;
    int N = strlen(str);
 
    // Preprocess the pattern (calculate lps[] array)
    kmpPreprocess();
   // for(int i = 0; i < M; i++){
   //   printf("%d ",lps[i]);
    //}
   // printf("\n");
    
    
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while (i < N)
    {
        if(t[i] > j) t[i] = -1;
       // printf("Comparing [%d](%d) to [%d](%d)\n",i,t[i],j,p[j]);
        if (p[j] == t[i])
        {
            //printf("Match!\n");
            j++;
            i++;
        }
 
        if (j == M)
        {
          //  printf("Found pattern at index %d \n", i-j);
            i = i-j+1;
            j = 0;
            tot++;
        }
 
        // mismatch after j matches
        else {
            if(t[i] > j) t[i] = -1;
            if (i < N && p[j] != t[i])
            {
            //    printf("p[%d]=%d t[%d]=%d\n",j,p[j],i,t[i]);
            //    printf("Mismatch!\n");
                // Do not match lps[0..lps[j-1]] characters,
                // they will match anyway
                if (j != 0)
                    j = lps[j-1];
                else
                    i = i+1;
            }
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
 // for(int i = 0; str[i]; i++){
 //   printf("%d ",t[i]);
 // }
 // putchar('\n');
 // for(int i = 0; i < n; i++){
 //   printf("%d ",p[i]);
 // }
 // putchar('\n');
  kmpSearch();

	printf("%d\n",tot);
	return 0;
}