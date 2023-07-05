#include "../include/mensagem.hpp"

Mensagem::Mensagem(string dataHora, int enviadoPor, string conteudo){
    this->dataHora = dataHora;
    this->enviadoPor = enviadoPor;
    this->conteudo = conteudo;
}

Mensagem::Mensagem()
{};

Mensagem::~Mensagem()
{};

string Mensagem::getDataHora(){
    return this->dataHora;
}

int Mensagem::getIdEnviado(){
    return this->enviadoPor;
}

string Mensagem::getConteudoMensagem(){
    return this->conteudo;
}