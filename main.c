#include<windows.h>
#include<stdio.h>


struct subj
{
    char name[10];
    int score;
    char status;
};
struct student
{
    int id;
    char name[40];
    int sub_count;
    struct subj *sp[11] ;
};


struct student* add_stundent(id)
{
    struct student *p = malloc(sizeof(struct student));

    p->id=id;

    int n;

    printf("Please enter your name: ");
    scanf("%s", p->name);

    printf("Please enter the number of subjects: ");
    scanf("%d",&n);


    p->sub_count = n;

    for(int i=0; i<n; i++)
    {
        struct subj *sp = malloc(sizeof(struct subj));
        p->sp[i] = sp;
        printf("Please enter the number (from above)of subject  %d:",i+1);

        int sub_num;
        scanf("%d", &sub_num);
        switch(sub_num)
        {
        case 10:
            strcpy(p->sp[i]->name, "SQL");
            break;
        case 9:
            strcpy(p->sp[i]->name, ".NET");
            break;
        case 8:
            strcpy(p->sp[i]->name, "NODE.JS");
            break;
        case 7:
            strcpy(p->sp[i]->name, "REACT.JS");
            break;
        case 6:
            strcpy(p->sp[i]->name, "PHP");
            break;
        case 5:
            strcpy(p->sp[i]->name, "HTML");
            break;
        case 4:
            strcpy(p->sp[i]->name, "C++");
            break;
        case 3:
            strcpy(p->sp[i]->name, "OOP");
            break;
        case 2:
            strcpy(p->sp[i]->name, "JS");
            break;
        case 1:
            strcpy(p->sp[i]->name, "XML");
            break;
        default:
            printf("know number or answer");
            break;
        }

        printf("Please enter the score of subject %d: ",i+1);
        scanf("%d", &p->sp[i]->score);
        while (p->sp[i]->score < 0)
        {
            printf("The score cannot be a negative number. Please enter a valid score: ");
            scanf("%d", &p->sp[i]->score);
        }
        switch (p->sp[i]->score / 10)
        {
        case 10:
        case 9:
            p->sp[i]->status = 'A';
            break;
        case 8:
            p->sp[i]->status = 'B';
            break;
        case 7:
            p->sp[i]->status = 'C';
            break;
        case 6:
            p->sp[i]->status = 'D';
            break;
        default:
            p->sp[i]->status = 'F';
            break;
        }
    }

    return p;

};

void show_subj()
{
    char subjects[10][10];

    strcpy(subjects[1], "XML");
    strcpy(subjects[2], "JS");
    strcpy(subjects[3], "OOP");
    strcpy(subjects[4], "C++");
    strcpy(subjects[5], "HTML");
    strcpy(subjects[6], "PHP");
    strcpy(subjects[7], "REACT.JS");
    strcpy(subjects[8], "NODE.JS");
    strcpy(subjects[9], ".NET");
    strcpy(subjects[10], "SQL");

    gotoxy(1,2);
    SetColor(1);
    printf("THE MAIN SUBJECTS IS:   ");
    SetColor(2);
    for(int i=1; i<11; i++)
    {
        printf("%d-%s | ",i,subjects[i]);
    }
    gotoxy(0,15);
    SetColor(12);
}
void display_all_stud(struct student *p[], int student_count)
{
    int highest = 0;

    for (int i = 0; i < student_count; i++)
    {
        printf("Student ID is : %d\n", p[i]->id);
        printf("Student NAME is: %s\n", p[i]->name);
        printf("---------------\n");
        int count = p[i]->sub_count;
        for(int m =0; m<count; m++)
        {
            printf("Student Subject %d name is: %s\n",m+1, p[i]->sp[m]->name);
            printf("Student Score in subject number %d is: %d\n", m+1,p[i]->sp[m]->score);
            printf("Student Grade in subject number %d is: %c\n", m+1,p[i]->sp[m]->status);
            printf("---------------\n");
        }
        printf("---------------\n");
        int scoure_sun =0;
        for(int m=0; m<p[i]->sub_count; m++)
        {
            scoure_sun += p[i]->sp[m]->score;
        }
        SetColor(6);
        printf("the avrage of this student is : %d\n",scoure_sun/p[i]->sub_count);

        if(scoure_sun/p[i]->sub_count>highest)
        {
            highest = scoure_sun/p[i]->sub_count;
        }
        if(scoure_sun/p[i]->sub_count > 59)
        {
            printf("STATUS : PASS\n");
        }
        else
        {
            printf("STATUS : FAIL\n");

        }
        scoure_sun=0;
        SetColor(5);
        printf("================================================================================\n");
        SetColor(4);
    }
    SetColor(11);

    for(int i = 0; i < student_count; i++)
    {
        int scoure_sun =0;
        for(int m=0; m < p[i]->sub_count; m++)
        {
            scoure_sun += p[i]->sp[m]->score;
        }
        if(scoure_sun/p[i]->sub_count == highest)
        {
            printf("THE STUDENT WITH THE HIGHEST AVG SCORE is: '%s' and his id is '%d'\n",p[i]->name,p[i]->id);
            printf("WITH AVG SCORE OF : %d\n",scoure_sun/p[i]->sub_count);
        }
        printf("================================================================================\n");

        scoure_sun =0;
    }
    SetColor(4);

}


