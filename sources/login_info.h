/*로그인 정보를 저장하는 구조체*/
typedef struct Login {
  char* site_name;
  char* id;
  char* password;
} LOGIN;

/*로그인 정보를 구조체에 저장하는 함수 선언*/
void InitializeLogin(LOGIN* login_info);

/*전체 사이트 목록을 출력하는 함수 선언*/
void PrintSiteList(LOGIN* p_login_info, int site_count);

/*로그인 정보를 삭제하는 함수 선언*/
void DelLoginInfo(LOGIN* login_info, int index);