#ifndef CUSTO_H
#define CUSTO_H

#include <stdexcept>
using namespace std;

class Custo {


    public:
        Custo();

        float getCusto() const;
        void setCusto(float) throw(invalid_argument);

    private:
        float custo;
        void avalia(float) throw(invalid_argument);
};


class TesteCusto {

    public:
        //!Construtor
        /*!
        *Constroi o objeto para o teste de unidade para a classe Custo
        */
        TesteCusto();

        //!SetUp de TesteCusto
        /*!
        *Inicializa os parametros necessarios para se iniciar os testes
        */
        void setUp(Custo);

        //!TearDown de TesteCusto
        /*!
        *Realiza a limpeza necessaria para finalizar os testes
        */
        void tearDown(Custo);

        //!Run de TesteCusto
        /*!
        *Inicia os testes
        */
        void run(Custo);

    private:
        //!variavel para armazenar o valor do modulo a ser testado, para nao perder o dado
        float custoTemp;

};

#endif // CUSTO_H
