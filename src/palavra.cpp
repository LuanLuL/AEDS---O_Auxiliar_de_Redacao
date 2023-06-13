#include"palavra.hpp"

/******************************************************************* CONSTRUTORES AND DESTRUTORES*/
Palavra::Palavra(){
    this->contador=0;
    this->paragrafo=1;
    this->sentenca=1;
}

Palavra::~Palavra(){}

/*************************************************************************** GETTERS AND SETTERS */
void Palavra::setcontador(short int contador){
    this->contador=contador;
}

short int Palavra::getcontador(){
    return this->contador;
}

void Palavra::setparagrafo(short int paragrafo){
    this->paragrafo=paragrafo;
}

short int Palavra::getparagrafo(){
    return this->paragrafo;
}

void Palavra::setsentenca(short int sentenca){
    this->sentenca=sentenca;
}

short int Palavra::getsentenca(){
    return this->sentenca;
}

void Palavra::setpalavra(string palavra){
    this->palavra=palavra;
}
string Palavra::getpalavra(){
    return this->palavra;
}

/*************************************************************************************** METODOS */