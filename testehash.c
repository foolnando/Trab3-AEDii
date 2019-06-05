#include <stdio.h>
#include <stdlib.h>

typedef struct Produto{
	int id; 		//4	(CHAVE)
	int modelo;  	// 4
	float custo; 	// 4
	char nome[32];	// 32
	int quantidade; //4
}Produto;

typedef struct hash{
  int tableSize;
  int qtd;
  Produto **item;
  int numCo;
}hash;


hash* criaHash(int tableSize){

  hash* h = (hash*) malloc(sizeof(hash));
  if(h != NULL){
		int i;
    h->tableSize = tableSize;
    h->item = (Produto**) malloc(sizeof(Produto));
    if(h->item ==  NULL){
      free(h);
      return NULL;
    }
    h->qtd = 0;
    for(i=0;i < h->tableSize; i++){
      h->item[i] = NULL;
    }
  }
	printf("jhjdhfjahjk00\n");
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

int chaveMultiplica(int chave, int tableSize){
  float a = 0.618033898;
  float val = chave*a;
  val = val - (int)val;
  return (int) (tableSize*val);
}


int sondagemLinear(int pos,int i, int tableSize){
  return ((pos + i) & 0x7FFFFFFF) & tableSize;
}

int contaColisao(hash* h){
	h->numCo++;
}

int insereHash_enderAberto(hash* h, Produto *p){
	printf("fffffff\n");
  if(h == NULL || h->qtd == h->tableSize){
    return 0;
  }
  int chave = p->id;
  int i, pos, newPos;

  pos = chaveDivisao(chave, h->tableSize);
  for(i=0;i<h->tableSize;i++){
    newPos = sondagemLinear(pos,i, h->tableSize);
		printf("fffffff\n");

    if(h->item[newPos] == NULL){
			Produto *nov;
			nov = (Produto*)malloc(sizeof(Produto));
			if(nov == NULL){
				return 0;
			}
			nov = p;

      h->item[newPos] = nov;
      h->qtd++;
      return 1;
			printf("inseriu");
    }
    return 0;
		printf("inseriu");
  }
}
int buscaHash_enderAberto(hash* h, int id, Produto *p){
  if(h == NULL){
    return 0;
  }
  int i,pos, newPos;
  pos = chaveDivisao(id, h->tableSize);
  for(i=0;i < h->tableSize; i++){
    newPos = sondagemLinear(pos,i,h->tableSize);
    if(h->item[newPos] == NULL){
      return 0;
    }
    if(h->item[newPos]->id == id){
      *p = *(h->item[newPos]);
      return 1;
    }
  }
  return 0;

}


int main(){
	Produto *po;
	po = (Produto*)malloc(sizeof(Produto));
	po->id =123312;
	po->custo=941;
	po->quantidade=1923;
	po->modelo=93;
	hash *ha;
	printf("adjds\n");
	criaHash(10);
	if(ha == NULL){
		printf("deu merda\n" );
	}


	int a,b;
	b = insereHash_enderAberto(ha, po);
	a = buscaHash_enderAberto(ha, 4,po);
	printf("%d %d\n",a,b );
	printf("adjds\n");


}
