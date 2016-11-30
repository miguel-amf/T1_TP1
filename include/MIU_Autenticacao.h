#ifndef MIU_AUTENTICACAO_H
#define MIU_AUTENTICACAO_H

#include "MRN_Autenticacao.h"

class MIU_Autenticacao
{
    public:
        MIU_Autenticacao();
        void setMRN(IRN_Autenticao*);
        int run();
    private:
        IRN_Autenticao* MRN;

};

#endif // MIU_AUTENTICACAO_H
