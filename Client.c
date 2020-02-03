//CopyRight : HATAM:)           Now You Can Say This is a CHEAT B****!
//Date Uploaded to QUERA : 2019/ 12/ 29

#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "cJSON.h"
#define PORT 12345
#define SA struct sockaddr

//Prototypes
int creataccount();


//Global Variables
int client_socket;
char token[80];
struct sockaddr_in servaddr;
char username[100];
char chnlname[100];

void etcprint(){
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    system("cls");
}

//Account Menu=================================================================================================================================================================================================
//=============================================================================================================================================================================================================

//prototypes
int login();

int account(){
    int option,flag=0;
    printf("Account Menu\n\n");
    location1:
    printf("Login into your Account\n1: Login\n\n"
           "Don't You Have HATA Account Yet?!\nHarry Up,Create One NOW!\n"
           "2: Create A New Account\n\n"
           "3: Exit Application\n\n"
           "Choose Your Option : ");
    scanf("%d",&option);
    if(option==1){
        system("cls");
        flag = login();
        if(flag==1){
            return 1;
        }
        else if(flag==0){
            system("cls");
            printf("Account Menu\n\n");
            goto location1;
        }
    }
    else if(option==2){
        system("cls");
        creataccount();
        printf("Account Menu\n\n");
        goto location1;
    }
    else if(option==3){
        return 2;
    }
    else{
        system("cls");
        printf("Account Menu\n\n");
        printf("Enter a Valid Option !\n\n");
        goto location1;
    }
    return 0;

}


//LOGIN========================================================================================================================================================================================================
int login(){
    char buffer[1024],lgnstr[80];
    struct login_info{
        char password[100];
    }client_info;
    int flag=0;

    char *user = username;
    char *pass = client_info.password;

    printf("Enter your UserName : ");
    scanf("%s",username);
    printf("Enter your PassWord : ");
    scanf("%s",client_info.password);

    //Combining Strings-----------------------------------------------------
    strcpy(lgnstr,"login ");
    strcat(lgnstr,user);
    strcat(lgnstr,", ");
    strcat(lgnstr,pass);
    strcat(lgnstr,"\n");

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
    cJSON *root1 = cJSON_Parse(buffer);
    char *msgtype1 = cJSON_GetObjectItem(root1,"type")->valuestring;
    char *msgcontent1 = cJSON_GetObjectItem(root1,"content")->valuestring;
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
        Sleep(2000);
        system("cls");
    }
    cJSON_Delete(root1);
    free(msgtype1);
    free(msgcontent1);


    return flag;

}




