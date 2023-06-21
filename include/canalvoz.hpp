#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <iostream>
#include <string>
#include <vector>
#include "canal.hpp"
#include "mensagem.hpp"

using std::string, std::cout;

class CanalVoz : public Canal
{
    private:
        Mensagem ultimaMensagem;
    
    public:

        CanalVoz();

        CanalVoz(Mensagem ultimaMensagem);

        ~CanalVoz();
};

#endif