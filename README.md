**Guia de instalação SystemC - Ubuntu 20.04**

**1. Pré-requisitos:**

- cmake (3.0+)

- g++ (5.4+)

- build-essential

g++ e cmake estão inclusos no pacote build-essential, logo só é necessário instalar o build-essential:

| sudo apt install build-essential |
| --- |

**3.**  **Instalação do pacote**** :**

Para instalar o SystemC, é necessário fazer a instalação de dois pacotes:

| sudo apt install libsystemc libsystemc-dev |
| --- |

**3. Criando um projeto systemc:**

Para iniciar um novo projeto, é necessário criar somente um arquivo .cpp, porém para facilitar a compilação, é recomendado criar um &quot;Makefile&quot;, um pequeno projeto está disponível para download, e pode se clonar este git para baixar a make file já pronta e um exemplo de mux com tb.

| git clone https://github.com/Jp-K/TutorialSystemc.git |
| --- |

Se quiser criar uma Makefile, aqui está o exemplo de como foi criado:

| CXXFLAGS=-lsystemcSRCS=\*cppCC=g++BIN=main
all: $(CC) $(SRCS) $(CXXFLAGS) -o $(BIN) ./$(BIN) |
| --- |

Após a criação do projeto, podemos usar o seguinte comando para compilar:

Caso tenha feito a Makefile:

| make |
| --- |

Caso não tenha a Makefile:

| g++ \*.cpp -lsystemc -o main
 ./main |
| --- |

**4. Configurando a compilação do visual studio code:**

Antes de tudo, é necessário baixar o pluguin &quot;code runner&quot;:

![](RackMultipart20210306-4-jlv8mt_html_4dc6a2520db7fb39.png)

Depois da istalação do plugin, é necessário configurar a compilação do c++, siga os passos a baixo:

Clique na roda dentada e selecione &quot;Extension Settings&quot;:

![](RackMultipart20210306-4-jlv8mt_html_d9b410287dd6a68.png)

Procure por &quot;Executor Map&quot;, e selecione &quot;Edit in settings.json&quot;:

![](RackMultipart20210306-4-jlv8mt_html_ce406c5f1e0a13df.png)

Por fim, localize a linha que se refere a &quot;cpp&quot;, e altere seu valor para:

**&quot;cd $dir &amp;&amp; make&quot;**

![](RackMultipart20210306-4-jlv8mt_html_9913d822aa9b2956.png)

![](RackMultipart20210306-4-jlv8mt_html_c824a0709fde1c84.png)

Pronto, seu visual studio code está pronto para compilar sozinho.
