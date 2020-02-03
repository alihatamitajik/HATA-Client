//CopyRight : HATAM:)           Now You Can Say This is a CHEAT B****!
//Date Uploaded to QUERA : 2019/ 12/ 29
//Got Help From :

#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "HATA_JSON.h"
/* For Printing UTF-8 */
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#ifndef _O_U16TEXT
  #define _O_U16TEXT 0x20000
#endif

#define PORT 12345
#define SA struct sockaddr
#define INT_MAX 100000

/* COLOR DEFINITIONS */
#define black printf("\033[0;30m")
#define red printf("\033[0;31m")
#define Bred printf("\033[1;31m")
#define green printf("\033[0;32m")
#define Bgreen printf("\033[1;32m")
#define yello printf("\033[0;33m")
#define Byello printf("\033[1;33m")
#define blue printf("\033[0;34m")
#define Bblue printf("\033[1;34m")
#define magneta printf("\033[0;35m")
#define Bmagneta printf("\033[1;35m")
#define cyan printf("\033[0;36m")
#define Bcyan printf("\033[1;36m")
#define RESET printf("\033[0m")
/* BG Color DEFINITIONS */
#define BGblack printf("\033[0;40m")
#define BGred printf("\033[0;41m")
#define BGBred printf("\033[1;41m")
#define BGgreen printf("\033[0;42m")
#define BGBgreen printf("\033[0;42m")
#define BGyello printf("\033[0;43m")
#define BGByello printf("\033[1;43m")
#define BGblue printf("\033[0;44m")
#define BGBblue printf("\033[1;44m")
#define BGmagneta printf("\033[0;45m")
#define BGBmagneta printf("\033[1;45m")
#define BGcyan printf("\033[0;46m")
#define BGBcyan printf("\033[1;46m")
/* Text Type */
#define CHOOSED 1
#define NORMAL 2
#define MENU 3
#define OTHER 4
/* Themes */
#define GOLDEN 1
#define WATERMELON 2
#define OCEAN 3

//Prototypes
int creataccount();

//Global Variables
int theme;
int client_socket;
char token[80];
struct sockaddr_in servaddr;
char username[100];
char chnlname[100];

void loadtheme()
{
    char c;
    FILE *fp = fopen("theme.txt","r");
    c = fgetc(fp);
    theme = (int)c - 48;
    fclose(fp);
    return;
}

void CPATT(int texttype)//ColorPickerAccordingToTheme
{
    if(theme == GOLDEN){
             if(texttype == NORMAL)yello;
        else if(texttype == CHOOSED)Byello;
        else if(texttype == MENU)magneta;
        else if(texttype == OTHER)RESET;
        return;
    }
    else if(theme == WATERMELON){
        if(texttype == NORMAL)green;
        else if(texttype == CHOOSED)Bgreen;
        else if(texttype == MENU)Bred;
        else if(texttype == OTHER)red;
        return;
    }
    else if(theme == OCEAN){
        if(texttype == NORMAL)cyan;
        else if(texttype == CHOOSED)Bcyan;
        else if(texttype == MENU)Bblue;
        else if(texttype == OTHER)yello;
        return;
    }

}

