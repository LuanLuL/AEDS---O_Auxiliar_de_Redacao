#include "Hash.hpp"
/******** CONSTRUTORES AND DESTRUTORES*/

Hash::Hash()
{
    unordered_map<string, Palavra *> map;
    this->p = new Palavra();
    this->para = new Para();
    this->map = map;
    this->linha = 0;
    pacote.resize(15);
    separastopwords();
}
stringstream ssparagrafo;
/********* GETTERS AND SETTERS */
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
/*********** METODOS */

/// @brief Função que converte caracteres Maiúsculos acentuados em Minúsculos acentudados dentro de uma string
/// @param bigAccentString string que precisa de ter seus caracteres maiúsculos acentuados convertidos para minúsculos acentuados
/// @return uma string que contém apenas caracteres minúsculos acentuados
string Hash::UpperToLowerAccent(string bigAccentString)
{
    for (int i = 0; i < int(bigAccentString.length()); i++)
    {
        if (int(bigAccentString[i]) == -61)
        {
            if (int(bigAccentString[i + 1]) == -128 || int(bigAccentString[i + 1]) <= -125)
            { // A
                if (int(bigAccentString[i + 1]) == -128)
                {
                    bigAccentString.replace(i, 2, "à");
                }
                else if (int(bigAccentString[i + 1]) == -127)
                {
                    bigAccentString.replace(i, 2, "á");
                }
                else if (int(bigAccentString[i + 1]) == -126)
                {
                    bigAccentString.replace(i, 2, "â");
                }
                else if (int(bigAccentString[i + 1]) == -125)
                {
                    bigAccentString.replace(i, 2, "ã");
                }
            }
            else if (int(bigAccentString[i + 1]) == -118 || int(bigAccentString[i + 1]) == -119)
            { // E
                if (int(bigAccentString[i + 1]) == -118)
                {
                    bigAccentString.replace(i, 2, "ê");
                }
                else if (int(bigAccentString[i + 1]) == -119)
                {
                    bigAccentString.replace(i, 2, "é");
                }
            }
            else if (int(bigAccentString[i + 1]) == -115)
            { // I
                bigAccentString.replace(i, 2, "í");
            }
            else if (int(bigAccentString[i + 1]) <= -107 && int(bigAccentString[i + 1]) >= -109)
            { // O
                if (int(bigAccentString[i + 1]) == -107)
                {
                    bigAccentString.replace(i, 2, "õ");
                }
                else if (int(bigAccentString[i + 1]) == -108)
                {
                    bigAccentString.replace(i, 2, "ô");
                }
                else if (int(bigAccentString[i + 1]) == -109)
                {
                    bigAccentString.replace(i, 2, "ó");
                }
            }
            else if (int(bigAccentString[i + 1]) == -100 || int(bigAccentString[i + 1]) == -102)
            { // U
                if (int(bigAccentString[i + 1]) == -100)
                {
                    bigAccentString.replace(i, 2, "ü");
                }
                else if (int(bigAccentString[i + 1]) == -102)
                {
                    bigAccentString.replace(i, 2, "ú");
                }
            }
        }
    }
    if (int(bigAccentString[0]) == 45 && int(bigAccentString[1]) == 45)
    {
        bigAccentString.replace(0, 2, "");
    }
    else if (int(bigAccentString[1]) == 45 && int(bigAccentString[2]) == 45)
    {
        bigAccentString.replace(1, 2, "");
    }
    return bigAccentString;
}

