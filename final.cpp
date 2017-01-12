//
//  Name: R.J. Quillen
//  File: asgt16.cpp
//  Date: Novemeber 2016 
//
//  Desc: yep
//        
//      left-right move eye.x by -/+ 0.125  
//		up-down arrows move eye.y
//      PgUp-PgDn move eye.z
//

#define GLUT_DISABLE_ATEXIT_HACK

#include <iostream>
#include <gl/glut.h>
#include <string>
#include <sstream>

using namespace std;

const int screenWidth = 640;
const int screenHeight = 480;

class wcPt3D		// definition of Point3 class
{
public:
	float x, y, z;

	wcPt3D()			// default constructor
	{
		x = 0.0; y = 0.0; z = 0.0;
	}
	wcPt3D(float x0, float y0, float z0)
	{
		x = x0; y = y0; z = z0;
	}

};

class Face
{
	public:
		enum color {RED, ORANGE, BLUE, WHITE, YELLOW, GREEN};
		Face(color c) : face{{c,c,c}, {c,c,c}, {c,c,c}} {}	// constructor
		color face[3][3];
		void draw()
		{
			glBegin(GL_QUADS);  
			//00
			set_color(face[0][0]);
			glVertex3f(-.25-.5,  -.25+1, 1.0);
			glVertex3f(.25-.5,  -.25+1, 1.0);
			glVertex3f(.25-.5, .25+1, 1.0);
			glVertex3f(-.25-.5, .25+1, 1.0);
	  
			//01
			set_color(face[0][1]);
			glVertex3f(-.25,  -.25+1, 1.0);
			glVertex3f(.25,  -.25+1, 1.0);
			glVertex3f(.25, .25+1, 1.0);
			glVertex3f(-.25, .25+1, 1.0);
	  
			//02
			set_color(face[0][2]);
			glVertex3f(-.25+.5,  -.25+1, 1.0);
			glVertex3f(.25+.5,  -.25+1, 1.0);
			glVertex3f(.25+.5, .25+1, 1.0);
			glVertex3f(-.25+.5, .25+1, 1.0);
	  
			//10
			set_color(face[1][0]);
			glVertex3f(-.25-.5,  -.25+.5, 1.0);
			glVertex3f(.25-.5,  -.25+.5, 1.0);
			glVertex3f(.25-.5, .25+.5, 1.0);
			glVertex3f(-.25-.5, .25+.5, 1.0);
	  
			//11
			set_color(face[1][1]);
			glVertex3f(-.25,  -.25+.5, 1.0);
			glVertex3f(.25,  -.25+.5, 1.0);
			glVertex3f(.25, .25+.5, 1.0);
			glVertex3f(-.25, .25+.5, 1.0);
	  
			//12
			set_color(face[1][2]);
			glVertex3f(-.25+.5,  -.25+.5, 1.0);
			glVertex3f(.25+.5,  -.25+.5, 1.0);
			glVertex3f(.25+.5, .25+.5, 1.0);
			glVertex3f(-.25+.5, .25+.5, 1.0);
	  
			//20
			set_color(face[2][0]);
			glVertex3f(-.25-.5,  -.25, 1.0);
			glVertex3f(.25-.5,  -.25, 1.0);
			glVertex3f(.25-.5, .25, 1.0);
			glVertex3f(-.25-.5, .25, 1.0);
	  
			//21
			set_color(face[2][1]);
			glVertex3f(-.25,  -.25, 1.0);
			glVertex3f(.25,  -.25, 1.0);
			glVertex3f(.25, .25, 1.0);
			glVertex3f(-.25, .25, 1.0);
	  
			//22
			set_color(face[2][2]);
			glVertex3f(-.25+.5,  -.25, 1.0);
			glVertex3f(.25+.5,  -.25, 1.0);
			glVertex3f(.25+.5, .25, 1.0);
			glVertex3f(-.25+.5, .25 , 1.0);	  
			glEnd();
			draw_border();
		}
		
	private:
		
	void set_color(color c)
	{
		switch(c)
		{
			case RED: glColor3f(1.0, 0.0, 0.0); break;
			case ORANGE: glColor3f(1.0, 0.5, 0.0); break;
			case BLUE: glColor3f(0.0, 0.0, 1.0); break;
			case GREEN: glColor3f(0.0, 1.0, 0.0); break;
			case WHITE: glColor3f(1.0, 1.0, 1.0); break;
			case YELLOW: glColor3f(1.0, 1.0, 0.0); break;
			default: cout << "Error: invalid value for color\n"; break;
		}
	}

