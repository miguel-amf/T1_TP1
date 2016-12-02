#include "MIU_Projetos.h"

#include <iostream>

MIU_Projetos::MIU_Projetos(MRN_Projetos* mrn)
{
    regrasNegProjetos = mrn;
    clearance = mrn->getClearance();
}


void MIU_Projetos::run() throw (runtime_error)
{
    try {
        switch(clearance) {
            case 0: menuDesenvolvedor();
                    break;
            case 1: menuGProjeto();
                    break;
            case 2: menuGSistema();
                    break;
            default: throw runtime_error("Autenticacao para acessar modulo falhou");

        }
    } catch (runtime_error e) {
        throw e;
    }
}

void MIU_Projetos::menuDesenvolvedor() throw (runtime_error) {

    cout << endl << "Voce nao tem permissao para acessar este modulo" << endl;

}
void MIU_Projetos::menuGProjeto() throw (runtime_error)
{
    int escolha = 0;
    while(escolha == 0) {
        cout << endl    << "Você gostaria de: " << endl
                << "(1) Cadastrar Projeto" << endl
                << "(2) Descadastrar Projeto" << endl
                << "(3) Visualizar/Alterar Projeto" << endl
                << "(4) Associar Desenvolvedor" << endl;
        cin >> escolha;
    }
    try {
        switch (escolha) {
            case 1: cadastrar(); break;
            case 2: descadastrar(); break;
            case 3: alterar(); break;
            case 4: associar(); break;
            default: throw runtime_error("Erro ao Interpretar escolha no MIU_Projeto");
        }
    }  catch (runtime_error e) {
        throw e;
    }





}

void MIU_Projetos::menuGSistema() throw (runtime_error)
{
    cout << endl << "Voce nao tem permissao para acessar este modulo" << endl;
}


void MIU_Projetos::cadastrar() throw (runtime_error)
{
    Projeto projetoNovo;
    string input;
    int terminou = 0;
    float valor;
    while (!terminou){
            try {
                cout << "Codigo Projeto (5 letras): ";
                cin >> input;
                CodigoProjeto cod;
                cod.setCodigo(input);
                projetoNovo.setCodigoProjeto(cod);

                cout << "Nome do Projeto (letras): ";
                cin.get();
                getline(cin,input,'\n');
                cin.get();
                Nome nome;
                nome.setNome(input);
                projetoNovo.setNome(nome);


                cout << endl << "Matricula do Gerente (5 numeros): ";
                cin >> input;
                GerenteProjeto gerente;
                Matricula mat;
                mat.setMatricula(input);
                gerente.setMatricula(mat);
                projetoNovo.setGerenteProjeto(gerente);

                cout << "Custo Previsto (float): ";
                cin >> valor;
                Custo custo;
                custo.setCusto(valor);
                projetoNovo.setCustoPrevisto(custo);

                cout << "Custo Atual (float): ";
                cin >> valor;
                custo.setCusto(valor);
                projetoNovo.setCustoAtual(custo);

                cout << "Data de Inicio (dd/mm/aaaa): ";
                cin >> input;
                Data data;
                data.setData(input);
                projetoNovo.setDataInicio(data);

                cout << "Data de Termino (dd/mm/aaaa): ";
                cin >> input;
                data.setData(input);
                projetoNovo.setDataTermino(data);

                regrasNegProjetos->criarProjeto(projetoNovo);

                cout << "Registro criado com sucesso!";

                terminou = 1;






            }  catch (runtime_error e) {
                throw e;
            } catch (invalid_argument e) {
                cout << endl << e.what() << endl << "Recomecando: " << endl;
            }
    }

}
//3
void MIU_Projetos::descadastrar() throw (runtime_error)
{
    string input;
    try {
        cout << "Digite a matricula do projeto a ser descadastrado: ";
        cin >> input;
        CodigoProjeto cod;
        cod.setCodigo(input);
        if(regrasNegProjetos->fecharProjeto(cod)) {
            cout << "Projeto fechado com sucesso!";
        } else {
            cout << "Erro ao descadastrar projeto";
        }


    }  catch (runtime_error e) {
        throw e;
    }
}

