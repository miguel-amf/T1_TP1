
using namespace std;

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


    Custo custo;
    TesteCusto testeCusto;

    testeCusto.setUp(custo);
    testeCusto.run(custo);
    testeCusto.tearDown(custo);

        cout << "Pressione enter para continuar ..." << endl;
    getchar();



    return 0;
}
