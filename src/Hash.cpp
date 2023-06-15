#include "Hash.hpp"
/******************************************************************* CONSTRUTORES AND DESTRUTORES*/
Hash::Hash()
{
    this->p = new Palavra();
}

/*************************************************************************** GETTERS AND SETTERS */
void Hash::setPalavra(Palavra *p)
{
    this->p = p;
}

Palavra *Hash::getPalavra()
{
    return this->p;
}
/*************************************************************************************** METODOS */
vector<Palavra *> Hash::retorna_vetor(char *separa_linha)
{
    vector<string> palavras, sentencas_separadas;
    vector<Palavra *> vetorpassado;
    string a;
    char *palavra, *palavra2;
    palavra = strtok(separa_linha, ".!?");
    while (palavra != nullptr)
    {
        a = palavra;
        cout << a  <<endl<<endl;
        if (a.length() != 1)
        {
            sentenca++;
        }
        palavras.push_back(palavra);
        palavra = strtok(nullptr, ".!?");
    }
    for (int i = 0; i < int(palavras.size()); i++)
    {
        palavra = new char[palavras[i].length() + 1];
        strcpy(palavra, palavras[i].c_str());
        palavra2 = strtok(palavra, ",;- :_");
        while (palavra2 != nullptr)
        {
            Palavra *p = new Palavra();
            setPalavra(p);
            vector<int> vec = getPalavra()->getsentenca();
            vec.push_back(sentenca);
            getPalavra()->setsentenca(vec);
            getPalavra()->setpalavra(palavra2);
            vetorpassado.push_back(getPalavra());
            sentencas_separadas.push_back(palavra2);
            palavra2 = strtok(nullptr, ",;- :_");
        }
    }
    return vetorpassado;
}

void Hash::learquivo(ifstream &arq)
{
    string linha, paragrafo;
    short int paragrafos = 1, contadorlinhas = 0,contadorcomeço=0;
    vector<Palavra *> vet;
    Palavra *p;
    unordered_map<string, Palavra *> map;
    arq.open("dataset/entrada.txt");
    while (getline(arq, linha))
    {
        if (linha.empty())
        {
            cout<<"AAA1"<<endl;
            // cout<<paragrafo<<endl;
            char *separa_linha = new char[paragrafo.length() + 1];
            contadorcomeço=0;
            paragrafos++;
            strcpy(separa_linha, paragrafo.c_str());
            vet = retorna_vetor(separa_linha);
            paragrafo = "";
            for (const auto &i : vet)
            {
                if (map.find(i->getpalavra()) != map.end())
                {
                    // cout<<"\nAAA\n"<<endl;
                    vector<int> vecparagrafos = map[i->getpalavra()]->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    map[i->getpalavra()]->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = map[i->getpalavra()]->getsentenca();
                    vecsentenca.push_back(i->getsentenca()[0]);
                    map[i->getpalavra()]->setsentenca(vecsentenca);
                }
                else
                {
                    p = new Palavra();
                    setPalavra(p);
                    getPalavra()->setcontador(contadorlinhas);
                    getPalavra()->setpalavra(i->getpalavra());
                    vector<int> vecparagrafos = getPalavra()->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    getPalavra()->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = i->getsentenca();
                    getPalavra()->setsentenca(vecsentenca);
                    map.insert({i->getpalavra(), getPalavra()});
                }
            }
        }
        else
        {
            cout<<"AAA2"<<endl;
            paragrafo = paragrafo + " " + linha;
        }
        contadorcomeço++;
        contadorlinhas++;
        cout<<"AAAB"<<endl;
    }
    paragrafos++;
    if (paragrafo != "")
    {
        // cout<<paragrafo<<endl;
        char *separa_linha = new char[paragrafo.length() + 1];
        contadorcomeço=0;
        strcpy(separa_linha, paragrafo.c_str());
        vet = retorna_vetor(separa_linha);
        paragrafo = "";
        for (const auto &i : vet)
        {
            if (map.find(i->getpalavra()) != map.end())
            {
                // cout<<"\nAAA\n"<<endl;
                vector<int> vecparagrafos = map[i->getpalavra()]->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                map[i->getpalavra()]->setparagrafo(vecparagrafos);
                vector<int> vecsentenca = map[i->getpalavra()]->getsentenca();
                vecsentenca.push_back(i->getsentenca()[0]);
                map[i->getpalavra()]->setsentenca(vecsentenca);
            }
            else
            {
                // cout<<" "<<i->getpalavra();
                p = new Palavra();
                setPalavra(p);
                getPalavra()->setcontador(contadorlinhas);
                getPalavra()->setpalavra(i->getpalavra());
                vector<int> vecparagrafos = getPalavra()->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                getPalavra()->setparagrafo(vecparagrafos);
                vector<int> vecsentenca = i->getsentenca();
                getPalavra()->setsentenca(vecsentenca);
                map.insert({i->getpalavra(), getPalavra()});
            }
        }
    }

    // for (const auto &par : map)
    // {
    //     cout << "CHAVE:" << par.first <<endl;
    //     for(const auto& j:par.second->getsentenca()){
    //         cout<< "Valor: " << j<<" "<< endl;
    //     }
    // }
    cout << "Paragrafos:" << paragrafos - 1 << endl;
    cout << "Linhas:" << contadorlinhas << endl;
    cout << "Senteças:" << sentenca << endl;
    arq.close();
}
