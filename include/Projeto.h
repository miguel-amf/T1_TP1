#ifndef PROJETO_H
#define PROJETO_H

#include "Nome.h"
#include "CodigoProjeto.h"
#include "GerenteProjeto.h"
#include "Desenvolvedor.h"
#include "Data.h"
#include "Custo.h"




class Projeto
{
    public:




        Projeto();

        Nome getNome();
        void setNome(Nome);

        CodigoProjeto getCodigoProjeto();
        void setCodigoProjeto(CodigoProjeto);

        GerenteProjeto getGerenteProjeto();
        void setGerenteProjeto(GerenteProjeto);


        //int referente ao index dele na lista, 0-9
        Desenvolvedor getDesenvolvedor(int);
        Desenvolvedor getDesenvolvedor(Nome);
        bool setDesenvolvedor(Desenvolvedor);
        bool remDesenvolvedor(int);
        bool remDesenvolvedor(Nome);


        Custo getCustoAtual();
        bool setCustoAtual(Custo);


        Custo getCustoPrevisto();
        bool setCustoPrevisto(Custo);


        Data getDataInicio();
        void setDataInicio(Data);


        Data getDataTermino();
        void setDataTermino(Data);

    protected:
    private:
        Nome nomeProjeto;
        CodigoProjeto codProjeto;
        GerenteProjeto gerenteProjeto;
        Desenvolvedor vDesenvolvedores[10];

        Custo custoAtual;
        Custo custoPrevisto;

        Data dataInicio;
        Data dataTermino;
};

#endif // PROJETO_H
