#ifndef MRN_PESSOA_H
#define MRN_PESSOA_H

#include <IRN_Pessoa.h>
#include <vector>

using namespace std;

class MRN_Pessoa:public IRN_Pessoa
{
    public:
        MRN_Pessoa();
        void cadastrarPessoa(Pessoa) throw (runtime_error);
        vector<Pessoa>* todasPessoas() throw (runtime_error);
        Pessoa* getPessoa(Matricula) throw (runtime_error);
        bool deletarPessoa(Matricula) throw (runtime_error);
    private:
        bool deletarGerente(Matricula mat) throw (runtime_error);
        bool deletarDesenvolvedor(Matricula) throw (runtime_error);

};

#endif // MRN_PESSOA_H
