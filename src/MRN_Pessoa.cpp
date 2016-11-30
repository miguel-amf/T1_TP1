#include "MRN_Pessoa.h"

MRN_Pessoa::MRN_Pessoa()
{
    //ctor
}


void MRN_Pessoa::cadastrarPessoa(Pessoa pessoa) throw (runtime_error){
    if(!pessoa.getMatricula().getMatricula().compare("12345")){
        throw runtime_error("Banco de dados indisponivel.");
    }
}

bool MRN_Pessoa::deletarGerente(Matricula mat) throw (runtime_error){
    if(!mat.getMatricula().compare("12345")){
        return false;
    }
    return true;
}

bool MRN_Pessoa::deletarDesenvolvedor(Matricula mat) throw (runtime_error){
    if(!mat.getMatricula().compare("12345")){
        return false;
    }
    return true;
}
Pessoa* MRN_Pessoa::todasPessoas() throw (runtime_error){
    Matricula mat;
    Pessoa* arr;
    arr = new Pessoa[5];
    mat.setMatricula("00000");
    arr[0].setMatricula(mat);
    mat.setMatricula("11111");
    arr[1].setMatricula(mat);
    mat.setMatricula("22222");
    arr[2].setMatricula(mat);
    mat.setMatricula("33333");
    arr[3].setMatricula(mat);
    mat.setMatricula("44444");
    arr[4].setMatricula(mat);
    return arr;
}
