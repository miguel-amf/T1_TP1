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

        Nome getNome();
        void setNome(Nome) throw (invalid_argument);

        Matricula getMatricula();
        void setMatricula(Matricula) throw (invalid_argument);

        Senha getSenha();
        void setSenha(Senha) throw (invalid_argument);


    private:
        Nome nome;
        Matricula matricula;
        Senha senha;
};

#endif // PESSOA_H
