#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int N, M, k;
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // Following code is used to print LCS
   int index = L[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   bool contiguous = true;
   int cur = 0;
   int a[20];
   memset(a,0,sizeof a);
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          if(contiguous) {
            cur++;
            //printf("Current = %d\n",cur);
          }
          else {
            cur = 1;
          }
          contiguous = true;
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1]){
         i--;
         ii mi(0,0);
         for(int z = 0; z < k; z++){
           if(a[z] <= mi.F){
             mi = ii(a[z],z);
           }
         }
         //printf("placing %d at %d\n",cur,mi.S);
         a[mi.S] = cur;
         contiguous = false;
         cur = 0;
      }
      else {
         j--;
         ii mi(0,0);
         for(int z = 0; z < k; z++){
           if(a[z] <= mi.F){
             mi = ii(a[z],z);
           }
         }
         //printf("placing %d at %d\n",cur,mi.S);
         a[mi.S] = cur;
         contiguous = false;
         cur = 0;
      }
   }
   ii mi(0,0);
   for(int z = 0; z < k; z++){
     if(a[z] <= mi.F){
       mi = ii(a[z],z);
     }
   }
   //printf("placing %d at %d\n",cur,mi.S);
   a[mi.S] = cur;
   int sum = 0;
   for(int z = 0; z < k; z++){
    sum += a[z];
   }
   return sum;
   // Print the lcs
   //cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
 
/* Driver program to test above function */
int main()
{
  char X[1010], Y[1010];
  scanf("%d %d %d",&N,&M,&k);
  scanf("%s",X);
  scanf("%s",Y);
  int m = strlen(X);
  int n = strlen(Y);
  cout << lcs(X, Y, m, n) << endl;
  
  return 0;
}