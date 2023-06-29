#include "Hash.hpp"
/******** CONSTRUTORES AND DESTRUTORES*/

Hash::Hash()
{
    unordered_map<string, Palavra *> map;
    this->p = new Palavra();
    this->para = new Para();
    this->map = map;
    this->linha=0;
    pacote.resize(5);
    separastopwords();
    
}

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
    int sentenca = 1, caracterelinha,posicaoparagrafo=1;
    this->linha++;
    unordered_map<string,Palavra*> vecaaaa;
    vector<string> palavras, vecsentencasembarra;
    vector<Palavra *> vetorpassado;
    string a;
    char *palavra, *palavra2;
    palavra = strtok(separa_linha, ".!?");
    while (palavra != nullptr)
    {
        a = palavra;
        //cout<<palavra<<endl;
        if (a.length() != 1)
        {
            sentenca++;
        }
        palavras.push_back(palavra);
        palavra = strtok(nullptr, ".!?");
    }
    for (int i = 0; i < int(palavras.size()); i++)
    {
        int posicaonasentenca = 1;
        palavra = new char[palavras[i].length() + 1];
        strcpy(palavra, palavras[i].c_str());
        palavra2 = strtok(palavra, ",;\"°() :");
        string sentencasembarra="";
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
                if(subs.length()>=2){
                    Palavra *p = new Palavra();
                    setPalavra(p);
                    vector<int> linhadeocorrencia = getPalavra()->getlinhaocorrencia();
                    linhadeocorrencia.push_back(linha);
                    vector<int> vec = getPalavra()->getnumsentenca();
                    vec.push_back(i + 1);
                    //cout<<vec.size()<<subs<<endl;
                    vector<int> posicaonoparagrafovec=getPalavra()->getposparagrafo();
                    posicaonoparagrafovec.push_back(posicaoparagrafo);
                    posicaoparagrafo++;
                    vector<int> posicaonasentencavec=getPalavra()->getpossentenca();
                    posicaonasentencavec.push_back(posicaonasentenca);
                    posicaonasentenca++;
                    getPalavra()->setposparagrafo(posicaonoparagrafovec);
                    getPalavra()->setpossentenca(posicaonasentencavec);
                    getPalavra()->setnumsentenca(vec);
                    getPalavra()->setpalavra(subs);
                    getPalavra()->setlinhaocorrencia(linhadeocorrencia);
                    vetorpassado.push_back(getPalavra());
       
                        if (vecaaaa.find(getPalavra()->getpalavra()) != vecaaaa.end())
                        {
                            vector<int> vecparagrafos =posicaonoparagrafovec;
                            vecparagrafos.push_back(0);
                            //getPalavra()->setparagrafos(getPalavra()->getparagrafos()+" "+to_string(paragrafos));
                            vecaaaa[getPalavra()->getpalavra()]->setparagrafo(vecparagrafos);
                            vector<int> vecsentenca = vecaaaa[getPalavra()->getpalavra()]->getnumsentenca();
                            vecsentenca.push_back(getPalavra()->getnumsentenca()[0]);
                            vector<int> veclinha = vecaaaa[getPalavra()->getpalavra()]->getlinhaocorrencia();
                            veclinha.push_back(getPalavra()->getlinhaocorrencia()[0]);
                            vector<int> vecpossentenca = vecaaaa[getPalavra()->getpalavra()]->getpossentenca();
                            vecpossentenca.push_back(getPalavra()->getpossentenca()[0]);
                            vector<int> vecposparagrafo = vecaaaa[getPalavra()->getpalavra()]->getposparagrafo();
                            vecposparagrafo.push_back(getPalavra()->getposparagrafo()[0]);
                            vecaaaa[getPalavra()->getpalavra()]->setposparagrafo(vecposparagrafo);
                            vecaaaa[getPalavra()->getpalavra()]->setpossentenca(vecpossentenca);
                            vecaaaa[getPalavra()->getpalavra()]->setnumsentenca(vecsentenca);
                            vecaaaa[getPalavra()->getpalavra()]->setlinhaocorrencia(veclinha);
                            vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
                        }
                        // Caso não ele só acrescenta a palavra na Hash:
                        else
                        {
                            // getPalavra()->setpalavra(getPalavra()->getpalavra());
                            // vector<int> vecparagrafos = getPalavra()->getparagrafo();
                            // vecparagrafos.push_back(0);
                            // getPalavra()->setparagrafo(vecparagrafos);
                            // vector<int> vecsentenca = getPalavra()->getnumsentenca();
                            // getPalavra()->setnumsentenca(vecsentenca);
                            // vector<int> veclinha = getPalavra()->getlinhaocorrencia();
                            // getPalavra()->setlinhaocorrencia(veclinha);
                            // vector<int> vecpossentenca = getPalavra()->getpossentenca();
                            // getPalavra()->setpossentenca(vecpossentenca);
                            // vector<int> vecposparagrafo = getPalavra()->getposparagrafo();
                            // getPalavra()->setposparagrafo(vecposparagrafo);
                            vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
                            // if(getPalavra()->getpalavra()=="busca" && getPalavra()->getnumsentenca().size()==2){
                            //     cout<<getPalavra()->getpalavra()<<"AAA";
                            //     exit(1);
                            // }
                        }
                    this->linha++;
                    if(sentencasembarra==""){
                        sentencasembarra=subs;
                    }
                    else{
                        sentencasembarra=sentencasembarra+" "+subs;
                    }
                    subs2.replace(0, caracterelinha + 1, "");
                    strcpy(palavra2, subs2.c_str());
                }
                else{
                    subs2.replace(0, caracterelinha + 1, "");
                    strcpy(palavra2, subs2.c_str());
                    this->linha++;
                }
            }
            //cout<<palavra2<<endl;
            Palavra *p = new Palavra();
            setPalavra(p);
            vector<int> vec = getPalavra()->getnumsentenca();
            vec.push_back(i + 1);
            //cout<<vec.size()<<palavra2<<endl;
            vector<int> posicaonoparagrafovec=getPalavra()->getposparagrafo();
            posicaonoparagrafovec.push_back(posicaoparagrafo);
            posicaoparagrafo++;
            vector<int> posicaonasentencavec=getPalavra()->getpossentenca();
            posicaonasentencavec.push_back(posicaonasentenca);
            //cout<<this->linha<<palavra2<<endl;
            posicaonasentenca++;
            getPalavra()->setposparagrafo(posicaonoparagrafovec);
            getPalavra()->setpossentenca(posicaonasentencavec);
            vector<int> linhadeocorrencia = getPalavra()->getlinhaocorrencia();
            linhadeocorrencia.push_back(linha);
            getPalavra()->setnumsentenca(vec);
            getPalavra()->setlinhaocorrencia(linhadeocorrencia);
            getPalavra()->setpalavra(palavra2);
            // vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
            // getPara()->setvecpalavra(vecaaaa);
            // if(getPalavra()->getpalavra()=="busca"){
            //     cout<<getPalavra()->getnumsentenca().size()<<endl;
            //     exit(1);
            // }
            // if(getPalavra()->getpalavra()=="busca" && getPalavra()->getnumsentenca().size()==2){
            //                     cout<<getPalavra()->getpalavra()<<"AAA";
            //                     exit(1);
            //                 }
            vetorpassado.push_back(getPalavra());
            if (vecaaaa.find(getPalavra()->getpalavra()) != vecaaaa.end())
                {
                    vector<int> vecparagrafos =posicaonoparagrafovec;
                    vecparagrafos.push_back(0);
                    //getPalavra()->setparagrafos(getPalavra()->getparagrafos()+" "+to_string(paragrafos));
                    vecaaaa[getPalavra()->getpalavra()]->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = vecaaaa[getPalavra()->getpalavra()]->getnumsentenca();
                    vecsentenca.push_back(getPalavra()->getnumsentenca()[0]);
                    vector<int> veclinha = vecaaaa[getPalavra()->getpalavra()]->getlinhaocorrencia();
                    veclinha.push_back(getPalavra()->getlinhaocorrencia()[0]);
                    vector<int> vecpossentenca = vecaaaa[getPalavra()->getpalavra()]->getpossentenca();
                    vecpossentenca.push_back(getPalavra()->getpossentenca()[0]);
                    vector<int> vecposparagrafo = vecaaaa[getPalavra()->getpalavra()]->getposparagrafo();
                    vecposparagrafo.push_back(getPalavra()->getposparagrafo()[0]);
                    vecaaaa[getPalavra()->getpalavra()]->setposparagrafo(vecposparagrafo);
                    vecaaaa[getPalavra()->getpalavra()]->setpossentenca(vecpossentenca);
                    vecaaaa[getPalavra()->getpalavra()]->setnumsentenca(vecsentenca);
                    vecaaaa[getPalavra()->getpalavra()]->setlinhaocorrencia(veclinha);
                }
                // Caso não ele só acrescenta a palavra na Hash:
                else
                {
                    // getPalavra()->setpalavra(getPalavra()->getpalavra());
                    // vector<int> vecparagrafos = getPalavra()->getparagrafo();
                    // vecparagrafos.push_back(0);
                    // getPalavra()->setparagrafo(vecparagrafos);
                    // vector<int> vecsentenca = getPalavra()->getnumsentenca();
                    // getPalavra()->setnumsentenca(vecsentenca);
                    // vector<int> veclinha = getPalavra()->getlinhaocorrencia();
                    // getPalavra()->setlinhaocorrencia(veclinha);
                    // vector<int> vecpossentenca = getPalavra()->getpossentenca();
                    // getPalavra()->setpossentenca(vecpossentenca);
                    // vector<int> vecposparagrafo = getPalavra()->getposparagrafo();
                    // getPalavra()->setposparagrafo(vecposparagrafo);
                    vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
                    
                }
                // for(const auto& i: vetorpassado){
                //     cout<<i->getpalavra()<<i->getnumsentenca().size()<<endl;
                //     if(i->getpalavra()=="busca" && i->getnumsentenca().size()==2){
                //         cout<<getPalavra()->getpalavra();
                //         exit(1);
                //     }
                // }
            if(sentencasembarra==""){
                sentencasembarra=subs;
            }
            else{
                sentencasembarra=sentencasembarra+" "+palavra2;
            }
            palavra2 = strtok(nullptr, ",;\"°() :");
        }
        vecsentencasembarra.push_back(sentencasembarra);
        
    }
    getPara()->setnumsentenca(sentenca-1);
    getPara()->setsentenca(vecsentencasembarra);
    getPara()->setvecpalavra(vecaaaa);
    vector<string> ordenadohash;
    for(const auto& i: vecaaaa){
        ordenadohash.push_back(i.first);
    }
    std::sort(ordenadohash.begin(),ordenadohash.end());
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
    vector<string> vectorordenado;
    Palavra *p;
