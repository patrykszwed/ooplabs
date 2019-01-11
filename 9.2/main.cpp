#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int *generateKey(unsigned long size) {
    char *block = new char[size + 1];
    int *result = new int[size];

    ifstream urandom("/dev/urandom", ios::in | ios::binary);
    urandom.read(block, static_cast<streamsize>(size));

    for (unsigned long i = 0; i < size; ++i)
        result[i] = abs(block[i]) % 26;

    urandom.close();
    delete[] block;

    return result;
}

void showKey(const int *otp, unsigned long len) {
    for (unsigned long i = 0; i < len; ++i)
        cout << otp[i] << ',';
    cout << "\n";
}

string encrypt(string &sentence, const int *otp) {
    string result;

    for (unsigned long i = 0; i < sentence.length(); ++i) {
        if (isalpha(sentence[i]))
            result += (char) ((tolower(sentence[i]) + otp[i] - 97) % 26 + 97);
        else
            result += sentence[i];
    }

    return result;
}

int main() {
    string plaintext = "this is secret";
	
    const int *key = generateKey(plaintext.length());
    string encrypted = encrypt(plaintext, key);
	
    cout << "\nPlain text: " << plaintext << endl << "Encrypted text: " << encrypted << endl;
    cout << "Key: ";
    showKey(key, plaintext.length());

    return 0;
}