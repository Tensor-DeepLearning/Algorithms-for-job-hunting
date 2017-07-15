/************************************************
  FileName    : main.h                          ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/14                      ;
              _                                 ;
             /  \         吉                    ;     
            /|oo \         祥                   ;    
           (_|  /_)       物                    ;   
             `@/  \   _    镇                   ;    
             |     \  \\  楼                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/

#include <iostream>
#include <fstream>

#include "./code/Algs.h"

using namespace std;

int main(int argc, char **argv)
{
#define REIOS 1  //输入重定向开关，1 重定向到根目录下"TestExample.txt"文件中;
                 //                0 从控制台输入;   
#if REIOS
    streambuf *backup;
    ifstream fin;
    fin.open("TestExample.txt");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());
#endif

    Chirl::CCocktailSort::test();

#if REIOS
    cin.rdbuf(backup);
#endif

#if _WIN32
    system("pause");
#endif
    
    return 0;
}


