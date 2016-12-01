#ifndef IRN_PESSOA_H
#define IRN_PESSOA_H

#include "Pessoa.h"
#include "Matricula.h"
#include <vector>

class IRN_Pessoa
{
    public:
        virtual void cadastrarPessoa(Pessoa) throw (runtime_error) = 0 ;
        virtual bool deletarGerente(Matricula) throw (runtime_error) = 0 ;
        virtual bool deletarDesenvolvedor(Matricula) throw (runtime_error) = 0 ;
        virtual vector<Pessoa>* todasPessoas() throw (runtime_error) = 0 ;
        virtual Pessoa* getPessoa(Matricula) throw (runtime_error) = 0 ;
        virtual void deletarPessoa(Matricula) throw (runtime_error) = 0 ;

};

#endif // IRN_PESSOA_H
