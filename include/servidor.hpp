#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include "canal.hpp"
#include "mensagem.hpp"

using std::string, std::cout;

class Servidor{
    private:
        int usuarioDonoId;
        string nome;
        string descricao;
        string codigoConvite;
        std::vector<Canal*> canais;
        std::vector<int> participantesIDs;

    public:

        Servidor();

        Servidor(int usuarioDonoId, string nome, string descricao, string codigoConvite, std::vector<Canal*> canais, std::vector<int> participantesIDs);

        ~Servidor();

        void setNome(string nome);

        void setDonoId(int usuarioDonoId);

        void setDescricao(string descricao);

        void setCodigoConvite(string codigoConvite);

        void setCanal(Canal* canal);

        void setParticipantesId(int participanteId);

        int getDonoId();

        string getNome();

        string getDescricao();

        string getCodigoConvite();

        std::vector<Canal*> getCanais();

        std::vector<int> getParticipantesId();

};

#endif