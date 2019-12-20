#include <stdlib.h>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<sstream>
#include<cstring>
#include <string>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;
//problem
//level 2 te timer negative hoye jai
//float transX=0.0,transY=0.0,transX1=0.0,transY1=0.0,transX2=0.0,transY2=0.0;
int randArr[7],randArr2[10];
float transFactor = 0.0f,transFish=1.0f,transPebble=0.0f,transSun=0.0f,transBalloon=0.0f,trans=0.0;
bool p1=false,p2=false,p3=false,window2=false,window1=true,l2flag=false,l3flag=false,atStart=true,atStart2=true;
int l2one=2,l2two=2,l2three=2,l2four=2,l2five=2,l2six=2,l2seven=2,l2eight=2,l2nine=2,l2ten=2,l2eleven=2,l2twelve=2,l2thirteen=2,l2fourteen=2;
float s1x2=-0.581,s2x1=-0.373,s2x2=-0.030,s3x1=0.196,s3x2=0.562,s4x1=0.728,s4x2=0.932;
bool up=false,first=true,down=false,p1cross=false,p2cross=false,p3cross=false,show=true,show3=true,goUp=false,nodown=false;
int one=2,two=2,three=2,four=2,five=2,six=2,seven=2,eight=2,nine=2,ten=2,eleven=2,twelve=2;
float trackMan=0.0f,shootFX=0.0,shootFY=0.0;
float changeX=0.0,changeY=0.0;
char text[] = "SCORE";
bool start=false,pebble1=false,pebble2=false,pebble3=false,pebble4=false;
int finalScore=0,timer=7500,timer2=8000,val=00,shootedfish=-1,shootedfish2=-1,t=0;



int ballx=0;
int bally=0;

