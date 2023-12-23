#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login_info.h"

/*로그인 정보 관리 프로그램*/
int main(void) {
  int choice;          // 메인기능 선택 번호 저장 변수
  int site_count = 0;  // 사이트 수 저장하는 변수
  int max_info = 10;   // 최대 입력 가능한 정보 저장 변수
  printf("로그인 정보 관리 시스템\n\n");

  // 로그인 정보를 저장할 구조체 크기 동적할당
  LOGIN* login_info = (LOGIN*)malloc(max_info * sizeof(LOGIN));

  while (1) {
    printf("========================\n");
    printf("--메뉴를 선택해주세요.--\n");
    printf(
        "1. 로그인 정보 입력\n2. 로그인 정보 보기\n3. 로그인 정보 변경\n4. "
        "추천 비밀번호\n5. 프로그램 종료\n");
    printf("========================\n");
    printf("번호: ");
    scanf_s("%d", &choice);

    // 저장된 정보가 최대 저장 가능 수보다 1작을때 구조체 크기 확장
    if (site_count % 10 == 9) {
      max_info = max_info + 10;
      login_info = realloc(login_info, max_info * sizeof(LOGIN));
    }

    if (choice == 1) {
      /*기능 1. 로그인 정보 저장*/
      /*기능 1.1 사용자로부터 로그인 정보 입력 받기*/
      // InitializeLogin(&login_info[site_count]);
      InitializeSite(&login_info[site_count]);
      InitializeId(&login_info[site_count]);
      InitializePassword(&login_info[site_count]);
      site_count++;

      printf("-- 로그인 정보가 저장 되었습니다 --\n");

    } else if (choice == 2) {
      /*기능 2. 로그인 정보 출력*/
      if (site_count == 0) {
        // 저장된 정보가 있는지 확인. 없을 경우 오류 문구 출력
        printf("저장된 로그인 정보가 없습니다. 로그인 정보를 추가하세요.\n");
      } else {
        /*기능 2.1 저장된 사이트 목록 출력*/
        PrintSiteList(login_info, site_count);

        /*기능2.2 로그인 정보 출력*/
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
            /*기능 2.2.1 전체 사이트의 로그인 정보 출력*/
            PrintLoginInfo(login_info, site_count, 0);
            break;
          } else if (choice_2 == 2) {
            /*기능 2.2.2 특정 사이트의 로그인 정보 출력*/
            int site_choice;
            printf("원하시는 사이트의 번호를 입력하세요: ");
            scanf_s("%d", &site_choice);
            printf("--- %d번 로그인 정보 ---\n", site_choice);
            PrintLoginInfo(login_info, site_count, site_choice);

          } else if (choice_2 == 3) {
            // 메인 기능 선택지로 이동
            break;
          } else {
            // 잘못된 번호 입력시 오류 메세지 출력
            PrintErrorMessage(3);
          }
        }
      }

    } else if (choice == 3) {
      if (site_count == 0) {
        // 저장된 정보가 있는지 확인. 없을 경우 오류 문구 출력
        printf("저장된 로그인 정보가 없습니다. 로그인 정보를 추가하세요.\n");
      } else {
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
            // 전체 사이트 목록 출력
            PrintSiteList(login_info, site_count);

            // 로그인 정보 삭제
            DelLoginInfo(login_info, site_count);
            site_count--;

            break;
          }

          /*기능 3.2 비밀번호 변경*/
          else if (choice_3 == 2) {
            int change_index;  // 변경할 사이트의 번호를 저장하는 변수

            // 전체 사이트 목록 출력
            PrintSiteList(login_info, site_count);

            // 비밀번호를 변경할 사이트의 번호를 입력받기
            printf("비밀번호를 변경할 사이트를 선택해주세요: ");
            scanf_s("%d", &change_index);

            // 선택한 사이트의 현재 로그인 정보 출력
            printf("----현재 로그인 정보----\n");
            PrintLoginInfo(login_info, site_count, change_index);

            // 변경할 비밀번호 입력받기
            InitializeNewPassword(&login_info[change_index - 1]);

            // 변경된 로그인 정보 출력
            printf("---변경된 로그인 정보---\n");
            PrintLoginInfo(login_info, site_count, change_index);

          } else if (choice_3 == 3) {
            // 메인기능 선택지로 이동
            break;
          } else {
            // 잘못된 번호 입력시 오류 메세지 출력
            PrintErrorMessage(3);
          }
        }
      }

    } else if (choice == 4) {
      /*기능 4. 추천 비밀번호 생성*/
      int password_len = 0;  // 추천 비밀번호 길이를 입력받을 변수
      int choice_4;  // 세부기능 선택 번호 저장 변수

      // 비밀번호 추천에 사용할 문자 배열
      char rec_arr[] =
          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*_-/"
          "?0123456789";

      // 비밀번호 길이 입력받기
      printf("몇 자리의 비밀번호를 추천해 드릴까요? ");
      scanf_s("%d", &password_len);
      char* rec_password = (char*)malloc(password_len + 1);
      printf("  추천 비밀번호: ");

      /*랜덤수의 나머지 위치의 인덱스에 맞는 문자를 출력을 반복하여 추천
      비밀번호 생성 및 저장*/
      for (int i = 0; i < password_len; i++) {
        rec_password[i] = rec_arr[rand() % strlen(rec_arr)];
      }
      rec_password[password_len] = '\0';  // 맨 뒤의 자리에 null값 저장
      printf("%s", rec_password);
      printf("\n");

      printf("------------------------\n");
      printf(
          "1. 새로운 로그인 정보에 추가\n2. 기존 로그인 정보에 추가\n3. 뒤로 "
          "가기\n");
      printf("------------------------\n");
      printf("번호: ");
      scanf_s("%d", &choice_4);
      if (choice_4 == 1) {
        /*새로운 로그인 정보에 추가*/

        InitializeSite(&login_info[site_count]);  // 사이트 입력 및 저장
        InitializeId(&login_info[site_count]);    // 아이디 입력 및 저장

        // 추천 받은 비밀번호 저장
        login_info[site_count].password =
            (char*)malloc((strlen(rec_password) + 1) * sizeof(char));
        strcpy_s(login_info[site_count].password, strlen(rec_password) + 1,
                 rec_password);
        site_count++;
        printf("- 다음 로그인 정보가 저장되었습니다 -\n");
        
        PrintLoginInfo(login_info, site_count, site_count);

      } else if (choice_4 == 2) {
        /*가존 로그인 정보에 추가*/
        int change_index;  // 변경할 사이트의 번호를 저장하는 변수

        // 전체 사이트 목록 출력
        PrintSiteList(login_info, site_count);

        // 비밀번호를 변경할 사이트의 번호를 입력받기
        printf("비밀번호를 변경할 사이트를 선택해주세요: ");
        scanf_s("%d", &change_index);

        // 선택한 사이트의 현재 로그인 정보 출력
        printf("----현재 로그인 정보----\n");
        PrintLoginInfo(login_info, site_count, change_index);

        // 변경할 비밀번호 동적할당 해제
        free(login_info->password);

        // 추천 비밀번호 동적할당 및 저장
        login_info->password =
            (char*)malloc((strlen(rec_password) + 1) * sizeof(char));
        strcpy_s(login_info->password, strlen(rec_password) + 1, rec_password);

        // 변경된 로그인 정보 출력
        printf("---변경된 로그인 정보---\n");
        PrintLoginInfo(login_info, site_count, change_index);
      }

    } else if (choice == 5) {
      /*프로그램 종료*/

      // 동적 할당 해제
      for (int i = 0; i < site_count; i++) {
        free(login_info[i].site_name);
        free(login_info[i].id);
        free(login_info[i].password);
      }
      free(login_info);

      // 프로그램 종료
      printf("프로그램을 종료합니다.");
      break;
    } else {
      // 잘못된 번호 입력시 오류 메세지 출력
      PrintErrorMessage(5);
    }
  }
  return 0;
}