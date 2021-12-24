#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"

void win(int *i,int xb,int yb,int s,int array[][s],int ap[][s]){
    if((array[xb][yb+1]==179)&&(array[xb][yb-1]==179)&&(array[xb+1][yb]==196)&&(array[xb-1][yb]==196)){
        ap[xb][yb]=178;
        array[xb][yb]=178;
        --*i;
        
    }
}
int score(int s,int a[][s]){
    int sp =0;
    for(int i=0;i<s;++i){
        for(int j=0;j<s;++j){
            if(a[i][j]==178){++sp;}
        }
    }
    return sp;
}


void print_array(int l,int grid,int array[][l],int p1[][l],int p2[][l]){
    int k = 0,i,t;
    for(i=1;i<=grid+1;++i){
        if(i==1){printf(BBLK"   %d",i);}
        else if(i==grid+1){printf(BBLK"     %d\n",i);}
        else{printf(BBLK"     %d",i);}
    }
    for (i=0;i<l;i++){
        if(i%2==0){
        printf(BBLK"%d ",++k);}
        else{
            printf("  ");
        }
        for (t=0;t<l-1;t++){
            if(array[i][t]==196&&p1[i][t]==196){
               printf(BBLU"%c%c%c",p1[i][t],p1[i][t],p1[i][t]);
            }
            else if (array[i][t]==179&&p1[i][t]==179){
                printf (BBLU" %c ",p1[i][t]);
            }
            else if (array[i][t]==179&&p2[i][t]==179){
                printf (BRED" %c ",p2[i][t]);
            }
            else if (array[i][t]==196&&p2[i][t]==196){
               printf(BRED"%c%c%c",p2[i][t],p2[i][t],p2[i][t]);}
            else{printf(WHT" %c ",array[i][t]);}
        }
             if (array[i][t]==179&&p1[i][t]==179){
                printf (BBLU" %c\n",p1[i][t]);
            }
            else if (array[i][t]==179&&p2[i][t]==179){
                printf (BRED" %c\n",p2[i][t]);
            }
            else{printf(WHT" %c\n",array[i][t]);}
    }
}
void swap(int *xp, int *yp)
{    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void Position(int *x,int *y){
    int z = *x;
    *x = (2*z)-3;
    z = *y;
    *y = (2*z)-2;
}
void print_grid(int s,int grid,int array[][s]){
    int i,t,k=0;
    for(i=0;i<s;++i){
    if(i%2==0){
        for(t=0;t<s;++t){
            if(t%2==0){array[i][t]=254;}
            else{array[i][t]=32;}
        }
    }
    else{
        for(t=0;t<s;++t){
            array[i][t]=32;
        }
    }
}
    for(i=1;i<=grid+1;++i){
        if(i==1){printf(BBLK"   %d",i);}
        else if(i==grid+1){printf(BBLK"     %d\n",i);}
        else{printf(BBLK"     %d",i);}
    }
    for (i=0;i<s;i++){
        if(i%2==0){
        printf(BBLK"%d ",++k);}
        for (t=0;t<s-1;t++){
            printf(WHT" %c ",array[i][t]);
    }
        printf(WHT" %c \n",array[i][t]);
}
}

int main()
{system("");
int i=0,t,x1,y1,x2,y2,s,grid,sp1=0,sp2=0,xb=0,yb=0,h;
printf("enter size of grid : ");
scanf("%d",&grid);
s = (2*grid)+1;
int array[s][s],p1[s][s],p2[s][s];
print_grid(s, grid , array);
while (sp1+sp2<grid*grid){
 if(i%2==0){
    printf(BBLU"Player1\n");
    printf("enter first block : ");
    scanf("%d %d",&x1,&y1);
    printf("enter second block : ");
    scanf("%d %d",&x2,&y2);
    if(x1>x2){
        swap(&x1,&x2);
        }
    if(y1>y2){
        swap(&y1,&y2);
        }
    if((x1>grid+1)||(x2>grid+1)||(y1>grid+1)||(y2>grid+1)){
        printf("enter a valid block\n");
    }
    else if((x1<0)||(x2<0)||(y1<0)||(y2<0)){
        printf("enter positive number\n");
    }
    else if((x1==x2)&&(y2-y1==1)){
        Position(&y2,&x1);
        if ((p1[x1][y2]==196)||(p2[x1][y2]==196)){printf("enter valid line ");}
        else{
        p1[x1][y2]=196;
        array[x1][y2]=196;
        ++i;
        xb = abs(x1-1);
        yb = y2;
        win(&i,xb,yb,s,array,p1);
        if((xb!=1)||(xb!=9)){
            xb += 2;
            win(&i,xb,yb,s,array,p1);
            if(array[xb][yb]==178){++i;}
        }
        sp1 = score(s,p1);
        print_array(s,grid,array,p1,p2);
        printf("%d %d",sp1,sp2);
        }
    }
    else if((y1==y2)&&(x2-x1==1)){
        Position(&x2,&y1);
        if ((p2[x2][y1]==179)||(p1[x2][y1]==179)){printf("enter valid line ");}
        else{
        p1[x2][y1]=179;
        array[x2][y1]=179;
        ++i;
        yb = abs(y1-1);
        xb = x2;
        win(&i,xb,yb,s,array,p1);
        if((yb!=1)||(yb!=9)){
            yb += 2;
            win(&i,xb,yb,s,array,p1);
            if(array[xb][yb]==178){++i;}
        }
        sp1 = score(s,p1);
        print_array(s,grid,array,p1,p2);
        printf("%d %d",sp1,sp2);
        }
    }
    else{printf("enter a valid block\n");}

  }
    else if(i%2==1){
    printf(BRED"Player2\n");
    printf("enter first block : ");
    scanf("%d %d",&x1,&y1);
    printf("enter second block : ");
    scanf("%d %d",&x2,&y2);
    if(x1>x2){
        swap(&x1,&x2);
        }
    if(y1>y2){
        swap(&y1,&y2);
        }
    if((x1>grid+1)||(x2>grid+1)||(y1>grid+1)||(y2>grid+1)){
        printf("enter a valid block\n");
    }
    else if((x1<0)||(x2<0)||(y1<0)||(y2<0)){
        printf("enter positive number\n");
    }
    else if((x1==x2)&&(y2-y1==1)){
        Position(&y2,&x1);
        if ((p1[x1][y2]==196)||(p2[x1][y2]==196)){printf("enter valid line ");}
        else{
        ++i;
        p2[x1][y2]=196;
        array[x1][y2]=196;
        xb = abs(x1-1);
        yb = y2;
        win(&i,xb,yb,s,array,p2);
        if((xb!=1)||(xb!=9)){
            xb += 2;
            win(&i,xb,yb,s,array,p2);
            if(array[xb][yb]==178){++i;}
        }
        sp2 = score(s,p2);
        print_array(s,grid,array,p1,p2);
        printf("%d %d",sp1,sp2);
        }
    }
    else if((y1==y2)&&(x2-x1==1)){
        Position(&x2,&y1);
        if ((p2[x2][y1]==179)||(p1[x2][y1]==179)){printf("enter valid line ");}
        else{
        p2[x2][y1]=179;
        array[x2][y1]=179;
        ++i;
        yb = abs(y1-1);
        xb = x2;
        win(&i,xb,yb,s,array,p2);

        if((yb!=1)||(yb!=9)){
            yb += 2;
            win(&i,xb,yb,s,array,p2);
            if(array[xb][yb]==178){++i;}
        }
        sp2 = score(s,p2);
        print_array(s,grid,array,p1,p2);
        printf("%d %d",sp1,sp2);
        }
    }
    else{printf("enter a valid block\n");}

 }
 }
    return 0;
}