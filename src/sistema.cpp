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

void Sistema::TelaInicial(){
    string linha, textotratado;
    int pos; int id = 0;
    this->setIdNovoUsuario(id);
    Usuario usuario;

    while(true){
        getline(std::cin, linha);

        if(linha.find("create-user ") != std::string::npos){
            int i = 0;
            bool usuarioexiste = false;
            pos = linha.find(" ");
            textotratado = linha.substr(pos+1, linha.find("\n"));

            string nome = "";

            while(textotratado.find(" ") < textotratado.find("\n") && usuarioexiste == false){

                if(i == 0){
                    string login = textotratado.substr(0, textotratado.find(" "));
                    if(this->getUsuarios().size() != 0){
                        for(int j = 0; j < this->getUsuarios().size(); j++){
                            if(this->getUsuarios()[j].getEmail() == login){
                                cout << "Usuário já existe!" << std::endl;
                                usuarioexiste = true;
                                break;
                            }
                        }
                        if (usuarioexiste == true) break;
                    }
                    usuario.setEmail(login);
                }
                
                if(textotratado.find(" ") != std::string::npos && i == 1){
                    string senha = textotratado.substr(0, textotratado.find(" "));
                    usuario.setSenha(senha);
                }

                else if(textotratado.find(" ") != std::string::npos && i == 2){
                    nome += textotratado;
                }

                textotratado = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                i++;
            }

            if(usuarioexiste == false){
                usuario.setNome(nome);
                usuario.setId(this->getIdNovoUsuario());
                cout << "Criando usuário " << usuario.getNome() << " (" << usuario.getEmail()<< ")..." << std::endl;
                cout << "Usuário criado" << std::endl;

                this->setUsuario(usuario);
                id++;
                this->setIdNovoUsuario(id);
            }
        }

        if(linha.find("login ") != std::string::npos){
            pos = linha.find(" ");
            textotratado = linha.substr(pos+1, linha.find("\n"));
            int i = 0;
            bool logincorreto, senhacorreta;

            while(textotratado.find(" ") < textotratado.find("\n")){
                if(i == 0){
                    string login = textotratado.substr(0, textotratado.find(" "));
                    for(int k = 0; k < this->getIdNovoUsuario(); k++){
                        if(login == this->getUsuarios()[i].getEmail()){
                            logincorreto = true;
                            break;
                        }
                    }
                    if(logincorreto == false){
                        cout << "Login ou senha incorretos" << std::endl;
                        break;
                    }
                }
                
                if(i == 1){
                    textotratado = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                    string senha = textotratado;
                    for(int k = 0; k < this->getIdNovoUsuario(); k++){
                        if(senha == this->getUsuarios()[k].getSenha()){
                            senhacorreta = true;
                            this->setIdUsuarioLogado(k);
                            cout << "Logado como " << this->getUsuarios()[k].getEmail() << std::endl;
                            this->Logado();
                            break;
                        }
                    }
                    if(senhacorreta == false){
                        cout << "Login ou senha incorretos" << std::endl;
                        break;
                    }
                }
                i++;
            }
        }

        if(linha.find("quit") != std::string::npos){
            cout << "Saindo..." << std::endl;
            return;
        }
        
    }
}

