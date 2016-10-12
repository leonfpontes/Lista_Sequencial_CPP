#include <iostream>
#include <stdio.h>
#define MAX 100

typedef struct str_vendedor
{
    int codVendedor;
    char nomeVendedor[50];
    float perComissao, vlrSalFixo, vlrVendas, vlrSalario;
}VENDEDOR;

typedef struct str_lista
{
    int Inicio, Fim;
    VENDEDOR v[MAX];
}LISTA;
using namespace std;

void listaConstrutor(LISTA *l);
bool listaVazia(LISTA *l);
bool listaCheia(LISTA *l);
int tamanhoLista(LISTA *l);
bool inserirInicioLista(VENDEDOR v, LISTA *l);
bool inserirFimLista(VENDEDOR vend, LISTA *l);
bool inserirLista (VENDEDOR vend, LISTA *l, int Posicao);
bool listaRemoverFim(VENDEDOR vend, LISTA *l);
bool listaRemoveInicio(VENDEDOR vend, LISTA *l);
bool listaRemove(VENDEDOR vend, LISTA *l, int Posicao);
bool getInicio(VENDEDOR vend, LISTA *l);
bool getFim(VENDEDOR vend, LISTA *l);
bool buscaElementoValor(int Elemento, int &posicao);
bool buscaElementoPosicao(int &Elemento, int posicao);
void criarVendedor (VENDEDOR *v);
float calculaSalario(float vlrSalFixo, float perComissao, float vlrTotVenda);



//MAIN PRINCIPAL
int main()
{
    VENDEDOR v1;
    LISTA l;

    listaConstrutor(&l);
    criarVendedor(&v1);

    inserirInicioLista(v1, &l);

    cout << "Hello world!" << endl;
    return 0;
}

//FUNÇÕES DA ESTRUTURA VENDEDOR
void criarVendedor (VENDEDOR *v)
{
    int i = 0;
    printf("Digite o Codigo do vendedor:\t");
    fflush(stdin);
    scanf("%d", &v->codVendedor);
    printf("\nDigite o Nome do vendedor:\t");
    fflush(stdin);
    scanf("%[^\n]s", &v->nomeVendedor);
    printf("\nDigite o Salario Fixo do vendedor:\t");
    fflush(stdin);
    scanf("%f", &v->vlrSalFixo);
    printf("\nDigite o Total de Vendas desse vendedor:\t");
    fflush(stdin);
    scanf("%f", &v->vlrVendas);
    while (i = 0)
    {
        if (v->vlrSalFixo > 0 && v->perComissao > 0)
            i = 1;
        else
        {
            printf("\nDigite o Salario Fixo do vendedor:\t");
            fflush(stdin);
            scanf("%f", v->vlrSalFixo);
            printf("Digite o Total de Vendas desse vendedor:\t");
            fflush(stdin);
            scanf("%f", &v->vlrVendas);
        }
    }
    v->vlrSalario = calculaSalario(v->vlrSalFixo, v->vlrVendas, v->perComissao);


}

//FUNÇÕES DE LISTA

//CONSTRUTOR
void listaConstrutor(LISTA *l)
{
    l->Inicio = 0;
    l->Fim = -1;
}

//VERIFICA SE A LISTA ESTÁ VAZIA
bool listaVazia(LISTA *l)
{
    if (l->Inicio > l->Fim)https://www.youtube.com/watch?v=qPr7Bg2HPtI
        return true;
    else
        return false;
}

//VERIFICA SE A LISTA ESTÁ CHEIA
bool listaCheia(LISTA *l)
{
    if(l->Fim==MAX-1)
        return true;
    else
        return false;
}

//RETORNA O TAMANHO DA LISTA
int tamanhoLista(LISTA *l)
{
    return l->Fim+1;
}

