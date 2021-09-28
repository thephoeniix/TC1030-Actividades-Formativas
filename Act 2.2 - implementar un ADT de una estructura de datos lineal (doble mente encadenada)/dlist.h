/*
    Karina Fernanda Maldonado Murillo
    A0707516
    Act 2.2 - Double Linked List Functions


*/

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class DList;


template <class T>
class DLink {
    private:
        T value;
        DLink<T> *previous;
        DLink<T> *next;
        DLink(T);
        DLink(T, DLink<T>*, DLink<T>*);
        DLink(const DLink<T>&);
        friend class DList<T>;
};

//FUNCIONES DE DLINK

template <class T>
DLink<T>::DLink(T v): value(v), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T v, DLink *prev, DLink* nxt): value(v), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source): value(source.value), previous(source.previous), next(source.next) {}


template <class T>
class DList{
    private:
        DLink<T> *head;
        DLink<T> *tail;
        int size;
    public:
        DList();
        DList(const DList<T>&) throw (OutOfMemory);
        ~DList();

        bool empty() const;
        void insertion(T) throw (OutOfMemory);
        T search(T) const;
        void update(int, T);

        T deleteAt(int) throw (IndexOutOfBounds);
        std::string toStringForward() const;
        std::string toStringBackward() const;

};

//CONSTRUCTORES

template <class T>
DList<T>::DList(): head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
    DLink<T> *p, *q;
    p = head;
    while (p != 0) {
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <class T>
bool DList<T>::empty() const {
    return (head == 0 && tail == 0);
}

//FUNCIONES

template <class T>
void DList<T>::insertion(T v)throw (OutOfMemory){
    DLink<T> *newDLink;

    newDLink = new DLink<T>(v);
    if (newDLink == 0) {
        throw OutOfMemory();
    }
    if(empty()){
        head = newDLink;
        tail = newDLink;
    }
    else{
        tail->next = newDLink;
        newDLink->previous = tail;
        tail = newDLink;
    }
    size++;
}


template <class T>
T DList<T>::search(T v) const {
    DLink<T> *p;
    p = head;
    int position = 0;



    while (p != 0) {
        if (p->value == v) {
            return position;
        }
        p = p->next;
        position++;
    }
    return -1;
}

template <class T>
void DList<T>::update(int position, T v){
    int pos;
    DLink<T> *p;

    p = head;
    pos = 0;

    while (p != 0) {

        if (pos == position){
            p->value = v;
            return;
        }
        p = p->next;
        tail= p->next->next;
        pos++;
    }

}


template <class T>
T DList<T>::deleteAt(int move) throw (IndexOutOfBounds){

    int pos;
    T v;
    DLink<T> *p;
    DLink<T> *newDLink;

    if(move < 0 || move >= size ){
        throw IndexOutOfBounds();
    }

    if(move == 0){
        p = head;
        v = p->value;
        if(head == tail){
            head = 0;
            tail = 0;
        }
        else{
            head = p->next;
            p->next->previous = 0;
        }
        delete p;
        size--;
        return v;
        }

        p = head;
        pos = 0;
        while(pos != move){
            p = p->next;
            pos++;
        }
        v = p->value;
        p->previous->next = p->next;
        if(p->next != 0){
            p->next->previous = p->previous;
        }
        size--;
        delete p;
        return v;
}


template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
    DLink<T> *p;
    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
    std::stringstream aux;
    DLink<T> *p;
    p = tail;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

#endif
