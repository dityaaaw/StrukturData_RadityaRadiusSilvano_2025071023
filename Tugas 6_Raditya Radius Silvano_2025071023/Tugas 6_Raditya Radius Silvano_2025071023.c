#include <stdio.h>

#define MAX 10

int data[MAX], next[MAX], prev[MAX];
int head = -1, tail = -1, freeHead = 0;

// inisialisasi free list
void init(){
    for(int i=0;i<MAX-1;i++){
        next[i] = i+1;
        prev[i] = -1;
    }
    next[MAX-1] = -1;
}

// ambil node dari free list
int ambilNode(){
    if(freeHead == -1) return -1;
    int idx = freeHead;
    freeHead = next[freeHead];
    return idx;
}

// kembalikan node ke free list
void freeNode(int idx){
    next[idx] = freeHead;
    freeHead = idx;
}

// insert awal
void insertAwal(int x){
    int idx = ambilNode();
    if(idx == -1){
        printf("Penuh\n");
        return;
    }

    data[idx] = x;
    prev[idx] = -1;
    next[idx] = head;

    if(head != -1){
        prev[head] = idx;
    }else{
        tail = idx;
    }

    head = idx;
}

// insert akhir
void insertAkhir(int x){
    int idx = ambilNode();
    if(idx == -1){
        printf("Penuh\n");
        return;
    }

    data[idx] = x;
    next[idx] = -1;
    prev[idx] = tail;

    if(tail != -1){
        next[tail] = idx;
    }else{
        head = idx;
    }

    tail = idx;
}

// delete awal
void deleteAwal(){
    if(head == -1){
        printf("Kosong\n");
        return;
    }

    int idx = head;
    head = next[head];

    if(head != -1){
        prev[head] = -1;
    }else{
        tail = -1;
    }

    freeNode(idx);
}

// delete akhir
void deleteAkhir(){
    if(tail == -1){
        printf("Kosong\n");
        return;
    }

    int idx = tail;
    tail = prev[tail];

    if(tail != -1){
        next[tail] = -1;
    }else{
        head = -1;
    }

    freeNode(idx);
}

// tampil maju
void tampilMaju(){
    int i = head;
    while(i != -1){
        printf("%d ", data[i]);
        i = next[i];
    }
    printf("\n");
}

// tampil mundur
void tampilMundur(){
    int i = tail;
    while(i != -1){
        printf("%d ", data[i]);
        i = prev[i];
    }
    printf("\n");
}

int main(){
    init();

    insertAwal(10);
    insertAkhir(20);
    insertAkhir(30);

    tampilMaju();
    tampilMundur();

    deleteAwal();
    deleteAkhir();

    tampilMaju();

    return 0;
}
