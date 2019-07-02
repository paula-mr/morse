#include "Arvore.h"
#include "Criptografia.h"
#include "Orquestrador.h"

#include <iostream>

int main () {
    Arvore* arvore = carregarArvore();
    arvore->lerPreOrdem();

    return 0;
}
