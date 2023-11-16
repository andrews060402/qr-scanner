#include "QRScanner.hpp"

#include <iostream>
#include <string>

using namespace std;

void showUsage(char* progName) {
    cout << "Usage: " << progName << " -i <image_path>" << endl;
    cout << "       " << progName << " -v" << endl;
    cout << "       " << progName << " -h" << endl;
}

int main(int argc, char* argv[]) {

    QRScanner qrScanner = QRScanner();

    if (argc == 2 && string(argv[1]) == "-h") {
        showUsage(argv[0]);
        return 0;
    }
    else if (argc == 2 && string(argv[1]) == "-v") {
        return qrScanner.videoScan();
    }
    else if (argc == 3 && string(argv[1]) == "-i") {
        return qrScanner.imgScan(argv[2]);
    }

    showUsage(argv[0]);
    return -1;

}