#include<iostream>
#include <stdlib.h>
using namespace std;
int total_score_user=0;
int total_score_computer=0;
char userChoice(){
char choice;
cout<<"Welcome to Rock/Paper/Scissors Game! Here are your choices.\n";
cout<<"(R/r)  Rock\n(P/p)  Paper\n(S/s)  Scissors\n";
cin>>choice;
if(choice!='R' && choice!='r' && choice!='P' && choice!='p' && choice!='S' && choice!='s'){
    cout<<"Invalid Choice.Please try again!!\n";
    userChoice();
}
return choice;
}
char computerChoice(){
/*
Here rand will generate number from 0 to RAND_MAX
but we modulo it to get number in range 1-3
*/
int randchoice=((rand()%3)+1);
char choice;
switch(randchoice){
case 1:
    choice='R';
    break;
case 2:
    choice='P';
    break;
case 3:
    choice='S';
    break;
}
return choice;
}
void determineWinner(char usrchoice,char compchoice){
//Rock v\s scissors Rock wins
if((usrchoice=='R' || usrchoice=='r') && (compchoice=='S' || compchoice=='s')){
        cout<<"User wins\n";
        return;
}
else if((usrchoice=='S' || usrchoice=='s') && (compchoice=='P' || compchoice=='p')){
    cout<<"Computer wins\n";
    return;
}
//scissors v\s paper scissors wins
else if((usrchoice=='S' || usrchoice=='s') && (compchoice=='P' || compchoice=='p')){
        cout<<"User wins\n";
        return;
}
else if((usrchoice=='P' || usrchoice=='p') && (compchoice=='S' || compchoice=='s')){
    cout<<"Computer wins\n";
    return;
}
//paper v\s rock paper wins
else if((usrchoice=='P' || usrchoice=='p') && (compchoice=='R' || compchoice=='r')){
    cout<<"User wins\n";
    return;
}
else if((usrchoice=='R' || usrchoice=='r') && (compchoice=='P' || compchoice=='p')){
    cout<<"Computer wins\n";
    return;
}
//Both have same choice game draws
else if(usrchoice==compchoice){
    cout<<"There is no winner.Game draw\n";
    return;
}
}
bool playagain(){
bool b;
char ch;
cout<<"Do you want to play again (Y/y) for yes (N/n) for no)?";
cin>>ch;

if(ch=='Y' || ch=='y')
    b=true;
else if(ch=='N' || ch=='n')
    b=false;
 else{ 
     cout<<"Invalid Option.Please try again!!!\n";
     b=playagain();
 }
  return b;
}
void showChoices(char usrchoice,char cmpchoice){
string usr,cmp;
//user choice
    if(usrchoice=='R'){
        usr="Rock";
    }
    else if(usrchoice=='P'){
        usr="Paper";
    }
    else{
        usr="Scissors";
    }
    //computer choice
    if(cmpchoice=='R'){
        cmp="Rock";
    }
    else if(cmpchoice=='P'){
        cmp="Paper";
    }
    else{
        cmp="Scissors";
    }
    cout<<"Your choice: "<<usr<<endl;
    cout<<"Computer Choice: "<<cmp<<endl;
}
int main(){
while(true){
    char usrchoice=userChoice();
    char compchoice=computerChoice();
    showChoices(usrchoice,compchoice);
    determineWinner(usrchoice,compchoice);
    bool b=playagain();
    // In case b is true we play again else we terminate
    if(b)
        continue;
    else{
        cout<<"Thank you for Playing Rock/Paper/Scissors\n";
        break;
    }
}
cout << "Total wins of Computer:" << total_score_computer << endl;
cout << "Total wins of user:" << total_score_user << endl;

}
