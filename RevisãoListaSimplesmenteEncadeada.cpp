#include<stdio.h>
#include<stdlib.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;

    Lista() {
        cabeca = cauda = NULL;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserirInicio(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
    }

    void inserirFinal(int v) {
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
    }

    void imprimir() {
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() {
        int t = 0;
        No *aux = cabeca;
        while (aux != NULL) {
            t++;
            aux = aux->prox;
        }
        return t;
        }

// -----------------------------------------------------------

    // 1 -----------------------------------------------------
    bool possuiElemento(int elemento){

        No *aux = cabeca;

        while (aux != NULL) {

            if(aux->valor == elemento){

                return true;

            }

            aux = aux->prox;

        }
    }

    // 2 -----------------------------------------------------
    void removerElementosIguais(int elemento) {

        No *aux = cabeca;
        No *anterior = NULL;

        while (aux != NULL) {

            if(aux == cabeca && aux->valor == elemento){

                No *temporario = cabeca;
                cabeca = aux->prox;
                aux = cabeca;
                delete temporario;
                anterior = NULL;

            }

            if(aux != cabeca && aux->valor == elemento){

                No *temporario = aux;
                aux = anterior;
                aux->prox = temporario->prox;
                delete temporario;

            }

            if(aux->prox == cauda && cauda->valor == elemento){

                No *temporario = cauda;
                aux->prox = NULL;
                cauda = aux;
                delete temporario;

            }

            if(aux->prox != NULL){

                anterior = aux;

            }

            aux = aux->prox;

        }

    }

    // 3 -----------------------------------------------------
    void inserirSeNaoPossuir(int elemento) {

        if(possuiElemento(elemento) == false){

            inserirFinal(elemento);

        }
    }

};

int main() {

    Lista l;

    int escolha, elemento;

    do{
        printf("Escolha uma opcao:\n");
        printf("\n1- Inserir no final\n");
        printf("2- Imprimir a lista\n");
        printf("3- Verificar se um determinado elemento existe na lista\n");
        printf("4- Remover ocorrencias de um elemento da lista\n");
        printf("5- Inserir elemento na lista se a lista nao o possuir\n");
        printf("6- Sair\n");
        scanf("%d", &escolha);

        switch(escolha){

        case 1:

            system("cls");
            printf("Digite um elemento para inserir: ");
            scanf("%d", &elemento);
            l.inserirFinal(elemento);
            printf("Numero inserido!\n\n");
            break;

        case 2:

            system("cls");
            printf("Lista:\n");
            l.imprimir();
            printf("\n");
            break;

        case 3:

            system("cls");
            printf("Digite um elemento para verificar: ");
            scanf("%d", &elemento);
            if(l.possuiElemento(elemento) == true){

                printf("A lista possui o elemento %d!\n\n", elemento);

            }else {

                printf("A lista nao possui o elemento %d!\n\n", elemento);
            }
            break;

        case 4:
            system("cls");
            printf("Digite um elemento para verificar e excluir da lista: ");
            scanf("%d", &elemento);
            l.removerElementosIguais(elemento);
            printf("Processo finalizado!\n");
            printf("Lista:\n");
            l.imprimir();
            printf("\n");
            break;

        case 5:
            system("cls");
            printf("Digite um elemento para inserir se a lista nao o possuir: ");
            scanf("%d", &elemento);
            l.inserirSeNaoPossuir(elemento);
            printf("Processo finalizado!\n");
            printf("Lista:\n");
            l.imprimir();
            printf("\n");
            break;

        case 6:
            system("cls");
            printf("\nPrograma encerrado!\n");

        }

    }while(escolha != 6);

    return 0;
}
