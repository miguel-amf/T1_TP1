#include "Custo.h"

#include <stdexcept>
#include <iostream>

Custo::Custo() {
    custo = 0.000001;
}

void Custo::setCusto(float entrada) throw(invalid_argument) {

    try {
        avalia(entrada);
    } catch (invalid_argument& erro) {
        throw erro;
    }

    custo = entrada;
}

float Custo::getCusto() const{
    return custo;
}

void Custo::avalia(float entrada) throw(invalid_argument) {

    if (entrada<=0)
        throw invalid_argument("fora da faixa dinamica ( >0 )");
}


/*
Trecho referente ao teste da unidade
*/

TesteCusto::TesteCusto() {
    //zera a variavel para o codigo temporario
    custoTemp = 0.00001;
}

void TesteCusto::setUp(Custo alvo) {
    //Armazena o valor do codigo do alvo
    custoTemp = alvo.getCusto();
}

void TesteCusto::tearDown(Custo alvo) {
    //atribui de volta o valor temporario
    try{
        alvo.setCusto(custoTemp);
    } catch(invalid_argument){
        cout << "Cost not set" << endl;
    }

}


void TesteCusto::run(Custo alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de custo com custo igual a " << alvo.getCusto() << endl ;
    cout << "testando valor '125.75' (Valido)             : ";
    try {
        alvo.setCusto(125.75);
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

    //Teste de tamanho
    cout << "Testando valor '-1' (Invalido, custo <0) : " ;

    try {
        alvo.setCusto(-1);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }
    //reset na flag para proximo teste
    flagCatch = 0;

    //teste de nao-alfabetico

    cout << "Testando valor '0' (Invalido, =0) : " ;

    try {
        alvo.setCusto(0);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

}
