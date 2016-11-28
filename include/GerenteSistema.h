#ifndef GERENTESISTEMA_H
#define GERENTESISTEMA_H

#include <stdexcept>
#include "Nome.h"
#include "Matricula.h"
#include "Telefone.h"
#include "Senha.h"
#include "Pessoa.h"


/*
Gerente de sistema basicamente eh uma Pessoa, mas manteremos
assim para fins de abstração, afinal pode ser que
um gerente ganhe atributos especiais ao longo da implementação ou
evolucao do codigo.
*/
class GerenteSistema : public Pessoa
{
    public:
        GerenteSistema();

    private:
};

#endif // GERENTESISTEMA_H
