import socket

sock  = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

sock.settimeout(2.0)
question = input("Enter the domain name")

sock.sendto(question.encode(),("10.0.0.1",9053))
try:
    data,addr = sock.recvfrom(1024)
    print(f"Server response: {data.decode()}")
except socket.timeout:
    print("Error: the server is either offline or the packet was lost")