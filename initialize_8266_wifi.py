import serial
import time

port = serial.Serial("/dev/ttyUSB0", baudrate=115200, timeout=3.0)
def readlineCR(port):
    rv = ""
    rv = port.read(5096)
    return rv


isConnected=True;
while isConnected:
    port.write(b'AT\r\n')
    returnedData=readlineCR(port)
    print(returnedData)
    if (b'OK') not in returnedData :
       print("Module not connected.  Reconnect and try again.")
       time.sleep(60)
    else :
        print("Device Connected.")
        isConnected=False

    port.write(b'AT+CWMODE=1\r\n')
    returnedData=readlineCR(port)
    print(returnedData)
    if (b'OK') not in returnedData :
        print("Unable to config client")
    else :
        print("Configd as STA")

    port.write(b'AT+CWJAP=\"YOUR WIFI SSID\",\"YOUR WIFI PASS\"\r\n')
    returnedData=readlineCR(port)
    print(returnedData)
    if (b'OK') not in returnedData :
        print("wifi not connected")
    else :
        print("Wifi Connected")

    port.write(b'AT+AUTOCONN=1\r\n')
    returnedData=readlineCR(port)
    print(returnedData)


port.write(b'AT+CIPCLOSE\r\n')
returnedData=readlineCR(port)
if (b'OK') not in returnedData :
    print("failed to close connection")
else :
    print("TCP Connetion Closed")