#include <iostream>
#include <string.h>
using namespace std;

class node {
    public:
        int noMhs;
        node *next;
};

class SingelLinkedList {    //membuat class SingelLinkedList
    node *START;

    public: //membuat aksesnya menjadi public
        SingelLinkedList() {        
            START = NULL;
        }

        void addNode() {     //membuat fungsi untuk menambah node
            int nim;
            cout << "\nMasukkan Nomor Mahasiswa : ";
            cin >> nim;

            node *nodeBaru = new node;
            nodeBaru -> noMhs = nim;

            if(START == NULL || nim <= START->noMhs) {  
                if ((START != NULL) && (nim == START->noMhs)) {
                    cout << "\nDuplikasi no mahasiswa tidak di izinkan\n";
                    return;
                }
                nodeBaru->next = START;
                START = nodeBaru;
                return;
            }
            node *previous = START;
            node *current = START;
            while ((current != NULL) && (current->noMhs < nim)) {
                  if (nim == current->noMhs) {
                    cout << "\nDuplikasi noMhs tidak di izinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }

            nodeBaru->next = current;
            previous->next = nodeBaru;

        }
        bool ListEmpty() {  //cek apakah list kosong
            return (START == NULL);
        }

        bool Search(int nim, node **previous, node ** current) {    //membuat fungsi untuk mencari kode
            *previous = START;  
            *current = START;

            while ((*current != NULL) && (nim != (*current)->noMhs)) {
                *previous = *current;
                *current = (*current)->next;
            }
            return (*current != NULL);
        }
        bool delNode(int nim) {     //membuat fungsi untuk menghapus node
            node *current, *previous;
            if (!Search(nim, &previous, &current))
                return false;
            if (current == START)
                START = START->next;
            else
                previous->next = current->next;
            delete current;
            return true;
        }
        
        void traverse() {   //membuat fungsi untuk menampilkan node
            if (ListEmpty()) {
                cout << "\nList kosong\n";
            }
        else {
            cout << "\nData didalam list adalah : \n";
            node *currentnode = START;
            while (currentnode != NULL) {
                cout << currentnode->noMhs << endl;
                currentnode = currentnode->next;
            }
            cout << endl;
        }
    }
};

int main() {    //memnaggil interger ke main 
    SingelLinkedList mhs;
    int nim;
    char ch;
    while (1) { //membuat perulangan
        cout << endl
             << "menu";
        cout << endl
             << "1. menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data didalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl
             << "Masukkan pilihan (1-5) : ";
        cin >> ch;
        switch (ch) {
            case '1': { //membuat fungsi case 1
                mhs.addNode();
            }
            break;

            case '2': { //membuat fungsi case 2
                if (mhs.ListEmpty()) {
                    cout << endl
                         << "List kosong" << endl;
                    break;
                }
                cout << endl
                     << "\nMasukkan Nomor Mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (mhs.delNode(nim) == false) 
                    cout << endl
                         << "Data tidak ditemukan" << endl;
                else 
                    cout << endl
                         << " Data dengan nomor mahasiswa " << nim << " berhasil di hapus " << endl;
            }
            break;
            
    }
}



