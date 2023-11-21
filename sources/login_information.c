#include <stdio.h>
#define SITE_NUM 10
#define CHAR_NUM 100

// TODO: 포인터를 이용한 함수 완성하기

/* 로그인 정보의 주소를 포인터 배열에 저장하는 함수
(행: 사이트, 1열: ID, 2열: password)*/
void CopyAddress(int* arr1, int* arr2, int** arr_ptr);
/*로그인 정보 삭제하는 함수*/
void DelLogin(char* site[][CHAR_NUM], char* ID[][CHAR_NUM],
              char* PW[][CHAR_NUM], int index);


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
      printf("사이트: ");
      scanf_s("%s", site_name[site_count],
              (int)sizeof(site_name[site_count]));  // TODO: 동적 메모리 할당
      printf("ID: ");
      scanf_s("%s", ID[site_count], (int)sizeof(ID[site_count]));
      printf("PW: ");
      scanf_s("%s", PW[site_count], (int)sizeof(PW[site_count]));

      printf("사이트: %s ", site_name[site_count]);
      printf("ID: %s ", ID[site_count]);
      printf("PW: %s\n", PW[site_count]);

      CopyAddress(site_name[site_count], site_name_ptr, site_count);
      CopyAddress(ID[site_count], ID_ptr, site_count);
      CopyAddress(PW[site_count], PW_ptr, site_count);

      // printf("ID: %s, PW: %s", login_ptr[site_count][0],
      // login_ptr[site_count][1]);

      printf("사이트: %s ID: %s PW: %s\n", site_name_ptr[site_count],
             ID_ptr[site_count], PW_ptr[site_count]);

      site_count++;

    } else if (choice == 2) {

      /*기능 2. 로그인 정보 출력*/
      if (site_count == 0) {  // 저장된 정보가 있는지 확인. 없을 경우 오류 문구 출력
        printf("저장된 로그인 정보가 없습니다. 로그인 정보를 추가하세요.\n");  
      } else {

        /*기능 2.1 저장된 사이트 목록 출력*/
        printf("-- 사이트 목록 (총 %d) --\n", site_count);
        for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, site_name[i]);
          
        }
        printf("------------------------\n");
        while (1) {
          int choice_2 = 0;
          printf("------------------------\n");
          printf("원하시는 기능을 선택하세요.\n");
          printf(
              "1. 전체 사이트 로그인 정보\n2. 특정 사이트의 로그인 정보\n3. 뒤로 "
              "가기\n");
          printf("------------------------\n");
          printf("번호: ");
          scanf_s("%d", &choice_2);
          
          if (choice_2 == 1) {
          /*기능 2.2 전체 사이트의 로그인 정보 출력*/
            for (int i = 0; i < site_count; i++) {
            printf("%d. 사이트: %s  아이디: %s  비밀번호: %s\n", i+1,
                   site_name[i], ID[i], PW[i]);
             }
          } else if (choice_2 == 2) {
          /*기능 2.3 특정 사이트의 로그인 정보 출력*/
             int site_choice;
             printf("원하시는 사이트의 번호를 입력하세요: ");
             scanf_s("%d", &site_choice);
             printf("-> 사이트: %s  아이디: %s  비밀번호: %s\n",
                    site_name[site_choice - 1], ID[site_choice - 1],
                    PW[site_choice - 1]);
          } else {
          break;
          }
        }
      }

    } else if (choice == 3) {
      while (1) 
{
        /*기능 3. 로그인 정보 수정*/
        int choice_3;
        printf("------------------------\n");
        printf("원하시는 기능을 선택하세요.\n");
        printf(
            "1. 로그인 정보 삭제\n2. 로그인 정보 수정\n3. 뒤로 "
            "가기\n");
        printf("------------------------\n");
        printf("번호: ");
        scanf_s("%d", &choice_3);



        

        /*기능 3.1 로그인 정보 삭제*/
        if (choice_3 == 1) {
          int del_index;  // 삭제할 사이트 번호 저장 변수
          
          /*TODO: 전체 사이트 목록을 출력하는 코드 함수화*/ 
          
          // 전체 사이트 목록 출력
          printf("-- 사이트 목록 (총 %d) --\n", site_count);
          for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, site_name[i]);
          }

          printf("삭제를 원하시는 사이트의 번호를 입력하세요: ");
          scanf_s("%d", &del_index);

          // TODO: 로그인 정보 삭제 하는 코드 작성
          
          // DelLogin(site_name, ID, PW, del_choice);
          printf(
              "%s의 로그인 정보가 정상적으로 삭제 되었습니다.", 
              site_name[del_index - 1]);

        }

        /*기능 3.2 비밀번호 변경*/
        else if (choice_3 == 2) {
          int change_index;

          // 전체 사이트 목록 출력
          printf("-- 사이트 목록 (총 %d) --\n", site_count);
          for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, site_name[i]);
          }

          printf("비밀번호를 변경할 사이트를 선택해주세요: ");
          scanf_s("%d", &change_index);

          // 선택한 사이트의 현재 로그인 정보 출력
          printf("----현재 로그인 정보----\n");
          printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
                 site_name[change_index - 1], ID[change_index - 1],
                 PW[change_index - 1]);
          printf("------------------------\n");

          printf("변경할 비밀번호를 입력하세요: ");
          scanf_s("%s", PW[change_index - 1],
                  (int)sizeof(PW[change_index - 1]));

          // 변경된 로그인 정보 출력
          printf("---변경된 로그인 정보---\n");
          printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
                 site_name[change_index - 1], ID[change_index - 1],
                 PW[change_index - 1]);
          printf("------------------------\n");
        } else {
          break;
        }
      }

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

// TODO: 함수 제대로 작동하도록 완성시키기
void CopyAddress(char* arr, char** arr_ptr, int size) { arr_ptr[size] = arr; }
void DelLogin(char* site[][CHAR_NUM], char* ID[][CHAR_NUM],
              char* PW[][CHAR_NUM], int index) {}