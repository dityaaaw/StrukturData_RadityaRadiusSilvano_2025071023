#include <stdio.h>


int hitungTotal(int data[], int ukuran) {
    int jumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        jumlah = jumlah + data[i];
    }
    return jumlah;
}


float hitungRataRata(int data[], int ukuran) {
    int jumlah = hitungTotal(data, ukuran);
    float rata = (float) jumlah / ukuran;
    return rata;
}

int nilaiTertinggi(int data[], int ukuran) {
    int tertinggi = data[0];
    for(int i = 1; i < ukuran; i++) {
        if(data[i] > tertinggi) {
            tertinggi = data[i];
        }
    }
    return tertinggi;
}

int main() {

    int nilai[10];
    int ukuran = 10;

    // Input data
    printf("Input 10 nilai berikut:\n");
    for(int i = 0; i < ukuran; i++) {
        printf("Data ke-%d - ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // Proses
    int total = hitungTotal(nilai, ukuran);
    float rata = hitungRataRata(nilai, ukuran);
    int max = nilaiTertinggi(nilai, ukuran);

    // Output
    printf("\n----- HASIL PERHITUNGAN -----\n");
    printf("Total Nilai - %d\n", total);
    printf("Rata-rata - %.2f\n", rata);
    printf("Nilai Tertinggi - %d\n", max);

    return 0;
}
