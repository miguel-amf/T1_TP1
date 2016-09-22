#include "Nome.h"
#include <string> //string
#include <stdexcept> //invalid_argument
#include <iostream> //cout, endl

using namespace std;

/*
* inicio da implementacao da classe nome
*/

Nome::Nome() {

    nome = "null null";

}

string Nome::getNome() const {
    return nome;
}

void Nome::setNome(string entrada) throw(invalid_argument) {

    try {
        avalia(entrada);
    } catch (invalid_argument& erro){
        throw erro;
    }

    nome = entrada;
}

void Nome::avalia(string entrada) throw(invalid_argument){

    int i = 0;

    if(entrada.length() > 20 ) {
        throw invalid_argument("nome muito longo");
    }

    for(i = 0; entrada[i] != '\0'; i++) {

        if (!(isalpha(entrada[i]) || entrada[i] == ' ')) {
            throw invalid_argument("nome contem caracteres invalidos");
        }
    }

}


/*
* inicio da implementacao da classe TesteNome
*/

TesteNome::TesteNome() {
    nomeTemp = "";
}

void TesteNome::setUp(Nome entrada) {
    nomeTemp = entrada.getNome();
}

void TesteNome::tearDown(Nome entrada) {
    try {
        entrada.setNome(nomeTemp);
    } catch(invalid_argument) {
        //virtualmente impossivel de acontecer, pois recebeu o valor oriundo do proprio objeto
        cout << endl << "Erro, nomeTemp nao armazenou valor valido";
    }
}

void TesteNome::run(Nome alvo) {

//flag para alertar o teste entrou no catch
    int flagCatch = 0;
    cout << "Iniciando os Testes no objeto de Nome com nome igual a " << alvo.getNome() << endl ;
    cout << "testando valor 'Edsger Wybe Dijkstra' (Valido)        : ";
    try {
        alvo.setNome("Edsger Wybe Dijkstra");
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
    cout << "Testando valor 'cincocincocincocincoum' (Invalido, >20) : ";

    try {
        alvo.setNome("cincocincocincocincoum");
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

    cout << "Testando valor 'Henrique 3' (Invalido, nao-alpha) : " ;

    try {
        alvo.setNome("Henrique 3");
    } catch(invalid_argument& erro) {
        flagCatch = 1;
        cout << "APROVADO (" << erro.what() << ")" << endl;
    }

    //testando para ver se entrou no catch
    if (flagCatch == 0) {
        cout << "REPROVADO (Aceitou o valor)" << endl;
    }




}
