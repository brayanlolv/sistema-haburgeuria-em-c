#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>

  //COR DA LETRA
  enum{BLACK,                 //0
       BLUE,                  //1
       GREEN,                 //2
       CYAN,                  //3
       RED,                   //4
       MAGENTA,               //5
       BROWN,                 //6
       LIGHTGRAY,             //7
       DARKGRAY,              //8
       LIGHTBLUE,             //9
       LIGHTGREEN,            //10
       LIGHTCYAN,             //11
       LIGHTRED,              //12
       LIGHTMAGENTA,          //13
       YELLOW,                //14
       WHITE                  //15
       
       };  
  //COR DO FUNDO
  enum{_BLACK=0,                 //0
       _BLUE=16,                  //1
       _GREEN=32,                 //2
       _CYAN=48,                  //3
       _RED=64,                   //4
       _MAGENTA=80,               //5
       _BROWN=96,                 //6
       _LIGHTGRAY=112,             //7
       _DARKGRAY=128,              //8
       _LIGHTBLUE=144,             //9
       _LIGHTGREEN=160,            //10
       _LIGHTCYAN=176,             //11
       _LIGHTRED=192,              //12
       _LIGHTMAGENTA=208,          //13
       _YELLOW=224,                //14
       _WHITE=240                  //15       
       };  

void gotoxy(int x,int y){// muda a posição do cursor
    COORD p={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void apagarlinha(int linha){
	int i;
	for(i = 0;i < 2; i++){
		gotoxy(i,linha);
		printf("%c",32);
	}
}

void textColor(int letra, int fundo){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
     }
     
void linhaCol(int lin, int col){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});// coorddenada na tela
     
     //funcao para deixar o cursor invisivel
     HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_CURSOR_INFO info;
     info.dwSize = 100;
     info.bVisible = FALSE;
     SetConsoleCursorInfo(consoleHandle, &info);
}
void box(int lin1, int col1, int lin2, int col2){
     int i,j , tamlin, tamcol;
     
     //achar o tamanho do box
     tamlin = lin2 - lin1;
     tamcol = col2 - col1;
     
     //Monta o Box
     
     for (i=col1; i<=col2; i++){ // linhas
         linhaCol(lin1,i);
         printf("%c",196);
         linhaCol(lin2,i);
         printf("%c",196);
         }
        
     for (i=lin1; i<=lin2; i++){ //colunas
         linhaCol(i,col1);
         printf("%c",179);
         linhaCol(i,col2);
         printf("%c",179);
         }
     for (i=lin1+1;i<lin2;i++){
         for(j=col1+1;j<col2;j++){
            linhaCol(i,j);printf(" ");
         }
         }
     //Posição dos cantos
     linhaCol(lin1,col1);
     printf("%c",218);
     linhaCol(lin1,col2);
     printf("%c",191);
     linhaCol(lin2,col1);
     printf("%c",192);
     linhaCol(lin2,col2);
     printf("%c",217);       
     
     }
int menu(int lin1, int col1, int qtd, char lista[3][40],int pontoInicial){
     int opc=pontoInicial, lin2, col2, linha,i,tamMaxItem, tecla;
     
     //calcula as coordenadas
     tamMaxItem = strlen(lista[0]);
     //tamanho maximo do item
     for(i=1; i<qtd;i++){
       if(strlen(lista[i])>tamMaxItem){
          tamMaxItem = strlen(lista[i]); 
       } 
     }
//     lin2 = lin1+(qtd*2+2);
//     col2 = col1+tamMaxItem+4;
     lin2 = 30;
     col2 =50;
     
     //Monta Tela
     textColor(WHITE, _BLUE);
     setlocale(LC_ALL,"C");
     box(lin1,col1,lin2,col2);
     setlocale(LC_ALL,"");
     //laço das opcões
     while(1){
     
        linha=lin1+2;
        for(i=0;i<qtd;i++){           
           if(i+1==opc)textColor(BLACK, _LIGHTGREEN);
           else textColor(WHITE, _BLUE);
        linhaCol(linha,col1+2);
        printf("%s",lista[i]);
        linha +=2;
        }
 		
		if(!pontoInicial){
		return 1;	
		}
       linhaCol(1,1);
       tecla= getch();
       linhaCol(22,1);
       //printf(" tecla:  %d   ",tecla);  
       //Opção
       if(tecla==27){ //ESC
       opc=0; break;
       }
       else if(tecla==13){ //ENTER
       break;
       }
       //Seta para cima
       else if(tecla==72){ //se possivel seleciona o item anterior - seta para cima
            if(opc>pontoInicial)opc--;  // se opcao for maior que 1, pode voltar 
       
       }
       else if(tecla==80 ){        //seta para baixo
            if (opc<qtd)opc++;                //Se opcao for menor que quantidade de itens, posso avançar
                  
                           
       //printf("tecla: %d ",opc);     
       }
     }
     return opc;
}     

