#ifndef HASH_HPP
#define HASH_HPP

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

        void FirstOcurrencyWord(string word);

        void AlphaOrder();
        void CriaArq(vector<string> vectorordenado);

        bool stopwords (string palavra);
        void separastopwords();

        //void MedeDistancia(vector <string> vectorordenado, int numparagrafo,fstream *arq);

};

#endif