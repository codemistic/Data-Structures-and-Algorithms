import wifi_qrcode_generator as qr

def generate_wifi_qr():
    ssid = input("Enter Wi-Fi name (SSID): ")
    security = input("Enter security type (WPA/WPA2/WEP/NONE): ").upper()
    password = "" if security == "NONE" else input("Enter Wi-Fi password: ")

    try:
        wifi_qr = qr.wifi_qrcode(ssid, hidden=False, authentication_type=security, password=password)
        wifi_qr.show()  # Display the QR code
    except Exception as e:
        print(f"Error generating QR code: {e}")

if __name__ == "__main__":
    generate_wifi_qr()
