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

 - [Fundamentação Teórica](#Fundamentação-Teórica)
    - [Estruturas de Dados](#Estruturas-de-Dados)
    - [Algoritmos](#Algoritmos)

 - [Metodologia](#Metodologia)
    - [Arquivos](#Arquivos)
        - [Funcionamento](#Funcionamento)
        - [Leitura do Arquivo](#Leitura-do-Arquivo)
 
 - [Objetivos](#Objetivos)
<br><br>

## Introdução
Este repositório apresenta um programa que obtem métricas textuais à cerca de uma entradas em forma de texto, livro ou junção de várias sentenças. A implementação foi proposta na disciplina de Algoritmos e Estruturas de Dados. Para isso foi necessário armazenar combinações de caracteres, formando aglomerados de dados que abstraem: parágrafos, sentenças e palavras. Para isso considere as seguintes colocações:

- Nomes de diretórios, ou arquivos serão referênciados da seguinte forma: `Nome.data` ou `Diretório_2`.

- $f$ - Representa uma função.

- $x$ - Representa um número que pertence ao domínio da função $f$.

- $y$ - Representa a imagem para um valor $x$ no domínio de uma função $f$.

- $N$ - Sequência de dados armazenados, ou seja, um vetor.

- $i$ - Representa o uma posição específica de $N$.

- $p$ - Abstrai a ideia de palavra, ou seja, uma relação entre caracteres.

- $s$ - Abstrai a ideia de sentença, ou seja, uma relação entre palavras.

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




## Objetivos
A problemática proposta pelo trabalho incita os alunos da disciplina a efetuar a análise de um texto contido em um arquivo sem formatação do tipo ASCII. Para realização deste procedimento é considerado que:
- As sentenças são definidas entre os delimitadores de pontuação à seguir: ".", "?" e "!".
- Os parágrafos são definidos como um conjunto de sentenças entre duas linhas em branco no arquivo. Na leitura o programa considera que duas linhas em branco são representadas por `\n`.
