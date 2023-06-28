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

/*
* @brief Classe que representa o sistema controlador do concordo.
*
*
*/
class Sistema{
    private:
        std::vector<Usuario> usuarios;
        std::vector<Servidor> servidores;
        int idUsuarioLogado;
        Servidor servidorAtual;
        Canal canalAtual;
        int idNovoUsuario;

    public:

        /**
         * @brief Construtor default de Sistema
         * 
         */
        Sistema();

        /**
         * @brief Construtor de Sistema que recebe suas variáveis.
         * 
         * @param usuarios vector de users
         * @param servidores vector de servers
         * @param idUsuarioLogado ID do user logado atualmente
         * @param servidorAtual Servidor que representa o server logado atualmente
         * @param canalAtual Canal que representa o canal logado atualmente
         */
        Sistema(std::vector<Usuario> usuarios, std::vector<Servidor> servidores, int idUsuarioLogado, Servidor servidorAtual, Canal canalAtual);

        /**
         * @brief Setter de user
         * 
         * @param usuario user recebido
         */
        void setUsuario(Usuario usuario);
        /**
         * @brief Setter de server
         * 
         * @param servidor server recebido
         */
        void setServidor(Servidor servidor);
        /**
         * @brief Setter do ID do user logado
         * 
         * @param idUsuarioLogado idusuario recebido
         */
        void setIdUsuarioLogado(int idUsuarioLogado);
        /**
         * @brief Setter do server atual
         * 
         * @param servidorAtual server recebido
         */
        void setServidorAtual(Servidor servidorAtual);
        /**
         * @brief Setter do canal atual
         * 
         * @param canalAtual canal recebido
         */
        void setCanalAtual(Canal canalAtual);
        /**
         * @brief Setter do ID de um novo user cadastrado
         * 
         * @param id id recebido
         */
        void setIdNovoUsuario(int id);
        /**
         * @brief Getter do ID do novo user
         * 
         * @return int novo ID
         */
        int getIdNovoUsuario();
        /**
         * @brief Getter do server atual
         * 
         * @return Servidor server atual
         */
        Servidor getServidorAtual();
        /**
         * @brief Getter do canal atual
         * 
         * @return Canal canal atual
         */
        Canal getCanalAtual();
        /**
         * @brief Getter do ID do user atual
         * 
         * @return int ID user atual
         */
        int getIdUsuarioLogado();
        /**
         * @brief Getter da lista de users
         * 
         * @return std::vector<Usuario> lista de users
         */
        std::vector<Usuario> getUsuarios();
        /**
         * @brief Getter da lista de servers
         * 
         * @return std::vector<Servidor> lista de servers
         */
        std::vector<Servidor> getServidores();
        /**
         * @brief interface da tela inicial
         * 
         */
        void TelaInicial();
        /**
         * @brief interface da tela apos logar
         * 
         */
        void Logado();
        /**
         * @brief Destrutor default do Sistema
         * 
         */
        ~Sistema();

};

#endif