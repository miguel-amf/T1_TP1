#include "EstadoProjeto.h"
#include <iostream>

using namespace std;

/*
Trecho para implementacao do EstadoProjeto
*/

EstadoProjeto::EstadoProjeto() {
    //inicializa a variavel
    estado = 0;
}

void EstadoProjeto::setEstado(int entrada) throw(invalid_argument){

    //testa usando a funcao avalia
    try {
        avalia(entrada);
    } catch (invalid_argument& erro) {
        throw erro;
    }

    //insere valor em estado
    estado = entrada;

}

int EstadoProjeto::getEstado() const{

    return estado;
}

void EstadoProjeto::avalia(int entrada) throw(invalid_argument){

    //testa para a faixa de [0,9] nos inteiros
    if (entrada<0 || entrada>9) {
        throw invalid_argument("Entrada fora da faixa dinamica");
    }

}

/*
Trecho para implementacao do TesteEstadoProjeto
*/


TesteEstadoProjeto::TesteEstadoProjeto() {
    estadoTemp = 0;
}

void TesteEstadoProjeto::setUp(EstadoProjeto alvo) {
    //armazena o valor de alvo
    estadoTemp = alvo.getEstado();
}

void TesteEstadoProjeto::tearDown(EstadoProjeto alvo) {

    alvo.setEstado(estadoTemp);
}

void TesteEstadoProjeto::run(EstadoProjeto alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de Estado do Projeto com estado igual a " << alvo.getEstado() << endl ;
    cout << "testando valor '3' (Valido)        : ";
    try {
        alvo.setEstado(3);
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
        alvo.setEstado(-1);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << alvo.getEstado() << endl;
    }
    //reset na flag para proximo teste
    flagCatch = 0;

    //teste de nao-alfabetico

    cout << "Testando valor '10' (Invalido, >9) : " ;

    try {
        alvo.setEstado(10);
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }



}


