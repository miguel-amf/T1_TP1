#ifndef PESSOA_H
#define PESSOA_H

#include <stdexcept>
#include "Nome.h"
#include "Matricula.h"
#include "Telefone.h"
#include "Senha.h"

class Pessoa
{
    public:
        Pessoa();

        virtual Nome getNome();
        virtual void setNome(Nome) throw (invalid_argument);

        virtual Matricula getMatricula();
        virtual void setMatricula(Matricula) throw (invalid_argument);

        virtual Senha getSenha();
        virtual void setSenha(Senha) throw (invalid_argument);


    private:
        Nome nome;
        Matricula matricula;
        Senha senha;
};

#endif // PESSOA_H
