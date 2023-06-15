#ifndef HASH_HPP
#define HASH_HPP

#include"palavra.hpp"
#include "Para.hpp"


class Hash{
    private:
        Palavra *p;
        Para *para;
    public:
        //Construtor:
        Hash();

        //Gets e Sets:
        void setPalavra(Palavra *p);
        Palavra* getPalavra();

        void setPara(Para *p);
        Para* getPara();

        //Métodos:
        void learquivo(ifstream &arq);
        vector<Palavra*> retorna_vetor(char *separa_linha);
};

#endif
