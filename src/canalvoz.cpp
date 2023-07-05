#include "../include/canalvoz.hpp"


CanalVoz::CanalVoz(Mensagem ultimaMensagem){
    this->ultimaMensagem = ultimaMensagem;
};

CanalVoz::CanalVoz()
{};

CanalVoz::~CanalVoz()
{};

string CanalVoz::getTipo(){
    return "voz";
}

void CanalVoz::setUltimaMensagem(Mensagem mensagem){
    this->ultimaMensagem = mensagem;
}

Mensagem CanalVoz::getUltimaMensagem(){
    return ultimaMensagem;
}