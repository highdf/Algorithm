import socket

servername = "luky"
serverPort = 12000

clientSocket = socket.socket(AF_INET, SOCK_DGRAM)

message = input("Input lowercase sentence:")

clientSocket.sendto(cli
