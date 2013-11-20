#include "Lista.h"

Lista::Lista()
{
    inicio=NULL;
}

void Lista::agregarNodo(Nodo*nodo)
{
    if(inicio==NULL)
    {
        inicio=nodo;
    }else
    {
        Nodo*temp=inicio;
        while(temp->siguiente!=NULL)
        {
            temp=temp->siguiente;
        }
        temp->siguiente=nodo;
    }
}

void Lista::agregarNodo(Nodo*nodo,int pos)
{
    if(nodo->nombre=="")
        return;
    if(inicio==NULL || pos==0)
    {
        nodo->siguiente=inicio;
        inicio=nodo;
    }else
    {
        Nodo*temp=inicio;
        int i=0;
        while(temp->siguiente!=NULL
              && i<pos-1)
        {
            temp=temp->siguiente;
            i++;
        }

        nodo->siguiente=temp->siguiente;
        temp->siguiente=nodo;
    }
}

void Lista::imprimirLista()
{
    for(Nodo*temp=inicio;
        temp!=NULL;
        temp=temp->siguiente)
    {
        cout<<temp->nombre<<endl;
        cout<<temp->score<<endl;
    }
}

void Lista::leerLista()
{   for(Nodo*temp=agregarNodo(new Nodo("inicio",4));
        temp!=NULL;
        temp=temp->siguiente)

    {   ifstream in ("scores.txt");
        while(true)
        {
        if(temp->nombre>>in==false)
        break;

        if(temp->score>>in==false)
        break;

        }
    }
}

void Lista::escribirLista()
{
    for(Nodo*temp=inicio;
        temp!=NULL;
        temp=temp->siguiente)
    {
    ofstream out("scores.txt", ios::app);
    out<<temp->nombre<<endl;
    out<<temp->score<<endl;
    }
}

Lista::~Lista()
{
    for(Nodo*temp=inicio;
        temp!=NULL;
        )
    {
        Nodo*temp2=temp;
        temp=temp->siguiente;
        delete temp2;
    }
    return;
}
