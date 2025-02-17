import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ("0.0.0.0", 12345)
server_socket.bind(server_address)
print("Server is launch")

try:
    while True:
        message, client_address = server_socket.recvfrom(1024)
        print(f"Client {client_address} send {message.decode()}")

        response = "Message received"
        server_socket.sendto(response.encode(), client_address)
except KeyboardInterrupt:
    print("server is close")
finally:
    server_socket.close()
