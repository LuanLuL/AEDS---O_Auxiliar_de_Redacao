#include "Hash.hpp"
/*********************** CONSTRUTORES AND DESTRUTORES*/
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
    unordered_map<string,Palavra*> vecaaaa;
    vector<string> palavras, vecsentencasembarra;
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
                    vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
                    getPara()->setvecpalavra(vecaaaa);
                    vetorpassado.push_back(getPalavra());
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
            // vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
            // getPara()->setvecpalavra(vecaaaa);
            if (vecaaaa.find(getPalavra()->getpalavra()) != vecaaaa.end())
                {
                    vector<int> vecparagrafos = vecaaaa[getPalavra()->getpalavra()]->getparagrafo();
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
                    getPalavra()->setpalavra(getPalavra()->getpalavra());
                    vector<int> vecparagrafos = getPalavra()->getparagrafo();
                    vecparagrafos.push_back(0);
                    getPalavra()->setparagrafo(vecparagrafos);
                    vector<int> vecsentenca = getPalavra()->getnumsentenca();
                    getPalavra()->setnumsentenca(vecsentenca);
                    vector<int> veclinha = getPalavra()->getlinhaocorrencia();
                    getPalavra()->setlinhaocorrencia(veclinha);
                    vector<int> vecpossentenca = getPalavra()->getpossentenca();
                    getPalavra()->setpossentenca(vecpossentenca);
                    vector<int> vecposparagrafo = getPalavra()->getposparagrafo();
                    getPalavra()->setposparagrafo(vecposparagrafo);
                    vecaaaa.insert({getPalavra()->getpalavra(), getPalavra()});
                }
            if(sentencasembarra==""){
                sentencasembarra=subs;
            }
            else{
                sentencasembarra=sentencasembarra+" "+palavra2;
            }
            vetorpassado.push_back(getPalavra());
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
                    //getPalavra()->setparagrafos(getPalavra()->getparagrafos()+" "+to_string(paragrafos));
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
                //getPalavra()->setparagrafos(getPalavra()->getparagrafos()+" "+to_string(paragrafos));
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
                //string paragrafostodos=getPalavra()->getparagrafos()+" "+to_string(paragrafos);
                //cout<<getPalavra()->getparagrafos();
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
    // imprimindo o vetor ordenado alfabeticamnete
    // for (long unsigned int i = 0; i < vectorordenado.size(); i++)
    // {
    //     cout << vectorordenado[i] << "\n";
    // }
    //CriaArq(vectorordenado);
    //MedeDistancia();

    fstream file2;
    string nome = "dataset/Resultados1.data";
    file2.open(nome, std::fstream::out);
    file2 << "Palavra "<<setw(30);
    file2<< "Num vezes:"<<setw(32);
    file2 << "Linhas:"<<setw(96);
    file2<<"Sentencas:"<<setw(95);
    file2<<"Paragrafos:"<<setw(100);
    file2<<"Posição paragrafo:\n";
    for(const auto& i:vectorordenado)
    {
        if(i.length()>=1 && stopwords(i)==false)
        {
            file2 << left <<setw(30)<< i<<"\t";
            file2<<left<<setw(30)<<map[i]->getparagrafo().size()<<"\t";
            // if(stopwords(i)==true){
                palavramaior="";
                cont=0;
                for(unsigned long int j=0; j<map[i]->getlinhaocorrencia().size(); j++){
                    file2 <<left<< " " << map[i]->getlinhaocorrencia()[j];
                    palavramaior=palavramaior+to_string(map[i]->getlinhaocorrencia()[j]);
                    cont++;
                }
                file2<<setw(90-(int(palavramaior.length())+(cont+1)))<<"\t";
                //cout<<palavramaior.length()<<endl;
                for(unsigned long int j=0;j<map[i]->getnumsentenca().size();j++){
                    file2 <<left<< " " << map[i]->getnumsentenca()[j];
                }
                file2<<setw(90)<<"\t";
                for(unsigned long int j=0;j<map[i]->getnumsentenca().size();j++){
                    file2 << " " << map[i]->getparagrafo()[j];
                }
                file2<<setw(90);
                for(unsigned long int j=0;j<map[i]->getposparagrafo().size();j++){
                    file2 << " " << map[i]->getposparagrafo()[j];
                }
                file2<<"\t";
                
                file2 << "\n";
            //}
        }
    }
    // file2<<left<<setw(90)<<"Paragrafo:";
    //     file2<<left<<setw(90)<<"Numsentenca paragrafos:";
    //     file2<<"Linha de inicio/linha de fim:"<<setw(90)<<endl;
    // for(int i=0;i<vetorParagrafos.size();i++){
    //     file2<<left<<setw(90)<<i+1;
    //     file2 << left<<setw(90) <<this->vetorParagrafos[i]->getnumsentenca();
    //     // file2<<setw(90);
    //     file2 << " " <<this->vetorParagrafos[i]->getnuminicio()<<"/"<<this->vetorParagrafos[i]->getnumfim();
    //     file2<<endl;
    // }
    //cout<<vetorParagrafos[3]->getvecpalavra()["uma"]->getlinhaocorrencia()[0]<<endl;
    file2 << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    file2 << "\n                           NUMBER OF WORDS IN EACH SENTENCE WITH AND WITHOUT STOP WORDS                                                           \n";
    file2 << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    file2 << "\n"<< left << setw(30) << "Parágrafo\t" << left << setw(30) << "sentenca\t" << left << setw(30) << "com stop words\t" << "sem stop words\n";
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
    file2 << "-------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    file2<<setw(30)<<"Palavra:";
        file2<<setw(30)<<"Paragrafo";
        file2<<setw(30)<<"sentenca";
        file2<<setw(30)<<"Linha:";
        file2<<setw(30)<<"Ocorrencia";
        file2<<setw(30)<<"Posicoes:";
        file2<<"Distancia\n";
    for(int i=0;i<vetorParagrafos.size();i++){
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
                tamanho = int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getparagrafo().size());
                inicio = 0;
                fim = 1;
                if(fim==tamanho){
                    file2<<distancia<<" ";
                }
                else{
                    while(fim<tamanho)
                    {
                        distancia = int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[fim])-int(vetorParagrafos[i]->getvecpalavra()[vetorParagrafos[i]->getpalavras()[j]]->getposparagrafo()[inicio]);
                        // cout << "Distância:" << distancia << "\n\n";
                        fim++;
                        file2<<distancia<<" ";
                    }
                }
                file2<<endl;
            }
        }
        file2<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            file2<<endl;
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

// void Hash :: MedeDistancia(vector <string> ordenadohash,int numeroparagrafo, fstream &arq)
// {
//     int inicio = 0;
//     int fim = 1;
//     int tamanho = 0;
//     int distancia = 0;
//     for (const auto &i : ordenadohash)
//     {
//         tamanho = int(vetorParagrafos[numeroparagrafo]->getvecpalavra()[i]->getparagrafo().size());
//         inicio = 0;
//         fim = 1;

//         while(fim!=tamanho)
//         {
//             distancia = int(vetorParagrafos[numeroparagrafo]->getvecpalavra()[i]->getparagrafo()[fim])-int(vetorParagrafos[numeroparagrafo]->getvecpalavra()[i]->getparagrafo()[inicio]);
//             // cout << "Distância:" << distancia << "\n\n";
//             fim++;
//             arq<<distancia;
//         }
//     }
// }