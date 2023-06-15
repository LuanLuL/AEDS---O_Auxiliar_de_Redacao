#ifndef HASH_HPP
#define HASH_HPP

#include"palavra.hpp"

int sentenca = 1;

class Hash{
    private:
        Palavra *p=new Palavra();
    public:
        /************************************************** CONSTRUTORES AND DESTRUTORES */
        Hash();
        /*********************************************************** GETTERS AND SETTERS */
        void setPalavra(Palavra *p);
        Palavra* getPalavra();
        /*********************************************************************** METODOS */
        void learquivo(ifstream &arq);
        vector<Palavra*> retorna_vetor(char *separa_linha);
};

#endif
