#include <stdlib.h>
#include <gl/glut.h>

static int right_shoulder = 0, right_elbow = 0;
static int left_shoulder = 0, left_elbow = 0;
GLboolean isOnXYZ = true, isWireframe = true;

void XYZ(void)
{
    // x 축
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(-100.0f, 0.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);
    glEnd();

    // y 축
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, -100.0f, 0.0f);
    glVertex3f(0.0f, 100.0f, 0.0f);
    glEnd();

    // z 축
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, -100.0f);
    glVertex3f(0.0f, 0.0f, 100.0f);
    glEnd();
}

void MyMenu(int entryId) {
    switch (entryId) {
    case 1:
        isOnXYZ = !isOnXYZ;
        break;
    case 2:
        isWireframe = !isWireframe;
        break;
    case 3:
        exit(0);
        break;
    }

    glutPostRedisplay();
}

void init(void) {
    GLint myMenu = glutCreateMenu(MyMenu);
    glutAddMenuEntry("XYZ Axis On/Off", 1);
    glutAddMenuEntry("Wireframe/Solid", 2);
    glutAddMenuEntry("Exit", 3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    if (isOnXYZ)
        XYZ();
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);	 // Pivot 지정 및 객체 이동
        glRotatef((GLfloat)right_shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
        glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대
            glColor3f(1.0, 1.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            if (isWireframe)
                glutWireCube(1.0);
            else
                glutSolidCube(1.0);
        glPopMatrix();

        glTranslatef(1.0, 0.0, 0.0);	// Pivot 지정 및 객체 이동
        glRotatef((GLfloat)right_elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
        glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대
            glColor3f(1.0, 1.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            if (isWireframe)
                glutWireCube(1.0);
            else
                glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);	 // Pivot 지정 및 객체 이동
        glRotatef((GLfloat)left_shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
        glTranslatef(-1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대
            glColor3f(1.0, 1.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            if (isWireframe)
                glutWireCube(1.0);
            else
                glutSolidCube(1.0);
        glPopMatrix();

        glTranslatef(-1.0, 0.0, 0.0);	// Pivot 지정 및 객체 이동
        glRotatef((GLfloat)left_elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
        glTranslatef(-1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동
        glPushMatrix();	// 원점을 기준으로 객체 생성 및 축소/확대
            glColor3f(1.0, 1.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            if (isWireframe)
                glutWireCube(1.0);
            else
                glutSolidCube(1.0);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's':
        right_shoulder = (right_shoulder + 5) % 360;
        break;
    case 'S':
        right_shoulder = (right_shoulder - 5) % 360;
        break;
    case 'e':
        right_elbow = (right_elbow + 5) % 360;
        break;
    case 'E':
        right_elbow = (right_elbow - 5) % 360;
        break;
    case 'a':
        left_shoulder = (left_shoulder + 5) % 360;
        break;
    case 'A':
        left_shoulder = (left_shoulder - 5) % 360;
        break;
    case 'w':
        left_elbow = (left_elbow + 5) % 360;
        break;
    case 'W':
        left_elbow = (left_elbow - 5) % 360;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}