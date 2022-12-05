#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"
#include "test_scripts.h"

void run()
{
    FILE *fp;
    if(!(fp = fopen("nand.txt", "r")))
    {
        fp = fopen("nand.txt", "w");
        for (int i = 0; i<100; i++)
        {
            fputs("0x00000000\n", fp);
            // if(i!=99)  fputs("\n", fp);
        }

        fclose(fp);
    }

    // 배열 공간 만들기

    char input[100];      // 입력

    while(1){
        char parsed_input[3][100];
        printf("SSD_TEST_SHELL:~$ ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = '\0';

        char *t = strtok(input, " ");
        int index = 0;
        while(1){
            if(t == NULL)
                break;
            strcpy(parsed_input[index++], t);
            t = strtok(NULL, " ");
        }

        // for (int i = 0; i<3; i++){
        //     printf("%s\n", parsed_input[i]);
        // }

        if(!strcmp(parsed_input[0], "write")){
            int offset = atoi(parsed_input[1]);
            mywrite(offset, parsed_input[2]);
        }
        else if(!strcmp(parsed_input[0], "read")){
            int offset = atoi(parsed_input[1]);
            myread(offset);
        }
        else if(!strcmp(parsed_input[0], "help")){
            help();
        }
        else if(!strcmp(parsed_input[0], "fullwrite")){
            fullwrite(parsed_input[1]);
        }
        else if(!strcmp(parsed_input[0], "fullread")){
            fullread();
        }
        else if(!strcmp(parsed_input[0], "exit")){
            myexit();
        }

        else if(!strcmp(parsed_input[0], "testapp1")){
            char cmd[100];
            sprintf(cmd, "./test_scripts %s", "testapp1");
            system(cmd);
        }
        else if(!strcmp(parsed_input[0], "testapp2")){
            char cmd[100];
            sprintf(cmd, "./test_scripts %s", "testapp2");
            system(cmd);
        }
        else
            printf("INVALID COMMAND\n");
    }
}