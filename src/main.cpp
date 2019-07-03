#include "Arvore.h"
#include "Criptografia.h"
#include "Orquestrador.h"

#include <iostream>

int main (int argc, char *argv[]) {
    Arvore* arvore = carregarArvore();
    descriptografar(arvore);

    if (argc == 2 && argv[1][1] == 'a') {
        arvore->lerPreOrdem();
    }

    return 0;
}
