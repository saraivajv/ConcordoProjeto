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