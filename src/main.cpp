#include "QRScanner.hpp"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <image_path>" << endl;
        return -1;
    }

    QRScanner qrScanner = QRScanner();

   return  qrScanner.imgScan(argv[1]);
}