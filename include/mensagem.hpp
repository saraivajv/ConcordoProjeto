#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP 

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;
/**
 * @brief Classe que representa uma mensagem enviada
 * 
 */
class Mensagem{
    private:
        string dataHora;
        int enviadoPor;
        string conteudo;
    
    public:
/**
 * @brief Construct a new Mensagem object
 * 
 */
        Mensagem();
/**
 * @brief Construct a new Mensagem object
 * 
 * @param dataHora 
 * @param enviadoPor 
 * @param conteudo 
 */
        Mensagem(string dataHora, int enviadoPor, string conteudo);
/**
 * @brief Destroy the Mensagem object
 * 
 */
        ~Mensagem();
        /**
         * @brief Get the Data Hora object
         * 
         * @return string 
         */
        string getDataHora();
        /**
         * @brief Get the Id Enviado object
         * 
         * @return int 
         */
        int getIdEnviado();
        /**
         * @brief Get the Conteudo Mensagem object
         * 
         * @return string 
         */
        string getConteudoMensagem();
};

#endif