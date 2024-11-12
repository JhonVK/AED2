#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

Arv* arv_cria() {
    return NULL;
}

//insere no arvore binaria de busca
Arv* arv_insere(Arv* a, int v) {
    if (a == NULL) {
        a = (Arv*) malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    } else if (v < a->info) {
        a->esq = arv_insere(a->esq, v);
    } else {
        a->dir = arv_insere(a->dir, v);
    }
    return a;
}

//libera a arvore binaria de busca
void arv_libera(Arv* a) {
    if (a != NULL) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
}
void arv_imprime(Arv* a){
    if(a==NULL){
        return;
    }
    arv_imprime(a->esq);
    printf("%d\n", a->info);
    arv_imprime(a->dir);

}
int maiores_que_x(Arv* a, int x){
    int soma=0;

    if(a->esq!=NULL){
       soma+=+maiores_que_x(a->esq, x); 
    }
    
    if(a->dir!=NULL){
       soma+=maiores_que_x(a->dir, x); 
    }

    if (a->info>x){
        soma += 1; 
    } 
    return soma;
}
Arv* menor_valor(Arv* a){
       
    while(a->esq!=NULL){
        a=a->esq;
    } 
    return a;
 

}

Arv* arv_busca_recursiva(Arv* r, int v) {
    if (r == NULL) {
        return NULL;
    } else if (r->info > v) {
        return arv_busca_recursiva(r->esq, v);
    } else if (r->info < v) {
        return arv_busca_recursiva(r->dir, v);
    } else {
        return r;
    }
}

Arv* arv_busca_iterativa(Arv* r, int v) {
    while (r != NULL) {
        if (r->info > v) {
            r = r->esq;
        } else if (r->info < v) {
            r = r->dir;
        } else {
            return r;
        }
    }
    return NULL;
}