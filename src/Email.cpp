#include "Email.h"
#include <stdexcept>
#include <string>
#include <iostream>

Email::Email()
{
    email = "notvalid@notvalid.com";
}

string Email::getEmail(){
    return email;
}

void Email::setEmail(string novoEmail) throw(invalid_argument){
    try{
        avalia(novoEmail);
    } catch(invalid_argument& erro){
        throw erro;
    }
    email = novoEmail;
}

void Email::avalia(string entrada) throw(invalid_argument){
    int flagAt = 1;
    int flagDomain = 1;

    for (int i=0; entrada[i] != '\0'; i++){
        if( entrada[i] == '@'){
            if(flagAt == 0){
                throw invalid_argument("Só deve existir um caractere @.");
            }
            flagAt = 0;
        }
        if (flagAt == 0 && entrada[i] == '.'){
            flagDomain = 0;
        }
    }
    if(flagAt){
        throw invalid_argument("Formato invalido.Não possui @.");
    }
    if(flagDomain){
        throw invalid_argument("Formato invalido.Não possui dominio.");
    }
}

/*
Trecho referente ao teste da unidade
*/

TesteEmail::TesteEmail() {
    //zera a variavel para o codigo temporario
    emailTemp = '\0';
}

void TesteEmail::setUp(Email alvo) {
    //Armazena o valor do codigo do alvo
    emailTemp = alvo.getEmail();
}

void TesteEmail::tearDown(Email alvo) {
    //atribui de volta o valor temporario
    try{
        alvo.setEmail(emailTemp);
    } catch(invalid_argument& erro){
        cout << erro.what() << endl;
    }

}


void TesteEmail::run(Email alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto email com email igual a " << alvo.getEmail() << endl ;
    cout << "testando valor 'teste@gmail.com' (Valido)             : ";
    try {
        alvo.setEmail("teste@gmail.com");
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

    //Teste de @
    cout << "Testando valor 'testegmail.com' (Invalido, nao possui @) : " ;

    try {
        alvo.setEmail("testegmail.com");
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

}

