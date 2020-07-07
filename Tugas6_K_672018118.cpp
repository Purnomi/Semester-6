#include <glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void Display()
{
    glLoadIdentity();
       gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}


void init(void){
  glClearColor(0, 0, 0, 0);
   glMatrixMode(GL_PROJECTION);
   glEnable(GL_DEPTH_TEST);
   is_depth=1;
   glMatrixMode(GL_MODELVIEW);
   glPointSize(9.0);
   glLineWidth(6.0f);

   }


   void tampil(void){


       if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);


    //depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-85.0, -45.0, 90.0);
    glVertex3f(-85.0, 25.0, 90.0);
    glVertex3f(85.0, 25.0, 90.0);
    glVertex3f(85.0, -45.0, 90.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-85.0, -45.0, -90.0);
    glVertex3f(-85.0, 25.0, -90.0);
    glVertex3f(85.0, 25.0, -90.0);
    glVertex3f(85.0, -45.0, -90.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(85.0, 25.0, 90.0);
    glVertex3f(85.0, -45.0, 90.0);
    glVertex3f(85.0, -45.0, -90.0);
    glVertex3f(85.0, 25.0, -90.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-85.0, 25.0, 90.0);
    glVertex3f(-85.0, -45.0, 90.0);
    glVertex3f(-85.0, -45.0, -90.0);
    glVertex3f(-85.0, 25.0, -90.0);
    glEnd();

    //Atap
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-90.0, 25.0, 95.0);
    glVertex3f(90.0, 25.0, 95.0);
    glVertex3f(90.0, 25.0, -95.0);
    glVertex3f(-90.0, 25.0, -95.0);
    glEnd();

	//Segitiga Atas Kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-0.0, 20.0 + 70.0, 15.0);
    glVertex3f(90.0, -55.0 + 80.0, 95.0);
    glVertex3f(90.0, -55.0 + 80.0, -95.0);
    glVertex3f(-0.0, 20.0 + 70.0, 15.0);
    glEnd();

	//Segitiga Atas Kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.0,   20.0 + 70.0, 15.0);
    glVertex3f(-90.0, -55.0+ 80.0, 95.0);
    glVertex3f(-90.0, -55.0+ 80.0, -95.0);
    glVertex3f(0.0,   20.0 + 70.0, 15.0);
    glEnd();

	//Segitiga Atas Belakang
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-90.0, 25.0, -95.0);
    glVertex3f(90.0, 25.0, -95.0);
    glVertex3f(0.0, 90.0, 15.0);
    glEnd();

	//Segitiga Atas Depan
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-90.0, 25.0, 95.0);
    glVertex3f(90.0, 25.0, 95.0);
    glVertex3f(0.0, 90.0, 15.0);
    glEnd();

	// CEK POINT //6/24/2020

	//Depan Segitiga Atas 
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-30.0, 25.0, 120.0);
    glVertex3f(30.0, 25.0, 120.0);
    glVertex3f(0.0, 65.0, 115.0);
    glEnd();

	//Depan Kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(0, 65.0, 115.0);
	glVertex3f(0, 65.0, 46.0);
	glVertex3f(36, 25.0, 95.0);
	glVertex3f(30, 25.0, 120.0);
	glEnd();

	//Depan Kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(0, 65.0, 115.0);
	glVertex3f(0, 65.0, 46.0);
	glVertex3f(-36, 25.0, 95.0);
	glVertex3f(-30, 25.0, 120.0);
	glEnd();

	//Atap Depan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30.0, 25.0, 90.0);
    glVertex3f(30.0, 25.0, 90.0);
    glVertex3f(30.0, 25.0, 120.0);
    glVertex3f(-30.0, 25.0, 120.0);
    glEnd();

	//Lantai
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30.0, -40.0, 90.0);
    glVertex3f(30.0, -40.0, 90.0);
    glVertex3f(30.0, -40.0, 120.0);
    glVertex3f(-30.0, -40.0, 120.0);
    glEnd();

	//Lantai Kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(30.0, -45.0, 120.0);
    glVertex3f(30.0, -40.0, 120.0);
    glVertex3f(30.0, -40.0, 90.0);
    glVertex3f(30.0, -45.0, 90.0);
    glEnd();

	//Lantai Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-30.0, -45.0, 120.0);
    glVertex3f(-30.0, -40.0, 120.0);
    glVertex3f(-30.0, -40.0, 90.0);
    glVertex3f(-30.0, -45.0, 90.0);
    glEnd();

	//Lantai Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-30.0, -40.0, 120.0);
    glVertex3f(-30.0, -45.0, 120.0);
    glVertex3f(30.0, -45.0, 120.0);
    glVertex3f(30.0, -40.0, 120.0);
    glEnd();

	//Tangga Lantai
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-30.0, -42.0, 120.0);
    glVertex3f(30.0, -42.0, 120.0);
    glVertex3f(30.0, -42.0, 122.0);
    glVertex3f(-30.0, -42.0, 122.0);
    glEnd();

	//Tangga Kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(30.0, -45.0, 122.0);
    glVertex3f(30.0, -42.0, 122.0);
    glVertex3f(30.0, -42.0, 120.0);
    glVertex3f(30.0, -45.0, 120.0);
    glEnd();

	//Lantai Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-30.0, -45.0, 122.0);
    glVertex3f(-30.0, -42.0, 122.0);
    glVertex3f(-30.0, -42.0, 120.0);
    glVertex3f(-30.0, -45.0, 120.0);
    glEnd();

	//Lantai Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-30.0, -42.0, 122.0);
    glVertex3f(-30.0, -45.0, 122.0);
    glVertex3f(30.0, -45.0, 122.0);
    glVertex3f(30.0, -42.0, 122.0);
    glEnd();

	//Pintu
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-10.0, -40.0, 90.1);
    glVertex3f(-10.0, 10.0, 90.1);
    glVertex3f(10.0, 10.0, 90.1);
    glVertex3f(10.0, -40.0, 90.1);
    glEnd();

	//Jendela Kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-22.0, -30.0, 90.1);
    glVertex3f(-22.0, 10.0, 90.1);
    glVertex3f(-12.0, 10.0, 90.1);
    glVertex3f(-12.0, -30.0, 90.1);
    glEnd();

	//Kaca Jendela Kanan
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-20.0, -25.0, 90.2);
    glVertex3f(-20.0, 5.0, 90.2);
    glVertex3f(-14.0, 5.0, 90.2);
    glVertex3f(-14.0, -25.0, 90.2);
    glEnd();

		//Jendela Kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(22.0, -30.0, 90.1);
    glVertex3f(22.0, 10.0, 90.1);
    glVertex3f(12.0, 10.0, 90.1);
    glVertex3f(12.0, -30.0, 90.1);
    glEnd();

	//Kaca Jendela Kiri
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(20.0, -25.0, 90.2);
    glVertex3f(20.0, 5.0, 90.2);
    glVertex3f(14.0, 5.0, 90.2);
    glVertex3f(14.0, -25.0, 90.2);
    glEnd();

	//Jendela Besar Kanan
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-80.0, -30.0, 90.1);
    glVertex3f(-80.0, 15.0, 90.1);
    glVertex3f(-35.0, 15.0, 90.1);
    glVertex3f(-35.0, -30.0, 90.1);
    glEnd();

	//Kaca Jendela Besar Kiri 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-48.75, -25.0, 90.2);
    glVertex3f(-48.75, 5.0, 90.2);
    glVertex3f(-38.75, 5.0, 90.2);
    glVertex3f(-38.75, -25.0, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-62.5, -25.0, 90.2);
    glVertex3f(-62.5, 5.0, 90.2);
    glVertex3f(-52.5, 5.0, 90.2);
    glVertex3f(-52.5, -25.0, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-76.25, -25.0, 90.2);
    glVertex3f(-76.25, 5.0, 90.2);
    glVertex3f(-66.25, 5.0, 90.2);
    glVertex3f(-66.25, -25.0, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri Kecil 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-48.75, 12.5, 90.2);
    glVertex3f(-48.75, 7.5, 90.2);
    glVertex3f(-38.75, 7.5, 90.2);
    glVertex3f(-38.75, 12.5, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-62.5, 12.5, 90.2);
    glVertex3f(-62.5, 7.5, 90.2);
    glVertex3f(-52.5, 7.5, 90.2);
    glVertex3f(-52.5, 12.5, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-76.25, 12.5, 90.2);
    glVertex3f(-76.25, 7.5, 90.2);
    glVertex3f(-66.25, 7.5, 90.2);
    glVertex3f(-66.25, 12.5, 90.2);
    glEnd();

	//Jendela Besar Kiri
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -30.0, 90.1);
    glVertex3f(80.0, 15.0, 90.1);
    glVertex3f(35.0, 15.0, 90.1);
    glVertex3f(35.0, -30.0, 90.1);
    glEnd();

	//Kaca Jendela Besar Kiri 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(48.75, -25.0, 90.2);
    glVertex3f(48.75, 5.0, 90.2);
    glVertex3f(38.75, 5.0, 90.2);
    glVertex3f(38.75, -25.0, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(62.5, -25.0, 90.2);
    glVertex3f(62.5, 5.0, 90.2);
    glVertex3f(52.5, 5.0, 90.2);
    glVertex3f(52.5, -25.0, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(76.25, -25.0, 90.2);
    glVertex3f(76.25, 5.0, 90.2);
    glVertex3f(66.25, 5.0, 90.2);
    glVertex3f(66.25, -25.0, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri Kecil 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(48.75, 12.5, 90.2);
    glVertex3f(48.75, 7.5, 90.2);
    glVertex3f(38.75, 7.5, 90.2);
    glVertex3f(38.75, 12.5, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(62.5, 12.5, 90.2);
    glVertex3f(62.5, 7.5, 90.2);
    glVertex3f(52.5, 7.5, 90.2);
    glVertex3f(52.5, 12.5, 90.2);
    glEnd();

	//Kaca Jendela Besar Kiri 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(76.25, 12.5, 90.2);
    glVertex3f(76.25, 7.5, 90.2);
    glVertex3f(66.25, 7.5, 90.2);
    glVertex3f(66.25, 12.5, 90.2);
    glEnd();
	
	//Jendela Seblah Kanan Rumah
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(85.1, -30.0, 10.0);
    glVertex3f(85.1, 10.0, 10.0);
    glVertex3f(85.1, 10.0, -10.0);
    glVertex3f(85.1, -30.0, -10.0);
    glEnd();

	//Kaca Jendela Seblah Kanan Rumah
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(85.2, -25.0, 5.0);
    glVertex3f(85.2, 5.0, 5.0);
    glVertex3f(85.2, 5.0, -5.0);
    glVertex3f(85.2, -25.0, -5.0);
    glEnd();

	//Pintu Belakang
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-10.0, -45.0, -90.1);
    glVertex3f(-10.0, 0.0, -90.1);
    glVertex3f(10.0, 0.0, -90.1);
    glVertex3f(10.0, -45.0, -90.1);
    glEnd();

	//Jendela Seblah Kiri Rumah
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-85.1, -30.0, 10.0);
    glVertex3f(-85.1, 10.0, 10.0);
    glVertex3f(-85.1, 10.0, -10.0);
    glVertex3f(-85.1, -30.0, -10.0);
    glEnd();

	//Kaca Jendela Seblah Kiri Rumah
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-85.2, -25.0, 5.0);
    glVertex3f(-85.2, 5.0, 5.0);
    glVertex3f(-85.2, 5.0, -5.0);
    glVertex3f(-85.2, -25.0, -5.0);
    glEnd();

	//KIRI
	//Tiang Kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(28.0, -40.0, 119.0);
    glVertex3f(28.0, 25.0, 119.0);
    glVertex3f(28.0, 25.0, 116.0);
    glVertex3f(28.0, -40.0, 116.0);
    glEnd();

	//Tiang Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(22.0, -40.0, 119.0);
    glVertex3f(22.0, 25.0, 119.0);
    glVertex3f(22.0, 25.0, 116.0);
    glVertex3f(22.0, -40.0, 116.0);
    glEnd();

	//Tiang Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(22.0, -40.0, 119.0);
    glVertex3f(22.0, 25.0, 119.0);
    glVertex3f(28.0, 25.0, 119.0);
    glVertex3f(28.0, -40.0, 119.0);
    glEnd();

	//Tiang Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(22.0, -40.0, 116.0);
    glVertex3f(22.0, 25.0, 116.0);
    glVertex3f(28.0, 25.0, 116.0);
    glVertex3f(28.0, -40.0, 116.0);
    glEnd();

	//KANAN
	//Tiang Kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-28.0, -40.0, 119.0);
    glVertex3f(-28.0, 25.0, 119.0);
    glVertex3f(-28.0, 25.0, 116.0);
    glVertex3f(-28.0, -40.0, 116.0);
    glEnd();

	//Tiang Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-22.0, -40.0, 119.0);
    glVertex3f(-22.0, 25.0, 119.0);
    glVertex3f(-22.0, 25.0, 116.0);
    glVertex3f(-22.0, -40.0, 116.0);
    glEnd();

	//Tiang Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-22.0, -40.0, 119.0);
    glVertex3f(-22.0, 25.0, 119.0);
    glVertex3f(-28.0, 25.0, 119.0);
    glVertex3f(-28.0, -40.0, 119.0);
    glEnd();

	//Tiang Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-22.0, -40.0, 116.0);
    glVertex3f(-22.0, 25.0, 116.0);
    glVertex3f(-28.0, 25.0, 116.0);
    glVertex3f(-28.0, -40.0, 116.0);
    glEnd();

	//ALAS RUMAH
    //glBegin(GL_QUADS);
    //glColor3f(0.1, 0.1, 0.0);
    //glVertex3f(-100.0, -45.0, -100.0);
    //glVertex3f(100.0, -45.0, -100.0);
    //glVertex3f(100.0, -45.0, 130.0);
    //glVertex3f(-100.0, -45.0, 130.0);
    //glEnd();

	//Lantai
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-90.0, -45.1, 95.0);
    glVertex3f(90.0, -45.1, 95.0);
    glVertex3f(90.0, -45.1, -95.0);
    glVertex3f(-90.0, -45.1, -95.0);
    glEnd();


	//--------------------------------------------------------------------------------------------------------------------------------
	
	//1
	//Almari Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-40.0, -44.9, 0.0);
    glVertex3f(40.0, -44.9, 0.0);
    glVertex3f(40.0, -44.9, 15.0);
    glVertex3f(-40.0, -44.9, 15.0);
    glEnd();

	//Almari Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-40.0, 15.0, 0.0);
    glVertex3f(40.0, 15.0, 0.0);
    glVertex3f(40.0, 15.0, 15.0);
    glVertex3f(-40.0, 15.0, 15.0);
    glEnd();

	//Almari Depan
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-40.0, -45.0, 15.0);
    glVertex3f(-40.0, 15.0, 15.0);
    glVertex3f(40.0, 15.0, 15.0);
    glVertex3f(40.0, -45.0, 15.0);
    glEnd();

	//Kaca  Besar Hitam
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(37.0, -25.0, 15.1);
    glVertex3f(37.0, 13.0, 15.1);
    glVertex3f(23.0, 13.0, 15.1);
    glVertex3f(23.0, -25.0, 15.1);
    glEnd();

	//Cermin  Besar
	glBegin(GL_QUADS);
	glColor3f(1.0,1.0,1.0);
    glVertex3f(-37.0, -25.0, 15.1);
    glVertex3f(-37.0, 13.0, 15.1);
    glVertex3f(-23.0, 13.0, 15.1);
    glVertex3f(-23.0, -25.0, 15.1);
    glEnd();

	//Almari Belakang
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-40.0, -45.0, 0.0);
    glVertex3f(-40.0, 15.0, 0.0);
    glVertex3f(40.0, 15.0, 0.0);
    glVertex3f(40.0, -45.0, 0.0);
    glEnd();

	//Almari kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(40.0, 15.0, 15.0);
    glVertex3f(40.0, -45.0, 15.0);
    glVertex3f(40.0, -45.0, 0.0);
    glVertex3f(40.0, 15.0, 0.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);

    glVertex3f(-40.0, 15.0, 15.0);
    glVertex3f(-40.0, -45.0, 15.0);
    glVertex3f(-40.0, -45.0, -0.0);
    glVertex3f(-40.0, 15.0, -0.0);
    glEnd();

	//2

	//Meja Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(-40.0, -25.0, -45.0);
    glVertex3f(40.0, -25.0, -45.0);
    glVertex3f(40.0, -25.0, -5.0);
    glVertex3f(-40.0, -25.0, -5.0);
    glEnd();

	//Meja Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-40.0, -23.0, -45.0);
    glVertex3f(40.0, -23.0, -45.0);
    glVertex3f(40.0, -23.0, -5.0);
    glVertex3f(-40.0, -23.0, -5.0);
    glEnd();

	//Meja kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(40.0, -25.0, -45.0);
    glVertex3f(40.0, -23.0, -45.0);
    glVertex3f(40.0, -23.0, -5.0);
    glVertex3f(40.0, -25.0, -5.0);
    glEnd();

    //Meja kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-40.0, -25.0, -45.0);
    glVertex3f(-40.0, -23.0, -45.0);
    glVertex3f(-40.0, -23.0, -5.0);
    glVertex3f(-40.0, -25.0, -5.0);
    glEnd();
	
	//Meja Depan
	glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-40.0, -25.0, -5.0);
    glVertex3f(-40.0, -23.0, -5.0);
    glVertex3f(40.0, -23.0, -5.0);
    glVertex3f(40.0, -25.0, -5.0);
    glEnd();

	//Meja Belakang
	glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-40.0, -25.0, -45.0);
    glVertex3f(-40.0, -23.0, -45.0);
    glVertex3f(40.0, -23.0, -45.0);
    glVertex3f(40.0, -25.0, -45.0);
    glEnd();

	//Bagian 2
	//Meja kanan 1
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(35.0, -30.0, -40.0);
    glVertex3f(35.0, -25.0, -40.0);
    glVertex3f(35.0, -25.0, -10.0);
    glVertex3f(35.0, -30.0, -10.0);
    glEnd();

	//Meja kanan 2
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.1f, 0.5f);
    glVertex3f(32.0, -30.0, -38.0);
    glVertex3f(32.0, -25.0, -38.0);
    glVertex3f(32.0, -25.0, -12.0);
    glVertex3f(32.0, -30.0, -12.0);
    glEnd();

    //Meja kiri 1
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -25.0, -40.0);
    glVertex3f(-35.0, -25.0, -10.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glEnd();

	//Meja kiri 2
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-32.0, -30.0, -38.0);
    glVertex3f(-32.0, -25.0, -38.0);
    glVertex3f(-32.0, -25.0, -12.0);
    glVertex3f(-32.0, -30.0, -12.0);
    glEnd();
	
	//Meja Depan
	glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -25.0, -10.0);
    glVertex3f(35.0, -25.0, -10.0);
    glVertex3f(35.0, -30.0, -10.0);
    glEnd();

	//Meja Depan 2
	glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-32.0, -30.0, -12.0);
    glVertex3f(-32.0, -25.0, -12.0);
    glVertex3f(32.0, -25.0, -12.0);
    glVertex3f(32.0, -30.0, -12.0);
    glEnd();

	//Meja Belakang
	glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -25.0, -40.0);
    glVertex3f(35.0, -25.0, -40.0);
    glVertex3f(35.0, -30.0, -40.0);
    glEnd();

	//Meja Belakang 2
	glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,0.5f);
    glVertex3f(-32.0, -30.0, -38.0);
    glVertex3f(-32.0, -23.0, -38.0);
    glVertex3f(32.0, -23.0, -38.0);
    glVertex3f(32.0, -30.0, -38.0);
    glEnd();

	//Meja Bawah Kecil
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(35.0, -30.0, -40.0);
    glVertex3f(35.0, -30.0, -10.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glEnd();

	//Meja Bawah Kecil 2
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-33.0, -30.01, -38.0);
    glVertex3f(33.0, -30.01, -38.0);
    glVertex3f(33.0, -30.01, -12.0);
    glVertex3f(-33.0, -30.01, -12.0);
    glEnd();

	//Kaki Meja

	//Kaki Meja Kanan 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -45.0, -12.0);
    glVertex3f(35.0, -30.0, -12.0);
    glVertex3f(35.0, -30.0, -10.0);
    glVertex3f(35.0, -45.0, -10.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -12.0);
    glVertex3f(34.0, -30.0, -12.0);
    glVertex3f(34.0, -30.0, -10.0);
    glVertex3f(34.0, -45.0, -10.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -10.0);
    glVertex3f(34.0, -30.0, -10.0);
    glVertex3f(35.0, -30.0, -10.0);
    glVertex3f(35.0, -45.0, -10.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -12.0);
    glVertex3f(34.0, -30.0, -12.0);
    glVertex3f(35.0, -30.0, -12.0);
    glVertex3f(35.0, -45.0, -12.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -12.0);
    glVertex3f(35.0, -45.0, -12.0);
    glVertex3f(35.0, -45.0, -10.0);
    glVertex3f(34.0, -45.0, -10.0);
    glEnd();

	//Kaki Meja Kanan 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -45.0, -40.0);
    glVertex3f(35.0, -30.0, -40.0);
    glVertex3f(35.0, -30.0, -38.0);
    glVertex3f(35.0, -45.0, -38.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -40.0);
    glVertex3f(34.0, -30.0, -40.0);
    glVertex3f(34.0, -30.0, -38.0);
    glVertex3f(34.0, -45.0, -38.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -38.0);
    glVertex3f(34.0, -30.0, -38.0);
    glVertex3f(35.0, -30.0, -38.0);
    glVertex3f(35.0, -45.0, -38.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -40.0);
    glVertex3f(34.0, -30.0, -40.0);
    glVertex3f(35.0, -30.0, -40.0);
    glVertex3f(35.0, -45.0, -40.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -40.0);
    glVertex3f(35.0, -45.0, -40.0);
    glVertex3f(35.0, -45.0, -38.0);
    glVertex3f(34.0, -45.0, -38.0);
    glEnd();

	//Kaki Meja Kiri 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -12.0);
    glVertex3f(-35.0, -30.0, -12.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-34.0, -30.0, -12.0);
    glVertex3f(-34.0, -30.0, -10.0);
    glVertex3f(-34.0, -45.0, -10.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -10.0);
    glVertex3f(-34.0, -30.0, -10.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-34.0, -30.0, -12.0);
    glVertex3f(-35.0, -30.0, -12.0);
    glVertex3f(-35.0, -45.0, -12.0);
    glEnd();

		//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-35.0, -45.0, -12.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glVertex3f(-34.0, -45.0, -10.0);
    glEnd();

	//Kaki Meja Kiri 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -40.0);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -30.0, -38.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-34.0, -30.0, -40.0);
    glVertex3f(-34.0, -30.0, -38.0);
    glVertex3f(-34.0, -45.0, -38.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -38.0);
    glVertex3f(-34.0, -30.0, -38.0);
    glVertex3f(-35.0, -30.0, -38.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-34.0, -30.0, -40.0);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -45.0, -40.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-35.0, -45.0, -40.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glVertex3f(-34.0, -45.0, -38.0);
    glEnd();

	//Variasi Kanan 1
	//Sebelah 
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -42.0, -38.0);
    glVertex3f(-35.0, -40.0, -38.0);
    glVertex3f(-35.0, -40.0, -12.0);
    glVertex3f(-35.0, -42.0, -12.0);
    glEnd();
	
	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -42.0, -38.0);
    glVertex3f(-34.0, -40.0, -38.0);
    glVertex3f(-34.0, -40.0, -12.0);
    glVertex3f(-34.0, -42.0, -12.0);
    glEnd();

	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(-34.0, -40.0, -38.0);
    glVertex3f(-35.0, -40.0, -38.0);
    glVertex3f(-35.0, -40.0, -12.0);
    glVertex3f(-34.0, -40.0, -12.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -42.0, -38.0);
    glVertex3f(-35.0, -42.0, -38.0);
    glVertex3f(-35.0, -42.0, -12.0);
    glVertex3f(-34.0, -42.0, -12.0);
    glEnd();

	//Kaki 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -40.0, -22.0);
    glVertex3f(-35.0, -30.0, -22.0);
    glVertex3f(-35.0, -30.0, -20.0);
    glVertex3f(-35.0, -40.0, -20.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -22.0);
    glVertex3f(-34.0, -30.0, -22.0);
    glVertex3f(-34.0, -30.0, -20.0);
    glVertex3f(-34.0, -40.0, -20.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -20.0);
    glVertex3f(-34.0, -30.0, -20.0);
    glVertex3f(-35.0, -30.0, -20.0);
    glVertex3f(-35.0, -40.0, -20.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -22.0);
    glVertex3f(-34.0, -30.0, -22.0);
    glVertex3f(-35.0, -30.0, -22.0);
    glVertex3f(-35.0, -40.0, -22.0);
    glEnd();

	//Kaki 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -40.0, -27.0);
    glVertex3f(-35.0, -30.0, -27.0);
    glVertex3f(-35.0, -30.0, -25.0);
    glVertex3f(-35.0, -40.0, -25.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -27.0);
    glVertex3f(-34.0, -30.0, -27.0);
    glVertex3f(-34.0, -30.0, -25.0);
    glVertex3f(-34.0, -40.0, -25.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -25.0);
    glVertex3f(-34.0, -30.0, -25.0);
    glVertex3f(-35.0, -30.0, -25.0);
    glVertex3f(-35.0, -40.0, -25.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -27.0);
    glVertex3f(-34.0, -30.0, -27.0);
    glVertex3f(-35.0, -30.0, -27.0);
    glVertex3f(-35.0, -40.0, -27.0);
    glEnd();

	//Kaki 3
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -40.0, -32.0);
    glVertex3f(-35.0, -30.0, -32.0);
    glVertex3f(-35.0, -30.0, -30.0);
    glVertex3f(-35.0, -40.0, -30.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -32.0);
    glVertex3f(-34.0, -30.0, -32.0);
    glVertex3f(-34.0, -30.0, -30.0);
    glVertex3f(-34.0, -40.0, -30.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -30.0);
    glVertex3f(-34.0, -30.0, -30.0);
    glVertex3f(-35.0, -30.0, -30.0);
    glVertex3f(-35.0, -40.0, -30.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -40.0, -32.0);
    glVertex3f(-34.0, -30.0, -32.0);
    glVertex3f(-35.0, -30.0, -32.0);
    glVertex3f(-35.0, -40.0, -32.0);
    glEnd();

	//Variasi Kanan 
	//Sebelah 
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -42.0, -38.0);
    glVertex3f(35.0, -40.0, -38.0);
    glVertex3f(35.0, -40.0, -12.0);
    glVertex3f(35.0, -42.0, -12.0);
    glEnd();
	
	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -42.0, -38.0);
    glVertex3f(34.0, -40.0, -38.0);
    glVertex3f(34.0, -40.0, -12.0);
    glVertex3f(34.0, -42.0, -12.0);
    glEnd();

	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(34.0, -40.0, -38.0);
    glVertex3f(35.0, -40.0, -38.0);
    glVertex3f(35.0, -40.0, -12.0);
    glVertex3f(34.0, -40.0, -12.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -42.0, -38.0);
    glVertex3f(35.0, -42.0, -38.0);
    glVertex3f(35.0, -42.0, -12.0);
    glVertex3f(34.0, -42.0, -12.0);
    glEnd();

	//Kaki 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -40.0, -22.0);
    glVertex3f(35.0, -30.0, -22.0);
    glVertex3f(35.0, -30.0, -20.0);
    glVertex3f(35.0, -40.0, -20.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -22.0);
    glVertex3f(34.0, -30.0, -22.0);
    glVertex3f(34.0, -30.0, -20.0);
    glVertex3f(34.0, -40.0, -20.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -20.0);
    glVertex3f(34.0, -30.0, -20.0);
    glVertex3f(35.0, -30.0, -20.0);
    glVertex3f(35.0, -40.0, -20.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -22.0);
    glVertex3f(34.0, -30.0, -22.0);
    glVertex3f(35.0, -30.0, -22.0);
    glVertex3f(35.0, -40.0, -22.0);
    glEnd();

	//Kaki 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -40.0, -27.0);
    glVertex3f(35.0, -30.0, -27.0);
    glVertex3f(35.0, -30.0, -25.0);
    glVertex3f(35.0, -40.0, -25.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -27.0);
    glVertex3f(34.0, -30.0, -27.0);
    glVertex3f(34.0, -30.0, -25.0);
    glVertex3f(34.0, -40.0, -25.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -25.0);
    glVertex3f(34.0, -30.0, -25.0);
    glVertex3f(35.0, -30.0, -25.0);
    glVertex3f(35.0, -40.0, -25.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -27.0);
    glVertex3f(34.0, -30.0, -27.0);
    glVertex3f(35.0, -30.0, -27.0);
    glVertex3f(35.0, -40.0, -27.0);
    glEnd();

	//Kaki 3
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -40.0, -32.0);
    glVertex3f(35.0, -30.0, -32.0);
    glVertex3f(35.0, -30.0, -30.0);
    glVertex3f(35.0, -40.0, -30.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -32.0);
    glVertex3f(34.0, -30.0, -32.0);
    glVertex3f(34.0, -30.0, -30.0);
    glVertex3f(34.0, -40.0, -30.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -30.0);
    glVertex3f(34.0, -30.0, -30.0);
    glVertex3f(35.0, -30.0, -30.0);
    glVertex3f(35.0, -40.0, -30.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -40.0, -32.0);
    glVertex3f(34.0, -30.0, -32.0);
    glVertex3f(35.0, -30.0, -32.0);
    glVertex3f(35.0, -40.0, -32.0);
    glEnd();
	
	//Tengah
	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -42.0, -25.0);
    glVertex3f(-34.0, -40.0, -25.0);
    glVertex3f(35.0, -40.0, -25.0);
    glVertex3f(35.0, -42.0, -25.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -42.0, -27.0);
    glVertex3f(-34.0, -40.0, -27.0);
    glVertex3f(35.0, -40.0, -27.0);
    glVertex3f(35.0, -42.0, -27.0);
    glEnd();

	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(-34.0, -40.0, -27.0);
    glVertex3f(35.0, -40.0, -27.0);
    glVertex3f(35.0, -40.0, -25.0);
    glVertex3f(-34.0, -40.0, -25.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -42.0, -27.0);
    glVertex3f(35.0, -42.0, -27.0);
    glVertex3f(35.0, -42.0, -25.0);
    glVertex3f(-34.0, -42.0, -25.0);
    glEnd();


	//3
	//Kursi
	
	//Kaki Kanan 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -45.0, -52.0);
    glVertex3f(35.0, -30.0, -52.0);
    glVertex3f(35.0, -30.0, -50.0);
    glVertex3f(35.0, -45.0, -50.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -52.0);
    glVertex3f(34.0, -30.0, -52.0);
    glVertex3f(34.0, -30.0, -50.0);
    glVertex3f(34.0, -45.0, -50.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -50.0);
    glVertex3f(34.0, -30.0, -50.0);
    glVertex3f(35.0, -30.0, -50.0);
    glVertex3f(35.0, -45.0, -50.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -52.0);
    glVertex3f(34.0, -30.0, -52.0);
    glVertex3f(35.0, -30.0, -52.0);
    glVertex3f(35.0, -45.0, -52.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -52.0);
    glVertex3f(35.0, -45.0, -52.0);
    glVertex3f(35.0, -45.0, -50.0);
    glVertex3f(34.0, -45.0, -50.0);
    glEnd();

	//Kaki Meja Kanan 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(35.0, -15.0, -60.0);
    glVertex3f(35.0, -45.0, -60.0);
    glVertex3f(35.0, -45.0, -58.0);
    glVertex3f(35.0, -15.0, -58.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -15.0, -60.0);
    glVertex3f(34.0, -45.0, -60.0);
    glVertex3f(34.0, -45.0, -58.0);
    glVertex3f(34.0, -15.0, -58.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -15.0, -58.0);
    glVertex3f(34.0, -45.0, -58.0);
    glVertex3f(35.0, -45.0, -58.0);
    glVertex3f(35.0, -15.0, -58.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -15.0, -60.0);
    glVertex3f(34.0, -45.0, -60.0);
    glVertex3f(35.0, -45.0, -60.0);
    glVertex3f(35.0, -15.0, -60.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(34.0, -45.0, -60.0);
    glVertex3f(35.0, -45.0, -60.0);
    glVertex3f(35.0, -45.0, -58.0);
    glVertex3f(34.0, -45.0, -58.0);
    glEnd();

	//Kaki Kiri 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -12.0);
    glVertex3f(-35.0, -30.0, -12.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-34.0, -30.0, -12.0);
    glVertex3f(-34.0, -30.0, -10.0);
    glVertex3f(-34.0, -45.0, -10.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -10.0);
    glVertex3f(-34.0, -30.0, -10.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-34.0, -30.0, -12.0);
    glVertex3f(-35.0, -30.0, -12.0);
    glVertex3f(-35.0, -45.0, -12.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-35.0, -45.0, -12.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glVertex3f(-34.0, -45.0, -10.0);
    glEnd();

	//Kaki Kiri 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -40.0);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -30.0, -38.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-34.0, -30.0, -40.0);
    glVertex3f(-34.0, -30.0, -38.0);
    glVertex3f(-34.0, -45.0, -38.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -38.0);
    glVertex3f(-34.0, -30.0, -38.0);
    glVertex3f(-35.0, -30.0, -38.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-34.0, -30.0, -40.0);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -45.0, -40.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-35.0, -45.0, -40.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glVertex3f(-34.0, -45.0, -38.0);
    glEnd();


	//Kaki Kiri 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -52.0);
    glVertex3f(-35.0, -30.0, -52.0);
    glVertex3f(-35.0, -30.0, -50.0);
    glVertex3f(-35.0, -45.0, -50.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -52.0);
    glVertex3f(-34.0, -30.0, -52.0);
    glVertex3f(-34.0, -30.0, -50.0);
    glVertex3f(-34.0, -45.0, -50.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -50.0);
    glVertex3f(-34.0, -30.0, -50.0);
    glVertex3f(-35.0, -30.0, -50.0);
    glVertex3f(-35.0, -45.0, -50.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -52.0);
    glVertex3f(-34.0, -30.0, -52.0);
    glVertex3f(-35.0, -30.0, -52.0);
    glVertex3f(-35.0, -45.0, -52.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -52.0);
    glVertex3f(-35.0, -45.0, -52.0);
    glVertex3f(-35.0, -45.0, -50.0);
    glVertex3f(-34.0, -45.0, -50.0);
    glEnd();

	//Kaki  Kanan 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -15.0, -60.0);
    glVertex3f(-35.0, -45.0, -60.0);
    glVertex3f(-35.0, -45.0, -58.0);
    glVertex3f(-35.0, -15.0, -58.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -15.0, -60.0);
    glVertex3f(-34.0, -45.0, -60.0);
    glVertex3f(-34.0, -45.0, -58.0);
    glVertex3f(-34.0, -15.0, -58.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -15.0, -58.0);
    glVertex3f(-34.0, -45.0, -58.0);
    glVertex3f(-35.0, -45.0, -58.0);
    glVertex3f(-35.0, -15.0, -58.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -15.0, -60.0);
    glVertex3f(-34.0, -45.0, -60.0);
    glVertex3f(-35.0, -45.0, -60.0);
    glVertex3f(-35.0, -15.0, -60.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -60.0);
    glVertex3f(-35.0, -45.0, -60.0);
    glVertex3f(-35.0, -45.0, -58.0);
    glVertex3f(-34.0, -45.0, -58.0);
    glEnd();

	//Kaki Meja Kiri 1
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -12.0);
    glVertex3f(-35.0, -30.0, -12.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-34.0, -30.0, -12.0);
    glVertex3f(-34.0, -30.0, -10.0);
    glVertex3f(-34.0, -45.0, -10.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -10.0);
    glVertex3f(-34.0, -30.0, -10.0);
    glVertex3f(-35.0, -30.0, -10.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-34.0, -30.0, -12.0);
    glVertex3f(-35.0, -30.0, -12.0);
    glVertex3f(-35.0, -45.0, -12.0);
    glEnd();

		//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -12.0);
    glVertex3f(-35.0, -45.0, -12.0);
    glVertex3f(-35.0, -45.0, -10.0);
    glVertex3f(-34.0, -45.0, -10.0);
    glEnd();

	//Kaki Kiri 2
	//Kanan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-35.0, -45.0, -40.0);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -30.0, -38.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-34.0, -30.0, -40.0);
    glVertex3f(-34.0, -30.0, -38.0);
    glVertex3f(-34.0, -45.0, -38.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -38.0);
    glVertex3f(-34.0, -30.0, -38.0);
    glVertex3f(-35.0, -30.0, -38.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-34.0, -30.0, -40.0);
    glVertex3f(-35.0, -30.0, -40.0);
    glVertex3f(-35.0, -45.0, -40.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -45.0, -40.0);
    glVertex3f(-35.0, -45.0, -40.0);
    glVertex3f(-35.0, -45.0, -38.0);
    glVertex3f(-34.0, -45.0, -38.0);
    glEnd();

	//Papan Duduk
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -30.1, -60.0);
    glVertex3f(35.0, -30.1, -60.0);
    glVertex3f(35.0, -30.1, -49.0);
    glVertex3f(-34.0, -30.1, -49.0);
    glEnd();

	//Papan Duduk2
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -30.51, -60.0);
    glVertex3f(35.0, -30.51, -60.0);
    glVertex3f(35.0, -30.51, -49.0);
    glVertex3f(-34.0, -30.51, -49.0);
    glEnd();

	//Punggung
	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -25.0, -59.5);
    glVertex3f(-34.0, -13.0, -59.5);
    glVertex3f(35.0, -13.0, -59.5);
    glVertex3f(35.0, -25.0, -59.5);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -25.0, -59.0);
    glVertex3f(-34.0, -13.0, -59.0);
    glVertex3f(35.0, -13.0, -59.0);
    glVertex3f(35.0, -25.0, -59.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -25.0, -59.5);
    glVertex3f(35.0, -25.0, -59.5);
    glVertex3f(35.0, -25.0, -59.0);
    glVertex3f(-34.0, -25.0, -59.0);
    glEnd();

	//Atas
	glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.5f);
    glVertex3f(-34.0, -13.0, -59.5);
    glVertex3f(35.0, -13.0, -59.5);
    glVertex3f(35.0, -13.0, -59.0);
    glVertex3f(-34.0, -13.0, -59.0);
    glEnd();


	//4
	//Meja Kaca
	
	//Atasyaa meja
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-80.0, -31.99, 35.0);
    glVertex3f(-60.0, -31.99, 35.0);
    glVertex3f(-60.0, -31.99, 70.0);
    glVertex3f(-80.0, -31.99, 70.0);
    glEnd();

	//Meja kanan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-60.0, -35.0, 80.0);
    glVertex3f(-60.0, -32.0, 80.0);
    glVertex3f(-60.0, -32.0, 45.0);
    glVertex3f(-60.0, -35.0, 45.0);
    glEnd();

    //Meja kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -35.0, 80.0);
    glVertex3f(-80.0, -32.0, 80.0);
    glVertex3f(-80.0, -32.0, 45.0);
    glVertex3f(-80.0, -35.0, 45.0);
    glEnd();
	
	//Meja Depan
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -35.0, 45.0);
    glVertex3f(-80.0, -32.0, 45.0);
    glVertex3f(-60.0, -32.0, 45.0);
    glVertex3f(-60.0, -35.0, 45.0);
    glEnd();

	//Meja Belakang
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -35.0, 80.0);
    glVertex3f(-80.0, -32.0, 80.0);
    glVertex3f(-60.0, -32.0, 80.0);
    glVertex3f(-60.0, -35.0, 80.0);
    glEnd();
	
	//Meja Besar
	//Meja Atas
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -35.0, 45.0);
    glVertex3f(-60.0, -35.0, 45.0);
    glVertex3f(-60.0, -35.0, 80.0);
    glVertex3f(-80.0, -35.0, 80.0);
    glEnd();

	//Meja Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -40.0, 45.0);
    glVertex3f(-60.0, -40.0, 45.0);
    glVertex3f(-60.0, -40.0, 80.0);
    glVertex3f(-80.0, -40.0, 80.0);
    glEnd();

	//Meja kanan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-60.0, -40.0, 80.0);
    glVertex3f(-60.0, -35.0, 80.0);
    glVertex3f(-60.0, -35.0, 45.0);
    glVertex3f(-60.0, -40.0, 45.0);
    glEnd();

    //Meja kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -40.0, 80.0);
    glVertex3f(-80.0, -35.0, 80.0);
    glVertex3f(-80.0, -35.0, 45.0);
    glVertex3f(-80.0, -40.0, 45.0);
    glEnd();
	
	//Meja Depan
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -40.0, 45.0);
    glVertex3f(-80.0, -35.0, 45.0);
    glVertex3f(-60.0, -35.0, 45.0);
    glVertex3f(-60.0, -40.0, 45.0);
    glEnd();

	//Meja Belakang
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -40.0, 80.0);
    glVertex3f(-80.0, -35.0, 80.0);
    glVertex3f(-60.0, -35.0, 80.0);
    glVertex3f(-60.0, -40.0, 80.0);
    glEnd();

	//Kaki Meja Kaca

	//Kaki Meja Kanan 1
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-60.0, -45.0, 47.0);
    glVertex3f(-60.0, -40.0, 47.0);
    glVertex3f(-60.0, -40.0, 45.0);
    glVertex3f(-60.0, -45.0, 45.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 47.0);
    glVertex3f(-61.0, -40.0, 47.0);
    glVertex3f(-61.0, -40.0, 45.0);
    glVertex3f(-61.0, -45.0, 45.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 45.0);
    glVertex3f(-61.0, -40.0, 45.0);
    glVertex3f(-60.0, -40.0, 45.0);
    glVertex3f(-60.0, -45.0, 45.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 47.0);
    glVertex3f(-61.0, -40.0, 47.0);
    glVertex3f(-60.0, -40.0, 47.0);
    glVertex3f(-60.0, -45.0, 47.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 47.0);
    glVertex3f(-60.0, -45.0, 47.0);
    glVertex3f(-60.0, -45.0, 45.0);
    glVertex3f(-61.0, -45.0, 45.0);
    glEnd();

	//Kaki Meja Kanan 2
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-60.0, -45.0, 80.0);
    glVertex3f(-60.0, -40.0, 80.0);
    glVertex3f(-60.0, -40.0, 78.0);
    glVertex3f(-60.0, -45.0, 78.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 80.0);
    glVertex3f(-61.0, -40.0, 80.0);
    glVertex3f(-61.0, -40.0, 78.0);
    glVertex3f(-61.0, -45.0, 78.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 78.0);
    glVertex3f(-61.0, -40.0, 78.0);
    glVertex3f(-60.0, -40.0, 78.0);
    glVertex3f(-60.0, -45.0, 78.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 80.0);
    glVertex3f(-61.0, -40.0, 80.0);
    glVertex3f(-60.0, -40.0, 80.0);
    glVertex3f(-60.0, -45.0, 80.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-61.0, -45.0, 80.0);
    glVertex3f(-60.0, -45.0, 80.0);
    glVertex3f(-60.0, -45.0, 78.0);
    glVertex3f(-61.0, -45.0, 78.0);
    glEnd();

	//Kaki Meja Kiri 1
		//Kanan
    glBegin(GL_QUADS);
	glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-79.0, -45.0, 47.0);
    glVertex3f(-79.0, -40.0, 47.0);
    glVertex3f(-79.0, -40.0, 45.0);
    glVertex3f(-79.0, -45.0, 45.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 47.0);
    glVertex3f(-80.0, -40.0, 47.0);
    glVertex3f(-80.0, -40.0, 45.0);
    glVertex3f(-80.0, -45.0, 45.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 45.0);
    glVertex3f(-80.0, -40.0, 45.0);
    glVertex3f(-79.0, -40.0, 45.0);
    glVertex3f(-79.0, -45.0, 45.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 47.0);
    glVertex3f(-80.0, -40.0, 47.0);
    glVertex3f(-79.0, -40.0, 47.0);
    glVertex3f(-79.0, -45.0, 47.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 47.0);
    glVertex3f(-79.0, -45.0, 47.0);
    glVertex3f(-79.0, -45.0, 45.0);
    glVertex3f(-80.0, -45.0, 45.0);
    glEnd();

	//Kaki Meja Kanan 2
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-79.0, -45.0, 80.0);
    glVertex3f(-79.0, -40.0, 80.0);
    glVertex3f(-79.0, -40.0, 78.0);
    glVertex3f(-79.0, -45.0, 78.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 80.0);
    glVertex3f(-80.0, -40.0, 80.0);
    glVertex3f(-80.0, -40.0, 78.0);
    glVertex3f(-80.0, -45.0, 78.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 78.0);
    glVertex3f(-80.0, -40.0, 78.0);
    glVertex3f(-79.0, -40.0, 78.0);
    glVertex3f(-79.0, -45.0, 78.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 80.0);
    glVertex3f(-80.0, -40.0, 80.0);
    glVertex3f(-79.0, -40.0, 80.0);
    glVertex3f(-79.0, -45.0, 80.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(-80.0, -45.0, 80.0);
    glVertex3f(-79.0, -45.0, 80.0);
    glVertex3f(-79.0, -45.0, 78.0);
    glVertex3f(-80.0, -45.0, 78.0);
    glEnd();

	//5
	//Meja Kayu

	//Atasyaa meja
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -32.0, 40.0);
    glVertex3f(60.0, -32.0, 40.0);
    glVertex3f(60.0, -32.0, 89.0);
    glVertex3f(80.0, -32.0, 89.0);
    glEnd();

	//Meja kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(60.0, -34.0, 89.0);
    glVertex3f(60.0, -32.0, 89.0);
    glVertex3f(60.0, -32.0, 40.0);
    glVertex3f(60.0, -34.0, 40.0);
    glEnd();

    //Meja kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -34.0, 89.0);
    glVertex3f(80.0, -32.0, 89.0);
    glVertex3f(80.0, -32.0, 40.0);
    glVertex3f(80.0, -34.0, 40.0);
    glEnd();
	
	//Meja Depan
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -34.0, 40.0);
    glVertex3f(80.0, -32.0, 40.0);
    glVertex3f(60.0, -32.0, 40.0);
    glVertex3f(60.0, -34.0, 40.0);
    glEnd();

	//Meja Belakang
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -34.0, 89.0);
    glVertex3f(80.0, -32.0, 89.0);
    glVertex3f(60.0, -32.0, 89.0);
    glVertex3f(60.0, -34.0, 89.0);
    glEnd();
	
	//Meja Besar
	//Meja Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -34.0, 42.0);
    glVertex3f(60.0, -34.0, 42.0);
    glVertex3f(60.0, -34.0, 88.0);
    glVertex3f(80.0, -34.0, 88.0);
    glEnd();

	//Meja Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(80.0, -37.0, 44.0);
    glVertex3f(60.0, -37.0, 44.0);
    glVertex3f(60.0, -37.0, 86.0);
    glVertex3f(80.0, -37.0, 86.0);
    glEnd();

	//Meja kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(60.0, -37.0, 88.0);
    glVertex3f(60.0, -34.0, 88.0);
    glVertex3f(60.0, -34.0, 42.0);
    glVertex3f(60.0, -37.0, 42.0);
    glEnd();

    //Meja kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -37.0, 88.0);
    glVertex3f(80.0, -34.0, 88.0);
    glVertex3f(80.0, -34.0, 42.0);
    glVertex3f(80.0, -37.0, 42.0);
    glEnd();
	
	//Meja Depan
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -37.0, 42.0);
    glVertex3f(80.0, -34.0, 42.0);
    glVertex3f(60.0, -34.0, 42.0);
    glVertex3f(60.0, -37.0, 42.0);
    glEnd();

	//Meja Belakang
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -37.0, 88.0);
    glVertex3f(80.0, -34.0, 88.0);
    glVertex3f(60.0, -34.0, 88.0);
    glVertex3f(60.0, -37.0, 88.0);
    glEnd();

	//Kaki Meja Kayu

	//Kaki Meja Kanan 1
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(60.0, -45.0, 44.0);
    glVertex3f(60.0, -37.0, 44.0);
    glVertex3f(60.0, -37.0, 42.0);
    glVertex3f(60.0, -45.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 44.0);
    glVertex3f(61.0, -37.0, 44.0);
    glVertex3f(61.0, -37.0, 42.0);
    glVertex3f(61.0, -45.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 42.0);
    glVertex3f(61.0, -37.0, 42.0);
    glVertex3f(60.0, -37.0, 42.0);
    glVertex3f(60.0, -45.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 44.0);
    glVertex3f(61.0, -37.0, 44.0);
    glVertex3f(60.0, -37.0, 44.0);
    glVertex3f(60.0, -45.0, 44.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 44.0);
    glVertex3f(60.0, -45.0, 44.0);
    glVertex3f(60.0, -45.0, 42.0);
    glVertex3f(61.0, -45.0, 42.0);
    glEnd();

	//Kaki Meja Kanan 2
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(60.0, -45.0, 88.0);
    glVertex3f(60.0, -37.0, 88.0);
    glVertex3f(60.0, -37.0, 86.0);
    glVertex3f(60.0, -45.0, 86.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 88.0);
    glVertex3f(61.0, -37.0, 88.0);
    glVertex3f(61.0, -37.0, 86.0);
    glVertex3f(61.0, -45.0, 86.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 86.0);
    glVertex3f(61.0, -37.0, 86.0);
    glVertex3f(60.0, -37.0, 86.0);
    glVertex3f(60.0, -45.0, 86.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 88.0);
    glVertex3f(61.0, -37.0, 88.0);
    glVertex3f(60.0, -37.0, 88.0);
    glVertex3f(60.0, -45.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -45.0, 88.0);
    glVertex3f(60.0, -45.0, 88.0);
    glVertex3f(60.0, -45.0, 86.0);
    glVertex3f(61.0, -45.0, 86.0);
    glEnd();

	//Kaki Kiri
	//Kiri 1
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -45.0, 44.0);
    glVertex3f(79.0, -37.0, 44.0);
    glVertex3f(79.0, -37.0, 42.0);
    glVertex3f(79.0, -45.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 44.0);
    glVertex3f(80.0, -37.0, 44.0);
    glVertex3f(80.0, -37.0, 42.0);
    glVertex3f(80.0, -45.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 42.0);
    glVertex3f(80.0, -37.0, 42.0);
    glVertex3f(79.0, -37.0, 42.0);
    glVertex3f(79.0, -45.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 44.0);
    glVertex3f(80.0, -37.0, 44.0);
    glVertex3f(79.0, -37.0, 44.0);
    glVertex3f(79.0, -45.0, 44.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 44.0);
    glVertex3f(80.0, -45.0, 44.0);
    glVertex3f(79.0, -45.0, 42.0);
    glVertex3f(79.0, -45.0, 42.0);
    glEnd();

	//Kaki Meja Kanan 2
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -45.0, 88.0);
    glVertex3f(79.0, -37.0, 88.0);
    glVertex3f(79.0, -37.0, 86.0);
    glVertex3f(79.0, -45.0, 86.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 88.0);
    glVertex3f(80.0, -37.0, 88.0);
    glVertex3f(80.0, -37.0, 86.0);
    glVertex3f(80.0, -45.0, 86.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 86.0);
    glVertex3f(80.0, -37.0, 86.0);
    glVertex3f(79.0, -37.0, 86.0);
    glVertex3f(79.0, -45.0, 86.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 88.0);
    glVertex3f(80.0, -37.0, 88.0);
    glVertex3f(79.0, -37.0, 88.0);
    glVertex3f(79.0, -45.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -45.0, 88.0);
    glVertex3f(79.0, -45.0, 88.0);
    glVertex3f(79.0, -45.0, 86.0);
    glVertex3f(80.0, -45.0, 86.0);
    glEnd();

	//Depan Kiri
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -43.0, 42.0);
    glVertex3f(60.0, -43.0, 42.0);
    glVertex3f(60.0, -43.0, 88.0);
    glVertex3f(61.0, -43.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(61.0, -44.0, 42.0);
    glVertex3f(60.0, -44.0, 42.0);
    glVertex3f(60.0, -44.0, 88.0);
    glVertex3f(61.0, -44.0, 88.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(60.0, -44.0, 88.0);
    glVertex3f(60.0, -43.0, 88.0);
    glVertex3f(60.0, -43.0, 42.0);
    glVertex3f(60.0, -44.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 88.0);
    glVertex3f(61.0, -43.0, 88.0);
    glVertex3f(61.0, -43.0, 42.0);
    glVertex3f(61.0, -44.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 42.0);
    glVertex3f(61.0, -43.0, 42.0);
    glVertex3f(60.0, -43.0, 42.0);
    glVertex3f(60.0, -44.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 88.0);
    glVertex3f(61.0, -43.0, 88.0);
    glVertex3f(60.0, -43.0, 88.0);
    glVertex3f(60.0, -44.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 88.0);
    glVertex3f(60.0, -44.0, 88.0);
    glVertex3f(60.0, -44.0, 42.0);
    glVertex3f(61.0, -44.0, 42.0);
    glEnd();

	//Depan Kanan
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -43.0, 42.0);
    glVertex3f(79.0, -43.0, 42.0);
    glVertex3f(79.0, -43.0, 88.0);
    glVertex3f(80.0, -43.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(80.0, -44.0, 42.0);
    glVertex3f(79.0, -44.0, 42.0);
    glVertex3f(79.0, -44.0, 88.0);
    glVertex3f(80.0, -44.0, 88.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 88.0);
    glVertex3f(79.0, -43.0, 88.0);
    glVertex3f(79.0, -43.0, 42.0);
    glVertex3f(79.0, -44.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -44.0, 88.0);
    glVertex3f(80.0, -43.0, 88.0);
    glVertex3f(80.0, -43.0, 42.0);
    glVertex3f(80.0, -44.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -44.0, 42.0);
    glVertex3f(80.0, -43.0, 42.0);
    glVertex3f(79.0, -43.0, 42.0);
    glVertex3f(79.0, -44.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -44.0, 88.0);
    glVertex3f(80.0, -43.0, 88.0);
    glVertex3f(79.0, -43.0, 88.0);
    glVertex3f(79.0, -44.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(80.0, -44.0, 88.0);
    glVertex3f(79.0, -44.0, 88.0);
    glVertex3f(79.0, -44.0, 42.0);
    glVertex3f(80.0, -44.0, 42.0);
    glEnd();

	//Samping Depan
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -43.0, 42.0);
    glVertex3f(61.0, -43.0, 42.0);
    glVertex3f(61.0, -43.0, 44.0);
    glVertex3f(79.0, -43.0, 44.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 42.0);
    glVertex3f(61.0, -44.0, 42.0);
    glVertex3f(61.0, -44.0, 44.0);
    glVertex3f(79.0, -44.0, 44.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 44.0);
    glVertex3f(61.0, -43.0, 44.0);
    glVertex3f(61.0, -43.0, 42.0);
    glVertex3f(61.0, -44.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 44.0);
    glVertex3f(79.0, -43.0, 44.0);
    glVertex3f(79.0, -43.0, 42.0);
    glVertex3f(79.0, -44.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 42.0);
    glVertex3f(79.0, -43.0, 42.0);
    glVertex3f(61.0, -43.0, 42.0);
    glVertex3f(61.0, -44.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 44.0);
    glVertex3f(79.0, -43.0, 44.0);
    glVertex3f(61.0, -43.0, 44.0);
    glVertex3f(61.0, -44.0, 44.0);
    glEnd();

	//Samping Tengah 1
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -43.0, 52.0);
    glVertex3f(61.0, -43.0, 52.0);
    glVertex3f(61.0, -43.0, 54.0);
    glVertex3f(79.0, -43.0, 54.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 52.0);
    glVertex3f(61.0, -44.0, 52.0);
    glVertex3f(61.0, -44.0, 54.0);
    glVertex3f(79.0, -44.0, 54.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 54.0);
    glVertex3f(61.0, -43.0, 54.0);
    glVertex3f(61.0, -43.0, 52.0);
    glVertex3f(61.0, -44.0, 52.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 54.0);
    glVertex3f(79.0, -43.0, 54.0);
    glVertex3f(79.0, -43.0, 52.0);
    glVertex3f(79.0, -44.0, 52.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 52.0);
    glVertex3f(79.0, -43.0, 52.0);
    glVertex3f(61.0, -43.0, 52.0);
    glVertex3f(61.0, -44.0, 52.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 54.0);
    glVertex3f(79.0, -43.0, 54.0);
    glVertex3f(61.0, -43.0, 54.0);
    glVertex3f(61.0, -44.0, 54.0);
    glEnd();

	//Samping Tengah 2
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -43.0, 76.0);
    glVertex3f(61.0, -43.0, 76.0);
    glVertex3f(61.0, -43.0, 78.0);
    glVertex3f(79.0, -43.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 76.0);
    glVertex3f(61.0, -44.0, 76.0);
    glVertex3f(61.0, -44.0, 78.0);
    glVertex3f(79.0, -44.0, 78.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 78.0);
    glVertex3f(61.0, -43.0, 78.0);
    glVertex3f(61.0, -43.0, 76.0);
    glVertex3f(61.0, -44.0, 76.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 78.0);
    glVertex3f(79.0, -43.0, 78.0);
    glVertex3f(79.0, -43.0, 76.0);
    glVertex3f(79.0, -44.0, 76.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 76.0);
    glVertex3f(79.0, -43.0, 76.0);
    glVertex3f(61.0, -43.0, 76.0);
    glVertex3f(61.0, -44.0, 76.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 78.0);
    glVertex3f(79.0, -43.0, 78.0);
    glVertex3f(61.0, -43.0, 78.0);
    glVertex3f(61.0, -44.0, 78.0);
    glEnd();

	//Variasi Tengah 1
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -43.0, 86.0);
    glVertex3f(61.0, -43.0, 86.0);
    glVertex3f(61.0, -43.0, 88.0);
    glVertex3f(79.0, -43.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 86.0);
    glVertex3f(61.0, -44.0, 86.0);
    glVertex3f(61.0, -44.0, 88.0);
    glVertex3f(79.0, -44.0, 88.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(61.0, -44.0, 88.0);
    glVertex3f(61.0, -43.0, 88.0);
    glVertex3f(61.0, -43.0, 86.0);
    glVertex3f(61.0, -44.0, 86.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 88.0);
    glVertex3f(79.0, -43.0, 88.0);
    glVertex3f(79.0, -43.0, 86.0);
    glVertex3f(79.0, -44.0, 86.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 86.0);
    glVertex3f(79.0, -43.0, 86.0);
    glVertex3f(61.0, -43.0, 86.0);
    glVertex3f(61.0, -44.0, 86.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(79.0, -44.0, 88.0);
    glVertex3f(79.0, -43.0, 88.0);
    glVertex3f(61.0, -43.0, 88.0);
    glVertex3f(61.0, -44.0, 88.0);
    glEnd();

	//Variasi Tengah
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(65.0, -43.0, 54.0);
    glVertex3f(63.0, -43.0, 54.0);
    glVertex3f(63.0, -43.0, 78.0);
    glVertex3f(65.0, -43.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(65.0, -44.0, 54.0);
    glVertex3f(63.0, -44.0, 54.0);
    glVertex3f(63.0, -44.0, 78.0);
    glVertex3f(65.0, -44.0, 78.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(63.0, -44.0, 78.0);
    glVertex3f(63.0, -43.0, 78.0);
    glVertex3f(63.0, -43.0, 54.0);
    glVertex3f(63.0, -44.0, 54.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(65.0, -44.0, 78.0);
    glVertex3f(65.0, -43.0, 78.0);
    glVertex3f(65.0, -43.0, 54.0);
    glVertex3f(65.0, -44.0, 54.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(65.0, -44.0, 54.0);
    glVertex3f(65.0, -43.0, 54.0);
    glVertex3f(63.0, -43.0, 54.0);
    glVertex3f(63.0, -44.0, 54.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(65.0, -44.0, 78.0);
    glVertex3f(65.0, -43.0, 78.0);
    glVertex3f(63.0, -43.0, 78.0);
    glVertex3f(63.0, -44.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(65.0, -44.0, 78.0);
    glVertex3f(63.0, -44.0, 78.0);
    glVertex3f(63.0, -44.0, 54.0);
    glVertex3f(65.0, -44.0, 54.0);
    glEnd();

	//Variasi Tengah 2
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(73.0, -43.0, 54.0);
    glVertex3f(67.0, -43.0, 54.0);
    glVertex3f(67.0, -43.0, 78.0);
    glVertex3f(73.0, -43.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(73.0, -44.0, 54.0);
    glVertex3f(67.0, -44.0, 54.0);
    glVertex3f(67.0, -44.0, 78.0);
    glVertex3f(73.0, -44.0, 78.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(67.0, -44.0, 78.0);
    glVertex3f(67.0, -43.0, 78.0);
    glVertex3f(67.0, -43.0, 54.0);
    glVertex3f(67.0, -44.0, 54.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(73.0, -44.0, 78.0);
    glVertex3f(73.0, -43.0, 78.0);
    glVertex3f(73.0, -43.0, 54.0);
    glVertex3f(73.0, -44.0, 54.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(73.0, -44.0, 54.0);
    glVertex3f(73.0, -43.0, 54.0);
    glVertex3f(67.0, -43.0, 54.0);
    glVertex3f(67.0, -44.0, 54.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(73.0, -44.0, 78.0);
    glVertex3f(73.0, -43.0, 78.0);
    glVertex3f(67.0, -43.0, 78.0);
    glVertex3f(67.0, -44.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(73.0, -44.0, 78.0);
    glVertex3f(67.0, -44.0, 78.0);
    glVertex3f(67.0, -44.0, 54.0);
    glVertex3f(73.0, -44.0, 54.0);
    glEnd();

	//Variasi Tengah 3
	//Atas
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(77.0, -43.0, 54.0);
    glVertex3f(75.0, -43.0, 54.0);
    glVertex3f(75.0, -43.0, 78.0);
    glVertex3f(77.0, -43.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.0);
    glVertex3f(77.0, -44.0, 54.0);
    glVertex3f(75.0, -44.0, 54.0);
    glVertex3f(75.0, -44.0, 78.0);
    glVertex3f(77.0, -44.0, 78.0);
    glEnd();

	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(75.0, -44.0, 78.0);
    glVertex3f(75.0, -43.0, 78.0);
    glVertex3f(75.0, -43.0, 54.0);
    glVertex3f(75.0, -44.0, 54.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(77.0, -44.0, 78.0);
    glVertex3f(77.0, -43.0, 78.0);
    glVertex3f(77.0, -43.0, 54.0);
    glVertex3f(77.0, -44.0, 54.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(77.0, -44.0, 54.0);
    glVertex3f(77.0, -43.0, 54.0);
    glVertex3f(75.0, -43.0, 54.0);
    glVertex3f(75.0, -44.0, 54.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(77.0, -44.0, 78.0);
    glVertex3f(77.0, -43.0, 78.0);
    glVertex3f(75.0, -43.0, 78.0);
    glVertex3f(75.0, -44.0, 78.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(77.0, -44.0, 78.0);
    glVertex3f(75.0, -44.0, 78.0);
    glVertex3f(75.0, -44.0, 54.0);
    glVertex3f(77.0, -44.0, 54.0);
    glEnd();

	//Variasi Kaki Depan
	//1
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(66.0, -43.0, 44.0);
    glVertex3f(66.0, -37.0, 44.0);
    glVertex3f(66.0, -37.0, 42.0);
    glVertex3f(66.0, -43.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 44.0);
    glVertex3f(68.0, -37.0, 44.0);
    glVertex3f(68.0, -37.0, 42.0);
    glVertex3f(68.0, -43.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 42.0);
    glVertex3f(68.0, -37.0, 42.0);
    glVertex3f(66.0, -37.0, 42.0);
    glVertex3f(66.0, -43.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 44.0);
    glVertex3f(68.0, -37.0, 44.0);
    glVertex3f(66.0, -37.0, 44.0);
    glVertex3f(66.0, -43.0, 44.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 44.0);
    glVertex3f(66.0, -43.0, 44.0);
    glVertex3f(66.0, -43.0, 42.0);
    glVertex3f(68.0, -43.0, 42.0);
    glEnd();

	//2
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(70.0, -43.0, 44.0);
    glVertex3f(70.0, -37.0, 44.0);
    glVertex3f(70.0, -37.0, 42.0);
    glVertex3f(70.0, -43.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 44.0);
    glVertex3f(72.0, -37.0, 44.0);
    glVertex3f(72.0, -37.0, 42.0);
    glVertex3f(72.0, -43.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 42.0);
    glVertex3f(72.0, -37.0, 42.0);
    glVertex3f(70.0, -37.0, 42.0);
    glVertex3f(70.0, -43.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 44.0);
    glVertex3f(72.0, -37.0, 44.0);
    glVertex3f(70.0, -37.0, 44.0);
    glVertex3f(70.0, -43.0, 44.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 44.0);
    glVertex3f(70.0, -43.0, 44.0);
    glVertex3f(70.0, -43.0, 42.0);
    glVertex3f(72.0, -43.0, 42.0);
    glEnd();

	//3
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(74.0, -43.0, 44.0);
    glVertex3f(74.0, -37.0, 44.0);
    glVertex3f(74.0, -37.0, 42.0);
    glVertex3f(74.0, -43.0, 42.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 44.0);
    glVertex3f(76.0, -37.0, 44.0);
    glVertex3f(76.0, -37.0, 42.0);
    glVertex3f(76.0, -43.0, 42.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 42.0);
    glVertex3f(76.0, -37.0, 42.0);
    glVertex3f(74.0, -37.0, 42.0);
    glVertex3f(74.0, -43.0, 42.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 44.0);
    glVertex3f(76.0, -37.0, 44.0);
    glVertex3f(74.0, -37.0, 44.0);
    glVertex3f(74.0, -43.0, 44.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 44.0);
    glVertex3f(74.0, -43.0, 44.0);
    glVertex3f(74.0, -43.0, 42.0);
    glVertex3f(76.0, -43.0, 42.0);
    glEnd();

		//Variasi Kaki Depan 1
	//1
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(66.0, -43.0, 88.0);
    glVertex3f(66.0, -37.0, 88.0);
    glVertex3f(66.0, -37.0, 86.0);
    glVertex3f(66.0, -43.0, 86.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 88.0);
    glVertex3f(68.0, -37.0, 88.0);
    glVertex3f(68.0, -37.0, 86.0);
    glVertex3f(68.0, -43.0, 86.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 86.0);
    glVertex3f(68.0, -37.0, 86.0);
    glVertex3f(66.0, -37.0, 86.0);
    glVertex3f(66.0, -43.0, 86.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 88.0);
    glVertex3f(68.0, -37.0, 88.0);
    glVertex3f(66.0, -37.0, 88.0);
    glVertex3f(66.0, -43.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(68.0, -43.0, 88.0);
    glVertex3f(66.0, -43.0, 88.0);
    glVertex3f(66.0, -43.0, 86.0);
    glVertex3f(68.0, -43.0, 86.0);
    glEnd();

	//2
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(70.0, -43.0, 88.0);
    glVertex3f(70.0, -37.0, 88.0);
    glVertex3f(70.0, -37.0, 86.0);
    glVertex3f(70.0, -43.0, 86.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 88.0);
    glVertex3f(72.0, -37.0, 88.0);
    glVertex3f(72.0, -37.0, 86.0);
    glVertex3f(72.0, -43.0, 86.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 86.0);
    glVertex3f(72.0, -37.0, 86.0);
    glVertex3f(70.0, -37.0, 86.0);
    glVertex3f(70.0, -43.0, 86.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 88.0);
    glVertex3f(72.0, -37.0, 88.0);
    glVertex3f(70.0, -37.0, 88.0);
    glVertex3f(70.0, -43.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(72.0, -43.0, 88.0);
    glVertex3f(70.0, -43.0, 88.0);
    glVertex3f(70.0, -43.0, 86.0);
    glVertex3f(72.0, -43.0, 86.0);
    glEnd();

	//3
	//Kanan
    glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(74.0, -43.0, 88.0);
    glVertex3f(74.0, -37.0, 88.0);
    glVertex3f(74.0, -37.0, 86.0);
    glVertex3f(74.0, -43.0, 86.0);
    glEnd();

	//Kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 88.0);
    glVertex3f(76.0, -37.0, 88.0);
    glVertex3f(76.0, -37.0, 86.0);
    glVertex3f(76.0, -43.0, 86.0);
    glEnd();

	//Depan
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 86.0);
    glVertex3f(76.0, -37.0, 86.0);
    glVertex3f(74.0, -37.0, 86.0);
    glVertex3f(74.0, -43.0, 86.0);
    glEnd();

	//Belakang
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 88.0);
    glVertex3f(76.0, -37.0, 88.0);
    glVertex3f(74.0, -37.0, 88.0);
    glVertex3f(74.0, -43.0, 88.0);
    glEnd();

	//Bawah
	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(76.0, -43.0, 88.0);
    glVertex3f(74.0, -43.0, 88.0);
    glVertex3f(74.0, -43.0, 86.0);
    glVertex3f(76.0, -43.0, 86.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();

    }

    void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;


}

void mouseMotion(int x, int y)
{
    Display();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }

}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi =1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 5, 500);
    glTranslated(0, -5, -150);
    glMatrixMode(GL_MODELVIEW);

}

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            glTranslated(0,0,3);
            break;
        case 'd':
        case 'D':
            glTranslated(3,0,0);
            break;
        case 's':
        case 'S':
            glTranslated(0,0,-3);
            break;
        case 'a':
        case 'A':
            glTranslated(-3,0,0);
            break;
        case '7':
            glTranslated(0,3,0);
            break;
        case '9':
            glTranslated(0,-3,0);
            break;
        case '2':
            glRotated(2,1,0,0);
            break;
        case '8':
            glRotated(-2,1,0,0);
            break;
        case '6':
            glRotated(2,0,1,0);
            break;
        case '4':
            glRotated(-2,1,0,0);
            break;
        case '1':
            glRotated(2,0,0,1);
            break;
        case '3':
            glRotated(-2,0,0,1);
            break;
        case '5':
            if (is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();


}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(250, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow(" Purnomo Adi - 672018118 ");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();

    return 0;
}