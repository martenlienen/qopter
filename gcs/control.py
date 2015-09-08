import bluetooth
import IPython

PORT = 0x1001
sock = bluetooth.BluetoothSocket()
sock.bind(("", PORT))
sock.listen(1)

print("Listening on {}".format(PORT))

clientsock, address = sock.accept()

print("Connection from {}".format(address))

IPython.embed()
