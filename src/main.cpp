
#include <locale>
#include <fstream>
#include <time.h>
#include "palavra.hpp"
#include "Hash.hpp"
#define _ios_base_sync_with_stdio _ios_base::sync_with_stdio(0)
using namespace std;

int main(){
    int timeInicio = clock();
    setlocale(LC_ALL, "Portuguese");
    Hash h;
    ifstream arq;
    h.learquivo(arq);
    int timeFinal = clock();
    cout << "Tempo: " << double(timeFinal - timeInicio) / (CLOCKS_PER_SEC / 1000) << " milisegundos" << endl;
    return 0;
}

