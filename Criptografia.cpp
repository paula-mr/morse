#include "Criptografia.h"
#include <iostream>

void descriptografar(Arvore* arvore) {
    char ch;

    int contadorLetras = 0, contadorCaracteresCodigo = 0;
    char anterior = ' ';
    char resposta[200];
    char codigo[10];

    while((ch = getchar()) != EOF) {
        if (ch == '/') {
            resposta[contadorLetras] = ' ';
            resposta[++contadorLetras] = '\0';
            contadorCaracteresCodigo = 0;
        } else if (ch != ' ' && ch != '\n') {
            codigo[contadorCaracteresCodigo] = ch;
            contadorCaracteresCodigo++;
        } else if (anterior != '/'){
            codigo[contadorCaracteresCodigo] = '\0';
            resposta[contadorLetras] = arvore->pesquisar(codigo)->letra;
            contadorCaracteresCodigo = 0;

            resposta[++contadorLetras] = '\0';
        }

        if (ch == '\n') {
            std::cout << resposta <<std::endl;
            resposta[0] = '\0';
            contadorLetras = 0;
            contadorCaracteresCodigo = 0;
        }

        anterior = ch;
    }

    codigo[contadorCaracteresCodigo] = '\0';
    resposta[contadorLetras] = arvore->pesquisar(codigo)->letra;
    contadorCaracteresCodigo = 0;

    resposta[++contadorLetras] = '\0';
    std::cout << resposta;
}