void display_pass_studs(struct student *p[], int student_count)
{


    for (int i = 0; i < student_count; i++)
    {
        int scoure_sun =0;
        for(int m=0; m<p[i]->sub_count; m++)
        {
            scoure_sun += p[i]->sp[m]->score;
        }
        if(scoure_sun/p[i]->sub_count > 59)
        {
            printf("Student ID is : %d\n", p[i]->id);
            printf("Student NAME is: %s\n", p[i]->name);
            printf("---------------\n");
            for(int m =0; m<p[i]->sub_count; m++)
            {
                printf("Student Subject %d name is: %s\n",m+1, p[i]->sp[m]->name);
                printf("Student Score in subject number %d is: %d\n", m+1,p[i]->sp[m]->score);
                printf("Student Grade in subject number %d is: %c\n", m+1,p[i]->sp[m]->status);
            }
            printf("---------------\n");
            printf("---------------\n");
            SetColor(6);
            printf("the avrage of this student is : %d\n",scoure_sun/p[i]->sub_count);
            scoure_sun=0;
            SetColor(5);
            printf("================================================================================\n");
            SetColor(4);
        }
        scoure_sun = 0;

    }
}

void display_failed_studs(struct student *p[], int student_count)
{

    for (int i = 0; i < student_count; i++)
    {
        int scoure_sun =0;
        for(int m=0; m<p[i]->sub_count; m++)
        {
            scoure_sun += p[i]->sp[m]->score;
        }
        if(scoure_sun/p[i]->sub_count< 60)
        {
            printf("Student ID is : %d\n", p[i]->id);
            printf("Student NAME is: %s\n", p[i]->name);
            printf("---------------\n");
            for(int m =0; m<p[i]->sub_count; m++)
            {
                printf("Student Subject %d name is: %s\n",m+1, p[i]->sp[m]->name);
                printf("Student Score in subject number %d is: %d\n", m+1,p[i]->sp[m]->score);
                printf("Student Grade in subject number %d is: %c\n", m+1,p[i]->sp[m]->status);
            }
            printf("---------------\n");
            printf("---------------\n");
            SetColor(6);
            printf("the avrage of this student is : %d\n",scoure_sun/p[i]->sub_count);
            scoure_sun=0;
            SetColor(5);
            printf("================================================================================\n");
            SetColor(4);

        }
        scoure_sun = 0;

    }

}


void display_stud(struct student *p)
{

    printf("Student ID is : %d\n", p->id);
    printf("Student NAME is: %s\n", p->name);
    printf("---------------\n");
    int count = p->sub_count;
    for(int m =0; m<count; m++)
    {
        printf("Student Subject %d name is: %s\n",m+1, p->sp[m]->name);
        printf("Student Score in subject number %d is: %d\n", m+1,p->sp[m]->score);
        printf("Student Grade in subject number %d is: %c\n", m+1,p->sp[m]->status);
        printf("---------------\n");
    }
    printf("---------------\n");
    int scoure_sun = 0;
    for(int m=0; m<p->sub_count; m++)
    {
        scoure_sun += p->sp[m]->score;
    }
    SetColor(6);
    printf("the avrage of this student is : %d\n",scoure_sun/p->sub_count);
    if(scoure_sun/p->sub_count > 60)
    {
        printf("STATUS : PASS\n");
    }
    else
    {
        printf("STATUS : FAIL\n");

    }
    SetColor(5);
    scoure_sun=0;
    printf("================================================================================\n");
    SetColor(4);


}


