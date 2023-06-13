#ifndef HASH_HPP
#define HASH_HPP
#include"palavra.hpp"
class Hash
{
private:
    Palavra *p=new Palavra();
public:
    Hash();
    void setPalavra(Palavra *p);
    Palavra* getPalavra();
    void learquivo(ifstream &arq);
    vector<Palavra*> retorna_vetor(char *separa_linha);
};
#endif