vector<Palavra *> Hash::retorna_vetor(char *separa_linha)
{
    int sentenca = 1, caracterelinha, posicaoparagrafo = 1;
    this->linha++;
    unordered_map<string, Palavra *> vecaaaa;
    vector<string> palavras, vecsentencasembarra;
    vector<Palavra *> vetorpassado;
    string a;
    char *palavra, *palavra2;
    palavra = strtok(separa_linha, ".!?");
    while (palavra != nullptr)
    {
        a = palavra;
        // cout<<palavra<<endl;
        if (a.length() != 1 && (a!="  " && a!="   " && a!= "    "))
        {
            sentenca++;
            palavras.push_back(palavra);
        }
        palavra = strtok(nullptr, ".!?");
    }
    for (int i = 0; i < int(palavras.size()); i++)
    {
        int posicaonasentenca = 1;
        palavra = new char[palavras[i].length() + 1];
        strcpy(palavra, palavras[i].c_str());
        palavra2 = strtok(palavra, ",;\"°() :");
        string sentencasembarra = "";
        while (palavra2 != nullptr)
        {
            string subs = palavra2, subs2;
            subs = UpperToLowerAccent(subs);
            strcpy(palavra2, subs.c_str());
            if ((subs.find("|") != string::npos))
            {
                caracterelinha = subs.find("|");
                subs2 = subs;
                subs.replace(caracterelinha, subs.length() - caracterelinha, "");
                if (subs.length() >= 2)
                {
                    Palavra *p = new Palavra();
                    setPalavra(p);
                    string vecparagrafos = getPalavra()->getparagrafo();
                    vecparagrafos = to_string(paragrafosglobal);
                    string linhadeocorrencia = to_string(linha);
                    string vec;
                    vec = to_string(i + 1);
                    vector<int> posicaonoparagrafovec = getPalavra()->getposparagrafo();
                    posicaonoparagrafovec.push_back(posicaoparagrafo);
                    posicaoparagrafo++;
                    vector<int> posicaonasentencavec = getPalavra()->getpossentenca();
                    posicaonasentencavec.push_back(posicaonasentenca);
                    posicaonasentenca++;
                    getPalavra()->setcont(getPalavra()->getcont() + 1);
                    getPalavra()->setposparagrafo(posicaonoparagrafovec);
                    getPalavra()->setpossentenca(posicaonasentencavec);
                    getPalavra()->setparagrafo(vecparagrafos);
                    getPalavra()->setnumsentenca(vec);
                    getPalavra()->setpalavra(subs);
                    getPalavra()->setlinhaocorrencia(linhadeocorrencia);
                    vetorpassado.push_back(getPalavra());

                    if (vecaaaa.find(getPalavra()->getpalavra()) != vecaaaa.end())
                    {
                        Palavra *novo_p = new Palavra;
                        novo_p->setposparagrafo(p->getposparagrafo());
                        novo_p->setpossentenca(p->getpossentenca());
                        novo_p->setnumsentenca(p->getnumsentenca());
                        novo_p->setlinhaocorrencia(p->getlinhaocorrencia());
                        novo_p->setcont(p->getcont());
                        novo_p->setpalavra(p->getpalavra());
                        string vecsentenca = vecaaaa[novo_p->getpalavra()]->getnumsentenca();
                        vecsentenca += " " + novo_p->getnumsentenca();
                        string linhadeocorrencia = vecaaaa[novo_p->getpalavra()]->getlinhaocorrencia();
                        linhadeocorrencia += " " + to_string(linha);
                        vecaaaa[novo_p->getpalavra()]->setcont(vecaaaa[novo_p->getpalavra()]->getcont() + 1);
                        vector<int> vecpossentenca = vecaaaa[novo_p->getpalavra()]->getpossentenca();
                        vecpossentenca.push_back(novo_p->getpossentenca()[0]);
                        vector<int> vecposparagrafo = vecaaaa[novo_p->getpalavra()]->getposparagrafo();
                        vecposparagrafo.push_back(novo_p->getposparagrafo()[0]);
                        vecaaaa[novo_p->getpalavra()]->setposparagrafo(vecposparagrafo);
                        vecaaaa[novo_p->getpalavra()]->setpossentenca(vecpossentenca);
                        vecaaaa[novo_p->getpalavra()]->setnumsentenca(vecsentenca);
                        vecaaaa[novo_p->getpalavra()]->setlinhaocorrencia(linhadeocorrencia);
                    }
                    // Caso não ele só acrescenta a palavra na Hash:
                    else
                    {
                        Palavra *novo_p = new Palavra;
                        novo_p->setposparagrafo(p->getposparagrafo());
                        novo_p->setpossentenca(p->getpossentenca());
                        novo_p->setnumsentenca(p->getnumsentenca());
                        novo_p->setlinhaocorrencia(p->getlinhaocorrencia());
                        novo_p->setcont(p->getcont());
                        novo_p->setpalavra(p->getpalavra());
                        vecaaaa.insert({novo_p->getpalavra(), novo_p});
                    }
                    this->linha++;
                    if (sentencasembarra == "")
                    {
                        sentencasembarra = subs;
                    }
                    else
                    {
                        sentencasembarra = sentencasembarra + " " + subs;
                    }
                    subs2.replace(0, caracterelinha + 1, "");
                    strcpy(palavra2, subs2.c_str());
                }
                else
                {
                    subs2.replace(0, caracterelinha + 1, "");
                    strcpy(palavra2, subs2.c_str());
                    this->linha++;
                }
            }
            Palavra *p = new Palavra();
            setPalavra(p);
            string vecparagrafos = getPalavra()->getparagrafo();
            vecparagrafos = to_string(paragrafosglobal);
            string vec;
            vec = to_string(i + 1);
            vector<int> posicaonoparagrafovec = getPalavra()->getposparagrafo();
            posicaonoparagrafovec.push_back(posicaoparagrafo);
            posicaoparagrafo++;
            vector<int> posicaonasentencavec = getPalavra()->getpossentenca();
            posicaonasentencavec.push_back(posicaonasentenca);
            posicaonasentenca++;
            getPalavra()->setposparagrafo(posicaonoparagrafovec);
            getPalavra()->setpossentenca(posicaonasentencavec);
            string linhadeocorrencia = to_string(linha);
            getPalavra()->setcont(getPalavra()->getcont() + 1);
            getPalavra()->setnumsentenca(vec);
            getPalavra()->setpalavra(palavra2);
            getPalavra()->setparagrafo(vecparagrafos);
            getPalavra()->setlinhaocorrencia(linhadeocorrencia);
            vetorpassado.push_back(getPalavra());
            if (vecaaaa.find(getPalavra()->getpalavra()) != vecaaaa.end())
            {
                Palavra *novo_p = new Palavra;
                novo_p->setposparagrafo(p->getposparagrafo());
                novo_p->setpossentenca(p->getpossentenca());
                novo_p->setnumsentenca(p->getnumsentenca());
                novo_p->setlinhaocorrencia(p->getlinhaocorrencia());
                novo_p->setcont(p->getcont());
                novo_p->setpalavra(p->getpalavra());
                string vecsentenca = vecaaaa[novo_p->getpalavra()]->getnumsentenca();
                vecsentenca += " " + novo_p->getnumsentenca();
                string linhadeocorrencia = vecaaaa[novo_p->getpalavra()]->getlinhaocorrencia();
                linhadeocorrencia += " " + to_string(linha);
                vecaaaa[novo_p->getpalavra()]->setcont(vecaaaa[novo_p->getpalavra()]->getcont() + 1);
                vector<int> vecpossentenca = vecaaaa[novo_p->getpalavra()]->getpossentenca();
                vecpossentenca.push_back(novo_p->getpossentenca()[0]);
                vector<int> vecposparagrafo = vecaaaa[novo_p->getpalavra()]->getposparagrafo();
                vecposparagrafo.push_back(novo_p->getposparagrafo()[0]);
                vecaaaa[novo_p->getpalavra()]->setposparagrafo(vecposparagrafo);
                vecaaaa[novo_p->getpalavra()]->setpossentenca(vecpossentenca);
                vecaaaa[novo_p->getpalavra()]->setnumsentenca(vecsentenca);
                vecaaaa[novo_p->getpalavra()]->setlinhaocorrencia(linhadeocorrencia);
            }
            // Caso não ele só acrescenta a palavra na Hash:
            else
            {
                Palavra *novo_p = new Palavra;
                novo_p->setposparagrafo(p->getposparagrafo());
                novo_p->setpossentenca(p->getpossentenca());
                novo_p->setnumsentenca(p->getnumsentenca());
                novo_p->setlinhaocorrencia(p->getlinhaocorrencia());
                novo_p->setcont(p->getcont());
                novo_p->setpalavra(p->getpalavra());
                vecaaaa.insert({novo_p->getpalavra(), novo_p});
            }
            if (sentencasembarra == "")
            {
                sentencasembarra = subs;
            }
            else
            {
                sentencasembarra = sentencasembarra + " " + palavra2;
            }
            palavra2 = strtok(nullptr, ",;\"°() :");
        }
        vecsentencasembarra.push_back(sentencasembarra);
    }
    getPara()->setnumsentenca(sentenca - 1);
    getPara()->setsentenca(vecsentencasembarra);
    getPara()->setvecpalavra(vecaaaa);
    vector<string> ordenadohash;
    for (const auto &i : vecaaaa)
    {
        ordenadohash.push_back(i.first);
    }
    ssparagrafo << "\n________________________________________________________________________________________________________________________________________________________________________________________________________________\n"
                << left << setw(30) << "WORD" << setw(30) << "PARAGRAPH" << setw(30) << "SENTENCE" << setw(30) << "LINE" << setw(30) << "APPEARANCES" << setw(30) << "POSITIONS"
                << "DISTANCE\n"
                << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    // MedeDistancia(vetorParagrafos[i]->getpalavras(),i,ssparagrafo);
    for (int j = 0; j < ordenadohash.size(); j++)
    {
        if (stopwords(ordenadohash[j]) == false && ordenadohash[j] != "")
        {
            ssparagrafo << setw(30) << ordenadohash[j] << setw(30) << paragrafosglobal;
            ssparagrafo << " " << vecaaaa[ordenadohash[j]]->getnumsentenca();
            ssparagrafo << setw(30);
            ssparagrafo << " " << vecaaaa[ordenadohash[j]]->getlinhaocorrencia();
            ssparagrafo << setw(30) << " " << vecaaaa[ordenadohash[j]]->getcont() << setw(30);
            for (int k = 0; k < int(vecaaaa[ordenadohash[j]]->getposparagrafo().size()); k++)
            {
                ssparagrafo << " " << vecaaaa[ordenadohash[j]]->getposparagrafo()[k];
            }
            ssparagrafo << setw(30) << "\t";
            short int inicio = 0;
            short int fim = 1;
            short int tamanho = 0;
            short int distancia = 0;
            tamanho = int(vecaaaa[ordenadohash[j]]->getposparagrafo().size());
            inicio = 0;
            fim = 1;
            while (fim < tamanho)
            {
                distancia = int(vecaaaa[ordenadohash[j]]->getposparagrafo()[fim]) - int(vecaaaa[ordenadohash[j]]->getposparagrafo()[inicio]);
                // cout << "Distância:" << distancia << "\n\n";
                ssparagrafo << distancia << " ";
                fim = fim + 1;
            }
            ssparagrafo << "\n";
        }
    }
    ssparagrafo << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    getPara()->setpalavras(ordenadohash);
    vetorParagrafos.push_back(getPara());
    this->linha++;
    return vetorpassado;
}

