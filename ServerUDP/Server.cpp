//
// Created by Gustavo Brunetto on 23/04/18.
//

#include "Server.h"

Server::Server()
{
    /** 1. Create a Socket
     *
     * socket(domain,type, protocol)
     *
     * All the parameters as well the returning value are integers.
     * @domain (or address family): communication domain in which the socket
     *                               should be created. Some of address families
     *                               AF_INET (IP), AF_INET6(IPv6), AF_UNIX (local,
     *                               channel, similar to pipes), AF_ISO (ISO protocols),
     *                               and AF_NX (Xerox Network Systems protocols).
     * @type                      : type of service. This is selected according to the
     *                               properties required by the application:
     *                               SOCK_STREAM (virtual circuit service)
     *                               SOCK_DGRAM (datagram service)
     *                               SOCK_RAW (direct IP service)
     * @protocol                  : indicate a specific protocol to use in supporting
     *                               the sockets operation. This is useful in cases
     *                               where the family have more than one protocol
     *
     * @return                    : positive integer
     *
     * For UDP/IP sockets, we want to specify the IP address family (AF_INET) and datagram
     * service (SOCK_DGRAM).
     *
     **/
    std::cout << "Creating the socket... ";
    ser_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (ser_fd < 0)
        throw std::invalid_argument("Error opening datagram socket");

    std::cout << "OK" << std::endl;

    /** 2. Identify (name) a socket
     *
     * Name a socket is assining a transport address to the socket (a port number in IP
     * networking). In sockets, this operation is called binding an address.
     *
     * Instead of accepting a port number as a parameters, it takes a sockaddr structur
     * whose actual format is determined on the address family (type of network).
     *
     * bind(int socket, const struct sockaddr *address, socklen_t address_len)
     *
     * @socket      : is the socket created in the socket system call (step 1)
     * @sockaddr    : generic container that contains information read by the OS that identify
     *                 the address family.
     * @sockaddr_in : specifies the length of the address structure. This is simply the size
     *                 of the internet address structure.
     * @return      : positive integer if the binding was done successfully.
     *
     *
     * Before call bind, it is necessary to fill the structure sockaddr_in. The three key parts
     * we need to set are sin_family, sin_port and sin_addr.
     *
     * - sin_family: is the address family we used when we set up the socket (AF_INET)
     * - sin_port  : the port number
     * - sin_addr  : the address for this socket. This is just the machine's IP. Most of the time,
     *               we don't care to specify a specific interface and can let the operating system
     *               use whatever it wants. The special address for this is 0.0.0.0, defined by the
     *               symbolic constant INADDR_ANY.
     *
     **/
    memset((char *) &ser_addr, 0, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ser_addr.sin_port = htons(SERVICE_PORT);
    std::cout << "Binding the socket...";
    if (bind(ser_fd, (struct sockaddr *) &ser_addr, sizeof(ser_addr)) < 0)
        throw std::invalid_argument("binding datagram socket failed");

    std::cout << "OK" << std::endl;

    // Listening for connection
    std::cout << "Listening for incoming connections...";
    if (listen(ser_fd, 3) < 0)
    {
        perror("listening");
        exit(2);
    }


    // accept the connection
    cli_fd = accept(ser_fd, (struct sockaddr *) &rem_addr, &rem_len);
    if (cli_fd < 0)
    {
        perror("accept");
        exit(2);
    }

    std::cout << "OK" << std::endl;

    /** 3. Receive messages
     *
     * With TCP sockets, a server would set up a socket for listening via
     * **listen** system call and then call accept to wait for a connection.
     * UDP is connectionless. A server can immediately listen for messages
     * once it has a socket.  We use recvfrom system call to wait for an
     * incoming datagram on a specific transport address (IP address and
     * port number).
     *
     * recvfrom => int recvfrom(int socket, void *restrict buffer, size_t length,
     *                          int flags, struct sockaddr *restrict src_addr,
                                socklen_t *restrict *src_len)
     *
     * @socket   : socket that we created ahead of time (and use bind). The port number
     *             assigned to that socket via the bind call tells us on what port
     *             recvfrom will wait for data.
     * @buffer   : The incoming data will be placed into the memory at buffer and no
     *             more that length bytes will be transferred (that's the size of
     *             your buffer).
     * @flags    : This parameter allows us to process out-of-band data, peek at
     *             an incoming message without removing it from the queue, or block
     *             until the request is fully satisfied. We can safely ignore these
     *             and use 0.
     * @src_addr : is a pointer to a sockaddr structure that you allocate and will
     *             be filled in by recvfrom to identify the sender of the message.
     * @src_len  : The length of this structure will be stored in src_len. If you
     *             do not care to identify the sender, you can set both of these
     *             to zero but you will then have no way to reply to the sender.
     *
     * @return   :  the number of bytes that were read into buffer
     *
     */
    int tmp = 0;
    CityConnections cityConnections;
    std::vector<std::string> cities = cityConnections.getCitiesName();
    char cityList[BUFSIZE] = "";
    std::string list;
    for (auto &city : cities)
        list += city + ";";
    list += "\n";

    strncpy(cityList, list.c_str(), strlen(list.c_str()));

    printf("Waiting on port %d\n", ntohs(ser_addr.sin_port));

    printf("Sending city list...");
    if (write(cli_fd, cityList, sizeof(cityList)) < 0)
    {
        perror("Sending city list");
        exit(2);
    }
    printf("OK\n");

    for(;;)
    {
//         recvlen = recvfrom(ser_fd, buf, BUFSIZE, 0, (struct sockaddr *)&rem_addr, &rem_len);
         recvlen = (int) read(cli_fd, buf, BUFSIZE);
         if (recvlen > 0)
         {
             buf[recvlen] = 0;
             printf("received message: \"%s\" (%d bytes)", buf, recvlen);
             tmp++;
             if (strncmp(buf, "FIM", BUFSIZE) == 0)
                 break;
         }
         else
         {
             printf("uh oh - something went wrong!\n");
             std::cout << "Closing connection...";
             close(ser_fd);
             exit(1);
         }


         // send message back to client
//         sprintf(buf, "ack %d", msgcnt++);
//         printf("sending response ""\"%s\"\n", buf);
//         if (sendto(ser_fd, buf, strlen(buf), 0, (struct sockaddr *)&rem_addr, rem_len) < 0)
//             perror("sendto");
//         printf("message count = %d\n", tmp);
     }

     std::cout << "Closing connection...";
     close(ser_fd);
     std::cout << "OK" << std::endl;

}