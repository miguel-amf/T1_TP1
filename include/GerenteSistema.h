#ifndef GERENTESISTEMA_H
#define GERENTESISTEMA_H

#include <stdexcept>
#include "Nome.h"
#include "Matricula.h"
#include "Telefone.h"
#include "Senha.h"

class GerenteSistema
{
    public:
        GerenteSistema();

        Nome getNome();
        void setNome(Nome) throw (invalid_argument);

        Matricula getMatricula();
        void setmatricula(Matricula) throw (invalid_argument);

        Senha getSenha();
        void setSenha(Senha) throw (invalid_argument);


    private:
        Nome nome;
        Matricula matricula;
        Senha senha;
};

#endif // GERENTESISTEMA_H
