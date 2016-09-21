#ifndef SENHA_H
#define SENHA_H

#include <string>
#include <stdexcept>

//! Classe Senha
/*! Classe armazena uma senha de
*   5 caracteres sem repeticao
*/
using namespace std;

class Senha
{
    public:
        //! Construtor
        /*! Instancia o objeto Senha
        */
        Senha();
        //! Get senha
        /*! retorna o valor armazenado na senha
        */
        string getSenha() const;

        //! Set senha
        /*!
        */
        void setSenha(string) throw(invalid_argument);
    private:
        string senha;
        void avalia(string) throw(invalid_argument);
};

class TesteSenha {

    public:
        //!Construtor
        /*!
        *Constroi o objeto para o teste de unidade para a classe Senha
        */
        TesteSenha();

        //!SetUp de TesteSenha
        /*!
        *Inicializa os parametros necessarios para se iniciar os testes
        */
        void setUp(Senha);

        //!TearDown de TesteSenha
        /*!
        *Realiza a limpeza necessaria para finalizar os testes
        */
        void tearDown(Senha);

        //!Run de TesteSenha
        /*!
        *Inicia os testes
        */
        void run(Senha);

    private:
        //!variavel para armazenar o valor do modulo a ser testado, para nao perder o dado
        string senhaTemp;

};

#endif // SENHA_H
