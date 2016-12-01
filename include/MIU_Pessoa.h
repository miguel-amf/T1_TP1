#ifndef MIU_PESSOA_H
#define MIU_PESSOA_H

#include "Matricula.h"
#include "IRN_Pessoa.h"
#include "Pessoa.h"
#include "Desenvolvedor.h"
#include "GerenteProjeto.h"
#include "GerenteSistema.h"

class MIU_Pessoa
{
    public:
        MIU_Pessoa(Pessoa*);
        void setMRN(IRN_Pessoa*);
        void menu(int);

    private:
        void listar();
        void editar(Matricula);
        void exibir(Matricula);
        IRN_Pessoa* MRN;
        int permissao;
        Pessoa* usuario;
};

#endif // MIU_PESSOA_H
