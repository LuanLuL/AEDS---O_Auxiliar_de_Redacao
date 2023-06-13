#ifndef PALAVRA_HPP
#define PALAVRA_HPP
#include<iostream>
#include<unordered_map>
#include<string.h>
#include<fstream>
#include<vector>
using namespace std;
class Palavra
{
private:
    short int contador,paragrafo, sentenca;
    string palavra;
public:
    Palavra();
    void setcontador(short int contador);
    short int getcontador() const;
    void setparagrafo(short int paragrafo);
    short int getparagrafo() const;
    void setsentenca(short int sentenca);
    short int getsentenca() const;
    void setpalavra(string palavra);
    string getpalavra() const;
    void learquivo(ifstream arq);
};
#endif
