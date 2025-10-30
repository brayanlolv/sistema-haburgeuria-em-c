#include <stdio.h>
#include <stdlib.h>

#include "Cardapio.h"

#include "tela20.h"
#include "tela.h"

int engine(int tela ){

	//o if 2 da tela da listqa vai estar na while
}


int main(){

	Cardapio* cdp = criarCardapio();

//	CardItem c1 = {"x-tudo",20000};	
//	CardItem c2 = {"x-bacon",15000};
//	addItem(cdp,c2);
//	addItem(cdp,c1);
//	printf("qtd do cdp %d",cdp->qtd);
	
	 
	int tela = 0;
	while(1){
		
		//salvarCardapio(cdp);
		
		if(tela == 0){
			tela = cardapioMenu();
		}else if(tela == 1){
			tela = telaAddPrato(cdp);
		}else if(tela == 2){
			tela = listateste(cdp);
		}
		
	}
//	printf("oba");
//
//
//	

////
//
//	listarCardapio(cdp);
//	
////	
//	listarCardapio(cdp);

	
	
	
	
	
	
	
	
	
//	
//	//sessap de teste em fazer um aray dinamico
//	printf("bora \n");	
//	Cardapio* cdp = criarCardapio();
//	printf("qtd = %d", cdp->qtd);
//	addTeste(cdp,39);
//	addTeste(cdp,3);
//	addTeste(cdp,8);
//	printf("\n depoisd e add \nqtd = %d", cdp->qtd);
//	listarTeste(cdp);


	
	
	
	
	
	
	system("pause>>null");
	return 0;
}
