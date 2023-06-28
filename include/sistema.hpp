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

        void setUsuario(Usuario usuario);
        
        void setServidor(Servidor servidor);

        void setIdUsuarioLogado(int idUsuarioLogado);

        void setServidorAtual(Servidor servidorAtual);

        void setCanalAtual(Canal canalAtual);

        void setIdNovoUsuario(int id);

        int getIdNovoUsuario();

        Servidor getServidorAtual();

        Canal getCanalAtual();

        int getIdUsuarioLogado();

        std::vector<Usuario> getUsuarios();
        
        std::vector<Servidor> getServidores();

        void TelaInicial();

        void Logado();

        ~Sistema();

};

#endif