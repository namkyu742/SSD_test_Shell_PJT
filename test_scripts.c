#include "commands.h"
#include <string.h>


void testapp1(char value[])
{
    fullwrite(value);
    fullread();
    return;
}

void testapp2()
{
    for (int j = 1; j<=5; j++){
        for (int i = 0; i<30; i++){
            mywrite(j, "0xAAAABBBB");
        }
        mywrite(j, "0x12345678");
        myread(j);
    }
    return;
}

int main(int argc, char *argv[])
{
    if(argc!=2) printf("[Error] Not enough parameters\n");
    if(!strcmp(argv[1], "testapp1")) {
        testapp1("0xABCDEFGE");
        return 0;
    } 
    if(!strcmp(argv[1], "testapp2")) {
        testapp2();
        return 0;
    }
    printf("[Error] format is invalid\n");
    return 0;
}