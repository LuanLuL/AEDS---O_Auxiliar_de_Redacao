#include "Para.hpp"
Para::Para()
{
    this->numinicio=1;
    this->numfim=1;
    this->sentencas={""};
}

void Para::setnuminicio(short int numinicio)
{
    this->numinicio=numinicio;
}

short int Para::getnuminicio()
{
    return this->numinicio;
}

void Para::setnumfim(short int numfim)
{
    this->numfim=numfim;
}

short int Para::getnumfim()
{
    return this->numfim;
}

void Para::setsentenca(vector<string> sentenca)
{
    this->sentencas=sentenca;
}

vector<string> Para::getsentenca()
{
    return this->sentencas;
}
