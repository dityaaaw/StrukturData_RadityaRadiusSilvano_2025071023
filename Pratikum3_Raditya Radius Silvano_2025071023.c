#include <stdio.h>
#include <stdlib.h>

struct node {
    int nilai;
    struct node *next;
};

struct node *awal = NULL;

// tambah di akhir
void tambahBelakang(int x) {
    struct node *baru = (struct node*) malloc(sizeof(struct node));
    baru->nilai = x;
    baru->next = NULL;

    if (awal == NULL) {
        awal = baru;
    } else {
        struct node *tmp = awal;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = baru;
    }
}

// tambah di depan
void tambahDepan(int x) {
    struct node *baru = (struct node*) malloc(sizeof(struct node));
    baru->nilai = x;
    baru->next = awal;
    awal = baru;
}

// tampilkan isi list
void tampil() {
    struct node *tmp = awal;

    printf("Isi data: ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->nilai);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// hapus berdasarkan nilai
void hapusData(int x) {
    struct node *tmp = awal;
    struct node *sebelum = NULL;

    if (tmp != NULL && tmp->nilai == x) {
        awal = tmp->next;
        free(tmp);
        printf("Data %d dihapus\n", x);
        return;
    }

    while (tmp != NULL && tmp->nilai != x) {
        sebelum = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Data tidak ketemu\n");
        return;
    }

    sebelum->next = tmp->next;
    free(tmp);
    printf("Data %d dihapus\n", x);
}

int main() {

    // 5 node awal
    tambahBelakang(10);
    tambahBelakang(20);
    tambahBelakang(30);
    tambahBelakang(40);
    tambahBelakang(50);

    printf("Data awal:\n");
    tampil();

    tambahDepan(5);
    printf("\nSetelah tambah depan (5):\n");
    tampil();

    tambahBelakang(60);
    printf("\nSetelah tambah belakang (60):\n");
    tampil();

    hapusData(30);
    printf("\nSetelah hapus 30:\n");
    tampil();

    return 0;
}
