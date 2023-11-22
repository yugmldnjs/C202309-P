#include <stdio.h>
#include <stdlib.h>

int main() {
  char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char pw = " ";
  printf("PW: ");
  for (int i = 0; i < 10; i++) {
    
    int a = rand() % 26;
    //printf("%d: %c\n", a, lower[a]);
    
    printf("%c", lower[a]);
    
  }
 
}

// TODO: 각 문자를 합쳐서 하나의 문자열로 저장하는 코드(비밀번호를 최종적으로 저장하기 위함)
// TODO: 알파벳뿐 아니라 숫자와 특수문자를 포함한 비밀번호 생성