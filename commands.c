#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _read(int offset)
{
    if(offset<1 || offset>100){
        printf("[ERROR] offset is invalid\n");
        return;
    }
    FILE* fp = fopen("nand.txt", "r");
    int result = fseek(fp, (offset-1)*11, SEEK_SET);
    char line[20];
    fgets(line, 20, fp);
    fclose(fp);

    FILE *result_fp = fopen("result.txt", "w");
    fputs(line, result_fp);
    fclose(result_fp);
    
    return;
}

void myread(int offset)
{
    if(offset<1 || offset>100){
        printf("[ERROR] offset is invalid\n");
        return;
    }
    // _read(offset);
    char cmd[100];
    sprintf(cmd, "./ssd %s %d", "R", offset);
    system(cmd);
    FILE *result_fp = fopen("result.txt", "r");
    char result[20];
    fgets(result, 20, result_fp);
    printf("%s", result);     // 나중에 지울 것
    fclose(result_fp);
}

void _write(int offset, char value[])
{
    if(offset<1 || offset>100){
        printf("[ERROR] offset is invalid\n");
        return;
    }
    if(value[0]!='0' || value[1]!='x'){
        printf("[ERROR] value is invalid\n");
        return;
    }
    for(int i = 2;i<10; i++){
        if(value[i]<'0'||value[i]>'F'||(value[i]>'9'&&value[i]<'A')){
            printf("[ERROR] value is invalid\n");
            return;
        }
    }

    FILE* fp = fopen("nand.txt", "r+");
    int result = fseek(fp, (offset-1)*11, SEEK_SET);
    fputs(value, fp);
    fclose(fp);
}

void mywrite(int offset, char value[])
{
    if(offset<1 || offset>100){
        printf("[ERROR] offset is invalid\n");
        return;
    }
    if(value[0]!='0' || value[1]!='x'){
        printf("[ERROR] value is invalid\n");
        return;
    }
    for(int i = 2;i<10; i++){
        if(value[i]<'0'||value[i]>'F'||(value[i]>'9'&&value[i]<'A')){
            printf("[ERROR] value is invalid\n");
            return;
        }
    }
    
    char cmd[100];
    sprintf(cmd, "./ssd %s %d %s", "W", offset, value);
    system(cmd);
    // _write(offset, value);

}

void help()
{
    printf("│ WRITE : \n");
    printf("│ => ssd W N 0x00000000 : N번째 자리에, 0x00000000 삽입\n");
    printf("│ READ : \n");
    printf("│ => ssd R N : N번째 자리에 있는 16진수 숫자를 읽어 Result.txt에 삽입\n");
    printf("│ => READ N : N번째 자리에 있는 16진수 숫자를 Result.txt에 삽입하고 출력 \n");
    printf("│ EXIT : \n");
    printf("│ => exit : 종료\n");
    printf("│ HELP : \n");
    printf("│ => help : 모든 명령어 설명 \n");
    printf("│ FULLWRITE\n");
    printf("│ => fullwrite 0xABCDFFFF : 모든 공간에 0xABCDFFFF 를 저장한다.\n");
    printf("│ FULLREAD\n");
    printf("│ => fullread : ssd 모든 값을 화면에 출력한다. \n");
    printf("│ TESTAPP1 \n");
    printf("│ => testapp1 : FULLWRITE FULLREAD 과정을 한 번씩 수행하면서, 전체 값이 잘 입력되고 출력되는지 확인하는 Script\n");
    printf("│ TESTAPP2\n");
    printf("│ => 0~5 번 LBA 에 0xAAAABBBB 값으로 촐 30번 Write를 수행한다. \n");
    printf("│ => 0~5 번 LBA 에 0x12345678 값으로 촐 1회 Over Write \n");
    printf("│ => 0~5 번 LBA Read 했을 때 정상적으로 값이 읽히는지 확인하다. \n");
}

void myexit()
{
    exit(-1);
}

void fullread()
{
    FILE *fp = fopen("nand.txt", "r");
    for(int i = 0; i<100; i++)
    {
        int result = fseek(fp, (i)*11, SEEK_SET);
        char line[20];
        fgets(line, 20, fp);
        printf("%s", line);
    }
    fclose(fp);
}

void fullwrite(char value[])
{
    for(int i = 1; i<=100; i++)
        _write(i, value);
    
}
