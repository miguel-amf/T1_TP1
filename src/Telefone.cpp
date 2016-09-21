#include "Telefone.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

Telefone::Telefone(){

    numero = "00000000";
}

string Telefone::getNumero(){
    return numero;
}

void Telefone::setNumero(string novoNumero) throw(invalid_argument){
    try{
        avalia(novoNumero);
    } catch (invalid_argument& erro){
        throw erro;
    }
    numero = novoNumero;
}

void Telefone::avalia(string novoNumero)throw(invalid_argument){

    if (novoNumero.length() != 8)
        throw invalid_argument("O numero deve possuir 8 digitos.");

    for (int i=0; novoNumero[i] != '\0'; i++){
        if(novoNumero[i] <= 48 || novoNumero[i] >= 57){
            throw invalid_argument("O numero so deve conter digitos.");
        }
    }
}

/*
Trecho referente ao teste da unidade
*/

TesteTelefone::TesteTelefone() {
    //zera a variavel para o codigo temporario
    telefoneTemp = '\0';
}

void TesteTelefone::setUp(Telefone alvo) {
    //Armazena o valor do codigo do alvo
    telefoneTemp = alvo.getNumero();
}

void TesteTelefone::tearDown(Telefone alvo) {
    //atribui de volta o valor temporario
    alvo.setNumero(telefoneTemp);
}


void TesteTelefone::run(Telefone alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de telefone com numero igual a " << alvo.getNumero() << endl ;
    cout << "testando valor '12345678' (Valido)             : ";
    try {
        alvo.setNumero("12345678");
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
    cout << "Testando valor '1234' (Invalido, length != 8) : " ;

    try {
        alvo.setNumero("1234");
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

    cout << "Testando valor '1234567A' (Invalido, nao númerico) : " ;

    try {
        alvo.setNumero("1234567A");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

}

