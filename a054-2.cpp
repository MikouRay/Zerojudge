#include <iostream>
#include <string> 
int chartonum(char);
using namespace std;
int main(){
  string id;
  int sum,check,first,sumCheck;
  while (cin >> id){
    sum=0;
    for(int i=0;i<8;i++){
      sum=sum+(id.at(i)-'0')*(8-i);  //�p�⨭���Ҧr�����^��r���᪺��1���8�Ʀr���H�������v��
    }
    if ((id.at(8)-'0')==0) check=0;
     else    check=10-(id.at(8)-'0');
    for(int i=0;i<26;i++){                 //���ըC�ӭ^��r��
      first=chartonum('A'+i);            //�^��r���ন�����Ҧr���W�h�ҩw�q���Ʀr
      sumCheck=sum+(first%10)*9+first/10;    //�^��r�����Ʀr�A�Q��ƭ��H1�A�Ӧ�ƭ��H9
      if ((sumCheck%10)==check){      //�ŦX�W�h�h��X�Ӧr��
        cout << char('A'+i);                    
      }
    }
    cout << endl;
  }
  //system("pause");
}
int chartonum(char x){     //�^��r���ন�Ʀr
  switch(x){
    case 'A':          
       return 10;
       break; 
    case 'B':          
       return 11;
       break; 
    case 'C':          
       return 12;
       break;    
    case 'D':          
       return 13;
       break; 
    case 'E':          
       return 14;
       break; 
    case 'F':          
       return 15;
       break;
    case 'G':          
       return 16;
       break; 
    case 'H':          
       return 17;
       break; 
    case 'I':          
       return 34;
       break;
    case 'J':          
       return 18;
       break; 
    case 'K':          
       return 19;
       break; 
    case 'L':          
       return 20;
       break;    
    case 'M':          
       return 21;
       break; 
    case 'N':          
       return 22;
       break; 
    case 'O':          
       return 35;
       break;
    case 'P':          
       return 23;
       break; 
    case 'Q':          
       return 24;
       break; 
    case 'R':          
       return 25;
       break;
    case 'S':          
       return 26;
       break; 
    case 'T':          
       return 27;
       break;
    case 'U':          
       return 28;
       break; 
    case 'V':          
       return 29;
       break; 
    case 'W':          
       return 32;
       break;
    case 'X':          
       return 30;
       break; 
    case 'Y':          
       return 31;
       break; 
    case 'Z':          
       return 33;
       break;
  }     
}
