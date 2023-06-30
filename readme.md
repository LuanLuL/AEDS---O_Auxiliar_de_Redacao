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
    - [Estruturas de Dados](#Estruturas-de-Dados)
    - [Algoritmos](#Algoritmos)  

 - [Metodologia](#Metodologia)
    - [Arquivos](#Arquivos)
        - [Funcionamento](#Funcionamento)
        - [Leitura do Arquivo](#Leitura-do-Arquivo)
 
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




## Referências

[1] LEGÍVEIS. In: DICIO, Dicionário Online de Português. Porto: 7Graus, 2023. Disponível em: <https://www.dicio.com.br/risco/>. Acesso em: 30/06/2023.

[2] PIRES, MICHEL - Repositório GitHub, @mpiress: GenerateDataToMatrix - Disponível em: https://github.com/mpiress/GenerateDataToMatrix/blob/main/src/mat.h. Acessado em 15 de Maio de 2023.

[3] GNU make. Disponível em: <https://www.gnu.org/software/make/manual/make.html>. Acessado em XX de Maio de 2023.

[4] GNU Make. Disponível em: <https://www.gnu.org/software/make/>. Acesso em: mai. 23DC.

