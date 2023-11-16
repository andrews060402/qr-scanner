#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <zbar.h>
#include <unordered_set>
#include <string>

#include "QRScanner.hpp"

using namespace std;
using namespace cv;
using namespace zbar;

QRScanner::QRScanner() {
    // Initialize ZBar scanner
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 0);
    scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);
}

int QRScanner::imgScan(char* imgPath) {

    // Read the image
    Mat image = imread(imgPath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Could not read the image" << endl;
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
        cout << "No QR codes found in the image" << endl;
    }

    return 0;

}

int QRScanner::videoScan() {
    
    // Get the default camera
    VideoCapture camera(0);

    // Check if camera is valid and operational
    if (!camera.isOpened()) {
        cerr << "Error: Could not open camera" << endl;
        return -1;
    }

    // Loop to use camera
    while (true) {

        // Read a frame from the camera
        Mat frame;
        camera >> frame;

        // Convert frame to grayscale
        Mat grayFrame;
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

        // Convert to ZBar image
        Image zbarImg(frame.cols, frame.rows, "Y800", grayFrame.data, frame.cols * frame.rows);

        // Scan zbar image for QR codes
        scanner.scan(zbarImg);

        // Iterate through detected QR codes
        for (Image::SymbolIterator symbol = zbarImg.symbol_begin(); symbol != zbarImg.symbol_end(); ++symbol) {
            
            // If the QR code is not in the set, print its contents and add it to the set
            if (qrCodes.find(symbol->get_data()) == qrCodes.end()) {
                
                // Print the QR code data
                cout << "QR Code Data: " << symbol->get_data() << endl;

                // Add code to set
                qrCodes.insert(symbol->get_data());
            }
        }

        // Check if the frame is empty (end of video stream)
        if (frame.empty()) {
            cerr << "Error: Could not read frame" << endl;
            break;
        }

        // Show the frame
        imshow("Camera Feed", frame);

        // Exit loop if escape key is pressed
        if (waitKey(1) == 27) {
            break;
        }
    }

    // Release the camera capture object
    camera.release();

    // Close all OpenCV windows
    destroyAllWindows();

    return 0;
}

QRScanner::~QRScanner() {}
