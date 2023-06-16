#include "Hash.hpp"
/******************************************************************* CONSTRUTORES AND DESTRUTORES*/
Hash::Hash()
{
    unordered_map<string, Palavra *> map;
    this->p = new Palavra();
    this->para=new Para();
    this->map = map;
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
void Hash::setPara(Para *para)
{
    this->para = para;
}

Para *Hash::getPara()
{
    return this->para;
}


void Hash::setMap(unordered_map<string, Palavra *> map)
{
    this->map = map;
}

unordered_map<string, Palavra *> Hash::getMap()
{
    return this->map;
}
/*************************************************************************************** METODOS */



vector<Palavra *> Hash::retorna_vetor(char *separa_linha)
{
    int sentenca=1;
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
            vector<int> vec = getPalavra()->getnumsentenca();
            vec.push_back(i+1);
            getPalavra()->setnumsentenca(vec);
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
    string linha, paragrafo="";
    short int paragrafos = 0, contadorlinhas = 0,contadorcomeco=0;
    vector<Palavra *> vet;
    vector <string> vectorordenado;
    Palavra *p;
    cout<<getPara()->getnumfim()<<endl;
    arq.open("dataset/DomCasmurro.txt");
    while (getline(arq, linha))
    {
        if(linha.empty()==false)
        {
            paragrafo = paragrafo + " " + linha;
        }
        else
        {
            this->para=new Para();
            setPara(para);
            paragrafos++;
            if(paragrafos==1){
                getPara()->setnumfim(contadorlinhas);
                getPara()->setnuminicio((contadorlinhas-contadorcomeco)+1);
            }
            else{
                getPara()->setnumfim(contadorlinhas);
                getPara()->setnuminicio((contadorlinhas-contadorcomeco)+2);
            }
            cout<<"Fim: "<<getPara()->getnumfim()<<"inicio: "<<getPara()->getnuminicio()<<endl;
            // cout<<paragrafo<<endl;
            char *separa_linha = new char[paragrafo.length() + 1];
            contadorcomeco=0;
            strcpy(separa_linha, paragrafo.c_str());
            vet = retorna_vetor(separa_linha);
            paragrafo = "";
            for (const auto &i : vet)
            {
                if (this->map.find(i->getpalavra()) != this->map.end())
                {
                    // cout<<"\nAAA\n"<<endl;
                    //cout<<i->getnumsentenca()[0]<<endl;
                    vector<int> vecparagrafos = this->map[i->getpalavra()]->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = this->map[i->getpalavra()]->getnumsentenca();
                    vecsentenca.push_back(i->getnumsentenca()[0]);
                    this->map[i->getpalavra()]->setnumsentenca(vecsentenca);
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
                    vector<int> vecsentenca = i->getnumsentenca();
                    getPalavra()->setnumsentenca(vecsentenca);
                    this->map.insert({i->getpalavra(), getPalavra()});
                }
            }
        }
        contadorcomeco++;
        contadorlinhas++;
    }
    if (paragrafo != "")
    {
        // cout<<paragrafo<<endl;
        this->para=new Para();
        setPara(para);
        paragrafos++;
        if(paragrafos==1){
            getPara()->setnumfim(contadorlinhas);
            getPara()->setnuminicio((contadorlinhas-contadorcomeco)+1);
        }
        else{
            getPara()->setnumfim(contadorlinhas);
            getPara()->setnuminicio((contadorlinhas-contadorcomeco)+2);
        }
        cout<<"Fim: "<<getPara()->getnumfim()<<"inicio: "<<getPara()->getnuminicio()<<endl;
        // cout<<paragrafo<<endl;
        char *separa_linha = new char[paragrafo.length() + 1];
        contadorcomeco=0;
        strcpy(separa_linha, paragrafo.c_str());
        vet = retorna_vetor(separa_linha);
        paragrafo = "";
        for (const auto &i : vet)
        {
            if (this->map.find(i->getpalavra()) != this->map.end())
            {
                // cout<<"\nAAA\n"<<endl;
                //cout<<i->getnumsentenca()[0]<<endl;
                //this->map[i->getpalavra()]->setcontador(this->map[i->getpalavra()]->getcontador()+1);
                vector<int> vecparagrafos = this->map[i->getpalavra()]->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                vector<int> vecsentenca = this->map[i->getpalavra()]->getnumsentenca();
                vecsentenca.push_back(i->getnumsentenca()[0]);
                this->map[i->getpalavra()]->setnumsentenca(vecsentenca);
            }
            else
            {
                // cout<<" "<<i->getpalavra();
                p = new Palavra();
                setPalavra(p);
                //getPalavra()->setcontador(1);
                getPalavra()->setpalavra(i->getpalavra());
                vector<int> vecparagrafos = getPalavra()->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                getPalavra()->setparagrafo(vecparagrafos);
                vector<int> vecsentenca = i->getnumsentenca();
                getPalavra()->setnumsentenca(vecsentenca);
                this->map.insert({i->getpalavra(), getPalavra()});
            }
        }
    }

    for (const auto &par : this->map)
    {
        cout << "CHAVE:" << par.first <<endl;
        for(int j=0;j<int(par.second->getnumsentenca().size());j++){
            cout<< "Sentença: " << par.second->getnumsentenca()[j]<<" Paragrafo: "<< par.second->getparagrafo()[j]<<" Tamanho:"<<par.second->getparagrafo().size()<< endl;
        }
    }
    cout << "Paragrafos:" << paragrafos << endl;
    cout << "Linhas:" << contadorlinhas << endl;
    arq.close();

    for (const auto &par : this->map)
    {
        //cout << "CHAVE:" << par.first <<endl;
        vectorordenado.push_back(par.first);
    }

    std::sort(vectorordenado.begin(), vectorordenado.end());

    // Imprime as strings ordenadas
    for (const std::string& str : vectorordenado) {
        std::cout << str << endl;
    }

}

void Hash::ShowWords()
{
    for(const auto &word : this->map)
    {
        cout<<word.first<<endl;
    }
}

// AlphaOrder()
// {
//     if()
// }

/*void Hash::stopwords(string palavra){

    ifstream arq("dataset/stopwords.txt");
    string aux;
    if(arq.is_open()){

        while(a){
            
        }

        arq.close();
    }else{
        cout << "Não foi possível abrir o arquivo." << endl;
    
    }

    int tam = palavras.size();
     for (int i = 0; i < tam; i++) {
        cout << "Palavra " << i + 1 << ": " << palavras[i] << endl;
    }
}*/