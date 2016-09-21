#ifndef TELEFONE_H
#define TELEFONE_H

#include <stdexcept>
#include <string>

using namespace std;

//! classe Telefone
/*! Classe armazena um número de telefone
*   de 8 dígitos.
*/
class Telefone
{
    public:
        //! Construtor de Telefone
        /*! Instancia um objeto do tipo telefone.
        */
        Telefone();

        //! Get Número
        /*! Retorna o valor do telefone armazenado no objeto.
        */
        string getNumero();

        //! Set Número
        /*! Valida e altera o valor do número de telefone armazenado.
        */
        void setNumero(string) throw(invalid_argument);

    private:

        string numero;

        void avalia(string) throw(invalid_argument);

};

class TesteTelefone {

    public:
        //!Construtor
        /*!
        *Constroi o objeto para o teste de unidade para a classe Telefone
        */
        TesteTelefone();

        //!SetUp de TesteTelefone
        /*!
        *Inicializa os parametros necessarios para se iniciar os testes
        */
        void setUp(Telefone);

        //!TearDown de TesteTelefone
        /*!
        *Realiza a limpeza necessaria para finalizar os testes
        */
        void tearDown(Telefone);

        //!Run de TesteTelefone
        /*!
        *Inicia os testes
        */
        void run(Telefone);

    private:
        //!variavel para armazenar o valor do modulo a ser testado, para nao perder o dado
        string telefoneTemp;

};
#endif // TELEFONE_H
