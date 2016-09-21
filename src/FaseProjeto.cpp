
#include "FaseProjeto.h"
#include <iostream>

using namespace std;

/*
Trecho para implementacao do FaseProjeto
*/

FaseProjeto::FaseProjeto() {
    //inicializa a variavel
    fase = 0;
}

void FaseProjeto::setFase(int entrada) throw(invalid_argument){

    //testa usando a funcao avalia
    try {
        avalia(entrada);
    } catch (invalid_argument& erro) {
        throw erro;
    }

    //insere valor em fase
    fase = entrada;

}

int FaseProjeto::getFase() const{

    return fase;
}

void FaseProjeto::avalia(int entrada) throw(invalid_argument){

    //testa para a faixa de [0,9] nos inteiros
    if (entrada<0 || entrada>9) {
        throw invalid_argument("Entrada fora da faixa dinamica");
    }

}

/*
Trecho para implementacao do TesteFaseProjeto
*/


TesteFaseProjeto::TesteFaseProjeto() {
    faseTemp = 0;
}

void TesteFaseProjeto::setUp(FaseProjeto alvo) {
    //armazena o valor de alvo
    faseTemp = alvo.getFase();
}

void TesteFaseProjeto::tearDown(FaseProjeto alvo) {

    alvo.setFase(faseTemp);
}

void TesteFaseProjeto::run(FaseProjeto alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de Fase do Projeto com fase igual a " << alvo.getFase() << endl ;
    cout << "testando valor '3' (Valido)        : ";
    try {
        alvo.setFase(3);
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
    cout << "Testando valor '-1' (Invalido, <0) : ";

    try {
        alvo.setFase(-1);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << alvo.getFase() << endl;
    }
    //reset na flag para proximo teste
    flagCatch = 0;

    //teste de nao-alfabetico

    cout << "Testando valor '10' (Invalido, >9) : " ;

    try {
        alvo.setFase(10);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }



}