// *******************************************************************
    string linhaLUAN = "";
    ifstream arqExpressao("dataset/expressoes.txt");
    if(!arqExpressao){
        throw "output3 ---> Não foi possível abrir o arquivo de entrada";
    }
    string expressao;
    vector<string> expressoes;
    while(getline(arqExpressao, expressao)){
        if(expressao.empty()){
            break;
        }
        expressoes.push_back(expressao);
    }
    arqExpressao.close();
    //Transforma para minusculo e coloca ' ' no inicio e no final de todas as expressões
    for (string& expressao : expressoes) {
        string addeSpace = " ";
        addeSpace += expressao + " ";
        expressao = addeSpace;
        transform(expressao.begin(), expressao.end(), expressao.begin(), ::tolower);
    }
    unordered_map<string, pair<int, vector<int>>> ocorrencias;
    // Inicializa o mapa com as expressões e suas ocorrências
    for (const string& expressao : expressoes) { // Loop (1)
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
            for (size_t i = 0; i < expressoes.size(); i++) {
                size_t pos = linhaLUAN.find(expressoes[i]);
                // Verifica se a expressão ocorre na linha
                while (pos != string::npos) {
                    ocorrencias[expressoes[i]].first++;                  // Incrementa o número de ocorrências
                    ocorrencias[expressoes[i]].second.push_back(contadorlinhas+1); // Armazena o número da linha
                    pos = linhaLUAN.find(expressoes[i], pos + 1);           // Procura por outras ocorrências na mesma linha
                }
            }

// *******************************************************************
            if(paragrafo!="")
                paragrafo = paragrafo + "|" + linha;
            else
                paragrafo=linha;
        }
        else
        {
            this->para = new Para();
            setPara(para);
            paragrafos++;
            transform(paragrafo.begin(), paragrafo.end(), paragrafo.begin(), ::tolower);
            //cout<<paragrafo<<endl;
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
            //cout<<separa_linha<<endl;
            vet = retorna_vetor(separa_linha);
            paragrafo = "";
            for (const auto &i : vet)
            {
                // Se map já possui a palavra lida ele retorna a palavra, se não ele retorna ponteiro null:
                //  Caso essa palavra for diferente de um ponteiro nulo entro no if
                if (this->map.find(i->getpalavra()) != this->map.end())
                {
                    //cout<<i->getpalavra()<<endl;
                    vector<int> vecparagrafos = this->map[i->getpalavra()]->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = this->map[i->getpalavra()]->getnumsentenca();
                    vecsentenca.push_back(i->getnumsentenca()[0]);
                    vector<int> veclinha = this->map[i->getpalavra()]->getlinhaocorrencia();
                    veclinha.push_back(i->getlinhaocorrencia()[0]);
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
                    //cout<<i->getpalavra()<<endl;
                    Palavra *p = new Palavra();
                    setPalavra(p);
                    getPalavra()->setpalavra(i->getpalavra());
                    vector<int> vecparagrafos = getPalavra()->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    getPalavra()->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca ;
                    vecsentenca.push_back(i->getnumsentenca()[0]);
                    getPalavra()->setnumsentenca(vecsentenca);
                    vector<int> veclinha ;
                    veclinha.push_back( i->getlinhaocorrencia()[0]);
                    getPalavra()->setlinhaocorrencia(veclinha);
                    vector<int> vecpossentenca;
                    vecpossentenca.push_back(i->getpossentenca()[0]);
                    getPalavra()->setpossentenca(vecpossentenca);
                    vector<int> vecposparagrafo; 
                    vecposparagrafo.push_back( i->getposparagrafo()[0]);
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
                vector<int> vecparagrafos = this->map[i->getpalavra()]->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                vector<int> vecsentenca = this->map[i->getpalavra()]->getnumsentenca();
                vecsentenca.push_back(i->getnumsentenca()[0]);
                vector<int> veclinha = this->map[i->getpalavra()]->getlinhaocorrencia();
                veclinha.push_back(i->getlinhaocorrencia()[0]);
                // vector<int> vecpossentenca = this->map[i->getpalavra()]->getpossentenca();
                // vecpossentenca.push_back(i->getpossentenca()[0]);
                vector<int> vecposparagrafo = this->map[i->getpalavra()]->getposparagrafo();
                vecposparagrafo.push_back(i->getposparagrafo()[0]);
                this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                this->map[i->getpalavra()]->setposparagrafo(vecposparagrafo);
                //this->map[i->getpalavra()]->setpossentenca(vecpossentenca);
                this->map[i->getpalavra()]->setnumsentenca(vecsentenca);
                this->map[i->getpalavra()]->setlinhaocorrencia(veclinha);
            }
            else
            {
                Palavra *p = new Palavra();
                setPalavra(p);
                getPalavra()->setpalavra(i->getpalavra());
                vector<int> vecparagrafos = getPalavra()->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                getPalavra()->setparagrafo(vecparagrafos);
                vector<int> vecsentenca ;
                vecsentenca.push_back(i->getnumsentenca()[0]);
                getPalavra()->setnumsentenca(vecsentenca);
                vector<int> veclinha ;
                veclinha.push_back( i->getlinhaocorrencia()[0]);
                getPalavra()->setlinhaocorrencia(veclinha);
                vector<int> vecpossentenca;
                vecpossentenca.push_back(i->getpossentenca()[0]);
                getPalavra()->setpossentenca(vecpossentenca);
                vector<int> vecposparagrafo; 
                vecposparagrafo.push_back( i->getposparagrafo()[0]);
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
    int cont=0;
    string palavramaior;
    for(const auto& i:vectorordenado){
        if(cont<map[i]->getparagrafo().size()){
            cont=map[i]->getparagrafo().size();
            palavramaior=map[i]->getpalavra();
        }
    }
    string seter;
    for(int i=0;i<map[palavramaior]->getparagrafo().size();i++){
        seter=seter+" "+to_string(map[palavramaior]->getparagrafo()[i]);
    }
    fstream file2;
    string nome = "dataset/Resultados1.data";
    file2.open(nome, std::fstream::out);
    file2 << "================\n=> FULL RESULTS\n================\n";
    file2 << "______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\n";
    file2 << "WORD " << setw(30);
    file2 << "APPEARANCES" << setw(32);
    file2 << "LINES" << setw(96);
    file2 << "SENTENCES" << setw(95);
    file2 << "PARAGRAPHS" << setw(100);
    file2 << "POSITION\n";
    file2 << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for(const auto& i:vectorordenado)
    {
        if(i.length()>=1 && stopwords(i)==false)
        {
            file2 << left <<setw(30)<< i<<"\t";
            file2<<left<<setw(30)<<map[i]->getparagrafo().size()<<"\t";
            palavramaior="";
            cont=0;
            for(unsigned long int j=0; j<map[i]->getlinhaocorrencia().size(); j++){
                file2 <<left<< " " << map[i]->getlinhaocorrencia()[j];
                palavramaior=palavramaior+to_string(map[i]->getlinhaocorrencia()[j]);
                cont++;
            }
            file2<<setw(90-(int(palavramaior.length())+(cont+1)))<<"\t";
            for(unsigned long int j=0;j<map[i]->getnumsentenca().size();j++){
                file2 <<left<< " " << map[i]->getnumsentenca()[j];
            }
            file2<<setw(90)<<"\t";
            for(unsigned long int j=0;j<map[i]->getparagrafo().size();j++){
                file2 << " " << map[i]->getparagrafo()[j];
            }
            file2<<setw(90);
            for(unsigned long int j=0;j<map[i]->getposparagrafo().size();j++){
                file2 << " " << map[i]->getposparagrafo()[j];
            }
            file2<<"\t\n";
        }
    }
    file2 << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
    file2 << "====================================================\n=> LINE NUMBER THAT START AND FINISH EACH PARAGRAPH \n====================================================\n";
    file2 << "_____________________________________________________________________\n";
    file2 << setw(20) << "PARAGRAPH" << setw(20) << "START" << "FINISH \n";
    file2 << "---------------------------------------------------------------------\n";
    for(int i=0;i<vetorParagrafos.size();i++){
        file2 << setw(20) << i+1 << setw(20) << this->vetorParagrafos[i]->getnuminicio() << setw(20) << this->vetorParagrafos[i]->getnumfim() <<endl;
    }
    file2 << "---------------------------------------------------------------------\n\n";
    file2 << "================================================================\n=> NUMBER OF WORDS IN EACH SENTENCE WITH AND WITHOUT STOP WORDS\n================================================================\n";
    file2 << "_____________________________________________________________________________________________________________________\n";
    file2 << left << setw(30) << "PARAGRAPH\t" << setw(28) << "SENTENCE\t" << setw(28) << "WITH STOP WORDS\t" << "WITHOUT STOP WORDS\n";
    file2 << "---------------------------------------------------------------------------------------------------------------------\n";
    for(int a=0; a < int(vetorParagrafos.size()); a++){
        for(int b=0; b < int(vetorParagrafos[a]->getsentenca().size()); b++){

            string palavra_aux;
            stringstream sentenca_aux;
            sentenca_aux << vetorParagrafos[a]->getsentenca()[b];
            
            while(sentenca_aux >> palavra_aux){
                if(stopwords(palavra_aux) == true){
                    contstopwords++;
                }
                contpalavras++;
            }
            
            file2 << left << setw(30) << a+1 << "\t";
            file2 << left << setw(30) << b+1 << "\t";
            file2 << left << setw(30) << contpalavras << "\t"; 
            file2 << left << setw(30) << (contpalavras - contstopwords) << endl;
            contpalavras = 0;
            contstopwords = 0;
        }
    }
    file2 << "---------------------------------------------------------------------\n\n";
// **********************************************************************
    file2 << "==========================\n=> SEARCH FOR EXPRESSIONS\n==========================\n";
    file2 << "_____________________________________________________\n";
    file2 << left << setw(20) << "EXPRESSION" << setw(20) << "APPEARANCES" << "LINE\n";
    file2 << "-----------------------------------------------------\n";
    for (const auto& ocorrencia : (*texto)) {
        if(ocorrencia.second.first >= 1){
            file2 << left << setw(20) << ocorrencia.first.substr(0, ocorrencia.first.length() - 1) << setw(20) << ocorrencia.second.first;
            for (size_t i = 0; i < ocorrencia.second.second.size(); ++i) {
                file2 << ocorrencia.second.second[i];
                if (i != ocorrencia.second.second.size() - 1) {
                    file2 << " ";
                }
            }
            file2 << endl;
        }
    }
    file2 << "-----------------------------------------------------\n\n";
// **********************************************************************
    file2 << "====================\n=> PARTIAL RESULTS\n====================";
    for(int i=0;i<vetorParagrafos.size();i++){
        file2 << "\n________________________________________________________________________________________________________________________________________________________________________________________________________________\n";
        file2<< left << setw(30) << "WORD" << setw(30) << "PARAGRAPH" << setw(30) << "SENTENCE" << setw(30) << "LINE" << setw(30) << "APPEARANCES" << setw(30) << "POSITIONS" << "DISTANCE\n";
        file2 << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        //MedeDistancia(vetorParagrafos[i]->getpalavras(),i,file2);
        for(int j=0;j<vetorParagrafos[i]->getpalavras().size();j++){
            if(stopwords(vetorParagrafos[i]->getpalavras()[j])==false && vetorParagrafos[i]->getpalavras()[j]!=""){
                file2<<setw(30)<<vetorParagrafos[i]->getpalavras()[j];
                file2<<setw(30)<<i+1;
                for(int k=0;k<int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getnumsentenca().size());k++){
                    file2<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getnumsentenca()[k];
                }
                file2<<setw(30);
                for(int k=0;k<int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getlinhaocorrencia().size());k++){
                    file2<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getlinhaocorrencia()[k];
                }
                file2<<setw(30);
                file2<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getlinhaocorrencia().size();
                file2<<setw(30);
                for(int k=0;k<int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo().size());k++){
                    file2<<" "<<vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[k];
                }
                file2<<setw(30)<<"\t";
                int inicio = 0;
                int fim = 1;
                int tamanho = 0;
                int distancia = 0;
                tamanho = int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo().size());
                inicio = 0;
                fim = 1;
                while(fim<tamanho)
                {
                    distancia = int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[fim])-int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[inicio]);
                    // cout << "Distância:" << distancia << "\n\n";
                    file2<<distancia<<" ";
                    fim=fim+1;
                }
                file2<<endl;
            }
        }
        file2<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    file2.close();
}

