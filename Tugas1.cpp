#include <iostream>
#include <iomanip>
using namespace std;

struct data
{
    string nama;
    int nim;
    float ipk;
};

data mhs[]={
    {"Budi Santoso", 124240001, 3.5},
    {"Andi Haryanto", 124240002, 3.6},
    {"Caca Arlianda P.", 124240003, 3.7},
    {"Dedi Hebiana Bo", 124240004, 3.8},
    {"Euis Martina", 124240005, 3.9},
    {"Feri Jacymanti", 124240006, 3.4},
    {"Gina Maulina S.", 124240007, 3.3},
    {"Hadi Anjani", 124240008, 3.2},
    {"Ika Rika Praptiningtyas", 124240009, 3.1},
    {"Ayu Sabrina P.", 124240010, 3},
};

int banyak = sizeof(mhs)/sizeof(mhs[0]);
int hasil = 0;

data *ptr_mhs = mhs;

string *ptr_nama = &ptr_mhs->nama;
int *ptr_nim = &ptr_mhs->nim;
float *ptr_ipk = &ptr_mhs->ipk;

void tampilData(data *ptr_mhs, int banyak);
void mencariData();
void binarySearch(data *ptr_, int banyak);
void sequentialSearch(data *ptr_mhs, int banyak);
void hasilData(data *ptr_mhs, int hasil);
void bubbleSort(data *ptr_mhs, int banyak);
void quick_sort(data *ptr_mhs, int banyak);
void urutkanData();


int main(){
    int menu;

    do
    {
        cout << "=========================================\n";
        cout << "|              MENU PILIHAN             |\n";
        cout << "========================================\n";
        cout << "| 1. Menampilkan Data Mahasiswa         |\n";
        cout << "| 2. Mencari Data                       |\n";
        cout << "| 3. Mengurutkan Data                   |\n";
        cout << "| 4. Exit                               |\n";
        cout << "=========================================\n\n";
    
        cout << "| Pilih Menu | : ";
        cin >> menu;
        cin.ignore();
        system("cls");

        switch (menu)
        {
        case 1:
            tampilData(mhs, banyak);
            break;

        case 2:
            mencariData();
            break;

        case 3:
            urutkanData();
            break;
        
        default:
            break;
        }
    } while (menu != 1 && menu != 2 && menu != 3 && menu != 4);
    
}

void tampilData(data *ptr_mhs, int banyak){
    int pil2;
    cout << "===============================================\n";
    cout << "|                 TAMPIL DATA                 |\n";
    cout << "===============================================\n";

    if (banyak == 0)
        cout << "Belum ada data yang diinput";

        cout << "| No. |" << "          Nama         |" << "   NIM   |" << " IPK |\n"; 
        cout << "-----------------------------------------------\n";
        for (int i = 0; i < banyak; i++)
        {
            cout << "|" << setw(3) << i+1 << setw(3) << "|" << setw(23) << ptr_mhs[i].nama << "|" << setw(9) << ptr_mhs[i].nim << "|" << setw(4) << ptr_mhs[i].ipk << setw(3) << "|\n";
            cout << "-----------------------------------------------\n";
        }

    cout << "Menu Utama (0) | Keluar (1) ";
    cin >> pil2;
    system("cls");
    if (pil2 == 0)
    { main(); }
    else if (pil2 == 1)
    { exit(0); }
}

void mencariData(){
    int cari;
    do
    {
        cout << "======================================\n";
        cout << "|              CARI DATA             |\n";
        cout << "======================================\n";
        cout << "| 1. Cari NIM                        |\n";
        cout << "| 2. Cari Nama                       |\n";
        cout << "======================================\n";
        cout << " Pilih Menu : ";
        cin >> cari;

        switch (cari)
        {
        case 1:
            sequentialSearch(mhs, banyak);
            break;

        case 2:
            binarySearch(mhs, banyak);
            break;
        
        default:
            break;
        }
    } while (cari != 1 && cari !=2);
    
}

void binarySearch(data *ptr, int banyak){
    int pil3;
    string cari_nama;
    bool found = false;
    int awal = 0;
    int akhir = banyak - 1;
    int tengah;

    cout << "======================================\n";
    cout << "|              CARI NAMA             |\n";
    cout << "======================================\n"; cin.ignore();
    cout << " Data Mahasiswa Nama : "; getline(cin, cari_nama);

    for (int i = 0; i < banyak - 1; i++) {
        for (int j = 0; j < banyak - i - 1; j++) {
            if (ptr_mhs[j].nama > ptr_mhs[j + 1].nama) { 
                swap(ptr_mhs[j], ptr_mhs[j + 1]);
            }
        }
    }

    while ((!found) && awal <= akhir)
    {
    tengah = (awal+akhir)/2;
    if (cari_nama == mhs[tengah].nama)
    {
        found = true;
    } else {
        if (cari_nama < mhs[tengah].nama)
        {
            akhir = tengah - 1;
        } else {
            awal = tengah + 1;
        }
        
    }
    
    }

    if (found == true)
    {
            if(cari_nama == mhs[tengah].nama)
            cout << "Status : Data Tersedia\n";
            cout << "|" << setw(3) << 1 << setw(3) << "|" << setw(23) << ptr_mhs[tengah].nama << "|" << setw(9) << ptr_mhs[tengah].nim << "|" << setw(4) << ptr_mhs[tengah].ipk << setw(3) << "|\n";
            cout << "-----------------------------------------------\n";
        
        
    } else {
        cout << "Status : Data Tidak Tersedia\n";
    }

    cout << "Menu Utama (0) | Keluar (1) ";
    cin >> pil3;
    system("cls");
    if (pil3 == 0)
    { main(); }
    else if (pil3 == 1)
    { exit(0); }
}


