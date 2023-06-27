#include "../include/servidor.hpp"

Servidor::Servidor(int usuarioDonoId, string nome, string descricao, string codigoConvite, std::vector<Canal*> canais, std::vector<int> participantesIDs){
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
    this->descricao = descricao;
    this->codigoConvite = codigoConvite;
    this->canais = canais;
    this->participantesIDs = participantesIDs;
};

Servidor::Servidor()
{};

Servidor::~Servidor()
{};

void Servidor::setNome(string nome){
    this->nome = nome;
}

void Servidor::setDonoId(int usuarioDonoId){
    this->usuarioDonoId = usuarioDonoId;
}

void Servidor::setDescricao(string descricao){
    this->descricao = descricao;
}

void Servidor::setCodigoConvite(string codigoConvite){
    this->codigoConvite = codigoConvite;
}

void Servidor::setCanal(Canal *canal){
    this->canais.push_back(canal);
}

void Servidor::setParticipantesId(int participanteId){
    this->participantesIDs.push_back(participanteId);
}

string Servidor::getNome(){
    return this->nome;
}

string Servidor::getDescricao(){
    return this->descricao;
}

int Servidor::getDonoId(){
    return this->usuarioDonoId;
}

std::vector<int> Servidor::getParticipantesId(){
    return this->participantesIDs;
}

string Servidor::getCodigoConvite(){
    return this->codigoConvite;
}

std::vector<Canal*> Servidor::getCanais(){
    return this->canais;
}