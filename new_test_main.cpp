#include <iostream>
#include <string>
#include <vector>

struct Cell{
    int content;
    Cell* next;
};

struct Queue{
    Cell* head;
    Cell* tail;
};
typedef Cell* lista;
typedef Queue lista_q;

void read_vector(std::vector<int>&);
void print_vector(const std::vector<int>&);
bool is_in_vector(const std::vector<int>&, int);
bool delete_item_vector(std::vector<int>&, int);
bool delete_all_vector(std::vector<int>&, int);
void sort_vector(std::vector<int>&);


void create_list(lista&); //inizializza la lista
void head_insert_lista_s(lista&, int);
void head_remove_lista_s(lista&);
void tail_insert_lista_s(lista&, int);
void tail_remove_lista_s(lista&);
void insertInOrder(lista &, int);
void read_lista_s(lista&);
void print_lista_s(const lista&);
bool is_in_lista_s(const lista&, int);
bool delete_item_lista_s(lista&, int);
bool delete_all_lista_s(lista&, int);
void sort_lista_s(lista&);
void reverseList(lista&);



void create_queue(lista_q&);
void head_insert_queue(lista_q&, int);
void head_remove_queue(lista_q&);
void tail_insert_queue(lista_q&, int);
void tail_remove_queue(lista_q&);
void read_queue(lista_q&);
void print_queue(const lista_q&);
bool is_in_queue(const lista_q&, int);
bool delete_item_queue(lista_q&, int);
bool delete_all_queue(lista_q&, int);
void sort_queue(lista_q&);




int main(){
    // std::vector<int> v;
    // read_vector(v);
    // print_vector(v);
    // delete_item_vector(v, 3);
    // print_vector(v);
    // std::cout << std::boolalpha << delete_all_vector(v, 5) << '\n';
    // print_vector(v);
    // sort_vector(v);
    // print_vector(v);



    // lista l = nullptr;
    // head_insert_lista_s(l, 3);
    // print_lista_s(l);
    // head_remove_lista_s(l);
    // tail_insert_lista_s(l, 4);
    // print_lista_s(l);
    // tail_remove_lista_s(l);
    // read_lista_s(l);
    // print_lista_s(l);
    // std::cout << std::boolalpha << is_in_lista_s(l, 3) << '\n';
    // delete_item_lista_s(l, 3);
    // print_lista_s(l);
    // delete_all_lista_s(l, 4);
    // print_lista_s(l);
    // sort_lista_s(l);
    // print_lista_s(l);



    // lista_q l;
    // create_queue(l);
    // head_insert_queue(l, 3);
    // head_insert_queue(l, 4);
    // print_queue(l);
    // head_remove_queue(l);
    // print_queue(l);
    // tail_remove_queue(l);
    // print_queue(l);
    // read_queue(l);
    // print_queue(l);
    // std::cout << std::boolalpha << is_in_queue(l, 3) << '\n';
    // delete_item_queue(l, 3);
    // print_queue(l);
    // delete_all_queue(l, 4);
    // print_queue(l);
    // sort_queue(l);
    // print_queue(l);

}


void read_vector(std::vector<int> &v){ //riempe il vector, adattare i parametri
    int input;
    while (true) {
        std::cout << "insert value, -1 to quit." << '\n';
        std::cin >> input;
        if(input == -1) return;
        v.push_back(input);
    }
}

void print_vector(const std::vector<int> &v){
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\t';
    }
    std::cout << '\n';
}
bool is_in_vector(const std::vector<int> &v, int n){
    if (v.size() == 0) throw std::string("is_in_vector error: empty vector");
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) return true;
    }
    return false;
}

