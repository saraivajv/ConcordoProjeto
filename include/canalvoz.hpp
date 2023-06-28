#ifndef CANALVOZ_HPP
#define CANALVOZ_HPP

#include <iostream>
#include <string>
#include <vector>
#include "canal.hpp"
#include "mensagem.hpp"

using std::string, std::cout;
/**
 * @brief 
 * 
 */
class CanalVoz : public Canal
{
    private:
        Mensagem ultimaMensagem;
    
    public:
/**
 * @brief Construct a new Canal Voz object
 * 
 */
        CanalVoz();
/**
 * @brief Construct a new Canal Voz object
 * 
 * @param ultimaMensagem 
 */
        CanalVoz(Mensagem ultimaMensagem);
/**
 * @brief Destroy the Canal Voz object
 * 
 */
        ~CanalVoz();
};

#endif