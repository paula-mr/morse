#include "No.h"

No::No() {
    //inicializa no com propriedades vazias
    codigo = nullptr;
    letra = '\0';
    esquerda = nullptr;
    direita = nullptr;
}

No::~No() = default;
