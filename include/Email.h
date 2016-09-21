#ifndef EMAIL_H
#define EMAIL_H

#include <stdexcept>
#include <string>

using namespace std;

class Email
{
    public:
        Email();
        void setEmail(string) throw(invalid_argument);
        string getEmail();
    private:

        string email;

        void avalia(string)throw(invalid_argument);

};

class TesteEmail {

    public:
        //!Construtor
        /*!
        *Constroi o objeto para o teste de unidade para a classe Email
        */
        TesteEmail();

        //!SetUp de TesteEmail
        /*!
        *Inicializa os parametros necessarios para se iniciar os testes
        */
        void setUp(Email);

        //!TearDown de TesteEmail
        /*!
        *Realiza a limpeza necessaria para finalizar os testes
        */
        void tearDown(Email);

        //!Run de TesteEmail
        /*!
        *Inicia os testes
        */
        void run(Email);

    private:
        //!variavel para armazenar o valor do modulo a ser testado, para nao perder o dado
        string emailTemp;

};

#endif // EMAIL_H
