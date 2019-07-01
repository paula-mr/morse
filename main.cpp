#include "Arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main () {
    Arvore* arvore = new Arvore();

    FILE *fp;

    fp = fopen("morse.txt", "r");

    if (fp == NULL) {
        std::cout << "Não foi possível abrir o arquivo com a codificação morse";
        return 1;
    }

    char ch;

    while((ch = fgetc(fp)) != EOF) {
        No* no = new No();
        no->esquerda = nullptr;
        no->direita = nullptr;
        no->letra = ch;

        //le espaco entre letra e codigo
        fgetc(fp);

        char codigo[10];
        int i = 0;

        while((ch = fgetc(fp)) != '\n' && ch != EOF) {
            codigo[i] = ch;
            i++;
        }
        codigo[i] = '\0';

        no->codigo = codigo;

        arvore->inserir(no);
    }

    fclose(fp);

    arvore->lerPreOrdem();

    return 0;
}