void LogoPrint(){
    _setmode(_fileno(stdout), _O_U16TEXT);
    int x;
    wprintf(L"%s\n", L"    ╔╗─╔╦═══╦════╦═══╦═╗╔═╗\n"
                      "    ║║─║║╔═╗║╔╗╔╗║╔═╗║║╚╝║║\n"
                      "    ║╚═╝║║─║╠╝║║╚╣║─║║╔╗╔╗╠══╦══╦══╦══╦═╗╔══╦══╦═╗\n"
                      "    ║╔═╗║╚═╝║─║║─║╚═╝║║║║║║║═╣══╣══╣║═╣╔╗╣╔╗║║═╣╔╝\n"
                      "    ║║─║║╔═╗║─║║─║╔═╗║║║║║║║═╬══╠══║║═╣║║║╚╝║║═╣║\n"
                      "    ╚╝─╚╩╝─╚╝─╚╝─╚╝─╚╩╝╚╝╚╩══╩══╩══╩══╩╝╚╩═╗╠══╩╝\n"
                      "Version 2.0.7────────────────────────────╔═╝║\n"
                      "Copyright © HTC 2021 All Rights Reserved─╚══╝\n");
    Sleep(500);
    scanf("%d",&x);
    system("cls");
    wprintf(L"%s\n",   L"    ╔╗─╔╦═══╦════╦═══╦═╗╔═╗\n"
                        "    ║║─║║╔═╗║╔╗╔╗║╔═╗║║╚╝║║\n"
                        "    ║╚═╝║║─║╠╝║║╚╣║─║║╔╗╔╗╠══╦══╦══╦══╦═╗╔══╦══╦═╗\n"
                        "    ║╔═╗║╚═╝║─║║─║╚═╝║║║║║║║═╣══╣══╣║═╣╔╗╣╔╗║║═╣╔╝\n"
                        "    ║║─║║╔═╗║─║║─║╔═╗║║║║║║║═╬══╠══║║═╣║║║╚╝║║═╣║ \033[0;31m╔╗\033[0m\n"
                        "    ╚╝─╚╩╝─╚╝─╚╝─╚╝─╚╩╝╚╝╚╩══╩══╩══╩══╩╝╚╩═╗╠══╩╝ \033[0;31m╚╝\033[0m\n"
                        "Version 2.0.7────────────────────────────╔═╝║\n"
                        "Copyright © HTC 2021 All Rights Reserved─╚══╝\n");

    Sleep(500);
    system("cls");
    wprintf(L"%s\n",   L"    ╔╗─╔╦═══╦════╦═══╦═╗╔═╗\n"
                        "    ║║─║║╔═╗║╔╗╔╗║╔═╗║║╚╝║║\n"
                        "    ║╚═╝║║─║╠╝║║╚╣║─║║╔╗╔╗╠══╦══╦══╦══╦═╗╔══╦══╦═╗\n"
                        "    ║╔═╗║╚═╝║─║║─║╚═╝║║║║║║║═╣══╣══╣║═╣╔╗╣╔╗║║═╣╔╝\n"
                        "    ║║─║║╔═╗║─║║─║╔═╗║║║║║║║═╬══╠══║║═╣║║║╚╝║║═╣║ \033[0;31m╔╗\033[0;32m╔╗\033[0m\n"
                        "    ╚╝─╚╩╝─╚╝─╚╝─╚╝─╚╩╝╚╝╚╩══╩══╩══╩══╩╝╚╩═╗╠══╩╝ \033[0;31m╚╝\033[0;32m╚╝\033[0m\n"
                        "Version 2.0.7────────────────────────────╔═╝║\n"
                        "Copyright © HTC 2021 All Rights Reserved─╚══╝\n");
    Sleep(500);
    system("cls");
    wprintf(L"%s\n",   L"    ╔╗─╔╦═══╦════╦═══╦═╗╔═╗\n"
                        "    ║║─║║╔═╗║╔╗╔╗║╔═╗║║╚╝║║\n"
                        "    ║╚═╝║║─║╠╝║║╚╣║─║║╔╗╔╗╠══╦══╦══╦══╦═╗╔══╦══╦═╗\n"
                        "    ║╔═╗║╚═╝║─║║─║╚═╝║║║║║║║═╣══╣══╣║═╣╔╗╣╔╗║║═╣╔╝\n"
                        "    ║║─║║╔═╗║─║║─║╔═╗║║║║║║║═╬══╠══║║═╣║║║╚╝║║═╣║ \033[0;31m╔╗\033[0;32m╔╗\033[0;34m╔╗\033[0m\n"
                        "    ╚╝─╚╩╝─╚╝─╚╝─╚╝─╚╩╝╚╝╚╩══╩══╩══╩══╩╝╚╩═╗╠══╩╝ \033[0;31m╚╝\033[0;32m╚╝\033[0;34m╚╝\033[0m\n"
                        "Version 2.0.7────────────────────────────╔═╝║\n"
                        "Copyright © HTC 2021 All Rights Reserved─╚══╝\n" );
    Sleep(1500);
    system("cls");
    _setmode(_fileno(stdout), 0x4000);
    return ;
}

//Account Menu=================================================================================================================================================================================================
//=============================================================================================================================================================================================================

