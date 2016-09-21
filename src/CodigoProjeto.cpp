#include "CodigoProjeto.h"

#include <string> //para string
#include <stdexcept> //para invalid_argument
#include <iostream> //para cout

using namespace std;

/*
Trecho para implementacao do CodigoProjeto
*/

//Construtor
CodigoProjeto::CodigoProjeto()
{
    this->codigo = "NULLO";
}

//metodo get
string CodigoProjeto::getCodigo() const {
    return this->codigo;
}

//metodo set
void CodigoProjeto::setCodigo(string novoValor) throw(invalid_argument) {
    //para o for
    int i = 0;

    //chama a funcao valida para novoValor
    try {
        valida(novoValor);
    } catch (invalid_argument& erro) {
        //apenas propaga o erro
        throw erro;
    }

    /*
    coloca os caracteres em caixa alta
    a chamada da funcao valida acima assegura que esta operacao nao sera
    feita em valores nao alfabeticos
    */
    for(i=0;novoValor[i] != '\0'; i++) {

        if (novoValor[i] >= 97) {
            novoValor[i] = novoValor[i] - 32;
        }
    }


    //atribui o valor para codigo
    this->codigo = novoValor;
}


//metodo privado auxiliar para validar no formato
void CodigoProjeto::valida(string entrada) throw(invalid_argument) {

    int i;

    /*verifica se tem 5 caracteres*/
    if(entrada.length() != 5) {
        throw invalid_argument("Codigo de Projeto nao possui 5 caracteres");
    }

    /*verifica se todos sao apenas letras*/
    for(i=0;entrada[i] != '\0'; i++) {
        if (!isalpha(entrada[i])) {
            throw invalid_argument("Codigo de Projeto possui caracteres nao alfabeticos");
        }
    }

}


/*
Trecho referente ao teste da unidade
*/

TesteCodigoProjeto::TesteCodigoProjeto() {
    //zera a variavel para o codigo temporario
    codigoTemp = '\0';
}

void TesteCodigoProjeto::setUp(CodigoProjeto alvo) {
    //Armazena o valor do codigo do alvo
    codigoTemp = alvo.getCodigo();
}

void TesteCodigoProjeto::tearDown(CodigoProjeto alvo) {
    //atribui de volta o valor temporario
    alvo.setCodigo(codigoTemp);
}

void TesteCodigoProjeto::run(CodigoProjeto alvo) {

    //flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de Codigo de Projeto com codigo igual a " << alvo.getCodigo() << endl ;
    cout << "testando valor 'ABCDE' (Valido)             : ";
    try {
        alvo.setCodigo("ABCDE");
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
    cout << "Testando valor 'ABC' (Invalido, lenght < 5) : " ;

    try {
        alvo.setCodigo("ABC");
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

    cout << "Testando valor 'ABCD3' (Invalido, nao alfa) : " ;

    try {
        alvo.setCodigo("ABCD3");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }

}
