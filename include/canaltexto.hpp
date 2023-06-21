#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "canal.hpp"
#include "mensagem.hpp"

using std::string, std::cout;

class CanalTexto : public Canal
{
    private:
        std::vector <Mensagem> mensagens;
    
    public:

        CanalTexto();

        CanalTexto(std::vector <Mensagem> mensagens);

        ~CanalTexto();
};

#endif