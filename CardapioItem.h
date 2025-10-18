typedef struct{
	char nome[50];
	int preco;
	//Receita* ptrReceita;
}CardItem;




void prtItem(CardItem  cdpi){
	printf("\nnome : %s ",cdpi.nome);
	printf("\npreco : %d ",cdpi.preco);
}


