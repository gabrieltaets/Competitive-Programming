#include <bits/stdc++.h>
using namespace std;

typedef struct no {
  char pal[50];
  struct no *prox;
} noLista;

noLista* calculaDif(noLista *primA, noLista *primB){
  noLista *primC = NULL;
  noLista *atualA = primA, *atualB = primB, *atualC = primC;
  while(atualA != NULL){
    atualB = primB;
    while(atualB != NULL){
      if(strcmp(atualA->pal,atualB->pal)!=0){
        noLista *novo = (noLista *) malloc(sizeof(noLista *));
        novo->prox = NULL;
        if(primC == NULL){
          primC = novo;
          atualC = primC;
        }
        else {
          atualC->prox = novo;
          atualC = atualC->prox;
        }
        strcpy(novo->pal,atualA->pal);
      }
      atualB = atualB->prox;
    }
    atualA = atualA->prox;
  }
  return primC;
}


int main(){
  
}