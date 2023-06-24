#include "../include/usuario.hpp"

Usuario::Usuario(int id, string nome, string email, string senha){
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

Usuario::Usuario()
{};

Usuario::~Usuario()
{};

void Usuario::setId(int id){
    this->id = id;
};

void Usuario::setNome(string nome){
    this->nome = nome;
};

void Usuario::setEmail(string email){
    this->email = email;
};

void Usuario::setSenha(string senha){
    this->senha = senha;
};