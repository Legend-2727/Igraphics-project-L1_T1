# include "iGraphics.h"
#include<cstdlib>
#include<string>
int chrctrX,chrctrY;

typedef struct namescore
{
    int b;
    char a[100];

}scoring;

scoring name[3];
int gamestate=-2;
int hero;
int sound=1;
int pause;
int vbullet_x=1600,vbullet_y=60;
int hbullet=-1;
int hbullet_x,hbullet_y;
int vdx,hdx;
int play=-1;
void hcollision();
int i=10000,j=700;
char cnt[10];
int rckt_x,rckt_y;
int rdx;
int msl_x,msl_y;
int mdy;
int dblt_x,dblt_y;
int dbdy;
int ult_x,ult_y=-100;
int udy;
int dmg_x=2000000,dmg_y;
int dmdy;
char load[16][100]={"project\\ld\\loading1.bmp","project\\ld\\loading2.bmp","project\\ld\\loading3.bmp","project\\ld\\loading4.bmp","project\\ld\\loading5.bmp"
                ,"project\\ld\\loading6.bmp","project\\ld\\loading7.bmp","project\\ld\\loading8.bmp","project\\ld\\loading9.bmp","project\\ld\\loading10.bmp"
                ,"project\\ld\\loading11.bmp","project\\ld\\loading12.bmp","project\\ld\\loading13.bmp","project\\ld\\loading14.bmp","project\\ld\\loading15.bmp",
                "project\\ld\\loading16.bmp"};
char hlife[4][50]={"project\\life100.bmp","project\\life75.bmp","project\\life25.bmp","project\\life10.bmp"};
char vlife[4][50]={"project\\vlife100.bmp","project\\vlife75.bmp","project\\vlife25.bmp","project\\vlife10.bmp"};
char ult[4][50]={"project\\power1.bmp","project\\power2.bmp","project\\power3.bmp","project\\power4.bmp"};
int ult_in=3;
int hlifind=0,vlifind=0;
int ldindex=0;
char hero_life[100];
int heroindex=200;
char vln_lf[100];
int vln_index=200;
int settings;
int instcn=0;
int bltindex=0;
int blttmr=400;
int ultactv=0;
int ulttmr;
int ulttmr2;
char lighning[11][50]={"project\\ult\\light1.bmp","project\\ult\\light2.bmp","project\\ult\\light3.bmp","project\\ult\\light4.bmp","project\\ult\\light5.bmp",
                       "project\\ult\\light6.bmp","project\\ult\\light7.bmp","project\\ult\\light8.bmp","project\\ult\\light9.bmp","project\\ult\\light10.bmp",
                        "project\\ult\\light11.bmp"};
int light_ind=0;
char bullet[3][50]={"project\\hbullet.bmp","project\\hbullet2.bmp","project\\fball.bmp"};
int losegame=0;
int wingame=0;
int chamber_ultX,chamber_ultY;
int chamb_dy;
char explosion[16][50]={"project\\explosion\\explosion1.bmp","project\\explosion\\explosion2.bmp","project\\explosion\\explosion3.bmp","project\\explosion\\explosion4.bmp",
                         "project\\explosion\\explosion5.bmp","project\\explosion\\explosion6.bmp","project\\explosion\\explosion7.bmp","project\\explosion\\explosion8.bmp",
                         "project\\explosion\\explosion9.bmp","project\\explosion\\explosion10.bmp","project\\explosion\\explosion11.bmp","project\\explosion\\explosion12.bmp",
                         "project\\explosion\\explosion13.bmp","project\\explosion\\explosion14.bmp"};

int expl_index=0;
char chamb_ult[21][100]={"project\\fire\\fire1.bmp","project\\fire\\fire2.bmp","project\\fire\\fire3.bmp","project\\fire\\fire4.bmp","project\\fire\\fire5.bmp",
                         "project\\fire\\fire6.bmp","project\\fire\\fire7.bmp","project\\fire\\fire8.bmp","project\\fire\\fire9.bmp","project\\fire\\fire10.bmp",
                         "project\\fire\\fire11.bmp","project\\fire\\fire12.bmp","project\\fire\\fire13.bmp","project\\fire\\fire14.bmp","project\\fire\\fire15.bmp"
                         ,"project\\fire\\fire16.bmp","project\\fire\\fire17.bmp","project\\fire\\fire18.bmp","project\\fire\\fire19.bmp","project\\fire\\fire20.bmp",
                         "project\\fire\\fire21.bmp"};

int chamb_in=0;
int msl_actv=0;
char red_bld[8][50]={"project\\red blood\\red blood1.bmp","project\\red blood\\red blood2.bmp","project\\red blood\\red blood3.bmp","project\\red blood\\red blood4.bmp",
                     "project\\red blood\\red blood5.bmp","project\\red blood\\red blood6.bmp","project\\red blood\\red blood7.bmp","project\\red blood\\red blood8.bmp"};
