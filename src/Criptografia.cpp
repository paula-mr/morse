#include "Criptografia.h"
#include <iostream>

//recebe chave de descriptografia
void descriptografar(Arvore* arvore) {
    char ch;

    //contador para a quantidade de letras da saida
    int contadorLetras = 0;
    //contador para a quantidade de caracteres do codigo
    //a ser descriptografado
    int contadorCaracteresCodigo = 0;
    //variavel auxiliar para salvar caracter anterior
    char anterior = ' ';

    char resposta[200];
    char codigo[10];

    //realiza descriptografia ate chegar ao fim da entrada
    while((ch = getchar()) != EOF) {

        //se o caracter recebido for o delimitador de palavra
        if (ch == '/') {
            //insere espaco na resposta e novo delimitador de fim de string
            resposta[contadorLetras] = ' ';
            resposta[++contadorLetras] = '\0';
            //reinicia contador de caracteres do codigo
            contadorCaracteresCodigo = 0;

        //se o caracter nao for espaco vazio ou nova linha
        } else if (ch != ' ' && ch != '\n') {
            //insere caracter na variavel a ser descriptografada
            codigo[contadorCaracteresCodigo] = ch;
            contadorCaracteresCodigo++;

        //se o caracter for espaco ou nova linha
        } else if (anterior != '/'){
            //finaliza variavel a ser descriptofrada
            codigo[contadorCaracteresCodigo] = '\0';
            //descriptografa codigo e insere na resposta
            resposta[contadorLetras] = arvore->pesquisar(codigo)->letra;
            resposta[++contadorLetras] = '\0';
            //reinicia contador de caracteres do codigo
            contadorCaracteresCodigo = 0;
        }

        //se o caracter for nova linha
        if (ch == '\n') {
            //imprime a saida
            std::cout << resposta <<std::endl;

            //reinicia variaveis de leitura
            resposta[0] = '\0';
            contadorLetras = 0;
            contadorCaracteresCodigo = 0;
        }

        //atualiza variavel anterior
        anterior = ch;
    }

    //descriptograda ultimo caracter inserido
    codigo[contadorCaracteresCodigo] = '\0';
    resposta[contadorLetras] = arvore->pesquisar(codigo)->letra;
    resposta[++contadorLetras] = '\0';
    contadorCaracteresCodigo = 0;

    //imprime ultima saida
    std::cout << resposta;
}
