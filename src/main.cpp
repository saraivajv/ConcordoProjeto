#include "../include/sistema.hpp"
#include "../include/mensagem.hpp"

using std::cin;

int main(int argc, char* argv[]){

    string linha;

    while(true){
        getline(cin, linha);

        if(linha.find("create-user ") != std::string::npos){
            cout << "Criou um usuário!!";
        }

        if(linha.find("login ") != std::string::npos){
            cout << "Logado como ...";
        }

        if(linha.find("quit ") != std::string::npos){
            cout << "Saindo...";
            return 0;
        }
        
    }

    return 0;
}