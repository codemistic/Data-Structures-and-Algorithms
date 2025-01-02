import socket as s 
#get the host name 
my_host = s.gethostname()

print('your name is' + my_host)
#get the IP address 
my_ip = s.gethostbyname(my_host)

print('Your IP address is: ' + my_ip)

#Enter your own email 
host = "yourname.com"

ip = s.gethostbyname(host)

print ('The IP address of ' + host + 'is' + ip)



