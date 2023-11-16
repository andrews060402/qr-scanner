#ifndef QR_SCANNER_HPP
#define QR_SCANNER_HPP

#include <zbar.h>
#include <unordered_set>
#include <string>

class QRScanner {

public:

    QRScanner();

    int imgScan(char* imgPath);

    int videoScan();

    ~QRScanner();

private:

    zbar::ImageScanner scanner;
    std::unordered_set<std::string> qrCodes;

};

#endif