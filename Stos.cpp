#include <iostream>

using namespace std;

struct element{
    int number;
    element *next;
};

bool isEmpty(element *Stack){
    return(Stack == NULL);
}

void push(element *&Stack, int value){  //Dzialaja na oryginale
    element *el = new element;
    el->number = value;
    el->next = Stack;
    Stack = el;
}

int pop(element *&Stack){
    element *temp = Stack;
    int Value = temp->number;

    Stack = Stack->next;
    delete temp;

    return Value;
}

int top(element *Stack){
    return Stack->number;
}

void wyswietl(element *&Stack){
    element *Rob = NULL;

    while(!isEmpty(Stack)){
        cout << top(Stack) << " ";

        int usuniety_stack = pop(Stack);
        push(Rob,usuniety_stack);
    }

    while(!isEmpty(Rob)){

        int usuniety_rob = pop(Rob);
        push(Stack,usuniety_rob);
    }
}

//Ile parzystych
int ile_parz(element *&Stack){
    element *Rob = NULL;
    int licznik = 0;

    while(!isEmpty(Stack)){

    if(top(Stack) % 2 == 0){
        licznik++;
    }
        int usuniety_stack = pop(Stack);
        push(Rob,usuniety_stack);
    }

    while(!isEmpty(Rob)){
        int usuniety_rob = pop(Rob);
        push(Stack,usuniety_rob);
    }

    return licznik;
}

//Ile parzystych 2
int ile_parz(element *Stack){
    element *Rob = NULL;
    int licznik = 0;

    while(!isEmpty(Stack)){

    if(top(Stack) % 2 == 0){
        licznik++;
    }
        push(Rob,pop(Stack));
    }

    while(!isEmpty(Rob)){
        push(Stack,pop(Rob));
    }

    return licznik;
}

//Minimalny element
int Min(element *&Stack){
    element *Rob = NULL;

    int Min = top(Stack);


    while(!isEmpty(Stack)){

    int usuniety_stack = pop(Stack);

    if(usuniety_stack < Min){
        Min = usuniety_stack;
    }
        push(Rob,usuniety_stack);
    }

    while(!isEmpty(Rob)){
        int usuniety_rob = pop(Rob);
        push(Stack,usuniety_rob);
    }

    return Min;
}

//Minimalny element 2
int Min(element *Stack){

    element* Rob = NULL;

    int Min = top(Stack);

    while(!isEmpty(Stack)){
        if(top(Stack) < Min){
            Min = top(Stack);
        }
        push(Rob, pop(Stack));
    }

    while(!isEmpty(Rob)){
        push(Stack, pop(Rob));
    }

    return Min;
}

//Srednia
float srednia(element *Stack){
    element *Rob = NULL;
    float suma = 0;
    int licznik = 0;

    while(!isEmpty(Stack)){

        suma += top(Stack);
        licznik++;
        push(Rob,pop(Stack));
    }

    while(!isEmpty(Rob)){
        push(Stack,pop(Rob));
    }

    if(licznik !=0 ){
        return suma/licznik;
    }
    else return 0;
}

int main()
{
    element *Stack = NULL;

    cout << isEmpty(Stack) << endl;

    push(Stack,34);
    push(Stack,5);
    push(Stack,-5);
    push(Stack,9);
    push(Stack,10);
    push(Stack,-3);
    push(Stack,18);

    cout << isEmpty(Stack) << endl;

    wyswietl(Stack);
    cout << "Liczba parzystych liczb: " << ile_parz(Stack) << endl;
    cout << "Minimalny element: " << Min(Stack) << endl;

    return 0;
}