void Sistema::Logado(){
    string linha, textotratado;
    Servidor novoservidor;

    while(true){
        getline(std::cin, linha);

        if(linha.find("disconnect") != std::string::npos){
            cout << "Desconectando usuário " << usuarios[this->getIdUsuarioLogado()].getEmail() << std::endl;
            this->setIdUsuarioLogado(-1);
            break;
        }

        if(linha.find("create-server ") != std::string::npos){
            bool servidorexiste = false;
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
                Servidor novoservidor;
                string nomeserver;
                nomeserver = textotratado;
                novoservidor.setNome(nomeserver);
                novoservidor.setDonoId(this->getIdUsuarioLogado());
                novoservidor.setParticipantesId(novoservidor.getDonoId());
                this->setServidor(novoservidor);
                this->setServidorAtual(novoservidor);
                cout << "Servidor criado" << std::endl;
            }
        }

        if(linha.find("set-server-desc ") != std::string::npos){
            int pos = linha.find(" ");

            textotratado = linha.substr(pos+1, linha.find("\n"));

            while(textotratado.find(" ") < textotratado.find("\n")){
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
                            if(this->getServidores()[i].getDonoId() != this->getIdUsuarioLogado() && existe == true){
                                cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << std::endl;
                                break;
                            }
                        }
                    }
                    if(existe == false) cout << "Servidor " << server << " não existe" << std::endl;
                    break;
                }
            }
        }

        if(linha.find("set-server-invite-code ") != std::string::npos){
            int pos = linha.find(" ");
            string codigoconvite;

            textotratado = linha.substr(pos+1, linha.find("\n"));

            while(true){
                if(textotratado.find(" ") == std::string::npos){
                    codigoconvite = "";
                    string server = textotratado.substr(0, textotratado.find("\n"));
                    for(int i = 0; i < this->getServidores().size(); i++){
                        if(this->getServidores()[i].getNome() == server){
                            if(this->getServidores()[i].getDonoId() == this->getIdUsuarioLogado()){
                                this->getServidores()[i].setCodigoConvite(codigoconvite);
                                cout << "Código de convite do servidor " << this->getServidores()[i].getNome() << " removido!" << std::endl;
                                break;
                            }
                        }
                    }
                    break;
                }
                else if(textotratado.find(" ") != std::string::npos){
                    string server = textotratado.substr(0, textotratado.find(" "));
                    textotratado = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                    Servidor servidorAnalisado;
                    for(int i = 0; i < this->getServidores().size(); i++){
                        servidorAnalisado = getServidores()[i];
                        if(servidorAnalisado.getNome() == server){
                            if(servidorAnalisado.getDonoId() == this->getIdUsuarioLogado()){
                                codigoconvite = textotratado;
                                servidorAnalisado.setCodigoConvite(codigoconvite);
                                cout << servidorAnalisado.getCodigoConvite() << std::endl;
                                cout << "Código de convite do servidor " << servidorAnalisado.getNome() << " modificado!" << std::endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            }

        }
        
        if(linha.find("list-servers") != std::string::npos){
            cout << getServidores().size() << std::endl;
            for(int i = 0; i < getServidores().size(); i++){
                cout << getServidores()[i].getNome() << std::endl;
            }
        }

        if(linha.find("remove-server ") != std::string::npos){
            int pos = linha.find(" ");
            bool operacaoconcluida = false;
            bool serverexiste = false;

            textotratado = linha.substr(pos+1, linha.find("\n"));

            while(true){
                string server = textotratado.substr(0, textotratado.find("\n"));
                // std::vector<Servidor> servidoresaux = getServidores();
                for(int i = 0; i < servidores.size(); i++){
                    if(servidores[i].getNome() == server && servidores[i].getDonoId() == getIdUsuarioLogado()){
                        Servidor servidorauxiliar;
                        servidorauxiliar = servidores[servidores.size()-1];
                        servidores[servidores.size()-1] = servidores[i];
                        servidores[i] = servidorauxiliar;
                        cout << "Servidor " << servidores[servidores.size()-1].getNome() << " removido" << std::endl;
                        servidores.pop_back();
                        operacaoconcluida = true;
                       
                        break;
                    }
                }
                if(operacaoconcluida == true) break;

                for(int i = 0; i < servidores.size(); i++){
                    if(servidores[i].getNome() == server && servidores[i].getDonoId() != this->getIdUsuarioLogado()){
                        cout << "Você não é o dono do servidor " << servidores[i].getNome() << std::endl;
                        operacaoconcluida = true;
                        break;
                    }
                }
                if(operacaoconcluida == true) break;
                
                cout << "Servidor " << server << " não encontrado" << std::endl;
                operacaoconcluida = true;
                if(operacaoconcluida == true) break;
            }
        }

        if(linha.find("enter-server ") != std::string::npos){
            int pos = linha.find(" ");
            string server;
            string codigoconvite;
            textotratado = linha.substr(pos+1, linha.find("\n"));
            if(textotratado.find(" ") == std::string::npos){
                server = textotratado;
            }
            else if(textotratado.find(" ") != std::string::npos){
                server = textotratado.substr(0, textotratado.find(" "));
                codigoconvite = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                cout << codigoconvite << std::endl;
            }
            

            for(int i = 0; i < this->getServidores().size(); i++){
                if(server == this->getServidores()[i].getNome()){
                    if(this->getServidores()[i].getDonoId() == this->getIdUsuarioLogado()){
                        cout << "Entrou no servidor com sucesso" << std::endl;
                        Servidor svaux = this->getServidores()[i];
                        this->setServidorAtual(svaux);
                        break;
                    }
                    else if(this->getServidores()[i].getDonoId() != this->getIdUsuarioLogado() && this->getServidores()[i].getCodigoConvite() == codigoconvite){
                        cout << "Entrou no servidor com sucesso" << std::endl;
                        Servidor svaux = this->getServidores()[i];
                        svaux.setParticipantesId(this->getIdUsuarioLogado());
                        this->setServidorAtual(svaux);
                        break;
                    }
                }
                else if(this->getServidores()[i].getCodigoConvite() != codigoconvite && this->getServidores()[i].getDonoId() != this->getIdUsuarioLogado()){
                    cout << "Servidor requer código de convite" << std::endl;
                    break;
                }
            }
        }

        if(linha.find("leave-server") != std::string::npos){
            Servidor nulo;
            if(this->getServidorAtual().getNome() != ""){
                this->setServidorAtual(nulo);
                cout << "Saindo do servidor " << this->getServidorAtual().getNome() << std::endl;
            }
            else if(this->getServidorAtual().getNome() == ""){
                cout << "Você não está visualizando nenhum servidor" << std::endl;
            }
        }

        if(linha.find("list-participants") != std::string::npos){
            std::vector<Usuario> ususist = this->getUsuarios();
            std::vector<int> idserv = this->getServidorAtual().getParticipantesId();
            string nome;
            bool found = false;
            cout << this->getServidorAtual().getNome() << std::endl;

            for(int i = 0; i < idserv.size(); i++){
                cout << this->getServidorAtual().getParticipantesId()[i] << std::endl;
                for(int j = 0; j < ususist.size(); j++){
                    if(idserv[i] == ususist[j].getId()){
                        nome = ususist[j].getNome();
                        cout << nome << std::endl;
                        found = true;
                        break;
                    }
                }
                if(found == true && idserv.size() == 1){
                    break;
                }
            }
        }
        

    }



}
