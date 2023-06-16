
#include"palavra.hpp"
#include "Hash.hpp"

using namespace std;

int main(){
    Hash h;
    ifstream arq;
    string palavra = "no coco ajcu da roça teta";
    h.learquivo(arq);
    h.ShowWords();
    //h.stopwords(palavra);
    return 0;
}