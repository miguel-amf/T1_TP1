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
    base.push_back("Editar");

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
            } else if(!result.compare("Editar")){
                MIU_Pessoa:editarPerfil();
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
            cout << "Email: " << dev->getEmail().getEmail() << endl;
            cout << "Funcao: ";
            switch (dev->getFuncao().getFuncao()){
                case 1:
                    cout << "Analista" << endl;
                    break;
                case 2:
                    cout << "Projetista" << endl;
                    break;
                case 3:
                    cout << "Programador" << endl;
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
            cin.get();
            getline(cin,input,'\n');
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
    string input;
    bool repeat = true;
    GerenteProjeto pessoa;
    Nome nome;
    Matricula mat;
    Telefone tel;

    while (repeat){
        try {
            cout << endl << "Insira o Nome da pessoa: " << endl;
            cin.get();
            getline(cin,input,'\n');
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
            cout << endl << "Insira o telefone da pessoa: " << endl;
            cin >> input;
            tel.setNumero(input);
            pessoa.setTelefone(tel);
            repeat = false;
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
void MIU_Pessoa::editarPerfil(){
    if(Desenvolvedor* dev = dynamic_cast<Desenvolvedor*>(usuario)){
        MIU_Pessoa::editarDesenvolvedor(dev);
    } else if(GerenteProjeto* gerente = dynamic_cast<GerenteProjeto*>(usuario)){
        MIU_Pessoa::editarGerenteProjeto(gerente);
    } else if(GerenteSistema* admin = dynamic_cast<GerenteSistema*>(usuario)){
        MIU_Pessoa::editarGerenteSistema(admin);
    }
}

void MIU_Pessoa::editarGerenteSistema(GerenteSistema* admin){
    int editOptions = -1;
    bool repeat = true;
    string input;
    Nome nome;
    Senha senha;

    while(editOptions != 0 && editOptions != 3){
        cout << "0 -> Sair" << endl;
        cout << "1 -> Nome: " << admin->getNome().getNome() << endl;
        cout << "X -> Matricula: " << admin->getMatricula().getMatricula() << endl;
        cout << "2 -> Senha" << endl;
        cout << "3 -> Enviar atualizacoes" << endl;
        cout << "Escolha o numero do campo que deseja editar"<< endl <<"(para finalizar selecione a opcao 3):" << endl;
        cin.get();
        cin >> editOptions;
        switch(editOptions){
            case 1:
                while (repeat){
                    try {
                        cout << endl << "Insira o novo Nome: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        nome.setNome(input);
                        admin->setNome(nome);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                repeat = true;
                break;
            case 2:
                while(repeat){
                    try{
                        cout << endl << "Insira a nova senha: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        senha.setSenha(input);
                        admin->setSenha(senha);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                break;
            case 3:
                try {
                    MRN->editarPessoa(admin,admin->getMatricula());
                    cout << "Perfil atualizado com sucesso" << endl;
                } catch (runtime_error error){
                    cout << "Erro no cadastramento" << endl;
                }
                break;

        }
    }
}

void MIU_Pessoa::editarGerenteProjeto(GerenteProjeto* gerente){
int editOptions = -1;
    bool repeat = true;
    string input;
    Nome nome;
    Senha senha;
    Telefone tel;

    while(editOptions != 0 && editOptions != 4){
        cout << "0 -> Sair" << endl;
        cout << "1 -> Nome: " << gerente->getNome().getNome() << endl;
        cout << "X -> Matricula: " << gerente->getMatricula().getMatricula() << endl;
        cout << "2 -> Senha" << endl;
        cout << "3 -> Telefone: " << gerente->getTelefone().getNumero() << endl;
        cout << "4 -> Enviar atualizacoes" << endl;
        cout << "Escolha o numero do campo que deseja editar"<< endl <<"(para finalizar selecione a opcao 3):" << endl;
        cin.get();
        cin >> editOptions;
        switch(editOptions){
            case 1:
                while (repeat){
                    try {
                        cout << endl << "Insira o novo Nome: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        nome.setNome(input);
                        gerente->setNome(nome);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                repeat = true;
                break;
            case 2:
                while(repeat){
                    try{
                        cout << endl << "Insira a nova senha: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        senha.setSenha(input);
                        gerente->setSenha(senha);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                break;
            case 3:
                while(repeat){
                    try{
                        cout << endl << "Insira o novo telefone: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        tel.setNumero(input);
                        gerente->setTelefone(tel);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
            case 4:
                try {
                    MRN->editarPessoa(gerente,gerente->getMatricula());
                    cout << "Perfil atualizado com sucesso" << endl;
                } catch (runtime_error error){
                    cout << "Erro no cadastramento" << endl;
                }
                break;

        }
    }
}

void MIU_Pessoa::editarDesenvolvedor(Desenvolvedor* dev){
    int editOption = -1;
    int fun = 0;
    string input;
    bool repeat = true;
    Senha senha;
    GerenteProjeto pessoa;
    Nome nome;
    Matricula mat;
    Email email;
    Funcao func;

    while(editOption != 0 && editOption != 5){
        cin.clear();
        cout << endl << endl;
        cout << "0 -> Sair" << endl;
        cout << "1 -> Nome: " << dev->getNome().getNome() << endl;
        cout << "X -> Matricula: " << dev->getMatricula().getMatricula() << endl;
        cout << "2 -> " << dev->getEmail().getEmail() << endl;
        cout << "3 -> Funcao: ";
        switch (dev->getFuncao().getFuncao()){
            case 1:
                cout << "Analista" << endl;
                break;
            case 2:
                cout << "Projetista" << endl;
                break;
            case 3:
                cout << "Programador" << endl;
                break;
            default:
                cout << "Error" << endl;
                break;
        }
        cout << "4 -> Senha" << endl;
        cout << "5 -> Enviar atualizacoes" << endl;
        cout << "Escolha o numero do campo que deseja editar"<< endl <<"(para finalizar selecione a opcao 5):" << endl;
        cin.get();
        cin >> editOption;
        switch (editOption){
            case 1:
                while (repeat){
                    try {
                        cout << endl << "Insira o novo Nome: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        nome.setNome(input);
                        dev->setNome(nome);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                repeat = true;
                break;
            case 2:
                while (repeat){
                    try {
                        cout << endl << "Insira o novo email: " << endl;
                        cin >> input;
                        email.setEmail(input);
                        dev->setEmail(email);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                repeat = true;
                break;
            case 3:
                while (!fun){
                    try {
                        cout << endl << "Escolha a nova funcao: " << endl;
                        cout << "1 -> Analista" << endl;
                        cout << "2 -> Projetista" << endl;
                        cout << "3 -> Programador" << endl;
                        cin >> fun;

                        func.setFuncao(fun);
                        dev->setFuncao(func);
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                fun = 0;
                break;
            case 4:
                while(repeat){
                    try{
                        cout << endl << "Insira a nova senha: " << endl;
                        cin.get();
                        getline(cin,input,'\n');
                        senha.setSenha(input);
                        dev->setSenha(senha);
                        repeat = false;
                    } catch (invalid_argument error){
                        cout << error.what() << endl;
                    }
                }
                break;
            case 5:
                try {
                    MRN->editarPessoa(dev,dev->getMatricula());
                    cout << "Perfil atualizado com sucesso" << endl;
                } catch (runtime_error error){
                    cout << "Erro no cadastramento" << endl;
                }
                break;
        }
    }
}
