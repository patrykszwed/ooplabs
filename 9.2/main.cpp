#include <iostream>
#include <algorithm>

using namespace std;

struct invalidStringException : public exception{
    const char * what() const throw(){
        return "Invalid string!";
    }
};

int isValidString(string input){
    for (char i : input)
        if (!(isalpha(i)))
            return 0;

    return 1;
}

void toLowerCases(string &data){
    for (char &i : data)
        i = (char)tolower(i);
}

string delSpaces(string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

string oneTimePad(string plaintext, string key) {
    int arrayLength = key.length();
    int plaintextArray[arrayLength], keyArray[arrayLength];
    string result;

    for(int i = 0; i < arrayLength; ++i)
        plaintextArray[i] = plaintext[i];

    for(int i = 0; i < arrayLength; ++i)
        keyArray[i] = key[i];

    for(int i = 0; i < arrayLength; ++i) {
        int tempResult = plaintext[i] + keyArray[i]; // variable to hold result of adding ASCII codes
        if(tempResult > 193 && tempResult < 220)    // a + a is min(194) and a + z(122 + 97 = 219) is max for this condition
            tempResult -= 97;
        else
            tempResult -= 123;
        result += char(tempResult);
    }

    return result;
}

int main() {
    // EXAMPLE PAIRS:

    // string plaintext = "this is secret";
    // string key = "xvhe uw nopgdz";
    // encrypted: qcpwcofsrxhs
    // SOURCE: https://www.google.com/search?q=one+time+pad+examples&source=lnms&tbm=isch&sa=X&ved=0ahUKEwilmbeU6OPfAhWplIsKHVYvCoYQ_AUIDigB&biw=958&bih=924#imgrc=j6mRs3j5IVpGuM:

    // string plaintext = "come today";
    // string key = "ncbtzqarx";
    // encrypted: pqnxsedrv
    // SOURCE: https://www.youtube.com/watch?v=YdJX-8g--H4

    string key, plaintext;

    cout << "What text do you want to code?\n";
    getline(cin, plaintext);

    // change to lower cases
    toLowerCases(plaintext);

    // remove spaces
    delSpaces(plaintext);

    try {
        if(!isValidString(plaintext))
            throw invalidStringException();
    }catch(invalidStringException &exception1){
        cout << exception1.what() << endl;
        return 0;
    }

    cout << "\nProvide a key(has to have the same length as the plaintext):\n";
    getline(cin, key);

    // change to lower cases
    toLowerCases(key);

    // remove spaces
    delSpaces(key);

    try {
        if(!isValidString(key))
            throw invalidStringException();
    }catch(invalidStringException &exception1){
        cout << exception1.what() << endl;
        return 0;
    }

    // check lengths of plaintext and key
    try {
        if (plaintext.length() != key.length())
            throw "\nLengths are not equal!\n";
    } catch(const char * msg){
        cout << msg;
        return 0;
    }

    cout << "\nEncrypted message is: " << oneTimePad(plaintext, key) << endl;

    return 0;
}