#include <stdlib.h>
#include <gl/glut.h>

GLboolean isOnXYZ = true;
GLboolean isWireframe = true;
GLboolean isOrthoPerspective = true;
// 왜곡현상 방지를 위한 전역변수
GLfloat width = 800;
GLfloat height = 600;
static int shoulder1 = 0, elbow1 = 0, shoulder2 = 180, elbow2 = 0; //shoulder1, elbow1 : 오른팔 & shoulder2, elbow2 : 왼팔

void MyMenu(int id) {
	switch (id) {
	case 1:
		isOnXYZ = !isOnXYZ;
		break;
	case 2:
		isWireframe = !isWireframe;
		break;
	case 3:
		isOrthoPerspective = !isOrthoPerspective;
		break;
	case 4:
		exit(0);
		break;
	}

	glutPostRedisplay();
}

void init(void) {
	GLint MyMainMenu = glutCreateMenu(MyMenu);
	glutAddMenuEntry("XYZ Axis On/Off", 1);
	glutAddMenuEntry("WireFrame On/Off", 2);
	glutAddMenuEntry("Ortho or Perspective", 3);
	glutAddMenuEntry("exit", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);


}

void XYZ() //기준축 그리기
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-2.0f, 0.0, 0.0);
	glVertex3f(2.0f, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -2.0f, 0.0);
	glVertex3f(0.0, 2.0f, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -2.0f);
	glVertex3f(0.0, 0.0, 2.0f);
	glEnd();
}


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 평행투상 원근투상 교대
	if (isOrthoPerspective)
	{
		// Parallel projection & 왜곡 현상 방지
		glOrtho(-width/800*4, width/800*4, -height/600*4, height/600*4, 0, 5);
	}
	else
	{
		// Perspective projection & 왜곡 현상 방지
		gluPerspective(65.0, width / height, 1.0, 20.0);
	}

	//기준축
	if (isOnXYZ) {
		XYZ();
	}

	//오른팔
	glPushMatrix(); {
		glTranslatef(0.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)shoulder1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
		glTranslatef(1.0, 0.0, 0.0); // Piovt으로 지정할 위치를 원점으로 이동
	}

	glPushMatrix(); { // 원점을 기준으로 객체 생성 및 축소/확대
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.0, 0.4, 1.0);
		if (isWireframe) {
			glutWireCube(1.0);
		}
		else {
			glutSolidCube(1.0);
		}

	}

	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0); // Pivot 지정 및 객체 이동
	glRotatef((GLfloat)elbow1, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
	glTranslatef(1.0, 0.0, 0.0); // Pivot으로 지정할 위치를 원점으로 이동

	glPushMatrix(); { // 원점을 기준으로 객체 생성 및 축소/확대
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.0, 0.4, 1.0);
		if (isWireframe) {
			glutWireCube(1.0);
		}
		else {
			glutSolidCube(1.0);
		}
	}

	glPopMatrix();
	glPopMatrix();

	//왼팔
	glPushMatrix(); {
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef((GLfloat)shoulder2, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
	}

	glPushMatrix(); {
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.0, 0.4, 1.0);
		if (isWireframe) {
			glutWireCube(1.0);
		}
		else {
			glutSolidCube(1.0);
		}
	}

	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow2, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix(); {
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.0, 0.4, 1.0);
		if (isWireframe) {
			glutWireCube(1.0);
		}
		else {
			glutSolidCube(1.0);
		}
	}

	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	// 왜곡 현상 방지를 위한 계산
	width = (GLfloat)w;
	height = (GLfloat)h;
	MyDisplay();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':// 오른팔 조작키
		shoulder1 = (shoulder1 + 5) % 360;
		break;
	case 'S':
		shoulder1 = (shoulder1 - 5) % 360;
		break;
	case 'e':
		elbow1 = (elbow1 + 5) % 360;
		break;
	case 'E':
		elbow1 = (elbow1 - 5) % 360;
		break;
	case 'A':// 왼팔 조작키
		shoulder2 = (shoulder2 + 5) % 360;
		break;
	case 'a':
		shoulder2 = (shoulder2 - 5) % 360;
		break;
	case 'W':
		elbow2 = (elbow2 + 5) % 360;
		break;
	case 'w':
		elbow2 = (elbow2 - 5) % 360;
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
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);

	glutMainLoop();
	return 0;
}