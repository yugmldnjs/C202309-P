/*�α��� ������ �����ϴ� ����ü*/
typedef struct Login {
  char* site_name;
  char* id;
  char* password;
} LOGIN;

/*�α��� ������ ����ü�� �����ϴ� �Լ� ����*/
void InitializeLogin(LOGIN* login_info);
void InitializeSite(LOGIN* login_info);
void InitializeId(LOGIN* login_info);
void InitializePassword(LOGIN* login_info);

/*��ü ����Ʈ ����� ����ϴ� �Լ� ����*/
void PrintSiteList(LOGIN* p_login_info, int site_count);

/*�α��� ������ �����ϴ� �Լ� ����*/
void DelLoginInfo(LOGIN* login_info, int index);

/*��й�ȣ �����ϴ� �Լ� ����*/
void InitializeNewPassword(LOGIN* login_info);