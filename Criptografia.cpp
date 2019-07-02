#include "Criptografia.h"
#include <iostream>

void descriptografar(Arvore* arvore) {
    char ch;

    int contandorLetras = 0, contadorCaracteresCodigo = 0;

    while((ch = getchar())) {
        char resposta[200];
        char codigo[10];

        if (ch == '/') {
            resposta[contandorLetras] = ' ';
            contadorCaracteresCodigo++;
            contandorLetras++;
        } else if (ch != ' ') {
            codigo[contadorCaracteresCodigo] = ch;
            contadorCaracteresCodigo++;
        } else {
            codigo[contadorCaracteresCodigo] = '\0';
            std::cout << codigo <<std::endl;
            resposta[contandorLetras] = arvore->pesquisar(codigo)->letra;
            contandorLetras++;

            std::cout << resposta <<std::endl;
        }
    }

}
