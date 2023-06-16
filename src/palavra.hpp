#ifndef PALAVRA_HPP
#define PALAVRA_HPP
#include<iostream>
#include<unordered_map>
#include<string.h>
#include<fstream>
#include<vector>
#include <algorithm>
#include<string>
#include<sstream>

using namespace std;
class Palavra
{
private:
    short int contador;
    vector<int> paragrafo, numsentenca;
    string palavra;
public:
    //Construtor:
    Palavra();

    //Gets e Sets:
    void setcontador(short int contador);
    short int getcontador() const;

    void setparagrafo(vector<int> paragrafo);
    vector<int> getparagrafo() const;

    void setnumsentenca(vector<int> numsentenca);
    vector<int> getnumsentenca() const;

    void setpalavra(string palavra);
    string getpalavra() const;

    //Métodos:
    void learquivo(ifstream arq);
};
#endif
