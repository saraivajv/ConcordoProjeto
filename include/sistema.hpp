#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "servidor.hpp"
#include "canalvoz.hpp"
#include "canaltexto.hpp"

using std::string, std::cout;

class Sistema{
    private:
        std::vector<Usuario> usuarios;
        std::vector<Servidor> servidores;
        int idUsuarioLogado;
        Servidor servidorAtual;
        Canal canalAtual;
        int idNovoUsuario;

    public:

        Sistema();

        Sistema(std::vector<Usuario> usuarios, std::vector<Servidor> servidores, int idUsuarioLogado, Servidor servidorAtual, Canal canalAtual);

        ~Sistema();

};

#endif