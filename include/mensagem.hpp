#ifndef MENSAGEM_HPP
#define MENSAGEM_HPP 

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;
/**
 * @brief 
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

        string getDataHora();

        int getIdEnviado();

        string getConteudoMensagem();
};

#endif