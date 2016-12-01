#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H

#include <stdexcept>
#include "Nome.h"
#include "Matricula.h"
#include "Telefone.h"
#include "Senha.h"
#include "Email.h"
#include "Funcao.h"
#include "Pessoa.h"


class Desenvolvedor:public Pessoa
{
    public:
        Desenvolvedor();

        Email getEmail();
        void setEmail(Email);

        Funcao getFuncao();
        void setFuncao(Funcao);

    private:
        Email email;
        Funcao funcao;
};

#endif // DESENVOLVEDOR_H
