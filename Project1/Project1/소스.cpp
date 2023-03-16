#include <gl/glut.h>

GLboolean IsSphere = true;
GLboolean IsSmall = true;
GLboolean IsWire = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.5);

	if ((IsSphere) && (IsSmall) && (IsWire))
		glutWireSphere(0.5, 30, 30);
	else if ((IsSphere) && (!IsSmall) && (IsWire))
		glutWireSphere(0.7, 30, 30);
	else if ((!IsSphere) && (IsSmall) && (IsWire))
		glutWireTorus(0.1, 0.3, 40, 20);
	else if ((!IsSphere) && (!IsSmall) && (IsWire))
		glutWireTorus(0.2, 0.5, 40, 20);
	else if ((IsSphere) && (IsSmall) && (!IsWire))
		glutSolidSphere(0.5, 30, 30);
	else if ((IsSphere) && (!IsSmall) && (!IsWire))
		glutSolidSphere(0.7, 30, 30);
	else if ((!IsSphere) && (IsSmall) && (!IsWire))
		glutSolidTorus(0.1, 0.3, 40, 20);
	else if ((!IsSphere) && (!IsSmall) && (!IsWire))
		glutSolidTorus(0.2, 0.5, 40, 20);
	glFlush();
}

void MyMainMenu(int entryID) {
	if (entryID == 1)	exit(0);
}

void MyModelingMenu(int entryID) {
	if (entryID == 1)	IsWire = true;
	else if (entryID == 2) IsWire = false;

	glutPostRedisplay();
}

void SphereSizeMenu(int entryID) {
	if (entryID == 1) {
		IsSphere = true;
		IsSmall = true;
	}
	else if (entryID == 2) {
		IsSphere = true;
		IsSmall = false;
	}

	glutPostRedisplay();
}

void TorusSizeMenu(int entryID) {
	if (entryID == 1) {
		IsSphere = false;
		IsSmall = true;
	}
	else if (entryID == 2) {
		IsSphere = false;
		IsSmall = false;
	}

	glutPostRedisplay();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MySphereID = glutCreateMenu(SphereSizeMenu);
	glutAddMenuEntry("Small Sphere", 1);
	glutAddMenuEntry("Large Sphere", 2);

	GLint MyTorusID = glutCreateMenu(TorusSizeMenu);
	glutAddMenuEntry("Small Torus", 1);
	glutAddMenuEntry("Large Torus", 2);

	GLint MyModelingID = glutCreateMenu(MyModelingMenu);
	glutAddMenuEntry("Wire Modeling", 1);
	glutAddMenuEntry("Solid Modeling", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Draw Sphere", MySphereID);
	glutAddSubMenu("Draw Torus", MyTorusID);
	glutAddSubMenu("Modeling mode", MyModelingID);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
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