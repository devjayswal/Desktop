#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include "windows.h"
using namespace std;
void gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;


}
class applicant{
    string name;
    int age;
    string address;
    int m_sal;
    int h_loan;
    int p_loan;
    int no_chq_bounce;
    char own_house;
    char spouse_workig;
    char dependent_parents;
    int company_tier;
    public:
    void get_data();
    int calc_liability();
    void display_score();
};

void applicant::get_data(){
    system("cls");
    cout<<"name of aplicant: ";
    getline(cin, name);
    cout<<"age: ";
    cin>>age;
    cin.clear();
    cin.ignore(1000, '\n');
    cout<<"address: ";
    getline(cin,address);
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"monthly salary is :- ";
    cin>>m_sal;
    cout<<"total home loan EMI:  ";
    cin>>h_loan;
    cout<<"total personal loan EMI: ";
    cin>>p_loan;
    cout<<"number of cheque bonus in last six month:- ";
    cin>>no_chq_bounce;
    cout<<"own house? (y or n ):  ";
    cin>>own_house;
    cout<<"spouse working ?(y or n ) ; ";
    cin>>spouse_workig;
    cout<<"dependent parents? (y or n)  ";
    cin>>dependent_parents;
    cout<<"company tier? (1 ,2 or 3):  ";
    cin>>company_tier;

}

//function for calculating credit
int applicant:: calc_liability(){
    int score=0;
    if(age>22&&age<=30)
    {score=score+2;}
    else if(age>30&&age<=35){score=score+1;}
    else{score=score-1;};

    int liability=h_loan+p_loan;
    if(liability<=m_sal/4)
    {score=score+5;}
    if(liability>m_sal/4&& liability<=m_sal/3)
    {score=score+3;}
    if(liability>m_sal/3 &&liability<=m_sal/2)
    {score=score+1;}
    if(liability>m_sal/2)
    {score=score-1;}
    if(no_chq_bounce>1)
     score=score-2; 
    if(no_chq_bounce==1)
     score=score-1;
    if(no_chq_bounce==0)
     score=score+1;
     if(p_loan>h_loan)
     score=score-1;
     else{score=score+1;}
     if(own_house=='y')
     score=score+1;
     if(spouse_workig=='y')
     score=score+1;
     if(dependent_parents=='y'){}
     else{score=score+1;}
     if(company_tier==1)
     score=score+3;
     if(company_tier==2)
      score=score+2;
    else{score=score+1;}
    return(score) ;
}
   void applicant::display_score(){
    int sc=calc_liability();
    system("cls");
    if(sc>9){cout<<"the applicant"<<name<<" is at low risk. \n credit score "
    <<sc<<"\ncredit can be given. ";}
    else{
        if(sc>5&&sc<=9){cout<<"the applicant"<<name<<"is at average risk \n credit score " <<sc<<"\n credit can be given with due precaution.";}
        else{cout<<"the applicant "<<name<<"is at high risk. \n credit score is "<<sc<<"\ncredit can not given. ";}}


getch();   }


//main funtion is on there he ehhe h e hhehe 
int main(){
    char flag='f';
    applicant a;
    char ch;
    while(1){system("cls");
    gotoxy(31,8);
    cout<<"credit calculator";
    gotoxy(31,9);
    cout<<"________________";
    gotoxy(22,12);
    cout<<"1  - enter laon applicant's details ";
    gotoxy(22,13);
    cout<<"2  -display credit score";
    gotoxy(22,14);
    cout<<"3  - exit";
    cout<<"salect an option by typing the number code:";
    ch=getch();
    switch(ch)
    {
        case('1'):{a.get_data();
        flag='t';
        break;}

        case('2'):{if(flag=='f'){
            gotoxy(22,18);
            cout<<"loan applicant's details not yet entered! press any key to continue......";
        getch();        }
        else{a.display_score();
        break;}
        case('3'):{exit(1);
        break;}
        default:{gotoxy(22,18);
        cout<<"invalid choice! press any key o continue......";
        getch();}}
    }
    
    }
}
