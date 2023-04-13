#include <gl/glut.h>

GLboolean IsSphere = true;
GLboolean SphereSmall = true;
GLboolean TorusSmall = true;
GLboolean Mode = true; // mode true�� wire ������, false�� solid �������� �ǹ��Ѵ�.

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.5, 0.5);

    if ((IsSphere) && (SphereSmall)) // sphere�� small �̶��
    {
        if (Mode == true)
            glutWireSphere(0.5, 30, 30);
        else if (Mode == false)
            glutSolidSphere(0.5, 30, 30);
    }

    else if ((IsSphere) && (!SphereSmall)) // sphere�� large���
    {
        if (Mode == true)
            glutWireSphere(0.7, 30, 30); // ���̾�

        else if (Mode == false)
            glutSolidSphere(0.7, 30, 30); // �ָ��� ���
    }
    else if ((!IsSphere) && (TorusSmall)) // sphere�� �ƴϰ� torus�� small�̶��
    {
        if (Mode == true)
            glutWireTorus(0.1, 0.3, 40, 20); // ��尡 true �ϰ�� wire���
        else if (Mode == false)
            glutSolidTorus(0.1, 0.3, 40, 20); // false�� ��� solid ���
    }

    else if ((!IsSphere) && (!TorusSmall)) // sphere�� �ƴϰ� torus�� large���
    {
        if (Mode == true) // mode�� true�ϰ椷
            glutWireTorus(0.2, 0.5, 40, 20);
        else if (Mode == false)
            glutSolidTorus(0.2, 0.5, 40, 20);
    }
    glFlush();
}

void MyMainMenu(int entryID) { // ���� �޴� ��ư
    if (entryID == 1)           IsSphere = true; // ��ư1�� ������ sphere�� true
    else if (entryID == 2)      IsSphere = false; // ��ư2�� ������ sphere�� false
    else if (entryID == 3)       Mode = false; // 3�� ������ mode = false.
    else if (entryID == 4)       exit(0); // 4���� exit

    glutPostRedisplay(); // ȭ�鿡 ����
}

void MySphereMenu(int entryID) { //Sphere ����޴� ��ư
    if (entryID == 1)           SphereSmall = true; // 1���� small
    else if (entryID == 2)      SphereSmall = false; // 2���� large

    glutPostRedisplay();
}
void MyTorusMenu(int entryID) { //Torus ����޴� ��ư
    if (entryID == 1)           TorusSmall = true; // 1���� Torusmall = true 
    else if (entryID == 2)      TorusSmall = false;// 2���� torusamll = false

    glutPostRedisplay();

}

void MyModeMenu(int entryID) { // MyModeMenu  = Mode ��ư
    if (entryID == 1)      Mode = true; // true�� wire ������ �ǹ�
    else if (entryID == 2)      Mode = false; // false �� solid ������ �ǹ�

    glutPostRedisplay();

}
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MySphereID = glutCreateMenu(MySphereMenu); // Sphere �޴� ����
    glutAddMenuEntry("Small Sphere", 1); // ���� MySphereId�� �Ű������� �۵�
    glutAddMenuEntry("Large Sphere", 2); // ���� Sphere ��ư Ŭ���� small sphere, large sphere ����


    GLint MyTorusID = glutCreateMenu(MyTorusMenu);
    glutAddMenuEntry("Small Torus", 1); // ���� MyTorusid�� �Ű������� �۵�
    glutAddMenuEntry("Large Torus", 2); // ���� Torus �����ư Ŭ���� small torus, large torus ��ư ����

    GLint MyModeID = glutCreateMenu(MyModeMenu); // �ش��ϴ� �� 1, 2 �� MyModeMenu �Լ����� �����Ѵ�.
    glutAddMenuEntry("Wire frame", 1); // ���� MyModeID�� �Ű������� ���� 
    glutAddMenuEntry("Solid frame", 2); // 


    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("Sphere", MySphereID); // Sphere ����޴� ��ư ���
    glutAddSubMenu("Torus", MyTorusID); // Torus ����޴� ��ư ���
    glutAddSubMenu("Modeling Mode", MyModeID); // Torus ����޴� ��ư ���
    glutAddMenuEntry("Exit", 4); // ������ ��ư ���
    glutAttachMenu(GLUT_RIGHT_BUTTON); // ������ Ŭ�� ��ư���� �۵�


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