//prototypes
int login();
void accountmenuprinter(int selected)
{
    system("cls");
    CPATT(MENU);
    printf("Account Menu\n\n");
    CPATT(OTHER);
    printf("Login into your Account\n");
    if(selected==1){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("1: Login\n\n");
    CPATT(OTHER);
    printf("Don't You Have HATA Account Yet?!\nHarry Up,Create One NOW!\n");

    if(selected==2){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("2: Create A New Account\n\n");

    if(selected==3){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("3: Exit Application\n");
}

int account(){
    int option=1,flag=0,ch1,ch2;
    while(TRUE){
        accountmenuprinter(option);
        ch1 = getch();
        /* If a controlling key pressed */
        if(ch1 == 0xE0){
            ch2 = getch();
            /* If Up was pressed*/
            if(ch2==72){
                if(option>1)option--;
            }
            /* If Down was presses */
            else if(ch2==80){
                if(option<3)option++;
            }
       }
       else if(ch1==13){
            if(option==1){
                system("cls");
                RESET;
                flag = login();
                if(flag==1)return 1;
            }
            else if(option==2){
                system("cls");
                RESET;
                flag = creataccount();
            }
            else if(option==3){
                RESET;
                return 2;
            }
       }
    }
    return 0;
}


//LOGIN========================================================================================================================================================================================================
int login(){
    char buffer[1024],lgnstr[80];
    int flag=0;
    int counter=0,ch1;
    char *user = username;
    char *pass = (char *)malloc(40);
    memset(pass,0,40);
    CPATT(MENU);
    printf("Enter your UserName : ");
    RESET;
    scanf("%s",username);
    CPATT(CHOOSED);
    printf("Enter your PassWord : ");
    RESET;
    while(TRUE){
        ch1 = getch();
        if(ch1==13)break;
        else{
            pass[counter]=(char)ch1;
            counter++;
            printf("*");
        }
    }
    RESET;

    //Combining Strings-----------------------------------------------------
    strcpy(lgnstr,"login ");
    strcat(lgnstr,user);
    strcat(lgnstr,", ");
    strcat(lgnstr,pass);
    strcat(lgnstr,"\n");
    free(pass);
    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		return 0;
	}
	Sleep(300);
    system("cls");

	// Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

    // Sending User/Pass
	send(client_socket,lgnstr, sizeof(lgnstr), 0);

    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);
    //Parsing Received Message----------------------------------------------
    JSON *root1 = ParseJSON(buffer);
    char *msgtype1 = GetObjectItemJSON(root1,"type")->valuestring;
    char *msgcontent1 = GetObjectItemJSON(root1,"content")->valuestring;
    if(!strcmp(msgtype1,"Error")){
        system("cls");
        printf("Error : %s",msgcontent1);
        Sleep(2000);
        system("cls");
        flag = 0;
        }
    else{
        strcpy(token,msgcontent1);
        flag = 1;
        system("cls");
        printf("You Are Logged in %s",user);
        Sleep(900);
        system("cls");
    }
    DeleteJSON(root1);
    free(msgtype1);
    free(msgcontent1);
    return flag;

}




//CREAT ACCOUNT================================================================================================================================================================================================
int creataccount(){

    char buffer[1024],rgstr[80];

    int flag,counter=0,ch1;

    //----------------------------------------------------------------------

    char *user = (char *)malloc(64);
    char *pass = (char *)malloc(40);
    memset(user,0,60);
    memset(pass,0,40);
    CPATT(CHOOSED);
    printf("Choose a UserName : ");
    RESET;
    scanf("%s",user);
    CPATT(MENU);
    printf("Choose your PassWord : ");
    RESET;
    while(TRUE){
        ch1 = getch();
        if(ch1==13)break;
        else{
            pass[counter]=(char)ch1;
            counter++;
            printf("*");
        }
    }
    RESET;
    //Combining Strings-----------------------------------------------------
    strcpy(rgstr,"register ");
    strcat(rgstr,user);
    strcat(rgstr,", ");
    strcat(rgstr,pass);
    strcat(rgstr,"\n");

    free(user);free(pass);
    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		return 0;
	}

	else printf("Socket successfully created...\n");
	Sleep(800);
    system("cls");



    // Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

    //Send The Register Message---------------------------------------------
    send(client_socket,rgstr, sizeof(rgstr), 0);

    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);

    //Parsing Received Message----------------------------------------------
    JSON *root = ParseJSON(buffer);
    char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
    char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
        flag = 0;
    }else{
        system("cls");
        flag = 1;
        printf("Your Account Successfully Created\n"
               "Now Login into your HATA Account");
        Sleep(2500);
        system("cls");
    }
    free(msgtype);
    free(msgcontent);
    DeleteJSON(root);
    return flag;
}
//============================================================================================================================================================================================================

//MainMenu====================================================================================================================================================================================================
//============================================================================================================================================================================================================

