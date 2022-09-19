#include <iostream>
#include "GL\glut.h"
#include "ParticleSpring.h"
#include <ctime>

int width = 600;
int height = 600;

Particle *m_Particles[2];
ParticleStiffSpring *m_StiffSpring;

void Init(void) 
{
	glEnable(GL_DEPTH_TEST);
	
	m_Particles[0] = new Particle();
	m_Particles[1] = new Particle();

	m_Particles[0]->SetPos(Vec3<double>(0.0, 7.0, 0.0));
	m_Particles[0]->SetMass(1.0);
	m_Particles[0]->SetDamping(0.9);

	m_Particles[1]->SetPos(Vec3<double>(0.0, 2.0, 0.0));
	m_Particles[1]->SetMass(1.0);
	m_Particles[1]->SetDamping(0.9);

	m_StiffSpring = new ParticleStiffSpring(m_Particles[0], 1.0, 0.9);
}

void DrawSpring(void)
{
	Vec3<double> p0 = m_Particles[0]->GetPos();
	Vec3<double> p1 = m_Particles[1]->GetPos();


	glPushMatrix();
	glTranslatef(p0.x(), p0.y(), p0.z());
	glutSolidSphere(0.25f, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p1.x(), p1.y(), p1.z());
	glutSolidTeapot(1.0f);
	glPopMatrix();
	
	glLineWidth(2.0f);
	glDisable(GL_LIGHTING);
	glColor3f(0.6f, 0.6f, 0.6f);
	glBegin(GL_LINES);
	glVertex3f(p0.x(), p0.y(), p0.z());
	glVertex3f(p1.x(), p1.y(), p1.z());
	glEnd();
	glEnable(GL_LIGHTING);
	glLineWidth(1.0f);
}

void Darw(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	DrawSpring();
}

void Update(void)
{
	m_StiffSpring->UpdateForce(m_Particles[1], 0.01);
	::glutPostRedisplay();
}

void Display(void)
{
	glClearColor(0.8980392156862745f, 0.9490196078431373f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 4.0, 15.0, 0.0, 4.0, 0.0, 0.0, 1.0, 0.0);
	Darw();
	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	if(w==0) {
		h = 1;
	}
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(float)w/h,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Motion(int x,int y)
{
	glutPostRedisplay();
}

void Mouse(int button,int state,int x,int y)
{
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		m_Particles[1]->m_Force[1] += 20.0;
		break;
	case GLUT_KEY_DOWN:
		m_Particles[1]->m_Force[1] -= 20.0;
		break;
	case GLUT_KEY_RIGHT:
		m_Particles[1]->m_Force[0] += 20.0;
		break;
	case GLUT_KEY_LEFT:
		m_Particles[1]->m_Force[0] -= 20.0;
		break;
	}
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		exit(0);
	}
	glutPostRedisplay();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(width,height);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Adv. Computer Graphics : Basic-Spring");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Update);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialInput);
	Init();
	glutMainLoop();
}

























