#include "MRN_Projetos.h"

#include <iostream>

MRN_Projetos::MRN_Projetos()
{
    //ctor
}

void MRN_Projetos::allProjetos() throw (runtime_error)
{
    cout    << "Nome: Desenvolvimento Web" << endl
            << "Codigo Projeto: ABCDE" << endl
            << "Gerente do Projeto: Alan Turing"<< endl
            << "Desenvolvedores: Renato Caetano" << endl
            << "                 Dorivaldo Felicio" << endl
            << "                 Vitao Steps Bridges" << endl
            << "Custo Atual: R$ 250,000.00" << endl
            << "Custo Previsto: R$ 750,000.00" << endl
            << "Data de Inicio: 30/02/2020" << endl
            << "Data de Termino: 31/11/2024" << endl

    ;
}

Projeto MRN_Projetos::getProjeto(CodigoProjeto cod)  throw (runtime_error)
{

}

Projeto MRN_Projetos::getProjeto(Nome nome)  throw (runtime_error)
{

}

void MRN_Projetos::coutProjeto(CodigoProjeto cod)  throw (runtime_error)
{

}

void MRN_Projetos::coutProjeto(Nome nome)  throw (runtime_error)
{

}

bool MRN_Projetos::fecharProjeto(CodigoProjeto cod)  throw (runtime_error)
{

}

bool MRN_Projetos::editarProjeto(CodigoProjeto cod, Projeto proj)  throw (runtime_error)
{

}
