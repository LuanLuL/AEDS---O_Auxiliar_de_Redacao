#ifndef HASH_HPP
#define HASH_HPP

#include"palavra.hpp"
#include"Paragrafo.hpp"

int sentenca = 1;

class Hash{
    private:
        Palavra *p;
        Paragrafo *para;
    public:
        /************************************************** CONSTRUTORES AND DESTRUTORES */
        Hash();
        ~Hash();
        /*********************************************************** GETTERS AND SETTERS */
        void setPalavra(Palavra *p);
        Palavra* getPalavra();
        void setParagrafo(Paragrafo *para);
        Paragrafo* getParagrafo();
        /*********************************************************************** METODOS */
        void learquivo(ifstream &arq);
        vector<Palavra*> retorna_vetor(char *separa_linha);
};

#endif
