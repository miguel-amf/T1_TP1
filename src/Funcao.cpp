

#include "Funcao.h"
#include <iostream>

using namespace std;

/*
Trecho para implementacao do Funcao
*/

Funcao::Funcao() {
    //inicializa a variavel
    funcao = 0;
}

void Funcao::setFuncao(int entrada) throw(invalid_argument){

    //testa usando a funcao avalia
    try {
        avalia(entrada);
    } catch (invalid_argument& erro) {
        throw erro;
    }

    //insere valor em funcao
    funcao = entrada;

}

int Funcao::getFuncao() const{

    return funcao;
}

void Funcao::avalia(int entrada) throw(invalid_argument){

    //testa para a faixa de [0,9] nos inteiros
    if (entrada<0 || entrada>9) {
        throw invalid_argument("Entrada fora da faixa dinamica");
    }

}

/*
Trecho para implementacao do TesteFuncao
*/


TesteFuncao::TesteFuncao() {
    funcaoTemp = 0;
}

void TesteFuncao::setUp(Funcao alvo) {
    //armazena o valor de alvo
    funcaoTemp = alvo.getFuncao();
}

void TesteFuncao::tearDown(Funcao alvo) {

    alvo.setFuncao(funcaoTemp);
}

void TesteFuncao::run(Funcao alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de Funcao do Projeto com funcao igual a " << alvo.getFuncao() << endl ;
    cout << "testando valor '3' (Valido)        : ";
    try {
        alvo.setFuncao(3);
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
        alvo.setFuncao(-1);
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

    cout << "Testando valor '10' (Invalido, >9) : " ;

    try {
        alvo.setFuncao(10);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }



}


