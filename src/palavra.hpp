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
        int cont;
        string paragrafo; 
        string numsentenca;
        string palavra,linhaocorrencia;
        vector<int> posparagrafo,possentenca;
        bool alreadyReaded, stopword;
    public:

        //Construtor:
        Palavra();

        //Gets e Sets:
        void setcont(int cont);
        int getcont() const;

        void setparagrafo(string paragrafo);
        string getparagrafo() const;

        void setposparagrafo(vector<int> posparagrafo);
        vector<int> getposparagrafo() const;

        void setpossentenca(vector<int> possentenca);
        vector<int> getpossentenca() const;

        void setnumsentenca(string numsentenca);
        string getnumsentenca() const;

        void setpalavra(string palavra);
        string getpalavra() const;
        
        void setlinhaocorrencia(string linhaocorrencia);
        string getlinhaocorrencia() const;

        void setalreadyReaded(bool alreadyReaded);
        bool getalreadyReaded() const;

        //Métodos:
        void learquivo(ifstream arq);
};
#endif