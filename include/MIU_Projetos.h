#ifndef MIU_PROJETOS_H
#define MIU_PROJETOS_H

#include "MRN_Projetos.h"

class MIU_Projetos
{
    public:
        MIU_Projetos(MRN_Projetos*);
        void run() throw(runtime_error);


    private:

        void menuDesenvolvedor() throw(runtime_error);
        void menuGProjeto() throw(runtime_error);
        void menuGSistema() throw(runtime_error);

        void cadastrar() throw(runtime_error);
        void descadastrar() throw(runtime_error);
        void associar() throw(runtime_error);
        void alterar() throw(runtime_error);

        int clearance;
        MRN_Projetos *regrasNegProjetos;


};

#endif // MIU_PROJETOS_H
