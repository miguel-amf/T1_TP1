#include "Matricula.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

Matricula::Matricula(){

    matricula = "00000";
}

string Matricula::getMatricula(){
    return matricula;
}

void Matricula::setMatricula(string novaMatricula) throw(invalid_argument){
    try{
        avalia(novaMatricula);
    } catch (invalid_argument& erro){
        throw erro;
    }
    matricula = novaMatricula;
}

void Matricula::avalia(string novaMatricula)throw(invalid_argument){

    if (novaMatricula.length() != 5)
        throw invalid_argument("A matricula deve possuir 5 digitos.");

    for (int i=0; novaMatricula[i] != '\0'; i++){
        if(novaMatricula[i] < 48 || novaMatricula[i] > 57){
            throw invalid_argument("A matricula so deve conter digitos.");
        }
    }
}

/*
Trecho referente ao teste da unidade
*/

TesteMatricula::TesteMatricula() {
    //zera a variavel para o codigo temporario
    matriculaTemp = '\0';
}

void TesteMatricula::setUp(Matricula alvo) {
    //Armazena o valor do codigo do alvo
    matriculaTemp = alvo.getMatricula();
}

void TesteMatricula::tearDown(Matricula alvo) {
    //atribui de volta o valor temporario
    try{
        alvo.setMatricula(matriculaTemp);
    } catch(invalid_argument& erro){
        cout << erro.what() << endl;
    }

}


void TesteMatricula::run(Matricula alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto matricula com matricula igual a " << alvo.getMatricula() << endl ;
    cout << "testando valor '12345' (Valido)             : ";
    try {
        alvo.setMatricula("12345");
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
    cout << "Testando valor '1234' (Invalido, length != 5) : " ;

    try {
        alvo.setMatricula("1234");
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

    cout << "Testando valor '1234A' (Invalido, nao númerico) : " ;

    try {
        alvo.setMatricula("1234A");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

}

