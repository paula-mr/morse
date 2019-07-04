#include "Arvore.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

void itemPreOrdem(No* no);
char* copiarString(char* palavra, int tamanho);


Arvore::~Arvore() = default;

Arvore::Arvore() {
    //inicia raiz da arvore vazia
    No* no = new No();
    no->esquerda = nullptr;
    no->direita = nullptr;

    raiz = no;
}

void Arvore::inserir(No* novoItem) {
    //pesquisa item pelo codigo
    No* item = pesquisar(novoItem->codigo);

    //se o item ja existe na arvore, insere a letra correspondente
    //e finaliza a funcao
    if (item != nullptr) {
        item->letra = novoItem->letra;
        return;
    }

    //se o item nao existe, percorre a arvore a partir da raiz
    item = raiz;

    for (int i=0; novoItem->codigo[i] != '\0'; i++) {
        //trunca o codigo ate a i-esima posicao (inclusive)
        char* codigo = copiarString(novoItem->codigo, i+1);

        //pesquisa o no intermediario
        No* itemIntermediario = pesquisar(codigo);

        //se o no intermediario nao existe, o insere
        if (itemIntermediario == nullptr) {
            itemIntermediario = new No();
            itemIntermediario->direita = nullptr;
            itemIntermediario->esquerda = nullptr;
            itemIntermediario->codigo = codigo;

            //insere o novo no na posicao correta a partir da i-esima
            //posicao do codigo
            if (novoItem->codigo[i] == '.') {
                item->esquerda = itemIntermediario;
            } else {
                item->direita = itemIntermediario;
            }
        }

        //atualiza item usado para percorrer a arvore
        if (novoItem->codigo[i] == '.') {
            item = item->esquerda;
        } else {
            item = item->direita;
        }

    }

    //adiciona a letra correspondente ao ultimo item adicionado
    item->letra = novoItem->letra;
}

char* copiarString(char* palavra, int tamanho) {
    //aloca a quantidade de memoria necessaria para a copia da string
    char* copia = (char*)malloc((tamanho+1)*sizeof(char));

    //copia elemento por elemento
    for (int i = 0; i < tamanho; i++) {
        copia[i] = palavra[i];
    }

    //seta o ultimo elemento como o caracter delimitador de string
    copia[tamanho] = '\0';

    return copia;
}

void Arvore::lerPreOrdem() {
    //le a arvore no tipo pre ordem
    itemPreOrdem(raiz);
}

void itemPreOrdem(No* no) {
    //condicao de parada para funcao recursiva
    if (no == nullptr)
        return;

    //imprime elemento se o no nao eh vazio
    if (no->letra != '\0')
        std::cout << std::endl << no->letra << " " << no->codigo;

    //le subarvores
    itemPreOrdem(no->esquerda);
    itemPreOrdem(no->direita);
}

No* Arvore::pesquisar(char* codigo) {
    //percorre arvore a partir da raiz
    No* item = raiz;

    //percorre arvore ate encontrar ou ate chegar em uma folha vazia
    for (int i=0; codigo[i] != '\0' && item != nullptr; i++) {
        if (codigo[i] == '.') {
            item = item->esquerda;
        } else {
            item = item->direita;
        }
    }    return item;
}
