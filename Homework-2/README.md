# Assignment 2 - Socket Programming

The objective of this assignment is to practice socket programming by writ-
ing a chat application. The assignment consists of implementing two compo-
nents: a chat client and a chat server. The server maintains information about
the clients that have registered with a specific chat group and dispatches the
messages sent by the clients.
Clients can communicate with others by registering with a group. All re-
ceived messages (from other clients) should be sent to standard output. The
server and clients should be invoked with:
* Sever: server \[server port number\]
* Client: client \[server host name\] \[server port number\] \[client name\]
After successfully contacting the server, the client should support the fol-
lowing commands:
* join [groupID]: registers the client with a group, allowing it to receive
and send messages from/to the specified group.
* send \[groupID\] \[message\]: allows a client to send a message to a group.
* leave \[groupID\]: indicates that a client wants to stop sending and re-
ceiving messages.
* quit: closes the client application.  
When a client joins a group, the server registers the client with the corre-
sponding group. A client can be member of multiple groups simultaneously and
duplicate join requests must be discarded. Similarly, when a client requests to
leave a group, the server removes the client from the corresponding group; if a
client tries to leave a group in which it is not a member, the request must be
discarded. When the server receives a send request message for a group, the
server delivers the message to all members of the group The message format
should be as follows: “ClientName: msg”.  
Hint: You should use select() in the server to perform multiplexing among
the clients (i.e., no busy wait). select() allows a program to monitor multiple
file descriptors (socket descriptor in our case), waiting until one or more of them
become ready.
