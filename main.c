//CopyRight : HATAM:)
//Date Uploaded to QUERA : 2019/ 12/ 29
//Got Help from GeeksForGeeks, StackOverflow, M.Mofayezi(:/), spacesciencesoftware.wordpress.com,& Special Thanks to Shirin Baghoulizadeh My Perfect Teacher..., Baghal sar koocheh be khater energy Bastani hash !,ham otaghi khoobam braye chii hash va tamam azizani ke mara hamrahi kardand...


#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "Client.c"
#include "HATA_JSON.h"
#include "HATA_JSON.c"

#define PORT 12345
#define SA struct sockaddr

//Global Variables
int theme = 1;
int client_socket;
struct sockaddr_in servaddr;

int main()
{

    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    int flag_account;
//Making Socket Operation-----------------------------------------------------------------------
	// Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h----------------
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        // Tell the user that we could not find a usable Winsock DLL.----------------
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    //Making socket------------------------------------------------------------------
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		return 0;
	}

	else printf("Socket successfully created...\n");
	Sleep(800);
    system("cls");
    // Assign IP and port---------------------------------------------------
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);
//---------------------------------------------------------------------------------------------
    /* Theme Picker */
    loadtheme();
    //printf("HATA Messenger | Version 2.0.7 ");
    LogoPrint();
    location :
    flag_account = account();
    if(flag_account==1)
    {mainmenu();
    goto location;}
    else if(flag_account==2){
            system("cls");
        CPATT(NORMAL);
        printf("Program Exited Normally\033[1;32m\nBey-Bey");
        RESET;
        Sleep(1200);
        system("cls");
        return 0;

    }
    else{
            printf("Program Crashed :( ");
            return 1;
    }
    return 0;

}
