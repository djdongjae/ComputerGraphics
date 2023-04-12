#include <stdlib.h>
#include <gl/glut.h>

GLboolean IsAxis = true;
GLboolean IsWire = true;
static int shoulder1 = 0, elbow1 = 0, shoulder2 = 180, elbow2 = 0; //shoulder1, elbow1 : ø¿∏•∆» & shoulder2, elbow2 : øﬁ∆»

void XYZ() //±‚¡ÿ√‡ ±◊∏Æ±‚
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

void MyMainMenu(int entryID) {
	if (entryID == 1)	exit(0);
}

void MyModelingMenu(int entryID) { // ∏µ®∏µ ∏ﬁ¥∫
	if (entryID == 1)	IsWire = true;
	else if (entryID == 2) IsWire = false;

	glutPostRedisplay();
}

void MyAxisMenu(int entryID) { // ±‚¡ÿ√‡ ¿Øπ´
	if (entryID == 1)	IsAxis = true;
	else if (entryID == 2) IsAxis = false;

	glutPostRedisplay();
}

void MyInit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);

	GLint MyAxisID = glutCreateMenu(MyAxisMenu);
	glutAddMenuEntry("Axis True", 1);
	glutAddMenuEntry("Axis False", 2);

	GLint MyModelingID = glutCreateMenu(MyModelingMenu);
	glutAddMenuEntry("Wire Modeling", 1);
	glutAddMenuEntry("Solid Modeling", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddSubMenu("Modeling mode", MyModelingID);
	glutAddSubMenu("Axis mode", MyAxisID);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	//±‚¡ÿ√‡
	if (IsAxis) {
		XYZ();
	}
	
	//ø¿∏•∆»
	glPushMatrix(); {
		glTranslatef(-1.0, 0.0, 0.0);
		glRotatef((GLfloat)shoulder1, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
	}
		
	glPushMatrix(); {
		glColor3f(1.0, 0.0, 1.0);
		glScalef(2.0, 0.4, 1.0);
		if (IsWire) {
			glutWireCube(1.0);
		}
		else {
			glutSolidCube(1.0);
		}
		
	}
			
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow1, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	
	glPushMatrix(); {
		glColor3f(1.0, 1.0, 0.0);
		glScalef(2.0, 0.4, 1.0);
		if (IsWire) {
			glutWireCube(1.0);
		}
		else {
			glutSolidCube(1.0);
		}
	}
			
	glPopMatrix();
	glPopMatrix();

	//øﬁ∆»
	glPushMatrix(); {
		glTranslatef(-1.0, 0.0, 0.0);
		glRotatef((GLfloat)shoulder2, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
	}

	glPushMatrix(); {
		glColor3f(1.0, 0.0, 1.0);
		glScalef(2.0, 0.4, 1.0);
		if (IsWire) {
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
		glColor3f(1.0, 1.0, 0.0);
		glScalef(2.0, 0.4, 1.0);
		if (IsWire) {
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':// ø¿∏•∆» ¡∂¿€≈∞
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
	case 'J':// øﬁ∆» ¡∂¿€≈∞
		shoulder2 = (shoulder2 + 5) % 360;
		break;
	case 'j':
		shoulder2 = (shoulder2 - 5) % 360;
		break;
	case 'I':
		elbow2 = (elbow2 + 5) % 360;
		break;
	case 'i':
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
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);

	glutMainLoop();
	return 0;
}