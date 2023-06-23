#include "../include/sistema.hpp"
#include "../include/mensagem.hpp"

using std::cin;

int main(int argc, char* argv[]){

    string linha, textotratado;
    int pos; int i = 0;

    while(true){
        getline(cin, linha);

        if(linha.find("create-user ") != std::string::npos){

            pos = linha.find(" ");
            textotratado = linha.substr(pos+1, linha.find("\n"));

            while(textotratado.find(" ") < textotratado.find("\n")){

                if(i == 0){
                    string login = textotratado.substr(0, linha.find(" "));
                    cout << login << std::endl;
                }
                
                if(textotratado.find(" ") != std::string::npos && i != 0){
                    string senha = textotratado.substr(0, textotratado.find(" "));
                    cout << senha << std::endl;
                }

                textotratado = textotratado.substr(textotratado.find(" ")+1, textotratado.find("\n"));
                i++;
            }

            string nome = textotratado;
            cout << nome << std::endl;
        
            // cout << "Criou um usuário!!" << std::endl;
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