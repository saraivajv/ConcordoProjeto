#ifndef CANAL_HPP
#define CANAL_HPP

#include <iostream>
#include <string>
#include <vector>

using std::string, std::cout;

class Canal{
    private:
        string nome;
    
    public:

        Canal();

        Canal(string nome);

        ~Canal();
};

#endif