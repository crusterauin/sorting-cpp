#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapWords(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

void selectionSortKecilBesar(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapNumbers(arr[i], arr[minIndex]);
        }
    }
}

void selectionSortBesarKecil(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swapNumbers(arr[i], arr[maxIndex]);
        }
    }
}

void selectionSortAZ(vector<string>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swapWords(arr[i], arr[minIndex]);
        }
    }
}

void selectionSortZA(vector<string>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swapWords(arr[i], arr[maxIndex]);
        }
    }
}

void inputAngka(vector<int>& arr) {
    cout << "Masukkan beberapa angka yang akan diurutkan. Pisahkan dengan spasi. \nJika sudah selesai, masukkan tanda titik (.) dan tekan enter.\n";

    int inputAngka;
    while (cin >> inputAngka) {
        arr.push_back(inputAngka);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputKata(vector<string>& arr) {
    cout << "Masukkan beberapa kata yang akan diurutkan. Pisahkan dengan spasi. \nJika sudah selesai, masukkan tanda titik (.) dan tekan enter.\n";

    string inputKata;
    while (cin >> inputKata && inputKata != ".") {
    	for(size_t i = 0; i < inputKata.size(); ++i){
    		inputKata[i] = tolower(inputKata[i]);
		}
        arr.push_back(inputKata);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<int> numbers;
    vector<string> words;
    int pilihTipe;
    int pilihMetodeAngka;
    int pilihMetodeKata;
    char ulangiProgram;

	do {
	numbers.clear();
    words.clear();
	pilihTipe = 0;
	pilihMetodeAngka = 0;
	pilihMetodeKata = 0;
	ulangiProgram = ' ';	
	cout << "Selamat datang di program sorting!\nMau sorting apa? (1/2)\n";
    cout << "1. Angka\n";
    cout << "2. Kata\n";
    cin >> pilihTipe;

    switch (pilihTipe) {
        case 1:
            cout << "Pilih metode sorting:\n";
            cout << "1. Terbesar ke Terkecil\n";
            cout << "2. Terkecil ke Terbesar\n";
            cin >> pilihMetodeAngka;
            break;
        case 2:
            cout << "Pilih metode sorting:\n";
            cout << "1. A-Z\n";
            cout << "2. Z-A\n";
            cin >> pilihMetodeKata;
            break;
    }

    switch (pilihMetodeAngka) {
        case 1:
            inputAngka(numbers);
            selectionSortBesarKecil(numbers);
            cout << "Anda telah memasukkan sebanyak " << numbers.size() << " angka.";
            cout << "\nVector setelah diurutkan (dari terbesar ke terkecil):\n";
            for (size_t i = 0; i < numbers.size(); ++i) {
                cout << numbers[i] << "\n";
            }
            break;
        case 2:
            inputAngka(numbers);
            selectionSortKecilBesar(numbers);
            cout << "Anda telah memasukkan sebanyak " << numbers.size() << " angka.";
            cout << "\nVector setelah diurutkan (dari terkecil ke terbesar):\n";
            for (size_t i = 0; i < numbers.size(); ++i) {
                cout << numbers[i] << "\n";
            }
            break;
    }

    switch (pilihMetodeKata) {
        case 1:
            inputKata(words);
            selectionSortAZ(words);
            cout << "Anda telah memasukkan sebanyak " << words.size() << " kata.";
            cout << "Kata-kata setelah diurutkan:\n";
            for (size_t i = 0; i < words.size(); ++i) {
                cout << words[i] << "\n";
            }
            break;
        case 2:
            inputKata(words);
            selectionSortZA(words);
            cout << "Anda telah memasukkan sebanyak " << words.size() << " kata.";
            cout << "Kata-kata setelah diurutkan:\n";
            for (size_t i = 0; i < words.size(); ++i) {
                cout << words[i] << "\n";
            }
            break;
    	}
    cout << "Apakah Anda ingin mengulangi program? (y/n): ";
    cin >> ulangiProgram;
	} while (ulangiProgram == 'Y' || ulangiProgram == 'y');
	
    
    return 0;
}
