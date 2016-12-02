#include "MRN_Projetos.h"

#include <iostream>

MRN_Projetos::MRN_Projetos()
{
    clearance = 0;
}

void MRN_Projetos::allProjetos() throw (runtime_error)
{
    if(clearance != 1) {
        throw runtime_error("Acesso Negado, voce nao tem permissao");
    }
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

    cout    << "Nome: Banco de Dados do Sistema" << endl
            << "Codigo Projeto: EDCBA" << endl
            << "Gerente do Projeto: Usain Bolt"<< endl
            << "Desenvolvedores: Guilherme Bonobo" << endl
            << "                 Victorino Ponterino" << endl
            << "                 Tomás Tejando" << endl
            << "Custo Atual: R$ 450,000.00" << endl
            << "Custo Previsto: R$ 1,250,000.00" << endl
            << "Data de Inicio: 02/01/2020" << endl
            << "Data de Termino: 20/10/2021" << endl

    ;
}
//ABCDE
Projeto MRN_Projetos::getProjeto(CodigoProjeto cod)  throw (runtime_error)
{
    if(clearance != 1) {
        throw runtime_error("Acesso Negado, voce nao tem permissao");
    }
    if(!cod.getCodigo().compare("AAAAA")) {
        throw runtime_error("Nao foi possivel acessar o banco de dados");
    }
    Projeto proj;
    Nome nome;
    Custo c;
    Data data;
    Desenvolvedor desenvolvedor;
    GerenteProjeto gerenteProj;
    c.setCusto(1000);
    nome.setNome("Sistema Financeiro");


    proj.setCodigoProjeto(cod);
    proj.setNome(nome);
    proj.setCustoAtual(c);
    c.setCusto(1500);
    proj.setCustoPrevisto(c);
    proj.setDataInicio(data);
    data.setData("11/10/2016");
    proj.setDataTermino(data);
    proj.setDesenvolvedor(desenvolvedor);
    proj.setGerenteProjeto(gerenteProj);
    return proj;
}

Projeto MRN_Projetos::getProjeto(Nome nome)  throw (runtime_error)
{
    if(clearance != 1) {
        throw runtime_error("Acesso Negado, voce nao tem permissao");
    }
    if(!nome.getNome().compare("AAAAA")) {
        throw runtime_error("Nao foi possivel acessar o banco de dados");
    }
    Projeto proj;
    Custo c;
    CodigoProjeto cod;
    Data data;
    Desenvolvedor desenvolvedor;
    GerenteProjeto gerenteProj;
    c.setCusto(1000);
    nome.setNome("Sistema Financeiro");


    proj.setCodigoProjeto(cod);
    proj.setNome(nome);
    proj.setCustoAtual(c);
    c.setCusto(1500);
    proj.setCustoPrevisto(c);
    proj.setDataInicio(data);
    data.setData("11/10/2016");
    proj.setDataTermino(data);
    proj.setDesenvolvedor(desenvolvedor);
    proj.setGerenteProjeto(gerenteProj);
    return proj;
}

bool MRN_Projetos::fecharProjeto(CodigoProjeto cod)  throw (runtime_error)
{
    if(clearance != 1) {
        throw runtime_error("Acesso Negado, voce nao tem permissao");
    }
    if(!cod.getCodigo().compare("AAAAA")) {
        throw runtime_error("Nao foi possivel acessar o banco de dados");
    }

    if(!cod.getCodigo().compare("BBBBB")) {
        throw runtime_error("Nao ha projetos com o codigo fornecido");
    }


    return 1;



}

bool MRN_Projetos::editarProjeto(CodigoProjeto cod, Projeto proj)  throw (runtime_error)
{

    if(clearance != 1) {
        throw runtime_error("Acesso Negado, voce nao tem permissao");
    }
    if(!proj.getCodigoProjeto().getCodigo().compare("AAAAA")) {
        throw runtime_error("Nao foi possivel acessar o banco de dados");
    }

    if(!cod.getCodigo().compare("BBBBB")) {
        throw runtime_error("Nao ha projetos com o codigo fornecido");
    }

    return 1;

}

bool MRN_Projetos::criarProjeto(Projeto proj)  throw (runtime_error)
{

    if(clearance != 1) {
        throw runtime_error("Acesso Negado, voce nao tem permissao");
    }
    if(!proj.getCodigoProjeto().getCodigo().compare("AAAAA")) {
        throw runtime_error("Limite de Cadastros por Gerente");
    }

    if(!proj.getCodigoProjeto().getCodigo().compare("BBBBB")) {
        throw runtime_error("Problema com banco de dados");
    }

    return 1;

}
void MRN_Projetos::setClearance(int i)
{
    clearance = i;
}

int MRN_Projetos::getClearance()
{
   return clearance;
}
