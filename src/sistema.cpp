#include "../include/sistema.hpp"


Sistema::Sistema(std::vector<Usuario> usuarios, std::vector<Servidor> servidores, int idUsuarioLogado, Servidor servidorAtual, Canal canalAtual){
    this->usuarios = usuarios;
    this->servidores = servidores;
    this->idUsuarioLogado = idUsuarioLogado;
    this->servidorAtual = servidorAtual;
    this->canalAtual = canalAtual;
};

Sistema::Sistema()
{};

Sistema::~Sistema()
{};

void Sistema::setUsuario(Usuario usuario){
    this->usuarios.push_back(usuario);
}

void Sistema::setServidor(Servidor servidor){
    this->servidores.push_back(servidor);
}

void Sistema::setCanalAtual(Canal canalatual){
    this->canalAtual = canalatual;
}

void Sistema::setServidorAtual(Servidor servidoratual){
    this->servidorAtual = servidoratual;
}

void Sistema::setIdUsuarioLogado(int idLogado){
    this->idUsuarioLogado = idLogado;
}

void Sistema::setIdNovoUsuario(int id){
    this->idNovoUsuario = id;
}

int Sistema::getIdNovoUsuario(){
    return this->idNovoUsuario;
}

int Sistema::getIdUsuarioLogado(){
    return this->idUsuarioLogado;
}

Canal Sistema::getCanalAtual(){
    return this->canalAtual;
}

Servidor Sistema::getServidorAtual(){
    return this->servidorAtual;
}

std::vector<Usuario> Sistema::getUsuarios(){
    return this->usuarios;
}

std::vector<Servidor> Sistema::getServidores(){
    return this->servidores;
}

void Sistema::Logado(){
    string linha, textotratado;
    getline(std::cin, linha);

    while(true){

        if(linha.find("disconnect") != std::string::npos){
            cout << "Desconectando usuário " << usuarios[this->getIdUsuarioLogado()].getEmail() << std::endl;
            this->setIdUsuarioLogado(-1);
            break;
        }
    }



}
