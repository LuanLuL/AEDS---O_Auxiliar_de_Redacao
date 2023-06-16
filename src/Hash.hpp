#ifndef HASH_HPP
#define HASH_HPP

#include"palavra.hpp"
#include "Para.hpp"


class Hash{
    private:
        //Atributos:
        Palavra *p;
        Para *para;    
        unordered_map<string, Palavra *> map;

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
        vector<Palavra*> retorna_vetor(char *separa_linha);

        void stopwords(string);
        void ShowWords();
};

#endif
