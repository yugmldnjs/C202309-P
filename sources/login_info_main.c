#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login_info.h"

/*�α��� ���� ���� ���α׷�*/
int main(void) {
  int choice;          // ���α�� ���� ��ȣ ���� ����
  int site_count = 0;  // ����Ʈ �� �����ϴ� ����

  printf("�α��� ���� ���� �ý���\n");
  printf("�ʱ� ���� �Է�\n");

  int site_num;
  printf("�����Ͻ� ����Ʈ�� ���� �Է��ϼ���: ");
  scanf_s("%d", &site_num);

  // �α��� ������ ������ ����ü ũ�� �����Ҵ�
  LOGIN* login_info = (LOGIN*)malloc(site_num);

  while (1) {

    printf("========================\n");
    printf("--�޴��� �������ּ���.--\n");
    printf(
        "1. �α��� ���� �Է�\n2. �α��� ���� ����\n3. �α��� ���� ����\n4. "
        "��õ ��й�ȣ\n5. ���α׷� ����\n");
    printf("========================\n");
    printf("��ȣ: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
      /*��� 1. �α��� ���� ����*/
      /*��� 1.1 ����ڷκ��� �α��� ���� �Է� �ޱ�*/
      for (int i = 0; i < site_num; i++) {
        printf("%d.      ", i + 1);
        InitializeLogin(&login_info[i]);
      }

      printf("-- �α��� ������ ���� �Ǿ����ϴ� --\n");

      // �α��� ���� ���� Ȯ�� �ڵ�
      /*for (int i = 0; i < site_num; i++) {
        printf("\t����Ʈ: %s\n\t���̵�: %s\n\t��й�ȣ: %s\n",
               login_info[i].site_name, login_info[i].id,
               login_info[i].password);
      }*/
      
      site_count += site_num;

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
            for (int i = 0; i < site_count; i++) {
              printf("%d. ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n", i + 1,
                     login_info[i].site_name, login_info[i].id, login_info[i].password);
            }
          } else if (choice_2 == 2) {
            /*��� 2.2.2 Ư�� ����Ʈ�� �α��� ���� ���*/
            int site_choice;
            printf("���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
            scanf_s("%d", &site_choice);
            printf("-> ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n",
                   login_info[site_choice - 1].site_name,
                   login_info[site_choice - 1].id,
                   login_info[site_choice - 1].password);
          } else {
            // ���� ��� �������� �̵�
            break;
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

          // DelLogin(site_name, ID, PW, del_choice);

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
          printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
                 login_info[change_index - 1].site_name,
                 login_info[change_index - 1].id,
                 login_info[change_index - 1].password);
          printf("------------------------\n");

          // ������ ��й�ȣ �Է¹ޱ�
          printf("������ ��й�ȣ�� �Է��ϼ���: ");
          scanf_s("%s", login_info[change_index - 1].password,
                  (int)sizeof(login_info[change_index - 1].password));

          /*TODO: �α��� ���� ���� �� �ٽ� �����Ҵ�*/

          // ����� �α��� ���� ���
          printf("---����� �α��� ����---\n");
          printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
                 login_info[change_index - 1].site_name,
                 login_info[change_index - 1].id,
                 login_info[change_index - 1].password);
          printf("------------------------\n");

          // ����� ������ �� ����Ǿ����� Ȯ���ϴ� �ڵ�
          /*for (int i = 0; i < site_count; i++) {
            printf(
                "login_info[%d].site_name: %s login_info[%d].id: %s
          login_info[%d].password: "
                "%s\n",
                i, login_info[change_index - 1].site_name,
          i,login_info[change_index - 1].id, i, login_info[change_index -
          1].password);
          }*/
        } else {
          // ���α�� �������� �̵�
          break;
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
      printf("�߸��� �Է��Դϴ�. 1~5 ������ ��ȣ�� �Է��ϼ���.\n");
    }
  }
  return 0;
}

