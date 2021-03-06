**Guia de instalação SystemC - Ubuntu 20.04**

**1. Pré-requisitos:**

\- cmake (3.0+)

\- g++ (5.4+)

\- build-essential

g++ e cmake estão inclusos no pacote build-essential, logo só é
necessário instalar o build-essential:

  ----------------------------------
  sudo apt install build-essential
  ----------------------------------

**3. Instalação do pacote:**

Para instalar o SystemC, é necessário fazer a instalação de dois
pacotes:

  --------------------------------------------
  sudo apt install libsystemc libsystemc-dev
  --------------------------------------------

**3. Criando um projeto systemc:**

Para iniciar um novo projeto, é necessário criar somente um arquivo
.cpp, porém para facilitar a compilação, é recomendado criar um
"Makefile", um pequeno projeto está disponível para download, e pode se
clonar este git para baixar a make file já pronta e um exemplo de mux
com tb.

  -------------------------------------------------------
  git clone https://github.com/Jp-K/TutorialSystemc.git
  -------------------------------------------------------

Se quiser criar uma Makefile, aqui está o exemplo de como foi criado:

+-----------------------------------------+
| CXXFLAGS=-lsystemc                      |
|                                         |
| SRCS=\*cpp                              |
|                                         |
| CC=g++                                  |
|                                         |
| BIN=main                                |
|                                         |
| all:                                    |
|                                         |
| \$(CC) \$(SRCS) \$(CXXFLAGS) -o \$(BIN) |
|                                         |
| ./\$(BIN)                               |
+-----------------------------------------+

Após a criação do projeto, podemos usar o seguinte comando para
compilar:

Caso tenha feito a Makefile:

  ------
  make
  ------

Caso não tenha a Makefile:

+------------------------------+
| g++ \*.cpp -lsystemc -o main |
|                              |
| ./main                       |
+------------------------------+
