#include "Hash.hpp"
/*********************** CONSTRUTORES AND DESTRUTORES*/
Hash::Hash()
{
    unordered_map<string, Palavra *> map;
    this->p = new Palavra();
    this->para = new Para();
    this->map = map;
    this->linha=0;
    
}

/************************* GETTERS AND SETTERS */
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
/***************************** METODOS */

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
    vector<string> palavras, sentencas_separadas, vecsentencasembarra;
    vector<Palavra *> vetorpassado;
    string a;
    char *palavra, *palavra2;
    palavra = strtok(separa_linha, ".!?");
    while (palavra != nullptr)
    {
        a = palavra;
        // cout<<palavra<<endl;
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
            // A=-127,-128,-126,125´`^~//E=-118 e-119^´//I=-115´//O=-107 a -109~^´//U=-100 e-102´ e bagulho
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
                    vector<int> posicaonoparagrafovec=getPalavra()->getposparagrafo();
                    posicaonoparagrafovec.push_back(posicaoparagrafo);
                    posicaoparagrafo++;
                    vector<int> posicaonasentencavec=getPalavra()->getpossentenca();
                    posicaonasentencavec.push_back(posicaonasentenca);
                    //cout<<"AAAAAAAAA "<<this->linha<<palavra2<<endl;
                    posicaonasentenca++;
                    getPalavra()->setposparagrafo(posicaonoparagrafovec);
                    getPalavra()->setpossentenca(posicaonasentencavec);
                    getPalavra()->setnumsentenca(vec);
                    getPalavra()->setpalavra(subs);
                    getPalavra()->setlinhaocorrencia(linhadeocorrencia);
                    vetorpassado.push_back(getPalavra());
                    sentencas_separadas.push_back(subs);
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
            //cout<<palavra2<<":"<<posicaonasentenca<<endl;
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
            if(sentencasembarra==""){
                sentencasembarra=subs;
            }
            else{
                sentencasembarra=sentencasembarra+" "+palavra2;
            }
            vetorpassado.push_back(getPalavra());
            sentencas_separadas.push_back(palavra2);
            palavra2 = strtok(nullptr, ",;\"°() :");
        }
        vecsentencasembarra.push_back(sentencasembarra);
    }
      getPara()->setsentenca(vecsentencasembarra);
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
    arq.open("dataset/DomCasmurro.txt");
    while (getline(arq, linha))
    {
        if (linha.empty() == false)
        {
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
                    p = new Palavra();
                    setPalavra(p);
                    getPalavra()->setpalavra(i->getpalavra());
                    vector<int> vecparagrafos = getPalavra()->getparagrafo();
                    vecparagrafos.push_back(paragrafos);
                    getPalavra()->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = i->getnumsentenca();
                    getPalavra()->setnumsentenca(vecsentenca);
                    vector<int> veclinha = i->getlinhaocorrencia();
                    getPalavra()->setlinhaocorrencia(veclinha);
                    vector<int> vecpossentenca = i->getpossentenca();
                    getPalavra()->setpossentenca(vecpossentenca);
                    vector<int> vecposparagrafo = i->getposparagrafo();
                    getPalavra()->setposparagrafo(vecposparagrafo);
                    this->map.insert({i->getpalavra(), getPalavra()});
                }
            }
        }
        // contadorcomeco++;
        // contadorlinhas++;
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
                vector<int> vecpossentenca = this->map[i->getpalavra()]->getpossentenca();
                vecpossentenca.push_back(i->getpossentenca()[0]);
                vector<int> vecposparagrafo = this->map[i->getpalavra()]->getposparagrafo();
                vecposparagrafo.push_back(i->getposparagrafo()[0]);
                this->map[i->getpalavra()]->setparagrafo(vecparagrafos);
                this->map[i->getpalavra()]->setposparagrafo(vecposparagrafo);
                this->map[i->getpalavra()]->setpossentenca(vecpossentenca);
                this->map[i->getpalavra()]->setnumsentenca(vecsentenca);
                this->map[i->getpalavra()]->setlinhaocorrencia(veclinha);
            }
            else
            {
                p = new Palavra();
                setPalavra(p);
                // getPalavra()->setcontador(1);
                getPalavra()->setpalavra(i->getpalavra());
                vector<int> vecparagrafos = getPalavra()->getparagrafo();
                vecparagrafos.push_back(paragrafos);
                getPalavra()->setparagrafo(vecparagrafos);
                vector<int> vecsentenca = i->getnumsentenca();
                getPalavra()->setnumsentenca(vecsentenca);
                vector<int> veclinha = i->getlinhaocorrencia();
                getPalavra()->setlinhaocorrencia(veclinha);
                vector<int> vecpossentenca = i->getpossentenca();
                getPalavra()->setpossentenca(vecpossentenca);
                vector<int> vecposparagrafo = i->getposparagrafo();
                getPalavra()->setposparagrafo(vecposparagrafo);
                this->map.insert({i->getpalavra(), getPalavra()});
            }
        }
    }
    arq.close();


    // }
    // for (const auto &par : map)
    // {
    //     cout << "Chave: " << par.first << endl;
    //     for (int i = 0; i < int(par.second->getparagrafo().size()); i++)
    //     {
    //         cout << "Sentença: " << par.second->getnumsentenca()[i] << "  "
    //              << "Paragrafo: " << par.second->getparagrafo()[i] << "  "
    //              << "Linha ocorrencia: " << par.second->getlinhaocorrencia()[i] << endl;
    //     }
    // }
}
/// @brief Essa função cria um vector com todas as palavras de map estando ordenadas com todas as suas letras sem acento minúsculas
void Hash::AlphaOrder()
{
    vector<string> vectorordenado;

    // Inserindo palavras no vetor:
    for (const auto &par : this->map)
    {
        vectorordenado.push_back(par.first);
    }
    // Ordenando palavras:
    std::sort(vectorordenado.begin(), vectorordenado.end());

    // imprimindo o vetor ordenado alfabeticamnete
    // for (long unsigned int i = 0; i < vectorordenado.size(); i++)
    // {
    //     cout << vectorordenado[i] << "\n";
    // }
    CriaArq(vectorordenado);

    fstream file2;
    string nome = "dataset/Resultados1.data";
    file2.open(nome, std::fstream::out);
    for(const auto& i:vectorordenado)
    {
        if(i.length()>=1)
        {
            file2 << "+++++++ NOVA PALAVRA +++++++++++";
            file2 << "\n";
            file2 << i;
            file2 << "\n";
            file2 << "Número de ocorrências" << map[i]->getparagrafo().size();
            file2 << "\n";
            file2 << "linha onde surge";
            for(unsigned long int j=0; j<map[i]->getlinhaocorrencia().size(); j++)
                file2 << " " << map[i]->getlinhaocorrencia()[j];
            file2 << "\n\n\n\n\n\n\n";
        }
    }
    file2.close();
}

