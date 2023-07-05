#include "../include/canaltexto.hpp"


CanalTexto::CanalTexto(std::vector <Mensagem> mensagens){
    this->mensagens = mensagens;
};

CanalTexto::CanalTexto()
{};

CanalTexto::~CanalTexto()
{};

string CanalTexto::getTipo(){
    return "texto";
}

void CanalTexto::setMensagem(Mensagem mensagem){
    this->mensagens.push_back(mensagem);
}

std::vector<Mensagem> CanalTexto::getMensagens(){
    return this->mensagens;
}