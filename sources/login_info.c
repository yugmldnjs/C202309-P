#include <stdlib.h>
#include <string.h>
#include "login_info.h"

// �α��� ������ ����ü�� �����ϴ� �Լ� ����
void InitializeLogin(LOGIN* login_info) {
  // ����Ʈ �Է¹ޱ�: temp������ �ӽ������Ͽ� �����Ҵ� �� ����ü�� ����
  printf("����Ʈ: ");
  char temp1[100];
  scanf_s("%s", temp1, (int)sizeof(temp1));
  login_info->site_name = (char*)malloc((strlen(temp1) + 1) * sizeof(char));
  strcpy_s(login_info->site_name, strlen(temp1) + 1, temp1);

  printf("\t");

  printf("���̵�: ");
  char temp2[100];
  scanf_s("%s", temp2, (int)sizeof(temp2));
  login_info->id = (char*)malloc((strlen(temp2) + 1) * sizeof(char));
  strcpy_s(login_info->id, strlen(temp2) + 1, temp2);

  printf("\t");

  printf("��й�ȣ: ");
  char temp3[100];
  scanf_s("%s", temp3, (int)sizeof(temp3));
  login_info->password = (char*)malloc((strlen(temp3) + 1) * sizeof(char));
  strcpy_s(login_info->password, strlen(temp3) + 1, temp3);
}