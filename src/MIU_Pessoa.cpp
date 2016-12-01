#include "MIU_Pessoa.h"

#include "Pessoa.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Desenvolvedor.h"
#define MENU_SIZE 2

MIU_Pessoa::MIU_Pessoa(Pessoa* pessoa, int codigo){
    usuario = pessoa;
    permissao = codigo;
}

void MIU_Pessoa::setMRN(IRN_Pessoa* novoMRN){
    MRN = novoMRN;
}

void MIU_Pessoa::menu(){
    int option = -1;
    vector<string> actual; // Será atribuido as funcionalidades permitidas
    vector<string> base; // Acoes basicas a todos e Desenvolvedor
    vector<string> gerente; // Gerente de projeto
    vector<string> admin; // Gerente de sistema
    string result;

    base.push_back("Sair");
    base.push_back("Listar");

    gerente = base;
    gerente.push_back("Cadastrar Desenvolvedor");


    admin = base;
    admin.push_back("Cadastrar Gerente de Projetos");


    actual = base;
    if(permissao == 1){
        actual = gerente;
    } else if(permissao == 2 ){
        actual = admin;
    }

    while (option != 0){
        for (int i = 0; i< actual.size(); i++){
            cout << i << " -> " << actual.at(i) << endl;
        }
        cout << "Escolha uma opcao: ";
        cin >> option;

        if(option >= 0 && option <= actual.size()){
            result = actual.at(option);
            if(!result.compare("Listar")){
                MIU_Pessoa::listar();
            } else if(!result.compare("Cadastrar Desenvolvedor")){
                MIU_Pessoa::criarDesenvolvedor();
            } else if(!result.compare("Cadastrar Gerente de Projetos")){
                MIU_Pessoa::criarGerente();
            }
        }

    }
}

void MIU_Pessoa::listar(){
    vector<Pessoa>* pessoas;
    int show = -1;

    while (show != 0){
        cout << "0 -> Sair" << endl;
        pessoas = MRN->todasPessoas();
        for (int i=0; i<pessoas->size();i++){
            cout << (i + 1) << " -> " << pessoas->at(i).getMatricula().getMatricula() << " " << pessoas->at(i).getNome().getNome() << endl;
        }
        cout << " Digite '0' para sair ou o numero do usuario que deseja visualizar e pressione enter:";
        cin >> show;
        if(show != 0 && show <= pessoas->size()){
            MIU_Pessoa::exibir(pessoas->at(show - 1).getMatricula());
        }
    }
}

void MIU_Pessoa::exibir(Matricula mat){
    Pessoa* pessoa;
    int option;

    try {
        pessoa = MRN->getPessoa(mat);
        cout << endl << endl;
        cout << "Nome: " << pessoa->getNome().getNome() << endl;
        cout << "Matricula: " << pessoa->getMatricula().getMatricula() << endl;
        //Exibir de desenvolvedor
        if(Desenvolvedor* dev = dynamic_cast<Desenvolvedor*>(pessoa)){
            cout << dev->getEmail().getEmail();
            cout << "Funcao: ";
            switch (dev->getFuncao().getFuncao()){
                case 1:
                    cout << "Analista" << endl;
                    break;
                case 2:
                    cout << "Projetista" << endl;
                    break;
                case 3:
                    cout << "Programdor" << endl;
                    break;
                default:
                    cout << "Error" << endl;
                    break;
            }

            if( permissao == 1 ){
                cout << "0 -> Sair" << endl;
                cout << "1 -> deletar" << endl;
                cin >> option;
                if (option == 1){
                    MIU_Pessoa::deletarPessoa(pessoa->getMatricula());
                }
            }
        } else if (GerenteProjeto* gerente = dynamic_cast<GerenteProjeto*>(pessoa)){
            cout << "Telefone: " << gerente->getTelefone().getNumero() << endl;
            if( permissao == 2 ){
                cout << "0 -> Sair" << endl;
                cout << "1 -> deletar" << endl;
                cin >> option;
                if (option == 1){
                    MIU_Pessoa::deletarPessoa(pessoa->getMatricula());
                }
            }
        }
        cout << endl << endl;
    } catch (runtime_error error) {
        cout << error.what() << endl;
    }
    catch (bad_cast error){
        cout << error.what() << endl;
    }
}

void MIU_Pessoa::deletarPessoa(Matricula mat){
    if(MRN->deletarPessoa(mat)){
        cout << "Usuario deletado com sucesso." << endl << endl;
    } else {
        cout << "Usuario não pode ser deletado, pois esta em projetos ativos!"<< endl << endl;
    }
}

void MIU_Pessoa::criarDesenvolvedor(){
    string input;
    bool repeat = true;
    Desenvolvedor pessoa;
    Nome nome;
    Matricula mat;
    Email email;
    Funcao func;
    int fun = 0;

    while (repeat){
        try {
            cout << endl << "Insira o Nome da pessoa: " << endl;
            cin >> input;
            nome.setNome(input);
            pessoa.setNome(nome);
            repeat = false;
        } catch (invalid_argument error){
            cout << error.what() << endl;
        }
    }
    repeat = true;

    while (repeat){
        try {
            cout << endl << "Insira a matricula: " << endl;
            cin >> input;
            mat.setMatricula(input);
            pessoa.setMatricula(mat);
            repeat = false;
        } catch (invalid_argument error){
            cout << error.what() << endl;
        }
    }
    repeat = true;
    while (repeat){
        try {
            cout << endl << "Insira o email da pessoa: " << endl;
            cin >> input;
            email.setEmail(input);
            pessoa.setEmail(email);
            repeat = false;
        } catch (invalid_argument error){
            cout << error.what() << endl;
        }
    }
    while (!fun){
        try {
            cout << endl << "Escolha a funcao do desenvolvedor: " << endl;
            cout << "1 -> Analista" << endl;
            cout << "2 -> Projetista" << endl;
            cout << "3 -> Programador" << endl;
            cin >> fun;

            func.setFuncao(fun);
            pessoa.setFuncao(func);
        } catch (invalid_argument error){
            cout << error.what() << endl;
        }
    }
    try {
        MRN->cadastrarPessoa(pessoa);
        cout << endl << "Usuario cadastrado com sucesso" << endl;
    } catch (runtime_error error){
        cout << error.what() << endl;
    }
}

void MIU_Pessoa::criarGerente(){
}