int listaTela(int lin1, int col1, int qtdx,int qtdy, char lista[10][2][30],int pontoInicial){
     int opc=pontoInicial, lin2, col2, linha,i,j,tamMaxItem, tecla;
     
     //calcula as coordenadas
//     tamMaxItem = strlen(lista[0][0]);
	tamMaxItem = 30;
     //tamanho maximo do item
//     for(i=1; i<qtdx;i++){
//     	for(j = 0; j < qtdy ; j++ ){
//     		if(strlen(lista[i][j])>tamMaxItem){
//          tamMaxItem = strlen(lista[i][j]); 
//      	 } 
//		}
//    
//     }
//     lin2 = lin1+(qtd*2+2);
//     col2 = col1+tamMaxItem+4;
     lin2 = 30;
     col2 =50;
     
     //Monta Tela
     textColor(WHITE, _BLUE);
     setlocale(LC_ALL,"C");
     box(lin1,col1,lin2,col2);
     setlocale(LC_ALL,"");
     //laço das opcões
     while(1){
     
        linha=lin1+2;
        
        for(i = 0; i < qtdx;i++){
        
			if(i+1==opc)textColor(BLACK, _LIGHTGREEN);
            else textColor(WHITE, _BLUE);
        	for(j = 0;j < qtdy; j++){
        		 
				linhaCol(linha,col1+2);
				printf("%s",lista[i][j]);
				linha++;
			}
        	linha++;
		}
//        for(i=0;i<qtd;i++){           
//           if(i+1==opc)textColor(BLACK, _LIGHTGREEN);
//           else textColor(WHITE, _BLUE);
//        linhaCol(linha,col1+2);
//        printf("%s",lista[i]);
//        linha +=1;
//        }
// 		
		if(!pontoInicial){
		return 1;	
		}
       linhaCol(1,1);
       tecla= getch();
       linhaCol(22,1);
       //printf(" tecla:  %d   ",tecla);  
       //Opção
       if(tecla==27){ //ESC
       opc=0; break;
       }
       else if(tecla==13){ //ENTER
       break;
       }
       //Seta para cima
       else if(tecla==72){ //se possivel seleciona o item anterior - seta para cima
            if(opc>pontoInicial)opc--;  // se opcao for maior que 1, pode voltar 
       
       }
       else if(tecla==80 ){        //seta para baixo
            if (opc<qtdx)opc++;                //Se opcao for menor que quantidade de itens, posso avançar
                  
                           
       //printf("tecla: %d ",opc);     
       }
     }
     return opc;
}     

int listateste(Cardapio* cdp){
	
	int i ;
	
	int opc;
    char lista[10][2][30]={
	{"voltar","p menu"},
	{"Nome1","preco1"},
	{"Nome1","preco1"},	
	{"Nome1","preco1"},	
	{"Nome1","preco1"},
	};
	
//	strcpy(lista[0][0],cdp->itens[0].nome);
	
	
	for(i = 0;i < cdp->qtd ;i++){
		strcpy(lista[i + 1][0],cdp->itens[i].nome);
		char str[20]; // buffer onde a string vai ser escrita
    	sprintf(str, "%d", cdp->itens[i].preco); 	
		strcpy(lista[i + 1][1],str);	
		
	}
	
 listaTela(10,10, cdp->qtd + 1 ,2,lista,1);

	
}
int cardapioMenu()
{
    int opc;
    char lista[6][40]={"bem vindo a noaswsa haburueria","escolha uma das opcoes","listar cardapio","adcioanr prato","remover prato"};
    
    setlocale(LC_ALL,"");
    
       opc = menu(10,10,5,lista,3);
    
      
	    
	    
        linhaCol(1,1);
        textColor(WHITE, _RED);
        printf("\nEscolheu a opção %d", opc);
  textColor(WHITE, _BLACK);
  linhaCol(24,1);
  printf("");
  
  switch(opc){
  	case 4:
  		return 1;
  }
  return 0;

}

int telaAddPrato()
{
	CardItem cditm;
	int etapa = 0;
    int opc;
    char lista[5][40]={"tela de adicionar","comecar", "ok->", "desistir e votlar"};
    
    setlocale(LC_ALL,"");
    opc = menu(10,10,4,lista,3);
    linhaCol(1,1);
    while(opc){
    	etapa++;
//        linhaCol(1,1);
//        textColor(WHITE, _RED);
//        printf("\nEscolheu a opção %d", opc);
//        textColor(WHITE, _BLACK);
		if(etapa == 1 ){
				
				strcpy(lista[1],"digete o nome do item:");
				opc = menu(10,10,3,lista,0);
				
				linhaCol(1,1);
				scanf("%s",&cditm.nome);
		}
		else if(etapa == 2 ){
				strcpy(lista[1],"digete o preco do item( em centavos)");
				opc = menu(10,10,3,lista,0);
				linhaCol(1,1);
				scanf("%d",&cditm.preco);
		}
		else if(etapa == 3){
				linhaCol(1,1);
				printf("cditm.nome = %s ",cditm.nome);
			strcpy(lista[1],"item adcionado com sucesso");
			strcpy(lista[2],"------------");
			strcpy(lista[3],cditm.nome);
//			
			int numero = 1234;
    		char str[20]; // buffer onde a string vai ser escrita

			strcpy(lista[4],"preco:");
    		sprintf(str, "%d", cditm.preco); 		
			strcpy(lista[5],str);
			strcpy(lista[6],"ok");
			menu(10,10,6,lista,6);
			return 0;
		}
//       

    }
    return 0;
}
