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

        void setNome(string nome);

        string getNome();
};

#endif