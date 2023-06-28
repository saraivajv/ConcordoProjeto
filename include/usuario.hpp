#ifndef USUARIO_HPP
#define USUARIO_HPP 

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;
/**
 * @brief Classe que representa user
 * 
 */
class Usuario{
    private:
        int id;
        string nome;
        string email;
        string senha;
    
    public:
        /**
         * @brief Construct a new Usuario object
         * 
         */
        Usuario();
        /**
         * @brief Construct a new Usuario object
         * 
         * @param id 
         * @param nome 
         * @param email 
         * @param senha 
         */
        Usuario(int id, string nome, string email, string senha);
        /**
         * @brief Destroy the Usuario object
         * 
         */
        ~Usuario();
        /**
         * @brief Set the Id object
         * 
         * @param id 
         */
        void setId(int id);
/**
 * @brief Set the Nome object
 * 
 * @param nome 
 */
        void setNome(string nome);
/**
 * @brief Set the Email object
 * 
 * @param email 
 */
        void setEmail(string email);
/**
 * @brief Set the Senha object
 * 
 * @param senha 
 */
        void setSenha(string senha);
/**
 * @brief Get the Nome object
 * 
 * @return string 
 */
        string getNome();
/**
 * @brief Get the Email object
 * 
 * @return string 
 */
        string getEmail();
/**
 * @brief Get the Senha object
 * 
 * @return string 
 */
        string getSenha();
/**
 * @brief Get the Id object
 * 
 * @return int 
 */
        int getId();
};

#endif