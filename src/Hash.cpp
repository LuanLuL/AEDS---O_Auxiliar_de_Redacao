#include "Hash.hpp"
/******************************************************************* CONSTRUTORES AND DESTRUTORES*/
Hash::Hash()
{
    unordered_map<string, Palavra *> map;
    this->p = new Palavra();
    this->para = new Para();
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

string Hash::M_ac_to_m_ac(string subs)
{
    for (int i = 0; i < int(subs.length()); i++)
    {
        if (int(subs[i]) == -61)
        {
            if (int(subs[i + 1]) == -128 || int(subs[i + 1]) <= -125)
            { // A
                if (int(subs[i + 1]) == -128)
                {
                    subs.replace(i, 2, "à");
                }
                else if (int(subs[i + 1]) == -127)
                {
                    subs.replace(i, 2, "á");
                }
                else if (int(subs[i + 1]) == -126)
                {
                    subs.replace(i, 2, "â");
                }
                else if (int(subs[i + 1]) == -125)
                {
                    subs.replace(i, 2, "ã");
                }
            }
            else if (int(subs[i + 1]) == -118 || int(subs[i + 1]) == -119)
            { // E
                if (int(subs[i + 1]) == -118)
                {
                    subs.replace(i, 2, "ê");
                }
                else if (int(subs[i + 1]) == -119)
                {
                    cout << subs << endl;
                    subs.replace(i, 2, "é");
                }
            }
            else if (int(subs[i + 1]) == -115)
            { // I
                subs.replace(i, 2, "í");
            }
            else if (int(subs[i + 1]) <= -107 && int(subs[i + 1]) >= -109)
            { // O
                if (int(subs[i + 1]) == -107)
                {
                    subs.replace(i, 2, "õ");
                }
                else if (int(subs[i + 1]) == -108)
                {
                    subs.replace(i, 2, "ô");
                }
                else if (int(subs[i + 1]) == -109)
                {
                    subs.replace(i, 2, "ó");
                }
            }
            else if (int(subs[i + 1]) == -100 || int(subs[i + 1]) == -102)
            {//U
                if (int(subs[i + 1]) == -100)
                {
                    subs.replace(i, 2, "ú");
                }
                else if (int(subs[i + 1]) == -102)
                {
                    subs.replace(i, 2, "ü");
                }
            }
        }
    }
    return subs;
}

vector<Palavra *> Hash::retorna_vetor(char *separa_linha)
{
    int sentenca = 1;
    vector<string> palavras, sentencas_separadas;
    vector<Palavra *> vetorpassado;
    string a;
    char *palavra, *palavra2;
    palavra = strtok(separa_linha, ".!?");
    while (palavra != nullptr)
    {
        a = palavra;
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
        palavra2 = strtok(palavra, ",;-\"° :_");
        while (palavra2 != nullptr)
        {
            // A=-127,-128,-126,125´`^~//E=-118 e-119^´//I=-115´//O=-107 a -109~^´//U=-100 e-102´ e bagulho
            string subs = palavra2;
            subs = M_ac_to_m_ac(subs);
            strcpy(palavra2, subs.c_str());
            Palavra *p = new Palavra();
            setPalavra(p);
            vector<int> vec = getPalavra()->getnumsentenca();
            vec.push_back(i + 1);
            getPalavra()->setnumsentenca(vec);
            getPalavra()->setpalavra(palavra2);
            vetorpassado.push_back(getPalavra());
            sentencas_separadas.push_back(palavra2);
            palavra2 = strtok(nullptr, ",;-\"° :_");
        }
    }
    return vetorpassado;
}

/// @brief Função responsável por ler o arquivo e armazenar todas as palavras no vector map
/// @param arq ponteiro do tipo ifstream
void Hash::learquivo(ifstream &arq)
{
    string linha, paragrafo = "";
    short int paragrafos = 0, contadorlinhas = 0, contadorcomeco = 0;
    vector<Palavra *> vet;
    vector<string> vectorordenado;
    Palavra *p;
    arq.open("dataset/DomCasmurro.txt");
    while (getline(arq, linha))
    {
        if (linha.empty() == false)
        {
            paragrafo = paragrafo + " " + linha;
        }
        else
        {
            this->para = new Para();
            setPara(para);
            paragrafos++;
            transform(paragrafo.begin(), paragrafo.end(), paragrafo.begin(), ::tolower);
            if (paragrafos == 1)
            {
                getPara()->setnumfim(contadorlinhas);
                getPara()->setnuminicio((contadorlinhas - contadorcomeco) + 1);
            }
            else
            {
                getPara()->setnumfim(contadorlinhas);
                getPara()->setnuminicio((contadorlinhas - contadorcomeco) + 2);
            }
            // cout<<paragrafo<<endl;
            char *separa_linha = new char[paragrafo.length() + 1];
            contadorcomeco = 0;
            strcpy(separa_linha, paragrafo.c_str());
            vet = retorna_vetor(separa_linha);
            paragrafo = "";
            for (const auto &i : vet)
            {
                if (this->map.find(i->getpalavra()) != this->map.end())
                {
                    // cout<<"\nAAA\n"<<endl;
                    // cout<<i->getnumsentenca()[0]<<endl;
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
        this->para = new Para();
        setPara(para);
        paragrafos++;
        if (paragrafos == 1)
        {
            getPara()->setnumfim(contadorlinhas);
            getPara()->setnuminicio((contadorlinhas - contadorcomeco) + 1);
        }
        else
        {
            getPara()->setnumfim(contadorlinhas);
            getPara()->setnuminicio((contadorlinhas - contadorcomeco) + 2);
        }
        // cout<<paragrafo<<endl;
        char *separa_linha = new char[paragrafo.length() + 1];
        contadorcomeco = 0;
        strcpy(separa_linha, paragrafo.c_str());
        vet = retorna_vetor(separa_linha);
        paragrafo = "";
        for (const auto &i : vet)
        {
            if (this->map.find(i->getpalavra()) != this->map.end())
            {
                // cout<<"\nAAA\n"<<endl;
                // cout<<i->getnumsentenca()[0]<<endl;
                // this->map[i->getpalavra()]->setcontador(this->map[i->getpalavra()]->getcontador()+1);
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
                // getPalavra()->setcontador(1);
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

    // for (const auto &par : this->map)
    // {
    // cout  << par.first<<" ";
    // for(int j=0;j<int(par.second->getnumsentenca().size());j++){
    //     cout<< "Sentença: " << par.second->getnumsentenca()[j]<<" Paragrafo: "<< par.second->getparagrafo()[j]<<" Tamanho:"<<par.second->getparagrafo().size()<< endl;
    // }
    // }
    // cout << "Paragrafos:" << paragrafos << endl;
    // cout << "Linhas:" << contadorlinhas << endl;
    arq.close();
}

/// @brief Essa função mostra todos os valores contidos em um vector
/// @param map vector com elementos do tipo string
void ShowWords(vector<string> map)
{
    int counter = 0;
    for (const auto &word : map)
    {
        counter++;
        cout << word << " ";
        if (counter % 20 == 0)
            cout << endl;
    }
}

// unsigned char accentRemover(unsigned char c)
// {
//     static std::locale mirror;

//     char newChar;

//     if(std::isalpha(c, mirror))
//     {

//         if(c == 'À' || c == 'Á' || c == 'Ã' || c == 'Â')
//             c = 'a';

//         else if(c == 'É' || c == 'Ê')
//             c = 'e';

//         else if(c == 'Í')
//             c = 'i';

//         else if(c == 'Ó' || c == 'Ô' || c == 'Õ')
//             c = 'o';

//         else if(c == 'Ú' || c == 'Ü')
//             c = 'u';

//         c = std::tolower(c, mirror);
//     }

//     else return c;
// }

/// @brief Essa função cria um vector com todas as palavras de map estando ordenadas com todas as suas letras sem acento minúsculas
void Hash::AlphaOrder()
{
    vector<string> vectorordenado;

    // Inserindo palavras no vetor:
    for (const auto &par : this->map)
    {
        vectorordenado.push_back(par.first);
    }

    // Convertendo letras maiúsculas para minúsculas:
    for (string &par : vectorordenado)
    {
        std::transform(par.begin(), par.end(), par.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
    }

    // Ordenando palavras:
    std::sort(vectorordenado.begin(), vectorordenado.end());

    // Mostrando palavras:
    ShowWords(vectorordenado);
}

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