	void draw_border()
	{
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(3.5);
		glBegin(GL_LINE_LOOP);  
			//00
			glVertex3f(-.25-.5,  -.25+1, 1.0);
			glVertex3f(.25-.5,  -.25+1, 1.0);
			glVertex3f(.25-.5, .25+1, 1.0);
			glVertex3f(-.25-.5, .25+1, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//01
			glVertex3f(-.25,  -.25+1, 1.0);
			glVertex3f(.25,  -.25+1, 1.0);
			glVertex3f(.25, .25+1, 1.0);
			glVertex3f(-.25, .25+1, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//02
			glVertex3f(-.25+.5,  -.25+1, 1.0);
			glVertex3f(.25+.5,  -.25+1, 1.0);
			glVertex3f(.25+.5, .25+1, 1.0);
			glVertex3f(-.25+.5, .25+1, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//10
			glVertex3f(-.25-.5,  -.25+.5, 1.0);
			glVertex3f(.25-.5,  -.25+.5, 1.0);
			glVertex3f(.25-.5, .25+.5, 1.0);
			glVertex3f(-.25-.5, .25+.5, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//11
			glVertex3f(-.25,  -.25+.5, 1.0);
			glVertex3f(.25,  -.25+.5, 1.0);
			glVertex3f(.25, .25+.5, 1.0);
			glVertex3f(-.25, .25+.5, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//12
			glVertex3f(-.25+.5,  -.25+.5, 1.0);
			glVertex3f(.25+.5,  -.25+.5, 1.0);
			glVertex3f(.25+.5, .25+.5, 1.0);
			glVertex3f(-.25+.5, .25+.5, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//20
			glVertex3f(-.25-.5,  -.25, 1.0);
			glVertex3f(.25-.5,  -.25, 1.0);
			glVertex3f(.25-.5, .25, 1.0);
			glVertex3f(-.25-.5, .25, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//21
			glVertex3f(-.25,  -.25, 1.0);
			glVertex3f(.25,  -.25, 1.0);
			glVertex3f(.25, .25, 1.0);
			glVertex3f(-.25, .25, 1.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
			//22
			glVertex3f(-.25+.5,  -.25, 1.0);
			glVertex3f(.25+.5,  -.25, 1.0);
			glVertex3f(.25+.5, .25, 1.0);
			glVertex3f(-.25+.5, .25 , 1.0);	  
		glEnd();
		glFlush();
	}
};

class Cube
{
	public:
		Cube() :
			front(Face::RED), back(Face::ORANGE), left(Face::GREEN),
			right(Face::BLUE), top(Face::WHITE), bottom(Face::YELLOW) {}
		void draw()
		{
			// DRAW FRONT FACE
			glPushMatrix();
			cout << "Front: \n";
			front.draw();
			
			// DRAW RIGHT FACE
			glRotated(90, 0, 1, 0);
			glPushMatrix();
			//glRotated(180, 0, 1, 0);
			glTranslated(-.25, 0, -.25);
			cout << "Right: \n";
			right.draw();
			glPopMatrix();
			
			// DRAW BACK FACE
			glRotated(90, 0, 1, 0);
			glPushMatrix();
			glRotated(0,0,0,1);
			glRotated(180, 0, 1, 0);
			glTranslated(0, 0, -1.5);
			cout << "Back: \n";
			back.draw();
			glPopMatrix();
			
			//DRAW LEFT FACE
			glRotated(90, 0, 1, 0);
			glPushMatrix();
			glTranslated(.25, 0, -.25);
			cout << "Left: \n";
			left.draw();
			glPopMatrix();
			
			// DRAW TOP FACE
			glRotated(-90, 1, 0, 0);
			glRotated(90, 0, 0, 1);
			glPushMatrix();
			glRotated(180, 1, 0, 0);
			glRotated(180, 0, 1, 0);
			glRotated(180, 0, 0, 1);
			glTranslated(0, -.75, 0.25);
			cout << "Top: \n";
			top.draw();
			glPopMatrix();
			
			// DRAW BOTTOM FACE
			glPushMatrix();
			glRotated(180, 0,1,0);
			glRotated(180, 0, 0, 1);
			glTranslated(0, -.25, -.75);
			cout << "Bottom: \n";
			bottom.draw();
			glPopMatrix();
			glPopMatrix();			
		}
		void u()
		{
			cout << "\n UP TURN \n";
			Face::color temp[3];
			Face::color temp2[3][3];
			
			temp[0] = right.face[0][0];
			temp[1] = right.face[0][1];
			temp[2] = right.face[0][2];
			
			right.face[0][0] = back.face[0][0];
			right.face[0][1] = back.face[0][1];
			right.face[0][2] = back.face[0][2];
			
			back.face[0][0] = left.face[0][0];
			back.face[0][1] = left.face[0][1];
			back.face[0][2] = left.face[0][2];
			
			left.face[0][0] = front.face[0][0];
			left.face[0][1] = front.face[0][1];
			left.face[0][2] = front.face[0][2];
			
			front.face[0][0] = temp[0];
			front.face[0][1] = temp[1];
			front.face[0][2] = temp[2];
			
			temp2[0][0] = top.face[2][0];
			temp2[0][1] = top.face[1][0];
			temp2[0][2] = top.face[0][0];	
			temp2[1][0] = top.face[2][1];
			temp2[1][1] = top.face[1][1];
			temp2[1][2] = top.face[0][1];
			temp2[2][0] = top.face[2][2];			
			temp2[2][1] = top.face[1][2];
			temp2[2][2] = top.face[0][2];
				
			top.face[0][0] = temp2[0][0];
			top.face[0][1] = temp2[0][1];
			top.face[0][2] = temp2[0][2];
			top.face[1][0] = temp2[1][0];
			top.face[1][2] = temp2[1][2];
			top.face[2][0] = temp2[2][0];
			top.face[2][1] = temp2[2][1];
			top.face[2][2] = temp2[2][2];
		}
		void u_prime()
		{
			u();
			u();
			u();
		}
		void r()
		{
			cout << "\n RIGHT TURN \n";
			Face::color temp[3];
			Face::color temp2[3][3];
			
			//ALMOST POSITIVE THIS IS RIGHT
			temp[0] = bottom.face[0][2];
			temp[1] = bottom.face[1][2];
			temp[2] = bottom.face[2][2];
			
			bottom.face[0][2] = back.face[2][0];
			bottom.face[1][2] = back.face[1][0];
			bottom.face[2][2] = back.face[0][0];
			
			back.face[2][0] = top.face[0][2];
			back.face[1][0] = top.face[1][2];
			back.face[0][0] = top.face[2][2];
			
			top.face[0][2] = front.face[0][2];
			top.face[1][2] = front.face[1][2];
			top.face[2][2] = front.face[2][2];
			
			front.face[0][2] = temp[0];
			front.face[1][2] = temp[1];
			front.face[2][2] = temp[2];
			
			temp2[0][0] = right.face[2][0];
			temp2[0][1] = right.face[1][0];
			temp2[0][2] = right.face[0][0];	
			temp2[1][0] = right.face[2][1];
			temp2[1][1] = right.face[1][1];
			temp2[1][2] = right.face[0][1];
			temp2[2][0] = right.face[2][2];			
			temp2[2][1] = right.face[1][2];
			temp2[2][2] = right.face[0][2];
				
			right.face[0][0] = temp2[0][0];
			right.face[0][1] = temp2[0][1];
			right.face[0][2] = temp2[0][2];
			right.face[1][0] = temp2[1][0];
			right.face[1][2] = temp2[1][2];
			right.face[2][0] = temp2[2][0];
			right.face[2][1] = temp2[2][1];
			right.face[2][2] = temp2[2][2];
		}
		
		void r_prime()
		{
			r();
			r();
			r();
		}
		
		void f()
		{
			Face::color temp[3];
			Face::color temp2[3][3];
			temp[0] = right.face[0][0];
			temp[1] = right.face[1][0];
			temp[2] = right.face[2][0];
			
			right.face[0][0] = top.face[2][0];
			right.face[1][0] = top.face[2][1];
			right.face[2][0] = top.face[2][2];
			
			top.face[2][0] = left.face[2][2];
			top.face[2][1] = left.face[1][2];
			top.face[2][2] = left.face[0][2];
			
			left.face[2][2] = bottom.face[0][2];
			left.face[1][2] = bottom.face[0][1];
			left.face[0][2] = bottom.face[0][0];
			
			bottom.face[0][0] = temp[2];
			bottom.face[0][1] = temp[1];
			bottom.face[0][2] = temp[0];
			
			temp2[0][0] = front.face[2][0];
			temp2[0][1] = front.face[1][0];
			temp2[0][2] = front.face[0][0];	
			temp2[1][0] = front.face[2][1];
			temp2[1][1] = front.face[1][1];
			temp2[1][2] = front.face[0][1];
			temp2[2][0] = front.face[2][2];			
			temp2[2][1] = front.face[1][2];
			temp2[2][2] = front.face[0][2];
				
			front.face[0][0] = temp2[0][0];
			front.face[0][1] = temp2[0][1];
			front.face[0][2] = temp2[0][2];
			front.face[1][0] = temp2[1][0];
			front.face[1][2] = temp2[1][2];
			front.face[2][0] = temp2[2][0];
			front.face[2][1] = temp2[2][1];
			front.face[2][2] = temp2[2][2];
		}
		
		void f_prime()
		{
			f();
			f();
			f();
		}
		
		void l()
		{
			Face::color temp[3];
			Face::color temp2[3][3];
			
			temp[0] = front.face[0][0];
			temp[1] = front.face[1][0];
			temp[2] = front.face[2][0];
			
			front.face[0][0] = top.face[0][0];
			front.face[1][0] = top.face[1][0];
			front.face[2][0] = top.face[2][0];
			
			top.face[0][0] = back.face[2][2];
			top.face[1][0] = back.face[1][2];
			top.face[2][0] = back.face[0][2];
			
			back.face[2][2] = bottom.face[0][0];
			back.face[1][2] = bottom.face[1][0];
			back.face[0][2] = bottom.face[2][0];
			
			bottom.face[0][0] = temp[0];
			bottom.face[1][0] = temp[1];
			bottom.face[2][0] = temp[2];
			
			temp2[0][0] = left.face[2][0];
			temp2[0][1] = left.face[1][0];
			temp2[0][2] = left.face[0][0];	
			temp2[1][0] = left.face[2][1];
			temp2[1][1] = left.face[1][1];
			temp2[1][2] = left.face[0][1];
			temp2[2][0] = left.face[2][2];			
			temp2[2][1] = left.face[1][2];
			temp2[2][2] = left.face[0][2];
				
			left.face[0][0] = temp2[0][0];
			left.face[0][1] = temp2[0][1];
			left.face[0][2] = temp2[0][2];
			left.face[1][0] = temp2[1][0];
			left.face[1][2] = temp2[1][2];
			left.face[2][0] = temp2[2][0];
			left.face[2][1] = temp2[2][1];
			left.face[2][2] = temp2[2][2];
				
		}
		void l_prime()
		{
			l();
			l();
			l();
		}
		
		void b()
		{
			Face::color temp[3];
			Face::color temp2[3][3];
			
			temp[0] = right.face[2][0];
			temp[1] = right.face[2][1];
			temp[2] = right.face[2][2];
			
			right.face[2][0] = front.face[2][0];
			right.face[2][1] = front.face[2][1];
			right.face[2][2] = front.face[2][2];
			
			front.face[2][0] = left.face[2][0];
			front.face[2][1] = left.face[2][1];
			front.face[2][2] = left.face[2][2];
			
			left.face[2][0] = back.face[2][0];
			left.face[2][1] = back.face[2][1];
			left.face[2][2] = back.face[2][2];
			
			back.face[2][0] = temp[0];
			back.face[2][1] = temp[1];
			back.face[2][2] = temp[2];
			
			temp2[0][0] = bottom.face[2][0];
			temp2[0][1] = bottom.face[1][0];
			temp2[0][2] = bottom.face[0][0];	
			temp2[1][0] = bottom.face[2][1];
			temp2[1][1] = bottom.face[1][1];
			temp2[1][2] = bottom.face[0][1];
			temp2[2][0] = bottom.face[2][2];			
			temp2[2][1] = bottom.face[1][2];
			temp2[2][2] = bottom.face[0][2];
				
			bottom.face[0][0] = temp2[0][0];
			bottom.face[0][1] = temp2[0][1];
			bottom.face[0][2] = temp2[0][2];
			bottom.face[1][0] = temp2[1][0];
			bottom.face[1][2] = temp2[1][2];
			bottom.face[2][0] = temp2[2][0];
			bottom.face[2][1] = temp2[2][1];
			bottom.face[2][2] = temp2[2][2];
		}
		
		void b_prime()
		{
			b();
			b();
			b();
		}
		
		void flip_up()
		{	
			Face::color temp[3][3];
			Face::color temp2[3][3];
		
			temp[0][0] = top.face[0][0];
			temp[0][1] = top.face[0][1];
			temp[0][2] = top.face[0][2];	
			temp[1][0] = top.face[1][0];
			temp[1][1] = top.face[1][1];
			temp[1][2] = top.face[1][2];
			temp[2][0] = top.face[2][0];			
			temp[2][1] = top.face[2][1];
			temp[2][2] = top.face[2][2];
		
			top.face[0][0] = front.face[0][0];
			top.face[0][1] = front.face[0][1];
			top.face[0][2] = front.face[0][2];
			top.face[1][0] = front.face[1][0];
			top.face[1][1] = front.face[1][1];
			top.face[1][2] = front.face[1][2];
			top.face[2][0] = front.face[2][0];
			top.face[2][1] = front.face[2][1];
			top.face[2][2] = front.face[2][2];
			
			front.face[0][0] = bottom.face[0][0];
			front.face[0][1] = bottom.face[0][1];
			front.face[0][2] = bottom.face[0][2];
			front.face[1][0] = bottom.face[1][0];
			front.face[1][1] = bottom.face[1][1];
			front.face[1][2] = bottom.face[1][2];
			front.face[2][0] = bottom.face[2][0];
			front.face[2][1] = bottom.face[2][1];
			front.face[2][2] = bottom.face[2][2];
			
			bottom.face[0][0] = back.face[2][2];
			bottom.face[0][1] = back.face[2][1];
			bottom.face[0][2] = back.face[2][0];
			bottom.face[1][0] = back.face[1][2];
			bottom.face[1][1] = back.face[1][1];
			bottom.face[1][2] = back.face[1][0];
			bottom.face[2][0] = back.face[0][2];
			bottom.face[2][1] = back.face[0][1];
			bottom.face[2][2] = back.face[0][0];
			
			back.face[0][0] = temp[2][2];
			back.face[0][1] = temp[2][1];
			back.face[0][2] = temp[2][0];
			back.face[1][0] = temp[1][2];
			back.face[1][1] = temp[1][1];
			back.face[1][2] = temp[1][0];
			back.face[2][0] = temp[0][2];
			back.face[2][1] = temp[0][1];
			back.face[2][2] = temp[0][0];
			
			// SHIFT LEFT FACE
			for(int i = 0; i < 3; ++i)
			{
			temp2[0][0] = left.face[2][0];
			temp2[0][1] = left.face[1][0];
			temp2[0][2] = left.face[0][0];	
			temp2[1][0] = left.face[2][1];
			temp2[1][1] = left.face[1][1];
			temp2[1][2] = left.face[0][1];
			temp2[2][0] = left.face[2][2];			
			temp2[2][1] = left.face[1][2];
			temp2[2][2] = left.face[0][2];
				
			left.face[0][0] = temp2[0][0];
			left.face[0][1] = temp2[0][1];
			left.face[0][2] = temp2[0][2];
			left.face[1][0] = temp2[1][0];
			left.face[1][2] = temp2[1][2];
			left.face[2][0] = temp2[2][0];
			left.face[2][1] = temp2[2][1];
			left.face[2][2] = temp2[2][2];
			}
			
			//SHIFT RIGHT FACE
			temp2[0][0] = right.face[2][0];
			temp2[0][1] = right.face[1][0];
			temp2[0][2] = right.face[0][0];	
			temp2[1][0] = right.face[2][1];
			temp2[1][1] = right.face[1][1];
			temp2[1][2] = right.face[0][1];
			temp2[2][0] = right.face[2][2];			
			temp2[2][1] = right.face[1][2];
			temp2[2][2] = right.face[0][2];
				
			right.face[0][0] = temp2[0][0];
			right.face[0][1] = temp2[0][1];
			right.face[0][2] = temp2[0][2];
			right.face[1][0] = temp2[1][0];
			right.face[1][2] = temp2[1][2];
			right.face[2][0] = temp2[2][0];
			right.face[2][1] = temp2[2][1];
			right.face[2][2] = temp2[2][2];	
		}
		
		void flip_down()
		{
			flip_up();
			flip_up();
			flip_up();
		}
		
		void rotate_clockwise()
		{
			Face::color temp[3][3];
			Face::color temp2[3][3];
			
			temp[0][0] = front.face[0][0];
			temp[0][1] = front.face[0][1];
			temp[0][2] = front.face[0][2];
			temp[1][0] = front.face[1][0];
			temp[1][1] = front.face[1][1];
			temp[1][2] = front.face[1][2];
			temp[2][0] = front.face[2][0];
			temp[2][1] = front.face[2][1];
			temp[2][2] = front.face[2][2];
			
			front.face[0][0] = right.face[0][0];
			front.face[0][1] = right.face[0][1];
			front.face[0][2] = right.face[0][2];
			front.face[1][0] = right.face[1][0];
			front.face[1][1] = right.face[1][1];
			front.face[1][2] = right.face[1][2];
			front.face[2][0] = right.face[2][0];
			front.face[2][1] = right.face[2][1];
			front.face[2][2] = right.face[2][2];
			
			right.face[0][0] = back.face[0][0];
			right.face[0][1] = back.face[0][1];
			right.face[0][2] = back.face[0][2];
			right.face[1][0] = back.face[1][0];
			right.face[1][1] = back.face[1][1];
			right.face[1][2] = back.face[1][2];
			right.face[2][0] = back.face[2][0];
			right.face[2][1] = back.face[2][1];
			right.face[2][2] = back.face[2][2];
			
			back.face[0][0] = left.face[0][0];
			back.face[0][1] = left.face[0][1];
			back.face[0][2] = left.face[0][2];
			back.face[1][0] = left.face[1][0];
			back.face[1][1] = left.face[1][1];
			back.face[1][2] = left.face[1][2];
			back.face[2][0] = left.face[2][0];
			back.face[2][1] = left.face[2][1];
			back.face[2][2] = left.face[2][2];
			
			left.face[0][0] = temp[0][0];
			left.face[0][1] = temp[0][1];
			left.face[0][2] = temp[0][2];
			left.face[1][0] = temp[1][0];
			left.face[1][1] = temp[1][1];
			left.face[1][2] = temp[1][2];
			left.face[2][0] = temp[2][0];
			left.face[2][1] = temp[2][1];
			left.face[2][2] = temp[2][2];
			
			//ROTATE TOP FACE
			temp2[0][0] = top.face[2][0];
			temp2[0][1] = top.face[1][0];
			temp2[0][2] = top.face[0][0];	
			temp2[1][0] = top.face[2][1];
			temp2[1][1] = top.face[1][1];
			temp2[1][2] = top.face[0][1];
			temp2[2][0] = top.face[2][2];			
			temp2[2][1] = top.face[1][2];
			temp2[2][2] = top.face[0][2];
				
			top.face[0][0] = temp2[0][0];
			top.face[0][1] = temp2[0][1];
			top.face[0][2] = temp2[0][2];
			top.face[1][0] = temp2[1][0];
			top.face[1][2] = temp2[1][2];
			top.face[2][0] = temp2[2][0];
			top.face[2][1] = temp2[2][1];
			top.face[2][2] = temp2[2][2];
			
			//ROTATE BOTTOM 
			for(int i = 0; i < 3; ++i)
			{
			temp2[0][0] = bottom.face[2][0];
			temp2[0][1] = bottom.face[1][0];
			temp2[0][2] = bottom.face[0][0];	
			temp2[1][0] = bottom.face[2][1];
			temp2[1][1] = bottom.face[1][1];
			temp2[1][2] = bottom.face[0][1];
			temp2[2][0] = bottom.face[2][2];			
			temp2[2][1] = bottom.face[1][2];
			temp2[2][2] = bottom.face[0][2];
				
			bottom.face[0][0] = temp2[0][0];
			bottom.face[0][1] = temp2[0][1];
			bottom.face[0][2] = temp2[0][2];
			bottom.face[1][0] = temp2[1][0];
			bottom.face[1][2] = temp2[1][2];
			bottom.face[2][0] = temp2[2][0];
			bottom.face[2][1] = temp2[2][1];
			bottom.face[2][2] = temp2[2][2];
			}
		}

		void rotate_counter_clockwise()
		{
			rotate_clockwise();
			rotate_clockwise();
			rotate_clockwise();
		}
		
	private:
		Face front, back, left, right, top, bottom;
};

Cube cube;

wcPt3D eye0(1.0, 1.0, 2.0);
wcPt3D eye = eye0;
wcPt3D lookAt0(0.0, 0.0,0.0);
wcPt3D lookAt = lookAt0;
wcPt3D up(0.0, 1.0, 0.0);

GLdouble windowHeight = 2.0;
GLfloat angle = 90.0;

void axis(double length)
{  
    glPushMatrix();
    glBegin(GL_LINES);
		glNormal3d(0.0, 0.0, 1.0);
        glVertex3d(0.0, 0.0, 0.0);
        glVertex3d(0.0, 0.0, length);
    glEnd();
    glTranslated(0.0, 0.0, length - 0.2);
    glutWireCone(0.04, 0.2, 12.0, 9.0);
    glPopMatrix();
}  

void init()
{

	glClearColor(1.0, 1.0, 1.0, 0.0);	//  Set display window color to white
	
}

void myDisplay(void)
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable (GL_DEPTH_TEST);
	/*
	glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
	  */
	double winHt = windowHeight;
    double aspect = float(screenWidth)/float(screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-winHt * aspect, winHt * aspect, -winHt, winHt, 0.5, 100.0);   
    gluLookAt(eye.x, eye.y, eye.z, 
              lookAt.x, lookAt.y, lookAt.z, 
              up.x, up.y, up.z);   
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	cube.draw();
	
    glColor3d(0.0, 0.0, 1.0);	// blue z-axis
    axis(1.5);
    glPushMatrix();
    glRotated(90.0, 0.0, 1.0, 0.0);
    glColor3d(1.0, 0.0, 0.0);	// red x-axis
    axis(1.5);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glColor3d(0.0, 1.0, 0.0);	// green y-axis
    axis(1.5);
    glPopMatrix();
	glFlush ();
    glColor3d(0.0, 0.0, 1.0);	// blue z-axis
    axis(1.5);
    glPushMatrix();
    glRotated(90.0, 0.0, 1.0, 0.0);
    glColor3d(1.0, 0.0, 0.0);	// red x-axis
    axis(1.5);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glColor3d(0.0, 1.0, 0.0);	// green y-axis
    axis(1.5);
    glPopMatrix();
	glFlush();
}            

void reshapeFcn(int newWidth, int newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) newWidth, 0.0, (GLdouble) newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

void mySpecialKeyboard(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
        eye.x -= 0.125;
    else if (key == GLUT_KEY_RIGHT)
        eye.x += 0.125;
    else if (key == GLUT_KEY_UP)
        eye.y += 0.125;
    else if (key == GLUT_KEY_DOWN)
        eye.y -= 0.125;
    else if (key == GLUT_KEY_PAGE_DOWN)
		eye.z -= 0.125;
    else if (key == GLUT_KEY_PAGE_UP)
        eye.z += 0.125; 
	else if (key == GLUT_KEY_HOME)
	{
		eye = eye0;  
	}
      
	//cout << eye.x << " " << eye.y << " " << eye.z << "\n";
	glutPostRedisplay();
}        

void myKeyboard(unsigned char key, int x, int y)
{
	if (key == 'u')
	{
		cube.u();
		myDisplay();
	}
	else if (key == 'r')
	{
		cube.r();
		myDisplay();
	}
	
	else if (key == 'f')
	{
		cube.f();
		myDisplay();
	}
	
	else if (key == 'l')
	{
		cube.l();
		myDisplay();
	}
	
	else if (key == 'b')
	{
		cube.b();
		myDisplay();
	}
	
	else if (key == 'w')
	{
		cube.flip_up();
		myDisplay();
	}
	
	else if (key == 's')
	{
		cube.flip_down();
		myDisplay();
	}
	
	else if (key == 'd')
	{
		cube.rotate_counter_clockwise();
		myDisplay();
	}
	
	else if (key == 'a')
	{
		cube.rotate_clockwise();
		myDisplay();
	}
	/*
	else if (key == 't')
	{
		string input = "";
		getline(cin, input);
		while(cin >> input)
		//{
		//	if (input == "stop")
		//	cout << "Input: " << input << "\n";
		//}
		
	}
	*/
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glutInitWindowPosition(100, 100);				
	glutInitWindowSize(screenWidth, screenHeight);	
	glutCreateWindow("RJ's Rubik's Cube");	
	glutDisplayFunc(myDisplay);	
    glutReshapeFunc(reshapeFcn);
	glutSpecialFunc(mySpecialKeyboard);
	glutKeyboardFunc(myKeyboard);
	init();
	glutMainLoop();
}