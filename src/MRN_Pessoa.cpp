#include "MRN_Pessoa.h"

#include "GerenteProjeto.h"
#include "Desenvolvedor.h"
#include "GerenteSistema.h"

MRN_Pessoa::MRN_Pessoa()
{
    //ctor
}


void MRN_Pessoa::cadastrarPessoa(Pessoa pessoa) throw (runtime_error){
    if(!pessoa.getMatricula().getMatricula().compare("12345")){
        throw runtime_error("Banco de dados indisponivel.");
    }
}

bool MRN_Pessoa::deletarGerente(Matricula mat) throw (runtime_error){
    if(!mat.getMatricula().compare("12345")){
        return false;
    }
    return true;
}

bool MRN_Pessoa::deletarDesenvolvedor(Matricula mat) throw (runtime_error){
    if(!mat.getMatricula().compare("12345")){
        return false;
    }
    return true;
}
vector<Pessoa>* MRN_Pessoa::todasPessoas() throw (runtime_error){
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

Pessoa* MRN_Pessoa::getPessoa(Matricula mat) throw (runtime_error) {
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

bool MRN_Pessoa::deletarPessoa(Matricula mat) throw (runtime_error){
    return true;
}
