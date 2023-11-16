# QR Scanner

## AR Object Identification Team (S24-18)
- Andrew Salzmann
- Tad DiDio
- Liam Bushway
- Samuel Park
- Varin Nakka

### Description
The purpose of this project is to determine the QR code scanning capabilities of live camera feed and static images.

This project determines the libraries needed for the capability to scan QR codes on the Magic Leap 2 AR headset.

### External Libraries
- OpenCV
- ZBar

Please install the listed libraries before building the project

### Build Instructions
CMake is used for building the project and should be installed prior. These instructions are based on UNIX systems.

Navigate to the root directory of the project and create a build folder and cd into it.

```
mkdir build
cd build
```

Next, enter the build folder and run the proper CMake commands

```
cmake ..
make
```

The project should be built and ready to be used in the 'bin' folder located in the root directory.

### Usage
Navigate to the bin folder from the root directory of the project.

```
cd bin
```

There are three possible arguments that the program recognizes:
 - (-h) is to show how to use the program.
 - (-i) sets the program to image mode. After the (-i), the user must provide an image path.
 - (-v) sets the program to video mode. A live video feed will be opened and will actively search for QR codes.

 Run the program using this command:

 ```
 ./QRScanner <input_arg> <optional_image_path>
 ```