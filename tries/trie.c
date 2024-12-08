#include "trie.h"
#include <string.h>

int main() {

    trie_nodo_t *raiz=trie_cria_nodo();
    trie_insere(raiz, "casas");
    trie_insere(raiz, "casaco");
    trie_insere(raiz, "cachorro");
    int conta=conta_nodos(raiz);
    printf("Total Nodos: %d\n", conta);
    char palavra[50];
    imprime_todas_chaves(raiz);
    imprime_todas_chaves_2(raiz, palavra, conta);
    trie_destroi(raiz);

    return 0;
}

int conta_nodos(trie_nodo_t *raiz){
    if(raiz==NULL){
        return 0;
    }
    int conta=1;
    for(int i=0; i<26; i++){
        conta+=conta_nodos(raiz->chave[i]);
    }
    return conta;
}
void imprime_todas_chaves(trie_nodo_t *raiz){//essa imprime todas as chaves mas bagunçado
    trie_nodo_t *atual = raiz;
    if(atual->chave==NULL){
        return;
    }

    for(int i=0; i<26; i++){
        if(raiz->chave[i]!=NULL){
            printf("\n%c", (i+'a'));
            imprime_todas_chaves(raiz->chave[i]);
        }
        if(raiz->eh_final_palavra==1){
            return;
        }
    }
}
void imprime_todas_chaves_2(trie_nodo_t *raiz, char *palavra, int conta) {

    if(raiz==NULL||conta<=0){
        return;
    }
    if (raiz->eh_final_palavra) {
        palavra[0]=' ';
        printf("\n%s\n", palavra);
    }

    for (int i=0; i<26; i++) {
        if (raiz->chave[i]!=NULL) {
            int len=strlen(palavra);
            palavra[len]=i+'a';
            palavra[len+1]='\0'; // a falta dessa linha estava comprometendo o programa, usei o gpt nessa linha

            imprime_todas_chaves_2(raiz->chave[i], palavra, conta-1);

            palavra[len]='\0';
        }
    }
}

/* cria um novo nó */
trie_nodo_t *trie_cria_nodo(void){
    trie_nodo_t *novo_no = (trie_nodo_t *)malloc(sizeof(trie_nodo_t));
    if(novo_no == NULL){
        fprintf(stderr, "Erro ao alocar memória para um novo nó\n");
        exit(1);
    }
    novo_no->eh_final_palavra = 0;
    for(int i = 0; i < TAM_ALFABETO; i++){
        novo_no->chave[i] = NULL;
    }
    return novo_no;
}

/* insere uma palavra na trie*/
void trie_insere(trie_nodo_t *raiz, char *chave){
    trie_nodo_t *atual = raiz;
    for(int i = 0; chave[i] != '\0'; i++){
        int idx = chave[i] - 'a';
        if(atual->chave[idx] == NULL){
            atual->chave[idx] = trie_cria_nodo();
        }
        atual = atual->chave[idx];
    }
    atual->eh_final_palavra = 1;
} 

/* busca uma palavra na trie */
int trie_busca(trie_nodo_t *raiz, char *chave){
    trie_nodo_t *atual = raiz;
    for(int i = 0; chave[i] != '\0'; i++){
        int idx = chave[i] - 'a'; // calcula o indice da letra
        if(atual->chave[idx] == NULL){
            return 0;
        }
        atual = atual->chave[idx];
    }
    return atual->eh_final_palavra;
}

/* destroi a trie */
void trie_destroi(trie_nodo_t *raiz){
    for(int i = 0; i < TAM_ALFABETO; i++){
        if(raiz->chave[i] != NULL){ // se o nó atual não for nulo
            trie_destroi(raiz->chave[i]);
        }
    }
    free(raiz);
}
