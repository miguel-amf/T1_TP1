
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
#include "GerenteProjeto.h"
#include "MRN_Autenticacao.h"
#include "MIU_Autenticacao.h"
#include "Projeto.h"
#include "IRN_Projetos.h"
#include "MRN_Pessoa.h"
#include "MIU_Pessoa.h"
#include "MRN_Projetos.h"
#include "MIU_Projetos.h"
#include "M_Persistencia.h"
#include <vector>

int getPermissao(Pessoa* usuario){
    if(dynamic_cast<Desenvolvedor*>(usuario)){
        return 0;
    } else if(dynamic_cast<GerenteProjeto*>(usuario)){
        return 1;
    } else if(dynamic_cast<GerenteSistema*>(usuario)){
        return 2;
    }
}

int main() {

    M_Persistencia persistencia;
    MIU_Autenticacao gui_auth;
    MRN_Autenticacao m_auth;
    m_auth.setPersistencia(&persistencia);
    MRN_Projetos mrn_proj;

    gui_auth.setMRN(&m_auth);
    MRN_Pessoa m_pessoa;
    Pessoa* usuario = gui_auth.run();
    int permissao = getPermissao(usuario);


    MIU_Pessoa iu_pessoa(usuario,permissao);

    int escolha;
    while (true) {
        cout    << "Bem vindo, " << usuario->getNome().getNome() << endl
                << "Escolha um dos itens abaixo: " << endl
                << "(1) Gestao de Pessoas" << endl
                << "(2) Gestao de Projetos" << endl
                << "(3) Sair" << endl;
        cin >> escolha;
        if (escolha == 3) {
            cout << "saindo do sistema";
            return 0;
        }

        if (escolha == 1) {
            iu_pessoa.setMRN(&m_pessoa);
            iu_pessoa.menu();
        }
        if (escolha == 2) {
            mrn_proj.setClearance(permissao);
            MIU_Projetos miu_proj(&mrn_proj);

            try{
                miu_proj.run();
            }catch (runtime_error e){
                cout << endl << e.what() <<endl;
            }
        }
    }

    return 0;
}
