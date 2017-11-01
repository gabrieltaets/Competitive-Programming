/* Gabriel Augusto Alves Taets      */
/* Universidade Federal de Itajuba  */
/* gabrieltaets at gmail.com        */
/* github.com/gabrieltaets/         */

#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

map<int,int> v;
priority_queue<int> pq;

int main(){
    int b,n,aux;
    scanf("%d",&n);
    scanf("%d",&b);
    for(int i=0;i<(2*n);i++){
        scanf("%d",&aux);
        v[aux]++;
    }
    map<int,int>::iterator it = v.lower_bound(b), it2;
    for(it--; ; it--){
        if(it->S == 0) continue;
        aux= it->S;
        it2 = it;
        for(it2--; ; it2--){
            if(it2->S&&(it->F!=it2->F || (it->F==it2->F && it->S>1))){
                pq.push(it->S+it2->S);
                it->S--;
                it2->S--;
                break;
            }
            if(it2 == v.begin()) break;
        }
        if (aux!=it->S && it->S){
            printf("%d   %d   %d\n",it->F,it->S,aux);
            //getchar();
            it++;
            continue;
        }
        if(it == v.begin()) break;
    }

    for(it = v.lower_bound(b); ;it--){
        if(pq.size()==n)break;
        if(it->S){
            it->S--;
            for(it2 = it; ; it2--){
                if(it2->S){
                    it2->S--;
                    pq.push((it->S+it2->S)%b);
                    break;
                }
                if(it2 == v.begin()) break;
            }
            if(it->S)it--;
        }
        if(it == v.begin()) break;
    }
    while(!pq.empty()){
        aux=pq.top();
        pq.pop();
        printf("%d",aux);
        if(!pq.empty())printf(" ");
    }
    printf("\n");


    return 0;
}