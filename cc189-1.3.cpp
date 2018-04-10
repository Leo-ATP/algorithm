#include "./common.h"
using namespace std;

void URLify(char* str, int len){
    int spacecount=0;
    for(int i=0;i<len;i++){
        if(str[i]==' ')
            spacecount++;
    }

    int index=len+2*spacecount;
    for(int i= len-1;i>=0;i--){
        if(str[i]==' '){
            str[--index]='0';
            str[--index]='2';
            str[--index]='%';
        }
        else
            str[--index]=str[i];
        
    }
}

int main()
{
    char str[] = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    URLify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}