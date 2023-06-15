#include"Paragrafo.hpp"
Paragrafo::Paragrafo(){
    this->numInicio=1;
    this->numFim=0;
}
void Paragrafo::setnumInicio(short int numInicio){
    this->numInicio=numInicio;
}
short int Paragrafo::getnumInicio() const{
    return this->numInicio;
}
void Paragrafo::setnumFim(short int numFim){
    this->numFim=numFim;
}
short int Paragrafo::getnumFim() const{
    return this->numFim;
}
void Paragrafo::setsentenca(vector<string> sentenca){
    this->sentenca=sentenca;
}
vector<string> Paragrafo::getsentenca() const{
    return this->sentenca;
}