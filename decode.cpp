#include "decode.h"
#include <omp.h>

int* decode2(cv::Mat Frame,int shift){
    int NumbersOfRow=0,HalfNumbersOfRow=0,NumbersOfColumn=0,
            CurrentRow=0,CurrentColumn=0,
            Counter1=0,Counter2=0,Counter3=0,WhiteCounter=0,
            Temp1=0,Temp2=0,Temp3=0,
            Col1=0,Col2=0,
            Width=0,TempWidth=0,
            L6,R6,
            Key1,Key2,Key3,Key4,
            Temp1stNum;
    float GroupWidth=0;
    int Left4LinesLocate[4]={0},
        BarWidth[4]={0},
        BarUnit[4]={0},
        Head[6]={0},
        Num[13]={0},
        edges[200];// here would cause segmentation fault!!!
    char code[94]={0};
    char n[]={3,10,17,24,31,38};
    char n2[]={51,58,65,72,79,86};

    //find left Left4LinesLocatege , and minimum width
    NumbersOfRow = Frame.rows;            //n rows
    NumbersOfColumn = Frame.cols;         //n columns
    HalfNumbersOfRow = NumbersOfRow/2;       //n/2 rows
    uchar* Current = Frame.ptr<uchar>(HalfNumbersOfRow+shift);

//Save edges' location
    for(Counter1=5,Counter2=0;Counter1<NumbersOfColumn;Counter1++){
        if(Current[Counter1]==0)//read black bar(0 is black)
        {
            edges[Counter2]=Counter1;
            Counter2++;
        }
    }




//Find left 6 numbers
    Counter2=1;
    Counter3=0;

//#pragma omp parallel for

    for(L6=0;L6<6;L6++)
    {
        GroupWidth=(edges[7+L6*4]-edges[3+L6*4])/7;
        if(GroupWidth<1){GroupWidth=1;}

        BarWidth[0]=(edges[4+L6*4]-edges[3+L6*4])-GroupWidth;
        BarWidth[1]=(edges[5+L6*4]-edges[4+L6*4])-GroupWidth;
        BarWidth[2]=(edges[6+L6*4]-edges[5+L6*4])-GroupWidth;
        BarWidth[3]=(edges[7+L6*4]-edges[6+L6*4])-GroupWidth;

        BarUnit[0]=BarUnit[1]=BarUnit[2]=BarUnit[3]=1;

        for(Temp1=0;Temp1<3;Temp1++)
        {
            Temp2=findMax(&BarWidth[0],4);
            BarWidth[Temp2]-=GroupWidth;
            BarUnit[Temp2]++;
        }
        Temp3=BarUnit[0]*1000+BarUnit[1]*100+BarUnit[2]*10+BarUnit[3];
        //cout<<Temp3;
        switch(Temp3){
            case 3211:
                Num[L6+1]=0;
                Head[L6]=0;
                break;
            case 1123:
                Num[L6+1]=0;
                Head[L6]=1;
                break;
            case 2221:
                Num[L6+1]=1;
                Head[L6]=0;
                break;
            case 1222:
                Num[L6+1]=1;
                Head[L6]=1;
                break;
            case 2122:
                Num[L6+1]=2;
                Head[L6]=0;
                break;
            case 2212:
                Num[L6+1]=2;
                Head[L6]=1;
                break;
            case 1411:
                Num[L6+1]=3;
                Head[L6]=0;
                break;
            case 1141:
                Num[L6+1]=3;
                Head[L6]=1;
                break;
            case 1132:
                Num[L6+1]=4;
                Head[L6]=0;
                break;
            case 2311:
                Num[L6+1]=4;
                Head[L6]=1;
                break;
            case 1231:
                Num[L6+1]=5;
                Head[L6]=0;
                break;
            case 1321:
                Num[L6+1]=5;
                Head[L6]=1;
                break;
            case 1114:
                Num[L6+1]=6;
                Head[L6]=0;
                break;
            case 4111:
                Num[L6+1]=6;
                Head[L6]=1;
                break;
            case 1312:
                Num[L6+1]=7;
                Head[L6]=0;
                break;
            case 2131:
                Num[L6+1]=7;
                Head[L6]=1;
                break;
            case 1213:
                Num[L6+1]=8;
                Head[L6]=0;
                break;
            case 3121:
                Num[L6+1]=8;
                Head[L6]=1;
                break;
            case 3112:
                Num[L6+1]=9;
                Head[L6]=0;
                break;
            case 2113:
                Num[L6+1]=9;
                Head[L6]=1;
                break;
            default :
                Num[L6]=-9999;
                break;
        }

    }


//Find right 6 numbers
    Counter2=1;
    Counter3=0;
//#pragma omp parallel for
    for(R6=0;R6<6;R6++)
    {
        GroupWidth=(edges[36+R6*4]-edges[32+R6*4])/7;
        if(GroupWidth<1){GroupWidth=1;}
        //cout<<endl<<"GW is"<<GroupWidth<<endl;

        BarWidth[0]=(edges[33+R6*4]-edges[32+R6*4])-GroupWidth;
        BarWidth[1]=(edges[34+R6*4]-edges[33+R6*4])-GroupWidth;
        BarWidth[2]=(edges[35+R6*4]-edges[34+R6*4])-GroupWidth;
        BarWidth[3]=(edges[36+R6*4]-edges[35+R6*4])-GroupWidth;

        //cout<<"1st BW is"<<BarWidth[0]<<"."<<BarWidth[1]<<"."<<BarWidth[2]<<"."<<BarWidth[3]<<endl;

        BarUnit[0]=BarUnit[1]=BarUnit[2]=BarUnit[3]=1;

        for(Temp1=0;Temp1<3;Temp1++)
        {
            Temp2=findMax(&BarWidth[0],4);
            BarWidth[Temp2]-=GroupWidth;
            BarUnit[Temp2]++;

            //cout<<"BW is"<<BarWidth[0]<<"."<<BarWidth[1]<<"."<<BarWidth[2]<<"."<<BarWidth[3]<<endl;
            //cout<<"BU is"<<BarUnit[0]<<"."<<BarUnit[1]<<"."<<BarUnit[2]<<"."<<BarUnit[3]<<endl;
         }
        Temp3=BarUnit[0]*1000+BarUnit[1]*100+BarUnit[2]*10+BarUnit[3];
        //cout<<"("<<Temp3<<")";
        //cout<<Temp3;
        switch(Temp3){
            case 3211:
                Num[R6+7]=0;
                break;
            case 2221:
                Num[R6+7]=1;
                break;
            case 2122:
                Num[R6+7]=2;
                break;
            case 1411:
                Num[R6+7]=3;
                break;
            case 1132:
                Num[R6+7]=4;
                break;
            case 1231:
                Num[R6+7]=5;
                break;
            case 1114:
                Num[R6+7]=6;
                break;
            case 1312:
                Num[R6+7]=7;
                break;
            case 1213:
                Num[R6+7]=8;
                break;
            case 3112:
                Num[R6+7]=9;
                break;
            default :
                Num[R6+7]=-9999;
                break;
        }
    }
    //cout<<endl<<"NEXT"<<endl;

//calculte 1st number
    Key1=(Num[11]+Num[9]+Num[7]+Num[5]+Num[3]+Num[1])*3;
    Key2=Num[10]+Num[8]+Num[6]+Num[4]+Num[2];
    Key3=10-Num[12];
    Key4=(Key1+Key2)%10;
    if(Key3>Key4) {Num[0]=Key3-Key4;}
    if(Key3<Key4) {Num[0]=Key3+10-Key4;}
    if(Key3==Key4){Num[0]=0;}
    if(Key1<0||Key2<0)Num[0]=-98;

//find table for 1st number
    if(Head[1]==0)  //AA
    {
        if(Head[2]==0&&Head[3]==0&&Head[4]==0&&Head[5]==0)Temp1stNum=0;//AAAAAA
        if(Head[2]==1&&Head[3]==0&&Head[4]==1&&Head[5]==1)Temp1stNum=1;//AABABB
        if(Head[2]==1&&Head[3]==1&&Head[4]==0&&Head[5]==1)Temp1stNum=2;//AABBAB
        if(Head[2]==1&&Head[3]==1&&Head[4]==1&&Head[5]==0)Temp1stNum=3;//AABBBA
    }else{          //AB
        if(Head[2]==0)  //ABA
        {
            if(Head[3]==0&&Head[4]==1&&Head[5]==1)Temp1stNum=4;//ABAABB
            if(Head[3]==1&&Head[4]==0&&Head[5]==1)Temp1stNum=7;//ABABAB
            if(Head[3]==1&&Head[4]==1&&Head[5]==0)Temp1stNum=8;//ABABBA
        }else{          //ABB
            if(Head[3]==0&&Head[4]==0&&Head[5]==1)Temp1stNum=5;//ABBAAB
            if(Head[3]==0&&Head[4]==1&&Head[5]==0)Temp1stNum=9;//ABBABA
            if(Head[3]==1&&Head[4]==0&&Head[5]==0)Temp1stNum=6;//ABBBAA
        }
    }


    if(Num[0]==Temp1stNum){
        return Num;

        /*
        cout<<"Answer is:"<<endl;
        cout<<Num[0]<<" "
            <<Num[1]<<" "<<Num[2]<<" "<<Num[3]<<" "<<Num[4]<<" "<<Num[5]<<" "<<Num[6]<<" "
            <<Num[7]<<" "<<Num[8]<<" "<<Num[9]<<" "<<Num[10]<<" "<<Num[11]<<" "<<Num[12]<<endl;
        */
    }

    return NULL;

}

