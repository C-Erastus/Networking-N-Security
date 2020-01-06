from socket import *
import sys
import os.path
from os import path
# *******************************  HTTP SERVER **************************************
port = int(sys.argv[1])

serverSocket = socket(AF_INET, SOCK_STREAM) # create the server socket 
serverSocket.bind(('', port)) # Assign a port number to the application
serverSocket.listen(1)

print("The server is listening")
while True:
	connectionServer, add = serverSocket.accept() # create a socket for the incoming request 
	msg = connectionServer.recv(1024).decode() # decode the message
	print("The Client Message: {}".format(msg))

	#***********parse message*****	
	msg = msg.split() # Parse the message from the client 
	method = msg[0]
	html = msg[1] # get the html doc sent my the client 

	if method == 'GET': 

	# sending a html dock to the client
		if path.exists(html): # checks if the html doc exists
			print("************The file exists*************")
			index = """<!DOCTYPE html>
			 <html>
			 	 <head>
			 	 	<meta charset="UTF-8">
			 	 	<title>myTest</title>
			 	 </head>

			 	 <body>
			 	     <h1>Test page</h1>
			 	 </body>cd
	        </body>"""
	
			response = "HTTP/1.0 200 OK" + index
			connectionServer.send(response.encode())

		else:
			response = "HTTP/1.0 404 Not Found"
			connectionServer.send(response.encode())

	if method == 'PUT':
		
		print("PUT")
		test = msg[1] # safe the file as test.txt
		response = "HTTP/1.0 200 OK"
		connectionServer.send(response.encode())

	connectionServer.close() # close the connection for the connection 