/// @brief Função responsável por ler o arquivo e armazenar todas as palavras no vector map
/// @param arq ponteiro do tipo ifstream
void Hash::learquivo(ifstream &arq)
{
    string linha, paragrafo = "";
    short int paragrafos = 0, contadorlinhas = 0, contadorcomeco = 0;
    vector<Palavra *> vet;
    ssparagrafo << "====================\n=> PARTIAL RESULTS\n====================";
    vector<string> vectorordenado;
    Palavra *p;
    // *******************************************************************
    string linhaLUAN = "";
    ifstream arqExpressao("dataset/expressoes.txt");
    if (!arqExpressao)
    {
        throw "output3 ---> Não foi possível abrir o arquivo de entrada";
    }
    string expressao;
    vector<string> expressoes;
    while (getline(arqExpressao, expressao))
    {
        if (expressao.empty())
        {
            break;
        }
        expressoes.push_back(expressao);
    }
    arqExpressao.close();
    // Transforma para minusculo e coloca ' ' no inicio e no final de todas as expressões
    for (string &expressao : expressoes)
    {
        string addeSpace = " ";
        addeSpace += expressao + " ";
        expressao = addeSpace;
        transform(expressao.begin(), expressao.end(), expressao.begin(), ::tolower);
    }
    unordered_map<string, pair<int, vector<int>>> ocorrencias;
    // Inicializa o mapa com as expressões e suas ocorrências
    for (const string &expressao : expressoes)
    { // Loop (1)
        ocorrencias[expressao].first = 0;
    }
    // *******************************************************************
    arq.open("dataset/DomCasmurro.txt");
    while (getline(arq, linha))
    {
        if (linha.empty() == false)
        {
            // *******************************************************************
            linhaLUAN = transforme(linha);
            // Percorre cada expressão
            for (size_t i = 0; i < expressoes.size(); i++)
            {
                size_t pos = linhaLUAN.find(expressoes[i]);
                // Verifica se a expressão ocorre na linha
                while (pos != string::npos)
                {
                    ocorrencias[expressoes[i]].first++;                              // Incrementa o número de ocorrências
                    ocorrencias[expressoes[i]].second.push_back(contadorlinhas + 1); // Armazena o número da linha
                    pos = linhaLUAN.find(expressoes[i], pos + 1);                    // Procura por outras ocorrências na mesma linha
                }
            }

            // *******************************************************************
            if (paragrafo != "")
                paragrafo = paragrafo + "|" + linha;
            else
                paragrafo = linha;
        }
        else
        {
            paragrafosglobal++;
            this->para = new Para();
            setPara(para);
            paragrafos++;
            transform(paragrafo.begin(), paragrafo.end(), paragrafo.begin(), ::tolower);
            // cout<<paragrafo<<endl;
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
            // cout<<separa_linha<<endl;
            vet = retorna_vetor(separa_linha);
            paragrafo = "";
            for (const auto &i : vet)
            {
                // Se map já possui a palavra lida ele retorna a palavra, se não ele retorna ponteiro null:
                //  Caso essa palavra for diferente de um ponteiro nulo entro no if
                if (this->map.find(i->getpalavra()) != this->map.end())
                {
                    // cout<<i->getpalavra()<<endl;
                    string vecparagrafos = this->map[i->getpalavra()]->getparagrafo();
                    vecparagrafos += " " + i->getparagrafo();
                    this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                    this->map[i->getpalavra()]->setcont(this->map[i->getpalavra()]->getcont() + 1);
                    string vecsentenca = this->map[i->getpalavra()]->getnumsentenca();
                    vecsentenca += " " + i->getnumsentenca();
                    string veclinha = this->map[i->getpalavra()]->getlinhaocorrencia();
                    veclinha += " " + i->getlinhaocorrencia();
                    vector<int> vecpossentenca = this->map[i->getpalavra()]->getpossentenca();
                    vecpossentenca.push_back(i->getpossentenca()[0]);
                    vector<int> vecposparagrafo = this->map[i->getpalavra()]->getposparagrafo();
                    vecposparagrafo.push_back(i->getposparagrafo()[0]);
                    this->map[i->getpalavra()]->setposparagrafo(vecposparagrafo);
                    this->map[i->getpalavra()]->setpossentenca(vecpossentenca);
                    this->map[i->getpalavra()]->setnumsentenca(vecsentenca);
                    this->map[i->getpalavra()]->setlinhaocorrencia(veclinha);
                }
                // Caso não ele só acrescenta a palavra na Hash:
                else
                {
                    // cout<<i->getpalavra()<<endl;
                    Palavra *p = new Palavra();
                    setPalavra(p);
                    getPalavra()->setcont(getPalavra()->getcont() + 1);
                    getPalavra()->setpalavra(i->getpalavra());
                    string vecparagrafos = getPalavra()->getparagrafo();
                    vecparagrafos = to_string(paragrafosglobal);
                    getPalavra()->setparagrafo(vecparagrafos);
                    string vecsentenca;
                    vecsentenca = i->getnumsentenca();
                    getPalavra()->setnumsentenca(vecsentenca);
                    string veclinha;
                    veclinha = i->getlinhaocorrencia();
                    getPalavra()->setlinhaocorrencia(veclinha);
                    vector<int> vecpossentenca;
                    vecpossentenca.push_back(i->getpossentenca()[0]);
                    getPalavra()->setpossentenca(vecpossentenca);
                    vector<int> vecposparagrafo;
                    vecposparagrafo.push_back(i->getposparagrafo()[0]);
                    getPalavra()->setposparagrafo(vecposparagrafo);
                    this->map.insert({i->getpalavra(), getPalavra()});
                }
            }
        }
        contadorcomeco++;
        contadorlinhas++;
    }
    if (paragrafo != "")
    {
        this->para = new Para();
        transform(paragrafo.begin(), paragrafo.end(), paragrafo.begin(), ::tolower);
        setPara(para);
        paragrafos++;
        paragrafosglobal++;
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
                string vecparagrafos = this->map[i->getpalavra()]->getparagrafo();
                vecparagrafos += " " + i->getparagrafo();
                this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                this->map[i->getpalavra()]->setcont(this->map[i->getpalavra()]->getcont() + 1);
                string vecsentenca = this->map[i->getpalavra()]->getnumsentenca();
                vecsentenca += " " + i->getnumsentenca();
                string veclinha = this->map[i->getpalavra()]->getlinhaocorrencia();
                veclinha += " " + i->getlinhaocorrencia();
                vector<int> vecpossentenca = this->map[i->getpalavra()]->getpossentenca();
                vecpossentenca.push_back(i->getpossentenca()[0]);
                vector<int> vecposparagrafo = this->map[i->getpalavra()]->getposparagrafo();
                vecposparagrafo.push_back(i->getposparagrafo()[0]);
                this->map[i->getpalavra()]->setposparagrafo(vecposparagrafo);
                this->map[i->getpalavra()]->setpossentenca(vecpossentenca);
                this->map[i->getpalavra()]->setnumsentenca(vecsentenca);
                this->map[i->getpalavra()]->setlinhaocorrencia(veclinha);
            }
            else
            {
                Palavra *p = new Palavra();
                setPalavra(p);
                getPalavra()->setcont(getPalavra()->getcont() + 1);
                getPalavra()->setpalavra(i->getpalavra());
                string vecparagrafos = getPalavra()->getparagrafo();
                vecparagrafos = to_string(paragrafos);
                getPalavra()->setparagrafo(vecparagrafos);
                string vecsentenca;
                vecsentenca = i->getnumsentenca();
                getPalavra()->setnumsentenca(vecsentenca);
                string veclinha;
                veclinha = i->getlinhaocorrencia();
                getPalavra()->setlinhaocorrencia(veclinha);
                vector<int> vecpossentenca;
                vecpossentenca.push_back(i->getpossentenca()[0]);
                getPalavra()->setpossentenca(vecpossentenca);
                vector<int> vecposparagrafo;
                vecposparagrafo.push_back(i->getposparagrafo()[0]);
                getPalavra()->setposparagrafo(vecposparagrafo);
                this->map.insert({i->getpalavra(), getPalavra()});
            }
        }
    }
    arq.close();
    AlphaOrder(&ocorrencias);
}
/// @brief Essa função cria um vector com todas as palavras de map estando ordenadas com todas as suas letras sem acento minúsculas
void Hash::AlphaOrder(unordered_map<string, pair<int, vector<int>>> *texto)
{
    vector<string> vectorordenado;
    // Inserindo palavras no vetor:
    for (const auto &par : this->map)
    {
        vectorordenado.push_back(par.first);
    }
    // Ordenando palavras:
    std::sort(vectorordenado.begin(), vectorordenado.end());
    int cont = 0;
    string palavramaior;
    // for(const auto& i:vectorordenado){
    //     if(cont<map[i]->getparagrafo().size()){
    //         cont=map[i]->getparagrafo().size();
    //         palavramaior=map[i]->getpalavra();
    //     }
    // }
    ofstream file2("dataset/Resultados1.data", std::ios::out | std::ios::binary);
    // string nome = "dataset/Resultados1.data";
    // file2.open(nome);
    stringstream ss;
    // char buffer[4096];
    // file2.rdbuf()->pubsetbuf(buffer, sizeof(buffer));
    ss << "================\n=> FULL RESULTS\n================\n";
    ss << "______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n";
    ss << "WORD " << setw(30) << "APPEARANCES" << setw(32) << "LINES" << setw(96) << "SENTENCES" << setw(95) << "PARAGRAPHS" << setw(100) << "POSITION\n"
       << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (const auto &i : vectorordenado)
    {
        if (i.length() >= 1 && stopwords(i) == false)
        {
            ss << left << setw(30) << i << "\t" << left << setw(30) << map[i]->getcont() << "\t";
            palavramaior = "";
            cont = 0;
            ss << left << " " << map[i]->getlinhaocorrencia();
            // palavramaior=palavramaior+to_string(map[i]->getlinhaocorrencia());
            ss << setw(90 - (int(palavramaior.length()) + (cont + 1))) << "\t";
            ss << left << " " << map[i]->getnumsentenca();
            ss << setw(90) << "\t";
            ss << " " << map[i]->getparagrafo();
            ss << setw(90);
            for (unsigned long int j = 0; j < map[i]->getposparagrafo().size(); j++)
            {
                ss << " " << map[i]->getposparagrafo()[j];
            }
            ss << "\t\n";
        }
    }
    ss << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
       << "====================================================\n=> LINE NUMBER THAT START AND FINISH EACH PARAGRAPH \n====================================================\n"
       << "_____________________________________________________________________\n"
       << setw(20) << "PARAGRAPH" << setw(20) << "START"
       << "FINISH \n"
       << "---------------------------------------------------------------------\n";
    for (int i = 0; i < vetorParagrafos.size(); i++)
    {
        ss << setw(20) << i + 1 << setw(20) << this->vetorParagrafos[i]->getnuminicio() << setw(20) << this->vetorParagrafos[i]->getnumfim() << "\n";
    }
    ss << "---------------------------------------------------------------------\n\n"
       << "================================================================\n=> NUMBER OF WORDS IN EACH SENTENCE WITH AND WITHOUT STOP WORDS\n================================================================\n"
       << "_____________________________________________________________________________________________________________________\n"
       << left << setw(30) << "PARAGRAPH\t" << setw(28) << "SENTENCE\t" << setw(28) << "WITH STOP WORDS\t"
       << "WITHOUT STOP WORDS\n"
       << "---------------------------------------------------------------------------------------------------------------------\n";
    for (int a = 0; a < int(vetorParagrafos.size()); a++)
    {
        for (int b = 0; b < int(vetorParagrafos[a]->getsentenca().size()); b++)
        {

            string palavra_aux;
            stringstream sentenca_aux;
            sentenca_aux << vetorParagrafos[a]->getsentenca()[b];

            while (sentenca_aux >> palavra_aux)
            {
                if (stopwords(palavra_aux) == true)
                {
                    contstopwords++;
                }
                contpalavras++;
            }

            ss << left << setw(30) << a + 1 << "\t" << left << setw(30) << b + 1 << "\t" << left << setw(30) << contpalavras << "\t" << left << setw(30) << (contpalavras - contstopwords) << "\n";
            contpalavras = 0;
            contstopwords = 0;
        }
    }
    ss << "---------------------------------------------------------------------\n\n";
    // **********************************************************************
    ss << "==========================\n=> SEARCH FOR EXPRESSIONS\n==========================\n"
       << "_____________________________________________________\n"
       << left << setw(20) << "EXPRESSION" << setw(20) << "APPEARANCES"
       << "LINE\n"
       << "-----------------------------------------------------\n";
    for (const auto &ocorrencia : (*texto))
    {
        if (ocorrencia.second.first >= 1)
        {
            ss << left << setw(20) << ocorrencia.first.substr(0, ocorrencia.first.length() - 1) << setw(20) << ocorrencia.second.first;
            for (size_t i = 0; i < ocorrencia.second.second.size(); ++i)
            {
                ss << ocorrencia.second.second[i];
                if (i != ocorrencia.second.second.size() - 1)
                {
                    ss << " ";
                }
            }
            ss << "\n";
        }
    }
    ss << "-----------------------------------------------------\n\n";
    // **********************************************************************
    // for(int i=0;i<vetorParagrafos.size();i++){
    //     ss << "\n________________________________________________________________________________________________________________________________________________________________________________________________________________\n"<< left << setw(30) << "WORD" << setw(30) << "PARAGRAPH" << setw(30) << "SENTENCE" << setw(30) << "LINE" << setw(30) << "APPEARANCES" << setw(30) << "POSITIONS" << "DISTANCE\n"<< "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    //     //MedeDistancia(vetorParagrafos[i]->getpalavras(),i,ss);
    //     for(int j=0;j<vetorParagrafos[i]->getpalavras().size();j++){
    //         if(stopwords(vetorParagrafos[i]->getpalavras()[j])==false && vetorParagrafos[i]->getpalavras()[j]!=""){
    //             ss<<setw(30)<<vetorParagrafos[i]->getpalavras()[j]<<setw(30)<<i+1;
    //             ss<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getnumsentenca();
    //             ss<<setw(30);
    //             ss<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getlinhaocorrencia();
    //             ss<<setw(30)<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getcont()<<setw(30);
    //             for(int k=0;k<int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo().size());k++){
    //                 ss<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[k];
    //             }
    //             ss<<setw(30)<<"\t";
    //             short int inicio = 0;
    //             short int fim = 1;
    //             short int tamanho = 0;
    //             short int distancia = 0;
    //             tamanho = int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo().size());
    //             inicio = 0;
    //             fim = 1;
    //             while(fim<tamanho)
    //             {
    //                 distancia = int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[fim])-int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[inicio]);
    //                 // cout << "Distância:" << distancia << "\n\n";
    //                 ss<<distancia<<" ";
    //                 fim=fim+1;
    //             }
    //             ss<<"\n";
    //         }
    //     }
    //     ss<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    // }
    ss << ssparagrafo.str();
    file2 << ss.str();
    file2.close();
}

