#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login_info.h"

/*로그인 정보 관리 프로그램*/
int main(void) {
  int choice;          // 메인기능 선택 번호 저장 변수
  int site_count = 0;  // 사이트 수 저장하는 변수
  int max_info = 10;   // 최대 입력 가능한 정보 저장 변수
  printf("로그인 정보 관리 시스템\n");

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
      InitializeLogin(&login_info[site_count]);
      site_count++;  
      
      printf("-- 로그인 정보가 저장 되었습니다 --\n");      

    } else if (choice == 2) {
      /*기능 2. 로그인 정보 출력*/
      if (site_count == 0) {
        // 저장된 정보가 있는지 확인. 없을 경우 오류 문구 출력
        printf("저장된 로그인 정보가 없습니다. 로그인 정보를 추가하세요.\n");
      } else {
        /*기능 2.1 저장된 사이트 목록 출력*/
        PrintSiteList(login_info, site_count, max_info);
                
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
            for (int i = 0; i < site_count; i++) {
              printf("%d. 사이트: %s  아이디: %s  비밀번호: %s\n", i + 1,
                     login_info[i].site_name, login_info[i].id, login_info[i].password);
            }
          } else if (choice_2 == 2) {
            /*기능 2.2.2 특정 사이트의 로그인 정보 출력*/
            int site_choice;
            printf("원하시는 사이트의 번호를 입력하세요: ");
            scanf_s("%d", &site_choice);
            printf("-> %d. 사이트: %s  아이디: %s  비밀번호: %s\n", site_choice,
                   login_info[site_choice - 1].site_name,
                   login_info[site_choice - 1].id,
                   login_info[site_choice - 1].password);
          } else if (choice_2 == 3) {
            // 메인 기능 선택지로 이동
            break;
          }
          else {
            // 잘못된 번호 입력시 오류 메세지 출력
            PrintErrorMessage(3);
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

          // 전체 사이트 목록 출력
          PrintSiteList(login_info, site_count,max_info);
          
          printf("삭제를 원하시는 사이트의 번호를 입력하세요: ");
          scanf_s("%d", &del_index);

          /*TODO: 로그인 정보 삭제 하는 코드 작성*/

          // DelLogin(site_name, ID, PW, del_choice);

          printf("'%s'의 로그인 정보가 정상적으로 삭제 되었습니다.\n",
                 login_info[del_index - 1].site_name);
        }

        /*기능 3.2 비밀번호 변경*/
        else if (choice_3 == 2) {
          int change_index;  // 변경할 사이트의 번호를 저장하는 변수

          // 전체 사이트 목록 출력
          PrintSiteList(login_info, site_count, max_info);

          // 비밀번호를 변경할 사이트의 번호를 입력받기
          printf("비밀번호를 변경할 사이트를 선택해주세요: ");
          scanf_s("%d", &change_index);

          // 선택한 사이트의 현재 로그인 정보 출력
          printf("----현재 로그인 정보----\n");
          printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
                 login_info[change_index - 1].site_name,
                 login_info[change_index - 1].id,
                 login_info[change_index - 1].password);
          printf("------------------------\n");

          // 변경할 비밀번호 입력받기
          InitializeNewPassword(&login_info[change_index-1]);

          // 변경된 로그인 정보 출력
          printf("---변경된 로그인 정보---\n");
          printf("사이트: %s\n아이디: %s\n비밀번호: %s\n",
                 login_info[change_index - 1].site_name,
                 login_info[change_index - 1].id,
                 login_info[change_index - 1].password);
          printf("------------------------\n");

        } else if (choice_3 == 3) {
          // 메인기능 선택지로 이동
          break;
        } else {
          // 잘못된 번호 입력시 오류 메세지 출력
          PrintErrorMessage(3);
        }
      }

    } else if (choice == 4) {
      /*기능 4. 추천 비밀번호 생성*/

      // 비밀번호 추천에 사용할 문자 배열
      char rec_char[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
      printf("추천 비밀번호: ");

      /*랜덤수의 나머지 위치의 인덱스에 맞는 문자를 출력을 반복하여 추천
      비밀번호를 생성*/
      for (int i = 0; i < 10; i++) {
        int random_index = rand() % 26;
        printf("%c", *(rec_char + random_index));

        /*TODO: 대문자, 특수문자, 숫자를 포함하여 추천 비밀번호 생성*/
      }
      printf("\n");
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