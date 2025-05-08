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
        
        
    };




