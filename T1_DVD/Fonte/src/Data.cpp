#include "Data.h"
#include <iostream>

using namespace std;

/*
Trecho para implementacao da Data
*/

Data::Data() {
    data = "01/01/2016";
}

string Data::getData() {
    return data;
}

void Data::setData(string entrada) throw(invalid_argument){

    try {
        avalia(entrada);
    } catch (invalid_argument& erro) {
        throw erro;
    }

    data = entrada;
}

void Data::avalia(string entrada) throw(invalid_argument){

    if(entrada.length() != 10) throw invalid_argument("A entrada nao possui 10 caracteres");
    //checa se eh um numero
    if (entrada[0] > 57 || entrada[0] < 48) throw invalid_argument("dia nao corresponde a um numero");
    if (entrada[1] > 57 || entrada[1] < 48) throw invalid_argument("dia nao corresponde a um numero");
    if (entrada[2] != '/') throw invalid_argument("nao ha barra separadora ( / )entre dia e mes");
    if (entrada[3] > 57 || entrada[3] < 48) throw invalid_argument("mes nao corresponde a um numero");
    if (entrada[4] > 57 || entrada[4] < 48) throw invalid_argument("mes nao corresponde a um numero");
    if (entrada[5] != '/') throw invalid_argument("nao ha barra separadora ( / )entre mes e ano");
    if (entrada[6] > 57 || entrada[6] < 48) throw invalid_argument("ano nao corresponde a um numero");
    if (entrada[7] > 57 || entrada[7] < 48) throw invalid_argument("ano nao corresponde a um numero");
    if (entrada[8] > 57 || entrada[8] < 48) throw invalid_argument("ano nao corresponde a um numero");
    if (entrada[9] > 57 || entrada[9] < 48) throw invalid_argument("ano nao corresponde a um numero");
}

/*
Trecho para implementacao da TesteData
*/

TesteData::TesteData() {
    dataTemp = "01/01/2016";
}


void TesteData::setUp(Data alvo) {
    dataTemp = alvo.getData();
}

void TesteData::tearDown(Data alvo) {
    alvo.getData() = dataTemp;
}

void TesteData::run(Data alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de Data com data igual a " << alvo.getData() << endl ;
    cout << "testando valor '02/02/2020' (Valido)        : ";
    try {
        alvo.setData("02/02/2020");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "REPROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "APROVADO" << endl;
    }
    //reset na flag para proximo teste
    flagCatch = 0;

    //Teste de tamanho invalido
    cout << "Testando valor '2/02/2020' (Invalido, nao ha 10 carac.) : ";

    try {
        alvo.setData("2/02/2020");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << alvo.getData() << endl;
    }
    //reset na flag para proximo teste
    flagCatch = 0;


    //Teste de dia invalido
    cout << "Testando valor 'aa/02/2020' (Invalido, dia nao inteiro) : ";

    try {
        alvo.setData("aa/02/2020");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << alvo.getData() << endl;
    }
    //reset na flag para proximo teste
    flagCatch = 0;

    //teste de falta de barra

    cout << "Testando valor '02a02/2020' (Invalido, sem barra) : " ;

    try {
        alvo.setData("02a02/2020");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

    //teste de mes invalido

    cout << "Testando valor '02/aa/2020' (Invalido, mes nao inteiro) : " ;

    try {
        alvo.setData("02/aa/2020");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

    //teste de sem barra
    cout << "Testando valor '02/02a2020' (Invalido, sem barra) : " ;

    try {
        alvo.setData("02/02a2020");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

    //teste de ano invalido

    cout << "Testando valor '02/02/aaaa' (Invalido, ano nao inteiro) : " ;

    try {
        alvo.setData("02/02/aaaa");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

}
