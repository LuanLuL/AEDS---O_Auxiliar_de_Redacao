#ifndef PARA_HPP
#define PARA_HPP
#include<string>
#include<vector>
using namespace std;

class Para

{
    private:
        short int numinicio,numfim;
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
};
#endif
