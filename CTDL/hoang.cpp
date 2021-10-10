#include <iostream>
#include <bitset>
#include <string>
#include <cstring>

using namespace std;



char search(char Test[]) {
    int i;
    int count = 0;
    for(i = 0; i < strlen(Test); i++) {
        if(Test[i] == '1')
            count++;            
    }
    cout << "Count = " << count;

    return count;
}
string TextToBi(string myString, char Test[]) 
{
    string binaryString;
    for (char& _char : myString) 
    {
        binaryString = bitset<7>(_char).to_string();
        binaryString.copy(Test, 7);
        cout.put('\n');

    }
    cout.write(Test, 7);
    search(Test);

    return binaryString;

}



int main() {
    string test;

    char Test[8];

    cout << "Enter a test: ";
    getline(cin , test);
    
    TextToBi(test, Test);
    

    return 0;
}