char grn_bld[8][50]={"project\\red blood\\grn blood1.bmp","project\\red blood\\grn blood2.bmp","project\\red blood\\grn blood3.bmp","project\\red blood\\grn blood4.bmp",
                     "project\\red blood\\grn blood5.bmp","project\\red blood\\grn blood6.bmp","project\\red blood\\grn blood7.bmp","project\\red blood\\grn blood8.bmp"};
int red_ind=0;
int rbldactv=0;
int grnbldactv=0;
int grntimer=35;
int grn_ind=0;
char scoreimg[10][50]={"project\\numb\\0.bmp","project\\numb\\1.bmp","project\\numb\\2.bmp","project\\numb\\3.bmp","project\\numb\\4.bmp",
                     "project\\numb\\5.bmp","project\\numb\\6.bmp","project\\numb\\7.bmp","project\\numb\\8.bmp","project\\numb\\9.bmp"};
int score_ind[3];
int score;
int highscore;
int one=1;
int temp;
int expl_x,expl_y;
int write;
char str[100],str2[3][10];
void herolifechange();
void dbldmgblt();
void ultpoint();
void rbldchange();
int len=0;
int i_pass,heropass;
int g12=200;
int music=1;
void filecheck();
void filewrite();
//void grnbldchange();
void iDraw()
{

    iClear();
            if(music==1)
                {
                    PlaySound("project\\bgm.wav",NULL,SND_ASYNC | SND_LOOP);
                    music=100;
                }
    if(j>0)
    {
        iShowBMP(0,0,"project\\val.bmp");
        j--;
        iShowBMP2(700,200,load[ldindex],0xffffff);
        if(j==0)
        {
            gamestate=-1;
        }
    }

    if(gamestate==-1)
    {
        iClear;
        iShowBMP(0,0,"project\\mainbg.bmp");
              if(sound>0)
              {
                  iShowBMP2(1290,10,"project\\sound_on.bmp",0xffffff);
              }
              else iShowBMP2(1290,10,"project\\sound_off.bmp",0xffffff);

    }
    else if(gamestate==0)
    {
        iClear;
        iShowBMP(0,0,"project\\mainbg2.bmp");
        iShowBMP2(200,10,"project\\sage.bmp",0xffffff);
        iShowBMP2(1100,10,"project\\chamber.bmp",0xffffff);
        if(hero==1)
        {
            iClear();
            if(music==100)
                {
                    PlaySound("project\\cod.wav",NULL,SND_ASYNC | SND_LOOP);
                    music=200;
                }
            if(play<0)
            {
                iClear();
                iShowBMP(0,0,"project\\blur.bmp");
                iSetColor(0,0,0);
                iText(600,250,"Press p any time to start/resume or pause the game",GLUT_BITMAP_TIMES_ROMAN_24);
                iShowBMP2(200,0,"project\\menus2.bmp",0xffffff);
                iPauseTimer(0);
                if(settings==1)
                {
                    iClear();
                    iShowBMP(0,0,"project\\blur.bmp");
                    iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
                    if(sound>0)
                    {
                        iShowBMP2(500,180,"project\\snon.bmp",0xffffff);
                    }
                    else
                        iShowBMP2(500,180,"project\\snoff.bmp",0xffffff);
                    iShowBMP2(800,200,"project\\instructions.bmp",0xffffff);
                    if(instcn==1)
                    {
                        iClear;
                        iShowBMP(0,0,"project\\instbg.bmp");
                        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
                    }
                }

            }
            if(play>0)
            {
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                iResumeTimer(4);
                iResumeTimer(5);
                iResumeTimer(6);
                iResumeTimer(7);
                iResumeTimer(8);
                iResumeTimer(9);
                iResumeTimer(10);
                iClear();
                iShowBMP(0,0,"project\\level1.bmp");
                iShowBMP2(20,500,hlife[hlifind],0xffffff);
                    if(heroindex<150) hlifind=1;
                    if(heroindex<100) hlifind=2;
                    if(heroindex<30) hlifind=3;
                iShowBMP2(1350,500,vlife[vlifind],0xffffff);
                iShowBMP2(chrctrX,chrctrY,"project\\sagegmp.bmp",0xffffff);
                ultpoint();
                iShowBMP2(20,580,ult[ult_in],0xf5f5f5);
                /*if(chrctrY>50&&((hbullet_x>=1250&&hbullet_y<200)||(hbullet_x>=1600&&hbullet_y<638)))
                {
                    hbullet=-1;
                }*/
                iShowBMP2(vbullet_x,vbullet_y,"project\\bfire.bmp",0xf7f7f7);

                //if(hbullet&&((hbullet_y>=160&&hbullet_x<=1600)||(hbullet_y<=160&&hbullet_x<=1400)))
                hcollision();
                dbldmgblt();
                if(hbullet==1)
                {
                    if(bltindex==2)
                        iShowBMP2(hbullet_x,hbullet_y,bullet[bltindex],0);
                    else
                        iShowBMP2(hbullet_x,hbullet_y,bullet[bltindex],0xffffff);
                }
                iShowBMP2(1400,2,"project\\venom.bmp",0xffffff);

                if(grnbldactv==1 && grntimer>0)
                {
                    iShowBMP2(1350,100,grn_bld[grn_ind],0xffffff);
                    if(grntimer%5==0)
                    {
                        grn_ind++;
                    }
                    grntimer--;
                    if(grntimer==0)
                    {
                        grnbldactv=0;
                        grn_ind=0;
                        grntimer=35;
                    }
                }
                iShowBMP2(735,560,"project\\pause.bmp",0);
                itoa(i,cnt,10);
                iSetColor(0,0,0);
                iText(745,520,cnt,GLUT_BITMAP_TIMES_ROMAN_24);
                i--;
                if(i%500==0)
                {
                    iResumeTimer(2);
                    rckt_x=1600;
                    rckt_y=chrctrY+50;
                }
                /*if(!(rckt_x>=chrctrX&&rckt_x<=chrctrX+80&&rckt_y>=chrctrY&&rckt_y<=chrctrY+121))
                {

                }*/
                /*if(rckt_x<=-200)
                {
                    iPauseTimer(3);
                }*/
                iShowBMP2(rckt_x,rckt_y,"project//rocketlft.bmp",0xffffff);
                if((i<9200&&i>9000)||(i<7200&&i>7000)||(i<5200&&i>5000)||(i<3200&&i>3000)||(i<1200&&i>1000))
                {
                    iSetColor(255,0,0);
                    iFilledCircle(chrctrX+10,690,100);
                }
                if((i-1000)%2000==0)
                {
                    //iResumeTimer(3);
                    msl_x=chrctrX;
                    msl_y=chrctrY+638;
                }
                /*if(!(msl_x>=chrctrX&&msl_x<=chrctrX+80&&msl_y>=chrctrY&&msl_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(msl_x,msl_y,"project//missile.bmp",0xf7f7f7);
                if(rbldactv==1)
                {
                    iShowBMP2(chrctrX+40,chrctrY+60,red_bld[red_ind],0xf7f7f7);
                    rbldchange();
                }
                if(i%800==0)
                {
                    dblt_x=rand()%1000;
                    dblt_y=650;
                }
                /*if(!(dblt_x>=chrctrX&&dblt_x<=chrctrX+80&&dblt_y>=chrctrY&&dblt_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(dblt_x,dblt_y,"project//dbl.bmp",0xffffff);
                if(msl_actv==1)
                {
                    iShowBMP2(expl_x,expl_y,explosion[expl_index],0xffffff);
                }
                if(i%600==0)
                {
                    dmg_x=rand()%1000;
                    dmg_y=650;
                }
                /*if(!(dmg_x>=chrctrX&&dmg_x<=chrctrX+80&&dmg_y>=chrctrY&&dmg_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(dmg_x,dmg_y,"project//dmgmp.bmp",0);
                if(i%500==0)
                {
                    ult_x=rand()%1000;
                    ult_y=650;
                }
                /*if(!(ult_x>=chrctrX&&ult_x<=chrctrX+80&&ult_y>=chrctrY&&ult_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(ult_x,ult_y,"project//ult.bmp",0);
                herolifechange();
                itoa(heroindex,hero_life,10);
                iSetColor(0,0,0);
                iText(20,550,hero_life,GLUT_BITMAP_TIMES_ROMAN_24);
                itoa(vln_index,vln_lf,10);
                iText(1500,550,vln_lf,GLUT_BITMAP_TIMES_ROMAN_24);
                //ultimate er kaj
                if(ulttmr>0 && ultactv==1)
                {
                    iShowBMP2(1450,2,lighning[light_ind],0);
                    ulttmr--;
                    if(ulttmr%6==0)
                    {
                        vln_index--;
                    }
                    if(ulttmr==0) ultactv=0;
                }
                iResumeTimer(0);
                //gameover
                if(heroindex<1 || i<1)
                {
                    iClear();
                    losegame=1;
                    iShowBMP(0,0,"project\\finalbg.bmp");
                    iShowBMP2(600,100,"project\\lose_game.bmp",0xf0f0f0);
                    iSetColor(0,0,0);
                    iText(600,500,"CONTINUE TO THE MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                    iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
                }
                //win game
                if(vln_index<=0)
                {
                    //score=i/20+heroindex*2;
                    i_pass=i/20;
                    heropass=heroindex*2;

                    score=i_pass+heropass;
                    name[0].b=score;
                    temp=i_pass+heropass;
                    score_ind[0]=temp%10;
                    temp=temp/10;
                    score_ind[1]=temp%10;
                    temp=temp/10;
                    score_ind[2]=temp%10;
                    temp=temp/10;
                    score_ind[3]=temp%10;
                    //temp=i_pass+heropass*40;
                    printf("%d %d %d %d",score,heropass,i_pass,name[0].b);
                    gamestate=10;
                    //iPauseTimer(0);

                }
            }

        }
        if(hero==2)
        {
            if(play<0)
            {
                iClear();
                if(music==100)
                {
                    PlaySound("project\\cod.wav",NULL,SND_ASYNC | SND_LOOP);
                    music=200;
                }
                iShowBMP(0,0,"project\\haven_blur.bmp");
                iSetColor(0,0,0);
                iText(600,250,"Press p any time to start/resume or pause the game",GLUT_BITMAP_TIMES_ROMAN_24);
                iShowBMP2(200,0,"project\\menus2.bmp",0xffffff);
                iPauseTimer(0);
                if(settings==1)
                {
                    iClear();
                    iShowBMP(0,0,"project\\blur.bmp");
                    iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
                    if(sound>0)
                    {
                        iShowBMP2(500,180,"project\\snon.bmp",0xffffff);
                    }
                    else
                        iShowBMP2(500,180,"project\\snoff.bmp",0xffffff);
                    iShowBMP2(800,200,"project\\instructions.bmp",0xffffff);
                    if(instcn==1)
                    {
                        iClear;
                        iShowBMP(0,0,"project\\instbg.bmp");
                        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
                    }
                }

            }
            if(play>0)
            {
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                iResumeTimer(4);
                iResumeTimer(5);
                iResumeTimer(6);
                iResumeTimer(7);
                iResumeTimer(8);
                iResumeTimer(9);
                iResumeTimer(10);
                iClear();
                iShowBMP(0,0,"project\\haven.bmp");
                iShowBMP2(20,500,hlife[hlifind],0xffffff);
                    if(heroindex<150) hlifind=1;
                    if(heroindex<100) hlifind=2;
                    if(heroindex<30) hlifind=3;
                iShowBMP2(1350,500,vlife[vlifind],0xffffff);
                //iShowBMP2(20,500,"project\\life100.bmp",0xffffff);
                //iShowBMP2(1350,500,"project\\vlife100.bmp",0xffffff);
                iShowBMP2(chrctrX,chrctrY,"project\\chambergmp.bmp",0xffffff);
                iShowBMP2(1400,2,"project\\venom.bmp",0xffffff);
                ultpoint();
                iShowBMP2(20,580,ult[ult_in],0xf5f5f5);
                iShowBMP2(780,540,"project\\pause.bmp",0);
                iShowBMP2(vbullet_x,vbullet_y,"project\\bfire.bmp",0xf7f7f7);
                hcollision();
                dbldmgblt();
                if(hbullet==1)
                {
                    if(bltindex==2)
                        iShowBMP2(hbullet_x,hbullet_y,bullet[bltindex],0);
                    else
                        iShowBMP2(hbullet_x,hbullet_y,bullet[bltindex],0xffffff);
                }
                iShowBMP2(1400,2,"project\\venom.bmp",0xffffff);
                if(grnbldactv==1 && grntimer>0)
                {
                    iShowBMP2(1350,100,grn_bld[grn_ind],0xffffff);
                    if(grntimer%5==0)
                    {
                        grn_ind++;
                    }
                    grntimer--;
                    if(grntimer==0)
                    {
                        grnbldactv=0;
                        grn_ind=0;
                        grntimer=35;
                    }
                }

                //iShowBMP2(735,560,"New folder\\pause.bmp",0);
                itoa(i,cnt,10);
                iSetColor(0,0,0);
                iText(745,520,cnt,GLUT_BITMAP_TIMES_ROMAN_24);
                if(rbldactv==1)
                {
                    iShowBMP2(chrctrX+40,chrctrY+60,red_bld[red_ind],0xf7f7f7);
                    rbldchange();
                }
                i--;
                if(i%500==0)
                {
                    iResumeTimer(2);
                    rckt_x=1600;
                    rckt_y=chrctrY+50;
                }
                iShowBMP2(rckt_x,rckt_y,"project//rocketlft.bmp",0xffffff);
                if((i<9200&&i>9000)||(i<7200&&i>7000)||(i<5200&&i>5000)||(i<3200&&i>3000)||(i<1200&&i>1000))
                {
                    iSetColor(255,0,0);
                    iFilledCircle(chrctrX+10,690,100);
                }
                if((i-1000)%2000==0)
                {
                    //iResumeTimer(3);
                    msl_x=chrctrX;
                    msl_y=chrctrY+638;
                }
                if(msl_actv==1)
                {
                    iShowBMP2(expl_x,expl_y,explosion[expl_index],0xffffff);
                }
                /*if(!(msl_x>=chrctrX&&msl_x<=chrctrX+80&&msl_y>=chrctrY&&msl_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(msl_x,msl_y,"project//missile.bmp",0xf7f7f7);
                if(i%800==0)
                {
                    dblt_x=rand()%1000;
                    dblt_y=650;
                }
                /*if(!(dblt_x>=chrctrX&&dblt_x<=chrctrX+80&&dblt_y>=chrctrY&&dblt_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(dblt_x,dblt_y,"project//dbl.bmp",0xffffff);
                if(i%600==0)
                {
                    dmg_x=rand()%1000;
                    dmg_y=650;
                }
                /*if(!(dmg_x>=chrctrX&&dmg_x<=chrctrX+80&&dmg_y>=chrctrY&&dmg_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(dmg_x,dmg_y,"project//dmgmp.bmp",0);
                if(i%500==0)
                {
                    ult_x=rand()%1000;
                    ult_y=650;
                }
                /*if(!(ult_x>=chrctrX&&ult_x<=chrctrX+80&&ult_y>=chrctrY&&ult_y<=chrctrY+121))
                {

                }*/
                iShowBMP2(ult_x,ult_y,"project//ult.bmp",0);
                herolifechange();
                itoa(heroindex,hero_life,10);
                iSetColor(0,0,0);
                iText(20,550,hero_life,GLUT_BITMAP_TIMES_ROMAN_24);
                itoa(vln_index,vln_lf,10);
                iText(1500,550,vln_lf,GLUT_BITMAP_TIMES_ROMAN_24);
                if(ulttmr>0 && ultactv==1)
                {
                    iShowBMP2(1400,2,chamb_ult[chamb_in],0xffffff);
                    if(ulttmr2%3==0)
                    {
                        chamb_in++;
                        if(chamb_in==21) chamb_in=0;
                    }
                    ulttmr--;
                    ulttmr2--;
                    if(ulttmr2<0) ulttmr2=60;
                    if(ulttmr%6==0)
                    {
                        vln_index--;
                    }
                    if(ulttmr==0) ultactv=0;
                }
                if(heroindex<1 || i<1)
                {
                    iClear();
                    losegame=1;
                    iShowBMP(0,0,"project\\finalbg.bmp");
                    iShowBMP2(600,100,"project\\lose_game.bmp",0xf0f0f0);
                    iSetColor(0,0,0);
                    iText(600,500,"CONTINUE TO THE MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                    iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
                }
                iResumeTimer(0);
                //win game
                if(vln_index<=0)
                {
                    //score=i/20+heroindex*2;
                    i_pass=i/20;
                    heropass=heroindex*2;

                    score=i_pass+heropass;
                    name[0].b=score;
                    temp=i_pass+heropass;
                    score_ind[0]=temp%10;
                    temp=temp/10;
                    score_ind[1]=temp%10;
                    temp=temp/10;
                    score_ind[2]=temp%10;
                    temp=temp/10;
                    score_ind[3]=temp%10;
                    //temp=i_pass+heropass*40;
                    printf("%d %d %d %d",score,heropass,i_pass,name[0].b);
                    gamestate=10;
                    //iPauseTimer(0);

                }
            }


        }
    }
     else if(gamestate==1)
    {
        iShowBMP(0,0,"project\\instbg.bmp");
        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);

    }
     else if(gamestate==2)
    {
        iClear();
        iShowBMP(0,0,"project\\leaderboard.bmp");
        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
        iSetColor(0,0,0);
        filecheck();
        iText(50,350,name[1].a,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(50,300,name[2].a,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(50,250,name[3].a,GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(name[1].b,str2[0],10);
        itoa(name[2].b,str2[1],10);
        itoa(name[3].b,str2[2],10);
        iText(200,350,str2[0],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,300,str2[1],GLUT_BITMAP_TIMES_ROMAN_24);
        iText(200,250,str2[2],GLUT_BITMAP_TIMES_ROMAN_24);

    }
    else if(gamestate==10)
    {
        //score=i_pass+heropass*40;

       /*if(one==1)
        {
            score_ind[0]=temp%10;
            temp=temp/10;
            score_ind[1]=temp%10;
            temp=temp/10;
            score_ind[2]=temp%10;
            temp=temp/10;
            score_ind[3]=temp%10;
            temp=i_pass+heropass*40;

          one--;
        }*/
        //printf("%d\n",score);
        //name[0].b=score;
        iClear();
        iShowBMP(0,0,"project\\win_game.bmp");
        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
        iShowBMP2(280,100,scoreimg[score_ind[0]],0xffffff);
        iShowBMP2(220,100,scoreimg[score_ind[1]],0xffffff);
        iShowBMP2(160,100,scoreimg[score_ind[2]],0xffffff);
        iShowBMP2(100,100,scoreimg[score_ind[3]],0xffffff);

        iSetColor(0,0,0);
        iRectangle(100,50,350,50);
        if(write==1)
        {
            iSetColor(0, 0, 0);
            iText(110, 60, str ,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        iText(100,30,"ENTER YOUR NAME",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(gamestate==11)
    {
        iClear();
        iShowBMP(0,0,"project\\creditsFA.bmp");
        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
    }
    else if(gamestate==12)
    {
        iClear();
        iShowBMP(0,0,"project\\gm12.bmp");
        iShowBMP2(1300,500,"project\\back.bmp",0xffffff);
        if(highscore==1)
        {
            iShowBMP2(50,350,"project\\cngrts.bmp",0xffffff);
        }
        iText(50,300,name[0].a,GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(name[0].b,str2[3],10);
        iText(200,300,str2[3],GLUT_BITMAP_TIMES_ROMAN_24);
        g12--;
        if(g12==0)
        {
            gamestate=-1;
        }
    }
}


void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
    int j=10,k=50;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {


            if(gamestate==-1&&mx>=155&&mx<=470&&my>=243&&my<=288)
            {
                gamestate=2;


            }
             else if(gamestate==-1&&mx>=155&&mx<=460&&my>=327&&my<=358)
            {
                gamestate=1;

            }
             else if(gamestate==-1&&mx>=150&&mx<=430&&my>=408&&my<=446)
            {
                gamestate=0;

                vbullet_x=1600;
                vbullet_y=60;
                hbullet=-1;
                play=-1;
                i=10000;
                j=700;
                ult_in=3;
                hlifind=0;
                vlifind=0;
                ldindex=0;
                heroindex=200;
                vln_index=200;
                instcn=0;
                bltindex=0;
                blttmr=400;
                ultactv=0;
                light_ind=0;
                chrctrX=20;
                chrctrY=210;
                chamb_in=0;
                hero=0;
                highscore=0;
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                iResumeTimer(4);
                iResumeTimer(5);
                iResumeTimer(6);
                iResumeTimer(7);
                iResumeTimer(8);
                iResumeTimer(9);
                iResumeTimer(10);

            }
            else if((gamestate==1||gamestate==2||gamestate==11||gamestate==12)&&mx>=1250&&mx<=1250+150&&my>=450&&my<=450+150)
            {
                gamestate=-1;
            }
            else if(gamestate==-1&&mx>=1290&&mx<=1290+290&&my>=10&&my<=10+70)
            {
                sound*=-1;
                if(sound>0)
                {
                    PlaySound("project\\bgm.wav",NULL,SND_ASYNC | SND_LOOP);
                }
                else if(sound<0){
                    PlaySound(NULL,NULL,0);
                }
             }

            else if(gamestate==0&&hero==0&&mx>=200&&mx<=200+326&&my>=10&&my<=10+500)
            {
                hero=1;
                iResumeTimer(0);
            }
            else if(gamestate==0&&hero==0&&mx>=1100&&mx<=1100+326&&my>=10&&my<=10+500)
            {
                hero=2;
                iResumeTimer(0);
            }
            if(gamestate==0&&(hero==1||hero==2)&&play>0&&mx>=0&&mx<=1600&&my>=00&&my<=638&&hbullet==-1)

            {
               hbullet=1;
               hbullet_x=chrctrX+100;
               hbullet_y=chrctrY+90;
            }
            if(gamestate==0&&(hero==1 || hero==2)&&mx>=735&&mx<=735+70&&my>=560&&my<=560+70 &&play==1)
            {
                play=-1;
                iPauseTimer(0);
            }
            if(gamestate==0&&play==-1&&(hero==1||hero==2)&&mx>=43+200&&mx<=235+200&&my>=282&&my<=387)
            {
                play=1;
                iResumeTimer(0);
            }
            if(gamestate==0&&play==-1&&(hero==1||hero==2)&&mx>=43+200&&mx<=250+200&&my>=182&&my<=255)
            {
                settings=1;
            }
            if(gamestate==0&&play==-1&&(hero==1||hero==2)&&mx>=45&&mx<=235+200&&my>=77&&my<=157)
            {
                gamestate=-1;
            }
            if(gamestate==0&&play==-1&&(hero==1||hero==2)&&settings==1&&mx>=500&&mx<=500+173&&my>=180&&my<=180+184)
            {
                sound*=-1;
                if(sound>0)
                {
                    PlaySound("project\\cod.wav",NULL,SND_ASYNC | SND_LOOP);
                }
                else{
                    PlaySound(NULL,NULL,0);
                }
            }
            if(gamestate==0&&play==-1&&(hero==1||hero==2)&&settings==1&&mx>=800&&mx<=800+290&&my>=200&&my<=200+72)
            {
                instcn=1;
            }
            else if(gamestate==0&&(hero==1||hero==2)&&play<0&&instcn==1&&mx>=1250&&mx<=1250+150&&my>=450&&my<=450+150)
            {
                instcn=0;
            }
            else if(gamestate==0&&(hero==1||hero==2)&&settings==1&&play<0&&mx>=1250&&mx<=1250+150&&my>=450&&my<=450+150)
            {
                settings=0;
            }
            else if(gamestate==0&&(hero==1||hero==2)&&losegame==1&&play>0&&mx>=1250&&mx<=1250+150&&my>=450&&my<=450+150)
            {
                gamestate=-1;
                losegame=0;

               /* vbullet_x=1600;
                vbullet_y=60;
                hbullet=-1;
                play=-1;
                i=10000;
                j=700;
                ult_in=3;
                hlifind=0;
                vlifind=0;
                ldindex=0;
                heroindex=200;
                vln_index=200;
                instcn=0;
                bltindex=0;
                blttmr=400;
                ultactv=0;
                light_ind=0;
                chrctrX=20;
                chrctrY=210;*/
            }
            if(gamestate==10&& mx>100&&mx<400 && my>50 && my<100 && write==0)
            {
                write=1;
                if(write ==1)
                {
                    printf("hoise");
                }
            }
            if(gamestate==11&& mx>50 && mx<150 && my>33 &&my<54)
            {
                gamestate=-1;
            }
            else if(gamestate==-1 && mx>65 && mx<395 && my>50 && my<110)
            {
                gamestate=11;
            }
           /* if(gamestate==10&&mx>10&&mx<400 && my>5 && my<50 && write==1)
            {
                write = 0;
			strcpy(str2, str);
			printf("%s\n",str2);
			for(int k = 0; k < len; k++)
				str[k] = 0;
			len = 0;
			gamestate=-1;
            }*/
        }
    }


void iKeyboard(unsigned char key)
{
    int k;
    if(key=='p')
    {
        play*=-1;
        if(play>0) iResumeTimer(0);
        else iPauseTimer(0);
    }
    if(key=='x' && ult_in==3)
    {
        if(hero==1)
        {
            ultactv=1;
            ult_in=0;
            ulttmr=300;
            light_ind=0;


        }
        else if(hero==2){
            ultactv=1;
            ult_in=0;
            chamb_in=0;
            ulttmr=300;
            ulttmr2=60;
        }
    }
    if(write==1)
    {
        if(key == '\r')
		{

			strcpy(name[0].a , str);
			printf("%s\n",name[0].a);
			for( k = 0; k < len; k++)
            {
                str[k] = 0;
            }

			len = 0;
			//name[0].b=score;
            filecheck();
            if(name[0].b>name[1].b)
            {
                name[3]=name[2];
                name[2]=name[1];
                name[1]=name[0];
                highscore=1;
            }
            else if(name[0].b>name[2].b)
            {
                name[3]=name[2];
                name[2]=name[0];
            }
            else if(name[0].b>name[3].b)
            {
                name[3]=name[0];
            }
            filewrite();
            write = 0;
            gamestate=12;
            printf("\n%s %s %s %s\n%d %d %d %d",name[1].a,name[2].a,name[3].a,name[0].a,name[1].b,name[2].b,name[3].b,name[0].b);

		}
		else{

			str[len] = key;
			len++;
			printf("%c\n",str[len]);
		}

    }

}



void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
	{

	}
	if(key == GLUT_KEY_LEFT && chrctrX>=10)
	{
		chrctrX-=20;
	}
	if(key == GLUT_KEY_RIGHT && chrctrX<=1100)
	{
		chrctrX+=20;
	}
	if(key == GLUT_KEY_UP && chrctrY<=350)
	{
		chrctrY+=20;
	}
	if(key == GLUT_KEY_DOWN && chrctrY>=25)
	{
		chrctrY-=20;
	}

}

void filecheck()
{
    FILE *fp;
    fp=fopen("score.txt","r");
    int ch=1;
    while((fscanf(fp,"%s %d",name[ch].a,&name[ch].b)!=EOF)&&ch<=3)
     {
         ch++;
     }
     fclose(fp);
}

void filewrite()
{
    FILE *fp;
    int m;
    fp=fopen("score.txt","w");
    for(m=1;m<=3;m++)
    {
        fprintf(fp,"%s %d\n",name[m].a,name[m].b);
    }
    fclose(fp);
}

void vbulletchange()
{
    vbullet_x-=vdx;
               if(vbullet_x<=-50)
                   vbullet_x=1300;
               if(vbullet_x>=chrctrX&&vbullet_x<=chrctrX+80&&vbullet_y>=chrctrY-50&&vbullet_y<=chrctrY+121)
                {
                    heroindex-=10;
                    rbldactv=1;
                    red_ind=0;
                    vbullet_x=1300;
                }
}
void hbulletchange()
{
    hbullet_x+=hdx;
}

void hcollision()
{
    if((hbullet_y>=0&&hbullet_y<=220&&hbullet_x>=1450)&&hbullet==1)
    {
        if(bltindex==0)
        {
            if(hbullet_y>=120&&hbullet_y<=140)
              {
                vln_index-=10;
              }

            else
            {
                vln_index-=5;
            }

        }
        else if(bltindex==2)
        {
            if(hbullet_y>=120&&hbullet_y<=140)
              {
                vln_index-=25;
              }

            else
            {
                vln_index-=15;
            }

        }
        else{
            if(hbullet_y>=120&&hbullet_y<=140)
              {
                vln_index-=20;
              }

            else
            {
                vln_index-=10;
            }

        }
        hbullet_x=1800;
        hbullet=-1;
        grnbldactv=1;
    }
    if(hbullet_y>200&&hbullet_x>1630)
    {
        hbullet=-1;
    }
    if(vln_index<150) vlifind=1;
    if(vln_index<100) vlifind=2;
    if(vln_index<50) vlifind=3;
}

void rocketchange()
{
    rckt_x-=rdx;
}

void mslchange()
{
    msl_y-=mdy;
}

void dblchange()
{
    dblt_y-=dbdy;
}

void dmgchange()
{
    dmg_y-=dmdy;
}

void ultchange()
{
    ult_y-=udy;
}

void ldindchange()
{
    ldindex++;
    if(ldindex==16) ldindex=0;
}
void rbldchange()
{
    red_ind++;
    if(red_ind==8) rbldactv=0;
}
void herolifechange()
{
            if(rckt_x>=chrctrX&&rckt_x<=chrctrX+80&&rckt_y>=chrctrY&&rckt_y<=chrctrY+121)
                {
                    heroindex-=20;
                    rckt_x=-200;
                    msl_actv=1;
                    expl_x=chrctrX-10;
                    expl_y=chrctrY;
                    expl_index=0;
                }
                if(msl_x>=chrctrX-50&&msl_x<=chrctrX+80+50&&msl_y>=chrctrY&&msl_y<=chrctrY+121)
                {
                    heroindex-=30;
                    msl_x=-200;
                    msl_actv=1;
                    expl_x=chrctrX-10;
                    expl_y=chrctrY;
                    expl_index=0;
                }
}

void dbldmgblt()
{
    blttmr--;
    if(dblt_x>=chrctrX-50&&dblt_x<=chrctrX+50+80&&dblt_y>=chrctrY&&dblt_y<=chrctrY+121)
    {
        dblt_x=1800;
        bltindex=1;
        blttmr=400;
    }

    if(blttmr<0)
    {
        bltindex=0;
    }
    if(dmg_x>=chrctrX-50&&dmg_x<=chrctrX+50+80&&dmg_y>=chrctrY&&dmg_y<=chrctrY+121)
    {
        dmg_x=1800;
        bltindex=2;
        blttmr=400;
    }
    if(blttmr<0)
    {
        bltindex=0;
    }
}

void ultpoint()
{
    if(ult_x>=chrctrX-80&&ult_x<=chrctrX+50+80&&ult_y>=chrctrY&&ult_y<=chrctrY+121)
    {
        if(ult_in<3)
        {
            ult_in++;
        }

        ult_x=1800;
    }
}

void lighchange()
{
    light_ind++;
    if(light_ind==11) light_ind=0;
}

/*void chamb_inchange()
{
    chamb_in++;
    if(chamb_in==10) chamb_in=0;
}*/



void explchange()
{
    expl_index++;
    if(expl_index==14) msl_actv=0;
}

int main()
{
    len = 0;
	write = 0;
	str[0]= 0;

   chrctrX=20;
   chrctrY=210;

   iSetTimer(5,vbulletchange);
   vdx=15;

   iSetTimer(5,hbulletchange);
   hdx=30;

   iSetTimer(25,rocketchange);
   rdx=10;

   iSetTimer(25,mslchange);
   mdy=15;

   iSetTimer(25,dblchange);
   dbdy=5;

   iSetTimer(25,ultchange);
   udy=5;

   iSetTimer(25,dmgchange);
   dmdy=5;

   iSetTimer(50,ldindchange);

   iSetTimer(50,lighchange);

   iSetTimer(100,explchange);

   //iSetTimer(50,chamb_inchange);

   //iSetTimer(50,rbldchange);

   //PlaySound("project\\bgm.wav",NULL,SND_ASYNC | SND_LOOP);

   //filecheck();


    iInitialize(1600,638, "FORTIS");

    return 0;
}
