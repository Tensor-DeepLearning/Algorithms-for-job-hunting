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

#include "./src/Algs.h"

using namespace std;

int main(int argc, char **argv)
{
#define REIOS 1  //输入重定向开关，1 重定向到根目录下"TestExample.txt"文件中;
                 //                0 从控制台输入;   
#if REIOS  
    streambuf *backup = NULL;
    ifstream fin;
    fin.open("TestExample.txt");
    if (fin.is_open())
    {
        backup = cin.rdbuf();
        cin.rdbuf(fin.rdbuf());
    }
    else
        cerr << "<Warning:>"
                "\n\t The file \"TestExample.txt\" is not exist in current folder!" 
                "\n\t Please input your test example from the console!"<< endl;
#endif


    //算法调用;
    Chirl::CQuickSort::test();

#if REIOS
    if (fin.is_open())
    {
        cin.rdbuf(backup);
    }
#endif

#if _WIN32
    system("pause");
#endif
    
    return 0;
}


