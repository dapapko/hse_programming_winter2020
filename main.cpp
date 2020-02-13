#include <iostream>
using namespace std;
#include <bitset>
const int initial_mask = 0x0ff;

void octal_dump(int value, int radix) {
   if(value < 0) {
        cout << "3";
    }
    int mask = 07000000000;
    int base_shift = 3;
    int correction_shift = 27;
    if(radix == 16) {
        correction_shift = 12;
        value = value & 0xffff;
        mask = 0x7000;
    } else  if (radix == 8) {
        correction_shift = 6;
        value = value & 0xff;
        mask = 0700;
    }
    for(int j=0; j < radix / base_shift; j++) {
        int digit = value & mask;
        digit >>= correction_shift;
        cout << char(digit + 48);
        mask >>= base_shift;
        correction_shift -= base_shift;
    }
}

void hex_dump(int value, int radix) {
    //cout << "Bitset: " << bitset<32>(value) << endl;
    int mask, correction_shift;
    int base_shift = 4;
    if(value < 0) {cout << "F";}
    if (radix == 32) {
        mask = 0x78000000 >> 3;
        correction_shift = 24;
    } else if(radix == 16) {
        correction_shift = 8;
        value = value & 0x7fff;
        mask = 0xf00;
      //  cout << "Value: "<< bitset<16>(value) << endl;
    } else {
        correction_shift = 4;
       // cout << "Value: "<< bitset<16>(value) << endl;
        value = value & 0xff;
        mask = 0360;
       // cout << "Value: "<< bitset<16>(value) << endl;
    }
   // cout << "Mask: "<< bitset<16>(mask) << endl;
    int upperbound;
    radix == 8 ? upperbound = 2 : upperbound = radix / base_shift -1;
    for(int j=0; j < upperbound; j++) {
        int digit = value & mask;
       // cout << "Digit: "<< bitset<32>(digit) << endl;
        digit >>= correction_shift;
      // cout << "Shifted digit: "<< bitset<32>(digit) << endl;
      // cout << "Mask: "<< bitset<16>(mask) << endl;
        if (digit > 9) {
            cout << char(digit + 55);
        } else {
            cout << char(digit + 48);
        }
        mask >>= base_shift;
        correction_shift -= base_shift;
    }
}

int main() {
    int a = -239;
    cout << oct << a << endl;
    octal_dump(a, 16);
    return 0;
}