bool delete_item_vector(std::vector<int> &v, int n){
    if (v.size() == 0) throw std::string("delete_item_vector error: empty vector");
    if (!is_in_vector(v, n)) return false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n){
            v.erase(v.begin()+ i);
            break;
        }
    }
    return true;
}
bool delete_all_vector(std::vector<int> &v, int n){
    if (v.size() == 0) throw std::string("delete_all_vector error: empty vector");
    if (!is_in_vector(v, n)) return false;
    while (is_in_vector(v, n)) {
        delete_item_vector(v, n);
    }
    return true;
}
void sort_vector(std::vector<int> &v){
    if (v.size() == 0) throw std::string("sort_vector error: empty vector");
    if (v.size() == 1) return;
    int min;
    for (int i = 0; i < v.size(); i++) {
        min = i;
        for (int j = i+1; j < v.size(); j++) {
            if(v[min] > v[j])
                min = j;
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}



//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================

void create_list(lista& l){
    l = nullptr;
}

void head_insert_lista_s(lista& l, int n){
    Cell* new_cell = new Cell;
    new_cell->content = n;

    new_cell->next = l;
    l = new_cell;
}

void head_remove_lista_s(lista& l){
    if (l == nullptr) throw std::string("head_remove_lista_s error: empty list");
    Cell* temp = l;
    l = l->next;
    delete temp;
}

void tail_insert_lista_s(lista& l, int n){
    Cell* new_cell = new Cell;
    new_cell->content = n;
    new_cell->next = nullptr;
    if (l == nullptr) {
        l = new_cell;
        return;
    }

    Cell* l_copy = l;
    while (l_copy->next != nullptr) {
        l_copy = l_copy->next;
    }
    l_copy->next = new_cell;
}


void tail_remove_lista_s(lista& l){ //fede
    if (l == nullptr) throw std::string("deleteTail error: empty list");
    Cell* curr = l;
    Cell* prev = l;
    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == l){
        l = nullptr;
    }
    else{
        prev->next = nullptr;
    }
    delete curr;
};


void insertInOrder(lista & l, int n){
    Cell* new_cell = new Cell;
    new_cell->content = n;
    new_cell->next = nullptr;

    Cell* curr = l;
    Cell* prev;
    while (curr != nullptr) {
        if (new_cell->content < curr->content) break;
        prev = curr;
        curr = curr->next;
    }
    if(l == curr)
        l = new_cell;
    else{
        prev->next = new_cell;
        new_cell->next = curr;
    }
}


void read_lista_s(lista& l){
    int input;
    while (true) {
        std::cout << "insert a value, -1 to quit" << '\n';
        std::cin >> input;
        if(input == -1) return;
        head_insert_lista_s(l, input);
        //tail_insert_lista_s(l, input);
    }
}

void print_lista_s(const lista& l){
    Cell* l_copy = l;
    while (l_copy != nullptr) {
        std::cout << l_copy->content << '\t';
        l_copy = l_copy->next;
    }
    std::cout << '\n';
}

bool is_in_lista_s(const lista& l, int n){
    if (l == nullptr) throw std::string("is_in_lista_s error: empty list.");
    Cell* l_copy = l;
    while (l_copy != nullptr) {
        if (l_copy->content == n) return true;
            l_copy = l_copy->next;
    }
    return false;
}

bool delete_item_lista_s(lista& l, int n){
    if (l == nullptr) throw std::string("delete_item_lista_s: empty list.");
    if(!is_in_lista_s(l, n)) return false;

    if (l->content == n) {
        head_remove_lista_s(l);
        return true;
    }

    Cell* curr = l;
    Cell* prev;
    while (curr != nullptr && curr->content != n) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
    return true;
}
bool delete_all_lista_s(lista& l, int n){
    if (l == nullptr) throw std::string("delete_item_lista_s: empty list.");
    if(!is_in_lista_s(l, n)) return false;
    while(is_in_lista_s(l, n)){
        delete_item_lista_s(l, n);
    }
    return true;
}
void sort_lista_s(lista& l){
    Cell* curr = l;
    Cell* step;
    Cell* min;
    while (curr != nullptr) {
        step = curr->next;
        min = curr;
        while (step != nullptr) {
            if (min->content > step->content) {
                min = step;
            }
            step = step->next;
        }
        if(min != curr){
            int temp = curr->content;
            curr->content = min->content;
            min->content = temp;
        }
        curr = curr->next;
    }
}

void reverseList(lista& l){
        Cell* curr = l; // creo puntatori della cella corrente precedente e successiva
        Cell* prev = nullptr;
        Cell* step = nullptr;

        while (curr != nullptr) { //itero tutta la lista
            step = curr->next; //memorizzo la cella successiva
            curr->next = prev; //punto alla cella precedente
            prev = curr; //sposto i puntatori prev e curr in avanti di una cella
            curr = step;
        }
        l = prev; //aggiorno la testa con il valore in "coda"
}

void insertInOrderByName(lista & l, int n){
    Cell* new_cell = new Cell;
    new_cell->content = n;
    new_cell->next = nullptr;

    Cell* curr = l;
    Cell* prev;
    while (curr != nullptr) {
        if (new_cell->content < curr->content) break;
        prev = curr;
        curr = curr->next;
    }
    if(l == curr)
        l = new_cell;
    else{
        prev->next = new_cell;
        new_cell->next = curr;
    }
}



//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================


void create_queue(lista_q& q){
    q.head = nullptr;
    q.tail = nullptr;
}

void head_insert_queue(lista_q& q, int n){
    Cell* new_cell = new Cell;
    new_cell->content = n;
    new_cell->next = nullptr;

    if(q.head == nullptr){
        q.head = new_cell;
        q.tail = new_cell;
    }
    else{
        new_cell->next = q.head;
        q.head = new_cell;
    }
}

void head_remove_queue(lista_q& q){
    if (q.head == nullptr) throw std::string("head_remove_queue error: empty list.");
    Cell* temp = q.head;
    q.head = q.head->next;
    delete temp;
}

void tail_insert_queue(lista_q& q, int n){
    Cell* new_cell = new Cell;
    new_cell->content = n;
    new_cell->next = nullptr;

    if (q.head == nullptr){
        q.head = new_cell;
        q.tail = new_cell;
    }
    else{
        Cell* q_copy = q.head;
        while (q_copy->next != nullptr) {
            q_copy = q_copy->next;
        }
        q_copy->next = new_cell;
        q.tail = nullptr;
    }
}
void tail_remove_queue(lista_q& q){
    if (q.head == nullptr) throw std::string("tail_remove_queue error: empty list.");
    Cell* curr = q.head;
    Cell* prev;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == q.head){
        q.head = nullptr;
        q.tail = nullptr;
    }
    else{
        prev->next = nullptr;
        q.tail = prev;
    }

    delete curr;
}
void read_queue(lista_q& q){
    int input;
    while(true){
        std::cout << "insert a value, -1 to quit" << '\n';
        std::cin >> input;
        if (input == -1) return;
        tail_insert_queue(q, input);
    }
}
void print_queue(const lista_q& q){
    Cell* q_copy = q.head;
    while (q_copy != nullptr) {
        std::cout << q_copy->content << '\t';
        q_copy = q_copy->next;
    }
    std::cout << '\n';
}

