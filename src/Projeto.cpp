#include "Projeto.h"

#include "Nome.h"
#include "CodigoProjeto.h"
#include "GerenteProjeto.h"
#include "Desenvolvedor.h"
#include "Data.h"
#include "Custo.h"

#include <cstdlib>

Projeto::Projeto()
{

}


Nome Projeto::getNome()
{
    return nomeProjeto;
}

void Projeto::setNome(Nome novoNome)
{
    if(fase.getFase() != 3)
    nomeProjeto = novoNome;
}

CodigoProjeto Projeto::getCodigoProjeto()
{
    return codProjeto;
}

void Projeto::setCodigoProjeto(CodigoProjeto novoCod)
{
    if(fase.getFase() != 3)
    codProjeto = novoCod;
}

GerenteProjeto Projeto::getGerenteProjeto()
{
    return gerenteProjeto;
}

void Projeto::setGerenteProjeto(GerenteProjeto novoGerente)
{
    if(fase.getFase() != 3)
    gerenteProjeto = novoGerente;
}

Desenvolvedor Projeto::getDesenvolvedor(int index)
{
    return vDesenvolvedores[index];
}

Desenvolvedor Projeto::getDesenvolvedor(Nome nomeAlvo)
{
    for(int i=0; i<10; i++) {

        if(!vDesenvolvedores[i].getNome().getNome().compare(nomeAlvo.getNome())) {
            return vDesenvolvedores[i];
        }
    }
    Desenvolvedor retornoFalso;
    return retornoFalso;
}

bool Projeto::setDesenvolvedor(Desenvolvedor desenNovo)
{
    if(fase.getFase() == 3) return false;
    for(int i = 0; i<10; i++) {
        if (!vDesenvolvedores[i].getMatricula().getMatricula().compare("00000")) {
            vDesenvolvedores[i] = desenNovo;
            return true;
        }
    }
    return false;
}

bool Projeto::remDesenvolvedor(Matricula mat)
{
    Desenvolvedor zerado;
    for(int i=0; i<10; i++) {

        if(!vDesenvolvedores[i].getMatricula().getMatricula().compare(mat.getMatricula())) {
            vDesenvolvedores[i] = zerado;
            return true;
        }
    }
    return true;
}

bool Projeto::remDesenvolvedor(Nome nomeAlvo)
{
    Desenvolvedor zerado;
    for(int i=0; i<10; i++) {

        if(!vDesenvolvedores[i].getNome().getNome().compare(nomeAlvo.getNome())) {
            vDesenvolvedores[i] = zerado;
            return true;
        }
    }
    return false;
}

Custo Projeto::getCustoAtual()
{
    return custoAtual;
}

bool Projeto::setCustoAtual(Custo custoNovo)
{
    if(fase.getFase() == 3) return false;
    if(custoNovo.getCusto() <= custoPrevisto.getCusto()) {
        custoAtual.setCusto(custoNovo.getCusto());
        return true;
    }
    return false;

}

Custo Projeto::getCustoPrevisto()
{
    return custoPrevisto;
}

bool Projeto::setCustoPrevisto(Custo custoNovo)
{
    if(fase.getFase() == 3) return false;
    if(custoAtual.getCusto() <= custoNovo.getCusto()) {
        custoPrevisto = custoNovo;
        return true;
    }
    return false;

}

Data Projeto::getDataInicio()
{
    return dataInicio;
}

void Projeto::setDataInicio(Data dataNova)
{
    if(fase.getFase() != 3)
    dataInicio = dataNova;
}

Data Projeto::getDataTermino()
{
    return dataTermino;
}

void Projeto::setDataTermino(Data dataNova)
{
    if(fase.getFase() != 3)
    dataTermino = dataNova;
}