void sequentialSearch(data *ptr_mhs, int banyak){
    int pil3;
    int i=0;
    int nim_cari;
    int hasil = 0;
    bool found = false;

    cout << "======================================\n";
    cout << "|              CARI  NIM             |\n";
    cout << "======================================\n"; 
    cout << " Data Mahasiswa NIM : "; cin >> nim_cari;
    
    mhs[banyak].nim = nim_cari;

    while(mhs[i].nim != nim_cari){
        if (mhs[i].nim == nim_cari)
        {
            found == true;
        } else {
            i++;
        }
    }

    if (i < (banyak))
    {
        cout << "Status : Data tersedia\n";
        cout << "| No. |" << "          Nama         |" << "   NIM   |" << " IPK |\n"; 
        cout << "-----------------------------------------------\n";
            cout << "|" << setw(3) << 1 << setw(3) << "|" << setw(23) << ptr_mhs[i].nama << "|" << setw(9) << ptr_mhs[i].nim << "|" << setw(4) << ptr_mhs[i].ipk << setw(3) << "|\n";
            // cout << "Nama  : " << ptr_mhs[i].nama << "\n";
            // cout << "NIM   : " << ptr_mhs[i].nim << "\n";
            // cout << "IPK   : " << ptr_mhs[i].ipk << "\n";
            cout << "-----------------------------------------------\n";
    } else {
        cout << "Status : Data tidak tersedia\n";
        }


    cout << "Menu Utama (0) | Keluar (1) ";
    cin >> pil3;
    system("cls");
    if (pil3 == 0)
    { main(); }
    else if (pil3 == 1)
    { exit(0); }
}

void hasilData(data *ptr, int hasil) {
    cout << "| No. |" << "          Nama         |" << "   NIM   |" << " IPK |\n"; 
        cout << "-----------------------------------------------\n";

        for (int i = 0; i < hasil; i++)
        {
            cout << "|" << setw(3) << 1 << setw(3) << "|" << setw(23) << ptr_mhs[hasil].nama << "|" << setw(9) << ptr_mhs[hasil].nim << "|" << setw(4) << ptr_mhs[hasil].ipk << setw(3) << "|\n";
            // cout << "Nama  : " << ptr_mhs[i].nama << "\n";
            // cout << "NIM   : " << ptr_mhs[i].nim << "\n";
            // cout << "IPK   : " << ptr_mhs[i].ipk << "\n";
            cout << "-----------------------------------------------\n";
        }
        
}

void quick_sort(data *ptr_mhs, int awal, int akhir) {
        int pil2;

        int low = awal, high = akhir;
        float pivot = ptr_mhs[(awal + akhir) / 2].ipk; 
        int temp;

        do {
            while (ptr_mhs[low].ipk < pivot)
                low++;
            while (ptr_mhs[high].ipk > pivot)
                high--;
    
            if (low <= high) {
                swap(ptr_mhs[low], ptr_mhs[high]);
                low++;
                high--;
            }
        } while (low <= high);
    
        if (awal < high)
            quick_sort(ptr_mhs, awal, high);
        if (low < akhir)
            quick_sort(ptr_mhs, low, akhir);

            cout << "| No. |" << "          Nama         |" << "   NIM   |" << " IPK |\n"; 
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < banyak; i++)
            {
                cout << "|" << setw(3) << i+1 << setw(3) << "|" << setw(23) << ptr_mhs[i].nama << "|" << setw(9) << ptr_mhs[i].nim << "|" << setw(4) << ptr_mhs[i].ipk << setw(3) << "|\n";
                cout << "-----------------------------------------------\n";
            }

            cout << "Menu Utama (0) | Keluar (1) ";
            cin >> pil2;
            system("cls");
            if (pil2 == 0)
            { main(); }
            else if (pil2 == 1)
            { exit(0); }
    
    }


void urutkanData(){
    int cari;

do
    {
        cout << "======================================\n";
        cout << "|            URUTKAN DATA            |\n";
        cout << "======================================\n";
        cout << "| 1. ASC (quick sort)                |\n";
        cout << "| 2. DESC (bubble sort)              |\n";
        cout << "======================================\n";
        cout << " Pilih Menu : ";
        cin >> cari;

        switch (cari)
        {
        case 1:
            quick_sort(mhs, 0, banyak-1);
            break;

        case 2:
            bubbleSort(mhs, banyak);
            break;
        
        default:
            break;
        }
    } while (cari != 1 && cari !=2);
    
}

void bubbleSort(data *ptr_mhs, int banyak){
    int pil2;

   for (int i = 0; i < banyak - 1; i++) {
      for (int j = 0; j < banyak - 1 - i; j++) {
         if (mhs[j].ipk < mhs[j + 1].ipk) {
            swap(mhs[j], mhs[j + 1]);
            // swap(mhs[j].ipk, mhs[j + 1].ipk);
         }
      }
   }

   cout << "| No. |" << "          Nama         |" << "   NIM   |" << " IPK |\n"; 
   cout << "-----------------------------------------------\n";
   for (int i = 0; i < banyak; i++)
   {
       cout << "|" << setw(3) << i+1 << setw(3) << "|" << setw(23) << ptr_mhs[i].nama << "|" << setw(9) << ptr_mhs[i].nim << "|" << setw(4) << ptr_mhs[i].ipk << setw(3) << "|\n";
       cout << "-----------------------------------------------\n";
   }

   cout << "Menu Utama (0) | Keluar (1) ";
   cin >> pil2;
   system("cls");
   if (pil2 == 0)
   { main(); }
   else if (pil2 == 1)
   { exit(0); }
}




    
    


