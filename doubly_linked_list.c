#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void tambahAwal(int x){
    struct node *baru = (struct node*)malloc(sizeof(struct node));

    baru->data = x;
    baru->prev = NULL;
    baru->next = head;

    if(head != NULL){
        head->prev = baru;
    }else{
        tail = baru;
    }

    head = baru;
}

void tambahAkhir(int x){
    struct node *baru = (struct node*)malloc(sizeof(struct node));

    baru->data = x;
    baru->next = NULL;
    baru->prev = tail;

    if(tail != NULL){
        tail->next = baru;
    }else{
        head = baru;
    }

    tail = baru;
}

void hapusAwal(){
    if(head == NULL){
        printf("List kosong\n");
        return;
    }

    struct node *temp = head;

    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }else{
        tail = NULL;
    }

    free(temp);

    printf("Data pertama dihapus\n");
}

void tampil(){
    struct node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){

    int pilih, x;

    // membuat minimal 5 node
    tambahAkhir(10);
    tambahAkhir(20);
    tambahAkhir(30);
    tambahAkhir(40);
    tambahAkhir(50);

    do{
        printf("\n1. Tambah di awal\n");
        printf("2. Tambah di akhir\n");
        printf("3. Hapus di awal\n");
        printf("4. Tampil maju\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d",&pilih);

        switch(pilih){

            case 1:
                printf("Masukkan data: ");
                scanf("%d",&x);
                tambahAwal(x);
                break;

            case 2:
                printf("Masukkan data: ");
                scanf("%d",&x);
                tambahAkhir(x);
                break;

            case 3:
                hapusAwal();
                break;

            case 4:
                tampil();
                break;

        }

    }while(pilih != 5);

    return 0;
}
