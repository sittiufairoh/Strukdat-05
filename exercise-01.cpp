/*
Nama Program	: exercise-01
Nama			: SITTI UFAIROH AZZAHRA
NPM				: 140810180002
Tanggal			: 27 Maret 2019
*/

#include <iostream>
using namespace std;

struct Pembalap {
   int nomor;
   char nama;
   int waktu;
   Pembalap* next;
   Pembalap* prev;
};

void createNode(Pembalap* &p,  int nomor, char nama){
    p=new Pembalap;
	cout << "nomor	: " ;cin >> p->nomor;
	cout << "nama	: " ;cin >> p->nama ;
	cout << "waktu	: " ;cin >> p->waktu ;
    p->next=NULL;
    p->prev=NULL;
    cout<<endl;
}

void insertFirst(Pembalap* &head, Pembalap* node){
	if (head==NULL)
		head = node;
	else{
		node->next = head;
		node->prev = node;
		head = node;
	}
}

void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node){
    Pembalap* pCari;
    if(pCari->next==NULL)
        pCari->next=node;
    else{
        node->next=pCari;
        node->prev=pCari->prev;
        pCari->prev->next=node;
        pCari->prev=node;
    }
}


void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode){
 Pembalap* pCari;
 Pembalap* pHapus;
      pCari = head;
      while(pCari != NULL){
        if(pCari->nomor == nomorKey){
          /*if(pCari->next == NULL){
            Pembalap last;
            last = head;
        while(last->next)
       }
      }*/ pHapus = pCari;     
 		pCari->prev->next = pCari->next;
  		pCari->next->prev = pCari->prev;
		pCari->next = NULL;
  		pCari->prev = NULL;
    	}
	}
}

void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate){
	pToUpdate=firstNode;
	while(pToUpdate->nomor!=nomorKey){
		pToUpdate=pToUpdate->next;
	}
}

void traversal(Pembalap* head){
    Pembalap* pBantu;
    if (head==NULL){
        cout<<"LIST KOSONG";
    }
    else {
        pBantu=head;
        while(pBantu!=NULL){
            cout<<"\nNomor	: "<<pBantu->nomor<<endl;
            cout<<"Nama	: "<<pBantu->nama<<endl;
            cout<<"Waktu	: "<<pBantu->waktu<<endl;
            cout<<endl;
            pBantu=pBantu->next;
        }
    }
}

void sortingByNomor(Pembalap* &head);
void update(Pembalap* firstNode, int nomorKey);

int main() {
    Pembalap* head = NULL;
    Pembalap* pBaru = NULL;
    Pembalap* pToUpdate = NULL;
    char nama = 'a';

    for (int i = 0; i < 4; i++) {
        createNode(pBaru, i+1, nama++);
        insertFirst(head, pBaru);
    }
    cout << "\n>>> List" << endl;
    traversal(head);

    int keyNomor = 2;

 	cout << "\n>>> Insert Before nomor " << keyNomor << endl;
 	createNode(pBaru, 99, 'z');
 	insertBefore(head, keyNomor, pBaru); 
 	traversal(head);

/*	cout << "\n>>> SortingByNomor" << endl;
	sortingByNomor(head);
	traversal(head);
*/
	keyNomor = 3;
 	cout << "\n>>> Delete nomor " << keyNomor << endl;
 	Pembalap* pHapus = NULL;
 	deleteByKey(head, keyNomor, pHapus);
 	traversal(head);
/*
 	keyNomor = 4;
 	cout << "\n>>> Update nomor " << keyNomor << endl;
 	update(head, keyNomor);
	cout << "\n>>> Updated list\n";
	traversal(head);*/
}




/////TOLONGG SUSAHHHH:((
