#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include "palavra.hpp"
#include "Para.hpp"

class Hash
{
    private:
        //Atributos:
        Palavra *p;
        Para *para;    
        unordered_map<string, Palavra *> map;
        int linha=0;
        int contpalavras = 0, contstopwords = 0;
        vector<vector<string>> pacote;
        vector<Para*> vetorParagrafos;
    public:
        //Construtor:
        Hash();
        //Gets e Sets:
        void setPalavra(Palavra *p);
        Palavra* getPalavra();
        void setPara(Para *p);
        Para* getPara();
        void setMap(unordered_map<string, Palavra *> map);
        unordered_map<string, Palavra *> getMap();
        //Métodos:
        void learquivo(ifstream &arq);
        string UpperToLowerAccent(string bigAccentString);
        vector<Palavra*> retorna_vetor(char *separa_linha);
        string transforme(string linha);
        void AlphaOrder(unordered_map<string, pair<int, vector<int>>> *texto);
        bool stopwords (string palavra);
        void separastopwords();
};

#endif