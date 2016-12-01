#ifndef MRN_PROJETOS_H
#define MRN_PROJETOS_H

#include "IRN_Projetos.h"

class MRN_Projetos:public IRN_Projetos
{
    public:
        MRN_Projetos();
        void allProjetos() throw (runtime_error) = 0;

        Projeto getProjeto(CodigoProjeto) throw (runtime_error) = 0;
        Projeto getProjeto(Nome) throw (runtime_error) = 0;

        void coutProjeto(CodigoProjeto) throw (runtime_error) = 0;
        void coutProjeto(Nome) throw (runtime_error) = 0;

        bool fecharProjeto(CodigoProjeto) throw (runtime_error) = 0;

        bool editarProjeto(CodigoProjeto, Projeto) throw (runtime_error) = 0;

    protected:
    private:
};
#endif // MRN_PROJETOS_H
