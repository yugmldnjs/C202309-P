#include "login_info.h"

#include <stdlib.h>
#include <string.h>

// 사이트명을 구조체 변수에 저장하는 함수 정의
void InitializeSite(LOGIN* login_info) {
  char temp[100];  // 입력받은 값 임시 저장 변수
  printf("   사이트: ");
  scanf_s("%s", temp, (int)sizeof(temp));

  // 동적할당 & 구조체에 저장
  login_info->site_name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(login_info->site_name, strlen(temp) + 1, temp);
}

// 아이디를 구조체 변수에 저장하는 함수 정의
void InitializeId(LOGIN* login_info) {
  char temp[100];
  printf("   아이디: ");
  scanf_s("%s", temp, (int)sizeof(temp));
  login_info->id = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(login_info->id, strlen(temp) + 1, temp);
}

// 비밀번호를 구조체 변수에 저장하는 함수 정의
void InitializePassword(LOGIN* login_info) {
  char temp[100];
  printf("   비밀번호: ");
  scanf_s("%s", temp, (int)sizeof(temp));
  login_info->password = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(login_info->password, strlen(temp) + 1, temp);
}

/*전체 사이트 목록을 출력하는 함수 정의*/
void PrintSiteList(LOGIN* p_login_info, int site_count) {
  printf("-- 사이트 목록 (총 %d) --\n", site_count);
  for (int i = 0; i < site_count; i++) {
    printf("   %d. %s\n", i + 1, p_login_info[i].site_name);
  }
  printf("------------------------\n");
}

/*로그인 정보를 출력하는 함수 정의*/
void PrintLoginInfo(LOGIN* p_login_info, int site_count, int index) {
  if (index == 0) {
    // 전체 로그인 정보 출력
    printf("--- 전체 로그인 정보 ---\n");
    for (int i = 0; i < site_count; i++) {
      printf("%d. 사이트: %s  아이디: %s  비밀번호: %s\n", i + 1,
             p_login_info[i].site_name, p_login_info[i].id,
             p_login_info[i].password);
    }
    printf("------------------------\n");
  } else {
    // 특정 사이트 로그인 정보 출력
    printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
           p_login_info[index - 1].site_name, p_login_info[index - 1].id,
           p_login_info[index - 1].password);
    printf("------------------------\n");
  }
}

/*로그인 정보를 삭제하는 함수 정의*/
void DelLoginInfo(LOGIN* login_info, int site_count) {
  int del_index;  // 삭제할 사이트 번호 저장 변수

  printf("삭제를 원하시는 사이트의 번호를 입력하세요: ");
  scanf_s("%d", &del_index);

  // 삭제 확인 메세지 출력
  printf("'%s'의 로그인 정보가 정상적으로 삭제 되었습니다.\n",
         login_info[del_index - 1].site_name);

  // 삭제할 정보 뒤의 값들을 하나씩 앞으로 복사
  for (int i = del_index - 1; i < site_count - 1; i++) {
    memcpy_s(&login_info[i], sizeof(LOGIN), &login_info[i + 1], sizeof(LOGIN));
  }
}

/*비밀번호 변경 후 구조체 변수에 저장하는 함수 정의*/
void InitializeNewPassword(LOGIN* login_info) {
  // 변경할 사이트의 비밀번호 동적할당 해제
  free(login_info->password);

  // 새로운 비밀번호 입력받기
  printf("새로운");
  InitializePassword(login_info);
}

/*잘못된 번호 입력시 에러 메시지 출력 함수 정의*/
void PrintErrorMessage(int size) {
  printf("잘못된 입력입니다. 1~%d 사이의 번호를 입력하세요.\n", size);
}