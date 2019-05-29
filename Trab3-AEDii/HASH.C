#include <stdio.h>
#include <stdlib.h>
#include "HASH.h"

hash* criaHash(int tableSize){
  int i;
  hash* h = (hash*) malloc(sizeof(hash));
  if(h != NULL){
    h->tableSize = tableSize;
    h->item = (Produto*) malloc(sizeof(Produto));
    if(h->item ==  NULL){
      free(h);
      return NULL;
    }
    h->qtd = 0;
    for(i=0;i < (h->tableSize); i++){
      h->item[i] = NULL;
    }
  }
  return h;
}

void liberaHash(hash* h){
  int i;
  if(h != NULL){
    for(i = 0; i < (h->tableSize);i++){
      if(h->item[i] != NULL){
        free(h->item[i]);
      }
    }
    free(h->item);
    free(h);
  }
}

int chaveDivisao(int chave, int tableSize){
  return(chave & 0x7FFFFFFF) % tableSize;
}
