#include <stdio.h>

int main() {


    // BAGIAN 1 – LOOPING


    // Nomor 1
    printf("Bagian 1 - Nomor 1\n");
    printf("Angka 1 sampai 10:\n");
    for(int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }

    printf("\n\n");

    // Nomor 2
    printf("Bagian 1 - Nomor 2\n");
    printf("Bilangan genap 1 sampai 50:\n");
    for(int i = 2; i <= 50; i += 2) {
        printf("%d ", i);
    }


    // BAGIAN 2

    int n, jumlah = 0;

    printf("\n\nBagian 2\n");
    printf("Masukkan angka N: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        jumlah += i;
    }

    printf("Jumlah 1 sampai %d = %d\n", n, jumlah);


    // BAGIAN 3

    int nilai[5];
    int total = 0;

    printf("\nBagian 3\n");
    printf("Masukkan 5 nilai:\n");

    for(int i = 0; i < 5; i++) {
        printf("Nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);
        total += nilai[i];
    }

    float rata = total / 5.0;

    printf("Total = %d\n", total);
    printf("Rata-rata = %.2f\n", rata);

    return 0;
}
