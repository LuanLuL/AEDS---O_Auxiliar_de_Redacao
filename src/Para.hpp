#ifndef PARA_HPP
#define PARA_HPP
#include<string>
#include<vector>
#include"palavra.hpp"
using namespace std;

class Para

{
    private:
        short int numinicio,numfim;
        int numsentenca;
        vector<Palavra*> vecpalavra;
        vector<string> sentencas;
    public:
        //Construtor:
        Para();

        //Gets e Sets:
        void setnuminicio(short int numinicio);
        short int getnuminicio();

        void setnumfim(short int numfim);
        short int getnumfim();
        
        void setsentenca(vector<string> sentenca);
        vector<string> getsentenca();

        void setvecpalavra(vector<Palavra*> vecpalavra);
        vector<Palavra*> getvecpalavra();

        void setnumsentenca(int numsentenca);
        int getnumsentenca();
};
#endif
