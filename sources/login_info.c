#include <stdlib.h>
#include <string.h>
#include "login_info.h"

// 로그인 정보를 구조체에 저장하는 함수 정의
void InitializeLogin(LOGIN* login_info) {
  // 사이트 입력받기: temp변수에 임시저장하여 동적할당 후 구조체에 저장
  printf("사이트: ");
  char temp1[100];
  scanf_s("%s", temp1, (int)sizeof(temp1));
  login_info->site_name = (char*)malloc((strlen(temp1) + 1) * sizeof(char));
  strcpy_s(login_info->site_name, strlen(temp1) + 1, temp1);

  printf("\t");

  printf("아이디: ");
  char temp2[100];
  scanf_s("%s", temp2, (int)sizeof(temp2));
  login_info->id = (char*)malloc((strlen(temp2) + 1) * sizeof(char));
  strcpy_s(login_info->id, strlen(temp2) + 1, temp2);

  printf("\t");

  printf("비밀번호: ");
  char temp3[100];
  scanf_s("%s", temp3, (int)sizeof(temp3));
  login_info->password = (char*)malloc((strlen(temp3) + 1) * sizeof(char));
  strcpy_s(login_info->password, strlen(temp3) + 1, temp3);
}