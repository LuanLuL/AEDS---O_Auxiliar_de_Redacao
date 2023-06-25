#include "palavra.hpp"
#include "Hash.hpp"

using namespace std;


/*


    Vamos pegar o vetor de parágrafos de cada palavras


*/

int main(){
    Hash h;
    ifstream arq;
    string palavra = "no coco ajcu da roça teta";
    h.learquivo(arq);
    h.AlphaOrder();
    h.imprimirSaidaStop();
    //h.AlphaOrder();
    //A=-127,-128,-126,125//E=-118 a -120//I=-115//O=-107 a -109//U=-100 a -102

    string d="Único";
    //h.FirstOcurrencyWord("ezequiel");
    //cout<<int(d[0])<<int(d[1])<<endl;
    //h.AlphaOrder();
    //h.stopwords(palavra);
    return 0;
}