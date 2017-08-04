#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n;
    cin >> n;
    int t = 2*n;
    int v[t];
    for(int i = 0; i < t; ++i)
        cin >> v[i];
    sort(v, v+t);
    for(int i = 0; i < n; ++i)
    {
        cout << v[i] << " " << v[t-1-i];
        if(i < n - 1) putchar(' ');
        
    }
    cout << endl;
 
 
 
    return 0;
}