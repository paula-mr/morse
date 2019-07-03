#include "Arvore.h"
#include "Criptografia.h"
#include "Orquestrador.h"

int main (int argc, char *argv[]) {
    //carrega arvore do arquivo
    Arvore* arvore = carregarArvore();
    //descriptografa entrada recebida
    descriptografar(arvore);

    //caso receba o parametro, exibe a arvore em pre ordem
    if (argc == 2 && argv[1][1] == 'a') {
        arvore->lerPreOrdem();
    }

    return 0;
}
