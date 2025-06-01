#include <iostream>
#include <string>
using namespace std;

struct Cust {
    string nama;
    string jenis;
    int harga;
};

struct Node {
    Cust data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

struct History {
    Cust data[100];
    int count = 0;
} history;

void buatQueue() {
    head = NULL;
    tail = NULL;
    history.count = 0;
}

bool queueKosong() {
    return head == NULL;
}

void ambilAntrean() {
    Cust pembeli;
    cout << "Masukkan Nama Customer  : ";
    getline(cin, pembeli.nama);
    cout << "Jenis Roti              : ";
    getline(cin, pembeli.jenis);
    cout << "Total Harga (Rp)        : ";
    cin >> pembeli.harga;
    cin.ignore();

    Node* baru = new Node;
    baru->data = pembeli;
    baru->next = NULL;

    if (queueKosong()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }

    cout << "\n>> Pesanan berhasil ditambahkan ke antrean.\n";
    system("pause");
    system("cls");
}

void layaniPembeli() {
    if (queueKosong()) {
        cout << "\n>> Antrean masih kosong.\n";
        return;
    }

    Node* hapus = head;
    head = head->next;

    cout << "\n>> Melayani pesanan:\n";
    cout << "Nama        : " << hapus->data.nama << endl;
    cout << "Jenis Roti  : " << hapus->data.jenis << endl;
    cout << "Total Harga : Rp" << hapus->data.harga << endl;

    // Simpan ke history
    history.data[history.count++] = hapus->data;

    delete hapus;
    if (head == NULL) {
        tail = NULL;
    }
}

void tampilkanAntrean() {
    if (queueKosong()) {
        cout << "\n>> Tidak ada pesanan dalam antrean.\n";
        return;
    }

    Node* bantu = head;
    int nomor = 1;

    cout << "\n>> Daftar Pesanan dalam Antrean:\n";
    while (bantu != NULL) {
        cout << nomor++ << ". Nama       : " << bantu->data.nama << endl;
        cout << "   Jenis Roti : " << bantu->data.jenis << endl;
        cout << "   Harga      : Rp" << bantu->data.harga << endl;
        cout << "-----------------------------\n";
        bantu = bantu->next;
    }
    system("pause");
    system("cls");
}

void batalkanPesananTerakhir() {
    if (queueKosong()) {
        cout << "\n>> Antrean kosong.\n";
        return;
    }

    if (head == tail) {
        cout << "\n>> Pesanan " << head->data.nama << " berhasil dibatalkan.\n";
        delete head;
        head = tail = NULL;
        return;
    }

    Node* bantu = head;
    while (bantu->next != tail) {
        bantu = bantu->next;
    }

    cout << "\n>> Pesanan " << tail->data.nama << " berhasil dibatalkan.\n";
    delete tail;
    tail = bantu;
    tail->next = NULL;
}

void tampilkanHistory() {
    if (history.count == 0) {
        cout << "\n>> Belum ada pesanan yang dilayani.\n";
        return;
    }

    cout << "\n>> Riwayat Pesanan yang Telah Dilayani:\n";
    for (int i = 0; i < history.count; i++) {
        cout << i + 1 << ". Nama       : " << history.data[i].nama << endl;
        cout << "   Jenis Roti : " << history.data[i].jenis << endl;
        cout << "   Harga      : Rp" << history.data[i].harga << endl;
        cout << "-----------------------------\n";
    }
}

int main() {
    buatQueue();
    int pil;

    do {
        cout << "\n======== TOKO ROTI MANIS LEZAT - DEPOK ========\n";
        cout << "1 | Ambil Antrean\n";
        cout << "2 | Layani Pembeli\n";
        cout << "3 | Tampilkan Pesanan\n";
        cout << "4 | Batalkan Pesanan\n";
        cout << "5 | Tampilkan History Pesanan\n";
        cout << "0 | Keluar\n";
        cout << "===============================================\n";
        cout << "Pilihan Anda: ";
        cin >> pil;
        cin.ignore(); 

        switch (pil) {
            case 1:
                ambilAntrean();
                break;
            case 2:
                layaniPembeli();
                break;
            case 3:
                tampilkanAntrean();
                break;
            case 4:
                batalkanPesananTerakhir();
                break;
            case 5:
                tampilkanHistory();
                break;
            case 0:
                cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                cout << "\n>> Pilihan tidak valid.\n";
        }

    } while (pil != 0);

    return 0;
}
