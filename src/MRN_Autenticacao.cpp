#include "MRN_Autenticacao.h"

#include "string.h"
#include "Matricula.h"
#include "Senha.h"

MRN_Autenticacao::MRN_Autenticacao()
{
    //ctor
}

int MRN_Autenticacao::autenticar(Matricula mat,Senha senha) throw (runtime_error){
    if(!mat.getMatricula().compare("12345") ){
        return 0; // programador
    }
    if(!mat.getMatricula().compare("23456") ){
        return 1; // gerente de projeto
    }
    if(!mat.getMatricula().compare("34567") ){
        return 2; // gerente de sistema
    }
    if(!mat.getMatricula().compare("45678") ){
        throw runtime_error("Banco de dados indisponivel");
    }
    return -1; // acesso negado
}
