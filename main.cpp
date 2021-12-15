#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1

}


void Draw()
{

   glClear(GL_COLOR_BUFFER_BIT);

   //First Circle

   glColor3f( 1 ,.8, 0);
   double x0=-3, y0=7+200, r=200;
   glBegin(GL_POLYGON);
   glVertex2d(x0,y0);

   double dp0=1-r;
   double dp_new;

   while(1){
    if(dp0<0){
        x0++;
        dp_new=dp0+2*x0+1;
    }
    else if(dp0>=0){
        x0++;
        y0--;
        dp_new=dp0+2*x0-2*y0+1;
    }
    dp0=dp_new;
    glVertex2d(x0,y0);
    glVertex2d(-x0,y0);
    glVertex2d(x0,-y0);
    glVertex2d(-x0,-y0);

    glVertex2d(y0,x0);
    glVertex2d(-y0,x0);
    glVertex2d(y0,-x0);
    glVertex2d(-y0,-x0);

    if(x0>=y0){
        break;
    }
   }

   glEnd();

   //2nd circle

    glColor3f( 0 ,0, 0);

   double x1=-5, y1=9+120, r1=120;
   glBegin(GL_POLYGON);
   glVertex2d(x1,y1);

   double dp1=1-r1;
   double dp_new1;

   while(1){
    if(dp1<0){
        x1++;
        dp_new1=dp1+2*x1+1;
    }
    else if(dp1>=1){
        x1++;
        y1--;
        dp_new1=dp1+2*x1-2*y1+1;
    }
    dp1=dp_new1;
    glVertex2d(x1,y1);
    glVertex2d(-x1,y1);
    glVertex2d(x1,-y1);
    glVertex2d(-x1,-y1);

    glVertex2d(y1,x1);
    glVertex2d(-y1,x1);
    glVertex2d(y1,-x1);
    glVertex2d(-y1,-x1);

    if(x1>=y1){
        break;
    }
   }

   glEnd();

   //3rd circle

    glColor3f( 1 ,0.8, 0);

   double x2=-7, y2=11+100, r2=100;
   glBegin(GL_POLYGON);
   glVertex2d(x2,y2);

   double dp2=1-r2;
   double dp_new2;

   while(1){
    if(dp2<0){
        x2++;
        dp_new2=dp2+2*x2+1;
    }
    else if(dp2>=1){
        x2++;
        y2--;
        dp_new2=dp2+2*x2-2*y2+1;
    }
    dp2=dp_new2;
    glVertex2d(x2,y2);
    glVertex2d(-x2,y2);
    glVertex2d(x2,-y2);
    glVertex2d(-x2,-y2);

    glVertex2d(y2,x2);
    glVertex2d(-y2,x2);
    glVertex2d(y2,-x2);
    glVertex2d(-y2,-x2);

    if(x2>=y2){
        break;
    }
   }

   glEnd();


   glFlush();


glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("182-15-2111");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
