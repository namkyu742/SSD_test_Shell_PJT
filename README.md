# **SSAFY EMBEDDED TRACK PRACTICE**

https://user-images.githubusercontent.com/81559614/205648070-5474e214-bb2d-4083-867d-e91beb84ab1f.mp4

---

### **구현해야 할 프로그램**
 **1) 가상 SSD**  
  LBA size : 4Byte ( 값은 항상 10글자로 표현 ex) 0x00000000 ~ 0xFFFFFFFF )  
  총 100개의 LBA ( 0 ~ 99 )  
 -> 사용할 명령어 : Write / Read  
  가상 ssd 프로그램 이름 : ssd  
   [사용가능 명령어]  
   - Write : >> ssd W 주소 값  
   모니터에 출력안됨 -> nand.txt 에 저장됩니다.  
   
   - Read : >> ssd R 주소  
   모니터에 출력 안됨 -> result.txt 에 read한 결과 저장 ( 1줄만 표시, over write )  
   기존에 저장된 값이 없으면 0x00000000  

 **2) Test Shell Application**  
  테스트 프로그램  
  [사용가능 명령어]  
   write     : write 3 0xAAAABBBB -> ssd에 명령어를 전달한다  
   read      : read 3 -> ssd에 명령어를 전달한다, result.txt의 값을 화면에 출력  
   exit       : shell 종료  
   help      : 명령어 "사용 방법" 출력  
   fullwrite : fullwrite 0xABCDASDA -> LBA 0`~`99 전체에 값 저장  
   fullread : fullread -> LBA 0`~`99 전체의 값 화면에 출력  

 **3) Test Script**  
   [사용가능 명령어]  
  TestApp1 : Test Shell 에서 "testapp1" 명령어 입력 시 동작  
          -1 fullwrite  
          -2 fullread  
  TestApp2 : Test Shell 에서 "testapp2" 명령어 입력 시 동작  
          -1 0`~`5 LBA에 0xAAAABBBB 값 총 30번 write  
          -2 0`~`5 LBA에 0x12345678 1회 OverWrite  
          -3 0`~`5 LBA read : 0x12345678 나옴   

### **유의사항**  
 1) 매개변수 유효성 검사 수행 : format, LBA 0`~`99, 0`~`F 숫자 범위만 허용  
 2) 없는 명령어일 경우, "INVALID COMMAND" 출력, segment fault 나오면 안됨  

### **참고**  
 1) main argument  
    리눅스에서 실행 프로그램 명령어 "ssd"  
 2) 리눅스쉘프로그래밍 4일차 빌드시스템 p.98 ~ 99  



---

### 실행방법  
make -f Makefile.plat1  
make -f Makefile.plat2  
make -f Makefile.plat3  

**[SSD 프로그램 단독 실행 예제]**
- ./ssd R 1
- ./ssd W 1 0x11111111

**[쉘 프로그램 실행]**
- ./run

**[테스트 스크립트 프로그램 단독 실행]**
- ./test_scripts testapp1
- ./test_scripts testapp2

