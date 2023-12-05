/*로그인 정보를 저장하는 구조체*/
typedef struct Login {
  char* site_name;
  char* id;
  char* password;
} LOGIN;

/*로그인 정보를 구조체에 저장하는 함수 선언*/
void InitializeLogin(LOGIN* login_info);
