from socket import * # for the user of sockets
import sys # for the user of arv[]
#***************************************** GET METHOD ******************************************
def getMethod( clientSocket,  serverName, port, path):
	request = "GET " + path + " HTTP/1.0\r\nhost:"+ serverName +"\r\n\r\n" # this is to get the request page 
	request = str.encode(request)
	clientSocket.send(request)
	# ( end with extra CR/LF)

	while True: # edit this loop later
		response = clientSocket.recv(1024)
		response = response.decode()
		response = repr(response)
		print("{}".format(response)) #response.decode()
		break
	clientSocket.close()

#******************************************** PUT METHOD ***********************************
def putMethod( clientSocket, serverName, port, path):

	request = "PUT "+ path + " HTTP/1.0\r\nhost:" + serverName + "\r\n\r\n"
	request = str.encode(request) # encode the request into bytes
	clientSocket.send(request) # send the request to the server

	# print the request. 
	while True: # edit this loop later
		response = clientSocket.recv(1024)
		response = response.decode()
		response = repr(response)
		print("{}".format(response))
		break
		
	clientSocket.close() # close the connection 
	
def main():
		# get the 4 arguments line
	serverName = sys.argv[1]
	port = int(sys.argv[2])
	method = sys.argv[3] # the method is either GET or PUT
	path = sys.argv[4]

	#1.Connect to the server via a connection-oriented socket. (TCP)
	clientSocket = socket(AF_INET, SOCK_STREAM) # create the client socket 
	clientSocket.connect((serverName, port)) # connect to the server useing the server address (IP and Port)

	if method == "GET":
		getMethod( clientSocket, serverName, port, path) # function to implement GET method

	if method == 'PUT':
		putMethod( clientSocket, serverName, port, path) # function to implement PUT method 

	clientSocket.close()
#************************* MAIN METHOD STARTS HERE ************************
if __name__ == '__main__':
	main()