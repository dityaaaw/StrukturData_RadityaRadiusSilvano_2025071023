#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Tambah data di akhir
void tambahData(int nilai) {
    struct Node *baru = (struct Node*) malloc(sizeof(struct Node));
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    printf("Data berhasil ditambahkan.\n");
}

// Hapus data
void hapusData(int nilai) {
    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        free(temp);
        printf("Data berhasil dihapus.\n");
        return;
    }

    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data tidak ditemukan.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Data berhasil dihapus.\n");
}

// Tampil data
void tampilData() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List kosong.\n");
        return;
    }

    printf("Isi Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int pilihan, nilai;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Data\n");
        printf("2. Hapus Data\n");
        printf("3. Tampil Data\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &nilai);
                tambahData(nilai);
                break;
            case 2:
                printf("Masukkan nilai yang ingin dihapus: ");
                scanf("%d", &nilai);
                hapusData(nilai);
                break;
            case 3:
                tampilData();
                break;
            case 4:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 4);

    return 0;
}