//Prototypes
int createchanel();
int joinchanel();
int chatmenu();
int logout();
void PickTheme();

void mainmenuprinter(int selected)
{
    system("cls");
    CPATT(MENU);
    printf("\"Main Menu\"\n\n");
    if(selected==1){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("1: Create a Channel\n");
    if(selected==2){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf( "2: Join a Channel\n");
    if(selected==3){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);;
    printf( "3: Change Theme\n");
    if(selected==4){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf( "4: LogOut\n\n");
}

int mainmenu(){
    int option=1,flag=0,ch1,ch2;
    while(TRUE){
        mainmenuprinter(option);
        ch1 = getch();
        /* If a controlling key pressed */
        if(ch1 == 0xE0){
            ch2 = getch();
            /* If Up was pressed*/
            if(ch2==72){
                if(option>1)option--;
            }
            /* If Down was presses */
            else if(ch2==80){
                if(option<4)option++;
            }
       }
       else if(ch1 == 13){
            if(option == 1){
                flag = createchanel();
                if(flag==1){
                    flag = chatmenu();
                    system("cls");
                }
                else{
                    red;
                    printf("Failed Operation!");
                    Sleep(600);
                }
                RESET;
            }
            else if(option==2){
                flag =joinchanel();
                if(flag==1){
                    flag = chatmenu();
                    system("cls");
                }
                else{
                    red;
                    printf("Failed Operation!");
                    Sleep(600);
                }
                RESET;
            }
            else if(option==4){
                flag = logout();
                if(flag==1){
                    return 1;
                }
                else if(flag == 0){
                    red;
                    printf("Failed Operation!");
                    Sleep(600);
                }
            }
            else if(option==3){
                PickTheme();
            }
       }
    }
    return 0;
}
//create channel==============================================================================================================================================================================================
int createchanel(){
    char buffer[1024],rgstr_chnl[80];
    char *chnlnm = chnlname;
    int flag;

    //scan a name for Chanel------------------------------------------------
    system("cls");
    CPATT(NORMAL);
    printf("Choose a name for your Channel : ");
    RESET;
    scanf("%s",chnlnm);

    //combining string make it readable for server
    strcpy(rgstr_chnl,"create channel ");
    strcat(rgstr_chnl,chnlname);
    strcat(rgstr_chnl,", ");
    strcat(rgstr_chnl,token);
    strcat(rgstr_chnl,"\n");


    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		Sleep(900);
        system("cls");
		return 0;
	}

	// Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));
    //Send The Register Message---------------------------------------------
    send(client_socket,rgstr_chnl, sizeof(rgstr_chnl), 0);
    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);
    //Parsing Received Message----------------------------------------------
    JSON *root = ParseJSON(buffer);
    char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
    char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
        flag = 0;
        }else{
            system("cls");
            flag = 1;
            printf("\"%s\"  Successfully Created\n"
                   "Now You share the name of it\n"
                   "and start chatting with other members",chnlname);
            Sleep(3000);
            system("cls");
        }

    free(msgtype);
    free(msgcontent);
    DeleteJSON(root);

    return flag;
}
//join Channel========================================================================================================================================================================================================
int joinchanel(){
    char buffer[1024],rgstr_chnl[80];
    char *chnlnm = chnlname;
    int flag;

    //scan a name for Chanel------------------------------------------------
    system("cls");
    CPATT(NORMAL);
    printf("Which channel do you want to join : ");
    RESET;
    scanf("%s",chnlnm);

    //combining string make it readable for server
    strcpy(rgstr_chnl,"join channel ");
    strcat(rgstr_chnl,chnlname);
    strcat(rgstr_chnl,", ");
    strcat(rgstr_chnl,token);
    strcat(rgstr_chnl,"\n");


    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		Sleep(900);
        system("cls");
		return 0;
	}


	// Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

    //Send The Register Message---------------------------------------------
    send(client_socket,rgstr_chnl, sizeof(rgstr_chnl), 0);

    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);
    //Parsing Received Message----------------------------------------------
    JSON *root = ParseJSON(buffer);
    char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
    char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
        flag = 0;
        }else{
            system("cls");
            flag = 1;
            printf("You Successfully joined \"%s\" Channel",chnlname);
            Sleep(3000);
            system("cls");
        }

    free(msgtype);
    free(msgcontent);
    DeleteJSON(root);

    return flag;
}

