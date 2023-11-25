#include <stdio.h>
#include <stdlib.h>
#define SITE_NUM 10
#define CHAR_NUM 100

// TODO: 포인터를 이용한 함수 완성하기
// TODO: 동적 메모리 할당 사용하기

/* 로그인 정보의 주소를 포인터 배열에 저장하는 함수
(행: 사이트, 1열: ID, 2열: password)*/
void CopyAddress(char* arr, char** arr_ptr, int size);
/*로그인 정보 삭제하는 함수*/
void DelLogin(char* site[][CHAR_NUM], char* id[][CHAR_NUM],
              char* password[][CHAR_NUM], int index);

/*로그인 정보 관리 프로그램*/
int main(void) {
  int choice;          // 메인기능 선택 번호 저장 변수
  int site_count = 0;  // 사이트 수 저장하는 변수

  // TODO: 포인터 배열을 사용하는데 더 간단한 방법 생각해보기
  char site_name[SITE_NUM][CHAR_NUM];
  char* site_name_ptr[SITE_NUM];
  char id[SITE_NUM][CHAR_NUM];
  char* id_ptr[SITE_NUM];
  char password[SITE_NUM][CHAR_NUM];
  char* password_ptr[SITE_NUM];

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
      /*TODO: 이미 저장되어 있는 사이트의 정보는 입력 받지 않는 코드 작성*/

      /*기능 1. 로그인 정보 저장*/
      /*기능 1.1 사용자로부터 로그인 정보 입력 받기*/
      printf("사이트: ");
      scanf_s("%s", site_name[site_count],
              (int)sizeof(site_name[site_count]));  // TODO: 동적 메모리 할당
      printf("아이디: ");
      scanf_s("%s", id[site_count], (int)sizeof(id[site_count]));
      printf("비밀번호: ");
      scanf_s("%s", password[site_count], (int)sizeof(password[site_count]));

      // 로그인 정보 저장 확인 코드
      /*printf("site_name[0]: %s id[0]: %s password[]: %s\n",
         site_name[site_count], id[site_count], password[site_count]);*/

      // 로그인 정보 포인터 배열에 저장
      CopyAddress(site_name[site_count], site_name_ptr, site_count);
      CopyAddress(id[site_count], id_ptr, site_count);
      CopyAddress(password[site_count], password_ptr, site_count);

      printf("- 다음 로그인 정보가 저장 되었습니다 -\n");
      printf("\t사이트: %s\n\t아이디: %s\n\t비밀번호: %s\n",
             *(site_name_ptr + site_count), *(id_ptr + site_count),
             *(password_ptr + site_count));

      site_count++;

    } else if (choice == 2) {
      /*기능 2. 로그인 정보 출력*/
      if (site_count == 0) {
        // 저장된 정보가 있는지 확인. 없을 경우 오류 문구 출력
        printf("저장된 로그인 정보가 없습니다. 로그인 정보를 추가하세요.\n");
      } else {
        /*기능 2.1 저장된 사이트 목록 출력*/
        printf("-- 사이트 목록 (총 %d) --\n", site_count);

        // 저장된 사이트 목록 순서대로 출력
        for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, *(site_name_ptr + i));
          ;
        }

        printf("------------------------\n");

        // 기능2의 하위 기능 목록 출력
        while (1) {
          int choice_2 = 0;
          printf("------------------------\n");
          printf("원하시는 기능을 선택하세요.\n");
          printf(
              "1. 전체 사이트 로그인 정보\n2. 특정 사이트의 로그인 정보\n3. "
              "뒤로 "
              "가기\n");
          printf("------------------------\n");
          printf("번호: ");
          scanf_s("%d", &choice_2);

          if (choice_2 == 1) {
            /*기능 2.2 전체 사이트의 로그인 정보 출력*/
            for (int i = 0; i < site_count; i++) {
              printf("%d. 사이트: %s  아이디: %s  비밀번호: %s\n", i + 1,
                     site_name[i], id[i], password[i]);
            }
          } else if (choice_2 == 2) {
            /*기능 2.3 특정 사이트의 로그인 정보 출력*/
            int site_choice;
            printf("원하시는 사이트의 번호를 입력하세요: ");
            scanf_s("%d", &site_choice);
            printf("-> 사이트: %s  아이디: %s  비밀번호: %s\n",
                   *(site_name_ptr + site_choice - 1),
                   *(id_ptr + site_choice - 1),
                   *(password_ptr + site_choice - 1));
          } else {
            // 메인 기능 선택지로 이동
            break;
          }
        }
      }

    } else if (choice == 3) {
      while (1) {
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
            printf("   %d. %s\n", i + 1, *(site_name_ptr + i));
          }

          printf("삭제를 원하시는 사이트의 번호를 입력하세요: ");
          scanf_s("%d", &del_index);

          /*TODO: 로그인 정보 삭제 하는 코드 작성*/

          // DelLogin(site_name, ID, PW, del_choice);

          printf("'%s'의 로그인 정보가 정상적으로 삭제 되었습니다.\n",
                 site_name[del_index - 1]);
        }

        /*기능 3.2 비밀번호 변경*/
        else if (choice_3 == 2) {
          int change_index;  // 변경할 사이트의 번호를 저장하는 변수

          // 전체 사이트 목록 출력
          printf("-- 사이트 목록 (총 %d) --\n", site_count);
          for (int i = 0; i < site_count; i++) {
            printf("   %d. %s\n", i + 1, site_name[i]);
          }

          // 비밀번호를 변경할 사이트의 번호를 입력받기
          printf("비밀번호를 변경할 사이트를 선택해주세요: ");
          scanf_s("%d", &change_index);

          // 선택한 사이트의 현재 로그인 정보 출력
          printf("----현재 로그인 정보----\n");
          printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
                 site_name[change_index - 1], id[change_index - 1],
                 password[change_index - 1]);
          printf("------------------------\n");

          // 변경할 비밀번호 입력받기
          printf("변경할 비밀번호를 입력하세요: ");
          scanf_s("%s", password[change_index - 1],
                  (int)sizeof(password[change_index - 1]));

          // 변경된 로그인 정보 출력
          printf("---변경된 로그인 정보---\n");
          printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
                 *(site_name_ptr + change_index - 1),
                 *(id_ptr + change_index - 1),
                 *(password_ptr + change_index - 1));
          printf("------------------------\n");
        } else {
          // 메인기능 선택지로 이동
          break;
        }
      }

    } else if (choice == 4) {
      /*기능 4. 추천 비밀번호 생성*/

      // 비밀번호 추천에 사용할 문자 배열
      char password_rec[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
      printf("추천 비밀번호: ");

      // 랜덤수의 나머지 위치의 인덱스에 맞는 문자를 출력을 반복하여 추천
      // 비밀번호를 생성
      for (int i = 0; i < 10; i++) {
        int random_index = rand() % 26;
        printf("%c", *(password_rec + random_index));

        /*TODO: 대문자, 특수문자, 숫자를 포함하여 추천 비밀번호 생성*/
      }
      printf("\n");
    } else if (choice == 5) {
      /*프로그램 종료*/
      printf("프로그램을 종료합니다.");
      break;
    } else {
      // 잘못된 번호 입력시 오류 메세지 출력
      printf("잘못된 입력입니다. 1~5 사이의 번호를 입력하세요.\n");
    }
  }
  return 0;
}

// TODO: 함수 제대로 작동하도록 완성시키기
void CopyAddress(char* arr, char** arr_ptr, int size) { arr_ptr[size] = arr; }
void DelLogin(char* site[][CHAR_NUM], char* id[][CHAR_NUM],
              char* password[][CHAR_NUM], int index) {}