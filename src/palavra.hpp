#ifndef PALAVRA_HPP
#define PALAVRA_HPP

#include<iostream>
#include<unordered_map>
#include<string.h>
#include<fstream>
#include<vector>

using namespace std;

class Palavra{
    private:
        short int contador, paragrafo, sentenca;
        string palavra;
    public:
        /************************************************** CONSTRUTORES AND DESTRUTORES */
        Palavra();
        ~Palavra();
        /*********************************************************** GETTERS AND SETTERS */
        void setcontador(short int contador);
        short int getcontador();
        void setparagrafo(short int paragrafo);
        short int getparagrafo();
        void setsentenca(short int sentenca);
        short int getsentenca();
        void setpalavra(string palavra);
        string getpalavra();
        /*********************************************************************** METODOS */
    };

#endif
