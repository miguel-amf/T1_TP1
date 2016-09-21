
using namespace std;

#include "CodigoProjeto.h"
#include "EstadoProjeto.h"
#include "FaseProjeto.h"
#include "Data.h"
#include "Nome.h"
#include <iostream>

int main() {

    Nome b;
    TesteNome test;

    try {
        b.setNome("Galileu Galilei");
    } catch (invalid_argument) {
        cout << endl << "deu ruim" << endl;
    }


    test.setUp(b);
    test.run(b);
    test.tearDown(b);

    cout << endl << b.getNome() << endl;

    return 0;
}
