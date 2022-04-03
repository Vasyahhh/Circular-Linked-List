#include <iostream>



using namespace std;

struct node{
    int info;
    node* next;
    node* prev;
    
    node(int value, node* n = 0, node* p = 0)
    : info(value), next(n), prev(p){};
};

node* first = NULL;
node* last = NULL;

void kosong(node* n){
    first = n;
    n->next = first;
    n->prev = first;
    last = n;
}

void deleteLastElement(){
    node* n = first;
    n->next = NULL;
    n->prev = NULL;
    first = NULL;
    last = NULL;
    delete n;
}

void insertfirst(int value){
    node* n = new node(value);
    if (first != NULL && last != NULL){
        n->next = first;
        n->prev = last;
        last->next = n;
        first->prev = n;
        first = n;
    } else { kosong(n);}
}


void insertlast(int value){
    node* n = new node(value);
    if (first != NULL && last != NULL){
        n->next = first;
        n->prev = last;
        last->next = n;
        first->prev = n;
        last = n;
    } else { kosong(n);}
}


void insertbefore(int value , node* pos){
    node* n = new node(value);
    n->next = pos;
    pos->prev->next = n;
    pos->prev = n;
}


void insertafter(int value, node* pos){
    node* n = new node(value);
    n->next = pos->next;
    pos->next->prev = n;
    pos->next = n;
}


void deletefirst(){
    if (first != NULL && last != NULL){
        node* temp = first;
        first = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        first->prev = last;
        last->next = first;
        delete temp;
    } else {deleteLastElement();}
}


void deletelast(){
    if (first != NULL && last != NULL){
        node* temp = last;
        last = last->prev;
        temp->next = NULL;
        temp->prev = NULL;
        first->prev = last;
        last->next = first;
        delete temp;
    } else {deleteLastElement();}
}


void deleteafter(node* pos){
    node* temp = pos->next;
    pos->next = temp->next;
    temp->next->prev = pos;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}


int search(int key){
    node* p = first;
    int i = 1;
    while (p->info != key){
        p = p->next;
        i++;
    }
    return i;
}


void print(node* pos){
    while(pos->next != first){
        cout << pos->info << " ";
        pos = pos->next;
    }
    cout << pos->info << " "; 
    cout << endl;
}

int main(){
	cout<<"Data Awal (1)\n";
	insertfirst(1);
	print(first);
	
	cout<<"insert first (2)\n";
    insertfirst(2);
    print(first);
    
    cout<<"insert Last (3)\n";
    insertlast(3);
    print(first);
    
    cout<<"insert Before (4)\n";
    insertbefore(4 , first->next);
    print(first);
    
    cout<<"insert After (5)\n";
    insertafter(5 , first->next->next);
    print(first);
    
    cout <<"Delete First\n";
    deletefirst();
    print(first);
    
    cout<<"Delete Last\n";
    deletelast();
    print(first);
    
    cout<<"Delete After\n";
    deleteafter(first);
    print(first);
    
    int cari;
    cout << "Elemen yang ingin dicari : ";
    cin >> cari;
    cout << "elemen "<< cari <<" ada di urutan ke-" << search(cari);

    return 0;
}
