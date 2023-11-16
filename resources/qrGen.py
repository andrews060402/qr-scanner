import qrcode

def generate_qr_code(text):
    # Create an instance of the QRCode class
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )

    # Add data to the QR code
    qr.add_data(text)
    qr.make(fit=True)

    # Create an image from the QR Code instance
    img = qr.make_image(fill_color="black", back_color="white")

    # Save the image or display it
    img.save("qrcode.png")
    img.show()

if __name__ == "__main__":
    # Get user input for the text
    user_text = input("Enter the text to convert to QR code: ")

    # Generate and display the QR code
    generate_qr_code(user_text)
