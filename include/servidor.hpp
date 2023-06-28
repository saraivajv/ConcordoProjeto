#ifndef SERVIDOR_HPP
#define SERVIDOR_HPP

#include <iostream>
#include <string>
#include <vector>
#include "canal.hpp"
#include "mensagem.hpp"

using std::string, std::cout;
/**
 * @brief Classe que representa um server
 * 
 */
class Servidor{
    private:
        int usuarioDonoId;
        string nome;
        string descricao;
        string codigoConvite;
        std::vector<Canal*> canais;
        std::vector<int> participantesIDs;

    public:
        /**
         * @brief Construct a new Servidor object
         * 
         */
        Servidor();
        /**
         * @brief Construct a new Servidor object
         * 
         * @param usuarioDonoId 
         * @param nome 
         * @param descricao 
         * @param codigoConvite 
         * @param canais 
         * @param participantesIDs 
         */
        Servidor(int usuarioDonoId, string nome, string descricao, string codigoConvite, std::vector<Canal*> canais, std::vector<int> participantesIDs);

        ~Servidor();
        /**
         * @brief Set the Nome object
         * 
         * @param nome 
         */
        void setNome(string nome);
        /**
         * @brief Set the Dono Id object
         * 
         * @param usuarioDonoId 
         */
        void setDonoId(int usuarioDonoId);
        /**
         * @brief Set the Descricao object
         * 
         * @param descricao 
         */
        void setDescricao(string descricao);
        /**
         * @brief Set the Codigo Convite object
         * 
         * @param codigoConvite 
         */
        void setCodigoConvite(string codigoConvite);
        /**
         * @brief Set the Canal object
         * 
         * @param canal 
         */
        void setCanal(Canal* canal);
        /**
         * @brief Set the Participantes Id object
         * 
         * @param participanteId 
         */
        void setParticipantesId(int participanteId);
        /**
         * @brief Get the Dono Id object
         * 
         * @return int 
         */
        int getDonoId();
        /**
         * @brief Get the Nome object
         * 
         * @return string 
         */
        string getNome();
        /**
         * @brief Get the Descricao object
         * 
         * @return string 
         */
        string getDescricao();
        /**
         * @brief Get the Codigo Convite object
         * 
         * @return string 
         */
        string getCodigoConvite();
        /**
         * @brief Get the Canais object
         * 
         * @return std::vector<Canal*> 
         */
        std::vector<Canal*> getCanais();
        /**
         * @brief Get the Participantes Id object
         * 
         * @return std::vector<int> 
         */
        std::vector<int> getParticipantesId();

};

#endif