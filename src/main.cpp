
#include"palavra.hpp"
#include "Hash.hpp"

using namespace std;

int main(){
    Hash h;
    ifstream arq;
    string palavra = "no coco ajcu da roça teta";
    h.learquivo(arq);
    h.AlphaOrder();
    //A=-127,-128,-126,125//E=-118 a -120//I=-115//O=-107 a -109//U=-100 a -102
    return 0;
}