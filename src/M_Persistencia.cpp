#include "M_Persistencia.h"

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
    Projeto proj;
    return proj;
}

vector<Projeto>* M_Persistencia::todosProjetos() throw(runtime_error)
{
    vector<Projeto>* projs = new vector<Projeto>;
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

vector<Pessoa>* M_Persistencia::todasPessoas() throw(runtime_error)
{
    Matricula mat;
    vector<Pessoa>* arr = new vector<Pessoa>;
    GerenteProjeto  gerente;
    Desenvolvedor dev;
    Telefone tel;
    Nome nome;
    Email email;
    Funcao func;
    GerenteSistema admin;

    mat.setMatricula("12345");
    gerente.setMatricula(mat);
    nome.setNome("Daniel Luz");
    gerente.setNome(nome);
    tel.setNumero("99991234");
    gerente.setTelefone(tel);
    arr->push_back(gerente);

    mat.setMatricula("23456");
    nome.setNome("Miguel Angelo");
    admin.setNome(nome);
    admin.setMatricula(mat);
    arr->push_back(admin);

    mat.setMatricula("33333");
    dev.setMatricula(mat);
    nome.setNome("Uriel Silva");
    dev.setNome(nome);
    email.setEmail("udiel@gmail.com");
    dev.setEmail(email);
    func.setFuncao(1);
    dev.setFuncao(func);
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
    Email email;
    Funcao func;

    try {
        if(!mat.getMatricula().compare("12345")){
            gerente->setMatricula(mat);
            nome.setNome("Daniel Luz");
            gerente->setNome(nome);
            tel.setNumero("99991234");
            gerente->setTelefone(tel);
            return gerente;
        } else if (!mat.getMatricula().compare("23456")) {
            nome.setNome("Miguel Angelo");
            admin->setNome(nome);
            admin->setMatricula(mat);
            return admin;
        } else {
            dev->setMatricula(mat);
            nome.setNome("Uriel Silva");
            dev->setNome(nome);
            email.setEmail("udiel@gmail.com");
            dev->setEmail(email);
            func.setFuncao(1);
            dev->setFuncao(func);
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

