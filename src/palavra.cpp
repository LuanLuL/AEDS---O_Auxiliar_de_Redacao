#include"palavra.hpp"
Palavra::Palavra(){
    this->contador=0;
}
void Palavra::setcontador(short int contador){
    this->contador=contador;
}
short int Palavra::getcontador() const{
    return this->contador;
}
void Palavra::setparagrafo(vector<int> paragrafo){
    this->paragrafo=paragrafo;
}
vector<int> Palavra::getparagrafo() const{
    return this->paragrafo;
}
void Palavra::setnumsentenca(vector<int> numsentenca){
    this->numsentenca=numsentenca;
}
vector<int> Palavra::getnumsentenca() const{
    return this->numsentenca;
}
void Palavra::setpalavra(string palavra){
    this->palavra=palavra;
}
string Palavra::getpalavra() const{
    return this->palavra;
}

void Palavra::setfirstOcurrencyLine(unsigned short int firstOcurrencyLine){
    this->firstOcurrencyLine=firstOcurrencyLine;
}
unsigned short int Palavra::getfirstOcurrencyLine() const{
    return this->firstOcurrencyLine;
}
