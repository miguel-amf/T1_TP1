#ifndef IRN_AUTENTICAO_H
#define IRN_AUTENTICAO_H

#include "Matricula.h"
#include "Senha.h"
class IRN_Autenticao
{
    public:
        virtual int autenticar(Matricula,Senha)  throw(runtime_error) = 0;

};

#endif // IRN_AUTENTICAO_H
