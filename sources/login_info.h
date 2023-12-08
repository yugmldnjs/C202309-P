/*로그인 정보를 저장하는 구조체*/
typedef struct Login {
  char* site_name;
  char* id;
  char* password;
} LOGIN;

/*로그인 정보를 구조체에 저장하는 함수 선언*/
void InitializeLogin(LOGIN* login_info);
// 사이트명을 구조체 변수에 저장하는 함수 선언
void InitializeSite(LOGIN* login_info);
// 아이디를 구조체 변수에 저장하는 함수	선언
void InitializeId(LOGIN* login_info);
// 비밀번호를 구조체 변수에 저장하는 함수 선언
void InitializePassword(LOGIN* login_info);

/*전체 사이트 목록을 출력하는 함수 선언*/
void PrintSiteList(LOGIN* p_login_info, int site_count, int max_info);

/*로그인 정보를 삭제하는 함수 선언*/
void DelLoginInfo(LOGIN* login_info, int index);

/*비밀번호 변경하는 함수 선언*/
void InitializeNewPassword(LOGIN* login_info);

/*잘못된 번호 입력시 에러 메시지 출력 함수 선언*/
void PrintErrorMessage(int size);