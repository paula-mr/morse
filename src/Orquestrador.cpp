#include "Orquestrador.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Arvore* carregarArvore() {
    Arvore* arvore = new Arvore();

    //inicializa arquivo
    FILE *fp;
    fp = fopen("morse.txt", "r");

    //valida arquivo
    if (fp == NULL) {
        std::cout << "Não foi possível abrir o arquivo com a codificação morse";
        return nullptr;
    }

    //le caracter ate chegar ao fim do arquivo
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        //cria novo no
        No* no = new No();
        no->esquerda = nullptr;
        no->direita = nullptr;
        //primeiro char lido representa a letra
        no->letra = ch;

        //le espaco entre letra e codigo
        fgetc(fp);

        //le o codigo ate chegar ao fim da linha
        char codigo[10];
        int i = 0;
        while((ch = fgetc(fp)) != '\n' && ch != EOF) {
            codigo[i] = ch;
            i++;
        }
        //demarca final da string de codigo
        codigo[i] = '\0';

        no->codigo = codigo;
        //insere no na arvore
        arvore->inserir(no);
    }

    //fecha arquivo
    fclose(fp);

    return arvore;
}
