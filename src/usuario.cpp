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