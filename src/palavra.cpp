#include"palavra.hpp"

Palavra::Palavra()
{
    this->cont=0;
    this->alreadyReaded = false;
}

void Palavra::setcont(int cont)
{
    this->cont=cont;
}

int Palavra::getcont() const
{
    return this->cont;
}

void Palavra::setparagrafo(string paragrafo)
{
    this->paragrafo=paragrafo;
}

string Palavra::getparagrafo() const
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

void Palavra::setnumsentenca(string numsentenca)
{
    this->numsentenca=numsentenca;
}

string Palavra::getnumsentenca() const
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

void Palavra::setlinhaocorrencia(string linhaocorrencia)
{
    this->linhaocorrencia=linhaocorrencia;
}

string Palavra::getlinhaocorrencia() const
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