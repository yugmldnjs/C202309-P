#include <stdio.h>
#define SITE_NUM 10
#define CHAR_NUM 100

// TODO: �����͸� �̿��� �Լ� �ϼ��ϱ�

/* �α��� ������ �ּҸ� ������ �迭�� �����ϴ� �Լ�
(��: ����Ʈ, 1��: ID, 2��: password)*/
void CopyAddress(int* arr1, int* arr2, int** arr_ptr);
/*�α��� ���� �����ϴ� �Լ�*/
void DelLogin(char* site[][CHAR_NUM], char* ID[][CHAR_NUM],
              char* PW[][CHAR_NUM], int index);


/*�α��� ���� ���� ���α׷�*/
int main(void) {
  int choice;
  int site_count = 0;

  // TODO: ������ �迭�� ����ϴµ� �� ������ ��� �����غ���
  char site_name[SITE_NUM][CHAR_NUM];
  char* site_name_ptr[SITE_NUM];
  char ID[SITE_NUM][CHAR_NUM];
  char* ID_ptr[SITE_NUM];
  char PW[SITE_NUM][CHAR_NUM];
  char* PW_ptr[SITE_NUM];

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
      /*��� 1. �α��� ���� ����*/
      /*��� 1.1 ����ڷκ��� �α��� ���� �Է� �ޱ�*/
      printf("����Ʈ: ");
      scanf_s("%s", site_name[site_count],
              (int)sizeof(site_name[site_count]));  // TODO: ���� �޸� �Ҵ�
      printf("ID: ");
      scanf_s("%s", ID[site_count], (int)sizeof(ID[site_count]));
      printf("PW: ");
      scanf_s("%s", PW[site_count], (int)sizeof(PW[site_count]));

      printf("����Ʈ: %s ", site_name[site_count]);
      printf("ID: %s ", ID[site_count]);
      printf("PW: %s\n", PW[site_count]);

      CopyAddress(site_name[site_count], site_name_ptr, site_count);
      CopyAddress(ID[site_count], ID_ptr, site_count);
      CopyAddress(PW[site_count], PW_ptr, site_count);

      // printf("ID: %s, PW: %s", login_ptr[site_count][0],
      // login_ptr[site_count][1]);

      printf("����Ʈ: %s ID: %s PW: %s\n", site_name_ptr[site_count],
             ID_ptr[site_count], PW_ptr[site_count]);

      site_count++;

    } else if (choice == 2) {

      /*��� 2. �α��� ���� ���*/
      if (site_count == 0) {  // ����� ������ �ִ��� Ȯ��. ���� ��� ���� ���� ���
        printf("����� �α��� ������ �����ϴ�. �α��� ������ �߰��ϼ���.\n");  
      } else {

        /*��� 2.1 ����� ����Ʈ ��� ���*/
        printf("-- ����Ʈ ��� (�� %d) --\n", site_count);
        for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, site_name[i]);
          
        }
        printf("------------------------\n");
        while (1) {
          int choice_2 = 0;
          printf("------------------------\n");
          printf("���Ͻô� ����� �����ϼ���.\n");
          printf(
              "1. ��ü ����Ʈ �α��� ����\n2. Ư�� ����Ʈ�� �α��� ����\n3. �ڷ� "
              "����\n");
          printf("------------------------\n");
          printf("��ȣ: ");
          scanf_s("%d", &choice_2);
          
          if (choice_2 == 1) {
          /*��� 2.2 ��ü ����Ʈ�� �α��� ���� ���*/
            for (int i = 0; i < site_count; i++) {
            printf("%d. ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n", i+1,
                   site_name[i], ID[i], PW[i]);
             }
          } else if (choice_2 == 2) {
          /*��� 2.3 Ư�� ����Ʈ�� �α��� ���� ���*/
             int site_choice;
             printf("���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
             scanf_s("%d", &site_choice);
             printf("-> ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n",
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
          printf("   %d. %s\n", i + 1, site_name[i]);
          }

          printf("������ ���Ͻô� ����Ʈ�� ��ȣ�� �Է��ϼ���: ");
          scanf_s("%d", &del_index);

          // TODO: �α��� ���� ���� �ϴ� �ڵ� �ۼ�
          
          // DelLogin(site_name, ID, PW, del_choice);
          printf(
              "%s�� �α��� ������ ���������� ���� �Ǿ����ϴ�.", 
              site_name[del_index - 1]);

        }

        /*��� 3.2 ��й�ȣ ����*/
        else if (choice_3 == 2) {
          int change_index;

          // ��ü ����Ʈ ��� ���
          printf("-- ����Ʈ ��� (�� %d) --\n", site_count);
          for (int i = 0; i < site_count; i++) {
          printf("   %d. %s\n", i + 1, site_name[i]);
          }

          printf("��й�ȣ�� ������ ����Ʈ�� �������ּ���: ");
          scanf_s("%d", &change_index);

          // ������ ����Ʈ�� ���� �α��� ���� ���
          printf("----���� �α��� ����----\n");
          printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
                 site_name[change_index - 1], ID[change_index - 1],
                 PW[change_index - 1]);
          printf("------------------------\n");

          printf("������ ��й�ȣ�� �Է��ϼ���: ");
          scanf_s("%s", PW[change_index - 1],
                  (int)sizeof(PW[change_index - 1]));

          // ����� �α��� ���� ���
          printf("---����� �α��� ����---\n");
          printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
                 site_name[change_index - 1], ID[change_index - 1],
                 PW[change_index - 1]);
          printf("------------------------\n");
        } else {
          break;
        }
      }

    } else if (choice == 4) {
      /*��� 4. ��õ ��й�ȣ ����*/
    } else if (choice == 5) {
      /*���α׷� ����*/
      printf("���α׷��� �����մϴ�.");
      break;
    } else {
      printf("�߸��� �Է��Դϴ�. 1~5 ������ ��ȣ�� �Է��ϼ���.\n");
    }
  }
}

// TODO: �Լ� ����� �۵��ϵ��� �ϼ���Ű��
void CopyAddress(char* arr, char** arr_ptr, int size) { arr_ptr[size] = arr; }
void DelLogin(char* site[][CHAR_NUM], char* ID[][CHAR_NUM],
              char* PW[][CHAR_NUM], int index) {}