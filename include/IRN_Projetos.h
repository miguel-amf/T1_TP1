#ifndef IRN_PROJETOS_H
#define IRN_PROJETOS_H

#include <stdexcept>
#include <Projeto.h>

class IRN_Projetos
{
    public:
        virtual void allProjetos() throw(runtime_error) = 0;

        virtual Projeto getProjeto(CodigoProjeto) throw(runtime_error) = 0;
        virtual Projeto getProjeto(Nome) throw(runtime_error) = 0;

        virtual bool fecharProjeto(CodigoProjeto) throw (runtime_error) = 0;

        virtual bool editarProjeto(CodigoProjeto, Projeto) throw (runtime_error) = 0;

        virtual bool criarProjeto(Projeto proj)  throw (runtime_error) = 0;

        virtual void setClearance(int) = 0;

        virtual int getClearance() = 0;

        int clearance;

    protected:
    private:

};

#endif // IRN_PROJETOS_H
