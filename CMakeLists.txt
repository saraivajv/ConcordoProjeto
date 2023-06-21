cmake_minimum_required(VERSION 3.13)
project(concordo)

set(CMAKE_CXX_STANDARD 20)

add_executable(concordo 
            src/main.cpp 
            src/canal.cpp 
            src/canaltexto.cpp 
            src/canalvoz.cpp 
            src/mensagem.cpp 
            src/servidor.cpp 
            src/usuario.cpp 
            src/sistema.cpp)
