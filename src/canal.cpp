#include "../include/canal.hpp"


Canal::Canal(string nome){
    this->nome = nome;
};

Canal::Canal(){};

Canal::~Canal(){};

void Canal::setNome(string nome){
    this->nome = nome;
}

string Canal::getNome(){
    return this->nome;
}