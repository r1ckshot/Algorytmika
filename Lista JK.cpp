#include <iostream>

using namespace std;

struct element{
    int number;
    element *next;
};

struct single_list{
    element *head;
    element *tail;
    int counter;
};

bool isEmpty(single_list *l){
    return(l->head == NULL && l->tail == NULL);
}

void add_tail(single_list *l, int value){
    element *el = new element;
    el->number = value;
    el->next = NULL;

    if(l->tail != NULL){
        l->tail->next = el;
    }
    else{
        l->head = el;
    }
    l->tail = el;

    l->counter++;
}

void add_head(single_list *l, int value){
    element *el = new element;
    el->number = value;
    el->next = l->head;

    l->head = el;

    if(l->tail == NULL){
        l->tail = el;
    }


    l->counter++;
}

void add_pos(single_list *l, int value, int position){
    element *el = new element;
    el->number = value;
    element *temp = l->head; // !!!!!!!!!!!!!!!

    int i = 1;
    while(i < position - 1){
        temp = temp->next;
        i++;
    }

    el->next = temp->next;
    temp->next = el;

    l->counter++;
}

void del_tail(single_list *l){
    element *temp = l->tail;

    if(l->counter == 1){
        l->tail = NULL;   // !!!!!!!!!!!!
        l->head = NULL;
    }
    else{
        element *bef_temp = l->head;

        int i = 1;
        while(i < l->counter - 1){
            bef_temp = bef_temp->next;
            i++;
        }

        l->tail = bef_temp;
        l->tail->next = NULL;
    }
    delete temp;
    l->counter--;
}

void del_head(single_list *l){
    element *temp = l->head;
    l->head = l->head->next;

    if(l->counter == 1){
        l->tail = NULL;
    }

    delete temp;
    l->counter--;
}

void del_pos(single_list *l, int position){
    element *prev = l->head;

    int i = 1;
    while(i < position - 1){
        prev = prev->next;
        i++;
    }
    element *temp = prev->next;
    prev->next = temp->next;
    delete temp;

    l->counter--;
}

void wyswietl(single_list *l){
    element *r;

    if(isEmpty(l)){ //l->head == NULL
        cout << "Lista jest pusta !!!" << endl;
    }
    else{
        r = l->head;
        while(r != NULL){
            cout << r->number << " ";
            r = r->next;
        }
    }
    cout << endl;
}

//Jak na wykładzie

//Ile dodatnich
int ile_dodatnich(single_list *l){
    element *r;
    int licznik = 0;

    if(isEmpty(l)){ //l->head == NULL
        cout << "Lista jest pusta !!!" << endl;
        return 0;
    }
    else{
        r = l->head;
        while(r != NULL){
            if(r->number > 0){
                licznik++;
            }
            r = r->next;
        }
    }
    return licznik;
}

//Maksymalny element
int Max(single_list *l){
    element *r;


    if(l->head == NULL){ //l->head == NULL
        cout << "Lista jest pusta !!!" << endl;
        return 0;
    }
    else{
        r = l->head;

        int Max = r->number;

        while(r != NULL){
            if(r->number > Max){
                Max = r->number;
            }
            r = r->next;
        }
        return Max;
    }

}

//Jak na laboratorium (z Counter !!!)

//Ile ujemnych
int ile_ujemnych(single_list *l){
    int i = 1;
    int licznik = 0;

    element *temp = l->head;

    while(i <= l->counter){

        if(temp->number < 0){
            licznik -= -1;
        }

        temp = temp->next;
        i++;
    }

    return licznik;
}

//Minimalny element
int Min(single_list *l){
    int i = 1;

    element *temp = l->head;

    int Min = temp->number;

    while(i <= l->counter){

        if(temp->number < Min){
            Min = temp->number;
        }

        temp = temp->next;
        i++;
    }

    return Min;
}

//Usun parzyste
void usun_parzyste(single_list &l) {
    element *prev = NULL;
    element *curr = l.head;

    while (curr != NULL) {
        if (curr->number % 2 == 0) {
            if (prev == NULL) {  // usuwamy głowę listy
                l.head = curr->next;
                if (l.head == NULL) {  // lista jest pusta
                    l.tail = NULL;
                }
                delete curr;
                curr = l.head;
            } else {  // usuwamy element z środka listy
                prev->next = curr->next;
                if (curr->next == NULL) {  // usuwamy ostatni element listy
                    l.tail = prev;
                }
                delete curr;
                curr = prev->next;
            }
            l.counter--;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}


int main()
{
    single_list *l = new single_list;
    l->head = NULL;
    l->tail = NULL;
    l->counter = 0;

        cout << isEmpty(l) << endl;

    add_head(l,-5);
    add_tail(l,-20);
    add_head(l,-4);
    add_tail(l,-33);

    add_pos(l,77,2);

    cout << "Ilosc elementow: " << l->counter << endl;

    wyswietl(l);

    //del_tail(l);
    //del_head(l);

    //del_pos(l,2);

    wyswietl(l);

    cout << "Ilosc dodatnich: " << ile_dodatnich(l) << endl;

    cout << "Maksymalny element: " << Max(l) << endl;

    cout << "Ilosc ujemnych elementow: " << ile_ujemnych(l) << endl;
    cout << "Minimalny element: " << Min(l) << endl;
    cout << "Ilosc elementow: " << l->counter << endl;

    delete l;

    return 0;
}