//INSERE UM ELEMENTO NO INÍCIO DA LISTA
bool inserirInicioLista(VENDEDOR vend, LISTA *l)
{
    int i;
    if (listaCheia(l))
        return false;
    else
    {
        for (i = l->Fim +1; i <= l->Inicio; i--)
            l->v[i] = l->v[i-1];
        l->v[l->Inicio] = vend;
        l->Fim++;
        return true;
    }

}

//INSERE UM ELEMENTO NO FIM DA LISTA
bool inserirFimLista(VENDEDOR vend, LISTA *l)
{
    if (listaCheia(l))
        return false;
    else
    {
        l->v[l->Fim] = vend;
        l->Fim++;
        return true;
    }
}

//INSERE UM ELEMENTO EM UMA POSIÇÃO ESPECÍFICA DA LISTA
bool inserirLista (VENDEDOR vend, LISTA *l, int Posicao)
{
    if (listaCheia(l))
        return false;
    else
    {
        if (Posicao > l->Inicio && Posicao < l->Fim)
        {
            for (int i = l->Fim +1; i<=Posicao; i--)
                l->v[i] = l->v[i-1];
            l->v[Posicao] = vend;
            l->Fim++;
            return true;
        }
        else
            return false;
    }
}

//REMOVE UM ELEMENTO DO FIM DA LISTA
bool listaRemoverFim(VENDEDOR vend, LISTA *l)
{
    if (listaVazia(l))
        return false;
    else
    {
        vend = l->v[l->Fim];
        l->Fim--;
        return true;
    }
}

//REMOVE UM ELEMENTO DO INICIO DA LISTA
bool listaRemoveInicio(VENDEDOR vend, LISTA *l)
{
    if (listaVazia(l))
        return false;
    else
    {
        vend = l->v[l->Fim];
        for (int i = l->Inicio; i < l->Fim; i++)
            l->v[i] = l->v[i+1];
        l->Fim--;
        return true;
    }
}

//REMOVE UM ELEMENTO EM UMA POSIÇÃO ESPECÍFICA DA LISTA
bool listaRemove(VENDEDOR vend, LISTA *l, int Posicao)
{
    if (listaVazia(l))
        return false;
    else
    {
        if (Posicao > l->Inicio && Posicao < l->Fim)
        {
            vend = l->v[Posicao];
            for (int i = Posicao; i < l->Fim; i++)
            l->v[i] = l->v[i+1];
            l->Fim--;
            return true;
        }else
            return false;
    }
}

//RETORNA O PRIMEIRO ELEMENTO DA LISTA
bool getInicio(VENDEDOR vend, LISTA *l)
{
    if (listaVazia(l))
        return false;
    else
    {
        vend = l->v[l->Inicio];
        return true;
    }
}

//RETORNA O ÚLTIMO ELEMENTO DA LISTA
bool getFim(VENDEDOR vend, LISTA *l)
{
    if (listaVazia(l))
        return false;
    else
    {
        vend = l->v[l->Fim];
        return true;
    }
}

/*//BUSCA UM ELEMENTO ESPECÍFICO DA LISTA
bool buscaElementoValor(VENDEDOR vend, LISTA *l)
{
    int i;
    if (listaVazia(l))
        return false;
    else
    {
       for(i=l->Inicio;i<l->Fim;i++)
       {
           if(l->v[i] == vend)
                break;
       }
       if(i==l->Fim)
            return false;
    }
}*/

//BUSCA UM ELEMENTO DE UMA POSIÇÃO ESPECÍFICA DA LISTA
bool buscaElementoPosicao(VENDEDOR vend, LISTA *l, int posicao)
{
    if (listaVazia(l))
        return false;
    else
    {
       if (posicao > l->Inicio && posicao < l->Fim)
        {
            vend = l->v[posicao];
            return true;
        }else
            return false;
    }
}

float calculaSalario(float pvlrSalFixo, float pperComissao, float pvlrTotVenda)
{
    float vlrSalTotal = ((pvlrTotVenda * pperComissao)/100)+pvlrSalFixo;
    return vlrSalTotal;
}