// identificação stopwords
bool Hash::stopwords(string palavra){

    ifstream arq("dataset/stopwords.txt");  
    string stopword;
    

    if(arq.is_open()){
        if(int(palavra.size()) == 1){
            for(int i = 0; i < int(pacote[0].size()); i++){
                if(palavra == pacote[0][i]){
                    return true;
                }
            }
            return false;
        }else if(int(palavra.size()) == 2){
            for(int i = 0; i < int(pacote[1].size()); i++){
                if(palavra == pacote[1][i]){
                    return true;
                }
            }
            return false;
        }else if(int(palavra.size()) == 3){
            for(int i = 0; i < int(pacote[2].size()); i++){
                if(palavra == pacote[2][i]){
                    return true;
                }
            }
            return false;
        }else if(int(palavra.size()) == 4){
            for(int i = 0; i < int(pacote[3].size()); i++){
                if(palavra == pacote[3][i]){
                    return true;
                }
            }
            return false;
        }else if(int(palavra.size()) == 14){
            for(int i = 0; i < int(pacote[4].size()); i++){
                if(palavra == pacote[4][i]){
                    return true;
                }
            }
            return false;
        }else{
            return false;
        }
        arq.close();
    }else{
        cout << "Não foi possível abrir o arquivo." << endl;
        return false;
    
    }
    return false;
}

