#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12

struct Peminjam {
    char nama[100];
    char buku[100];
};

struct Peminjam queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue() {
    if (isFull()) {
        printf("? Antrean penuh. Tidak dapat menambahkan peminjam.\n");
        return;
    }

    struct Peminjam p;
    printf("\n?? Tambah Peminjam\n");
    printf("Nama Peminjam: "); scanf(" %[^\n]", p.nama);
    printf("Judul Buku   : "); scanf(" %[^\n]", p.buku);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = p;
    printf("? Peminjam berhasil ditambahkan ke antrean.\n");
}

void dequeue() {
    if (isEmpty()) {
        printf("? Antrean kosong.\n");
        return;
    }

    printf("? Melayani peminjam: %s (Buku: %s)\n", queue[front].nama, queue[front].buku);
	
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void peek() {
    if (isEmpty()) {
        printf("? Tidak ada peminjam dalam antrean.\n");
        return;
    }

    printf("?? Peminjam berikutnya: %s (Buku: %s)\n", queue[front].nama, queue[front].buku);
}

void tampilkanAntrean() {
    if (isEmpty()) {
        printf("?? Tidak ada antrean saat ini.\n");
        return;
    }

    printf("\n?? Daftar Antrean Peminjam:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s - Buku: %s\n", i - front + 1, queue[i].nama, queue[i].buku);
    }
}

int main() {
    int pilihan;

    do {
        printf("\n=== MENU ANTREAN PEMINJAMAN (Queue) ===\n");
        printf("1. Tambah Peminjam (Enqueue)\n");
        printf("2. Layani Peminjam (Dequeue)\n");
        printf("3. Lihat Peminjam Berikutnya (Peek)\n");
        printf("4. Tampilkan Semua Antrean\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                tampilkanAntrean();
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

