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

// TODO: �� ���ڸ� ���ļ� �ϳ��� ���ڿ��� �����ϴ� �ڵ�(��й�ȣ�� ���������� �����ϱ� ����)
// TODO: ���ĺ��� �ƴ϶� ���ڿ� Ư�����ڸ� ������ ��й�ȣ ����