void Editstudentloyee(struct student *p)
{

    for(int i=0; i<p->sub_count; i++)
    {

        printf("Please enter the new number(from above)of subject  %d:",i+1);

        int sub_num;
        scanf("%d", &sub_num);
        switch(sub_num)
        {
        case 10:
            strcpy(p->sp[i]->name, "SQL");
            break;
        case 9:
            strcpy(p->sp[i]->name, ".NET");
            break;
        case 8:
            strcpy(p->sp[i]->name, "NODE.JS");
            break;
        case 7:
            strcpy(p->sp[i]->name, "REACT.JS");
            break;
        case 6:
            strcpy(p->sp[i]->name, "PHP");
            break;
        case 5:
            strcpy(p->sp[i]->name, "HTML");
            break;
        case 4:
            strcpy(p->sp[i]->name, "C++");
            break;
        case 3:
            strcpy(p->sp[i]->name, "OOP");
            break;
        case 2:
            strcpy(p->sp[i]->name, "JS");
            break;
        case 1:
            strcpy(p->sp[i]->name, "XML");
            break;
        default:
            printf("know number or answer");
            break;
        }
        printf("Please enter the new score of subject %d: ",i+1);
        scanf("%d", &p->sp[i]->score);

        switch (p->sp[i]->score / 10)
        {
        case 10:
        case 9:
            p->sp[i]->status = 'A';
            break;
        case 8:
            p->sp[i]->status = 'B';
            break;
        case 7:
            p->sp[i]->status = 'C';
            break;
        case 6:
            p->sp[i]->status = 'D';
            break;
        default:
            p->sp[i]->status = 'F';
            break;
        }

    }



};

COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void esc_menu_error_id()
{
    system("cls");

    gotoxy(0,11);
    SetColor(5);

    printf("this id is taken pls enter a diffrent id");

    SetColor(4);
    gotoxy(0,15);
    printf("press esc to return to the menu");
    int key;
    while(1)
    {
        key = getch();

        if((key >= 0 && key <= 240))
        {
            if (key == 27)
            {
                system("cls");
                break;
            }
        }
    }


}

void esc_menu()
{
    system("cls");
    gotoxy(0,10);
    SetColor(5);
    printf("you have added a new stundent succ");
    SetColor(4);
    gotoxy(0,15);
    printf("press esc to return to the menu");
    int key;
    while(1)
    {
        key = getch();

        if((key >= 0 && key <= 240))
        {
            if (key == 27)
            {
                system("cls");
                break;
            }
        }
    }

}
void esc_menu_edit()
{
    system("cls");
    gotoxy(0,10);
    SetColor(5);
    printf("this user dosn't exist");
    SetColor(4);
    gotoxy(0,15);
    printf("press esc to return to the menu");
    int key;
    while(1)
    {
        key = getch();

        if((key >= 0 && key <= 240))
        {
            if (key == 27)
            {
                system("cls");
                break;
            }
        }
    }

}

void display_menu()
{
    SetColor(4);
    printf("press esc to return to the perv menu");
    int key;
    while(1)
    {
        key = getch();

        if((key >= 0 && key <= 240))
        {
            if (key == 27)
            {
                system("cls");
                break;
            }
        }
    }
}

struct student** expand(struct student** oldArray[], int oldSize)
{
    struct student** newArray = (struct student**)malloc((oldSize*2) * sizeof(struct student*));

    for (size_t i = 0; i < oldSize; i++)
    {
        newArray[i] = oldArray[i];
    }


    free(oldArray);

    return newArray;
}


