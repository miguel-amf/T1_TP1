
using namespace std;

#include "CodigoProjeto.h"
#include "EstadoProjeto.h"
#include "FaseProjeto.h"
#include "Data.h"
#include "Nome.h"
#include "Telefone.h"
#include <iostream>

int main() {

//    Nome b;
//    TesteNome test;
//
//    try {
//        b.setNome("Galileu Galilei");
//    } catch (invalid_argument) {
//        cout << endl << "deu ruim" << endl;
//    }
//
//
//    test.setUp(b);
//    test.run(b);
//    test.tearDown(b);

    Telefone b;
    TesteTelefone test;

    try {
        b.setNumero("87654321");
    } catch (invalid_argument& erro) {
        cout << endl << erro.what() << endl;
    }


    test.setUp(b);
    test.run(b);
    test.tearDown(b);

    cout << endl << b.getNumero() << endl;

    return 0;
}
