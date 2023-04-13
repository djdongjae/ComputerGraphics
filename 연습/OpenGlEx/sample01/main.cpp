#include <gl/glut.h>

GLboolean IsSphere = true;
GLboolean SphereSmall = true;
GLboolean TorusSmall = true;
GLboolean Mode = true; // mode true면 wire 프레임, false면 solid 프레임을 의미한다.

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.5, 0.5);

    if ((IsSphere) && (SphereSmall)) // sphere에 small 이라면
    {
        if (Mode == true)
            glutWireSphere(0.5, 30, 30);
        else if (Mode == false)
            glutSolidSphere(0.5, 30, 30);
    }

    else if ((IsSphere) && (!SphereSmall)) // sphere에 large라면
    {
        if (Mode == true)
            glutWireSphere(0.7, 30, 30); // 와이어

        else if (Mode == false)
            glutSolidSphere(0.7, 30, 30); // 솔리드 모드
    }
    else if ((!IsSphere) && (TorusSmall)) // sphere가 아니고 torus가 small이라면
    {
        if (Mode == true)
            glutWireTorus(0.1, 0.3, 40, 20); // 모드가 true 일경우 wire모드
        else if (Mode == false)
            glutSolidTorus(0.1, 0.3, 40, 20); // false일 경우 solid 모드
    }

    else if ((!IsSphere) && (!TorusSmall)) // sphere가 아니고 torus가 large라면
    {
        if (Mode == true) // mode가 true일경ㅇ
            glutWireTorus(0.2, 0.5, 40, 20);
        else if (Mode == false)
            glutSolidTorus(0.2, 0.5, 40, 20);
    }
    glFlush();
}

void MyMainMenu(int entryID) { // 메인 메뉴 버튼
    if (entryID == 1)           IsSphere = true; // 버튼1을 누르면 sphere가 true
    else if (entryID == 2)      IsSphere = false; // 버튼2를 누르면 sphere가 false
    else if (entryID == 3)       Mode = false; // 3번 누르면 mode = false.
    else if (entryID == 4)       exit(0); // 4번은 exit

    glutPostRedisplay(); // 화면에 구현
}

void MySphereMenu(int entryID) { //Sphere 서브메뉴 버튼
    if (entryID == 1)           SphereSmall = true; // 1번은 small
    else if (entryID == 2)      SphereSmall = false; // 2번은 large

    glutPostRedisplay();
}
void MyTorusMenu(int entryID) { //Torus 서브메뉴 버튼
    if (entryID == 1)           TorusSmall = true; // 1번은 Torusmall = true 
    else if (entryID == 2)      TorusSmall = false;// 2번은 torusamll = false

    glutPostRedisplay();

}

void MyModeMenu(int entryID) { // MyModeMenu  = Mode 버튼
    if (entryID == 1)      Mode = true; // true는 wire 프레임 의미
    else if (entryID == 2)      Mode = false; // false 는 solid 프레임 의미

    glutPostRedisplay();

}
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MySphereID = glutCreateMenu(MySphereMenu); // Sphere 메뉴 정의
    glutAddMenuEntry("Small Sphere", 1); // 밑의 MySphereId의 매개변수로 작동
    glutAddMenuEntry("Large Sphere", 2); // 밑의 Sphere 버튼 클릭시 small sphere, large sphere 나옴


    GLint MyTorusID = glutCreateMenu(MyTorusMenu);
    glutAddMenuEntry("Small Torus", 1); // 밑의 MyTorusid의 매개변수로 작동
    glutAddMenuEntry("Large Torus", 2); // 밑의 Torus 서브버튼 클릭시 small torus, large torus 버튼 나옴

    GLint MyModeID = glutCreateMenu(MyModeMenu); // 해당하는 값 1, 2 를 MyModeMenu 함수에게 전달한다.
    glutAddMenuEntry("Wire frame", 1); // 밑의 MyModeID의 매개변수를 받음 
    glutAddMenuEntry("Solid frame", 2); // 


    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("Sphere", MySphereID); // Sphere 서브메뉴 버튼 등록
    glutAddSubMenu("Torus", MyTorusID); // Torus 서브메뉴 버튼 등록
    glutAddSubMenu("Modeling Mode", MyModeID); // Torus 서브메뉴 버튼 등록
    glutAddMenuEntry("Exit", 4); // 나가기 버튼 등록
    glutAttachMenu(GLUT_RIGHT_BUTTON); // 오른쪽 클릭 버튼으로 작동


}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Menu Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);

    glutMainLoop();
    return 0;
}