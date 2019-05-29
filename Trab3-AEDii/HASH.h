#ifndef HASH_H
#define HASH_H

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
}hash;



#endif
