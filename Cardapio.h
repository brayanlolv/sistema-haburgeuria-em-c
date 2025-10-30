#include "CardapioItem.h"
#include <string.h>
#include <stdlib.h>

typedef struct {
	int qtd,cap;
	CardItem* itens;	
	int* teste;
} Cardapio;



salvarCardapio(Cardapio * cdp){
	FILE *fptr;
	fptr = fopen("./database.txt", "w");
	int i ;
	for(i = 0; i < cdp->qtd;i++){
		fprintf(fptr, cdp->itens[i].nome);
		fprintf(fptr, "\n");
		fprintf(fptr,"%d",cdp->itens[i].preco);
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}



//versao 1 
//Cardapio* criarCardapio(){
// 	Cardapio cdp;
// 	cdp.cap = 5 ;
//	cdp.qtd = 0;
////	cdp.teste = (int*)malloc(2 * sizeof(int)); 
//	cdp.itens = (CardItem*)malloc(5 * sizeof( CardItem));
//	Cardapio *ptr = (Cardapio*)malloc(sizeof( Cardapio) );
//	*ptr = cdp;
//	return ptr;
//};



void addItem(Cardapio * cdp,CardItem ci){
	//printf("adicionando");
	if(
		cdp->qtd >= cdp->cap
	){
		printf("oi");
		CardItem* nPtr = (CardItem*)malloc(cdp->qtd * 2 * sizeof(CardItem));
		CardItem* xp =cdp->itens;
		CardItem* yp = nPtr;
		int i;
		
		for (i = 0;i < cdp->qtd;i++){
			*yp = *xp;
			xp += sizeof(CardItem);
			yp += sizeof(CardItem);
		}	
		free(cdp->itens);
		cdp->itens = nPtr;	
	}
	

//
//	CardItem*  ptr = cdp->itens + sizeof(CardItem) * cdp->qtd;
//	*ptr = ci; 
	cdp->itens[cdp->qtd++] = ci;
//	cdp->qtd++;
	
}

lerCardapio(Cardapio * cdp){
	
	FILE *filePointer;
    filePointer = fopen("database.txt", "r");
	char buffer[250]; // Buffer to store a line of text
	int i = 0;
	CardItem c1;

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
 		strcpy(c1.nome,buffer);
		//printf("%s", buffer);         
        fgets(buffer, sizeof(buffer), filePointer);
        c1.preco = atoi(buffer);
         addItem(cdp,c1);
         //prtItem(c1);
	}
    
 
    
	fclose(filePointer);
	
}

Cardapio* criarCardapio(){


 	Cardapio cdp;
 	cdp.cap = 5 ;
	cdp.qtd = 0;
//	cdp.teste = (int*)malloc(2 * sizeof(int)); 
	cdp.itens = (CardItem*)malloc(5 * sizeof( CardItem));
	Cardapio *ptr = (Cardapio*)malloc(sizeof( Cardapio) );
	*ptr = cdp;
	
	lerCardapio(ptr);
	return ptr;
};

//criar uma funcao listar, que retorne um array de duas strings


void removerItem(Cardapio * cdp, int index){
	int i;
	cdp->qtd--;
	for (i = index; i < cdp->qtd;i++){
		cdp->itens[i] = cdp->itens[i+1];
	}
}



void listarCardapio(Cardapio * cdp){
	printf("qtd no listar %d",cdp->qtd);
	int i;
	CardItem* ptr =  cdp->itens;
	for(i = 0; i < cdp->qtd; i++){
		prtItem(cdp->itens[i]);
//		ptr += sizeof(CardItem);
	}
}


//void addTeste(Cardapio* cdp,int i){
//
//	if(
//		cdp->qtd >= sizeof(cdp->teste) / sizeof(int) 
//	){
//		int* nPtr = (int*)malloc(cdp->qtd * 2 * sizeof(int));
//		int* xp =cdp->teste;
//		int* yp = nPtr;
//		int i;
//		
//		for (i = 0;i < cdp->qtd;i++){
//			*yp = *xp;
//			xp += sizeof(int);
//			yp += sizeof(int);
//		}	
//		free(cdp->teste);
//		cdp->teste = nPtr;	
//	}
//	
//	*cdp->teste + cdp->qtd = i;
//
//	int* ptr =cdp->teste + sizeof(int)*cdp->qtd;
//	*ptr = i; 
//	cdp->qtd++;
//}

void listarTeste(Cardapio * cdp){
	int i;
	int* ptr =  cdp->teste;
	for(i = 0; i < cdp->qtd; i++){
		printf("\n%d",*ptr);
		ptr += sizeof(int);
	}
}


