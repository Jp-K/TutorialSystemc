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

**4. Configurando a compilação do visual studio code:**

Antes de tudo, é necessário baixar o pluguin "code runner":

![](media/image1.png){width="4.177083333333333in"
height="5.260416666666667in"}

Depois da istalação do plugin, é necessário configurar a compilação do
c++, siga os passos a baixo:

Clique na roda dentada e selecione "Extension Settings":

![](media/image2.png){width="6.925in" height="6.822916666666667in"}

Procure por "Executor Map", e selecione "Edit in settings.json":

![](media/image3.png){width="6.925in" height="6.300694444444445in"}

Por fim, localize a linha que se refere a "cpp", e altere seu valor
para:

**"cd \$dir && make"**

![](media/image4.png){width="6.591666666666667in"
height="3.6527777777777777in"}

![](media/image5.png){width="6.6194444444444445in"
height="3.8604166666666666in"}

Pronto, seu visual studio code está pronto para compilar sozinho.
