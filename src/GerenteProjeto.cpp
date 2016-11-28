#include "GerenteProjeto.h"

GerenteProjeto::GerenteProjeto()
{

}

Telefone GerenteProjeto::getTelefone(){
    return telefone;
}
void GerenteProjeto::setTelefone(Telefone novoTelefone) throw (invalid_argument){
    telefone = novoTelefone;
}
