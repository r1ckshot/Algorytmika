#include <iostream>

using namespace std;

struct element{
    int number;
    element* next;
    element* prev;
};

struct DwuKierunkowaCykliczna{
    element* biezacy;
};

bool isEmpty_lista_DKC(DwuKierunkowaCykliczna l){
    if (l.biezacy == NULL)
        return true;
    return false;
}

int ileEl_DKC(DwuKierunkowaCykliczna &l){
    int e = 0;
    if(isEmpty_lista_DKC(l))
        return e;
    element *p = l.biezacy;
    do{
        e++;
        p = p->next;
    }while(p!=l.biezacy);
    return e;
}




void add_tail_DKC(DwuKierunkowaCykliczna&l, int value){
    element *End, *el = new element;
    if(l.biezacy == NULL){
        el->number = value;
        el->next   = el;
        el->prev   = el->next;
        l.biezacy  = el;
        return;
    }
    End = l.biezacy;

    el->next   = End->next;
    el->number = value;
    el->prev   = End;
    End->next  = el;
    End = el;
    End->next->prev = End;
}

void add_head_DKC(DwuKierunkowaCykliczna &l, int value){
    element *el = new element;
    if(l.biezacy == NULL){
        el->number = value;
        el->next   = el;
        el->prev   = el->next;
        l.biezacy  = el;
        return;
    }
    element* prev =l.biezacy->prev;
    el->number=value;
    el->prev=prev;
    el->next=l.biezacy;
    prev->next=el;
    l.biezacy->prev=el;
}

void delete_za_DKC(DwuKierunkowaCykliczna &l){
    element *el  = l.biezacy->next;
    l.biezacy->next = el->next;
    l.biezacy->next->prev = el->prev;
    if( el->next == el )
        l.biezacy = NULL;
    delete el;
}

void delete_przed_DKC(DwuKierunkowaCykliczna&l){
    element *pom, *el, *End;
    End = l.biezacy->prev->prev;
    el = End->next;
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = NULL;
    }
    else{
        //l.biezacy = el->next;
        End->next = l.biezacy;
        l.biezacy->prev = el->prev;
    }
    delete pom;

}

void delete_biezacy_DKC(DwuKierunkowaCykliczna &l){
    element *pom, *el, *End;
    el = l.biezacy;
    End = l.biezacy->prev;
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = NULL;
    }
    else{
        l.biezacy = el->next;
        l.biezacy->prev = el->prev;
        End->next = l.biezacy;
    }
    delete pom;
}

void show_DKC(DwuKierunkowaCykliczna l, short tryb){
    element *temp = l.biezacy;
    cout << "Lista dwukierunkowa\n";

    do{
        cout << temp->number << " ";

        if (tryb == 0)
            temp=temp->next;
        else
            temp=temp->prev;

    }while(temp!=l.biezacy);

    cout << endl;
}

//Ile ujemnych
int ile_ujemnych(DwuKierunkowaCykliczna *l){
    element *temp = l->biezacy;

    int licznik = 0;

    if(l->biezacy == NULL){ //isEmpty_lista_JKC(l)
        return licznik;
    }

    do{
        if(temp->number < 0){
            licznik++;
        }

        temp=temp->next; //temp = temp->prev

    }while(temp != l->biezacy);

    return licznik;

}

//Min element
int Min(DwuKierunkowaCykliczna *l){

    if(l->biezacy == NULL){ //isEmpty_lista_JKC(l) ????
        return 0;
    }

    int Min = l->biezacy->number;

    element *temp = l->biezacy->prev; //Od konca listy !!! //temp = temp->next

    do{
        if(temp->number < Min){
            Min = temp->number;
        }

        temp=temp->prev; //temp = temp->next

    }while(temp != l->biezacy);

    return Min;
}


//Funkcja zwracająca sumę jako return, a ile przez parametr z referencja !!! Obowiązkowo może być !!!
int suma_parzystcyh(DwuKierunkowaCykliczna *l, int &ile){

    element *temp = l->biezacy;
    int suma = 0;
    ile = 0;

    if(l->biezacy == NULL){
        return suma;
    }

    do{
        if(temp->number %2 == 0){
            suma += temp->number;
            ile++;
        }

        temp = temp->next; //temp = temp->prev

    }while(temp != l->biezacy);

    return suma;
}


int main()
{
    DwuKierunkowaCykliczna l;  // DwuKierunkowaCykliczna *l = new DwuKierunkowaCykliczna;
    l.biezacy = NULL; //l->biezacy = NULL;

    cout << isEmpty_lista_DKC(l) << endl;

    add_tail_DKC(l,5);

    show_DKC(l,0);

    add_head_DKC(l,7);
    add_head_DKC(l,14);
    add_tail_DKC(l,-30);
    add_tail_DKC(l,-3);
    add_head_DKC(l,18);
    add_tail_DKC(l,33);

    show_DKC(l,0);
    show_DKC(l,1);

    delete_za_DKC(l);
    delete_przed_DKC(l);

    show_DKC(l,0);

    /*element* newElement = new element;
    newElement->number = 3;
    newElement->next = newElement; // Wskaźnik na sam siebie, ponieważ jest to jedyny element
    l.biezacy = newElement;

    newElement = new element;
    newElement->number = 7;
    newElement->next = l.biezacy->next; // Wskaźnik na początek listy
    l.biezacy->next = newElement; // Aktualizacja wskaźnika bieżącego elementu

    newElement = new element;
    newElement->number = 5;
    newElement->next = l.biezacy->next;
    l.biezacy->next = newElement;

    newElement = new element;
    newElement->number = 9;
    newElement->next = l.biezacy->next;
    l.biezacy->next = newElement;

    show_JKC(l); */

    cout << "Ilosc ujemnych elementow: " << ile_ujemnych(&l) << endl;
    cout << "Min element: " << Min(&l) << endl;

    int ile;
    cout << "Suma parzystych: " << suma_parzystcyh(&l,ile) <<  " " << ile << endl;

    //delete l;

    return 0;
}
