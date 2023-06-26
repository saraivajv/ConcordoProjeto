#ifndef USUARIO_HPP
#define USUARIO_HPP 

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;

class Usuario{
    private:
        int id;
        string nome;
        string email;
        string senha;
    
    public:

        Usuario();

        Usuario(int id, string nome, string email, string senha);

        ~Usuario();

        void setId(int id);

        void setNome(string nome);

        void setEmail(string email);

        void setSenha(string senha);

        string getNome();

        string getEmail();

        string getSenha();

        int getId();
};

#endif