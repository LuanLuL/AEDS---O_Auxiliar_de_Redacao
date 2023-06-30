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
Este repositório apresenta um programa que obtém métricas textuais à cerca de uma entradas em forma de texto, livro ou junção de várias sentenças. A implementação foi proposta na disciplina de Algoritmos e Estruturas de Dados. Para isso foi necessário armazenar combinações de caracteres, formando aglomerados de dados que abstraem: parágrafos, sentenças e palavras. Para isso considere as seguintes colocações:

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
- O Número de palavras de cada sentença incluindo e descartando "stop words".


Da análise das palavras que não estão contidas no arquivo `stopwords.x`, é obtido:
- Cada palavra listada em ordem alfabética com frequÊncia de sua ocorrência no texto, indicando as linhas do arquivo onde essas surgem.
- A ocorrência das palavras que aparecem mais de uma vez em um mesmo parágrafo.

Da análise das palavras que estão contidas ou não no arquivo `stopwords.x`, é analisado:
- A distância entre as repetições de palavras que aparecem mais de uma vez em um mesmo parágrafo. 

## Justificativa
A análise de parágrafos assiste escritores de redações ao indicar parágrafos longos de mais, bem como parágrafos formados por uma única sentença.

A análise de palavras contribui durante a escrita acadêmica, uma vez que indica repetições excessivas de palavras em um mesmo parágrafo.
