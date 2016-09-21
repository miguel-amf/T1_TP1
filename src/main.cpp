
using namespace std;

#include "Funcao.h"
#include "Custo.h"
#include "CodigoProjeto.h"
#include "EstadoProjeto.h"
#include "FaseProjeto.h"
#include "Data.h"
#include "Nome.h"
#include "Telefone.h"
#include "Senha.h"
#include "Matricula.h"
#include "Email.h"
#include <iostream>
#include <stdio.h>

int main() {

    CodigoProjeto codigoProjeto;
    TesteCodigoProjeto testeCodP;

    testeCodP.setUp(codigoProjeto);
    testeCodP.run(codigoProjeto);
    testeCodP.tearDown(codigoProjeto);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    Data data;
    TesteData testeData;

    testeData.setUp(data);
    testeData.run(data);
    testeData.tearDown(data);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    EstadoProjeto estadoProjeto;
    TesteEstadoProjeto testeEstadoP;

    testeEstadoP.setUp(estadoProjeto);
    testeEstadoP.run(estadoProjeto);
    testeEstadoP.tearDown(estadoProjeto);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    Funcao funcao;
    TesteFuncao testeF;

    testeF.setUp(funcao);
    testeF.run(funcao);
    testeF.tearDown(funcao);


    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    // Testando Dominio Nome
    Nome b;
    TesteNome test;

    test.setUp(b);
    test.run(b);
    test.tearDown(b);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    // Testando Dominio Telefone
    Telefone telefone;
    TesteTelefone testeTelefone;

    testeTelefone.setUp(telefone);
    testeTelefone.run(telefone);
    testeTelefone.tearDown(telefone);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    Senha senha;
    TesteSenha testeSenha;

    testeSenha.setUp(senha);
    testeSenha.run(senha);
    testeSenha.tearDown(senha);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    Matricula matricula;
    TesteMatricula testeMatricula;

    testeMatricula.setUp(matricula);
    testeMatricula.run(matricula);
    testeMatricula.tearDown(matricula);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();

    Email email;
    TesteEmail testeEmail;

    testeEmail.setUp(email);
    testeEmail.run(email);
    testeEmail.tearDown(email);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();


    FaseProjeto faseP;
    TesteFaseProjeto testeFaseP;

    testeFaseP.setUp(faseP);
    testeFaseP.run(faseP);
    testeFaseP.tearDown(faseP);

    cout << "Pressione enter para continuar ..." << endl;
    getchar();


    Custo custo;
    TesteCusto testeCusto;

    testeCusto.setUp(custo);
    testeCusto.run(custo);
    testeCusto.tearDown(custo);

        cout << "Pressione enter para continuar ..." << endl;
    getchar();



    return 0;
}
