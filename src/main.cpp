#include "../include/sistema.hpp"
#include "../include/mensagem.hpp"

using std::cin;

int main(int argc, char* argv[]){

    string linha, textotratado;
    int pos; int i = 0; int id = 0;
    Sistema sys;
    Usuario *usuarios = new Usuario();

    while(true){
        getline(cin, linha);

        if(linha.find("create-user ") != std::string::npos){
            string nome = "";

            pos = linha.find(" ");
            textotratado = linha.substr(pos+1, linha.find("\n"));

            while(textotratado.find(" ") < textotratado.find("\n")){

                if(i == 0){
                    string login = textotratado.substr(0, textotratado.find(" "));
                    cout << login << std::endl;
                    usuarios[id].setEmail(login);
                }
                
                if(textotratado.find(" ") != std::string::npos && i == 1){
                    string senha = textotratado.substr(0, textotratado.find(" "));
                    cout << senha << std::endl;
                    usuarios[id].setSenha(senha);
                }

                else if(textotratado.find(" ") != std::string::npos && i > 1){
                    nome += textotratado;
                }

                textotratado = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                i++;
            }

            usuarios[id].setNome(nome);
            cout << nome << std::endl;
        
            // cout << "Criou um usuário!!" << std::endl;

            id++;
        }

        if(linha.find("login ") != std::string::npos){
            cout << "Logado como ...";
        }

        if(linha.find("quit") != std::string::npos){
            cout << "Saindo..." << std::endl;
            return 0;
        }
        
    }

    return 0;
}