#include <stdio.h>
#include <stdlib.h>
#define SITE_NUM 10
#define CHAR_NUM 100

// TODO: �����͸� �̿��� �Լ� �ϼ��ϱ�
// TODO: ���� �޸� �Ҵ� ����ϱ�

/* �α��� ������ �ּҸ� ������ �迭�� �����ϴ� �Լ�
(��: ����Ʈ, 1��: ID, 2��: password)*/
void CopyAddress(char* arr, char** arr_ptr, int size);
/*�α��� ���� �����ϴ� �Լ�*/
void DelLogin(char* site[][CHAR_NUM], char* id[][CHAR_NUM],
              char* password[][CHAR_NUM], int index);

/*�α��� ���� ���� ���α׷�*/
int main(void) {
  int choice;          // ���α�� ���� ��ȣ ���� ����
  int site_count = 0;  // ����Ʈ �� �����ϴ� ����

  // TODO: ������ �迭�� ����ϴµ� �� ������ ��� �����غ���
  char site_name[SITE_NUM][CHAR_NUM];
  char* site_name_ptr[SITE_NUM];
  char id[SITE_NUM][CHAR_NUM];
  char* id_ptr[SITE_NUM];
  char password[SITE_NUM][CHAR_NUM];
  char* password_ptr[SITE_NUM];

  while (1) {
    printf("========================\n");
    printf("--�޴��� �������ּ���.--\n");
    printf(
        "1. �α��� ���� �Է�\n2. �α��� ���� ����\n3. �α��� ���� ����\n4. "
        "��õ ��й�ȣ\n5. ���α׷� ����\n");
    printf("========================\n");
    printf("��ȣ: ");
    scanf_s("%d", &choice);
    /*printf("%d", choice);*/  // ��ȣ ���� Ȯ�� �ڵ�

    if (choice == 1) {
      /*TODO: �̹� ����Ǿ� �ִ� ����Ʈ�� ������ �Է� ���� �ʴ� �ڵ� �ۼ�*/

      /*��� 1. �α��� ���� ����*/
      /*��� 1.1 ����ڷκ��� �α��� ���� �Է� �ޱ�*/
      printf("����Ʈ: ");
      scanf_s("%s", site_name[site_count],
              (int)sizeof(site_name[site_count]));  // TODO: ���� �޸� �Ҵ�
      printf("���̵�: ");
      scanf_s("%s", id[site_count], (int)sizeof(id[site_count]));
      printf("��й�ȣ: ");
      scanf_s("%s", password[site_count], (int)sizeof(password[site_count]));

      // �α��� ���� ���� Ȯ�� �ڵ�
      /*printf("site_name[0]: %s id[0]: %s password[]: %s\n",
         site_name[site_count], id[site_count], password[site_count]);*/

      // �α��� ���� ������ �迭�� ����
      CopyAddress(site_name[site_count], site_name_ptr, site_count);
      CopyAddress(id[site_count], id_ptr, site_count);
      CopyAddress(password[site_count], password_ptr, site_count);

      printf("- ���� �α��� ������ ���� �Ǿ����ϴ� -\n");
      printf("\t����Ʈ: %s\n\t���̵�: %s\n\t��й�ȣ: %s\n",
             *(site_name_ptr + site_count), *(id_ptr + site_count),
             *(password_ptr + site_count));

      site_count++;

    } else if (choice == 2) {
      /*��� 2. �α��� ���� ���*/
      if (site_count == 0) {
        // ����� ������ �ִ��� Ȯ��. ���� ��� ���� ���� ���
        printf("����� �α��� ������ �����ϴ�. �α��� ������ �߰��ϼ���.\n");
      } else {
        /*��� 2.1 ����� ����Ʈ ��� ���*/
        printf("-- ����Ʈ ��� (�� %d) --\n", site_count);

        // ����� ����Ʈ ��� ������� ���
        for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, *(site_name_ptr + i));
          ;
        }

        printf("------------------------\n");

        // ���2�� ���� ��� ��� ���
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
            /*��� 2.2 ��ü ����Ʈ�� �α��� ���� ���*/
            for (int i = 0; i < site_count; i++) {
              printf("%d. ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n", i + 1,
                     site_name[i], id[i], password[i]);
            }
          } else if (choice_2 == 2) {
            /*��� 2.3 Ư�� ����Ʈ�� �α��� ���� ���*/
            int site_choice;
            printf("���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
            scanf_s("%d", &site_choice);
            printf("-> ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n",
                   *(site_name_ptr + site_choice - 1),
                   *(id_ptr + site_choice - 1),
                   *(password_ptr + site_choice - 1));
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

          /*TODO: ��ü ����Ʈ ����� ����ϴ� �ڵ� �Լ�ȭ*/

          // ��ü ����Ʈ ��� ���
          printf("-- ����Ʈ ��� (�� %d) --\n", site_count);
          for (int i = 0; i < site_count; i++) {
            printf("   %d. %s\n", i + 1, *(site_name_ptr + i));
          }

          printf("������ ���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
          scanf_s("%d", &del_index);

          /*TODO: �α��� ���� ���� �ϴ� �ڵ� �ۼ�*/

          // DelLogin(site_name, ID, PW, del_choice);

          printf("'%s'�� �α��� ������ ���������� ���� �Ǿ����ϴ�.\n",
                 site_name[del_index - 1]);
        }

        /*��� 3.2 ��й�ȣ ����*/
        else if (choice_3 == 2) {
          int change_index;  // ������ ����Ʈ�� ��ȣ�� �����ϴ� ����

          // ��ü ����Ʈ ��� ���
          printf("-- ����Ʈ ��� (�� %d) --\n", site_count);
          for (int i = 0; i < site_count; i++) {
            printf("   %d. %s\n", i + 1, site_name[i]);
          }

          // ��й�ȣ�� ������ ����Ʈ�� ��ȣ�� �Է¹ޱ�
          printf("��й�ȣ�� ������ ����Ʈ�� �������ּ���: ");
          scanf_s("%d", &change_index);

          // ������ ����Ʈ�� ���� �α��� ���� ���
          printf("----���� �α��� ����----\n");
          printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
                 site_name[change_index - 1], id[change_index - 1],
                 password[change_index - 1]);
          printf("------------------------\n");

          // ������ ��й�ȣ �Է¹ޱ�
          printf("������ ��й�ȣ�� �Է��ϼ���: ");
          scanf_s("%s", password[change_index - 1],
                  (int)sizeof(password[change_index - 1]));

          // ����� �α��� ���� ���
          printf("---����� �α��� ����---\n");
          printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
                 *(site_name_ptr + change_index - 1),
                 *(id_ptr + change_index - 1),
                 *(password_ptr + change_index - 1));
          printf("------------------------\n");
        } else {
          // ���α�� �������� �̵�
          break;
        }
      }

    } else if (choice == 4) {
      /*��� 4. ��õ ��й�ȣ ����*/

      // ��й�ȣ ��õ�� ����� ���� �迭
      char password_rec[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
      printf("��õ ��й�ȣ: ");

      // �������� ������ ��ġ�� �ε����� �´� ���ڸ� ����� �ݺ��Ͽ� ��õ
      // ��й�ȣ�� ����
      for (int i = 0; i < 10; i++) {
        int random_index = rand() % 26;
        printf("%c", *(password_rec + random_index));

        /*TODO: �빮��, Ư������, ���ڸ� �����Ͽ� ��õ ��й�ȣ ����*/
      }
      printf("\n");
    } else if (choice == 5) {
      /*���α׷� ����*/
      printf("���α׷��� �����մϴ�.");
      break;
    } else {
      // �߸��� ��ȣ �Է½� ���� �޼��� ���
      printf("�߸��� �Է��Դϴ�. 1~5 ������ ��ȣ�� �Է��ϼ���.\n");
    }
  }
  return 0;
}

// TODO: �Լ� ����� �۵��ϵ��� �ϼ���Ű��
void CopyAddress(char* arr, char** arr_ptr, int size) { arr_ptr[size] = arr; }
void DelLogin(char* site[][CHAR_NUM], char* id[][CHAR_NUM],
              char* password[][CHAR_NUM], int index) {}