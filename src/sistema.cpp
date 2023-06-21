#include "../include/sistema.hpp"


Sistema::Sistema(std::vector<Usuario> usuarios, std::vector<Servidor> servidores, int idUsuarioLogado, Servidor servidorAtual, Canal canalAtual){
    this->usuarios = usuarios;
    this->servidores = servidores;
    this->idUsuarioLogado = idUsuarioLogado;
    this->servidorAtual = servidorAtual;
    this->canalAtual = canalAtual;
};