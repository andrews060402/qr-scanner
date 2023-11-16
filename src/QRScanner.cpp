#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <zbar.h>
#include "QRScanner.hpp"

using namespace std;
using namespace cv;
using namespace zbar;

QRScanner::QRScanner() {
    // Initialize ZBar scanner
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
}

int QRScanner::imgScan(char* imgPath) {

    // Read the image
    Mat image = imread(imgPath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Could not read the image." << endl;
        return -1;
    }

    // Convert OpenCV image to ZBar image
    Image zbarImage(image.cols, image.rows, "Y800", image.data, image.cols * image.rows);

    // Scan the image for QR codes
    int n = scanner.scan(zbarImage);

    // Print the decoded QR codes
    for (Image::SymbolIterator symbol = zbarImage.symbol_begin(); symbol != zbarImage.symbol_end(); ++symbol) {
        cout << "Decoded QR Code: " << symbol->get_data() << endl;
    }

    if (n == 0) {
        cout << "No QR codes found in the image." << endl;
    }

    return 0;

}

QRScanner::~QRScanner() {
    
}