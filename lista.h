#ifndef LISTA_H
#define LISTA_H

typedef struct no * lista;
struct no{
    int valor;
    lista prox;
    lista ant;
};

void mostraLista(lista);
lista iniciaLista();
lista insereLista(lista, int);
lista removeLista(lista, int);

void menu();


#endif 

