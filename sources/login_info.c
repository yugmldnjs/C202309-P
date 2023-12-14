#include <stdlib.h>
#include <string.h>
#include "login_info.h"

/*�α��� ������ ����ü�� �����ϴ� �Լ� ����*/
void InitializeLogin(LOGIN* login_info) {
  // ����Ʈ�� ����ü ������ ����
  printf("   ����Ʈ: ");
  InitializeSite(login_info);
  // ���̵� ����ü ������ ����
  printf("   ���̵�: ");
  InitializeId(login_info);
  // ��й�ȣ ����ü ������ ����
  printf("   ��й�ȣ: ");
  InitializePassword(login_info);
}

// ����Ʈ���� ����ü ������ �����ϴ� �Լ� ����
void InitializeSite(LOGIN* login_info) {
  char temp[100]; // �Է¹��� �� �ӽ� ���� ����
  scanf_s("%s", temp, (int)sizeof(temp));

  // �����Ҵ� & ����ü�� ����
  login_info->site_name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(login_info->site_name, strlen(temp) + 1, temp);
}

// ���̵� ����ü ������ �����ϴ� �Լ� ����
void InitializeId(LOGIN* login_info) {
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  login_info->id = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(login_info->id, strlen(temp) + 1, temp);
}

// ��й�ȣ�� ����ü ������ �����ϴ� �Լ� ����
void InitializePassword(LOGIN* login_info) {
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  login_info->password = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(login_info->password, strlen(temp) + 1, temp);
}

/*��ü ����Ʈ ����� ����ϴ� �Լ� ����*/
void PrintSiteList(LOGIN* p_login_info, int site_count) {
  printf("-- ����Ʈ ��� (�� %d) --\n", site_count);
  for (int i = 0; i < site_count; i++) {
    printf("   %d. %s\n", i + 1, p_login_info[i].site_name);
  }
  printf("------------------------\n");
}

/*�α��� ������ ����ϴ� �Լ� ����*/
void PrintLoginInfo(LOGIN* p_login_info, int site_count, int index) {
  if (index == 0) {
    for (int i = 0; i < site_count; i++) {
      printf("%d. ����Ʈ: %s  ���̵�: %s  ��й�ȣ: %s\n", i + 1,
             p_login_info[i].site_name, p_login_info[i].id, p_login_info[i].password);
    }
  } else {
    printf("����Ʈ: %s\n���̵�: %s\n��й�ȣ: %s\n",
           p_login_info[index - 1].site_name, p_login_info[index - 1].id,
           p_login_info[index - 1].password);
    printf("------------------------\n");
  }
}

//TODO: �α��� ���� ���� �Լ� �ϼ�
//TODO: error �ذ�
/*�α��� ������ �����ϴ� �Լ� ����*/
void DelLoginInfo(LOGIN** login_info, int* site_count, int index) {
  *site_count--;
  for (int i = 0; i < site_count; i++) {
    if (i >= index - 1) {
      strcpy_s(login_info[i], sizeof(login_info[i]), login_info[i + 1]);
    } else {
      strcpy_s(login_info[i], sizeof(login_info[i]), login_info[i]);
    }
  }
}

/*��й�ȣ ���� �� ����ü ������ �����ϴ� �Լ� ����*/
void InitializeNewPassword(LOGIN* login_info) {
  // ������ ����Ʈ�� ��й�ȣ �����Ҵ� ����
  free(login_info->password);

  // ���ο� ��й�ȣ �Է¹ޱ�
  printf("���ο� ��й�ȣ�� �Է��ϼ���: ");
  InitializePassword(login_info);
}

/*�߸��� ��ȣ �Է½� ���� �޽��� ��� �Լ� ����*/
void PrintErrorMessage(int size) {
  printf("�߸��� �Է��Դϴ�. 1~%d ������ ��ȣ�� �Է��ϼ���.\n", size);
}