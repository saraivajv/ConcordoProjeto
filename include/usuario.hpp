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
};

#endif