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

void Arvore::inserir(No* no) {
    No* item = pesquisar(no->codigo);

    if (item != nullptr) {
        item->letra = no->letra;
        return;
    }

    No* novoItem;
    item = raiz;
    for (int i=0; no->codigo[i] != '\0'; i++) {
        char* codigo = copiarString(no->codigo, i+1);

        No* novoItem = pesquisar(codigo);

        if (novoItem == nullptr) {
            novoItem = new No();
            novoItem->direita = nullptr;
            novoItem->esquerda = nullptr;
            novoItem->codigo = codigo;

            if (item->codigo[i] == '.') {
                item->esquerda = novoItem;
            } else {
                item->direita = novoItem;
            }
        }

        if (item->codigo[i] == '.') {
            item = item->esquerda;
        } else {
            item = item->direita;
        }

    }

    item->letra = no->letra;

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
    std::cout << "teste" << std::endl;

    itemPreOrdem(raiz->esquerda);
    itemPreOrdem(raiz->direita);
}

void itemPreOrdem(No* no) {
    if (no == nullptr)
        return;


    std::cout << no->codigo << std::endl;

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
        std::cout << item->letra << std::endl;
    }

    return item;
}