int main()
{
    system("COLOR F0");
    char menu[6][30] = {"EDIT STUDENT","NEW STUDENT ","DISPLAY ALL","DISPLAY ONE STUDENT", "SHOW PASSED STUDENTS", "SHOW FAILED STUDENTS" };
    int where=0;
    int key;
    struct student **P = malloc(100 * sizeof(struct student*));
    int pointers_count =1;
    int student_count = 0;




    while(1)
    {
        if(student_count == pointers_count)
        {
            P = expand(P,pointers_count);
            pointers_count = pointers_count*2;
        }
        for( int i=0; i<6; i++)
        {
            gotoxy(50,3+i);

            if(i==where)
            {
                SetColor(4);

            }
            else
            {
                SetColor(10);
            }
            printf("%s\n",menu[i]);

        }

        key = getch();

        if((key >= 0 && key <= 240))
        {

            if(key==72)
            {
                where--;

            }
            else if(key == 80)
            {
                where++;

            }
            if(key==13)
            {
                if(where == 1)
                {
                    system("cls");
                    show_subj();
                    gotoxy(0,10);
                    SetColor(4);

                    printf("enter you student id number :");
                    int student_id;
                    scanf("%d",&student_id);
                    if(student_count>0)
                    {
                        for(int m=0; m<student_count; m++)
                        {
                            if(student_id == P[m]->id)
                            {
                                esc_menu_error_id();
                                break;
                            }
                            else
                            {
                                P[student_count] = add_stundent(student_id);
                                student_count++;
                                esc_menu();
                                break;
                            }
                        }

                    }
                    else
                    {
                        P[student_count] = add_stundent(student_id);
                        student_count++;
                        esc_menu();
                    }
                }
                else if(where == 2)
                {
                    gotoxy(1,10);
                    if(student_count==0)
                    {
                        gotoxy(1,10);
                        printf("no student to display");
                    }
                    else
                    {

                        system("cls");
                        gotoxy(0,10);
                        SetColor(4);
                        display_all_stud(P,student_count);
                        display_menu();
                    }
                }
                else if(where == 0)
                {
                    gotoxy(1,10);
                    system("cls");
                    if(student_count==0)
                    {
                        gotoxy(1,10);
                        printf("no student to edit");
                    }
                    else
                    {
                        gotoxy(0,10);
                        SetColor(4);
                        printf("enter you student id number :");
                        int student_id;
                        scanf("%d",&student_id);
                        for(int m=0; m<student_count; m++)
                        {
                            if(student_id == P[m]->id)
                            {
                                show_subj();
                                Editstudentloyee(P[m]);
                                system("cls");
                                break;
                            }
                            else
                            {
                                esc_menu_edit();
                            }
                        }

                    }
                }
                else if(where == 3)
                {
                    gotoxy(1,10);
                    system("cls");
                    if(student_count==0)
                    {
                        gotoxy(1,10);
                        printf("no student to display");
                    }
                    else
                    {
                        gotoxy(0,15);

                        printf("enter you student id number :");
                        int student_id;
                        scanf("%d",&student_id);
                        for(int m=0; m<student_count; m++)
                        {
                            if(student_id == P[m]->id)
                            {
                                system("cls");
                                gotoxy(0,10);
                                SetColor(4);
                                display_stud(P[m]);
                                display_menu();
                                break;
                            }
                            else
                            {
                                printf("this student dosn't exists");


                            }
                        }

                    }
                }
                else if(where == 4)
                {
                    gotoxy(1,10);
                    if(student_count==0)
                    {
                        gotoxy(1,10);
                        printf("no student to display");
                    }
                    else
                    {

                        system("cls");
                        gotoxy(0,10);
                        SetColor(4);
                        display_pass_studs(P,student_count);
                        display_menu();
                    }
                }
                else if(where == 5)
                {
                    gotoxy(1,10);
                    if(student_count==0)
                    {
                        gotoxy(1,10);
                        printf("no student to display");
                    }
                    else
                    {

                        system("cls");
                        gotoxy(0,10);
                        SetColor(4);
                        display_failed_studs(P,student_count);
                        display_menu();
                    }
                }

            }
        }

        if(where>5)
        {
            where=0;
        }
        else if(where<0)
        {
            where=5;
        }
    }
}


