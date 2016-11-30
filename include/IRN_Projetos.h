#ifndef IRN_PROJETOS_H
#define IRN_PROJETOS_H


class IRN_Projetos
{
    public:
        virtual void allProjetos() throw (runtime_error) = 0;

        virtual Projeto getProjeto(CodigoProjeto) throw (runtime_error) = 0;
        virtual Projeto getProjeto(Nome) throw (runtime_error) = 0;

        /*carrega um projeto para a classe, afim de ser editado ou removido*/
        virtual bool carregarProjeto(CodigoProjeto) throw (runtime_error) = 0;
        virtual Projeto carregarProjeto(Nome) throw (runtime_error) = 0;

        /*Exclui da persistencia tambem*/
        virtual bool removeProjetoCarregado() throw (runtime_error) = 0;

        virtual bool modificarProjetoCarregado(Nome);
        virtual bool modificarProjetoCarregado(CodigoProjeto);
        virtual bool modificarProjetoCarregado(GerenteProjeto);
        /*char: 'a' para adicionar e 'r' para remover*/
        virtual bool modificarProjetoCarregado(Desenvolvedor, char);
        /*char: 'a' para atual, 'p' para previsto*/
        virtual bool modificarProjetoCarregado(Custo, char);
        /*char: 'i' para inicio, 't' para termino*/
        virtual bool modificarProjetoCarregado(Data, char);

    protected:
    private:
};

#endif // IRN_PROJETOS_H
