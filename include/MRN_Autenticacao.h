#ifndef MRN_AUTENTICACAO_H
#define MRN_AUTENTICACAO_H

#include "IRN_Autenticao.h"

class MRN_Autenticacao:public IRN_Autenticao
{
    public:
        MRN_Autenticacao();
        int autenticar(Matricula,Senha)  throw(runtime_error);
};

#endif // MRN_AUTENTICACAO_H
