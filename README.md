# Projeto 3 de LP1 (Concordo)
Projeto de aplicativo com funcionalidades semelhantes ao Discord em c++.

## Funcionalidades presentes
* Manipulação de arquivos
* Métodos novos na classe Lista
* Sobrecarga de operadores na classe Lista (incompleto)
* Métodos novos na classe Playlist
* Sobrecarga de operadores na classe Playlist (incompleto)

## Documentação
Documentação feita com Doxygen, enviando arquivos .tex e .html.

## Compilação
### <em>Executando com GCC</em>
<ol>
<li> Clone o seguinte repositório

    git clone https://github.com/saraivajv/ConcordoProjeto --branch main --single-branch master
    
<li> Abra o terminal na pasta clonada e digite

    g++ -o master main.cpp canal.cpp canaltexto.cpp canalvoz.cpp mensagem.cpp servidor.cpp usuario.cpp sistema.cpp
    
<li> Agora execute com

    ./concordo

</ol>

### <em>Executando com CMake</em>

<ol>
<li> Clone o seguinte repositório

    git clone https://github.com/saraivajv/ConcordoProjeto--branch main --single-branch master
    
<li> Abra o terminal na pasta clonada e digite

    mkdir build
    cd build
    
<li> Execute o CMake

    cmake ..
    
<li> Compile com

    make
    
<li> Por fim, execute

    ./concordo

</ol>

## Dificuldades
O list-participants está parcialmente funcional.

## Aluno
* João Victor Gonçalves de Albuquerque Saraiva