#ifndef MRN_AUTENTICACAO_H
#define MRN_AUTENTICACAO_H

#include "IRN_Autenticao.h"
#include "I_Persistencia.h"
#include "Pessoa.h"
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

class MRN_Autenticacao:public IRN_Autenticao
{
    public:
        MRN_Autenticacao();
        Pessoa* autenticar(Matricula,Senha)  throw(runtime_error);
        void setPersistencia(I_Persistencia*) throw(runtime_error);
    private:
        I_Persistencia* persistencia;
};

#endif // MRN_AUTENTICACAO_H
