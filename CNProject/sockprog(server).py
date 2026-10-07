import socket

sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

sock.bind(('10.0.0.1',9053))
dns_records = {
    "example.com": "93.184.216.34",
    "google.com": "142.250.190.46",
    "fedora.org": "8.43.85.67"
}

print("Our Mini server is listening on 10.0.0.1:9053.....")

while True:
    data,addr = sock.recvfrom(1024)
    domain_requested = data.decode().strip()
    if domain_requested in dns_records:
        answer = dns_records[domain_requested]
    else:
        answer = "Error: Domain not found"
    sock.sendto(answer.encode(),addr)
