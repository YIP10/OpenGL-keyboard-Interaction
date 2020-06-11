#include <stdlib.h>
#include <GL/glut.h>

float a=1,b=1,c=1;
float a1=1,b1=1,c1=1;
float a2=1,b2=1,c2=1;
float j=1,k=1,l=1;
float j1=1,k1=1,l1=1;
float j2=1,k2=1,l2=1;
bool check=true;
float x,y;


void empat () {
	glBegin (GL_QUADS) ;
    glColor3f(a1,b1,c1);
	glVertex2f (50,200) ;
	glVertex2f (190,200) ;
	glVertex2f (190,350) ;
	glVertex2f (50,350) ;
	glEnd ();
}
void empatline () {
	glBegin (GL_QUADS) ;
    glColor3f(j1,k1,l1);
	glVertex2f (51,201) ;
	glVertex2f (189,201) ;
	glVertex2f (189,349) ;
	glVertex2f (51,349) ;
	glEnd ();
}
void empatkanan () {
	glBegin (GL_QUADS) ;
    glColor3f(a,b,c);
	glVertex2f (320,200) ; //garis bawahan,depan garis kiri
	glVertex2f (460,200) ; //garis bawahan
	glVertex2f (460,350) ; //garis pucukan,depan garis kanan
	glVertex2f (320,350) ; //garis pucukan
	glEnd ();
}
void empatkananline () {
	glBegin (GL_QUADS) ;
    glColor3f(j,k,l);
	glVertex2f (321,201) ; //garis bawahan,depan garis kiri
	glVertex2f (459,201) ; //garis bawahan
	glVertex2f (459,349) ; //garis pucukan,depan garis kanan
	glVertex2f (321,349) ; //garis pucukan
	glEnd ();
}

void segitiga () {
	glBegin (GL_POLYGON) ;
    glColor3f(a2,b2,c2);
	glVertex2f (210.,200.) ; //garis bawah terakhir
	glVertex2f (260.,350.) ; //garis pucukan terakhir
	glVertex2f (310.,200.) ;//garis bawah terakhir
	glEnd ();
}
void segitigaline () {
	glBegin (GL_POLYGON) ;
    glColor3f(j2,k2,l2);
	glVertex2f (212.,202.) ; //garis bawah terakhir
	glVertex2f (260.,346.) ; //garis pucukan terakhir
	glVertex2f (308.,202.) ;//garis bawah terakhir
	glEnd ();
}



void kb(unsigned char key, int x, int y){
if(key=='a') a=0,b=1,c=0,a1=0,b1=0,c1=1,a2=1,b2=0,c2=0,j=a,k=b,l=c,j1=a1,k1=b1,l1=c1,j2=a2,k2=b2,l2=c2;
else if(key=='d') a=1,b=1,c=1,a1=1,b1=1,c1=1,a2=1,b2=1,c2=1,j=0,k=0,l=0,j1=0,k1=0,l1=0,j2=0,k2=0,l2=0;
else if(key=='s') a=1,b=1,c=1,a1=1,b1=1,c1=1,a2=1,b2=1,c2=1,j=a,k=b,l=c,j1=a1,k1=b1,l1=c1,j2=a2,k2=b2,l2=c2;
}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check=true;
        x = mousex;
        y = 480-mousey;
        }
glutPostRedisplay();
     }

void timer(int value){
glutPostRedisplay();
glutTimerFunc(10,timer,0);
}

void update(int value){
glutPostRedisplay();
glutTimerFunc(50,update,0);
}

void render () {

    segitiga(); //pemanggil untuk dirender
	empat ();
	empatkanan();
	empatline();
	empatkananline();
	segitigaline();
    glColor3f(1,1,1); // warna dari points
    glPointSize(7); // ukuran points

    glMatrixMode(GL_PROJECTION);// matrix diproyeksikan
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);//pokone orto lah

if(check)
{
       glBegin(GL_POINTS); // buat points
       glVertex2i(x,y);
    glEnd();
}
	glFlush();
	}


	int main (int argc, char **argv)
	{
	glutInit (&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition (100,100);
	glutInitWindowSize (640,480) ; //ukuran dari jendela
	glutCreateWindow ("TUGAS 2 Grafkom 672018219") ;
    glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc (render) ; //yang mau dirender
	glutKeyboardFunc(kb); //fungsi kibot
	glutMouseFunc(mouse); //fungsi mouse
    glutTimerFunc(50,update,0);
	glutMainLoop () ;
	}
