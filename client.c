

#include <stdio.h>
#include <stdlib.h>


#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>


int main(){

  // create a socket
  int network_socket;
  // AF_INET is an address family that is used to designate the type of addresses that your socket can communicate with (in this case, Internet Protocol v4 addresses)
  // TCP (SOCK_STREAM) is a connection-based protocol. The connection is established and the two parties have a conversation until the connection is terminated by one of the parties or by a network error.
  network_socket = socket(AF_INET, SOCK_STREAM, 0);


  // specify an address for the socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  // htons converts integer port to proper data type
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;



  int connection_status = connect(network_socket, (struct sockaddr * ) &server_address, sizeof(server_address));
  if (connection_status == -1){
    printf("There was an error making a connection to the remote socket.\n");
    // return 0;
  }
  char server_response[256];
  recv(network_socket, &server_response, sizeof(server_address), 0);

  printf("The server sent : %s\n", server_response);
  // close(sock);
  return 0;
}
