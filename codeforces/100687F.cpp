#include <bits/stdc++.h>
 
using namespace std;
 
string gabarito;
string aluno[100];
bool removed[100];
int N;

int solve(){
  int q[6], sat = 0;
  for(q[0] = 0; q[0] < 8; q[0]++){
    for(q[1] = 8; q[1] < 16; q[1]++){
      for(q[2] = 16; q[2] < 24; q[2]++){
        for(q[3] = 24; q[3] < 32; q[3]++){
          for(q[4] = 32; q[4] < 40; q[4]++){
            for(q[5] = 40; q[5] < 48; q[5]++){
              int cont = 0;
              for(int i = 0; i < N; i++){
                int erou = 0;
                if(removed[i]){
                  for(int j = 0; j < 6; j++){
                    if(!aluno[i][q[j]]) erou++;
                  }
                  if(erou >= 3) cont++;
                }
                else {
                  for(int j = 0; j < 6; j++){
                    if(!aluno[i][q[j]]) erou++;
                  }
                  if(erou < 3) cont++;
                }
              }
              //if(cont) printf("Cont = %d\n",cont);
              if(cont == N) {
                sat++;
                //printf("%d %d %d %d %d %d sat\n",q[0],q[1],q[2],q[3],q[4],q[5]);
              }
            }
          }
        }
      }
    }
  }
  return sat;
}

int main(){
    cin >> gabarito;
    scanf("%d",&N);
    char flag;
    for(int i = 0; i < N; i++){
        cin >> aluno[i];
        scanf(" %c",&flag);
        removed[i] = flag == '-' ? 1 : 0;
        for(int j = 0; j < 48; j++){
            if(tolower(aluno[i][j]) == tolower(gabarito[j]))
                aluno[i][j] = 1;
            else aluno[i][j] = 0;
        }
        //cout << aluno[i] << endl;
    }                           
    printf("%s\n",solve()==1?"Yes":"No");    
    return 0;
}