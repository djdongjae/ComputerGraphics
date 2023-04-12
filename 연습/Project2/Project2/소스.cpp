#include <gl/glut.h>
#include <math.h>

GLfloat theta = 45.0;

GLfloat RotateZ_matrix[4][4] = {
	{cos(theta), -sin(theta), 0.0, 0.0},
	{sin(theta), cos(theta), 0.0, 0.0},
	{0.0, 0.0, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

GLfloat RotateY_matrix[4][4] = {
	{cos(theta), 0.0, sin(theta), 0.0},
	{0.0, 1.0, 0.0, 0.0},
	{-sin(theta), 0.0, cos(theta), 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

GLfloat RotateX_matrix[4][4] = {
	{1.0, 0.0, 0.0, 0.0},
	{0.0, cos(theta), -sin(theta), 0.0},
	{0.0, sin(theta), cos(theta), 0.0},
	{0.0, 0.0, 0.0, 1.0}
};

GLfloat scaleMatrix[4][4] = {
	{2.0, 0.0, 0.0, 0.0},
	{0.0, 2.0, 0.0, 0.0},
	{0.0, 0.0, 2.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}
};


void XYZ()
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

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	XYZ();

	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	//glMultMatrixf((float*)scaleMatrix);
	glRotatef(45, 0, 1, 0);

	glutWireTeapot(0.5);


	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Composite Transformation");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MyDisplay);

	glutMainLoop();

	return 0;
}