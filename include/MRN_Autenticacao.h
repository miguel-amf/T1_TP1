#ifndef MRN_AUTENTICACAO_H
#define MRN_AUTENTICACAO_H

#include "IRN_Autenticao.h"
#include "Pessoa.h"

class MRN_Autenticacao:public IRN_Autenticao
{
    public:
        MRN_Autenticacao();
        Pessoa* autenticar(Matricula,Senha)  throw(runtime_error);
};

#endif // MRN_AUTENTICACAO_H
