#ifndef PARAGRAFO_HPP
#define PARAGRAFO_HPP
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
class Paragrafo
{
private:
    short int numInicio,numFim;
    vector<string> sentenca;
public:
    Paragrafo();
    void setnumInicio(short int numInicio);
    short int getnumInicio() const;
    void setnumFim(short int numFim);
    short int getnumFim() const;
    void setsentenca(vector<string> sentenca);
    vector<string> getsentenca() const;
};
#endif
