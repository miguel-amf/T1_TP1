#ifndef I_PERSISTENCIA_H
#define I_PERSISTENCIA_H

#include "Pessoa.h"
#include <vector>
#include "Matricula.h"
#include "Projeto.h"
#include "CodigoProjeto.h"

class I_Persistencia
{
    public:

        virtual void editarProjeto(Projeto,CodigoProjeto) throw (runtime_error) = 0;
        virtual void cadastrarProjeto(Projeto) throw (runtime_error) = 0;
        virtual Projeto getProjeto(CodigoProjeto) throw (runtime_error) = 0;
        virtual vector<Projeto>* todosProjetos() throw (runtime_error) = 0;
        virtual void deletarProjeto(Matricula) throw(runtime_error) = 0;

        virtual void editarPessoa(Pessoa,Matricula) throw(runtime_error) = 0;
        virtual void cadastrarPessoa(Pessoa*) throw(runtime_error) = 0;
        virtual vector<Pessoa>* todasPessoas() throw(runtime_error) = 0;
        virtual Pessoa* getPessoa(Matricula) throw(runtime_error) = 0;
        virtual bool deletarPessoa(Matricula) throw(runtime_error) = 0;
};

#endif // I_PERSISTENCIA_H