// identificação stopwords
bool Hash::stopwords(string palavra)
{

    ifstream arq("dataset/stopwords.txt");
    string stopword;

    if (arq.is_open())
    {
        if (int(palavra.size()) == 1)
        {
            for (int i = 0; i < int(pacote[0].size()); i++)
            {
                if (palavra == pacote[0][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 2)
        {
            for (int i = 0; i < int(pacote[1].size()); i++)
            {
                if (palavra == pacote[1][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 3)
        {
            for (int i = 0; i < int(pacote[2].size()); i++)
            {
                if (palavra == pacote[2][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 4)
        {
            for (int i = 0; i < int(pacote[3].size()); i++)
            {
                if (palavra == pacote[3][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 5)
        {
            for (int i = 0; i < int(pacote[4].size()); i++)
            {
                if (palavra == pacote[4][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 6)
        {
            for (int i = 0; i < int(pacote[5].size()); i++)
            {
                if (palavra == pacote[5][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 7)
        {
            for (int i = 0; i < int(pacote[6].size()); i++)
            {
                if (palavra == pacote[6][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 8)
        {
            for (int i = 0; i < int(pacote[7].size()); i++)
            {
                if (palavra == pacote[7][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 9)
        {
            for (int i = 0; i < int(pacote[8].size()); i++)
            {
                if (palavra == pacote[8][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 10)
        {
            for (int i = 0; i < int(pacote[9].size()); i++)
            {
                if (palavra == pacote[9][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 11)
        {
            for (int i = 0; i < int(pacote[10].size()); i++)
            {
                if (palavra == pacote[10][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 12)
        {
            for (int i = 0; i < int(pacote[11].size()); i++)
            {
                if (palavra == pacote[11][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 13)
        {
            for (int i = 0; i < int(pacote[12].size()); i++)
            {
                if (palavra == pacote[12][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 14)
        {
            for (int i = 0; i < int(pacote[13].size()); i++)
            {
                if (palavra == pacote[13][i])
                {
                    return true;
                }
            }
            return false;
        }
        else if (int(palavra.size()) == 15)
        {
            for (int i = 0; i < int(pacote[14].size()); i++)
            {
                if (palavra == pacote[14][i])
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
        arq.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
        return false;
    }
    return false;
}

void Hash::separastopwords()
{

    ifstream arq("dataset/stopwords.txt");
    string stopword;

    if (arq.is_open())
    {

        while (getline(arq, stopword))
        {
            if (stopword.size() == 1)
            {
                pacote[0].push_back(stopword);
            }
            else if (stopword.size() == 2)
            {
                pacote[1].push_back(stopword);
            }
            else if (stopword.size() == 3)
            {
                pacote[2].push_back(stopword);
            }
            else if (stopword.size() == 4)
            {
                pacote[3].push_back(stopword);
            }
             else if (stopword.size() == 5)
            {
                pacote[4].push_back(stopword);
            }
             else if (stopword.size() == 6)
            {
                pacote[5].push_back(stopword);
            }
             else if (stopword.size() == 7)
            {
                pacote[6].push_back(stopword);
            }
             else if (stopword.size() == 8)
            {
                pacote[7].push_back(stopword);
            }
             else if (stopword.size() == 9)
            {
                pacote[8].push_back(stopword);
            }
             else if (stopword.size() == 10)
            {
                pacote[9].push_back(stopword);
            }
             else if (stopword.size() == 11)
            {
                pacote[10].push_back(stopword);
            }
             else if (stopword.size() == 12)
            {
                pacote[11].push_back(stopword);
            }
            else if (stopword.size() == 13)
            {
            pacote[12].push_back(stopword);
            }
             else if (stopword.size() == 14)
            {
                pacote[13].push_back(stopword);
            }
             else if (stopword.size() == 15)
            {
                pacote[14].push_back(stopword);
            }
        }
        arq.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}

string Hash::transforme(string linha)
{
    char space = ' ';
    short int tam = linha.size();
    linha = " " + linha + " ";
    for (int i = 0; i <= tam; i++)
    {
        linha[i] = tolower(linha[i]);
        if (linha[i] == 44 || linha[i] == 63 || linha[i] == 33 || linha[i] == 59 || linha[i] == 248 || linha[i] == 92 || linha[i] == 40 || linha[i] == 41 || linha[i] == 34 || linha[i] == 58 || linha[i] == 46)
        {
            linha[i] = space;
        }
        else if (linha[i] == 45 && linha[i + 1] == 45)
        {
            linha[i + 1] = space;
        }
    }
    return linha;
}