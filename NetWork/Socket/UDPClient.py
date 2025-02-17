import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ("127.0.0.1", 12345)

try:
    while True:
        message = input("Please enter you want send message: ")
        if message.lower() == "exit":
            break

        client_socket.sendto(message.encode(), server_address)

        client_socket.settimeout(2)
        try:
            responese, _ = client_socket.recvfrom(1024)
            print(f"Get response: {responese.decode()}")
        except socket.timeout:
            print("TimeOut")
except KeyboardInterrupt:
    print("client close")
finally:
    client_socket.close