float getX(float value)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    float frac = (float)value/((float)width/2);
    return frac;
}
float getY(float value)
{
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    float frac = (float)value/((float)height/2);
    return frac;
}
//Print
void Sprint( float x, float y, char *st)
{
    int l,i;
    l=strlen( st );
    glColor3f(0.0,0.0,0.0);
    glRasterPos2f( x, y);
    for( i=0; i < l; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}

void generateRandom(int x)
{
  srand(time(0));
  if(!l2flag && !l3flag)
  {
      for(int i=0;i<7;i++)
      {
        bool add=false;
        int randomNumber = rand() % 12 ;
        for(int j=0;j<7;j++)
        {
            if(randomNumber==randArr[j] || randomNumber==0)
            {
                add=true;
                i--;
                j=7;
            }
        }
        if(!add)
        {
            if(x!=0)
            {
                shootedfish=randomNumber;
                //cout<<shootedfish;
                i=7;
            }
            else
                randArr[i]=randomNumber;
            cout<<randomNumber<<endl;
        }
    }
  }
   else
   {
       for(int i=0;i<10;i++)
       {
        bool add=false;
        int randomNumber = rand() % 14 ;
        for(int j=0;j<10;j++)
        {
            if(randomNumber==randArr2[j] || randomNumber==0)
            {
                add=true;
                i--;
                j=10;
            }
        }
        if(!add)
        {
            if(x!=0)
            {
                shootedfish2=randomNumber;
                //cout<<shootedfish;
                i=10;
            }
            else
                randArr2[i]=randomNumber;
            cout<<randomNumber<<endl;
        }
       }
   }
}
void check()
{
    if(!l2flag)
    {
        for(int i=0;i<7;i++)
        {
            if(randArr[i]==1)
                one=1;
            else if(randArr[i]==2)
                two=1;
            else if(randArr[i]==3)
                three=1;
            else if(randArr[i]==4)
                four=1;
            else if(randArr[i]==5)
                five=1;
            else if(randArr[i]==6)
                six=1;
            else if(randArr[i]==7)
                seven=1;
            else if(randArr[i]==8)
                eight=1;
            else if(randArr[i]==9)
                nine=1;
            else if(randArr[i]==10)
                ten=1;
            else if(randArr[i]==11)
                eleven=1;
            else if(randArr[i]==12)
                twelve=1;
        }
        atStart=false;
    }
    else
    {
        //cout<<"l2 er check function called"<<endl;
        for(int i=0;i<10;i++)
        {
            if(randArr2[i]==1)
                l2one=1;
            else if(randArr2[i]==2)
                l2two=1;
            else if(randArr2[i]==3)
                l2three=1;
            else if(randArr2[i]==4)
                l2four=1;
            else if(randArr2[i]==5)
                l2five=1;
            else if(randArr2[i]==6)
                l2six=1;
            else if(randArr2[i]==7)
                l2seven=1;
            else if(randArr2[i]==8)
                l2eight=1;
            else if(randArr2[i]==9)
                l2nine=1;
            else if(randArr2[i]==10)
                l2ten=1;
            else if(randArr2[i]==11)
                l2eleven=1;
            else if(randArr2[i]==12)
                l2twelve=1;
            else if(randArr2[i]==13)
                l2thirteen=1;
            else if(randArr2[i]==14)
                l2fourteen=1;
        }
        atStart2=false;
    }

}
void exclude(int sf)
{
    if(!l2flag)
    {
       for(int i=0;i<7;i++)
       {
        if(randArr[i]==sf)
        {
            cout<<"found";
            generateRandom(sf);
            if(shootedfish!=-1)
            {
               randArr[i]=shootedfish;
               check();
            }

        }
       }
    }
    else
    {
        for(int i=0;i<10;i++)
       {
        if(randArr2[i]==sf)
        {
            cout<<"found";
            generateRandom(sf);
            if(shootedfish2!=-1)
            {
               randArr2[i]=shootedfish2;
               check();
            }

        }
       }
    }

}
void moveMan(int a)
{
        //shoe left
        glPushMatrix();
            glTranslatef(changeX,changeY,0.0);
            glBegin(GL_QUADS);
            glColor3ub(128,64,0);
            glVertex2f(getX(-506.15-30),getY(-140.18+20));
            glVertex2f(getX(-506.15-30),getY(-150.96+20));
            glVertex2f(getX(-475.45-30),getY(-150.98+20));
            glVertex2f(getX(-475.45-30),getY(-140.18+20));

            glEnd();
            //shoe right
            glBegin(GL_QUADS);
            glColor3ub (128,64,0);
            glVertex2f(getX(-460.15-30),getY(-140.18+20));
            glVertex2f(getX(-460.15-30),getY(-150.96+20));
            glVertex2f(getX(-429.45-30),getY(-150.96+20));
            glVertex2f(getX(-429.45-30),getY(-140.18+20));

            glEnd();

            //leg left

            glBegin(GL_QUADS);
            glColor3ub(233,218,146);
            glVertex2f(getX(-498.46-30),getY(-140.18+20));
            glVertex2f(getX(-498.46-30),getY(-118.62+20));
            glVertex2f(getX(-483.08-30),getY(-118.62+20));
            glVertex2f(getX(-483.08-30),getY(-140.18+20));
            glEnd();

            //leg right

            glBegin(GL_QUADS);
            glColor3ub(233,218,146);
            glVertex2f(getX(-452.46-30),getY(-140.18+20));
            glVertex2f(getX(-452.46-30),getY(-118.62+20));
            glVertex2f(getX(-437.08-30),getY(-118.62+20));
            glVertex2f(getX(-437.08-30),getY(-140.18+20));
            glEnd();


            //pant

            glBegin(GL_QUADS);
            glColor3ub(255,0,0);
            glVertex2f(getX(-498.46-30),getY(-97.06+20));
            glVertex2f(getX(-498.46-30),getY(-118.62+20));
            glVertex2f(getX(-475.39-30),getY(-118.62+20));
            glVertex2f(getX(-475.39-30),getY(-97.06+20));

            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255,0,0);
            glVertex2f(getX(-475.39-30),getY(-97.06+20));
            glVertex2f(getX(-475.39-30),getY(-107.85+20));
            glVertex2f(getX(-460.15-30),getY(-107.85+20));
            glVertex2f(getX(-460.15-30),getY(-97.06+20));
            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(255,0,0);
            glVertex2f(getX(-460.15-30),getY(-97.06+20));
            glVertex2f(getX(-460.15-30),getY(-118.62+20));
            glVertex2f(getX(-437.08-30),getY(-118.62+20));
            glVertex2f(getX(-437.08-30),getY(-97.06+20));
            glEnd();
            /////body////

            glBegin(GL_QUADS);
            glColor3ub(0,0,255);
            glVertex2f(getX(-498.46-30),getY(-64.72+20));
            glVertex2f(getX(-498.46-30),getY(-97.06+20));
            glVertex2f(getX(-437.08-30),getY(-97.06+20));
            glVertex2f(getX(-437.08-30),getY(-64.72+20));
            glEnd();
////////left hand///////////////

        glBegin(GL_QUADS);
        glColor3ub(233,218,146);

        glVertex2f(getX(-513.84+13-30),getY(-64.72+20));
        glVertex2f(getX(-513.84+13-30),getY(-74.72+20));
        glVertex2f(getX(-498.46-30),getY(-74.72+20));
        glVertex2f(getX(-498.46-30),getY(-64.72+20));


        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(233,218,146);

        glVertex2f(getX(-523.22+13-30),getY(-64.72+20));
        glVertex2f(getX(-523.22+13-30),getY(-97.06+20-3));
        glVertex2f(getX(-513.84+13-30),getY(-97.06+20));
        glVertex2f(getX(-513.84+13-30),getY(-64.72+20));

        glEnd();

        //left hand in pocket
        glBegin(GL_QUADS);
        glColor3ub(233,218,146);
        glVertex2f(getX(-523.22+13-30),getY(-97.06+20-3));
        glVertex2f(getX(-511.22+13-30),getY(-87.06));
        glVertex2f(getX(-507.22+13-30),getY(-80.06));
        glVertex2f(getX(-513.84+13-30),getY(-97.06+20));


        glEnd();

        /////right hand////////////////


        glBegin(GL_QUADS);
        glColor3ub(233,218,146);

        glVertex2f(getX(-437.08-30),getY(-64.72+20));
        glVertex2f(getX(-437.08-30),getY(-74.72+20));
        glVertex2f(getX(-422.08-9-30),getY(-74.72+20));
        glVertex2f(getX(-422.08-9-30),getY(-64.72+20));

        glEnd();
        glBegin(GL_QUADS);
        glColor3ub(233,218,146);
        glVertex2f(getX(-422.08-9-30),getY(-64.72+20));
        glVertex2f(getX(-422.08-9-30),getY(-97.06+20));
        glVertex2f(getX(-412.08-9-30),getY(-97.06+20));
        glVertex2f(getX(-412.08-9-30),getY(-64.72+20));

        glEnd();

        //pistol in right hand
        glBegin(GL_POLYGON);
        glColor3ub(39,80,80);
        //glColor3ub(25,25,25);
        glVertex2f(getX(-422.08-9-30),getY(-97.06+20));
        glVertex2f(getX(-422.08-9-30),getY(-97.06+20-13));
        glVertex2f(getX(-422.08-9+6-30),getY(-97.06+20-13));
        glVertex2f(getX(-422.08-9+6-30),getY(-97.06+20-9));
        glVertex2f(getX(-422.08-9+2-30),getY(-97.06+20-9));
        glVertex2f(getX(-422.08-9+2-30),getY(-97.06+20-4));
        glVertex2f(getX(-422.08-9+6-30),getY(-97.06+20-4));
        glVertex2f(getX(-422.08-9+12-30),getY(-97.06+20-10)); //8
        glVertex2f(getX(-422.08-9+14-30),getY(-97.06+20-3));
        glVertex2f(getX(-422.08-9+19-30),getY(-97.06+20-3));
        glVertex2f(getX(-422.08-9+12-30),getY(-97.06+20));
        glEnd();
        //holding pistol (skin portion)
        glBegin(GL_QUADS);
        glColor3ub(233,218,146);
        glVertex2f(getX(-422.08-9+2.5-30),getY(-97.06+20-9));
        glVertex2f(getX(-422.08-9+6-30),getY(-97.06+20-9));
        glVertex2f(getX(-422.08-9+6-30),getY(-97.06+20-4));
        glVertex2f(getX(-422.08-9+2.5-30),getY(-97.06+20-4));
        glEnd();
        // the black portion of pistol
        glBegin(GL_QUADS);
        //glColor3ub(148,148,148);
        glColor3ub(25,25,25);
        glVertex2f(getX(-422.08-9+12-30),getY(-97.06+20-3));
        glVertex2f(getX(-422.08-9+12-30),getY(-97.06+20-10));
        glVertex2f(getX(-422.08-9+19-30),getY(-97.06+20-10));
        glVertex2f(getX(-422.08-9+19-30),getY(-97.06+20-3));
        glEnd();
        // bullet point of pistol
         glColor3ub(255,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-422.08-9+16.3-30),getY(-97.06+20-6.7));
         glEnd();
            ////neck//////////
            glBegin(GL_QUADS);
            glColor3ub(233,218,146);
            glVertex2f(getX(-474.99-30),getY(-53.94+20));
            glVertex2f(getX(-474.99-30),getY(-64.72+20));
            glVertex2f(getX(-459.61-30),getY(-64.72+20));
            glVertex2f(getX(-459.61-30),getY(-53.94+20));

            glEnd();
            ////////head//////////
            glBegin(GL_QUADS);
            glColor3ub(233,218,146);
            glVertex2f(getX(-490.97-30),getY(-21.63+20));
            glVertex2f(getX(-490.97-30),getY(-53.94+20));
            glVertex2f(getX(-444.23-30),getY(-53.94+20));
            glVertex2f(getX(-444.23-30),getY(-21.63+20));

            glEnd();

            //////////cap/////////////////

            glBegin(GL_QUADS);
            glColor3ub(233,0,0);
            glVertex2f(getX(-506.35-30),getY(-10.85+20));
            glVertex2f(getX(-506.35-30),getY(-21.63+20));
            glVertex2f(getX(-428.85-30),getY(-21.63+20));
            glVertex2f(getX(-428.85-30),getY(-10.85+20));

            glEnd();

            glBegin(GL_QUADS);
            glColor3ub(233,0,0);
            glVertex2f(getX(-490.97-30),getY(0.07+20));
            glVertex2f(getX(-490.97-30),getY(-10.85+20));
            glVertex2f(getX(-444.23-30),getY(-10.85+20));
            glVertex2f(getX(-444.23-30),getY(0.07+20));

            glEnd();
            /////////////eye1/////////////

        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(getX(-483.97-30),getY(-32.43+20));
        glVertex2f(getX(-483.97-30),getY(-37.8+20));
        glVertex2f(getX(-477.89-30),getY(-37.8+20));
        glVertex2f(getX(-477.89-30),getY(-32.43+20));


        glEnd();

        /////////////eye2/////////////

        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(getX(-458.0-30),getY(-32.43+20));
        glVertex2f(getX(-458.0-30),getY(-37.8+20));
        glVertex2f(getX(-451.92-30),getY(-37.8+20));
        glVertex2f(getX(-451.92-30),getY(-32.43+20));

        glEnd();


         /////////////lip/////////////

        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex2f(getX(-474.76-30),getY(-42.43+20));
        glVertex2f(getX(-474.76-30),getY(-47.8+20));
        glVertex2f(getX(-461.13-30),getY(-47.8+20));
        glVertex2f(getX(-461.13-30),getY(-42.43+20));

        glEnd();
        glPopMatrix();
        if((l2flag==true || l3flag==true) && window2==false)
    {
        //hot air balloon
    glPushMatrix();
        glTranslatef(0.8, 0.37+transBalloon, 0.5);//Rotate about the the vector (1, 2, 3)
        glColor3ub(255,127,39);
         glutSolidSphere(0.14,10,10);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.80, 0.5+transBalloon, 1.0);
        glColor3ub(255,127,39);
        glutSolidSphere(.2,10,10);
        //Sprint(.7,0,text);
    glPopMatrix();
    //
   glPushMatrix();
   glTranslatef(0.0,transBalloon,0.0);
    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);
     glVertex2f(getX(593.3),getY(-118.58-10+60));
     glVertex2f(getX(593.3),getY(-118.58-10));
     glVertex2f(getX(490.9),getY(-118.58-10));
     glVertex2f(getX(490.9),getY(-118.58-10+60));
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
     glVertex2f(getX(593.3+10),getY(-118.58-10));
     glVertex2f(getX(593.3+10),getY(-118.58-10-15));
     glVertex2f(getX(490.9-10),getY(-118.58-10-15));
     glVertex2f(getX(490.9-10),getY(-118.58-10));
    glEnd();
    //
    glColor3ub (0,0,0);
    glBegin(GL_LINES);
    //glTranslatef(0.0,transBalloon,0.0);
    glLineWidth(55);
     glVertex2f(getX(490.9),getY(-118.58-10+60));
    glVertex2f(getX(490-43),getY(-118.58-10+60+200));
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(55);
     glVertex2f(getX(593.3),getY(-118.58-10+60));
    glVertex2f(getX(593+43),getY(-118.58-10+60+200));
    glEnd();
   glPopMatrix();
    }

        glutPostRedisplay();
        float x2=changeX+getX(-460.15-30);
        float y2=changeY+getY(-97.06+20);

           //stand on the pebble without going down
        if(changeY<0.0 && (x2<s1x2+transPebble || (x2>s2x1+transPebble && x2<s2x2+transPebble) || (x2>s3x1+transPebble && x2<s3x2+transPebble) || (x2>s4x1+transPebble && x2<s4x2+transPebble)))
        {
            changeY=0.01;
            first=true;
            if(l3flag==true)
            {
                t++;
                start=true;
                if(x2<s1x2+transPebble)
                    pebble1=true;
                else if(x2>s2x1+transPebble && x2<s2x2+transPebble)
                    pebble2=true;
                else if(x2>s3x1+transPebble && x2<s3x2+transPebble)
                    pebble3=true;


            }
        }
        //man falling in the water considering a particular body height and gap within the pebbles.
        if(((x2>s1x2+transPebble && x2<s2x1+transPebble) || (x2>s2x2+transPebble && x2<s3x1+transPebble) || (x2>s3x2+transPebble && x2<s4x1+transPebble) ) && (y2<-0.10))
        {
            down=true;
            t=0;
        }
        if(y2<-0.35)
        {
            window2=true;
            window1=false;
            if(l2flag==true)
            {
                l2flag=false;
                show=false;
            }
            else if(l3flag==true)
            {
                l3flag=false;
                show3=false;
            }
            //exit(0);
        }
        //score increment
        if(x2>s2x1+transPebble && x2<s2x2+transPebble && p1==false)
        {
            //p1=true;
            //calculateScore();
            val+=10;
            p1=true;
            p1cross=true;
            t=0;
            trans=0.0;
            start=false;
        }
        else if(x2>s3x1+transPebble && x2<s3x2+transPebble && p2==false)
        {
            val+=10;
            p2=true;
            p2cross=true;
            t=0;
            trans=0.0;
            start=false;
            //calculateScore();
        }
        else if(x2>getX(487.9) && x2<getX(595.3) && p3==false && y2<getY(-118.58-10+60))
        {
            val+=10;
            p3=true;
            p3cross=true;
            t=0;
            trans=0.0;
            start=false;
            //float leg=getY(-140.18+20)+changeY;
            //float leg=getY(-118.62+20)+changeY;
            //if(y2 < getY(-118.58-10+60) && y2 > getY(-118.58-10))
             //if(changeY==0.01)
              if(l2flag==true || l3flag==true)
                 goUp=true;
            //<getY(-118.58-10)
            //glVertex2f(getX(593.3),getY(-118.58-10+60));
     //glVertex2f(getX(593.3),getY(-118.58-10));
     //glVertex2f(getX(490.9),getY(-118.58-10));
     //glVertex2f(getX(490.9),getY(-118.58-10+60));
            //calculateScore();
        }

}
void pebbleCalling()
{

    //peable 1
     glPushMatrix();
     if(pebble1=true)
        glTranslatef(0.0,trans,0.0);
     glBegin(GL_POLYGON);
     glColor3ub(127,127,127);
     /////top
     glVertex2f(getX(-613.6-40),getY(-140.18+25));
     glVertex2f(getX(-552.2-40),getY(-172.52+25));
     glVertex2f(getX(-337.3-70),getY(-161.74+25));
     glVertex2f(getX(-352.65-70),getY(-150.96+25));
     glVertex2f(getX(-337.3-70),getY(-140.18+25));
     glVertex2f(getX(-383.35-70),getY(-129.4+25));
     glVertex2f(getX(-368-70),getY(-118.62+25));
     glVertex2f(getX(-552.2-40),getY(-118.62+25));
     glEnd();

     ////lowleft
     glBegin(GL_POLYGON);
     glColor3ub(176,176,176);
     glVertex2f(getX(-613.6-40),getY(-140.18+25));
     glVertex2f(getX(-613.6-40),getY(-150.96+25));
     glVertex2f(getX(-552.2-40),getY(-194.08+25));
     glVertex2f(getX(-552.2-40),getY(-172.52+25));
     glEnd();
     ///////lowright
     glBegin(GL_POLYGON);
     glColor3ub(150,150,150);
     glVertex2f(getX(-552.2-40),getY(-172.52+25));
     glVertex2f(getX(-552.2-40),getY(-194.08+25));
     glVertex2f(getX(-321.95-70),getY(-172.52+25));
     glVertex2f(getX(-337.3-70),getY(-161.74+25));
     glEnd();
     glColor3ub(0,128,64);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-572.95+30-40),getY(-141.74+8));
     glVertex2f(getX(-592.3+30-40),getY(-172.52+3));
     glVertex2f(getX(-552.2+30-40),getY(-172.52+8));
     glEnd();
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-572.95+60-40),getY(-151.74+8));
     glVertex2f(getX(-592.3+60-40),getY(-172.52+5));
     glVertex2f(getX(-552.2+60-40),getY(-172.52+8));
     glEnd();
          //////////2nd peables///////////
     glBegin(GL_POLYGON);
     glColor3ub(127,127,127);
     if(pebble2=true)
        glTranslatef(0.0,trans,0.0);
     /////top
     glVertex2f(getX(-291.65+40),getY(-129.36-31+25));
     glVertex2f(getX(-199.55+40),getY(-161.7-31+25));
     glVertex2f(getX(0-20),getY(-161.7-31+25));
     glVertex2f(getX(-61.4-20),getY(-140.14-31+25));
     glVertex2f(getX(-15.35-20),getY(-118.58-31+25));
     glVertex2f(getX(-46.05-20),getY(-107.8-31+25));
     glVertex2f(getX(-260.95+40),getY(-107.8-31+25));
     glEnd();
     //////lowleft///////
     glBegin(GL_POLYGON);
     glColor3ub(176,176,176);
     glVertex2f(getX(-291.65+40),getY(-129.36-31+25));
     glVertex2f(getX(-291.65+40),getY(-150.92-31+25));
     glVertex2f(getX(-199.55+40),getY(-183.26-31+25));
     glVertex2f(getX(-199.55+40),getY(-161.7-31+25));
     glEnd();
     ///////lowright
     glBegin(GL_POLYGON);
     glColor3ub(150,150,150);
     glVertex2f(getX(-199.55+40),getY(-161.7-31+25));
     glVertex2f(getX(-199.55+40),getY(-183.26-31+25));
     glVertex2f(getX(0-20),getY(-183.26-31+25));
     glVertex2f(getX(0-20),getY(-161.7-31+25));
     glEnd();
     ////////lowextra//////////
     glBegin(GL_POLYGON);
     glColor3ub(176,176,176);
     glVertex2f(getX(-61.4-20),getY(-140.14-31+25));
     glVertex2f(getX(-44.515-20),getY(-145.53-31+25));
     glVertex2f(getX(-15.35-20),getY(-140.14-31+25));
     glVertex2f(getX(-15.35-20),getY(-118.58-31+25));
     glEnd();
     //////////3rd peables///////////
     glBegin(GL_POLYGON);
     glColor3ub(127,127,127);
     if(pebble3=true)
        glTranslatef(0.0,trans,0.0);
     /////top
     glVertex2f(getX(92.1+40),getY(-161.7+32));
     glVertex2f(getX(153.5+40),getY(-172.48+32));
     glVertex2f(getX(138.15+40),getY(-183.26+32));
     glVertex2f(getX(337.7-20),getY(-183.26+32));
     glVertex2f(getX(399.1-20),getY(-161.7+32));
     glVertex2f(getX(337.7-20),getY(-140.14+32));
     glVertex2f(getX(138.15+40),getY(-140.14+32));
     glEnd();
     //////lowleft///////
     glBegin(GL_POLYGON);
     glColor3ub(176,176,176);
     glVertex2f(getX(92.1+40),getY(-161.7+32));
     glVertex2f(getX(92.1+40),getY(-183.26+32));
     glVertex2f(getX(138.15+40),getY(-183.26+32));
     glVertex2f(getX(153.5+40),getY(-172.48+32));
     glEnd();
     ///////lowright
     glBegin(GL_POLYGON);
     glColor3ub(150,150,150);
     glVertex2f(getX(138.15+40),getY(-183.26+32));
     glVertex2f(getX(107.45+40),getY(-204.82+32));
     glVertex2f(getX(337.7-20),getY(-204.82+32));
     glVertex2f(getX(337.7-20),getY(-183.26+32));
     glEnd();
     glBegin(GL_POLYGON);
     glColor3ub(150,150,150);
     glVertex2f(getX(337.7-20),getY(-183.26+32));
     glVertex2f(getX(337.7-20),getY(-204.82+32));
     glVertex2f(getX(399.1-20),getY(-183.26+32));
     glVertex2f(getX(399.1-20),getY(-161.7+32));
     glEnd();
     glPopMatrix();
    /////////4th peables///////////
     glBegin(GL_POLYGON);
     glColor3ub(127,127,127);
     /////top
     glVertex2f(getX(491.2),getY(-140.14-10));
     glVertex2f(getX(491.2),getY(-161.7-10));
     //glVertex2f(getX(521.9),getY(-172.48));
     glVertex2f(getX(614.0),getY(-161.7-10));
     glVertex2f(getX(598.65),getY(-150.92-10));
     glVertex2f(getX(629.35),getY(-140.14-10));
     glVertex2f(getX(583.3),getY(-118.58-10));
     glVertex2f(getX(521.9-20),getY(-118.58-10));
     glEnd();
     //////lowleft///////
     glBegin(GL_POLYGON);
     glColor3ub(150,150,150);
     glVertex2f(getX(491.2),getY(-161.7-10));
     glVertex2f(getX(491.2),getY(-183.26-10));
     glVertex2f(getX(644.7),getY(-183.26-10));
     glVertex2f(getX(614.0),getY(-161.7-10));
     glEnd();
     ///////lowright
     glBegin(GL_POLYGON);
     glColor3ub(176,176,176);
     glVertex2f(getX(598.65),getY(-150.92-10));
      glVertex2f(getX(614.0),getY(-161.7-10));
     glVertex2f(getX(629.35),getY(-156.31-10));
     glVertex2f(getX(629.35),getY(-140.14-10));
     glEnd();



}