//LogOut=====================================================================================================================================================================================================
int logout(){
    char buffer[1024],command[100];
    int flag;
    //combining string make it readable for server
    strcpy(command,"logout ");
    strcat(command,token);
    strcat(command,"\n");


    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		Sleep(900);
        system("cls");
		return 0;
	}


	// Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

    //Send The Register Message---------------------------------------------
    send(client_socket,command, sizeof(command), 0);

    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);
    //Parsing Received Message----------------------------------------------
    JSON *root = ParseJSON(buffer);
    char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
    char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
        flag = 0;
        }else{
            system("cls");
            flag = 1;
            printf("You Successfully Logged Out.\n"
                   "Hope to see you soon \"%s\" in HATA !",username);
            Sleep(3000);
            system("cls");
        }

    free(msgtype);
    free(msgcontent);
    DeleteJSON(root);

    return flag;
}
//Pick Theme =====================================================================================================
void themeprinter(int selected){
    system("cls");
    Bgreen;
    printf("Theme Menu\n\n");
    RESET;
    printf("Choose Your theme\n");
    if(selected==1){Byello;printf("->");RESET;printf("1:");Byello;printf(" Golden\n");}
    else {RESET;printf("1:");yello;printf(" Golden\n");}

    if(selected==2){Bred;printf("->");RESET;printf("2: ");Bgreen;printf(" Water");Bred;printf("Melon\n");}
    else {RESET;printf("2: ");red;printf(" Water");green;printf("Melon\n");}

    if(selected==3){Bblue;printf("->");RESET;printf("3:");Bblue;printf(" Ocean\n");}
    else {RESET;printf("3:");blue;printf(" Ocean\n");}

}
void PickTheme()
{
    int option=1,ch1,ch2;
    while(TRUE){
        themeprinter(option);
        ch1 = getch();
        /* If a controlling key pressed */
        if(ch1 == 0xE0){
            ch2 = getch();
            /* If Up was pressed*/
            if(ch2==72){
                if(option>1)option--;
            }
            /* If Down was presses */
            else if(ch2==80){
                if(option<3)option++;
            }
       }
       else if(ch1==13){
            if(option==1){
                theme = 1;
                break;
            }
            else if(option==2){
                theme = 2;
                break;
            }
            else if(option==3){
                theme = 3;
                break;
            }
       }
    }
    FILE *fp = fopen("theme.txt","w");
    fprintf(fp,"%d",theme);
    fclose(fp);
}

//Chat Menu===================================================================================================================================================================================================
//============================================================================================================================================================================================================
//============================================================================================================================================================================================================

//prototypes
int send_msg();
int refresh();
int channel_member();
int leave();
void RAP();
void searchmembers();
void searchmessages();

//Global Variables
int f,l;
int lastline,curruntlastline;
int year,month,day,h,min,sec;

