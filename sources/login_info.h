/*�α��� ������ �����ϴ� ����ü*/
typedef struct Login {
  char* site_name;
  char* id;
  char* password;
} LOGIN;

/*����Ʈ���� ����ü ������ �����ϴ� �Լ� ����*/
void InitializeSite(LOGIN* login_info);

/*���̵� ����ü ������ �����ϴ� �Լ�	����*/
void InitializeId(LOGIN* login_info);

/*��й�ȣ�� ����ü ������ �����ϴ� �Լ� ����*/
void InitializePassword(LOGIN* login_info);

/*��ü ����Ʈ ����� ����ϴ� �Լ� ����*/
void PrintSiteList(LOGIN* p_login_info, int site_count);

/*�α��� ������ ����ϴ� �Լ� ����*/
void PrintLoginInfo(LOGIN* p_login_info, int site_count, int index);

/*�α��� ������ �����ϴ� �Լ� ����*/
void DelLoginInfo(LOGIN* login_info, int site_count);

/*��й�ȣ �����ϴ� �Լ� ����*/
void InitializeNewPassword(LOGIN* login_info);

/*�߸��� ��ȣ �Է½� ���� �޽��� ��� �Լ� ����*/
void PrintErrorMessage(int size);