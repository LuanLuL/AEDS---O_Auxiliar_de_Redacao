<!--STOP WORD -  qualquer string que você queira ignorar na sua análise-->

<div align = "center" >
<img src="./img/Icon.png" height="35%" width="35%">
</div>

<div align="justify">

<div align="center">

# Auxiliar de Redação

#### Algoritmos e Estrutura de Dados

#### Compatibilidade e Desenvolvimento
![Vscode](https://img.shields.io/badge/VSCode-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white) 
![C++](https://img.shields.io/badge/C++-00599C.svg?style=for-the-badge&logo=C++&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

</div>

## Índice
 - [Introdução](#Introdução)

 - [Objetivos](#Objetivos)
   - [Premissas](#premissas)
   - [Objetivo Geral](#objetivo-geral)
   - [Objetivos Específicos](#objetivos-específicos)

 - [Justificativa](#Justificativa)

 - [Fundamentação Teórica](#Fundamentação-Teórica)
    - [Paradigma de Programação Orientado à Objetos](#paradigma-de-programação-orientado-à-objetos)
    - [Tabela de Espalhamento](#tabela-de-espalhamento) 

 - [Metodologia](#Metodologia)
    - [Definição da Amostragem](#definição-da-amostragem)
    - [Arquitetura do Projeto](#arquitetura-do-projeto)
    - [Funcionamento](#Funcionamento)
      - [Leitura do Arquivo](#Leitura-do-Arquivo)

 - [Instruções de Instalação](#instruções-de-instalação)
 - [Instruções de Uso](#instruções-de-uso)

 - [Referências](#referências)

<br><br>

## Introdução
Este repositório apresenta um programa que obtém métricas textuais à cerca de uma entrada em forma de texto, livro ou junção de várias sentenças. A implementação foi proposta na disciplina de Algoritmos e Estruturas de Dados. Para isso foi necessário armazenar combinações de caracteres, formando aglomerados de dados que abstraem: parágrafos, sentenças e palavras.

Além da reconstrução de um software auxiliar de redação a equipe desenvolve o projeto com o intuito de minimizar custos relacionados ao processamento de dados textuais, uma vez que as ferramentas propostas já foram criadas por outros desenvolvedores.
 Para isso considere as seguintes colocações:

- Nomes de diretórios, ou arquivos serão referênciados da seguinte forma: `Nome.data` ou `Diretório_2`.

- $f$ - Representa uma função.

- $x$ - Representa um número que pertence ao domínio da função $f$.

- $y$ - Representa a imagem para um valor $x$ no domínio de uma função $f$.

- $N$ - Sequência de dados armazenados, ou seja, um vetor.

- $i$ - Representa o uma posição específica de $N$.

- $p$ - Abstrai a ideia de palavra, ou seja, uma relação entre caracteres.

<!-- - $s$ - Abstrai a ideia de sentença, ou seja, uma relação entre palavras.

- $P$ - Abstrai a ideia de um parágrafo, ou seja, uma relação entre sentenças.

- $§$ - Abstrai a ideia de um texto, ou seja, um conjunto de parágrafos.

- $A$ - É um conjunto de palavras.

- $B$ - É um conjunto de sentenças.

- $C$ - É um conjunto de parágrafos.

- $V$ - Conjunto de vértices de um grafo.

- $E$ - Conjunto de arestas de um grafo.

- $G$ - Um Grafo $G$ qualquer.

- $e$ - Um vértice $e$ qualquer.

- $v$ - Um Grafo $v$ qualquer.

- $n_{v}$ - Número de vértices em um percurso.
 -->



## Objetivos
### Objetivo Geral
O objetivo do código elaborado é efetuar a análise de um texto contido em um arquivo sem formatação do tipo ASCII. Gerando uma análise de diversos dados textuais como saída, de forma à seguir os objetivos específicos.

### Premissas
Para realização deste procedimento foi considerado que:
- As sentenças são definidas entre os delimitadores de pontuação à seguir: ".", "?" e "!".
- Os parágrafos são definidos como um conjunto de sentenças entre pelo menos uma linha em branco. Linhas em branco são caracterizadas por `\n`.
- Artigos(a, o, as, os), conjunções (mas, nem, como, se, mais) e palavras(depois, aquilo, seríamos) contidas em um arquivo denominado `stopwords.x` serão desconsideradas nas análises realizadas pelo programa. Este arquivo é criado pelo aluno e deverá ter seu formato especificado.
- A análise envolve métricas com o número das linhas nos arquivo analisado, para isso considere a primeira linha do arquivo de entrada como "1", a segunda como "2" e assim por diante.
- Uma única palavra $p$ é delimitada por espaço em branco, coluna da esquerda, coluna da direita e símbolos de pontuação.
- Outras suposições e premissas podem ser criadas desde que não aleterem as premissas acima.

### Objetivos Específicos
Da análise dos parágrafos, são obtidos:
- O Número das linhas de início e fim dos parágrafos.
- A Quantidade de sentenças em cada parágrafo.
- O Número de palavras de cada sentença incluindo e descartando _stop words_.


Quando analisadas as palavras que não estão contidas no arquivo `stopwords.txt`, é obtida:
- Cada palavra listada em ordem alfabética com frequÊncia de sua ocorrência no texto, indicando as linhas do arquivo onde essas surgem.
- A ocorrência das palavras que aparecem mais de uma vez em um mesmo parágrafo.

Caso a entrada provenha palavras que estão contidas ou não no arquivo `stopwords.txt`, é inspecionada:
- A distância entre as repetições de palavras que aparecem mais de uma vez em um mesmo parágrafo. 

Da análise das expressões que estão contidas no arquivo `expressoes.txt`, é considerado:
- O número das linhas onde essas palavras aparecem.


## Justificativa

O projeto foi realizado visando reescrever ferramentas para auxiliar usuários de editores de texto. Os dados gerados tem importância uma vez que os seguintes problemas são enfrentados durante a escrita.

1. Parágrafos grandes de mais, com um pequeno número de sentenças dificultam a compreensão dos textos.

2. Artigos científicos são penalizados e se tornam confusos ao apresentar palavras excessivamente  repetidas. Além de tudo, há outros gêneros textuais em que a repetição das palavras de qualquer tipo podem torná-los não legíveis. Define-se "legíveis" como "O plural de legível. Que se consegue ler com facilidade; cuja clareza e/ou nitidez facilita a leitura.(RISCO, 2023)"

3. Quando uma palavra foi digitada várias vezes em um texto, pode ser necessário que esta seja corrigida. Um exemplo dessa situação é quando uma palavra é utilizada de maneira indevida ou quando ela não existe formalmente e é inserido em um texto.

O auxiliar de redação desenvolvido auxilia escritores à lidar com as situações citadas acima, uma vez que:

1. A análise de parágrafos indica parágrafos longos, bem como parágrafos formados por uma única sentença.

2. A análise de palavras contribui durante a escrita de diversos gêneros textuais, uma vez que mostra repetições excessivas de palavras em um mesmo parágrafo.

3. A análise de expressões, provém a localização destas no texto, para que diante de uma busca realizada pela máquina haja uma correção eficiênte por parte do escritor.

 Durante o desenvolvimento minimizar custos de implmementação era um propósito

## Fundamentação Teórica

### Paradigma de Programação Orientado à Objetos
A leitura do texto de entrada tem os dados segmentados em parágrafos, sentenças e palavras, afinal era necessário que estes pudessem ter somente características essênciais ao cumprimento dos objetivos sendo processadas.Dito isto é essêncial trabalhar paralelamente com a proposta de tipos de dados abstratos e construções de encapsulamento.

Para (SEBESTA, 2018, p.446) uma abstração pode ser definida da seguinte forma: "Visão ou representação de uma entidade que inclui apenas os atributos mais significativos. De um modo geral, a abstração permite que alguém colete exemplares de entidades em grupos nos quais seus atributos comuns não precisam
ser considerados". Além de tudo o autor 

Diante disso a programação Orientada à Objetos(Que também dispõe de herança e vinculação dinâmica como recursos para desenvolvimento) é o paradígma de programação pelo qual o Auxiliar de Redação foi estruturado afim de usufruir da abstração de dados e encapsulamento de atributos.

### Tabela de Espalhamento
Para gerar dados diante da anaĺise de palavras, sentenças e parágrafos é imprescindível armazená-los em estruturas de dados. Dito isto os parágrafos são armazenados em um vector, que se define como um vetor dinâmico que reajusta seu tamanho a cada inserção.

O armazenamento de palavras foi elaborado com maior cautela, afinal a forma com que o algoritmo foi escrito demanda que a pesquisa por palavras fosse realizada várias vezes. Diante de uma situação onde há mais pesquisa que inserção e não existe remoção das estruturas de dados que armazenariam palavras, uma estrutura com baixo custo de pesquisa foi escolhida para integrar o Auxiliar de Redação.

"Embora a busca por um elemento em uma tabela de espalhamento possa demorar tanto quanto procurar um elemento em uma lista ligada - o tempo $Θ(n)$ no pior caso - , na prática o hashing funciona extremamente bem. Sob premissas razoáveis, o tempo médio para pesquisar um elemento em uma tabela de espalhamento é $O(1)$"(CORMEN, 2012, p.184).

Portanto as circunstâncias indicam que uma tabela de espalhamento se torna a decisão de estrutura de dados mais adequada para armazenar as palavras e realizar pesquisa sobre estes elementos.

## Metodologia

### Definição da Amostragem
Os dados utilizados como entrada para desenvolvimento do Auxiliar de Redação são os textos nos arquivos `dataset/DomCasmurro.txt`, `dataset/entrada.txt`e `dataset/entrada2.txt`. 

A escolha da amostra de dados se justifica por diversos motivos. Os textos de entrada escolhidos agregam pela variedade de vocábulos, expressões e caracteres e pela diferença entre a quantidade de linhas, diante disso os arquivos escolhidos são: `Bíblia.txt`, `DomCasmurro.txt`,  `entrada.txt` e `entrada2.txt`. Ter uma diversificação no número de linhas ajudou os desenvolvedores à observar coerencia relacionada às mensurações de saídas dependentes do número de linhas. Ademais,
a variedade de caracteres nos textos dos arquivos `Bíblia.txt` e `DomCasmurro.txt`, foram importantes para validar a persistividade dos resultados relacionados à identificação de _stop words_, expressões e tratamento de palavras com letras maiúsculas. Por fim a diversidade de palavras no conjunto de entradas foi essêncial para testar o programa em situações onde as mais diversas palavras possíveis teriam de ser classificadas como _stop words_ ou não, armazenadas na estrutura de espalhamento e ter seus atributos necessários associados.

As entradas fornecidas em `expressoes.txt` e `stopwords.txt` foram selecionadas em função de delimitar situações onde as palavras contidas nestes arquivos tivessem de ser ignorados. Portanto foram consideradas como palavras pertencentes à casos de exceção.

### Arquitetura do Projeto
Para realização dos objetivos específicos o programa segue a seguinte árvore de diretórios.
```
.AEDS---O_Auxiliar_de_Redacao
│
│
...
│
├── dataset
│   ├── DomCasmurro.txt
│   └── entrada.txt
│   └── entrada2.txt
│   └── expressoes.txt
│   └── Resultados1.data
│   └── stopwords.txt
│
...
│
├── src
│   ├── Hash.cpp
│   ├── Hash.hpp
│   ├── main.cpp
│   ├── palavra.cpp
│   ├── palavra.hpp
│   ├── Para.cpp
│   ├── Para.hpp
│   └── file23.ext
│
├── Makefile
└── readme.md
```

- `Hash.cpp`: Arquivo com _gets_ _sets_ e construtores da classe principal _Hash_.
- `Hash.hpp`: Arquivo com assinaturas da classe principal _Hash_.

- `palavra.cpp`: Arquivo com _gets_ _sets_ e construtores da classe palavra.
- `palavra.hpp`: Arquivo com assinaturas da classe  palavra.

- `Para.cpp`: Arquivo com _gets_ _sets_ e construtores da classe Para, uma classe para abstração de parágrafos.
- `Para.hpp`: Arquivo com assinaturas da classe Para.

- `main.cpp`: Arquivo onde é criado um objeto da classe _Hash_ inicializando o objeto principal do programa.

- `Makefile`: Controla a geração dos executáveis e compilação dos mesmos(FREE SOFTWARE FOUNDATION, GNU make, 2023).
- `readme.md`: contém a documentação do projeto.

### Funcionamento
#### Leitura do Arquivo
O código do arquivo main inicaliza uma estrutura denominada `_Hash_` que na verdade representa uma abstração para todos os processos e variáveis do programa.

Após a inicialização o método `lerarquivo` recebe um ponteiro `arq` realiza a leitura de uma linha de cada vez da entrada que for passada como parâmetro para a chamada do seu método open.

Durante a leitura do arquivo objetos que representam palavras são criados e tem seus atributos atualizados conforme a leitura ocorre. Vale ressaltar que o mesmo ocorre para os Parágrafos.

#### Extraindo informações
Durante a leitura do arquivo vários processos são realizados. De maneira simultânea, portanto será descrito como cada funcionalidade do Auxiliar de Redação foi implementada separadamente.

1. O programa concebe que a leitura das últimas linhas é delimitada em um único parágrafo quando uma linha vazia é lida. Dito isto, um objeto do tipo `Para` tem dois atributos, denominados `numfim` e `numinicio`, estes recebem respectivamente o valor da linha inicial o valor da linha atual como equivalente ao valor da linha que está após uma linha vazia e o valor da linha final como o valor da linha aterior à ela.


## Instruções de Instalação
1. Copie a URL **`https://github.com/LuanLuL/AEDS---O_Auxiliar_de_Redacao.git`**.

2. Abra o terminal e escolha um diretório para a instalação.

3. Para clonar o repositório na máquina digite `git clone`, e cole a URL que foi copiada previamente.

4. Por fim o seguinte conteúdo será o resultado dos últimos passos, então é só pressionar a tecla `Enter`.

```
git clone https://github.com/LuanLuL/AEDS---O_Auxiliar_de_Redacao.git
```


## Instruções de Uso
Para compilação e execução do código é necessário que seja criado um arquivo Makefile. Para uso deste arquivo de forma correta, siga as diretrizes de execução abaixo:
<table>

<tr>
<td colspan = '1'><strong>Comandos</strong></td>
<td align = "center" colspan = '1'><strong>Funções</strong></td>
</tr>

<tr>
<td align="center"><strong><i>make clean</i></strong>
</td>
<td align="center">Deleta o arquivo executável e todos os arquivos objetos do diretório. (FREE SOFTWARE FOUNDATION, GNU make, 2023)</td>
</tr>
<tr>
<td align="center"><strong><i>make</i></strong></td>
<td align="center">Compila diferentes partes do programa através do g++ e cria um arquivo executável na pasta build. </td>
</tr>
<tr>
<td align="center"><strong><i>make run</i></strong></td>
<td align="center">Executa o programa da pasta build após a realização da compilação. (PIRES, MICHEL, 2023)</td>
</tr>
</table>

<!--Apesar do texto ter várias palavras iguais, o algoritmo escrito usa a colisão para atualizar atributos da palavra armazenada em alguma posição na Hash ao invés de armazená-la em outro índice. -->


## Referências

[1] LEGÍVEIS. In: DICIO, Dicionário Online de Português. Porto: 7Graus, 2023. Disponível em: <https://www.dicio.com.br/risco/>. Acesso em: 30/06/2023.

[2] SEBESTA, R. W. Concepts of Programming Languages. Tradução: João Eduardo Nóbrega Tortello. 11. ed. [s.l.] Pearson Education, Inc., 2018. p. 446, 488 e 489

[3] CORMEN, T. H. et al. Introduction to Algorithms, third edition. [s.l.] MIT Press, 2012. Acessado em 01 de Julho de 2023.

[4] GNU make. Disponível em: <https://www.gnu.org/software/make/manual/make.html>. Acessado em 01 de Julho de 2023.

[5] PIRES, MICHEL - Repositório GitHub, @mpiress: GenerateDataToMatrix - Disponível em: https://github.com/mpiress/GenerateDataToMatrix/blob/main/src/mat.h. Acessado em 01 de Julho de 2023.




