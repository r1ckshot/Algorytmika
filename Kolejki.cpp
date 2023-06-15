#include <iostream>

using namespace std;

struct element{
    int number;
    element *next;
};

struct Queue{
    element *head;
    element *tail;
};

int isEmpty(Queue *q){
    if (q->head == NULL){
        return 1;
    }
    return 0;
}

void push(Queue *q, int value){
    element *el = new element;
    el->number = value;
    el->next = NULL;

    if(q->tail != NULL){
        q->tail->next = el;
    }
    else{
        q->head = el;
    }

    q->tail = el;
}

int pop(Queue *q){
    element *temp = q->head;
    int returnValue = temp->number;

    q->head = q->head->next;

    if(q->head == NULL){
        q->tail = NULL;
    }

    delete temp;

    return returnValue;
}

int top(Queue *q){
    return q->head->number;
}

//Ile_nieparzystych
int ile_nieparzystych(Queue *q){
    Queue *Rob = new Queue;
    Rob->head = NULL;
    Rob->tail = NULL;

    int licznik = 0;

    while(!isEmpty(q)){
        if(top(q) % 2 != 0){
            licznik++;
        }
        int usunienty_q = pop(q);
        push(Rob,usunienty_q);

    }

    while(!isEmpty(Rob)){
        int usuniety_rob = pop(Rob);
        push(q,usuniety_rob);
    }

    delete Rob;

    return licznik;
}

//Minimalny element
int Min_element(Queue *q){

    Queue *Rob = new Queue;
    Rob->head = NULL;
    Rob->tail = NULL;

    int minEl = top(q);

    while(!isEmpty(q)){
        int usunienty_q = pop(q);
        if (usunienty_q < minEl){
            minEl = usunienty_q;
        }
        push(Rob,usunienty_q);
    }

    while(!isEmpty(Rob)){
        int usuniety_rob = pop(Rob);
        push(q,usuniety_rob);
    }

    delete Rob;

    return minEl;
}

//Tak jak powinno byc

//Ile_nieparzystych
int ile_nieparzystych(Queue *q){
    Queue *Rob = new Queue;
    Rob->head = NULL;
    Rob->tail = NULL;

    int licznik = 0;

    while(!isEmpty(q)){
        if(top(q) % 2 != 0){
            licznik++;
        }

        push(Rob,pop(q));

    }

    while(!isEmpty(Rob)){

        push(q,pop(Rob));
    }

    delete Rob;

    return licznik;
}

//Minimalny element
int Min_element(Queue *q){

    Queue *Rob = new Queue;
    Rob->head = NULL;
    Rob->tail = NULL;

    int minEl = top(q);

    while(!isEmpty(q)){

        if (top(q) < minEl){
            minEl = top(q);
        }

        push(Rob,pop(q));
    }

    while(!isEmpty(Rob)){
        push(q,pop(Rob));
    }

    delete Rob;

    return minEl;
}

//Srednia
float srednia(Queue *q){
    Queue *Rob = new Queue;
    Rob->head = NULL;
    Rob->tail = NULL;

    float suma = 0;
    int licznik = 0;

    while(!isEmpty(q)){

        suma += top(q);
        licznik++;

        push(Rob,pop(q));

    }

    while(!isEmpty(Rob)){

        push(q,pop(Rob));
    }

    delete Rob;

    if(licznik != 0){
        return suma/licznik;
    }
    else return 0;
}

int main()
{
    Queue *q = new Queue; // !!!!
    q->head = NULL;
    q->tail = NULL;

    cout << isEmpty(q) << endl;

    push(q,5);
    push(q,7);

    cout << isEmpty(q) << endl;

    cout << top(q) << endl;

    push(q,-1);
    push(q,8);


    cout << "Ilosc nieparzystych elementow: " << ile_nieparzystych(q) << endl;
    cout << "Minimalny element: " << Min_element(q) << endl;

    delete q; // !!!!

    return 0;
}
