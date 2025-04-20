#include <iostream>
#include <string>
using namespace std;

// Dinh nghia struct mo ta vi xu ly 8086
struct Microprocessor {
    string name;           // Ten vi xu ly
    float clockSpeed;      // Tan so xung nhap (MHz)
    int MN_MX;             // Chan MN/MX: 0 (Max mode), 1 (Min mode)
};

// Ham thiet lap che do lam viec
void setMode(Microprocessor &mp, bool isMaxMode) {
    if (isMaxMode) {
        mp.MN_MX = 0; // Che do Maximum
        cout << "Da thiet lap che do Maximum (MN/MX = 0)." << endl;
    } else {
        mp.MN_MX = 1; // Che do Minimum
        cout << "Da thiet lap che do Minimum (MN/MX = 1)." << endl;
    }
}

// Ham kiem tra che do lam viec
void checkMode(const Microprocessor &mp) {
    if (mp.MN_MX == 0) {
        cout << "Vi xu ly dang o che do Maximum." << endl;
    } else if (mp.MN_MX == 1) {
        cout << "Vi xu ly dang o che do Minimum." << endl;
    } else {
        cout << "Gia tri MN/MX khong hop le!" << endl;
    }
}

int main() {
    // Khoi tao mot vi-producing 8086
    Microprocessor mp;
    mp.name = "Intel 8086";
    mp.clockSpeed = 5.0; // Tan so 5 MHz (mot trong cac tan so cua 8086)
    mp.MN_MX = 1;        // M?c d?nh là Min mode

    // Hien thi thong tin vi xu ly
    cout << "Vi xu ly: " << mp.name << endl;
    cout << "Tan so xung nhip: " << mp.clockSpeed << " MHz" << endl;

    // Thu thiet lap va kiem tra che do
    setMode(mp, true);   // Thiet lap che do Maximum
    checkMode(mp);       // Ki?m tra ch? d?

    setMode(mp, false);  // Thiet lap che do Minimum
    checkMode(mp);       // Kiem tra che do

    return 0;
}
