#ifndef MRN_PESSOA_H
#define MRN_PESSOA_H

#include <IRN_Pessoa.h>


class MRN_Pessoa:public IRN_Pessoa
{
    public:
        MRN_Pessoa();
        void cadastrarPessoa(Pessoa) throw (runtime_error);
        bool deletarGerente(Matricula mat) throw (runtime_error);
        bool deletarDesenvolvedor(Matricula) throw (runtime_error);
        Pessoa* todasPessoas() throw (runtime_error);

};

#endif // MRN_PESSOA_H
