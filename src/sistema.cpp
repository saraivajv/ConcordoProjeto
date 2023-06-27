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
    Servidor novoservidor;
    bool servidorexiste = false;

    while(true){
        getline(std::cin, linha);

        if(linha.find("disconnect") != std::string::npos){
            cout << "Desconectando usuário " << usuarios[this->getIdUsuarioLogado()].getEmail() << std::endl;
            this->setIdUsuarioLogado(-1);
            break;
        }

        if(linha.find("create-server ") != std::string::npos){
            int pos = linha.find(" ");
            textotratado = linha.substr(pos+1, linha.find("\n"));

            for(int i = 0; i < this->servidores.size(); i++){
                if(textotratado == this->servidores[i].getNome()){
                    cout << "Servidor com esse nome já existe" << std::endl;
                    servidorexiste = true;
                    break;
                }
            }

            if(servidorexiste == false){
                string nomeserver;
                nomeserver = textotratado;
                novoservidor.setNome(nomeserver);
                novoservidor.setDonoId(this->getIdUsuarioLogado());
                this->setServidor(novoservidor);
                this->setServidorAtual(novoservidor);
                cout << "Servidor criado" << std::endl;
            }
        }

        if(linha.find("set-server-desc ") != std::string::npos){
            int i = 0;
            bool descricaoexiste = false;
            int pos = linha.find(" ");

            textotratado = linha.substr(pos+1, linha.find("\n"));

            while(textotratado.find(" ") < textotratado.find("\n") && descricaoexiste == false){
                string server = textotratado.substr(0, textotratado.find(" "));
                textotratado = textotratado.substr(textotratado.find(" "), textotratado.find("\n"));
                if(server == this->getServidorAtual().getNome()){
                    if(this->getServidorAtual().getDonoId() == this->getIdUsuarioLogado()){
                        string descricao = textotratado;
                        this->getServidorAtual().setDescricao(descricao);
                        cout << "Descrição do servidor " << this->getServidorAtual().getNome() << " modificada!" << std::endl;
                        break;
                    }
                }
                if(server != this->getServidorAtual().getNome()){
                    bool existe = false;
                    for (int i = 0; i < this->getServidores().size(); i++){
                        if(server == this->getServidores()[i].getNome()){
                            existe = true;
                            if(this->getServidores()[i].getDonoId() != this->getIdUsuarioLogado()){
                                cout << "“Você não pode alterar a descrição de um servidor que não foi criado por você" << std::endl;
                                break;
                            }
                        }
                    }
                    cout << "Servidor " << server << " não existe" << std::endl;
                    break;
                }
            }
        }


    }



}
