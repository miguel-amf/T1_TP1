#include "Pessoa.h"

Pessoa::Pessoa()
{

}


Nome Pessoa::getNome(){
    return nome;
}

void Pessoa::setNome(Nome novoNome) throw (invalid_argument){
    nome = novoNome;
}

Matricula Pessoa::getMatricula(){
    return matricula;

}

void Pessoa::setMatricula(Matricula novaMatricula) throw (invalid_argument){
    matricula = novaMatricula;
}

Senha Pessoa::getSenha(){
    return senha;
}

void Pessoa::setSenha(Senha novaSenha) throw (invalid_argument){
    senha = novaSenha;
}
