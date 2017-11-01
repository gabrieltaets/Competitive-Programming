#include <bits/stdc++.h>

using namespace std;
int conta0;
int vetor[500010];
long long casos[500010];
long long soma;
long long soma1, soma2;
long long possibilidades =0;
long long media;
queue<int> q;
bool flag;

int main(){
    memset(casos,0,sizeof(casos));
    int cont, aux, k;
    conta0 = soma1 = soma2 =0;
    long long soma = 0;
    scanf("%d",&cont);
    for(int i=0;i<cont;i++){
        scanf ("%d",&aux);
        soma+=aux;
        vetor[i]=aux;
        if(!aux)conta0++;
    }
    if(cont<3){
        printf("0\n");
        return 0;
    }
    if(cont==conta0){
        printf("%lld\n",((long long) (cont-1)*(cont-2))/2);
        return 0;
    }
    if(ceil((double)soma/3)!=floor((double)soma/3)){
        printf("0\n");
        return 0;
    }
    media=soma/3;
    for(k=cont-1;k>1;k--){
        soma1+=vetor[k];
        if(soma1==media)break;
    }
    k--;
    aux=0;
    soma1=0;
    flag = false;
    for(k;k>0;k--){
        soma1+=vetor[k];
        if((soma1==media || soma1==0)&& !flag)aux++;
        if(soma1==media)flag= true;
        if(soma1!=media && flag) flag=false;
        casos[k]=aux;
    }
    soma1=0;
    for(int i=0;i<cont-2;i++){
        soma1+=vetor[i];
        if(soma1==media){
            q.push(i+1);
        }
    }
    while(!q.empty()){
        k=q.front();
        q.pop();
        soma2=0;
        for(k;k<cont-1;k++){
            soma2+=vetor[k];
            if(soma2==media)break;
        }
        if(!casos[k])casos[k]=1;
        possibilidades+= casos[k];
    }
    printf("%lld\n",possibilidades);

    return 0;

}