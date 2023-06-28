#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

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
class CanalTexto : public Canal
{
    private:
        std::vector <Mensagem> mensagens;
    
    public:
/**
 * @brief Construct a new Canal Texto object
 * 
 */
        CanalTexto();
/**
 * @brief Construct a new Canal Texto object
 * 
 * @param mensagens 
 */
        CanalTexto(std::vector <Mensagem> mensagens);
/**
 * @brief Destroy the Canal Texto object
 * 
 */
        ~CanalTexto();
};

#endif