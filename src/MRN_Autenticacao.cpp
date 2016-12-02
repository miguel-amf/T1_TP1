#include "MRN_Autenticacao.h"
#include <iostream>

MRN_Autenticacao::MRN_Autenticacao()
{
    //ctor
}

void MRN_Autenticacao::setPersistencia(I_Persistencia* novaPers) throw (runtime_error){
    try{
        persistencia = novaPers;
    } catch (runtime_error error){
        throw error;
    }
}
Pessoa* MRN_Autenticacao::autenticar(Matricula mat,Senha senha) throw (runtime_error){
    vector<Pessoa*>* pessoas;
    try{
        pessoas = persistencia->todasPessoas();
        for(int i = 0; i < pessoas->size(); i++){
            if( !pessoas->at(i)->getMatricula().getMatricula().compare(mat.getMatricula())
               && !pessoas->at(i)->getSenha().getSenha().compare(senha.getSenha())
               ){
                return pessoas->at(i);
            }
        }
        return NULL; // acesso negado
    } catch (runtime_error* error) {
        throw error;
    }
}
