#include "Senha.h"

#include <iostream>
#include <stdexcept>

Senha::Senha()
{
    senha = "ABCDE";
}

void Senha::setSenha(string entrada) throw(invalid_argument){
    try {
        avalia(entrada);
    } catch (invalid_argument& erro) {
        throw erro;
    }

    senha = entrada;
}

string Senha::getSenha() const{
    return senha;
}

void Senha::avalia(string entrada) throw(invalid_argument) {

    if(entrada.length() != 5)
        throw invalid_argument("A senha nao possui 5 caracteres");

    for(int j = 0; j<5; j++){
        for(int i = j + 1; i<5; i++) {
            if (entrada[i] == entrada[j])
                throw invalid_argument("A senha possui caracteres iguais");
        }
    }
}

/*
Trecho referente ao teste da unidade
*/

TesteSenha::TesteSenha() {
    //zera a variavel para o codigo temporario
    senhaTemp = '\0';
}

void TesteSenha::setUp(Senha alvo) {
    //Armazena o valor do codigo do alvo
    senhaTemp = alvo.getSenha();
}

void TesteSenha::tearDown(Senha alvo) {
    //atribui de volta o valor temporario
    try{
        alvo.setSenha(senhaTemp);
    } catch(invalid_argument& erro){
        cout << erro.what() << endl;
    }

}


void TesteSenha::run(Senha alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de senha com senha igual a " << alvo.getSenha() << endl ;
    cout << "testando valor 'ABCDE' (Valido)             : ";
    try {
        alvo.setSenha("ABCDE");
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
    cout << "Testando valor 'ABCD' (Invalido, length != 4) : " ;

    try {
        alvo.setSenha("ABCD");
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

    cout << "Testando valor 'ABCDD' (Invalido, caracter duplicado) : " ;

    try {
        alvo.setSenha("ABCDD");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

}

