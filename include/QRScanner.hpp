#ifndef QR_SCANNER_HPP
#define QR_SCANNER_HPP

#include <zbar.h>

class QRScanner {

public:

    QRScanner();

    int imgScan(char* imgPath);

    void videoScan();

    ~QRScanner();

private:

    zbar::ImageScanner scanner;

};

#endif