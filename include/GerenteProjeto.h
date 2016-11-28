#ifndef GERENTEPROJETO_H
#define GERENTEPROJETO_H

#include <stdexcept>
#include "Nome.h"
#include "Matricula.h"
#include "Telefone.h"
#include "Senha.h"
#include "Pessoa.h"

class GerenteProjeto : public Pessoa
{


    public:
        GerenteProjeto();

        Telefone getTelefone();
        void setTelefone(Telefone) throw (invalid_argument);


    private:
        Telefone telefone;

};

#endif // GERENTEPROJETO_H
