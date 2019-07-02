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
        std::cout << "INSERIDO " << item->letra << " " << item->codigo << "\n";
        return;
    }

    item = raiz;
    for (int i=1; no->codigo[i] != '\0'; i++) {
        char* codigo = copiarString(item->codigo, i);

        No* novoItem = new No();
        novoItem->direita = nullptr;
        novoItem->esquerda = nullptr;
        novoItem->codigo = codigo;

        std::cout << "INSERIDO " << item->letra << " " << item->codigo << "\n";
        if (item->codigo[i] == '.') {
            item->esquerda = novoItem;
            item = item->esquerda;
        } else {
            item->direita = novoItem;
            item = item->direita;
        }
        i++;
    }
}

char* copiarString(char* palavra, int tamanho) {
    char* copia = (char*)malloc(10*sizeof(char));

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