void fishCalling()
{
    if(l2flag==true || l3flag==true)
    {
        if(atStart2)
           check();
           //cout<<"ha eta second arr ta";
       if(l2one==1)
       {
              //cout<<l2one<<endl;
            /////////fish1
             glPushMatrix();
             glTranslatef(transFish, 0.0, 0.0);
             //body
             glBegin(GL_POLYGON);
             glColor3ub(135,156,61);
             glVertex2f(getX(-615),getY(-269.54));
             glVertex2f(getX(-608),getY(-283.1));
             glVertex2f(getX(-563),getY(-283.1));
             glVertex2f(getX(-546.5),getY(-269.54));
             glVertex2f(getX(-563),getY(-255.98));
             glVertex2f(getX(-608),getY(-255.98));
             glEnd();
             //tail
             glColor3ub(61,61,150);
             glBegin(GL_TRIANGLES);
             glVertex2f(getX(-551.5),getY(-269.54));
             glVertex2f(getX(-530),getY(-291.1));
             glVertex2f(getX(-530),getY(-247.98));
             glEnd();
             //uppweWing
             glColor3ub(61,61,150);
             glBegin(GL_POLYGON);
             glVertex2f(getX(-600),getY(-249.2));
             glVertex2f(getX(-600),getY(-255.98));
             glVertex2f(getX(-570),getY(-255.98));
             glVertex2f(getX(-555),getY(-249.2));
             glVertex2f(getX(-585),getY(-242.42));
             glEnd();
             //lowerWing
             glColor3ub(61,61,150);
             glBegin(GL_QUADS);
             glVertex2f(getX(-602),getY(-283.1));
             glVertex2f(getX(-587),getY(-289.88));
             glVertex2f(getX(-550),getY(-289.88));
             glVertex2f(getX(-565),getY(-283.1));
             glEnd();
             //eye
             glColor3ub(0,0,0);
             glPointSize(3.0);
             glBegin(GL_POINTS);
             glVertex2f(getX(-602.5),getY(-264.76));
             glEnd();
             ////lip
             glBegin(GL_LINES);
             glVertex2f(getX(-615),getY(-269.54));
             glVertex2f(getX(-600),getY(-269.54));
             glEnd();

             glPopMatrix();
       }
      if(l2two==1)
      {
         //////fish2

         glPushMatrix();
         glTranslatef(transFish+0.10, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615+95),getY(-269.54+10));
         glVertex2f(getX(-608+95),getY(-283.1+10));
         glVertex2f(getX(-563+95),getY(-283.1+10));
         glVertex2f(getX(-546.5+95),getY(-269.54+10));
         glVertex2f(getX(-563+95),getY(-255.98+10));
         glVertex2f(getX(-608+95),getY(-255.98+10));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5+95),getY(-269.54+10));
         glVertex2f(getX(-530+95),getY(-291.1+10));
         glVertex2f(getX(-530+95),getY(-247.98+10));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600+95),getY(-249.2+10));
         glVertex2f(getX(-600+95),getY(-255.98+10));
         glVertex2f(getX(-570+95),getY(-255.98+10));
         glVertex2f(getX(-555+95),getY(-249.2+10));
         glVertex2f(getX(-585+95),getY(-242.42+10));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602+95),getY(-283.1+10));
         glVertex2f(getX(-587+95),getY(-289.88+10));
         glVertex2f(getX(-550+95),getY(-289.88+10));
         glVertex2f(getX(-565+95),getY(-283.1+10));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5+95),getY(-264.76+10));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615+95),getY(-269.54+10));
         glVertex2f(getX(-600+95),getY(-269.54+10));
         glEnd();

         glPopMatrix();
      }

      if(l2three==1)
      {
          //////fish3
            glPushMatrix();
         glTranslatef(transFish+0.4, 0.0, 0.0);

         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-20));
         glVertex2f(getX(-608),getY(-283.1-20));
         glVertex2f(getX(-563),getY(-283.1-20));
         glVertex2f(getX(-546.5),getY(-269.54-20));
         glVertex2f(getX(-563),getY(-255.98-20));
         glVertex2f(getX(-608),getY(-255.98-20));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-20));
         glVertex2f(getX(-530),getY(-291.1-20));
         glVertex2f(getX(-530),getY(-247.98-20));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-20));
         glVertex2f(getX(-600),getY(-255.98-20));
         glVertex2f(getX(-570),getY(-255.98-20));
         glVertex2f(getX(-555),getY(-249.2-20));
         glVertex2f(getX(-585),getY(-242.42-20));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-20));
         glVertex2f(getX(-587),getY(-289.88-20));
         glVertex2f(getX(-550),getY(-289.88-20));
         glVertex2f(getX(-565),getY(-283.1-20));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-20));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-20));
         glVertex2f(getX(-600),getY(-269.54-20));
         glEnd();

         glPopMatrix();
      }

      if(l2four==1)
      {
         //////fish4
        glPushMatrix();
         glTranslatef(transFish+0.62, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54+30));
         glVertex2f(getX(-608),getY(-283.1+30));
         glVertex2f(getX(-563),getY(-283.1+30));
         glVertex2f(getX(-546.5),getY(-269.54+30));
         glVertex2f(getX(-563),getY(-255.98+30));
         glVertex2f(getX(-608),getY(-255.98+30));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54+30));
         glVertex2f(getX(-530),getY(-291.1+30));
         glVertex2f(getX(-530),getY(-247.98+30));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2+30));
         glVertex2f(getX(-600),getY(-255.98+30));
         glVertex2f(getX(-570),getY(-255.98+30));
         glVertex2f(getX(-555),getY(-249.2+30));
         glVertex2f(getX(-585),getY(-242.42+30));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1+30));
         glVertex2f(getX(-587),getY(-289.88+30));
         glVertex2f(getX(-550),getY(-289.88+30));
         glVertex2f(getX(-565),getY(-283.1+30));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76+30));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54+30));
         glVertex2f(getX(-600),getY(-269.54+30));
         glEnd();

         glPopMatrix();
      }

      if(l2five==1)
      {
         //////fish5
        //body
        glPushMatrix();
         glTranslatef(transFish+0.79, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-9));
         glVertex2f(getX(-608),getY(-283.1-9));
         glVertex2f(getX(-563),getY(-283.1-9));
         glVertex2f(getX(-546.5),getY(-269.54-9));
         glVertex2f(getX(-563),getY(-255.98-9));
         glVertex2f(getX(-608),getY(-255.98-9));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-9));
         glVertex2f(getX(-530),getY(-291.1-9));
         glVertex2f(getX(-530),getY(-247.98-9));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-9));
         glVertex2f(getX(-600),getY(-255.98-9));
         glVertex2f(getX(-570),getY(-255.98-9));
         glVertex2f(getX(-555),getY(-249.2-9));
         glVertex2f(getX(-585),getY(-242.42-9));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-9));
         glVertex2f(getX(-587),getY(-289.88-9));
         glVertex2f(getX(-550),getY(-289.88-9));
         glVertex2f(getX(-565),getY(-283.1-9));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-9));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-9));
         glVertex2f(getX(-600),getY(-269.54-9));
         glEnd();

         glPopMatrix();

      }

    if(l2six==1)
      {
         //////fish6
         glPushMatrix();
         glTranslatef(transFish+0.96, 0.0, 0.0);
          //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54+15));
         glVertex2f(getX(-608),getY(-283.1+15));
         glVertex2f(getX(-563),getY(-283.1+15));
         glVertex2f(getX(-546.5),getY(-269.54+15));
         glVertex2f(getX(-563),getY(-255.98+15));
         glVertex2f(getX(-608),getY(-255.98+15));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54+15));
         glVertex2f(getX(-530),getY(-291.1+15));
         glVertex2f(getX(-530),getY(-247.98+15));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2+15));
         glVertex2f(getX(-600),getY(-255.98+15));
         glVertex2f(getX(-570),getY(-255.98+15));
         glVertex2f(getX(-555),getY(-249.2+15));
         glVertex2f(getX(-585),getY(-242.42+15));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1+15));
         glVertex2f(getX(-587),getY(-289.88+15));
         glVertex2f(getX(-550),getY(-289.88+15));
         glVertex2f(getX(-565),getY(-283.1+15));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76+15));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54+15));
         glVertex2f(getX(-600),getY(-269.54+15));
         glEnd();

         glPopMatrix();
      }

      if(l2seven==1)
      {
         //////fish7

         glPushMatrix();
         glTranslatef(transFish+1.18, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-35));
         glVertex2f(getX(-608),getY(-283.1-35));
         glVertex2f(getX(-563),getY(-283.1-35));
         glVertex2f(getX(-546.5),getY(-269.54-35));
         glVertex2f(getX(-563),getY(-255.98-35));
         glVertex2f(getX(-608),getY(-255.98-35));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-35));
         glVertex2f(getX(-530),getY(-291.1-35));
         glVertex2f(getX(-530),getY(-247.98-35));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-35));
         glVertex2f(getX(-600),getY(-255.98-35));
         glVertex2f(getX(-570),getY(-255.98-35));
         glVertex2f(getX(-555),getY(-249.2-35));
         glVertex2f(getX(-585),getY(-242.42-35));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-35));
         glVertex2f(getX(-587),getY(-289.88-35));
         glVertex2f(getX(-550),getY(-289.88-35));
         glVertex2f(getX(-565),getY(-283.1-35));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-35));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-35));
         glVertex2f(getX(-600),getY(-269.54-35));
         glEnd();

         glPopMatrix();
      }
      if(l2eight==1)
      {
         //////fish8
         glPushMatrix();
         glTranslatef(transFish+1.3, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54+40));
         glVertex2f(getX(-608),getY(-283.1+40));
         glVertex2f(getX(-563),getY(-283.1+40));
         glVertex2f(getX(-546.5),getY(-269.54+40));
         glVertex2f(getX(-563),getY(-255.98+40));
         glVertex2f(getX(-608),getY(-255.98+40));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54+40));
         glVertex2f(getX(-530),getY(-291.1+40));
         glVertex2f(getX(-530),getY(-247.98+40));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2+40));
         glVertex2f(getX(-600),getY(-255.98+40));
         glVertex2f(getX(-570),getY(-255.98+40));
         glVertex2f(getX(-555),getY(-249.2+40));
         glVertex2f(getX(-585),getY(-242.42+40));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1+40));
         glVertex2f(getX(-587),getY(-289.88+40));
         glVertex2f(getX(-550),getY(-289.88+40));
         glVertex2f(getX(-565),getY(-283.1+40));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76+40));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54+40));
         glVertex2f(getX(-600),getY(-269.54+40));
         glEnd();

         glPopMatrix();
      }

      if(l2nine==1)
      {
           //////fish9
         glPushMatrix();
         glTranslatef(transFish+1.5, 0.0, 0.0);
          //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-5));
         glVertex2f(getX(-608),getY(-283.1-5));
         glVertex2f(getX(-563),getY(-283.1-5));
         glVertex2f(getX(-546.5),getY(-269.54-5));
         glVertex2f(getX(-563),getY(-255.98-5));
         glVertex2f(getX(-608),getY(-255.98-5));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-5));
         glVertex2f(getX(-530),getY(-291.1-5));
         glVertex2f(getX(-530),getY(-247.98-5));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-5));
         glVertex2f(getX(-600),getY(-255.98-5));
         glVertex2f(getX(-570),getY(-255.98-5));
         glVertex2f(getX(-555),getY(-249.2-5));
         glVertex2f(getX(-585),getY(-242.42-5));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-5));
         glVertex2f(getX(-587),getY(-289.88-5));
         glVertex2f(getX(-550),getY(-289.88-5));
         glVertex2f(getX(-565),getY(-283.1-5));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-5));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-5));
         glVertex2f(getX(-600),getY(-269.54-5));
         glEnd();

         glPopMatrix();
      }

      if(l2ten==1)
      {
      //////fish10
         glPushMatrix();
         glTranslatef(transFish+1.66, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-20));
         glVertex2f(getX(-608),getY(-283.1-20));
         glVertex2f(getX(-563),getY(-283.1-20));
         glVertex2f(getX(-546.5),getY(-269.54-20));
         glVertex2f(getX(-563),getY(-255.98-20));
         glVertex2f(getX(-608),getY(-255.98-20));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-20));
         glVertex2f(getX(-530),getY(-291.1-20));
         glVertex2f(getX(-530),getY(-247.98-20));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-20));
         glVertex2f(getX(-600),getY(-255.98-20));
         glVertex2f(getX(-570),getY(-255.98-20));
         glVertex2f(getX(-555),getY(-249.2-20));
         glVertex2f(getX(-585),getY(-242.42-20));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-20));
         glVertex2f(getX(-587),getY(-289.88-20));
         glVertex2f(getX(-550),getY(-289.88-20));
         glVertex2f(getX(-565),getY(-283.1-20));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-20));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-20));
         glVertex2f(getX(-600),getY(-269.54-20));
         glEnd();

         glPopMatrix();
      }

      if(l2eleven==1)
      {
       //////fish11
         glPushMatrix();
         glTranslatef(transFish+1.9,0.0,0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54+25));
         glVertex2f(getX(-608),getY(-283.1+25));
         glVertex2f(getX(-563),getY(-283.1+25));
         glVertex2f(getX(-546.5),getY(-269.54+25));
         glVertex2f(getX(-563),getY(-255.98+25));
         glVertex2f(getX(-608),getY(-255.98+25));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54+25));
         glVertex2f(getX(-530),getY(-291.1+25));
         glVertex2f(getX(-530),getY(-247.98+25));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2+25));
         glVertex2f(getX(-600),getY(-255.98+25));
         glVertex2f(getX(-570),getY(-255.98+25));
         glVertex2f(getX(-555),getY(-249.2+25));
         glVertex2f(getX(-585),getY(-242.42+25));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1+25));
         glVertex2f(getX(-587),getY(-289.88+25));
         glVertex2f(getX(-550),getY(-289.88+25));
         glVertex2f(getX(-565),getY(-283.1+25));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76+25));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54+25));
         glVertex2f(getX(-600),getY(-269.54+25));
         glEnd();

         glPopMatrix();

      }

       if(l2twelve==1)
       {
         //////fish12
         glPushMatrix();
         glTranslatef(transFish+2.18, 0.0, 0.0);
          //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-10));
         glVertex2f(getX(-608),getY(-283.1-10));
         glVertex2f(getX(-563),getY(-283.1-10));
         glVertex2f(getX(-546.5),getY(-269.54-10));
         glVertex2f(getX(-563),getY(-255.98-10));
         glVertex2f(getX(-608),getY(-255.98-10));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-10));
         glVertex2f(getX(-530),getY(-291.1-10));
         glVertex2f(getX(-530),getY(-247.98-10));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-10));
         glVertex2f(getX(-600),getY(-255.98-10));
         glVertex2f(getX(-570),getY(-255.98-10));
         glVertex2f(getX(-555),getY(-249.2-10));
         glVertex2f(getX(-585),getY(-242.42-10));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-10));
         glVertex2f(getX(-587),getY(-289.88-10));
         glVertex2f(getX(-550),getY(-289.88-10));
         glVertex2f(getX(-565),getY(-283.1-10));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-10));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-10));
         glVertex2f(getX(-600),getY(-269.54-10));
         glEnd();

         glPopMatrix();
       }
       //fish 13
       if(l2thirteen==1)
      {
        /////////fish13
         glPushMatrix();
         glTranslatef(transFish+2.4, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54+30));
         glVertex2f(getX(-608),getY(-283.1+30));
         glVertex2f(getX(-563),getY(-283.1+30));
         glVertex2f(getX(-546.5),getY(-269.54+30));
         glVertex2f(getX(-563),getY(-255.98+30));
         glVertex2f(getX(-608),getY(-255.98+30));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54+30));
         glVertex2f(getX(-530),getY(-291.1+30));
         glVertex2f(getX(-530),getY(-247.98+30));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2+30));
         glVertex2f(getX(-600),getY(-255.98+30));
         glVertex2f(getX(-570),getY(-255.98+30));
         glVertex2f(getX(-555),getY(-249.2+30));
         glVertex2f(getX(-585),getY(-242.42+30));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1+30));
         glVertex2f(getX(-587),getY(-289.88+30));
         glVertex2f(getX(-550),getY(-289.88+30));
         glVertex2f(getX(-565),getY(-283.1+30));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76+30));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54+30));
         glVertex2f(getX(-600),getY(-269.54+30));
         glEnd();

         glPopMatrix();
      }
      //fish 14
      if(l2fourteen==1)
      {
        /////////fish14
         glPushMatrix();
         glTranslatef(transFish+2.58, 0.0, 0.0);
         //body
         glBegin(GL_POLYGON);
         glColor3ub(135,156,61);
         glVertex2f(getX(-615),getY(-269.54-30));
         glVertex2f(getX(-608),getY(-283.1-30));
         glVertex2f(getX(-563),getY(-283.1-30));
         glVertex2f(getX(-546.5),getY(-269.54-30));
         glVertex2f(getX(-563),getY(-255.98-30));
         glVertex2f(getX(-608),getY(-255.98-30));
         glEnd();
         //tail
         glColor3ub(61,61,150);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(-551.5),getY(-269.54-30));
         glVertex2f(getX(-530),getY(-291.1-30));
         glVertex2f(getX(-530),getY(-247.98-30));
         glEnd();
         //uppweWing
         glColor3ub(61,61,150);
         glBegin(GL_POLYGON);
         glVertex2f(getX(-600),getY(-249.2-30));
         glVertex2f(getX(-600),getY(-255.98-30));
         glVertex2f(getX(-570),getY(-255.98-30));
         glVertex2f(getX(-555),getY(-249.2-30));
         glVertex2f(getX(-585),getY(-242.42-30));
         glEnd();
         //lowerWing
         glColor3ub(61,61,150);
         glBegin(GL_QUADS);
         glVertex2f(getX(-602),getY(-283.1-30));
         glVertex2f(getX(-587),getY(-289.88-30));
         glVertex2f(getX(-550),getY(-289.88-30));
         glVertex2f(getX(-565),getY(-283.1-30));
         glEnd();
         //eye
         glColor3ub(0,0,0);
         glPointSize(3.0);
         glBegin(GL_POINTS);
         glVertex2f(getX(-602.5),getY(-264.76-30));
         glEnd();
         ////lip
         glBegin(GL_LINES);
         glVertex2f(getX(-615),getY(-269.54-30));
         glVertex2f(getX(-600),getY(-269.54-30));
         glEnd();

         glPopMatrix();
      }
    }
    else
    {
        if(atStart)
           check();
        if(one==1)
    {
    /////////fish1
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     //body
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3),getY(-301.88));
     glVertex2f(getX(-582.96),getY(-312.66));
     glVertex2f(getX(-544.61),getY(-312.66));
     glVertex2f(getX(-528.872),getY(-301.88));
     glVertex2f(getX(-544.61),getY(-291.1));
     glVertex2f(getX(-582.96),getY(-291.1));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93),getY(-285.71));
     glVertex2f(getX(-534.872),getY(-301.88));
     glVertex2f(getX(-518.532),getY(-301.88));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872),getY(-301.88));
     glVertex2f(getX(-513.93),getY(-318.05));
     glVertex2f(getX(-518.532),getY(-301.88));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28),getY(-280.32));
     glVertex2f(getX(-567.62),getY(-291.1));
     glVertex2f(getX(-544.6),getY(-291.1));
     glVertex2f(getX(-532.94),getY(-286.32));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5),getY(-312.66));
     glVertex2f(getX(-560.28),getY(-323.44));
     glVertex2f(getX(-536.94),getY(-318.05));
     glVertex2f(getX(-544.61),getY(-312.66));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96),getY(-297.88));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3),getY(-301.88));
     glVertex2f(getX(-588.3),getY(-301.88));
     glEnd();

     glPopMatrix();
  }
  if(two==1)
  {
     //////fish2
     //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-383.54),getY(-271.2));
     glVertex2f(getX(-368.2),getY(-281.98));
     glVertex2f(getX(-329.85),getY(-281.98));
     glVertex2f(getX(-310.112),getY(-271.2));
     glVertex2f(getX(-329.85),getY(-260.5));
     glVertex2f(getX(-368.2),getY(-260.5));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+214.76),getY(-285.71+30.68));
     glVertex2f(getX(-534.872+214.76),getY(-301.88+30.68));
     glVertex2f(getX(-518.532+214.76),getY(-301.88+30.68));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+214.76),getY(-301.88+30.68));
     glVertex2f(getX(-513.93+214.76),getY(-318.05+30.68));
     glVertex2f(getX(-518.532+214.76),getY(-301.88+30.68));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+214.76),getY(-280.32+30.68));
     glVertex2f(getX(-567.62+214.76),getY(-291.1+30.68));
     glVertex2f(getX(-544.6+214.76),getY(-291.1+30.68));
     glVertex2f(getX(-532.94+214.76),getY(-286.32+30.68));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+214.76),getY(-312.66+30.68));
     glVertex2f(getX(-560.28+214.76),getY(-323.44+30.68));
     glVertex2f(getX(-536.94+214.76),getY(-318.05+30.68));
     glVertex2f(getX(-544.61+214.76),getY(-312.66+30.68));
     glEnd();
     glBegin(GL_POINTS);
     glVertex2f(getX(-575.5+214.76),getY(-312.66+30.68));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+214.76),getY(-297.88+30.68));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+214.76),getY(-301.88+30.68));
     glVertex2f(getX(-588.3+214.76),getY(-301.88+30.68));
     glEnd();

     glPopMatrix();
  }
  if(three==1)
  {
      //////fish3
      //body

        glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+429.52),getY(-301.88));
     glVertex2f(getX(-582.96+429.52),getY(-312.66));
     glVertex2f(getX(-544.61+429.52),getY(-312.66));
     glVertex2f(getX(-528.872+429.52),getY(-301.88));
     glVertex2f(getX(-544.61+429.52),getY(-291.1));
     glVertex2f(getX(-582.96+429.52),getY(-291.1));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+429.52),getY(-285.71));
     glVertex2f(getX(-534.872+429.52),getY(-301.88));
     glVertex2f(getX(-518.532+429.52),getY(-301.88));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+429.52),getY(-301.88));
     glVertex2f(getX(-513.93+429.52),getY(-318.05));
     glVertex2f(getX(-518.532+429.52),getY(-301.88));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+429.52),getY(-280.32));
     glVertex2f(getX(-567.62+429.52),getY(-291.1));
     glVertex2f(getX(-544.6+429.52),getY(-291.1));
     glVertex2f(getX(-532.94+429.52),getY(-286.32));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+429.52),getY(-312.66));
     glVertex2f(getX(-560.28+429.52),getY(-323.44));
     glVertex2f(getX(-536.94+429.52),getY(-318.05));
     glVertex2f(getX(-544.61+429.52),getY(-312.66));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+429.52),getY(-297.88));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+429.52),getY(-301.88));
     glVertex2f(getX(-588.3+429.52),getY(-301.88));
     glEnd();
      glPopMatrix();
  }
  if(four==1)
  {
     //////fish4
    //body
    glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+644.28),getY(-301.88+21.56));
     glVertex2f(getX(-582.96+644.28),getY(-312.66+21.56));
     glVertex2f(getX(-544.61+644.28),getY(-312.66+21.56));
     glVertex2f(getX(-528.872+644.28),getY(-301.88+21.56));
     glVertex2f(getX(-544.61+644.28),getY(-291.1+21.56));
     glVertex2f(getX(-582.96+644.28),getY(-291.1+21.56));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+644.28),getY(-285.71+21.56));
     glVertex2f(getX(-534.872+644.28),getY(-301.88+21.56));
     glVertex2f(getX(-518.532+644.28),getY(-301.88+21.56));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+644.28),getY(-301.88+21.56));
     glVertex2f(getX(-513.93+644.28),getY(-318.05+21.56));
     glVertex2f(getX(-518.532+644.28),getY(-301.88+21.56));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+644.28),getY(-280.32+21.56));
     glVertex2f(getX(-567.62+644.28),getY(-291.1+21.56));
     glVertex2f(getX(-544.6+644.28),getY(-291.1+21.56));
     glVertex2f(getX(-532.94+644.28),getY(-286.32+21.56));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+644.28),getY(-312.66+21.56));
     glVertex2f(getX(-560.28+644.28),getY(-323.44+21.56));
     glVertex2f(getX(-536.94+644.28),getY(-318.05+21.56));
     glVertex2f(getX(-544.61+644.28),getY(-312.66+21.56));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+644.28),getY(-297.88+21.56));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+644.28),getY(-301.88+21.56));
     glVertex2f(getX(-588.3+644.28),getY(-301.88+21.56));
     glEnd();
      glPopMatrix();
  }
  if(five==1)
  {
     //////fish5
    //body
    glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+859.04),getY(-301.88+26.95));
     glVertex2f(getX(-582.96+859.04),getY(-312.66+26.95));
     glVertex2f(getX(-544.61+859.04),getY(-312.66+26.95));
     glVertex2f(getX(-528.872+859.04),getY(-301.88+26.95));
     glVertex2f(getX(-544.61+859.04),getY(-291.1+26.95));
     glVertex2f(getX(-582.96+859.04),getY(-291.1+26.95));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+859.04),getY(-285.71+26.95));
     glVertex2f(getX(-534.872+859.04),getY(-301.88+26.95));
     glVertex2f(getX(-518.532+859.04),getY(-301.88+26.95));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+859.04),getY(-301.88+26.95));
     glVertex2f(getX(-513.93+859.04),getY(-318.05+26.95));
     glVertex2f(getX(-518.532+859.04),getY(-301.88+26.95));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+859.04),getY(-280.32+26.95));
     glVertex2f(getX(-567.62+859.04),getY(-291.1+26.95));
     glVertex2f(getX(-544.6+859.04),getY(-291.1+26.95));
     glVertex2f(getX(-532.94+859.04),getY(-286.32+26.95));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+859.04),getY(-312.66+26.95));
     glVertex2f(getX(-560.28+859.04),getY(-323.44+26.95));
     glVertex2f(getX(-536.94+859.04),getY(-318.05+26.95));
     glVertex2f(getX(-544.61+859.04),getY(-312.66+26.95));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+859.04),getY(-297.88+26.95));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+859.04),getY(-301.88+26.95));
     glVertex2f(getX(-588.3+859.04),getY(-301.88+26.95));
     glEnd();
     glPopMatrix();

  }
  if(six==1)
  {
     //////fish6
     //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+1073.8),getY(-301.88));
     glVertex2f(getX(-582.96+1073.8),getY(-312.66));
     glVertex2f(getX(-544.61+1073.8),getY(-312.66));
     glVertex2f(getX(-528.872+1073.8),getY(-301.88));
     glVertex2f(getX(-544.61+1073.8),getY(-291.1));
     glVertex2f(getX(-582.96+1073.8),getY(-291.1));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+1073.8),getY(-285.71));
     glVertex2f(getX(-534.872+1073.8),getY(-301.88));
     glVertex2f(getX(-518.532+1073.8),getY(-301.88));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+1073.8),getY(-301.88));
     glVertex2f(getX(-513.93+1073.8),getY(-318.05));
     glVertex2f(getX(-518.532+1073.8),getY(-301.88));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+1073.8),getY(-280.32));
     glVertex2f(getX(-567.62+1073.8),getY(-291.1));
     glVertex2f(getX(-544.6+1073.8),getY(-291.1));
     glVertex2f(getX(-532.94+1073.8),getY(-286.32));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+1073.8),getY(-312.66));
     glVertex2f(getX(-560.28+1073.8),getY(-323.44));
     glVertex2f(getX(-536.94+1073.8),getY(-318.05));
     glVertex2f(getX(-544.61+1073.8),getY(-312.66));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+1073.8),getY(-297.88));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+1073.8),getY(-301.88));
     glVertex2f(getX(-588.3+1073.8),getY(-301.88));
     glEnd();
      glPopMatrix();
  }
  if(seven==1)
  {
     //////fish7
     //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3-40),getY(-301.88+80));
     glVertex2f(getX(-582.96-40),getY(-312.66+80));
     glVertex2f(getX(-544.61-40),getY(-312.66+80));
     glVertex2f(getX(-528.872-40),getY(-301.88+80));
     glVertex2f(getX(-544.61-40),getY(-291.1+80));
     glVertex2f(getX(-582.96-40),getY(-291.1+80));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93-40),getY(-285.71+80));
     glVertex2f(getX(-534.872-40),getY(-301.88+80));
     glVertex2f(getX(-518.532-40),getY(-301.88+80));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872-40),getY(-301.88+80));
     glVertex2f(getX(-513.93-40),getY(-318.05+80));
     glVertex2f(getX(-518.532-40),getY(-301.88+80));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28-40),getY(-280.32+80));
     glVertex2f(getX(-567.62-40),getY(-291.1+80));
     glVertex2f(getX(-544.6-40),getY(-291.1+80));
     glVertex2f(getX(-532.94-40),getY(-286.32+80));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5-40),getY(-312.66+80));
     glVertex2f(getX(-560.28-40),getY(-323.44+80));
     glVertex2f(getX(-536.94-40),getY(-318.05+80));
     glVertex2f(getX(-544.61-40),getY(-312.66+80));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96-40),getY(-297.88+80));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3-40),getY(-301.88+80));
     glVertex2f(getX(-588.3-40),getY(-301.88+80));
     glEnd();
      glPopMatrix();
  }
  if(eight==1)
  {
     //////fish8
     //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-383.54-50),getY(-271.2+58));
     glVertex2f(getX(-368.2-50),getY(-281.98+58));
     glVertex2f(getX(-329.85-50),getY(-281.98+58));
     glVertex2f(getX(-310.112-50),getY(-271.2+58));
     glVertex2f(getX(-329.85-50),getY(-260.5+58));
     glVertex2f(getX(-368.2-50),getY(-260.5+58));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+214.76-50),getY(-285.71+30.68+58));
     glVertex2f(getX(-534.872+214.76-50),getY(-301.88+30.68+58));
     glVertex2f(getX(-518.532+214.76-50),getY(-301.88+30.68+58));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+214.76-50),getY(-301.88+30.68+58));
     glVertex2f(getX(-513.93+214.76-50),getY(-318.05+30.68+58));
     glVertex2f(getX(-518.532+214.76-50),getY(-301.88+30.68+58));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+214.76-50),getY(-280.32+30.68+58));
     glVertex2f(getX(-567.62+214.76-50),getY(-291.1+30.68+58));
     glVertex2f(getX(-544.6+214.76-50),getY(-291.1+30.68+58));
     glVertex2f(getX(-532.94+214.76-50),getY(-286.32+30.68+58));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+214.76-50),getY(-312.66+30.68+58));
     glVertex2f(getX(-560.28+214.76-50),getY(-323.44+30.68+58));
     glVertex2f(getX(-536.94+214.76-50),getY(-318.05+30.68+58));
     glVertex2f(getX(-544.61+214.76-50),getY(-312.66+30.68+58));
     glEnd();
     glBegin(GL_POINTS);
     glVertex2f(getX(-575.5+214.76-50),getY(-312.66+30.68+58));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+214.76-50),getY(-297.88+30.68+58));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+214.76-50),getY(-301.88+30.68+58));
     glVertex2f(getX(-588.3+214.76-50),getY(-301.88+30.68+58));
     glEnd();
      glPopMatrix();
  }
  if(nine==1)
  {
       //////fish9
    //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+429.52+70),getY(-301.88+58));
     glVertex2f(getX(-582.96+429.52+70),getY(-312.66+58));
     glVertex2f(getX(-544.61+429.52+70),getY(-312.66+58));
     glVertex2f(getX(-528.872+429.52+70),getY(-301.88+58));
     glVertex2f(getX(-544.61+429.52+70),getY(-291.1+58));
     glVertex2f(getX(-582.96+429.52+70),getY(-291.1+58));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+429.52+70),getY(-285.71+58));
     glVertex2f(getX(-534.872+429.52+70),getY(-301.88+58));
     glVertex2f(getX(-518.532+429.52+70),getY(-301.88+58));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+429.52+70),getY(-301.88+58));
     glVertex2f(getX(-513.93+429.52+70),getY(-318.05+58));
     glVertex2f(getX(-518.532+429.52+70),getY(-301.88+58));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+429.52+70),getY(-280.32+58));
     glVertex2f(getX(-567.62+429.52+70),getY(-291.1+58));
     glVertex2f(getX(-544.6+429.52+70),getY(-291.1+58));
     glVertex2f(getX(-532.94+429.52+70),getY(-286.32+58));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+429.52+70),getY(-312.66+58));
     glVertex2f(getX(-560.28+429.52+70),getY(-323.44+58));
     glVertex2f(getX(-536.94+429.52+70),getY(-318.05+58));
     glVertex2f(getX(-544.61+429.52+70),getY(-312.66+58));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+429.52+70),getY(-297.88+58));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+429.52+70),getY(-301.88+58));
     glVertex2f(getX(-588.3+429.52+70),getY(-301.88+58));
     glEnd();
      glPopMatrix();
  }
  if(ten==1)
  {
  //////fish10
    //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+644.28+100),getY(-301.88+21.56+50));
     glVertex2f(getX(-582.96+644.28+100),getY(-312.66+21.56+50));
     glVertex2f(getX(-544.61+644.28+100),getY(-312.66+21.56+50));
     glVertex2f(getX(-528.872+644.28+100),getY(-301.88+21.56+50));
     glVertex2f(getX(-544.61+644.28+100),getY(-291.1+21.56+50));
     glVertex2f(getX(-582.96+644.28+100),getY(-291.1+21.56+50));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+644.28+100),getY(-285.71+21.56+50));
     glVertex2f(getX(-534.872+644.28+100),getY(-301.88+21.56+50));
     glVertex2f(getX(-518.532+644.28+100),getY(-301.88+21.56+50));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+644.28+100),getY(-301.88+21.56+50));
     glVertex2f(getX(-513.93+644.28+100),getY(-318.05+21.56+50));
     glVertex2f(getX(-518.532+644.28+100),getY(-301.88+21.56+50));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+644.28+100),getY(-280.32+21.56+50));
     glVertex2f(getX(-567.62+644.28+100),getY(-291.1+21.56+50));
     glVertex2f(getX(-544.6+644.28+100),getY(-291.1+21.56+50));
     glVertex2f(getX(-532.94+644.28+100),getY(-286.32+21.56+50));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+644.28+100),getY(-312.66+21.56+50));
     glVertex2f(getX(-560.28+644.28+100),getY(-323.44+21.56+50));
     glVertex2f(getX(-536.94+644.28+100),getY(-318.05+21.56+50));
     glVertex2f(getX(-544.61+644.28+100),getY(-312.66+21.56+50));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+644.28+100),getY(-297.88+21.56+50));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+644.28+100),getY(-301.88+21.56+50));
     glVertex2f(getX(-588.3+644.28+100),getY(-301.88+21.56+50));
     glEnd();
      glPopMatrix();
  }
  if(eleven==1)
  {
   //////fish11
    //body
     glPushMatrix();
     glTranslatef(transFish,0.0,0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+859.04+100),getY(-301.88+26.95+45));
     glVertex2f(getX(-582.96+859.04+100),getY(-312.66+26.95+45));
     glVertex2f(getX(-544.61+859.04+100),getY(-312.66+26.95+45));
     glVertex2f(getX(-528.872+859.04+100),getY(-301.88+26.95+45));
     glVertex2f(getX(-544.61+859.04+100),getY(-291.1+26.95+45));
     glVertex2f(getX(-582.96+859.04+100),getY(-291.1+26.95+45));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+859.04+100),getY(-285.71+26.95+45));
     glVertex2f(getX(-534.872+859.04+100),getY(-301.88+26.95+45));
     glVertex2f(getX(-518.532+859.04+100),getY(-301.88+26.95+45));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+859.04+100),getY(-301.88+26.95+45));
     glVertex2f(getX(-513.93+859.04+100),getY(-318.05+26.95+45));
     glVertex2f(getX(-518.532+859.04+100),getY(-301.88+26.95+45));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+859.04+100),getY(-280.32+26.95+45));
     glVertex2f(getX(-567.62+859.04+100),getY(-291.1+26.95+45));
     glVertex2f(getX(-544.6+859.04+100),getY(-291.1+26.95+45));
     glVertex2f(getX(-532.94+859.04+100),getY(-286.32+26.95+45));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+859.04+100),getY(-312.66+26.95+45));
     glVertex2f(getX(-560.28+859.04+100),getY(-323.44+26.95+45));
     glVertex2f(getX(-536.94+859.04+100),getY(-318.05+26.95+45));
     glVertex2f(getX(-544.61+859.04+100),getY(-312.66+26.95+45));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+859.04+100),getY(-297.88+26.95+45));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+859.04+100),getY(-301.88+26.95+45));
     glVertex2f(getX(-588.3+859.04+100),getY(-301.88+26.95+45));
     glEnd();
      glPopMatrix();

  }
   if(twelve==1)
   {
     //////fish12
     //body
     glPushMatrix();
     glTranslatef(transFish, 0.0, 0.0);
     glBegin(GL_POLYGON);
     glColor3ub(255,151,47);
     glVertex2f(getX(-598.3+1073.8+80),getY(-301.88+90));
     glVertex2f(getX(-582.96+1073.8+80),getY(-312.66+90));
     glVertex2f(getX(-544.61+1073.8+80),getY(-312.66+90));
     glVertex2f(getX(-528.872+1073.8+80),getY(-301.88+90));
     glVertex2f(getX(-544.61+1073.8+80),getY(-291.1+90));
     glVertex2f(getX(-582.96+1073.8+80),getY(-291.1+90));
     glEnd();
     //tailUpper
     glColor3ub(255,79,79);
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-513.93+1073.8+80),getY(-285.71+90));
     glVertex2f(getX(-534.872+1073.8+80),getY(-301.88+90));
     glVertex2f(getX(-518.532+1073.8+80),getY(-301.88+90));
     glEnd();
      //tailLower
     glBegin(GL_TRIANGLES);
     glVertex2f(getX(-534.872+1073.8+80),getY(-301.88+90));
     glVertex2f(getX(-513.93+1073.8+80),getY(-318.05+90));
     glVertex2f(getX(-518.532+1073.8+80),getY(-301.88+90));
     glEnd();
     //uppweWing
     glColor3ub(255,106,106);
     glBegin(GL_QUADS);
     glVertex2f(getX(-552.28+1073.8+80),getY(-280.32+90));
     glVertex2f(getX(-567.62+1073.8+80),getY(-291.1+90));
     glVertex2f(getX(-544.6+1073.8+80),getY(-291.1+90));
     glVertex2f(getX(-532.94+1073.8+80),getY(-286.32+90));
     glEnd();
     //lowerWing
     glColor3ub(255,83,83);
     glBegin(GL_QUADS);
     glVertex2f(getX(-575.5+1073.8+80),getY(-312.66+90));
     glVertex2f(getX(-560.28+1073.8+80),getY(-323.44+90));
     glVertex2f(getX(-536.94+1073.8+80),getY(-318.05+90));
     glVertex2f(getX(-544.61+1073.8+80),getY(-312.66+90));
     glEnd();
     //eye
     glColor3ub(0,0,0);
     glPointSize(3.0);
     glBegin(GL_POINTS);
     glVertex2f(getX(-582.96+1073.8+80),getY(-297.88+90));
     glEnd();
     ////lip

     glBegin(GL_LINES);
     glVertex2f(getX(-598.3+1073.8+80),getY(-301.88+90));
     glVertex2f(getX(-588.3+1073.8+80),getY(-301.88+90));
     glEnd();
    glPopMatrix();
   }
    }

}
void update(int value)
{
    if(t>30)
    {
        window2=true;
        window1=false;
        l3flag=false;
        show3=false;
    }
    if(start==true)
        trans-=0.0006;
    timer-=10;
    if(l2flag==true)
        timer2-=10;
    if(l3flag==true)
        timer2-=20;
    if(timer2==0)
    {
        window2=true;
        window1=false;
        l2flag=false;
        show=false;
        if(l3flag==true)
        {
            l3flag=false;
            show3=false;
        }
    }
    if(timer==0)
    {
        window2=true;
        window1=false;
        //exit(0);
    }

    transSun-=0.002;
    if(goUp==true)
    {
        transBalloon+=0.002;
        //changeY=0.0;
        nodown=true;
        changeY+=0.002;
    }
    transFactor += .005;
    if(l2flag==true || l3flag==true)
        transFish-=0.009f;
    else
       transFish-=0.005f;
    if(transFish+0.8<0.0)
    {
        transFish = 1.0;
    }

    if(transFactor-0.98 > 1.0)
    {
        transFactor = -1.0;
    }
    if(changeY<0.45 && up==true && nodown==false)
    {
        changeY+=0.005;
        moveMan(0);
    }
    if(changeY>0.45 && nodown==false)
    {
        up=false;
        first=false;
    }
    if(down==true && nodown==false)
    {
        //up==false;
        changeY-=0.005;
        moveMan(0);
    }
    //first variable limits the movement further e.g man cannot go down further when he is standing on the pebble
    if(up==false && first==false && nodown==false)
    {
        changeY-=0.005;
        moveMan(0);
    }

    glutPostRedisplay();
    glutTimerFunc(35, update, 0);
}
void shootedFish(float x,float y)
{
    //1
   if(x<transFish+getX(-528.872-18) && x>transFish+getX(-598.3+18))
   {
      one=0;
      exclude(1);
      val+=10;
   }
   //2
   if(x<transFish+getX(-310.112-8) && x>transFish+getX(-383.54+8))
   {
      two=0;
      exclude(2);
      val+=10;
   }
   //3
   if(x<transFish+getX(-528.872+429.52-8) && x>transFish+getX(-598.3+429.52+8))
   {
      three=0;
      exclude(3);
      val+=10;
   }
   //4
   if(x<transFish+getX(-528.872+644.28-8) && x>transFish+getX(-598.3+644.28+8))
   {
      four=0;
      exclude(4);
      val+=10;
   }
   //5
   if(x<transFish+getX(-528.872+859.04-8) && x>transFish+getX(-598.3+859.04+8))
   {
      five=0;
      exclude(5);
      val+=10;
   }
   //6
   if(x<transFish+getX(-528.872+1073.8-8) && x>transFish+getX(-598.3+1073.8+8))
   {
      six=0;
      exclude(6);
      val+=10;
   }
   //7
   if(x<transFish+getX(-528.872-40-8) && x>transFish+getX(-598.3-40+8))
   {
      seven=0;
      exclude(7);
      val+=10;
   }
   //8
   if(x<transFish+getX(-310.112-50-8) && x>transFish+getX(-383.54-50+8))
   {
      eight=0;
      exclude(8);
      val+=10;
   }
   //9
   if(x<transFish+getX(-528.872+429.52+70-8) && x>transFish+getX(-598.3+429.52+70+8))
   {
      nine=0;
      exclude(9);
      val+=10;
   }
   //10
   if(x<transFish+getX(-528.872+644.28+100-8) && x>transFish+getX(-598.3+644.28+100+8))
   {
      ten=0;
      exclude(10);
      val+=10;
   }
   //11
   if(x<transFish+getX(-528.872+859.04+100-8) && x>transFish+getX(-598.3+859.04+100+8))
   {
      eleven=0;
      exclude(11);
      val+=10;
   }
   //12
   if(x<transFish+getX(-528.872+1073.8+80-8) && x>transFish+getX(-598.3+1073.8+80+8))
   {
      twelve=0;
      exclude(12);
      val+=10;
   }

}
void l2shootedFish(float x,float y)
{
    //1
   if(x<transFish+getX(-517.5-10) && x>transFish+getX(-615+10))
   {
      l2one=0;
      exclude(1);
      val+=10;
   }
   //2
   else if(x<(transFish+0.15)+getX(-517.5-5) && x>(transFish+0.15)+getX(-615+5))
   {
      l2two=0;
      exclude(2);
      val+=10;
   }
   //3
   if(x<(transFish+0.4)+getX(-517.5-10) && x>(transFish+0.4)+getX(-615+10))
   {
      l2three=0;
      exclude(3);
      val+=10;
   }
   //4
   if(x<(transFish+0.62)+getX(-517.5-10) && x>(transFish+0.62)+getX(-615+10))
   {
      l2four=0;
      exclude(4);
      val+=10;
   }
   //5
   if(x<(transFish+0.79)+getX(-517.5-10) && x>(transFish+0.79)+getX(-615+10))
   {
      l2five=0;
      exclude(5);
      val+=10;
   }
   //6
   if(x<(transFish+0.96)+getX(-517.5-10) && x>(transFish+0.96)+getX(-615+10))
   {
      l2six=0;
      exclude(6);
      val+=10;
   }
   //7
   if(x<(transFish+1.18)+getX(-517.5-10) && x>(transFish+1.18)+getX(-615+10))
   {
      l2seven=0;
      exclude(7);
      val+=10;
   }
   //8
   if(x<(transFish+1.3)+getX(-517.5-10) && x>(transFish+1.3)+getX(-615+10))
   {
      l2eight=0;
      exclude(8);
      val+=10;
   }
   //9
   if(x<(transFish+1.5)+getX(-517.5-10) && x>(transFish+1.5)+getX(-615+10))
   {
      l2nine=0;
      exclude(9);
      val+=10;
   }
   //10
   if(x<(transFish+1.66)+getX(-517.5-10) && x>(transFish+1.66)+getX(-615+10))
   {
      l2ten=0;
      exclude(10);
      val+=10;
   }
   //11
   if(x<(transFish+1.9)+getX(-517.5-10) && x>(transFish+1.9)+getX(-615+10))
   {
      l2eleven=0;
      exclude(11);
      val+=10;
   }
   //12
   if(x<(transFish+2.18)+getX(-517.5-10) && x>(transFish+2.17)+getX(-615+10))
   {
      l2twelve=0;
      exclude(12);
      val+=10;
   }
   //13
   if(x<(transFish+2.4)+getX(-517.5-10) && x>(transFish+2.32)+getX(-615+10))
   {
      l2thirteen=0;
      exclude(13);
      val+=10;
   }
   //14
   if(x<(transFish+2.58)+getX(-517.5-10) && x>(transFish+2.4)+getX(-615+10))
   {
      l2fourteen=0;
      exclude(14);
      val+=10;
   }

}
void shoot(float x,float y)
{
    //
    glColor3ub (255,0,0);
    glBegin(GL_LINES);
    glLineWidth(55);
    glVertex2f(getX(-444.78)+changeX,getY(-83.76)+changeY);
    glVertex2f(getX(x),getY(y));
    glEnd();
    glFlush();
    shootFX=getX(x);
    shootFY=getY(y);

    if(l2flag==true || l3flag==true)
    {
       l2shootedFish(shootFX,shootFY);
       //glFlush();
    }
    else{
    shootedFish(shootFX,shootFY);
    //glFlush();
    }


}
void moveToL2(float x,float y)
{
    glColor3ub (255,0,0);
    glBegin(GL_LINES);
    glLineWidth(25);
    glVertex2f(getX(-444.78)+changeX,getY(-83.76)+changeY);
    glVertex2f(getX(x),getY(y));
    glEnd();
    glFlush();

    if((getX(x)>getX(-320+180) && getX(x)<getX(-210+180)) && (getY(y)>getY(-145+90) && getY(y)<getY(-110+90)))
    {
        if(l3flag==true)
        {
           l2flag=false;
           window1=true;
           window2=false;
           changeY=0.0;
           changeX=0.0;
           up=false,first=true,down=false,p1=false,p2=false,p3=false;
           generateRandom(0);
           val=0;
        }
         else
         {
             l2flag=true;
             window1=true;
             window2=false;
             up=false,first=true,down=false,p1=false,p2=false,p3=false;
             generateRandom(0);
             val=0;
         }
         //changeX=changeY=0.0;
    }
}
void mouseClick(int buttonPressed ,int state ,int x, int y) {
    if(buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //sndPlaySound("gun.wav",SND_ASYNC);
        float windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        float windowWidth = -(glutGet(GLUT_WINDOW_WIDTH));
        ballx = windowWidth/2+(float)x;
        bally = windowHeight/2-(float)y;
        if(window2==true)
            moveToL2(ballx,bally);
        else
           shoot(ballx,bally);
        cout<<ballx<<", "<<bally<<endl;
	}
}
void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_RIGHT:
          changeX+=0.005;
          moveMan(0);
          break;
      case GLUT_KEY_LEFT:
          changeX-=0.005;
          moveMan(0);
          break;
      case GLUT_KEY_UP:
          up=true;

          //changeY+=0.005;
          //goUpUntill();
          //moveMan(0);
          break;
    }
}
void cloudsCalling()
{
    //1
   glPushMatrix();
   glTranslatef(transFactor+0.2, 0.8, 0.0);
   glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
   glPushMatrix();
   glTranslatef(transFactor+0.28, 0.8, 0.0);
   glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
  glPushMatrix();
	   //glTranslatef(6,0,0);
   glTranslatef(transFactor+0.35, 0.75, 0.0);
   glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
   glTranslatef(transFactor+0.28, 0.75, 0.0);
   glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
    glPushMatrix();
   glTranslatef(transFactor+0.19, 0.73, 0.0);
   glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.05;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	//2
    glPushMatrix();
    glTranslatef(transFactor-0.35, 0.89, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(transFactor-0.40, 0.83, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(transFactor-0.25, 0.76, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
//
    glPushMatrix();
    glTranslatef(transFactor-0.29, 0.8, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(transFactor-0.35, 0.74, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	//3
	glPushMatrix();
    glTranslatef(transFactor-0.73, 0.74, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.08;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(transFactor-0.74, 0.65, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
    glTranslatef(transFactor-0.85, 0.65, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
    glPushMatrix();
    glTranslatef(transFactor-0.83, 0.73, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);

	for(int i=0;i<600;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
	glPopMatrix();
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(window1==true)
    {
        //sndPlaySound("strings.wav",SND_ASYNC);
            ////sky////
            if(0.8+transSun>0.0)
            {
                glBegin(GL_QUADS);
                glColor3ub(191, 255, 255);
                glVertex2f(getX(-675),getY(345));
                glVertex2f(getX(-675),getY(0));
                glVertex2f(getX(675),getY(0));
                glVertex2f(getX(675),getY(345));
                glEnd();
            }
            else
            {
               glBegin(GL_QUADS);
                glColor3ub(191, 191, 191);
                glVertex2f(getX(-675),getY(345));
                glVertex2f(getX(-675),getY(0));
                glVertex2f(getX(675),getY(0));
                glVertex2f(getX(675),getY(345));
               glEnd();
            }


        //score box//
        glBegin(GL_QUADS);
        glColor3ub(255, 128, 128);
        glVertex2f(getX(-665),getY(335));
        glVertex2f(getX(-665),getY(280));
        glVertex2f(getX(-600),getY(280));
        glVertex2f(getX(-600),getY(335));
        glEnd();
        stringstream ss;
        ss<<val<<endl;
        string scoreValue=ss.str();
        int len=scoreValue.length();
        //scrvalue this is the score
        char scrvalue[len];
        for(int i=0;i<len;i++)
        {
            scrvalue[i]=scoreValue[i];
        }
        Sprint(getX(-640),getY(300),scrvalue);
        if(l2flag==true)
           Sprint(getX(-665),getY(180),"Level 2");
        else if(l3flag==true)
            Sprint(getX(-665),getY(180),"Level 3");
        Sprint(getX(-665),getY(260),text);
        Sprint(getX(-665),getY(220),"Lifetime");
        stringstream ts;
        if(l2flag==true || l3flag==true)
            ts<<timer2<<endl;
        else
           ts<<timer<<endl;
        string timerValue=ts.str();
        int lent=timerValue.length();
        //scrvalue this is the score
        char timervalue[lent];
        for(int i=0;i<lent;i++)
        {
            timervalue[i]=timerValue[i];
        }
        Sprint(getX(-665),getY(200),timervalue);
        //sun//
        glPushMatrix();
        glTranslatef(0.65, 0.8+transSun, 0.0);
        glColor3ub(255,255,148);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200 ;
            float r=0.15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y);
        }
        glEnd();
        glPopMatrix();
        //INNER SUN
        glPushMatrix();
        glTranslatef(0.65, 0.8+transSun, 0.0);
        glColor3ub(255,255,26);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200 ;
            float r=0.10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();
        cloudsCalling();
         ////down
         //glPushMatrix();
         glBegin(GL_QUADS);
         glColor3ub(91, 199, 234);
         glVertex2f(getX(-675),getY(0));
         glVertex2f(getX(-675),getY(-345));
         glVertex2f(getX(675),getY(-345));
         glVertex2f(getX(675),getY(0));
         glEnd();

         fishCalling();
         /////////////////////////////////
         ////////////////////////////////

          //fields and river bank
          //upperGreen
         glBegin(GL_POLYGON);
         glColor3ub(57,174,64);
         glVertex2f(getX(168.74),getY(-21.56));
         glVertex2f(getX(475.54),getY(-53.9));
         glVertex2f(getX(675),getY(-53.9));
         glVertex2f(getX(675),getY(0));
         glVertex2f(getX(230.1),getY(0));
         glEnd();
         //lowerGreen
         glBegin(GL_POLYGON);
         glColor3ub(57,174,64);
         glVertex2f(getX(429.52),getY(-68.992));
         glVertex2f(getX(675),getY(-86.24+10.78+5));
         glVertex2f(getX(675),getY(-53.9));
         glVertex2f(getX(475.54),getY(-53.9));
         glEnd();
         //leftSoil
         glBegin(GL_POLYGON);
         glColor3ub(179,89,0);
         glVertex2f(getX(168.74),getY(-21.56));
         glVertex2f(getX(168.74),getY(-21.56-10.78));
         glVertex2f(getX(429.52),getY(-68.992));
         glVertex2f(getX(475.54),getY(-53.9));
         glEnd();
         //rightSoil
         glBegin(GL_POLYGON);
          glVertex2f(getX(429.52),getY(-68.992));
          glVertex2f(getX(429.52),getY(-68.992-10.78));
          glVertex2f(getX(675),getY(-86.24+5));
          glVertex2f(getX(675),getY(-86.24+10.78+5));
         glEnd();

         //left Field
         glColor3ub(57,174,64);
         glBegin(GL_POLYGON);
          glVertex2f(getX(-675),getY(0));
          glVertex2f(getX(-675),getY(-75.46));
          glVertex2f(getX(-368.16),getY(-43.12));
          glVertex2f(getX(-306.8),getY(0));
         glEnd();
         //left soil
         //1
         glBegin(GL_POLYGON);
         glColor3ub(179,89,0);
          glVertex2f(getX(-675),getY(-75.46));
          glVertex2f(getX(-675),getY(-75.46-10.78));
          glVertex2f(getX(-368.16),getY(-43.12-10.78));
          glVertex2f(getX(-368.16),getY(-43.12));
         glEnd();
         //2
         glBegin(GL_POLYGON);
         glColor3ub(179,89,0);
          glVertex2f(getX(-368.16),getY(-43.12));
          glVertex2f(getX(-368.16),getY(-43.12-10.78));
          glVertex2f(getX(-306.8),getY(-10.78));
          glVertex2f(getX(-306.8),getY(0));
         glEnd();

         //righ side trees
         glColor3ub(0,128,64);
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(354),getY(50));
         glVertex2f(getX(341),getY(0));
         glVertex2f(getX(421),getY(0));
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(422),getY(93));
         glVertex2f(getX(384),getY(0));
         glVertex2f(getX(510),getY(0));
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(489),getY(65));
         glVertex2f(getX(405),getY(0));
         glVertex2f(getX(553),getY(0));
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(489),getY(108));
         glVertex2f(getX(443),getY(0));
         glVertex2f(getX(532),getY(0));
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(633),getY(122));
         glVertex2f(getX(559),getY(0));
         glVertex2f(getX(675),getY(0));
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(580),getY(137));
         glVertex2f(getX(538),getY(0));
         glVertex2f(getX(622),getY(0));
         glEnd();
         glBegin(GL_TRIANGLES);
         glVertex2f(getX(531),getY(93));
         glVertex2f(getX(468),getY(0));
         glVertex2f(getX(595),getY(0));
         glEnd();
         pebbleCalling();
          moveMan(0);
         //glPopMatrix();
    }
    else if(window2==true)
    {
          glBegin(GL_POLYGON);
             glColor3f(1.0,1.0,1.0);
             glVertex2f(getX(-475),getY(245));
             glVertex2f(getX(-475),getY(-245));
             glVertex2f(getX(475),getY(-245));
             glVertex2f(getX(475),getY(245));
           glEnd();
           glBegin(GL_POLYGON);
                 //glColor3ub(135,156,61);
                 glColor3ub(150,150,150);
                 glVertex2f(getX(-255),getY(-0));
                 glVertex2f(getX(-195),getY(-118.58));
                 glVertex2f(getX(150),getY(-118.58));
                 glVertex2f(getX(210),getY(0));
                 glVertex2f(getX(150),getY(118.58));
                 glVertex2f(getX(-195),getY(118.58));
                 glEnd();
                 //tail
                 glColor3ub(99,112,203);
                 //glColor3ub(61,61,150);
                 glBegin(GL_TRIANGLES);
                 glVertex2f(getX(180),getY(0));
                 glVertex2f(getX(300),getY(-129.36));
                 glVertex2f(getX(300),getY(129.36));
                 glEnd();
                 //uppweWing
                 glColor3ub(99,112,203);
                 glBegin(GL_POLYGON);
                 glVertex2f(getX(-120),getY(161.7));
                 glVertex2f(getX(-120),getY(118.58));
                 glVertex2f(getX(90),getY(118.58));
                 glVertex2f(getX(150),getY(150.92));
                 glVertex2f(getX(-30),getY(215.6));
                 glEnd();
                 //lowerWing
                 glColor3ub(99,112,203);
                 glBegin(GL_QUADS);
                 glVertex2f(getX(-135),getY(-118.58));
                 glVertex2f(getX(-120),getY(-172.48));
                 glVertex2f(getX(195),getY(-172.48));
                 glVertex2f(getX(105),getY(-118.58));
                 glEnd();
                 //eye
                 glColor3ub(0,0,0);
                 glPointSize(6.0);
                 glBegin(GL_POINTS);
                 glVertex2f(getX(-172.5),getY(70.07));
                 glEnd();
                 ////lip
                 glBegin(GL_LINES);
                 glVertex2f(getX(-255),getY(0));
                 glVertex2f(getX(-180),getY(0));
            glEnd();
            changeX=0.0;
            changeY=0.0;
            moveMan(0);
            //glColor3f(0.0,0.0,0.0);
            if(val>110 && val<150)
                Sprint(getX(-320+180),getY(-50+90),"YOU WERE CLOSE!");
            else if(val<120)
                Sprint(getX(-320+180),getY(-50+90),"YOU LOSE!");
            else if(p3cross)
                Sprint(getX(-320+180),getY(-50+90),"CONGRATUATIONS! YOU WIN");
            else
                Sprint(getX(-320+180),getY(-50+90),"YOU DIDN'T CROSS THE PEBBLES SO YOU LOSE!");
            Sprint(getX(-320+180),getY(-80+90),"GAME OVER");
            Sprint(getX(-320+180),getY(-100+90),"Your score is:");
            stringstream ss;
            ss<<val<<endl;
            string scoreValue=ss.str();
            int len=scoreValue.length();
            //scrvalue this is the score
            char scrvalue[len];
            for(int i=0;i<len;i++)
            {
                scrvalue[i]=scoreValue[i];
            }
            Sprint(getX(-200+180),getY(-100+90),scrvalue);
            //button
            if(val>110 && p3cross==true && show==true)
            {
                glBegin(GL_QUADS);
                 glColor3f(1.0,0.0,0.0);
                 glVertex2f(getX(-320+180),getY(-145+90));
                 glVertex2f(getX(-320+180),getY(-110+90));
                 glVertex2f(getX(-210+180),getY(-110+90));
                 glVertex2f(getX(-210+180),getY(-145+90));
                glEnd();
               Sprint(getX(-290+180),getY(-135+90),"Level 2");
            }
            if(val>110 && p3cross==true && show==false && show3==true)
            {
                glBegin(GL_QUADS);
                 glColor3f(1.0,0.0,0.0);
                 glVertex2f(getX(-320+180),getY(-145+90));
                 glVertex2f(getX(-320+180),getY(-110+90));
                 glVertex2f(getX(-210+180),getY(-110+90));
                 glVertex2f(getX(-210+180),getY(-145+90));
                glEnd();
               Sprint(getX(-290+180),getY(-135+90),"Level 3");
               l3flag=true;
               goUp=false;
               nodown=false;
               timer2=10000;
               transBalloon=0.0f;
            }
    }

     glFlush();
     glutSwapBuffers();
}
void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (1350, 690);
glutInitWindowPosition (0, 0);
glutCreateWindow ("Man VS Piranha");
myInit();
generateRandom(0);
glutDisplayFunc(myDisplay);

glutSpecialFunc(specialKeys);
glutMouseFunc(mouseClick);
//sndPlaySound("strings.wav",SND_ASYNC|SND_LOOP);
glutTimerFunc(35, update, 0);
//shoot();
glutMainLoop();
return 0;
}
