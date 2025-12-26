#include <stdio.h>
#include <string.h>

int main() {
    char namaPembeli[50], namaMetode[20];
    int pilihan, jumlah, total = 0, caraBayar, diskon = 0;
    char lanjut;
    FILE *file;

    printf("=== KANTIN SEDERHANA ===\n");
    printf("Nama Pembeli: ");
    fgets(namaPembeli, sizeof(namaPembeli), stdin);
    namaPembeli[strcspn(namaPembeli, "\n")] = '\0';

    do {
        printf("\n--- MENU MAKANAN ---\n");
        printf("1. Nasi Goreng  (Rp 15.000)\n");
        printf("2. Ayam Geprek  (Rp 12.000)\n");
        printf("3. Mie Goreng   (Rp 10.000)\n");
        printf("4. Es Teh Manis (Rp  5.000)\n");
        printf("5. Kopi Hitam   (Rp  7.000)\n");
        
        printf("Pilih nomor menu (1-5): ");
        scanf("%d", &pilihan);
        printf("Jumlah porsi: ");
        scanf("%d", &jumlah);

        int harga = 0;
        if (pilihan == 1) harga = 15000;
        else if (pilihan == 2) harga = 12000;
        else if (pilihan == 3) harga = 10000;
        else if (pilihan == 4) harga = 5000;
        else if (pilihan == 5) harga = 7000;

        total += (harga * jumlah);

        printf("Ada pesanan lain? (y/n): ");
        scanf(" %c", &lanjut);
    } while (lanjut == 'y' || lanjut == 'Y');

    if (total >= 50000) {
        diskon = total * 0.1; 
    }

    printf("\n--- METODE BAYAR ---\n");
    printf("1. Cash (Tunai)\n");
    printf("2. QRIS (Digital)\n");
    printf("Pilih (1-2): ");
    scanf("%d", &caraBayar);

    if (caraBayar == 1) strcpy(namaMetode, "Cash");
    else strcpy(namaMetode, "QRIS");

    file = fopen("struk_kantin.txt", "a"); 

    printf("\n========================\n");
    printf("   STRUK PEMBAYARAN\n");
    printf("========================\n");
    printf("Nama      : %s\n", namaPembeli);
    printf("Total     : Rp %d\n", total);
    printf("Diskon    : Rp %d\n", diskon);
    printf("Bayar     : Rp %d\n", total - diskon);
    printf("Metode    : %s\n", namaMetode);
    printf("========================\n");

    fprintf(file, "Nama: %s | Total: %d | Diskon: %d | Akhir: %d | Metode: %s\n", 
            namaPembeli, total, diskon, total - diskon, namaMetode);
    
    fclose(file);
    printf("Data berhasil dicatat ke struk_kantin.txt\n");

    return 0;
}
