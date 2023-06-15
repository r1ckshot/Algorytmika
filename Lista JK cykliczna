#include <iostream>

using namespace std;

struct element{
    int number;
    element* next;
};

//JednoKierunkowa Cykliczna
struct JednoKierunkowaCykliczna{
    element* biezacy;
};

bool isEmpty_lista_JKC(JednoKierunkowaCykliczna l){
    if (l.biezacy == NULL)
        return true;
    return false;
}


int ileEl_JKC(JednoKierunkowaCykliczna&l){
    int e = 0;
    if(isEmpty_lista_JKC(l))
        return e;
    element *p = l.biezacy;
    do{
        e++;
        p = p->next;
    }while(p!=l.biezacy);
    return e;

}

void add_tail_JKC(JednoKierunkowaCykliczna&l, int value){
    element *el = new element, *pom;
    if(l.biezacy == NULL){
        el->number  = value;
        el->next    = el;
        l.biezacy   = el;
        return;
    }
    el = l.biezacy;
    pom = new element;
    pom->next   = el->next;
    pom->number = value;
    el->next = pom;
}

void add_head_JKC(JednoKierunkowaCykliczna&l, int value){
    element *el = new element;
    el->number  = value;

    if(l.biezacy != NULL){
        el->next = l.biezacy->next;
        l.biezacy->next = el;
    }
    else{
        element *prev = l.biezacy;
        do{
            prev = prev->next;
        }while(prev->next!=l.biezacy);
        el->next = l.biezacy;
        prev->next = el;
    }

}

void delete_przed_JKC(JednoKierunkowaCykliczna&l){
    element *pom, *el, *End;
    End = l.biezacy, el = l.biezacy->next;
    while(true){
        if (el->next != l.biezacy){
            el=el->next;
            End = End->next;
        }
        else
            break;
    }
    el = End->next;
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = NULL;
    }
    else{
        //l.biezacy = el->next;
        End->next = l.biezacy;
    }
    delete pom;
}

void delete_za_JKC(JednoKierunkowaCykliczna&l){
    element *el  = l.biezacy->next;
    l.biezacy->next = el->next;
    if( el->next == el )
        l.biezacy = NULL;
    delete el;
}

void delete_biezacy_JKC(JednoKierunkowaCykliczna&l){
    element *pom, *el, *End;
    el = End = l.biezacy;
    int i = 0;
    while(true){
        if (End->next != l.biezacy)
            End=End->next;
        else
            break;
        i++;
    }
    pom = el;
    if (el->next == el){
        pom = l.biezacy->next;
        l.biezacy = NULL;
    }
    else{
        l.biezacy = el->next;
        End->next = l.biezacy;
    }
    delete pom;
}

void show_JKC(JednoKierunkowaCykliczna l){
    element *temp = l.biezacy;

    cout << "Lista jednokierunkowa\n";

    do{
        cout << temp->number << " ";

        temp=temp->next;

    }while(temp!=l.biezacy);

    cout << endl;
}

//Ile dodatnich
int ile_dodatnich(JednoKierunkowaCykliczna l){
    element *temp = l.biezacy;

    int licznik = 0;

    if(l.biezacy == NULL){ //isEmpty_lista_JKC(l)
        return licznik;
    }

    do{
        if(temp->number > 0){
            licznik++;
        }

        temp=temp->next;

    }while(temp != l.biezacy);

    return licznik;

}

//Maks element
int Max(JednoKierunkowaCykliczna l){

    if(l.biezacy == NULL){ //isEmpty_lista_JKC(l) ????
        return 0;
    }

    int Max = l.biezacy->number;

    element *temp = l.biezacy->next; // !!!!

    do{
        if(temp->number > Max){
            Max = temp->number;
        }

        temp=temp->next;

    }while(temp != l.biezacy);

    return Max;
}


//Funkcja zwracająca sumę jako return, a ile przez parametr z referencja !!! Obowiązkowo może być !!!
int suma_nieparzystcyh(JednoKierunkowaCykliczna l, int &ile){

    element *temp = l.biezacy;
    int suma = 0;
    ile = 0;

    if(l.biezacy == NULL){
        return suma;
    }

    do{
        if(temp->number %2 != 0){
            suma += temp->number;
            ile++;
        }

        temp = temp->next;

    }while(temp != l.biezacy);

    return suma;
}


//Nie dziala, ale na wszelki wypadek !!!
void deleteOdd_JKC(JednoKierunkowaCykliczna& l) {
    if (isEmpty_lista_JKC(l)) {
        return;
    }

    element *current = l.biezacy;
    element *prev = NULL;

    // Znajdź poprzedni element
    do {
        prev = current;
        current = current->next;
    } while (current != l.biezacy);

    current = l.biezacy;

    do {
        if (current->number % 2 != 0) {
            if (current == l.biezacy) {
                l.biezacy = current->next;
            }
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    } while (current != l.biezacy);

    // Jeśli wszystkie elementy były nieparzyste
    if (l.biezacy->number % 2 != 0) {
        delete l.biezacy;
        l.biezacy = NULL;
    }
}

int main()
{
    JednoKierunkowaCykliczna l;

    l.biezacy = NULL;

    /*cout << isEmpty_lista_JKC(l);

    add_tail_JKC(l,5);

    show_JKC(l);

    add_head_JKC(l,7);
    add_head_JKC(l,15);
    add_tail_JKC(l,31);
    add_tail_JKC(l,-3);
    add_head_JKC(l,18);
    add_tail_JKC(l,33);

    show_JKC(l);

    delete_za_JKC(l);
    delete_przed_JKC(l); */

    element* newElement = new element;
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

    show_JKC(l);

    cout << "Ilosc dodatnich elementow: " << ile_dodatnich(l) << endl;
    cout << "Max element: " << Max(l) << endl;

    int ile;
    cout << "Suma nieparzystych: " << suma_nieparzystcyh(l,ile) <<  " " << ile << endl;

    show_JKC(l);


    return 0;
}
