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
      InitializeLogin(&login_info[site_count]);
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
          } else if (choice_2 == 2) {
            /*��� 2.2.2 Ư�� ����Ʈ�� �α��� ���� ���*/
            int site_choice;
            printf("���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
            scanf_s("%d", &site_choice);
            printf("----%d�� �α��� ����----\n", site_choice);
            PrintLoginInfo(login_info, site_count, site_choice);

          } else if (choice_2 == 3) {
            // ���� ��� �������� �̵�
            break;
          }
          else {
            // �߸��� ��ȣ �Է½� ���� �޼��� ���
            PrintErrorMessage(3);
          }
        }
      }

    } else if (choice == 3) {
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
          int del_index;  // ������ ����Ʈ ��ȣ ���� ����

          // ��ü ����Ʈ ��� ���
          PrintSiteList(login_info, site_count);
          
          printf("������ ���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
          scanf_s("%d", &del_index);

          /*TODO: �α��� ���� ���� �ϴ� �ڵ� �ۼ�*/

          DelLoginInfo(&login_info,&site_count, del_index);
          

          printf("'%s'�� �α��� ������ ���������� ���� �Ǿ����ϴ�.\n",
                 login_info[del_index - 1].site_name);
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
          InitializeNewPassword(&login_info[change_index-1]);

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

    } else if (choice == 4) {
      /*��� 4. ��õ ��й�ȣ ����*/

      // ��й�ȣ ��õ�� ����� ���� �迭
      char rec_char[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
      printf("��õ ��й�ȣ: ");

      /*�������� ������ ��ġ�� �ε����� �´� ���ڸ� ����� �ݺ��Ͽ� ��õ
      ��й�ȣ�� ����*/
      for (int i = 0; i < 10; i++) {
        int random_index = rand() % 26;
        printf("%c", *(rec_char + random_index));

        /*TODO: �빮��, Ư������, ���ڸ� �����Ͽ� ��õ ��й�ȣ ����*/
        /*TODO: ��õ ���� ��й�ȣ �ٷ� ���� ��� �߰� 
        (1.���ο� ���� 2.���� ����)*/
      }
      printf("\n");
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