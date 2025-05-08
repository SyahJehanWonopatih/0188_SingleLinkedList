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

      
        };
    



