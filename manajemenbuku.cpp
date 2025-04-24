#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buku {
    char kode[20];
    char judul[100];
    char pengarang[100];
    int tahun;
    char status[20];
    struct Buku* next;
};

struct Buku* head = NULL;

struct Buku* buatNodeBaru(char kode[], char judul[], char pengarang[], int tahun, char status[]) {
    struct Buku* newNode = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(newNode->kode, kode);
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->tahun = tahun;
    strcpy(newNode->status, status);
    newNode->next = NULL;
    return newNode;
}

void tambahBukuDiAwal() {
    char kode[20], judul[100], pengarang[100], status[20];
    int tahun;

    printf("\n?? Tambah Buku Baru\n");
    printf("Kode Buku: "); scanf(" %[^\n]", kode);
    printf("Judul Buku: "); scanf(" %[^\n]", judul);
    printf("Pengarang: "); scanf(" %[^\n]", pengarang);
    printf("Tahun Terbit: "); scanf("%d", &tahun);
    printf("Status (Tersedia/Dipinjam): "); scanf(" %[^\n]", status);

    struct Buku* newNode = buatNodeBaru(kode, judul, pengarang, tahun, status);
    newNode->next = head;
    head = newNode;

    printf("? Buku berhasil ditambahkan di awal.\n");
}

void hapusBukuDiAkhir() {
    if (head == NULL) {
        printf("? Daftar buku kosong.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("? Buku terakhir berhasil dihapus.\n");
        return;
    }

    struct Buku* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("? Buku terakhir berhasil dihapus.\n");
}

void tampilkanBuku() {
    if (head == NULL) {
        printf("?? Tidak ada buku di perpustakaan.\n");
        return;
    }

    struct Buku* temp = head;
    int i = 1;
    printf("\n?? Daftar Buku Perpustakaan:\n");
    while (temp != NULL) {
        printf("\nBuku ke-%d:\n", i++);
        printf("Kode       : %s\n", temp->kode);
        printf("Judul      : %s\n", temp->judul);
        printf("Pengarang  : %s\n", temp->pengarang);
        printf("Tahun      : %d\n", temp->tahun);
        printf("Status     : %s\n", temp->status);
        temp = temp->next;
    }
}

int main() {
    int pilihan;

    do {
        printf("\n=== MENU PERPUSTAKAAN (Linked List) ===\n");
        printf("1. Tambah Buku di Awal\n");
        printf("2. Hapus Buku Terakhir\n");
        printf("3. Tampilkan Semua Buku\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBukuDiAwal();	
                break;
            case 2:
                hapusBukuDiAkhir();
                break;
            case 3:
                tampilkanBuku();
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

