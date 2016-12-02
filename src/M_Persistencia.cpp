#include "M_Persistencia.h"
#include <iostream>
M_Persistencia::M_Persistencia()
{
    //ctor
}

void M_Persistencia::editarProjeto(Projeto proj, CodigoProjeto cod) throw(runtime_error)
{

}

void M_Persistencia::cadastrarProjeto(Projeto proj) throw(runtime_error)
{

}

Projeto M_Persistencia::getProjeto(CodigoProjeto cod) throw(runtime_error)
{
    if(!cod.getCodigo().compare("AAAAA")) {
        throw runtime_error("Nao foi possivel acessar o banco de dados");
    }
    Projeto proj;
    Nome nome,nomeDev;
    Custo c;
    Matricula mat;
    Data data;
    Desenvolvedor desenvolvedor,dev;
    GerenteProjeto gerenteProj;
    c.setCusto(1000);
    Funcao func;
    nome.setNome("Sistema Financeiro");
    Email email;
    Senha senha;

    mat.setMatricula("33333");
    dev.setMatricula(mat);
    nomeDev.setNome("Uriel Silva");
    dev.setNome(nomeDev);
    email.setEmail("udiel@gmail.com");
    dev.setEmail(email);
    func.setFuncao(1);
    dev.setFuncao(func);
    senha.setSenha("senha");
    dev.setSenha(senha);

    proj.setCodigoProjeto(cod);
    proj.setNome(nome);
    proj.setCustoAtual(c);
    c.setCusto(1500);
    proj.setCustoPrevisto(c);
    proj.setDataInicio(data);
    data.setData("11/10/2016");
    proj.setDataTermino(data);
    proj.setDesenvolvedor(desenvolvedor);
    proj.setDesenvolvedor(dev);
    proj.setGerenteProjeto(gerenteProj);
    return proj;
}

vector<Projeto>* M_Persistencia::todosProjetos() throw(runtime_error)
{
    vector<Projeto>* projs = new vector<Projeto>;
    Projeto proj;
    CodigoProjeto cod;
    try{
        cod.setCodigo("ABCDE");
        proj = getProjeto(cod);
        projs->push_back(proj);
        cod.setCodigo("12345");
        proj = getProjeto(cod);
        projs->push_back(proj);
        cod.setCodigo("23456");
        proj = getProjeto(cod);
        projs->push_back(proj);
        cod.setCodigo("A1C3E");
        proj = getProjeto(cod);
        projs->push_back(proj);
        cod.setCodigo("A23DE");
        proj = getProjeto(cod);
        projs->push_back(proj);
    } catch (runtime_error error){
        throw error;
    }
    return projs;
}

void M_Persistencia::editarPessoa(Pessoa pessoa, Matricula mat) throw(runtime_error)
{

}

void M_Persistencia::cadastrarPessoa(Pessoa* pessoa) throw(runtime_error)
{
    if(pessoa->getMatricula().getMatricula().compare("12345")){
        throw runtime_error("Usuario cadastrado");
    }
}

vector<Pessoa*>* M_Persistencia::todasPessoas() throw(runtime_error)
{
    Matricula mat;
    vector<Pessoa*>* arr = new vector<Pessoa*>;
    GerenteProjeto*  gerente = new GerenteProjeto;
    Desenvolvedor* dev = new Desenvolvedor;
    Telefone tel;
    Nome nome;
    Email email;
    Senha senha;
    Funcao func;
    GerenteSistema* admin = new GerenteSistema;

    mat.setMatricula("12345");
    gerente->setMatricula(mat);
    nome.setNome("Daniel Luz");
    gerente->setNome(nome);
    tel.setNumero("99991234");
    gerente->setTelefone(tel);
    senha.setSenha("54321");
    gerente->setSenha(senha);
    arr->push_back(gerente);

    mat.setMatricula("23456");
    nome.setNome("Miguel Angelo");
    admin->setNome(nome);
    admin->setMatricula(mat);
    senha.setSenha("65432");
    admin->setSenha(senha);
    arr->push_back(admin);

    mat.setMatricula("33333");
    dev->setMatricula(mat);
    nome.setNome("Uriel Silva");
    dev->setNome(nome);
    email.setEmail("udiel@gmail.com");
    dev->setEmail(email);
    func.setFuncao(1);
    dev->setFuncao(func);
    senha.setSenha("senha");
    dev->setSenha(senha);
    arr->push_back(dev);

    return arr;
}

Pessoa* M_Persistencia::getPessoa(Matricula mat) throw(runtime_error)
{
    GerenteProjeto* gerente = new GerenteProjeto;
    Desenvolvedor* dev = new Desenvolvedor;
    GerenteSistema* admin = new GerenteSistema;
    Telefone tel;
    Nome nome;
    Senha senha;
    Email email;
    Funcao func;

    try {
        if(!mat.getMatricula().compare("12345")){
            gerente->setMatricula(mat);
            nome.setNome("Daniel Luz");
            gerente->setNome(nome);
            tel.setNumero("99991234");
            gerente->setTelefone(tel);
            senha.setSenha("54321");
            gerente->setSenha(senha);
            return gerente;
        } else if (!mat.getMatricula().compare("23456")) {
            nome.setNome("Miguel Angelo");
            admin->setNome(nome);
            admin->setMatricula(mat);
            senha.setSenha("65432");
            admin->setSenha(senha);
            return admin;
        } else {
            dev->setMatricula(mat);
            nome.setNome("Uriel Silva");
            dev->setNome(nome);
            email.setEmail("udiel@gmail.com");
            dev->setEmail(email);
            func.setFuncao(1);
            dev->setFuncao(func);
            senha.setSenha("senha");
            dev->setSenha(senha);
            return dev;
        }
    }
    catch (invalid_argument* error){
        throw error;
    }
}

void M_Persistencia::deletarProjeto(CodigoProjeto cod) throw (runtime_error){

}
bool M_Persistencia::deletarPessoa(Matricula mat) throw(runtime_error)
{
    if(mat.getMatricula().compare("12345")){
        return false;
    } else if(mat.getMatricula().compare("3333")){
        throw runtime_error("Banco de dados indisponivel.");
    } else {
        return true;
    }
}

