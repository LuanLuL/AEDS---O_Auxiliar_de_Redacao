#include"palavra.hpp"

Palavra::Palavra()
{
    this->contador=0;
    this->alreadyReaded = false;
}

void Palavra::setcontador(short int contador)
{
    this->contador=contador;
}

short int Palavra::getcontador() const
{
    return this->contador;
}

void Palavra::setparagrafo(vector<int> paragrafo)
{
    this->paragrafo=paragrafo;
}

vector<int> Palavra::getparagrafo() const
{
    return this->paragrafo;
}

void Palavra::setposparagrafo(vector<int> posparagrafo)
{
    this->posparagrafo=posparagrafo;
}

vector<int> Palavra::getposparagrafo() const
{
    return this->posparagrafo;
}

void Palavra::setpossentenca(vector<int> possentenca)
{
    this->possentenca=possentenca;
}

vector<int> Palavra::getpossentenca() const
{
    return this->possentenca;
}

void Palavra::setnumsentenca(vector<int> numsentenca)
{
    this->numsentenca=numsentenca;
}

vector<int> Palavra::getnumsentenca() const
{
    return this->numsentenca;
}

void Palavra::setpalavra(string palavra)
{
    this->palavra=palavra;
}

string Palavra::getpalavra() const
{
    return this->palavra;
}

void Palavra::setlinhaocorrencia(vector<int> linhaocorrencia)
{
    this->linhaocorrencia=linhaocorrencia;
}

vector<int> Palavra::getlinhaocorrencia() const
{
    return this->linhaocorrencia;
}

void Palavra::setalreadyReaded(bool alreadyReaded)
{
    this->alreadyReaded=alreadyReaded;
}

bool Palavra::getalreadyReaded() const
{
    return this->alreadyReaded;
}