//4
void MIU_Projetos::associar() throw (runtime_error)
{
    string input;
    try {
        cout << "Digite o codigo do Projeto para remover/adicionar desenvolvedor: ";
        cin >> input;
        CodigoProjeto cod;
        cod.setCodigo(input);
        Projeto proj = regrasNegProjetos->getProjeto(cod);

        cout << "Digite a matricula do desenvolvedor: ";
        cin >> input;
        Matricula mat;
        mat.setMatricula(input);

        cout << "Deseja remover ou adicionar? (R/A) : ";
        cin >> input;
        if (!input.compare("R") || !input.compare("r")) {
            if(proj.remDesenvolvedor(mat)) {
                //remove da persistencia (ao menos tenta)
                regrasNegProjetos->editarProjeto(proj.getCodigoProjeto(), proj);
                cout << "Desenvolvedor removido com sucesso";
            } else {
                cout << "Desenvolvedor nao encontrado";
            }
        } else if(!input.compare("A") || !input.compare("a")) {
            //TO-DO: checa na persistencia se existe desenvolvedor com aquela mat
            Desenvolvedor des;
            mat.setMatricula(input);
            des.setMatricula(mat);
            if(proj.setDesenvolvedor(des)) {

                cout << "Desenvolvedor inserido com sucesso";
            } else {
                cout << "Quantidade maxima de desenvolvedores atingida";
            }
        }

    }  catch (runtime_error e) {
        throw e;
    }
}

void MIU_Projetos::alterar() throw (runtime_error)
{
        string input;
    int terminou = 0;
    float valor;
    try {

        Projeto projetoNovo;



        while (!terminou){
            try {

                cout << "Digite o codigo do Projeto a ser alterado: ";
                cin >> input;
                CodigoProjeto cod;
                cod.setCodigo(input);
                Projeto p = regrasNegProjetos->getProjeto(cod);
                if (p.getCodigoProjeto().getCodigo().compare(cod.getCodigo())) {
                    cout << "projeto nao encontrado";
                    terminou =1;
                } else {
                    cout << "Projeto Localizado. iniciando alteracao, caso queira manter um campo inalterado, escreva skip no valor" << endl;
                }


                cout << "Nome do Projeto (letras): ";
                cin.get();
                getline(cin,input,'\n');
                cin.get();
                if (input.compare("skip")) {
                    Nome nome;
                    nome.setNome(input);
                    projetoNovo.setNome(nome);
                }



                cout << endl << "Matricula do Gerente (5 numeros): ";
                cin >> input;
                if (input.compare("skip")) {
                    GerenteProjeto gerente;
                    Matricula mat;
                    mat.setMatricula(input);
                    gerente.setMatricula(mat);
                    projetoNovo.setGerenteProjeto(gerente);
                }

                cout << "Custo Previsto (float) (0 para nao mudar): ";
                cin >> valor;
                Custo custo;
                if (valor != 0) {
                custo.setCusto(valor);
                projetoNovo.setCustoPrevisto(custo);
                }
                cout << "Custo Atual (float) (0 para nao mudar): ";
                cin >> valor;
                if (valor != 0) {
                custo.setCusto(valor);
                projetoNovo.setCustoAtual(custo);
                }

                cout << "Data de Inicio (dd/mm/aaaa): ";
                cin >> input;
                Data data;
                if (input.compare("skip")) {
                data.setData(input);
                projetoNovo.setDataInicio(data);
                }

                cout << "Data de Termino (dd/mm/aaaa): ";
                cin >> input;
                if (input.compare("skip")) {
                data.setData(input);
                projetoNovo.setDataTermino(data);
                }
                regrasNegProjetos->criarProjeto(projetoNovo);

                cout << "Registro criado com sucesso!";

                terminou = 1;






            }  catch (runtime_error e) {
                throw e;
            } catch (invalid_argument e) {
                cout << endl << e.what() << endl << "Recomecando: " << endl;
            }
    }
    }  catch (runtime_error e) {
        throw e;
    }
}
