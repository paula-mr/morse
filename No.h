#ifndef NO_H
#define NO_H

class No {
    public:
        char* codigo;
        char letra;
        No* esquerda;
        No* direita;

        No();
        ~No();
};

#endif
