#include "MIU_Pessoa.h"

#include "Pessoa.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Desenvolvedor.h"
#define MENU_SIZE 2

MIU_Pessoa::MIU_Pessoa(Pessoa* pessoa){
    usuario = pessoa;
}

void MIU_Pessoa::menu(int permissao){
    int option = -1;
    vector<string> actual; // Será atribuido as funcionalidades permitidas
    vector<string> dev; // Desenvolvedor
    vector<string> gerente; // Gerente de projeto
    vector<string> admin; // Gerente de sistema
    string result;

    dev.push_back("Sair");
    dev.push_back("Listar");

    actual = dev;

    while (option != 0){
        for (int i = 0; i< actual.size(); i++){
            cout << i << " -> " << actual.at(i) << endl;
        }
        cout << "Escolha uma opcao: ";
        cin >> option;

        result = actual.at(option);
        if(!result.compare("Listar")){
            MIU_Pessoa::listar();
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
        } else if (GerenteProjeto* gerente = dynamic_cast<GerenteProjeto*>(pessoa)){
            cout << "Telefone: " << gerente->getTelefone().getNumero() << endl;
        }
        cout << endl << endl;
    } catch (runtime_error error) {
        cout << error.what() << endl;
    }
    catch (bad_cast error){
        cout << error.what() << endl;
    }
}

void MIU_Pessoa::setMRN(IRN_Pessoa* novoMRN){
    MRN = novoMRN;
}
