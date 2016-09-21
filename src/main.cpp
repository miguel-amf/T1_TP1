
using namespace std;

#include "CodigoProjeto.h"
#include "EstadoProjeto.h"
#include "FaseProjeto.h"
#include "Data.h"
#include "Nome.h"
#include <iostream>

int main() {

    Data b;
    TesteData test;

    try {
        b.setData("05/05/2025");
    } catch (invalid_argument) {

    }


    test.setUp(b);
    test.run(b);
    test.tearDown(b);

    cout << endl << b.getData() << endl;

    return 0;
}
