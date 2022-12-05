#include "commands.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc == 3) {
        if(!strcmp(argv[1], "R")){
            int offset = atoi(argv[2]);
            _read(offset);
        }
        else printf("[Error] format is invalid\n");
    }
    else if(argc == 4) {
        if(!strcmp(argv[1], "W")){
            int offset = atoi(argv[2]);
            _write(offset, argv[3]);
        }
        else printf("[Error] format is invalid\n");
    }
    else printf("[Error] Not enough parameters\n");
}