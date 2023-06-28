#include "palavra.hpp"
#include "Hash.hpp"

using namespace std;


/*


    Vamos pegar o vetor de parágrafos de cada palavras


*/

int main(){
    Hash h;
    ifstream arq;
    h.learquivo(arq);
    h.AlphaOrder();
    return 0;
}