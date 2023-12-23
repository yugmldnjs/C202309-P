#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login_info.h"

/*�α��� ���� ���� ���α׷�*/
int main(void) {
  int choice;          // ���α�� ���� ��ȣ ���� ����
  int site_count = 0;  // ����Ʈ �� �����ϴ� ����
  int max_info = 10;   // �ִ� �Է� ������ ���� ���� ����
  printf("�α��� ���� ���� �ý���\n\n");

  // �α��� ������ ������ ����ü ũ�� �����Ҵ�
  LOGIN* login_info = (LOGIN*)malloc(max_info * sizeof(LOGIN));

  while (1) {
    printf("========================\n");
    printf("--�޴��� �������ּ���.--\n");
    printf(
        "1. �α��� ���� �Է�\n2. �α��� ���� ����\n3. �α��� ���� ����\n4. "
        "��õ ��й�ȣ\n5. ���α׷� ����\n");
    printf("========================\n");
    printf("��ȣ: ");
    scanf_s("%d", &choice);

    // ����� ������ �ִ� ���� ���� ������ 1������ ����ü ũ�� Ȯ��
    if (site_count % 10 == 9) {
      max_info = max_info + 10;
      login_info = realloc(login_info, max_info * sizeof(LOGIN));
    }

    if (choice == 1) {
      /*��� 1. �α��� ���� ����*/
      /*��� 1.1 ����ڷκ��� �α��� ���� �Է� �ޱ�*/
      // InitializeLogin(&login_info[site_count]);
      InitializeSite(&login_info[site_count]);
      InitializeId(&login_info[site_count]);
      InitializePassword(&login_info[site_count]);
      site_count++;

      printf("-- �α��� ������ ���� �Ǿ����ϴ� --\n");

    } else if (choice == 2) {
      /*��� 2. �α��� ���� ���*/
      if (site_count == 0) {
        // ����� ������ �ִ��� Ȯ��. ���� ��� ���� ���� ���
        printf("����� �α��� ������ �����ϴ�. �α��� ������ �߰��ϼ���.\n");
      } else {
        /*��� 2.1 ����� ����Ʈ ��� ���*/
        PrintSiteList(login_info, site_count);

        /*���2.2 �α��� ���� ���*/
        while (1) {
          int choice_2 = 0;
          printf("------------------------\n");
          printf("���Ͻô� ����� �����ϼ���.\n");
          printf(
              "1. ��ü ����Ʈ �α��� ����\n2. Ư�� ����Ʈ�� �α��� ����\n3. "
              "�ڷ� "
              "����\n");
          printf("------------------------\n");
          printf("��ȣ: ");
          scanf_s("%d", &choice_2);

          if (choice_2 == 1) {
            /*��� 2.2.1 ��ü ����Ʈ�� �α��� ���� ���*/
            PrintLoginInfo(login_info, site_count, 0);
            break;
          } else if (choice_2 == 2) {
            /*��� 2.2.2 Ư�� ����Ʈ�� �α��� ���� ���*/
            int site_choice;
            printf("���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
            scanf_s("%d", &site_choice);
            printf("--- %d�� �α��� ���� ---\n", site_choice);
            PrintLoginInfo(login_info, site_count, site_choice);

          } else if (choice_2 == 3) {
            // ���� ��� �������� �̵�
            break;
          } else {
            // �߸��� ��ȣ �Է½� ���� �޼��� ���
            PrintErrorMessage(3);
          }
        }
      }

    } else if (choice == 3) {
      if (site_count == 0) {
        // ����� ������ �ִ��� Ȯ��. ���� ��� ���� ���� ���
        printf("����� �α��� ������ �����ϴ�. �α��� ������ �߰��ϼ���.\n");
      } else {
        while (1) {
          /*��� 3. �α��� ���� ����*/
          int choice_3;
          printf("------------------------\n");
          printf("���Ͻô� ����� �����ϼ���.\n");
          printf(
              "1. �α��� ���� ����\n2. �α��� ���� ����\n3. �ڷ� "
              "����\n");
          printf("------------------------\n");
          printf("��ȣ: ");
          scanf_s("%d", &choice_3);

          /*��� 3.1 �α��� ���� ����*/
          if (choice_3 == 1) {
            // ��ü ����Ʈ ��� ���
            PrintSiteList(login_info, site_count);

            // �α��� ���� ����
            DelLoginInfo(login_info, site_count);
            site_count--;

            break;
          }

          /*��� 3.2 ��й�ȣ ����*/
          else if (choice_3 == 2) {
            int change_index;  // ������ ����Ʈ�� ��ȣ�� �����ϴ� ����

            // ��ü ����Ʈ ��� ���
            PrintSiteList(login_info, site_count);

            // ��й�ȣ�� ������ ����Ʈ�� ��ȣ�� �Է¹ޱ�
            printf("��й�ȣ�� ������ ����Ʈ�� �������ּ���: ");
            scanf_s("%d", &change_index);

            // ������ ����Ʈ�� ���� �α��� ���� ���
            printf("----���� �α��� ����----\n");
            PrintLoginInfo(login_info, site_count, change_index);

            // ������ ��й�ȣ �Է¹ޱ�
            InitializeNewPassword(&login_info[change_index - 1]);

            // ����� �α��� ���� ���
            printf("---����� �α��� ����---\n");
            PrintLoginInfo(login_info, site_count, change_index);

          } else if (choice_3 == 3) {
            // ���α�� �������� �̵�
            break;
          } else {
            // �߸��� ��ȣ �Է½� ���� �޼��� ���
            PrintErrorMessage(3);
          }
        }
      }

    } else if (choice == 4) {
      /*��� 4. ��õ ��й�ȣ ����*/
      int password_len = 0;  // ��õ ��й�ȣ ���̸� �Է¹��� ����
      int choice_4;  // ���α�� ���� ��ȣ ���� ����

      // ��й�ȣ ��õ�� ����� ���� �迭
      char rec_arr[] =
          "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*_-/"
          "?0123456789";

      // ��й�ȣ ���� �Է¹ޱ�
      printf("�� �ڸ��� ��й�ȣ�� ��õ�� �帱���? ");
      scanf_s("%d", &password_len);
      char* rec_password = (char*)malloc(password_len + 1);
      printf("  ��õ ��й�ȣ: ");

      /*�������� ������ ��ġ�� �ε����� �´� ���ڸ� ����� �ݺ��Ͽ� ��õ
      ��й�ȣ ���� �� ����*/
      for (int i = 0; i < password_len; i++) {
        rec_password[i] = rec_arr[rand() % strlen(rec_arr)];
      }
      rec_password[password_len] = '\0';  // �� ���� �ڸ��� null�� ����
      printf("%s", rec_password);
      printf("\n");

      printf("------------------------\n");
      printf(
          "1. ���ο� �α��� ������ �߰�\n2. ���� �α��� ������ �߰�\n3. �ڷ� "
          "����\n");
      printf("------------------------\n");
      printf("��ȣ: ");
      scanf_s("%d", &choice_4);
      if (choice_4 == 1) {
        /*���ο� �α��� ������ �߰�*/

        InitializeSite(&login_info[site_count]);  // ����Ʈ �Է� �� ����
        InitializeId(&login_info[site_count]);    // ���̵� �Է� �� ����

        // ��õ ���� ��й�ȣ ����
        login_info[site_count].password =
            (char*)malloc((strlen(rec_password) + 1) * sizeof(char));
        strcpy_s(login_info[site_count].password, strlen(rec_password) + 1,
                 rec_password);
        site_count++;
        printf("- ���� �α��� ������ ����Ǿ����ϴ� -\n");
        
        PrintLoginInfo(login_info, site_count, site_count);

      } else if (choice_4 == 2) {
        /*���� �α��� ������ �߰�*/
        int change_index;  // ������ ����Ʈ�� ��ȣ�� �����ϴ� ����

        // ��ü ����Ʈ ��� ���
        PrintSiteList(login_info, site_count);

        // ��й�ȣ�� ������ ����Ʈ�� ��ȣ�� �Է¹ޱ�
        printf("��й�ȣ�� ������ ����Ʈ�� �������ּ���: ");
        scanf_s("%d", &change_index);

        // ������ ����Ʈ�� ���� �α��� ���� ���
        printf("----���� �α��� ����----\n");
        PrintLoginInfo(login_info, site_count, change_index);

        // ������ ��й�ȣ �����Ҵ� ����
        free(login_info->password);

        // ��õ ��й�ȣ �����Ҵ� �� ����
        login_info->password =
            (char*)malloc((strlen(rec_password) + 1) * sizeof(char));
        strcpy_s(login_info->password, strlen(rec_password) + 1, rec_password);

        // ����� �α��� ���� ���
        printf("---����� �α��� ����---\n");
        PrintLoginInfo(login_info, site_count, change_index);
      }

    } else if (choice == 5) {
      /*���α׷� ����*/

      // ���� �Ҵ� ����
      for (int i = 0; i < site_count; i++) {
        free(login_info[i].site_name);
        free(login_info[i].id);
        free(login_info[i].password);
      }
      free(login_info);

      // ���α׷� ����
      printf("���α׷��� �����մϴ�.");
      break;
    } else {
      // �߸��� ��ȣ �Է½� ���� �޼��� ���
      PrintErrorMessage(5);
    }
  }
  return 0;
}