//CREAT ACCOUNT================================================================================================================================================================================================
int creataccount(){

    char buffer[1024],rgstr[80];

    int flag;
    struct login_info{
        char username[100];
        char password[100];
    }client_info;

    //----------------------------------------------------------------------

    char *user = client_info.username;
    char *pass = client_info.password;

    printf("Choose a UserName : ");
    scanf("%s",client_info.username);
    printf("Choose your PassWord : ");
    scanf("%s",client_info.password);

    //Combining Strings-----------------------------------------------------
    strcpy(rgstr,"register ");
    strcat(rgstr,user);
    strcat(rgstr,", ");
    strcat(rgstr,pass);
    strcat(rgstr,"\n");


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
    cJSON *root = cJSON_Parse(buffer);
    char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
    char *msgcontent = cJSON_GetObjectItem(root,"content")->valuestring;

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
    cJSON_Delete(root);
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

int mainmenu(){
    int flag=0,option;
    location:
    printf("\"Main Menu\"\n\n"
           "1: Create a Channel\n"
           "2: Join a Channel\n"
           "3: LogOut\n\n"
           "Choose your option : ");
    scanf("%d",&option);
    if(option==1){
        flag = createchanel();
        if(flag==1){
            flag = chatmenu();
            system("cls");
            goto location;
        }
        else if(flag == 0){
            printf("Failed Operation!");
            Sleep(600);
            system("cls");
            goto location;
        }
    }
    else if(option==2){
        flag = joinchanel();
        if(flag==1){
            flag = chatmenu();
            system("cls");
            goto location;
        }
        else{
            printf("Failed Operation!");
            Sleep(600);
            system("cls");
            goto location;
        }
    }
    else if(option==3){
        flag = logout();
        if(flag==1){
            return 1;
        }
        else if(flag == 0){
            printf("Failed Operation!");
            Sleep(600);
            system("cls");
            goto location;
        }
    }
    else {
        system("cls");
        printf("Enter a Valid Option !");
        Sleep(1500);
        system("cls");
        goto location;
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
    printf("Choose a name for your Channel : ");
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
    cJSON *root = cJSON_Parse(buffer);
    char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
    char *msgcontent = cJSON_GetObjectItem(root,"content")->valuestring;

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
    cJSON_Delete(root);

    return flag;
}
//join Channel========================================================================================================================================================================================================
int joinchanel(){
    char buffer[1024],rgstr_chnl[80];
    char *chnlnm = chnlname;
    int flag;

    //scan a name for Chanel------------------------------------------------
    system("cls");
    printf("Which channel do you want to join : ");
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
    cJSON *root = cJSON_Parse(buffer);
    char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
    char *msgcontent = cJSON_GetObjectItem(root,"content")->valuestring;

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
    cJSON_Delete(root);

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
    cJSON *root = cJSON_Parse(buffer);
    char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
    char *msgcontent = cJSON_GetObjectItem(root,"content")->valuestring;

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
    cJSON_Delete(root);

    return flag;
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

//Global Variables
int f,l;
int lastline,curruntlastline;
int year,month,day,h,min,sec;

int chatmenu(){
    lastline = 0;
    f=0;
    l=0;
    int option,flag,temp;
    FILE *files = fopen("chnl.txt","w");
    fclose(files);

    while(1){
         printf("Chat Menu\t\"%s\"\tLast Refresh : %d-%d-%d %02d:%02d:%02d\n\n"
                "1: Send A New Message\n"
                "2: Refresh\n"
                "3: Channel Members\n"
                "4: See Last 10 Messages\n"
                "5: See Previous 10 Messages\n"
                "6: See Next 10 Messages\n"
                "7: See Messages Manually\n"
                "8: Leave Chanel\n\n"
                "----------------------------------------------------------------------------------------------------\n",chnlname,year,month,day,h,min,sec);
        RAP(f,l);
        printf("----------------------------------------------------------------------------------------------------\n\nChoose Your Option : ");
        scanf("%d",&option);
        //Sending a new message-----------------------------------------------------------------------------------------
        if (option==1){
            flag = send_msg();
            if(flag==0){
                printf("Operation Failed ...");
                Sleep(1500);
                system("cls");
            }
        }
        //Refresh--------------------------------------------------------------------------------------------------------
        else if(option==2){
                flag = refresh();
                if(flag==0){
                printf("Operation Failed ...");
                Sleep(1500);
                system("cls");
            }
        }
        //Channel Members------------------------------------------------------------------------------------------------
        else if(option==3){
            flag = channel_member();
            if(flag==0){
                printf("Operation Failed ...");
                Sleep(1500);
                system("cls");
            }
        }
        //Last 10 -------------------------------------------------------------------------------------------------------
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
        //Pre 10 MSG----------------------------------------------------------------------------------------------------
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
        //Next 10 MSG---------------------------------------------------------------------------------------------------
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
        //Manually------------------------------------------------------------------------------------------------------
        else if (option==7){
            location :
            system("cls");
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
        //Leave --------------------------------------------------------------------------------------------------------
        else if(option==8){
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
        else{
            printf("Enter a Valid Option !");

        }
        system("cls");
    }

}
//Send Message================================================================================================================================================================================================
int send_msg(){
    char command[100],buffer[1024],msg[700];
    system("cls");
    printf("\"CAUTION : YOU CAN NOT USE COMMA(,) OR ENTER IN YOUR MESSAGE!\"\n"
    "Your Message : ");
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
   cJSON *root = cJSON_Parse(buffer);
   char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
   char *msgcontent = cJSON_GetObjectItem(root,"content")->valuestring;

    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error : %s",msgcontent);
        Sleep(2000);
        system("cls");
        free(msgtype);
        free(msgcontent);
        cJSON_Delete(root);
        return 0;
    }
    else{
        system("cls");
        free(msgtype);
        free(msgcontent);
        cJSON_Delete(root);
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
    char command[100],buffer[4096],svmsg[400];
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
   cJSON *root = cJSON_Parse(buffer);
   char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
   cJSON *msgcontent = cJSON_GetObjectItem(root,"content");
    if(!strcmp(msgtype,"Error")){
        system("cls");
        printf("Error ; Try Again Later. ");
        Sleep(2000);
        system("cls");
        free(msgtype);
        free(msgcontent);
        cJSON_Delete(root);
        return 0;
    }


    //Parsing new messages and writing them in a new file----------------
    msgcount = cJSON_GetArraySize(msgcontent);
    FILE *files;
    for(i=0;i<msgcount;i++){
        cJSON *msg = cJSON_GetArrayItem(msgcontent,i);
        char *sender = cJSON_GetObjectItem(msg,"sender")->valuestring;
        char *mssg = cJSON_GetObjectItem(msg,"content")->valuestring;
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
    cJSON_Delete(root);
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
            cJSON *root = cJSON_Parse(buffer);
            char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
            cJSON *mmbr = cJSON_GetObjectItem(root,"content");

            if(!strcmp(msgtype,"Error")){
                system("cls");
                printf("Something Went Wrong");
                Sleep(2000);
                system("cls");
                free(msgtype);
                cJSON_Delete(mmbr);
                cJSON_Delete(root);
                return 0;
            }
            else{
                system("cls");
                member_count = cJSON_GetArraySize(mmbr);
                printf("%d Members on-line : \n",member_count);
                for(int i = 0; i<member_count;i++){
                    ptrnm = cJSON_GetArrayItem(mmbr,i)->valuestring;
                   printf("%d: %s\n",i+1,ptrnm);
                }
                free(msgtype);
                cJSON_Delete(root);
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
            cJSON *root = cJSON_Parse(buffer);
            char *msgtype = cJSON_GetObjectItem(root,"type")->valuestring;
            char *msgcontent = cJSON_GetObjectItem(root,"content")->valuestring;

            if(!strcmp(msgtype,"Error")){
                system("cls");
                printf("Error : %s",msgcontent);
                Sleep(2000);
                system("cls");
                free(msgtype);
                free(msgcontent);
                cJSON_Delete(root);
                return 0;
            }
            else{
                system("cls");
                free(msgtype);
                free(msgcontent);
                cJSON_Delete(root);
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
