#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>


void print_mac_address(char * interface_name){

    struct ifreq ifr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    strncpy(ifr.ifr_name, interface_name, IFNAMSIZ);
    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1) {
        perror("Error getting MAC address");
        close(sockfd);
        exit(1);
    }

    


    
    unsigned char *mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);


    // Get IP address
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("Error getting IP address");
        close(sockfd);
        exit(1);
    }
    
    // Get IP address from ifr
    struct sockaddr_in *ipaddr = (struct sockaddr_in *)&ifr.ifr_addr;
    printf("IP address: %s\n", inet_ntoa(ipaddr->sin_addr));

    close(sockfd);

}

int main() {
    char interface_name[] = "eth0";  // Replace with the actual interface name (e.g., eth0, wlan0)
    print_mac_address(interface_name);

    // Continue with the next steps (MD5 hash, ID, and port)


    // int port = 12345;  // Replace with your desired port

    // int sockfd, new_sock;
    // struct sockaddr_in server_addr, client_addr;
    // socklen_t addr_size;

    // sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // if (sockfd == -1) {
    //     perror("Error creating socket");
    //     return 1;
    // }

    // server_addr.sin_family = AF_INET;
    // server_addr.sin_port = htons(port);
    // server_addr.sin_addr.s_addr = INADDR_ANY;
    // memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

    // if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    //     perror("Error binding");
    //     close(sockfd);
    //     return 1;
    // }

    // listen(sockfd, 10);
    // printf("Listening on port %d...\n", port);

    // addr_size = sizeof(client_addr);
    // new_sock = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
    // if (new_sock == -1) {
    //     perror("Error accepting connection");
    //     close(sockfd);
    //     return 1;
    // }

    // printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // // Handle client communication here (send/receive data)
    // // ...

    // close(new_sock);
    // close(sockfd);
    return 0;
}
