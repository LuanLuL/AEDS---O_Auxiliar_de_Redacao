#ifndef PARA_HPP
#define PARA_HPP
#include<string>
#include<vector>
#include"palavra.hpp"
#include"unordered_map"
using namespace std;

class Para

{
    private:
        short int numinicio,numfim;
        int numsentenca;
        unordered_map<string,Palavra*> vecpalavra;
        vector<string> sentencas,palavras;
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

        void setpalavras(vector<string> palavras);
        vector<string> getpalavras();

        void setvecpalavra(unordered_map<string,Palavra*> vecpalavra);
        unordered_map<string,Palavra*> getvecpalavra();

        void setnumsentenca(int numsentenca);
        int getnumsentenca();
};
#endif
