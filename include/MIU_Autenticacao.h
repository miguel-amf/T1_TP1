#ifndef MIU_AUTENTICACAO_H
#define MIU_AUTENTICACAO_H

#include "MRN_Autenticacao.h"

class MIU_Autenticacao
{
    public:
        MIU_Autenticacao();
        void setMRN(MRN_Autenticacao*);
        int run();
    private:
        MRN_Autenticacao* MRN;

};

#endif // MIU_AUTENTICACAO_H
