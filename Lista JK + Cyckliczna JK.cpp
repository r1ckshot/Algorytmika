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

    if(isEmpty(l)){
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

//Ile dodatnich
int ile_dodatnich(single_list *l){
    element *r;
    int licznik = 0;

    if(isEmpty(l)){
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


    if(isEmpty(l)){
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

//Lista cyckliczna JK

//Ile dodatnich
int ile_dodatnich(element *biezacy){
    // jeœli lista jest pusta, zwróæ 0
    if(biezacy == NULL){
        return 0;
    }

    element *p = biezacy;
    int licznik = 0;

    // zaczynamy od bie¿¹cego elementu i kontynuujemy, dopóki nie dojdziemy z powrotem do bie¿¹cego elementu
    do{
        if(p->number > 0){
            licznik++;
        }
        p = p->next;
    }while(p != biezacy);

    return licznik;
}

//Max element
int znajdz_max(element *biezacy){

    if(biezacy == NULL){
        return 0;
    }

    int mmax = biezacy->number;
    element *p = biezacy;

    do{
        if(p->number > mmax){
            mmax = p->number;
        }
        p = p->next;
    }while(p != biezacy);

    return mmax;
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
    add_tail(l,13);

    add_pos(l,9,2);

    cout << "Ilosc elementow: " << l->counter << endl;

    wyswietl(l);

    //del_tail(l);
    //del_head(l);

    //del_pos(l,2);

    wyswietl(l);

    cout << "Ilosc dodatnich: " << ile_dodatnich(l) << endl;

    wyswietl(l);

    cout << "Ilosc elementow: " << l->counter << endl;
    cout << "Maksymalny element: " << Max(l) << endl;

    delete l;

    return 0;
}
