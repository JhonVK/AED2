#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


int main(){

    Arv *raiz=arv_cria();
    raiz=arv_insere(raiz, 10);
    arv_insere(raiz, 20);
    arv_insere(raiz, 30);
    arv_insere(raiz, 15);
    arv_insere(raiz, 7);
    arv_imprime(raiz);
    Arv *menor=menor_valor(raiz);
    printf("Menor Valor: %d", menor->info);
    
    return 0;
}
