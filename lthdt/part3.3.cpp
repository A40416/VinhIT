#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <string.h>
using namespace std;

struct BookData { 
    char bookTitle[100]; // Tên sách
    char Author[100]; // Tác giả
    int pubYear; //năm xuất bản m 
    int numPage; // Số trang
    char pubHouse[100]; //Nhà xuất bản 

    // BookData() {}

    // BookData(char* b, char* a, int pY, int nP, char* pH) {
    //     strcpy(bookTitle, b);
    //     strcpy(Author, a);
    //     pubYear =pY;
    //     numPage = nP;
    //     strcpy(pubHouse, pH);
    // }
    // friend ostream &operator<<(ostream *out, BookData a)
    // {
    //     out<<"----------\n";
    //     out<<"Name: "<<a.bookTitle<<endl;
    //     out<<"Tac gia: "<<a.Author<<endl;
    //     out<<"Nam xb: "<<a.pubYear<<endl;
    //     out<<"Sotrang: "<<a.numPage<<endl;
    //     out<<"Nha xb: "<<a.pubHouse<<endl;
    //     return out;
    // }
};

// int LinearSearch(int A[], int n, int x) {
//     for (int i = 0; i < n; i++)
//         if (A[i] == x)
//             return i;
//     return -1;
// }
// int LinearSearch(BookData a[], int size, int giatritim)
// {
// 	int vitri=-1;
// 	for(int i=0; i<size; i++)
// 	{
// 		if (a[i].pubYear==giatritim)
// 			vitri=i;
// 	}
// 	return vitri;
// }

int main() {
    int a;
    int n;
    int pubYear;

    //BookData aa;

    cout << "Enter to the book quality (n): ";
    cin >> n;

    BookData book[n];
    BookData _book[n];
    char *k1;
    char *k2;
    char *k3;


    for(int i = 0; i < n; i++) {
        cout << "Book Title #" << (i + 1) << endl;
        cout << "Enter a book title: ";
        cin >> book[i].bookTitle;
        cout << "Enter a author: ";
        cin >> book[i].Author;
        cout << "Enter a pubYear: ";
        cin >> book[i].pubYear;
        cout << "Enter a page number: ";
        cin >> book[i].numPage;
        cout << "Enter a pubHouse of: ";
        cin >> book[i].pubHouse;

        cout << endl << endl;
    }

    // struct BookData b1 = {"Nhà giả kim", "Paulo Coelho", 1988, 133, "NXB Văn học"};
    // struct BookData b1 = {"qwertyu", "Paullho", 1978, 154, "NXB Văn học"};
    // struct BookData b1 = {"dsavfdsavdsa", "PaudslCoelho", 1965, 176, "NXB Văn học"};
    // struct BookData b1 = {"sadfsdaf", "Paulo cCoelho", 1998, 198, "NXB Văn học"};
    // struct BookData b1 = {"dhergyet", "Paulo dfcdsCoelho", 1996, 173, "NXB Văn học"};
    // struct BookData b1 = {"dsqrfewfdsaf", "PauloSD Coelho", 1968, 162, "NXB Văn học"};
    // struct BookData b1 = {"sdadcascx", "Paulo DsCoelho", 1958, 179, "NXB Văn học"};
    // struct BookData b1 = {"fgsfacsvc", "Paulo SDCoelho", 1988, 167, "NXB Văn học"};
    // struct BookData b1 = {"rwrfcdsavcs", "PauloDSSA Coelho", 1934, 195, "NXB Văn học"};
    // struct BookData b1 = {"csavawwf", "Paulo CsDoelho", 1948, 147, "NXB Văn học"};
    // struct BookData b1 = {"trhyrjhy", "Paulo sadCoelho", 1956, 127, "NXB Văn học"};

    fstream f;
    f.open("Data.txt", ios::out | ios:: binary);
    f.write(reinterpret_cast<char*>(book),sizeof(book));
    f.close();
    
    
    f.open("Data.txt", ios::in | ios:: binary);
    f.read(reinterpret_cast<char*>(_book),sizeof(book));
    f.close();

    

    cout << "Enter the year of publication: ";
    cin >> pubYear;

    //a=LinearSearch(book[], n, pubYear);
    // for(int i=0; i<sizeof(a); i++)
    // {
    //     cout<<book[a[i]];
    // }

    for(int i=0; i<n; i++)
    {
        if(_book[i].pubYear==pubYear)
        {
            cout<< _book[i].bookTitle<<endl;
            cout<< _book[i].Author<<endl;
            cout<< _book[i].pubYear<<endl;
            cout<< _book[i].numPage<<endl;
            cout<< _book[i].pubHouse<<endl;
            //cout<<book[i];
            cout<< "---------------------\n";
        }


    }



    return 0;
}
    

    
