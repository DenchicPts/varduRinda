#include "rtu.h"


int main() {

	//string input = "Paradigm (PP(procedural program), OOP(object oriented program)) is program style";
    string input = "Strings can contain single-byte (ASCII) or multi-byte (UNICODE) characters";

    cout << "A : " << firstUzdevums(input) << endl;
    cout << "B : " << secondUzdevums(input) << endl;
    cout << "C : " << thirdUzdevums(input) << endl;
    cout << "D : ";
    vector result = fourthUzdevums(input);

    for (string& i : result)
    {
        cout << i << ", ";
    }
   

	return 0;
}