void Hash::separastopwords(){

    ifstream arq("dataset/stopwords.txt");  
    string stopword;

    
    if(arq.is_open()){
        
        while(getline(arq, stopword)){
            if(stopword.size() == 1){
                pacote[0].push_back(stopword);
            }else if(stopword.size() == 2){
                pacote[1].push_back(stopword);
            }else if(stopword.size() == 3){
                pacote[2].push_back(stopword);
            }else if(stopword.size() == 4){
                pacote[3].push_back(stopword);
            }else if(stopword.size() == 14){
                pacote[4].push_back(stopword);
            } 
        }
        arq.close();
    }else{
        cout << "Não foi possível abrir o arquivo." << endl;
    
    }
}

string Hash::transforme(string linha){
    char space = ' ';
    short int tam = linha.size();
    linha = " " + linha + " ";
    for(int i=0;i<=tam;i++){
        linha[i] = tolower(linha[i]);
        if(linha[i] == 44 || linha[i] == 63 || linha[i] == 33 || linha[i] == 59 || linha[i] == 248 || linha[i] == 92 || linha[i] == 40  || linha[i] == 41  || linha[i] == 34 || linha[i] == 58 || linha[i] == 46){
            linha[i] = space;
        }
        else if(linha[i] == 45 && linha[i+1] == 45){
            linha[i+1] = space;
        }
    }
    return linha;
}