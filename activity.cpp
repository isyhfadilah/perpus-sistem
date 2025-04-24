#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Transaksi {
    char nama[100];
    char buku[100];
    char tanggal[20];
};

struct Transaksi stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push() {
    if (isFull()) {
        printf("? Stack penuh. Tidak bisa menambahkan transaksi baru.\n");
        return;
    }

    struct Transaksi t;
    printf("\n?? Tambah Riwayat Transaksi\n");
    printf("Nama Peminjam : "); scanf(" %[^\n]", t.nama);
    printf("Judul Buku    : "); scanf(" %[^\n]", t.buku);
    printf("Tanggal       : "); scanf(" %[^\n]", t.tanggal);

    top++; 
    stack[top] = t;

    printf("? Transaksi berhasil ditambahkan ke riwayat.\n");
}

void pop() {
    if (isEmpty()) {
        printf("? Stack kosong. Tidak ada transaksi yang bisa dihapus.\n");
        return;
    }

    printf("??? Menghapus transaksi: %s - %s (%s)\n", stack[top].nama, stack[top].buku, stack[top].tanggal);
    top--;
}

void peek() {
    if (isEmpty()) {
        printf("? Tidak ada transaksi dalam riwayat.\n");
        return;
    }

    printf("?? Transaksi terakhir:\n");
    printf("Nama     : %s\n", stack[top].nama);
    printf("Buku     : %s\n", stack[top].buku);
    printf("Tanggal  : %s\n", stack[top].tanggal);
}

void tampilkanRiwayat() {
    if (isEmpty()) {
        printf("?? Riwayat transaksi masih kosong.\n");
        return;
    }

    printf("\n?? Riwayat Transaksi (Stack):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d. %s - %s (%s)\n", top - i + 1, 
		stack[i].nama, stack[i].buku, stack[i].tanggal);
    }
}

int main() {
    int pilihan;

    do {
        printf("\n=== MENU RIWAYAT TRANSAKSI (Stack) ===\n");
        printf("1. Tambah Transaksi (Push)\n");
        printf("2. Hapus Transaksi Terakhir (Pop)\n");
        printf("3. Lihat Transaksi Terakhir (Peek)\n");
        printf("4. Tampilkan Semua Riwayat\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                tampilkanRiwayat();
                break;
            case 0:
                printf("?? Keluar dari program.\n");
                break;
            default:
                printf("?? Pilihan tidak valid.\n");
        }
    } while (pilihan != 0);

    return 0;
}

