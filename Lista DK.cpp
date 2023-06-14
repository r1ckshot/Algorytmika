#include <iostream>

using namespace std;

struct element{
    int number;
    element *next;
    element *prev;
};

struct double_list{
    element *head;
    element *tail;
    int counter;
};

bool isEmpty(double_list *l){
    return(l->head == NULL && l->tail == NULL);
}

void add_tail(double_list *l, int value){
    element *el = new element;
    el->number = value;
    el->next = NULL;
    el->prev = NULL;

    if(l->tail != NULL){
        l->tail->next = el;
        el->prev = l->tail; // !!!!!!!
    }
    else{
        l->head = el;
    }

    l->tail = el;

    l->counter++;
}

void add_head(double_list *l, int value){
    element *el = new element;
    el->number = value;
    el->next = NULL;
    el->prev = NULL;
                            // !!!!!!!!!!!!!!!
    if(l->head != NULL){
        l->head->prev = el;
        el->next = l->head;
    }
    else{
        l->tail = el;
    }

    l->head = el;

    l->counter++;
}

void add_position(double_list *l, int value, int position){
    element *temp = l->head;

    int i = 1;
    while(i < position - 1){
        temp = temp->next;
        i++;
    }

    element *el = new element;
    el->number = value;
    el->prev = temp;  // !!!!!
    el->next = temp->next;

    temp->next->prev = el;
    temp->next = el;

    l->counter++;

}

void delete_tail(double_list *l){
    element *temp = l->tail;

    if(l->counter == 1){
        l->head == NULL;
        l->tail == NULL;
    }
    else{
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }
    delete temp;
    l->counter--;
}

void delete_head(double_list *l){
    element *temp = l->head;

    if(l->counter == 1){
        l->tail = NULL;
        l->head = NULL;
    }
    else{
        l->head = l->head->next;
        l->head->prev = NULL;
    }

    delete temp;
    l->counter--;
}

void delete_position(double_list *l, int position){
    element *temp = l->head;

    int i = 1;
    while(i < position - 1){
        temp = temp->next;
        i++;
    }

    element *temp_us = temp->next;
    temp->next = temp_us->next;
    temp->next->prev = temp;

    delete temp_us;

    l->counter--;

}

void wyswietl(double_list *l){
    element *r;

    if(isEmpty(l)){ //l->head == NULL ?
        cout << "Lista jest pusta!!!" << endl;
    }
    else{
        r = l->head; // r = l->tail; // W innym kierunku
        while(r!= NULL){
            cout << r->number << " ";
            r = r->next; // r = r->prev;
        }
    }
    cout << endl;
}

// Jak na wykładzie

//Ile_dodatnich
int ile_dodatnich(double_list *l){
    element *r;
    int licznik = 0;

    if(isEmpty(l)){ //l->head == NULL ?
        cout << "Lista jest pusta!!!" << endl;
        return 0;
    }
    else{
        r = l->head; // r = l->tail; // W innym kierunku
        while(r!= NULL){
            if(r->number > 0)
                licznik++;
            r = r->next; // r = r->prev;
        }
    }
    return licznik;
}

//Min element
int Min(double_list *l){
    element *r;


    if(isEmpty(l)){ //l->head == NULL ?
        cout << "Lista jest pusta!!!" << endl;
        return 0;
    }
    else{
        r = l->head; // r = l->tail; // W innym kierunku

        int Min = r->number;

        while(r!= NULL){
            if(r->number < Min)
                Min = r->number;
            r = r->next; // r = r->prev;
        }

        return Min;
    }
}

//Jak na laboratorium (z Counter !!!)

//Ile ujemnych
int ile_ujemnych(double_list *l){
    element *temp = l->head; // temp = l->tail; // W innym kierunku

    int i = 1;
    int licznik = 0;

    while(i <= l->counter){

        if(temp->number < 0){
            licznik++;
        }

    temp = temp->next; // temp = temp->prev;

    i++;
    }
    //delete temp;
    return licznik;
}

//Max element
int Max(double_list *l){
    element *temp = l->tail; //temp = l->head;

    int i = 1;

    int Max = temp->number;

    while(i <= l->counter){
        if(Max < temp->number){
            Max = temp->number;
        }

        temp = temp->prev; //temp = temp->next
        i++;
    }

    //delete temp;

    return Max;
}


int main()
{
    double_list *l = new double_list;
    l->head = NULL;
    l->tail = NULL;
    l->counter = 0;

    cout << isEmpty(l) << endl;

    add_tail(l,10);
    add_head(l,33);
    add_tail(l,-7);
    add_head(l,22);
    add_position(l,-9,3);

    cout << "Ilosc elementow: " << l->counter << endl;

    wyswietl(l);

    /*delete_head(l);
    delete_position(l,3);
    delete_tail(l); */


    cout << "Ilosc dodatnich elementow: " << ile_dodatnich(l) << endl;
    cout << "Minimalny el: " << Min(l) << endl;

    cout << "Ilosc ujemnych elementow: " << ile_ujemnych(l) << endl;
    cout << "Maksymalny el: " << Max(l) << endl;

    delete l;


    return 0;
}
