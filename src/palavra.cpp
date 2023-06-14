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
void Palavra::setsentenca(vector<int> sentenca){
    this->sentenca=sentenca;
}
vector<int> Palavra::getsentenca() const{
    return this->sentenca;
}
void Palavra::setpalavra(string palavra){
    this->palavra=palavra;
}
string Palavra::getpalavra() const{
    return this->palavra;
}