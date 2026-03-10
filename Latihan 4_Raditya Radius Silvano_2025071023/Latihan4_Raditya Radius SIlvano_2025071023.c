#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char nim[20];
    char nama[50];
    int nilai;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;
struct node *tail=NULL;

void tambahAwal(){
    struct node *baru=(struct node*)malloc(sizeof(struct node));

    printf("NIM   : ");
    scanf("%s",baru->nim);

    printf("Nama  : ");
    scanf("%s",baru->nama);

    printf("Nilai : ");
    scanf("%d",&baru->nilai);

    baru->prev=NULL;
    baru->next=head;

    if(head!=NULL){
        head->prev=baru;
    }else{
        tail=baru;
    }

    head=baru;
}

void tambahAkhir(){
    struct node *baru=(struct node*)malloc(sizeof(struct node));

    printf("NIM   : ");
    scanf("%s",baru->nim);

    printf("Nama  : ");
    scanf("%s",baru->nama);

    printf("Nilai : ");
    scanf("%d",&baru->nilai);

    baru->next=NULL;
    baru->prev=tail;

    if(tail!=NULL){
        tail->next=baru;
    }else{
        head=baru;
    }

    tail=baru;
}

void hapus(){
    char cari[20];
    printf("Masukkan NIM yang ingin dihapus: ");
    scanf("%s",cari);

    struct node *temp=head;

    while(temp!=NULL){

        if(strcmp(temp->nim,cari)==0){

            if(temp->prev!=NULL){
                temp->prev->next=temp->next;
            }else{
                head=temp->next;
            }

            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }else{
                tail=temp->prev;
            }

            free(temp);
            printf("Data berhasil dihapus\n");
            return;
        }

        temp=temp->next;
    }

    printf("Data tidak ditemukan\n");
}

void tampilMaju(){
    struct node *temp=head;

    while(temp!=NULL){
        printf("%s - %s - %d\n",temp->nim,temp->nama,temp->nilai);
        temp=temp->next;
    }
}

void tampilMundur(){
    struct node *temp=tail;

    while(temp!=NULL){
        printf("%s - %s - %d\n",temp->nim,temp->nama,temp->nilai);
        temp=temp->prev;
    }
}

int main(){

    int pilih;

    do{

        printf("\nMENU\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di akhir\n");
        printf("3. Hapus data\n");
        printf("4. Tampilkan data maju\n");
        printf("5. Tampilkan data mundur\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d",&pilih);

        switch(pilih){

            case 1:
                tambahAwal();
                break;

            case 2:
                tambahAkhir();
                break;

            case 3:
                hapus();
                break;

            case 4:
                tampilMaju();
                break;

            case 5:
                tampilMundur();
                break;
        }

    }while(pilih!=6);

    return 0;
}
