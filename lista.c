#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/*_________________________________________________________
                                                       /*|*/
//WHERE YOUR DATA WILL BE APPENDED IN YOUR LIST?     | /*|*/
//insert an "x" below in front of the chosen option  V /*|*/
#define APP_BEGINNING(x)/*-----------------------*/  x  /*|*/
#define APP_ORGANIZED(x)/*-----------------------*/    /*|*/
#define APP_END(x)/*-----------------------------*/    /*|*/
/*_______________________________________________________*/

/*__________________________________________________________
                                                        /*|*/
//SELECT THE ORDER YOU WANT YOU DATA TO BE SHOWN     |  /*|*/
//insert an "x" below in front of the chosen option  V  /*|*/
#define SMALLEST_TO_BIGGEST(x)/*------------------*/ x  /*|*/
#define BIGGEST_TO_SMALLEST(x)/*------------------*/    /*|*/
/*________________________________________________________*/

/*________________________________________________________
                                                      /*|*/
//HOW DO YOU WANT TO REMOVE ITEMS FROM YOUR LIST?   | /*|*/
//insert an "x" below in front of the chosen option  V /*|*/
#define REM_BEGINNING(x)/*-----------------------*/ x  /*|*/
#define REM_ELEMENT(x)/*-------------------------*/   /*|*/
#define REM_END(x)/*-----------------------------*/   /*|*/
/*_______________________________________________________*/



lista iniciaLista(){
    return NULL;
}

void mostraLista(lista ptlista){
    if(ptlista != NULL){
SMALLEST_TO_BIGGEST(
            lista aux = ptlista;
                printf("NULL");
                while(aux != NULL){
                    printf(" <-[| %d |]->", aux->valor);

                    aux=aux->prox;	
                }
                printf(" NULL\n");
)

BIGGEST_TO_SMALLEST(
            lista aux = ptlista;
                while(aux->prox != NULL)
                    aux=aux->prox;
        
                printf("NULL");
                while(aux != NULL){
                    printf(" <-[| %d |]->", aux->valor);
                    aux=aux->ant;
                }
                        printf(" NULL\n");
        )
    }
}

lista insereLista(lista ptlista, int valor){
    lista prov;

    prov = (lista)malloc(sizeof(struct no));

    prov->valor = valor;

// INSERE NO INICIO:
APP_BEGINNING(
    prov->prox = ptlista;
    prov->ant = NULL;

    if(ptlista != NULL)
        ptlista->ant = prov;
    
    ptlista = prov;
)

//INSERE NO FINAL:
APP_END(
    prov->prox = NULL;

    if(ptlista == NULL){
        prov->ant = NULL;
        ptlista = prov;
    }
    
    else{
        lista aux = ptlista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = prov;
        prov->ant = aux;
    }
)

//INSERE ORDENADA
APP_ORGANIZED(
    if(ptlista == NULL){
        prov->prox = NULL;
        prov->ant = NULL;
        ptlista = prov;
    }
    else{
        lista ante;
        lista atual = ptlista;
        while(atual != NULL && atual->valor < valor){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == ptlista){
            prov->ant = NULL;
            ptlista->ant = prov;
            prov->prox = ptlista;
            ptlista = prov;
        }
        else{
            prov->prox = ante->prox;
            prov->ant = ante;
            ante->prox = prov;
            if(atual != NULL){
                atual->ant = prov;
            }
        }
    }
)



    return ptlista;
}

lista removeLista(lista ptlista, int valor){
    
    lista aux = ptlista;

    while(aux != NULL && valor != aux->valor){
        aux = aux->prox;
    }

    if(aux != NULL){
        aux->ant = aux->prox;
    }
    
    return aux;
}

void menu(){
    
    lista ptlista = iniciaLista();
    int op = 0;
       
    while(op != 5){
        
        printf("\nDIGITE O COMANDO DESEJADO\n");
        printf("1 - INSERIR\n");
        printf("2 - MOSTRAR\n");
        printf("3 - REMOVER\n");
        printf("5 - SAIR\n");
        scanf("%d",&op);

        switch (op){
            case 1:
            {
                int valorI = 0;
                printf("\nDIGITE OS VALORES NATURAIS DA LISTA ENCADEADA: \n");
                scanf("%d",&valorI);
                while(valorI >= 0){
                    ptlista = insereLista(ptlista,valorI);
                    scanf("%d",&valorI);                   
                }
                printf("PREENCHIMENTO DA LISTA CONCLUÍDO\n");
            }
                break;
                
            case 2:
            {
                mostraLista(ptlista);
            }
                break;
                
            case 3:
            {
                int valorR = 0;
                printf("\nDIGITE O VALOR A SER REMOVIDO DA LISTA ENCADEADA: \n");
                scanf("%d",&valorR);
                lista no = removeLista(ptlista,valorR);
                if(no == NULL)
                    printf("VALOR NAO ENCONTRADO\n");
                else
                    printf("VALOR REMOVIDO: %d\n", no->valor);
            }
                break;
          
            
            default:
                printf("ENTRADA INVALIDA, DIGITE OUTRO COMANDO\n\n");
                break;
           
        }
    
    }
}
