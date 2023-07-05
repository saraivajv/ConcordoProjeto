#include "../include/sistema.hpp"
#include <ctime>
#include <sstream>


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

/**
 * @brief Função auxiliar que converte int em string
 * 
 * @param value valor passado
 * @return char 
 */
char IntToChar(int value) {
    if (value < 0 || value > 9) {
        return '0';
    }

    return (char)(value + 48);
}

/**
 * @brief Função auxiliar que converte int em string
 * 
 * @param value valor passado
 * @return char 
 */
std::string IntToString(int value) {
    std::string buffer = std::string();

    std::vector<int> splitValue;

    while (true) {

        splitValue.insert(splitValue.begin(), value % 10);

        value /= 10;

        if (value == 0)
            break;
    }

    for (int i = 0; i < splitValue.size(); i++) {

        buffer += IntToChar(splitValue[i]);
    }

    splitValue.clear();

    return buffer;
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
    time_t horaatual = time(0);

        tm* datahora = localtime(&horaatual);
        string dia = IntToString(datahora->tm_mday);
        string mes = IntToString(1 + datahora->tm_mon);
        string ano = IntToString(1900 + datahora->tm_year);
        string hora = IntToString(datahora->tm_hour);
        string minuto = IntToString(datahora->tm_min);

    while(true){
        getline(std::cin, linha);

        if(getServidorAtual().getNome() != "nulo"){

            if(canalAtual.getNome().empty() == true){
                Canal nulo;
                nulo.setNome("nulo");
                canalAtual = nulo;
            }

            if(linha.find("create-channel ") != std::string::npos){
                string tipo;
                bool canalexiste = false;
                int pos = linha.find(" ");
                textotratado = linha.substr(pos+1, linha.find("\n"));
                string nomecanal = textotratado.substr(0, textotratado.find(" "));
                string tipocanal = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));

                    for(int i = 0; i < servidorAtual.getCanais().size(); i++){
                        tipo = servidorAtual.getCanais()[i]->getTipo();
                        if(servidorAtual.getCanais()[i]->getNome() == nomecanal && tipo == tipocanal){
                            cout << "Canal de " << tipo << " " << nomecanal << " já existe!" << std::endl;
                            canalexiste = true;
                            break;
                        }
                    }
                

                if(tipocanal == "texto" && canalexiste == false){
                    CanalTexto *tchannel = new CanalTexto();
                    tchannel->setNome(nomecanal);
                    servidorAtual.setCanal(tchannel);
                    cout << "Canal de texto " << nomecanal << " criado" << std::endl;
                    // delete tchannel;
                }
                if(tipocanal == "voz" && canalexiste == false){
                    CanalVoz *vchannel = new CanalVoz();
                    vchannel->setNome(nomecanal);
                    servidorAtual.setCanal(vchannel);
                    cout << "Canal de voz " << nomecanal << " criado" << std::endl;
                    // delete vchannel;
                }
            }

            if(linha.find("list-channels") != std::string::npos){
                cout << "#canais de texto" << std::endl;
                for(int i = 0; i < servidorAtual.getCanais().size(); i++){
                    if(servidorAtual.getCanais()[i]->getTipo() == "texto"){
                        cout << servidorAtual.getCanais()[i]->getNome() << std::endl;
                    }
                }
                cout << "#canais de voz" << std::endl;
                for(int i = 0; i < servidorAtual.getCanais().size(); i++){
                    if(servidorAtual.getCanais()[i]->getTipo() == "voz"){
                        cout << servidorAtual.getCanais()[i]->getNome() << std::endl;
                    }
                }

            }

            if(linha.find("enter-channel ") != std::string::npos){
                int pos = linha.find(" ");
                string nomecanal = linha.substr(pos+1, linha.find("\n"));

                for(int i = 0; i < servidorAtual.getCanais().size(); i++){
                    if(nomecanal == servidorAtual.getCanais()[i]->getNome()){
                        cout << "Entrou no canal " << servidorAtual.getCanais()[i]->getNome() << std::endl;
                        if(servidorAtual.getCanais()[i]->getTipo() == "texto"){
                            CanalTexto *tchannel = dynamic_cast<CanalTexto*>(this->servidorAtual.getCanais()[i]);
                            setCanalAtual(*tchannel);
                            this->servidorAtual.getCanais()[i] = tchannel;
                            // delete tchannel;
                            break;
                        }
                        else if(servidorAtual.getCanais()[i]->getTipo() == "voz"){
                            CanalVoz *vchannel = dynamic_cast<CanalVoz*>(this->servidorAtual.getCanais()[i]);
                            setCanalAtual(*vchannel);
                            this->servidorAtual.getCanais()[i] = vchannel;
                            // delete vchannel;
                            break;
                        }
                    }
                    else if(i+1 == servidorAtual.getCanais().size()){
                        cout << "Canal " << nomecanal << " não existe" << std::endl;
                        break;
                    }
                }
            }

            if(linha.find("leave-channel") != std::string::npos){
                Canal nulo;
                setCanalAtual(nulo);
                cout << "Saindo do canal" << std::endl;
            }

            if(canalAtual.getNome() != "nulo"){
                for(int i = 0; i < this->getServidorAtual().getCanais().size(); i++){
                    if(linha.find("send-message ") != std::string::npos){
                        string msg = linha.substr(linha.find(" ")+1, linha.find("\n"));
                        string horario = dia + "/" + mes + "/" + ano + " - " + hora + ":" + minuto;

                        if(this->getServidorAtual().getCanais()[i]->getTipo() == "texto" && canalAtual.getNome() == this->getServidorAtual().getCanais()[i]->getNome()){
                            Mensagem m = Mensagem(horario, idUsuarioLogado, msg);
                            CanalTexto *tchannel = dynamic_cast<CanalTexto*>(this->getServidorAtual().getCanais()[i]);
                            tchannel->setMensagem(m);
                            this->getServidorAtual().getCanais()[i] = tchannel;
                            break;
                        }
                        else if(this->getServidorAtual().getCanais()[i]->getTipo() == "voz" && canalAtual.getNome() == this->getServidorAtual().getCanais()[i]->getNome()){
                            Mensagem m = Mensagem(horario, idUsuarioLogado, msg);
                            CanalVoz *vchannel = dynamic_cast<CanalVoz*>(this->getServidorAtual().getCanais()[i]);
                            vchannel->setUltimaMensagem(m);
                            this->getServidorAtual().getCanais()[i] = vchannel;
                            break;
                        }
                    }

                }

                if(linha.find("list-messages") != std::string::npos){
                    for(int i = 0; i < this->getServidorAtual().getCanais().size(); i++){
                        if(this->getServidorAtual().getCanais()[i]->getTipo() == "texto" && canalAtual.getNome() == this->getServidorAtual().getCanais()[i]->getNome()){
                            string nomeusuario;
                            CanalTexto *tchannel = dynamic_cast<CanalTexto*>(this->getServidorAtual().getCanais()[i]);
                            cout << tchannel->getNome() << std::endl;
                            for(int j = 0; j < tchannel->getMensagens().size(); j++){
                                int idcheck = tchannel->getMensagens()[j].getIdEnviado();

                                for(int k = 0; k < usuarios.size(); k++){
                                    if(idcheck == usuarios[k].getId()){
                                        nomeusuario = usuarios[k].getNome();
                                        break;
                                    }
                                }
                                cout << nomeusuario << "<" << tchannel->getMensagens()[j].getDataHora() << ">: " << tchannel->getMensagens()[j].getConteudoMensagem() << std::endl;
                            }
                        }
                        else if(this->getServidorAtual().getCanais()[i]->getTipo() == "voz" && canalAtual.getNome() == this->getServidorAtual().getCanais()[i]->getNome()){
                            string nomeusuario;
                            CanalVoz *vchannel = dynamic_cast<CanalVoz*>(this->getServidorAtual().getCanais()[i]);
                            cout << vchannel->getNome() << std::endl;
                                int idcheck = vchannel->getUltimaMensagem().getIdEnviado();
                                for(int k = 0; k < usuarios.size(); k++){
                                    if(idcheck == usuarios[k].getId()){
                                        nomeusuario = usuarios[k].getNome();
                                        break;
                                    }
                                }
                                cout << nomeusuario << "<" << vchannel->getUltimaMensagem().getDataHora() << ">: " << vchannel->getUltimaMensagem().getConteudoMensagem() << std::endl;
                        }
                    }
                        


                }
            }


        }

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
                nulo.setNome("nulo");
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
