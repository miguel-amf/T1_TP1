#ifndef GERENTEPROJETO_H
#define GERENTEPROJETO_H

#include <stdexcept>
#include "Nome.h"
#include "Matricula.h"
#include "Telefone.h"
#include "Senha.h"

class GerenteProjeto
{


    public:
        GerenteProjeto();

        Nome getNome();
        void setNome(Nome) throw (invalid_argument);

        Matricula getMatricula();
        void setmatricula(Matricula) throw (invalid_argument);

        Telefone getTelefone();
        void setTelefone(Telefone) throw (invalid_argument);

        Senha getSenha();
        void setSenha(Senha) throw (invalid_argument);


    private:
        Nome nome;
        Matricula matricula;
        Telefone telefone;
        Senha senha;
};

#endif // GERENTEPROJETO_H