bool is_in_queue(const lista_q& q, int n){
    if (q.head == nullptr) return false;
    Cell* q_copy = q.head;
    while (q_copy != nullptr) {
        if(q_copy->content == n) return true;
        q_copy = q_copy->next;
    }
    return false;
}


bool delete_item_queue(lista_q& q, int n){
    if (q.head == nullptr) throw std::string("tail_remove_queue error: empty list.");
    if(!is_in_queue(q, n)) return false;

    Cell* curr = q.head;
    Cell* prev = q.head;
    while (curr != nullptr && curr->content != n) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == q.head){
        q.head = nullptr;
        q.tail = nullptr;
    }
    else{
        prev->next = curr->next;
    }
    delete curr;
    return true;
}

bool delete_all_queue(lista_q& q, int n){
    if (q.head == nullptr) throw std::string("tail_remove_queue error: empty list.");
    if(!is_in_queue(q, n)) return false;
    while (delete_item_queue(q, n)) {
    }
    return true;
}


void sort_queue(lista_q& q){
    Cell* curr = q.head;
    Cell* step;
    Cell* min;
    while(curr != nullptr){
        step = curr->next;
        min = curr;
        while(step != nullptr){
            if(min->content > step->content)
            min = step;

            step = step->next;
        }
        //swap
        if(curr != min){
            int temp = curr->content;
            curr->content = min->content;
            min->content = temp;
        }
        curr = curr->next;
    }
}

//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================
//==========================================================================================================================================



// void read_file(string nomefile, lista& l){
//     std::ifstream handler;
//     handler.open(nomefile);
//     if(!handler.isopen()) throw std::string("error");
//     std::string s;
//     while(!handler.eof()) {//ritorna true quando finisce il file
//         handler >> s; // cme il cin e memorizza dentro la variabile
//         head_insert(l, s) // inserisco il dato da qualche parte
//     }
//     handler.close()
// }



/*
metodi vector

V<tipo> nome_vector    dichiarazione
V<tipo> nome_vector(nome_array/vector)    dichiara e inizializza con i valori di un array o vector esistente

V.size()   restituisce la lunghezza del vector (il numero degli elementi non l'indice)
V.capacity()    Spazio occupato da V, include spazio non ancora utilizzato
V.max_size()    Dimensione massima possibile

V[i]    Accede all’elemento i-esimo (segmentation fault se i>=V.size() o i<0)

V.at(i)     Accede all’elemento i-esimo (errore trattabile se i>=V.size() o i<0)
V.back()    Accede all’ultimo elemento (possibile errore se V è vuoto)
W=V         Copia il contenuto da V a W (che deve esistere)

V.push_back(val) Aggiunge val in coda (ultima posizione) incrementando automaticamente la dimensione

V.pop_back()    Elimina l’ultimo elemento decrementando automaticamente la dimensione
V.resize(N)     Ridimensiona a nuova lunghezza N
V.clear()       Svuota (porta a lunghezza 0)
V.erase(v.begin()+ i) elimina un elemento in un indice i (o più elementi in un intervallo)

V.swap()    scambia i vector.
*/
