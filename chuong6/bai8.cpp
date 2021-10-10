#include <iostream>
#include <fstream>
#include <string>
//#include <cctype>
using namespace std;

void arrayToFile(fstream&);
void fileToArray(fstream&);

const int SIZE = 10;
int myArray[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int myArray1[SIZE];
int main()
{
   fstream file;
   arrayToFile(file);
   fileToArray(file);
   return 0;
}

void arrayToFile(fstream& file)
{
   file.open("pro.txt", ios::out | ios::binary | ios::trunc);
   for (int i = 0; i < SIZE; i++)
   {
      // file << myArray[i] << "\n";
      file.write(reinterpret_cast<char*>(myArray),10);
   }
   file.close();
   cout << "We have written the array to file in binary" << endl;
}
void fileToArray(fstream& file)
{
   file.open("pro.txt", ios::in | ios::binary);
   string line;
   file.read(reinterpret_cast<char*>(myArray1),10);
   for (int i = 0; i < SIZE; i++)
   {
      //file >> line;
      //cout << line << endl;
      cout<<myArray1[i]<<endl;
   }
   file.close();
}