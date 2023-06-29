
#include <locale>
#include <fstream>
#include "palavra.hpp"
#include "Hash.hpp"
#define _ ios_base::sync_with_stdio(0);
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Hash h;
    ifstream arq;
    h.learquivo(arq);
    return 0;
}

