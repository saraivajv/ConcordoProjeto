#include "../include/sistema.hpp"
#include "../include/mensagem.hpp"

using std::cin;

int main(int argc, char* argv[]){

    string linha, textotratado;
    int pos; int id = 0;
    Sistema sys;
    sys.setIdNovoUsuario(id);
    Usuario *usuarios = new Usuario[2];

    while(true){
        getline(cin, linha);

        if(linha.find("create-user ") != std::string::npos){
            int i = 0;
            bool usuarioexiste = false;
            pos = linha.find(" ");
            textotratado = linha.substr(pos+1, linha.find("\n"));

            string nome = "";

            while(textotratado.find(" ") < textotratado.find("\n") && usuarioexiste == false){

                if(i == 0){
                    string login = textotratado.substr(0, textotratado.find(" "));
                    if(sys.getUsuarios().size() != 0){
                        for(int j = 0; j < sys.getUsuarios().size(); j++){
                            if(sys.getUsuarios()[j].getEmail() == login){
                                cout << "Usuário já existe!" << std::endl;
                                usuarioexiste = true;
                                break;
                            }
                        }
                        if (usuarioexiste == true) break;
                    }
                    usuarios[sys.getIdNovoUsuario()].setEmail(login);
                }
                
                if(textotratado.find(" ") != std::string::npos && i == 1){
                    string senha = textotratado.substr(0, textotratado.find(" "));
                    usuarios[sys.getIdNovoUsuario()].setSenha(senha);
                }

                else if(textotratado.find(" ") != std::string::npos && i == 2){
                    nome += textotratado;
                }

                textotratado = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                i++;
            }

            if(usuarioexiste == false){
                usuarios[sys.getIdNovoUsuario()].setNome(nome);
                usuarios[sys.getIdNovoUsuario()].setId(sys.getIdNovoUsuario());
                cout << "Criando usuário " << usuarios[id].getNome() << " (" << usuarios[sys.getIdNovoUsuario()].getEmail()<< ")..." << std::endl;
                cout << "Usuário criado" << std::endl;

                sys.setUsuario(usuarios[sys.getIdNovoUsuario()]);
                id++;
                sys.setIdNovoUsuario(id);
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
                    for(int k = 0; k < sys.getIdNovoUsuario(); k++){
                        if(login == usuarios[k].getEmail()){
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
                    for(int k = 0; k < sys.getIdNovoUsuario(); k++){
                        if(senha == usuarios[k].getSenha()){
                            senhacorreta = true;
                            sys.setIdUsuarioLogado(k);
                            cout << "Logado como " << usuarios[k].getEmail() << std::endl;
                            sys.Logado();
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
            return 0;
        }
        
    }

    return 0;
}