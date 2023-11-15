#include <stdio.h>
#define SITE_NUM 10
#define CHAR_NUM 100

/* 로그인 정보의 주소를 포인터 배열에 저장하는 함수
(행: 사이트, 1열: ID, 2열: password)*/
void CopyAddress(int* arr1, int* arr2, int** arr_ptr);

/*로그인 정보 관리 프로그램*/
int main(void) {
  int choice;
  int site_count = 0;

  // TODO: 포인터 배열을 사용하는데 더 간단한 방법 생각해보기
  char site_name[SITE_NUM][CHAR_NUM];
  char* site_name_ptr[SITE_NUM];
  char ID[SITE_NUM][CHAR_NUM];
  char* ID_ptr[SITE_NUM];
  char PW[SITE_NUM][CHAR_NUM];
  char* PW_ptr[SITE_NUM];

  while (1) {
    printf("========================\n");
    printf("--메뉴를 선택해주세요.--\n");
    printf(
        "1. 로그인 정보 입력\n2. 로그인 정보 보기\n3. 로그인 정보 변경\n4. "
        "추천 비밀번호\n5. 프로그램 종료\n");
    printf("========================\n");
    printf("번호: ");
    scanf_s("%d", &choice);
    /*printf("%d", choice);*/  // 번호 저장 확인 코드

    if (choice == 1) {
      /*기능 1. 로그인 정보 저장*/
      /*기능 1.1 사용자로부터 로그인 정보 입력 받기*/
      printf("사이트명: ");
      scanf_s("%s", site_name[site_count],
              (int)sizeof(site_name[site_count]));  // TODO: 동적 메모리 할당
      printf("ID: ");
      scanf_s("%s", ID[site_count], (int)sizeof(ID[site_count]));
      printf("PW: ");
      scanf_s("%s", PW[site_count], (int)sizeof(PW[site_count]));

      printf("사이트명: %s ", site_name[site_count]);
      printf("ID: %s ", ID[site_count]);
      printf("PW: %s\n", PW[site_count]);

      CopyAddress(site_name[site_count], site_name_ptr, site_count);
      CopyAddress(ID[site_count], ID_ptr, site_count);
      CopyAddress(PW[site_count], PW_ptr, site_count);

      // printf("ID: %s, PW: %s", login_ptr[site_count][0],
      // login_ptr[site_count][1]);

      printf("사이트: %s ID: %s PW: %s", site_name_ptr[site_count],
             ID_ptr[site_count], PW_ptr[site_count]);

      site_count++;

    } else if (choice == 2) {
      /*기능 2. 로그인 정보 출력*/
      /*기능 2.1 저장된 사이트 목록 출력*/
      /*기능 2.2 전체 사이트의 로그인 정보 출력*/
      /*기능 2.3 특정 사이트의 로그인 정보 출력*/
    } else if (choice == 3) {
      /*기능 3. 로그인 정보 변경*/
    } else if (choice == 4) {
      /*기능 4. 추천 비밀번호 생성*/
    } else if (choice == 5) {
      /*프로그램 종료*/
      printf("프로그램을 종료합니다.");
      break;
    } else {
      printf("잘못된 입력입니다. 1~5 사이의 번호를 입력하세요.\n");
    }
  }
}

void CopyAddress(char* arr, char** arr_ptr, int size) { arr_ptr[size] = arr; }