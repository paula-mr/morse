#include "Arvore.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

void itemPreOrdem(No* no);
char* copiarString(char* palavra, int tamanho);


Arvore::~Arvore() = default;

Arvore::Arvore() {
    No* no = new No();

    no->esquerda = nullptr;
    no->direita = nullptr;

    raiz = no;
}

void Arvore::inserir(No* novoItem) {
    No* item = pesquisar(novoItem->codigo);

    if (item != nullptr) {
        item->letra = novoItem->letra;
        return;
    }

    item = raiz;

    for (int i=0; novoItem->codigo[i] != '\0'; i++) {
        char* codigo = copiarString(novoItem->codigo, i+1);

        No* itemIntermediario = pesquisar(codigo);

        if (itemIntermediario == nullptr) {
            itemIntermediario = new No();
            itemIntermediario->direita = nullptr;
            itemIntermediario->esquerda = nullptr;
            itemIntermediario->codigo = codigo;

            if (novoItem->codigo[i] == '.') {
                item->esquerda = itemIntermediario;
            } else {
                item->direita = itemIntermediario;
            }
        }

        if (novoItem->codigo[i] == '.') {
            item = item->esquerda;
        } else {
            item = item->direita;
        }

    }

    item->letra = novoItem->letra;
}

char* copiarString(char* palavra, int tamanho) {
    char* copia = (char*)malloc((tamanho+1)*sizeof(char));

    for (int i = 0; i < tamanho; i++) {
        copia[i] = palavra[i];
    }

    copia[tamanho] = '\0';

    return copia;
}

void Arvore::lerPreOrdem() {
    itemPreOrdem(raiz->esquerda);
    itemPreOrdem(raiz->direita);
}

void itemPreOrdem(No* no) {
    if (no == nullptr)
        return;

    if (no->letra != '\0')
        std::cout << no->letra << " " << no->codigo << std::endl;

    itemPreOrdem(no->esquerda);
    itemPreOrdem(no->direita);
}

No* Arvore::pesquisar(char* codigo) {
    No* item = raiz;

    for (int i=0; codigo[i] != '\0' && item != nullptr; i++) {
        if (codigo[i] == '.') {
            item = item->esquerda;
        } else {
            item = item->direita;
        }
    }    return item;
}