void chatmenuprinter(int selected)
{
    system("cls");
    CPATT(MENU);
    printf("Chat Menu   \"");CPATT(NORMAL);printf("%s",chnlname);
    CPATT(MENU);printf("\"");
    CPATT(OTHER);
    printf("\t\tLast Refresh : %d-%d-%d %02d:%02d:%02d\n\n",year,month,day,h,min,sec);

    if(selected==1){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf( "1: Send A New Message\n");

    if(selected==2){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("2: Refresh\n");

    if(selected==3){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("3: Channel Members\n");

    if(selected==4){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("4: See Last 10 Messages\n");

    if(selected==5){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("5: See Previous 10 Messages\n");

    if(selected==6){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("6: See Next 10 Messages\n");

    if(selected==7){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("7: See Messages Manually\n");

    if(selected==8){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("8: Search Members\n");

    if(selected==9){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("9: Search Messages\n");

    if(selected==10){CPATT(CHOOSED);printf("->");}
    else CPATT(NORMAL);
    printf("10: Leave Chanel\n\n");
    CPATT(NORMAL);
    printf(    "----------------------------------------------------------------------------------------------------\n");
    RESET;
    RAP();
    CPATT(NORMAL);
    printf(    "----------------------------------------------------------------------------------------------------\n");
    RESET;
}

int chatmenu(){
    lastline = 0;
    f=0;
    l=0;
    int option=1,flag,temp,ch1,ch2;
    FILE *files = fopen("chnl.txt","w");
    fclose(files);

    while(TRUE){
        chatmenuprinter(option);
        ch1 = getch();
        /* get it from QOURA.com*/
        /* If a controlling key pressed */
        if(ch1 == 0xE0){
            ch2 = getch();
            /* If Up was pressed*/
            if(ch2==72){
                if(option>1)option--;
            }
            /* If Down was presses */
            else if(ch2==80){
                if(option<10)option++;
            }
       }
       else if(ch1==13){
            //Sending a new message ----------------------------------
            if(option==1){
                flag = send_msg();
                if(flag==0){
                    printf("Operation Failed ...");
                    Sleep(1500);
                    system("cls");
                }
                RESET;
            }
            //Refreshing ---------------------------------------------
            else if(option==2){
                flag = refresh();
                if(flag==0){
                    printf("Operation Failed ...");
                    Sleep(1500);
                    system("cls");
                }
                RESET;
            }
            //Channel Members ----------------------------------------
            else if(option==3){
                flag = channel_member();
                if(flag==0){
                    printf("Operation Failed ...");
                    Sleep(1500);
                    system("cls");
                }
            }
            //Last 10 ------------------------------------------------
            else if(option==4){
                if(lastline>9){
                    f = lastline -9;
                    l = lastline;
                }
                else{
                    f = 0;
                    l = lastline;
                }
            }
            //Pre 10 MSG ---------------------------------------------
            else if(option==5){
                if(curruntlastline>10){
                    f = f - 10;
                    l = l - 10;
                    curruntlastline = l;
                }
                else{
                    f = 0;
                    if(lastline>10)
                        l = 10;
                    else l = lastline;
                    curruntlastline = l;
                }
            }
            //Next 10 MSG ---------------------------------------------
            else if(option==6){
                if(curruntlastline+10>lastline){
                    if(lastline>9){
                        l = lastline;
                        f = lastline - 9;
                    }
                    else{
                        f = 0;
                        l = lastline;
                    }
                }
                else {
                    l = curruntlastline + 10;
                    f = f + 10 ;
                    curruntlastline +=10;
                }
            }
            //Manually -----------------------------------------------
            else if(option==7){
                location :
                system("cls");
                RESET;
                printf("You can see Massages in range 1 to %d\n"
                       "Enter first message number that you want to see : ",lastline);
                scanf("%d",&temp);
                if(temp<1){
                    system("cls");
                    printf("Enter a valid input");
                    Sleep(1500);
                    goto location;
                }
                f = temp;
                printf("Enter last message number that you want to see : ");
                scanf("%d",&temp);
                if(temp>lastline){
                    system("cls");
                    printf("Enter a valid input");
                    Sleep(1500);
                    goto location;
                }
                l = temp;
            }
            //leaving------------------------------------------------------------------------------
            else if(option==10){
                flag = leave();
                if(flag==0){
                    printf("Operation Failed ...");
                    Sleep(1500);
                    system("cls");
                }
                else {
                    system("cls");
                    return 1;
                }
            }
            //Searches-------------------------
            else if(option == 8){
                searchmembers();
                RESET;
            }
            else if(option == 9){
                searchmessages();
                RESET;
            }
       }
    }
    return 0;

}
//Send Message================================================================================================================================================================================================
int send_msg(){
    char command[100],buffer[1024],msg[700];
    system("cls");
    red;
    printf("\"CAUTION : YOU CAN NOT USE COMMA(,) OR ENTER IN YOUR MESSAGE!\"\n");
    CPATT(NORMAL);
    printf("Your Message : ");
    RESET;
    scanf("%*c%[^\n]",msg);
    //Making the command-------------------------------------------------------------
    strcpy(command,"send ");
    strcat(command,msg);
    strcat(command,", ");
    strcat(command,token);
    strcat(command,"\n");
    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Socket creation failed...\n");
        Sleep(900);
        system("cls");
    }

    // Connect the client socket to server socket---------------------------
    connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

   //Send The Register Message---------------------------------------------
   send(client_socket,command, sizeof(command), 0);
   //Receive The Message from Server---------------------------------------
   memset(buffer, 0, sizeof(buffer));
   recv(client_socket,buffer,sizeof(buffer),0);


   //Parsing Received Message----------------------------------------------
   JSON *root = ParseJSON(buffer);
   char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
   char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
        free(msgtype);
        free(msgcontent);
        DeleteJSON(root);
        return 0;
    }
    else{
        system("cls");
        free(msgtype);
        free(msgcontent);
        DeleteJSON(root);
        printf("Your Message Sent Successfully");
        Sleep(3000);
        system("cls");
        refresh();
        return 1;
    }


}

//refresh=====================================================================================================================================================================================================
int refresh(){
    int msgcount,i;
    char command[100],buffer[INT_MAX],svmsg[400];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    year = tm.tm_year+1900;
    month = tm.tm_mon +1;
    day = tm.tm_mday;
    h = tm.tm_hour;
    min = tm.tm_min;
    sec = tm.tm_sec;
    //Making the command-------------------------------------------------------------
    strcpy(command,"refresh ");
    strcat(command,token);
    strcat(command,"\n");
    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Socket creation failed...\n");
        Sleep(900);
        system("cls");
    }

    // Connect the client socket to server socket---------------------------
    connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

   //Send The Register Message---------------------------------------------
   send(client_socket,command, sizeof(command), 0);
   //Receive The Message from Server---------------------------------------
   memset(buffer, 0, sizeof(buffer));
   recv(client_socket,buffer,sizeof(buffer),0);
   //Parsing Received Message----------------------------------------------
   JSON *root = ParseJSON(buffer);
   char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
   JSON *msgcontent = GetObjectItemJSON(root,"content");
    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error ; Try Again Later. ");
        Sleep(2000);
        system("cls");
        free(msgtype);
        free(msgcontent);
        DeleteJSON(root);
        return 0;
    }


    //Parsing new messages and writing them in a new file----------------
    msgcount = GetArraySizeJSON(msgcontent);
    printf("%d\n",msgcount);
    FILE *files;
    JSON *msg;
    for(i=0;i<msgcount;i++){
        msg = GetArrayItemJSON(msgcontent,i);
        char *sender = GetObjectItemJSON(msg,"sender")->valuestring;
        char *mssg = GetObjectItemJSON(msg,"content")->valuestring;
        files = fopen("chnl.txt","a");
        strcpy(svmsg,sender);
        strcat(svmsg," : ");
        strcat(svmsg,mssg);
        strcat(svmsg,"\n");
        fputs(svmsg,files);
        fclose(files);
   }
    lastline += msgcount;
    if(lastline>9){
        f = lastline -9;
        l = lastline;
    }
    else{
        f = 0;
        l = lastline;
    }
    curruntlastline = lastline;
    DeleteJSON(root);
    return 1;
}

//Channel member==============================================================================================================================================================================================
int channel_member(){
    int member_count;
    char command[100],buffer[1024],*ptrnm;

            //Making the command-------------------------------------------------------------
            strcpy(command,"channel members ");
            strcat(command,token);
            strcat(command,"\n");
            //Making socket------------------------------------------------------------------
            system("cls");
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket == -1) {
                printf("Socket creation failed...\n");
                Sleep(300);
                system("cls");
            }

            // Connect the client socket to server socket---------------------------
            connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

            //Send The Register Message---------------------------------------------
            send(client_socket,command, sizeof(command), 0);

            //Receive The Message from Server---------------------------------------
            memset(buffer, 0, sizeof(buffer));
            recv(client_socket,buffer,sizeof(buffer),0);
            //Parsing Received Message----------------------------------------------
            JSON *root = ParseJSON(buffer);
            char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
            JSON *mmbr = GetObjectItemJSON(root,"content");

            if(!strcmp(msgtype,"Error")){
                system("cls");
                printf("Something Went Wrong");
                Sleep(2000);
                system("cls");
                free(msgtype);
                DeleteJSON(mmbr);
                DeleteJSON(root);
                return 0;
            }
            else{
                system("cls");
                member_count = GetArraySizeJSON(mmbr);
                green;
                printf("%d ",member_count);
                RESET;
                printf("Members on-line : \n");
                for(int i = 0; i<member_count;i++){
                    ptrnm = GetArrayItemJSON(mmbr,i)->valuestring;
                   printf("%d: %s\n",i+1,ptrnm);
                }
                free(msgtype);
                DeleteJSON(root);
                printf("Press Any Key to Back ...");
                getch();
                system("cls");
                return 1;
            }
    return 0;
}

//Leave ======================================================================================================================================================================================================
int leave(){
    char command[100],buffer[1024];
    //Making the command-------------------------------------------------------------
            strcpy(command,"leave ");
            strcat(command,token);
            strcat(command,"\n");

            //Making socket------------------------------------------------------------------
            system("cls");
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket == -1) {
                printf("Socket creation failed...\n");
                Sleep(900);
                system("cls");
                return 0;
            }


            // Connect the client socket to server socket---------------------------
            connect(client_socket, (SA*)&servaddr, sizeof(servaddr));

            //Send The Register Message---------------------------------------------
            send(client_socket,command, sizeof(command), 0);

            //Receive The Message from Server---------------------------------------
            memset(buffer, 0, sizeof(buffer));
            recv(client_socket,buffer,sizeof(buffer),0);
            //Parsing Received Message----------------------------------------------
            JSON *root = ParseJSON(buffer);
            char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
            char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

            if(!strcmp(msgtype,"Error")){
                system("cls");
                printf("Error : %s",msgcontent);
                Sleep(2000);
                system("cls");
                free(msgtype);
                free(msgcontent);
                DeleteJSON(root);
                return 0;
            }
            else{
                system("cls");
                free(msgtype);
                free(msgcontent);
                DeleteJSON(root);
                printf("You Successfully Leaved \"%s\"",chnlname);
                Sleep(3000);
                system("cls");
                return 1;
            }
    return 0;
}

//Read and Print==============================================================================================================================================================================================
void RAP(){
    if(l==0)return;
    FILE *file = fopen("chnl.txt", "r");
    int count = 1;
    if(f==1)printf("\n\"Start of Messages\"\n");
    if ( file != NULL )
    {
        char line[256];
        while (fgets(line, sizeof line, file) != NULL) // read a line
        {
            if (count>=f&&count<=l)
            {
                printf("%s",line);
                count++;
            }
            else
            {
                count++;
            }
        }
        fclose(file);
    }
    else
    {
        printf("No Message Available ,First Refresh");
    }
    if(l==lastline)printf("\n\"End of Messages\"\n");
}

//Search Members =================================================================================================
void searchmembers()
{
    char buffer[1024],rgstr[80],memnm[60];
    system("cls");
    printf("Which member do you looking for in this channel ?\n");
    scanf("%s",memnm);

     //combining string make it readable for server
    strcpy(rgstr,"member search ");
    strcat(rgstr,memnm);
    strcat(rgstr,", ");
    strcat(rgstr,token);
    strcat(rgstr,"\n");

    //Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		Sleep(900);
        system("cls");
		return ;
	}

	// Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));
    //Send The Register Message---------------------------------------------
    send(client_socket,rgstr, sizeof(rgstr), 0);
    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);
    //Parsing Received Message----------------------------------------------
    JSON *root = ParseJSON(buffer);
    char *msgtype = GetObjectItemJSON(root,"type")->valuestring;
    char *msgcontent = GetObjectItemJSON(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
    }
    else{
        system("cls");
        printf("Member Found!");
        Sleep(3000);
        system("cls");
    }

    free(msgtype);
    free(msgcontent);
    DeleteJSON(root);
}

//Search Messages==================================================================================================
void searchmessages()
{
    char rgstr[80],searchkey[60];
    char buffer[INT_MAX];
    system("cls");
    printf("Enter Your Search Key : ");
    scanf("%s",searchkey);

    //combining string make it readable for server
    strcpy(rgstr,"message search ");
    strcat(rgstr,searchkey);
    strcat(rgstr,", ");
    strcat(rgstr,token);
    strcat(rgstr,"\n");

	//Making socket------------------------------------------------------------------
    system("cls");
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		printf("Socket creation failed...\n");
		Sleep(900);
        system("cls");
		return ;
	}

	// Connect the client socket to server socket---------------------------
	connect(client_socket, (SA*)&servaddr, sizeof(servaddr));
    //Send The Register Message---------------------------------------------
    send(client_socket,rgstr, sizeof(rgstr), 0);
    //Receive The Message from Server---------------------------------------
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket,buffer,sizeof(buffer),0);

    /* Parsing the result */
    JSON *root = ParseJSON(buffer);
    JSON *array = GetObjectItemJSON(root,"content");
    JSON *message;
    char *sndr,*msgg;
    int count = GetArraySizeJSON(array);
    if(count == 0){
        printf("No messages found ...\n\nPress any key to continue...");
        getch();
        DeleteJSON(root);
        return;
    }
    for(int i=0 ; i< count ;i++){
        message = GetArrayItemJSON(array,i);
        sndr = GetObjectItemJSON(message,"sender")->valuestring;
        msgg = GetObjectItemJSON(message,"message")->valuestring;
        printf("%s : %s\n",sndr,msgg);
    }
    printf("\nPress any key to continue...");
    getch();
    DeleteJSON(root);
    return;
}
