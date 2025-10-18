#include "CardapioItem.h"


typedef struct {
	int qtd,cap;
	CardItem* itens;	
	int* teste;
} Cardapio;



Cardapio* criarCardapio(){
 	Cardapio cdp;
 	cdp.cap = 5 ;
	cdp.qtd = 0;
//	cdp.teste = (int*)malloc(2 * sizeof(int)); 
	cdp.itens = (CardItem*)malloc(5 * sizeof( CardItem));
	Cardapio *ptr = (Cardapio*)malloc(sizeof( Cardapio) );
	*ptr = cdp;
	return ptr;
};



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
	cdp->qtd++;
	
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


