#include "../include/sistema.hpp"
#include "../include/mensagem.hpp"

using std::cin;

int main(int argc, char* argv[]){

    string linha;

    while(true){
        getline(cin, linha);

        if(linha.find("create-user") != std::string::npos){
            cout << "Criou um usuário!!";
        }
        
    }

    return 0;
}