#ifndef MRN_PROJETOS_H
#define MRN_PROJETOS_H

#include "IRN_Projetos.h"

class MRN_Projetos: public IRN_Projetos
{
    public:
        MRN_Projetos();
        void allProjetos() throw (runtime_error);

        Projeto getProjeto(CodigoProjeto) throw (runtime_error);
        Projeto getProjeto(Nome) throw (runtime_error);

        bool fecharProjeto(CodigoProjeto) throw (runtime_error);

        bool editarProjeto(CodigoProjeto, Projeto) throw (runtime_error);

        bool criarProjeto(Projeto proj)  throw (runtime_error);

        void setClearance(int);

        int getClearance();


    protected:
    private:
};
#endif // MRN_PROJETOS_H
