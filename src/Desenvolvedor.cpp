#include "Desenvolvedor.h"

Desenvolvedor::Desenvolvedor()
{
    //ctor
}

Email Desenvolvedor::getEmail() {
    return email;
}

void Desenvolvedor::setEmail(Email novoEmail) {
    email = novoEmail;
}

Funcao Desenvolvedor::getFuncao() {
    return funcao;
}

void Desenvolvedor::setFuncao(Funcao novaFuncao) {
    funcao = novaFuncao;
}
