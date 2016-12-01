#include "MRN_Autenticacao.h"

#include "string.h"
#include "Matricula.h"
#include "Senha.h"
#include "GerenteProjeto.h"
#include "GerenteSistema.h"
#include "Email.h"
#include "Nome.h"
#include "Telefone.h"
#include "Funcao.h"
#include "Desenvolvedor.h"

MRN_Autenticacao::MRN_Autenticacao()
{
    //ctor
}

Pessoa* MRN_Autenticacao::autenticar(Matricula mat,Senha senha) throw (runtime_error){
    GerenteProjeto* gerente = new GerenteProjeto;
    Desenvolvedor* dev = new Desenvolvedor;
    GerenteSistema* admin = new GerenteSistema;
    Telefone tel;
    Nome nome;
    Email email;
    Funcao func;

    if(!mat.getMatricula().compare("33333") ){
        dev->setMatricula(mat);
        nome.setNome("Uriel Silva");
        dev->setNome(nome);
        email.setEmail("udiel@gmail.com");
        dev->setEmail(email);
        func.setFuncao(1);
        dev->setFuncao(func);
        return dev; // programador
    }
    if(!mat.getMatricula().compare("12345") ){
        mat.setMatricula("12345");
        gerente->setMatricula(mat);
        nome.setNome("Daniel Luz");
        gerente->setNome(nome);
        tel.setNumero("99991234");
        gerente->setTelefone(tel);
        return gerente; // gerente de projeto
    }
    if(!mat.getMatricula().compare("23456") ){
        mat.setMatricula("23456");
        nome.setNome("Miguel Angelo");
        admin->setNome(nome);
        admin->setMatricula(mat);
        return admin; // gerente de sistema
    }
    if(!mat.getMatricula().compare("45678") ){
        throw runtime_error("Banco de dados indisponivel");
    }
    return NULL; // acesso negado
}
