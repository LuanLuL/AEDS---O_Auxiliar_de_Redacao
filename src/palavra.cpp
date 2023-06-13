#include"palavra.hpp"
Palavra::Palavra(){
    this->contador=0;
    this->paragrafo=1;
    this->sentenca=1;
}
void Palavra::setcontador(short int contador){
    this->contador=contador;
}
short int Palavra::getcontador() const{
    return this->contador;
}
void Palavra::setparagrafo(short int paragrafo){
    this->paragrafo=paragrafo;
}
short int Palavra::getparagrafo() const{
    return this->paragrafo;
}
void Palavra::setsentenca(short int sentenca){
    this->sentenca=sentenca;
}
short int Palavra::getsentenca() const{
    return this->sentenca;
}
void Palavra::setpalavra(string palavra){
    this->palavra=palavra;
}
string Palavra::getpalavra() const{
    return this->palavra;
}