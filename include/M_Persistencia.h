#ifndef M_PERSISTENCIA_H
#define M_PERSISTENCIA_H

#include <vector>
#include "CodigoProjeto.h"
#include "Pessoa.h"
#include "Projeto.h"
#include "Matricula.h"
#include "GerenteProjeto.h"
#include "GerenteSistema.h"
#include "Desenvolvedor.h"
#include "Nome.h"
#include "Senha.h"

class M_Persistencia
{
    public:
        M_Persistencia();

        void editarProjeto(Projeto,CodigoProjeto) throw (runtime_error);
        void cadastrarProjeto(Projeto) throw (runtime_error) ;
        Projeto getProjeto(CodigoProjeto) throw (runtime_error);
        vector<Projeto>* todosProjetos() throw (runtime_error);
        void deletarProjeto(CodigoProjeto) throw(runtime_error);

        void editarPessoa(Pessoa,Matricula) throw(runtime_error);
        void cadastrarPessoa(Pessoa*) throw(runtime_error);
        vector<Pessoa>* todasPessoas() throw(runtime_error);
        Pessoa* getPessoa(Matricula) throw(runtime_error);
        bool deletarPessoa(Matricula) throw(runtime_error);

    private:
};

#endif // M_PERSISTENCIA_H
