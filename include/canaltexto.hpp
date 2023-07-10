#ifndef CANALTEXTO_HPP
#define CANALTEXTO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "canal.hpp"
#include "mensagem.hpp"

using std::string, std::cout;
/**
 * @brief Classe que representa um canal de texto
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
        /**
         * @brief Get the Tipo object
         * 
         * @return string 
         */
        string getTipo() override;
        /**
         * @brief Set the Mensagem object
         * 
         * @param mensagem 
         */
        void setMensagem(Mensagem mensagem);
        /**
         * @brief Get the Mensagens object
         * 
         * @return std::vector<Mensagem> 
         */
        std::vector<Mensagem> getMensagens();
};

#endif