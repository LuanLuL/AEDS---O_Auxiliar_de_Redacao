#include "Hash.hpp"

/******************************************************************* CONSTRUTORES AND DESTRUTORES*/
Hash::Hash() {
   this->p = new Palavra();
}

Hash::~Hash(){}

/*************************************************************************** GETTERS AND SETTERS */
void Hash::setPalavra(Palavra *p){
    this->p = p;
}

Palavra *Hash::getPalavra(){
    return this->p;
}
/*************************************************************************************** METODOS */
vector<Palavra *> Hash::retorna_vetor(char *separa_linha){
    vector<string> palavras, sentencas_separadas;
    vector<Palavra *> vetorpassado;
    string a;
    char *palavra, *palavra2;
    palavra = strtok(separa_linha, ",;- :_");
    while (palavra != nullptr)
    {
        palavras.push_back(palavra);
        palavra = strtok(nullptr, ",;- :_");
    }
    for (int i = 0; i < int(palavras.size()); i++)
    {
        palavra = new char[palavras[i].length() + 1];
        strcpy(palavra, palavras[i].c_str());
        if (palavras[i].find('.') != string::npos || palavras[i].find('?') != string::npos || palavras[i].find('!') != string::npos)
        {
            palavra2 = strtok(palavra, "?!.");
            while (palavra2 != nullptr)
            {
                a=palavra2;
                if(a.length()!=1){
                    sentenca++;
                }
                Palavra *p = new Palavra();
                setPalavra(p);
                vector<int> vec=getPalavra()->getsentenca();
                vec.push_back(sentenca);
                getPalavra()->setsentenca(vec);
                getPalavra()->setpalavra(palavra2);
                vetorpassado.push_back(getPalavra());
                sentencas_separadas.push_back(palavra2);
                palavra2 = strtok(nullptr, "?!.");
            }
        }
        else
        {
            Palavra *p = new Palavra();
            palavra2 = palavra;
            setPalavra(p);
            vector<int> vec=getPalavra()->getsentenca();
            vec.push_back(sentenca);
            getPalavra()->setsentenca(vec);
            getPalavra()->setpalavra(palavra2);
            vetorpassado.push_back(getPalavra());
            sentencas_separadas.push_back(palavra2);
        }
    }
    return vetorpassado;
}

void Hash::learquivo(ifstream &arq){
    string linha;
    short int paragrafos = 1, contadorlinhas = 0;
    vector<Palavra *> vet;
    Palavra *p;
    unordered_map<string, Palavra *> map;
    arq.open("dataset/entrada.txt");
    while (getline(arq, linha))
    {
        // map.insert({linha,p});
        if (linha.empty())
        {
            paragrafos++;
            //cout<<endl;
        }
        else
        {
            // cout<<linha.length()<<endl;
            char *separa_linha = new char[linha.length() + 1];
            strcpy(separa_linha, linha.c_str());
            vet = retorna_vetor(separa_linha);
            for (const auto &i : vet)
            {
                if(map.find(i->getpalavra())!=map.end()){
                    //cout<<"\nAAA\n"<<endl;
                    vector<int> vecparagrafos=map[i->getpalavra()]->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    map[i->getpalavra()]->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca=map[i->getpalavra()]->getsentenca();
                    vecsentenca.push_back(i->getsentenca()[0]);
                    map[i->getpalavra()]->setsentenca(vecsentenca);
                }
                else{
                //cout<<" "<<i->getpalavra();
                    p = new Palavra();
                    setPalavra(p);
                    getPalavra()->setcontador(contadorlinhas);
                    getPalavra()->setpalavra(i->getpalavra());
                    vector<int> vecparagrafos=getPalavra()->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    getPalavra()->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca=i->getsentenca();
                    getPalavra()->setsentenca(vecsentenca);
                    map.insert({i->getpalavra(), getPalavra()});
                }

                // cout<<vet[i];
            }
            // cout<<endl;
        }
        contadorlinhas++;
    }
    for (const auto &par : map)
    {
        cout << "CHAVE:" << par.first << "\t\tValor: " << par.second->getsentenca().size() << endl;
    }
    cout << "Paragrafos:" << paragrafos << endl;
    cout << "Linhas:" << contadorlinhas << endl;
    cout << "Senteças:" << sentenca << endl;
    arq.close();
}

