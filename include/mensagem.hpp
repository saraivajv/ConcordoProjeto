#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP 

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;

class Mensagem{
    private:
        string dataHora;
        int enviadoPor;
        string conteudo;
    
    public:

        Mensagem();

        Mensagem(string dataHora, int enviadoPor, string conteudo);

        ~Mensagem();
};

#endif