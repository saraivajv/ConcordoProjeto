#ifndef CANAL_HPP
#define CANAL_HPP

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;
/**
 * @brief Classe que representa canal
 * 
 */
class Canal{
    private:
        string nome;
    
    public:
/**
 * @brief Construct a new Canal object
 * 
 */
        Canal();
/**
 * @brief Construct a new Canal object
 * 
 * @param nome 
 */
        Canal(string nome);
/**
 * @brief Destroy the Canal object
 * 
 */
        ~Canal();
        /**
         * @brief Set the Nome object
         * 
         * @param nome 
         */
        void setNome(string nome);
        /**
         * @brief Get the Nome object
         * 
         * @return string 
         */
        string getNome();
        /**
         * @brief Get the Tipo object
         * 
         * @return string 
         */
        virtual string getTipo();
};

#endif