#ifndef ARVORE_H
#define ARVORE_H

#include "No.h"

class Arvore {
    public:
        No* raiz;

        Arvore();
        ~Arvore();
        void inserir(No* no);
        void lerPreOrdem();
        No* pesquisar(char* codigo);
};
#endif