void decode(cv::Mat Frame1,int shift,int* Num)
{


    cv::Mat Frame;
    Frame1.copyTo(Frame);
    int NumbersOfRow=0,HalfNumbersOfRow=0,NumbersOfColumn=0,
            CurrentRow=0,CurrentColumn=0,
            Counter1=0,Counter2=0,Counter3=0,WhiteCounter=0,
            Temp1=0,Temp2=0,Temp3=0,
            Col1=0,Col2=0,
            Width=0,TempWidth=0,
            L6,R6,
            Key1,Key2,Key3,Key4,
            Temp1stNum;
    float GroupWidth=0;
    int Left4LinesLocate[4]={0},
        BarWidth[4]={0},
        BarUnit[4]={0},
        Head[6]={0},
        //Num[13]={0},
        edges[200];
    char code[94]={0};
    char n[]={3,10,17,24,31,38};
    char n2[]={51,58,65,72,79,86};

    //find left Left4LinesLocatege , and minimum width
    NumbersOfRow = Frame.rows;            //n rows
    NumbersOfColumn = Frame.cols;         //n columns
    HalfNumbersOfRow = NumbersOfRow/2;       //n/2 rows
    uchar* Current = Frame.ptr<uchar>(HalfNumbersOfRow+shift);

//Save edges' location
    for(Counter1=5,Counter2=0;Counter1<NumbersOfColumn;Counter1++){
        if(Current[Counter1]==0)//read black bar(0 is black)
        {
            edges[Counter2]=Counter1;
            Counter2++;
        }
    }




//Find left 6 numbers
    Counter2=1;
    Counter3=0;

//#pragma omp parallel for

    for(L6=0;L6<6;L6++)
    {
        GroupWidth=(edges[7+L6*4]-edges[3+L6*4])/7;
        if(GroupWidth<1){GroupWidth=1;}

        BarWidth[0]=(edges[4+L6*4]-edges[3+L6*4])-GroupWidth;
        BarWidth[1]=(edges[5+L6*4]-edges[4+L6*4])-GroupWidth;
        BarWidth[2]=(edges[6+L6*4]-edges[5+L6*4])-GroupWidth;
        BarWidth[3]=(edges[7+L6*4]-edges[6+L6*4])-GroupWidth;

        BarUnit[0]=BarUnit[1]=BarUnit[2]=BarUnit[3]=1;

        for(Temp1=0;Temp1<3;Temp1++)
        {
            Temp2=findMax(&BarWidth[0],4);
            BarWidth[Temp2]-=GroupWidth;
            BarUnit[Temp2]++;
        }
        Temp3=BarUnit[0]*1000+BarUnit[1]*100+BarUnit[2]*10+BarUnit[3];
        //cout<<Temp3;
        switch(Temp3){
            case 3211:
                Num[L6+1]=0;
                Head[L6]=0;
                break;
            case 1123:
                Num[L6+1]=0;
                Head[L6]=1;
                break;
            case 2221:
                Num[L6+1]=1;
                Head[L6]=0;
                break;
            case 1222:
                Num[L6+1]=1;
                Head[L6]=1;
                break;
            case 2122:
                Num[L6+1]=2;
                Head[L6]=0;
                break;
            case 2212:
                Num[L6+1]=2;
                Head[L6]=1;
                break;
            case 1411:
                Num[L6+1]=3;
                Head[L6]=0;
                break;
            case 1141:
                Num[L6+1]=3;
                Head[L6]=1;
                break;
            case 1132:
                Num[L6+1]=4;
                Head[L6]=0;
                break;
            case 2311:
                Num[L6+1]=4;
                Head[L6]=1;
                break;
            case 1231:
                Num[L6+1]=5;
                Head[L6]=0;
                break;
            case 1321:
                Num[L6+1]=5;
                Head[L6]=1;
                break;
            case 1114:
                Num[L6+1]=6;
                Head[L6]=0;
                break;
            case 4111:
                Num[L6+1]=6;
                Head[L6]=1;
                break;
            case 1312:
                Num[L6+1]=7;
                Head[L6]=0;
                break;
            case 2131:
                Num[L6+1]=7;
                Head[L6]=1;
                break;
            case 1213:
                Num[L6+1]=8;
                Head[L6]=0;
                break;
            case 3121:
                Num[L6+1]=8;
                Head[L6]=1;
                break;
            case 3112:
                Num[L6+1]=9;
                Head[L6]=0;
                break;
            case 2113:
                Num[L6+1]=9;
                Head[L6]=1;
                break;
            default :
                Num[L6]=-9999;
                break;
        }

    }


//Find right 6 numbers
    Counter2=1;
    Counter3=0;
//#pragma omp parallel for
    for(R6=0;R6<6;R6++)
    {
        GroupWidth=(edges[36+R6*4]-edges[32+R6*4])/7;
        if(GroupWidth<1){GroupWidth=1;}
        //cout<<endl<<"GW is"<<GroupWidth<<endl;

        BarWidth[0]=(edges[33+R6*4]-edges[32+R6*4])-GroupWidth;
        BarWidth[1]=(edges[34+R6*4]-edges[33+R6*4])-GroupWidth;
        BarWidth[2]=(edges[35+R6*4]-edges[34+R6*4])-GroupWidth;
        BarWidth[3]=(edges[36+R6*4]-edges[35+R6*4])-GroupWidth;

        //cout<<"1st BW is"<<BarWidth[0]<<"."<<BarWidth[1]<<"."<<BarWidth[2]<<"."<<BarWidth[3]<<endl;

        BarUnit[0]=BarUnit[1]=BarUnit[2]=BarUnit[3]=1;

        for(Temp1=0;Temp1<3;Temp1++)
        {
            Temp2=findMax(&BarWidth[0],4);
            BarWidth[Temp2]-=GroupWidth;
            BarUnit[Temp2]++;

            //cout<<"BW is"<<BarWidth[0]<<"."<<BarWidth[1]<<"."<<BarWidth[2]<<"."<<BarWidth[3]<<endl;
            //cout<<"BU is"<<BarUnit[0]<<"."<<BarUnit[1]<<"."<<BarUnit[2]<<"."<<BarUnit[3]<<endl;
         }
        Temp3=BarUnit[0]*1000+BarUnit[1]*100+BarUnit[2]*10+BarUnit[3];
        //cout<<"("<<Temp3<<")";
        //cout<<Temp3;
        switch(Temp3){
            case 3211:
                Num[R6+7]=0;
                break;
            case 2221:
                Num[R6+7]=1;
                break;
            case 2122:
                Num[R6+7]=2;
                break;
            case 1411:
                Num[R6+7]=3;
                break;
            case 1132:
                Num[R6+7]=4;
                break;
            case 1231:
                Num[R6+7]=5;
                break;
            case 1114:
                Num[R6+7]=6;
                break;
            case 1312:
                Num[R6+7]=7;
                break;
            case 1213:
                Num[R6+7]=8;
                break;
            case 3112:
                Num[R6+7]=9;
                break;
            default :
                Num[R6+7]=-9999;
                break;
        }
    }
    //cout<<endl<<"NEXT"<<endl;

//calculte 1st number
    Key1=(Num[11]+Num[9]+Num[7]+Num[5]+Num[3]+Num[1])*3;
    Key2=Num[10]+Num[8]+Num[6]+Num[4]+Num[2];
    Key3=10-Num[12];
    Key4=(Key1+Key2)%10;
    if(Key3>Key4) {Num[0]=Key3-Key4;}
    if(Key3<Key4) {Num[0]=Key3+10-Key4;}
    if(Key3==Key4){Num[0]=0;}
    if(Key1<0||Key2<0)Num[0]=-98;

//find table for 1st number
    if(Head[1]==0)  //AA
    {
        if(Head[2]==0&&Head[3]==0&&Head[4]==0&&Head[5]==0)Temp1stNum=0;//AAAAAA
        if(Head[2]==1&&Head[3]==0&&Head[4]==1&&Head[5]==1)Temp1stNum=1;//AABABB
        if(Head[2]==1&&Head[3]==1&&Head[4]==0&&Head[5]==1)Temp1stNum=2;//AABBAB
        if(Head[2]==1&&Head[3]==1&&Head[4]==1&&Head[5]==0)Temp1stNum=3;//AABBBA
    }else{          //AB
        if(Head[2]==0)  //ABA
        {
            if(Head[3]==0&&Head[4]==1&&Head[5]==1)Temp1stNum=4;//ABAABB
            if(Head[3]==1&&Head[4]==0&&Head[5]==1)Temp1stNum=7;//ABABAB
            if(Head[3]==1&&Head[4]==1&&Head[5]==0)Temp1stNum=8;//ABABBA
        }else{          //ABB
            if(Head[3]==0&&Head[4]==0&&Head[5]==1)Temp1stNum=5;//ABBAAB
            if(Head[3]==0&&Head[4]==1&&Head[5]==0)Temp1stNum=9;//ABBABA
            if(Head[3]==1&&Head[4]==0&&Head[5]==0)Temp1stNum=6;//ABBBAA
        }
    }


    if(Num[0]!=Temp1stNum){
        Num[0]=-1;
    }



}
int findMax(int* num, int numsOfThing)//input an array , and how long is this array
{
    int times,biggest=0;

    for(times=1;times<numsOfThing;times++)
    {
        if(num[biggest]<num[times])
        {
            biggest=times;
        }
    }

return biggest;//output the biggest one's location(in this array)

}
