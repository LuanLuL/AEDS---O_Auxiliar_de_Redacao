#ifndef PALAVRA_HPP
#define PALAVRA_HPP

#include <iostream>
#include <unordered_map>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include<iomanip>

using namespace std;

class Palavra
{
    private:

        short int contador;
        vector<int> paragrafo, numsentenca;
        string palavra;
        vector<int> linhaocorrencia,posparagrafo,possentenca;
        bool alreadyReaded, stopword;
    public:

        //Construtor:
        Palavra();

        //Gets e Sets:
        void setcontador(short int contador);
        short int getcontador() const;

        void setparagrafo(vector<int> paragrafo);
        vector<int> getparagrafo() const;

        void setposparagrafo(vector<int> posparagrafo);
        vector<int> getposparagrafo() const;

        void setpossentenca(vector<int> possentenca);
        vector<int> getpossentenca() const;

        void setnumsentenca(vector<int> numsentenca);
        vector<int> getnumsentenca() const;

        void setpalavra(string palavra);
        string getpalavra() const;
        
        void setlinhaocorrencia(vector<int> linhaocorrencia);
        vector<int> getlinhaocorrencia() const;

        void setalreadyReaded(bool alreadyReaded);
        bool getalreadyReaded() const;

        //Métodos:
        void learquivo(ifstream arq);
};
#endif