void Hash :: CriaArq(vector<string> vectorordenado)
{

    fstream file;
    string nome = "dataset/Resultados.data";
    file.open(nome, std::fstream::out);
    file << "Chave:     "  
        << "Sentença: "  << "    "
        << "Paragrafo: " << "    "
        << "Linha ocorrencia: " <<"    "
        << "Posição na sentença: "<<"    "
        << "Posição no paragrafo: "<<"    "
        << "Aparições no texto:a "<<endl;
    for (const auto& j:vectorordenado)
    {
        if(j.length()>=1)
        {
            file<<j<<"       ";
            for(int i=0;i<int(map[j]->getparagrafo().size());i++){
                 file<< map[j]->getnumsentenca()[i] << "\t\t\t     "
                 << map[j]->getparagrafo()[i] << "\t\t\t     "
                 << map[j]->getlinhaocorrencia()[i] <<"\t\t\t     "
                 << map[j]->getpossentenca()[i] <<"\t \t\t    "
                 << map[j]->getposparagrafo()[i]<<"\t\t\t      "
                 << map[j]->getparagrafo().size()<<endl;
            }
        }
    }
    file.close();
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

void Hash::imprimirSaidaStop(){
    pacote.resize(5);
    separastopwords();
    for(int a=0; a < int(vetorParagrafos.size()); a++){
        for(int b=0; b < int(vetorParagrafos[a]->getsentenca().size()); b++){
            cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
            cout << vetorParagrafos[a]->getsentenca()[b] << endl;

            string palavra_aux;
            stringstream sentenca_aux;
            sentenca_aux << vetorParagrafos[a]->getsentenca()[b];
            
            while(sentenca_aux >> palavra_aux){
                if(stopwords(palavra_aux) == true){
                    contstopwords++;
                }
                contpalavras++;
            }
           
            
            cout << "paragrafo: " << a+1 << " " << " sentenca: " << b+1 << " Com stop words: " << contpalavras << " Sem stop words: " << (contpalavras - contstopwords) << endl;
             cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
            contpalavras = 0;
            contstopwords = 0;
        }

    }
}
void Hash :: MedeDistancia(vector <string> vectorordenado)
{
    int inicio = 0;
    int fim = 1;
    int tamanho = 0;
    int distancia = 0;
    for (const auto &i : vectorordenado)
    {
        tamanho = int(map[i]->getparagrafo().size());
        inicio = 0;
        fim = 1;

        while(fim!=tamanho)
        {
            if(map[i]->getparagrafo()[inicio]==map[i]->getparagrafo()[fim])
            {
                cout << "Palavra igual encontrada!\n";
                cout << "Palavra: "<< i << "\n";
                cout << "Parágrafo: " << map[i]->getparagrafo()[inicio] << "\n";
                cout << "Posições: " << int(map[i]->getposparagrafo()[fim]) << " " << int(map[i]->getposparagrafo()[inicio]) << "\n";
                distancia = int(map[i]->getposparagrafo()[fim])-int(map[i]->getposparagrafo()[inicio]);
                cout << "Distância:" << distancia << "\n\n";
                fim++;
            }
            else
            {
                inicio=fim;
                fim++;
            }
        }
    }
}