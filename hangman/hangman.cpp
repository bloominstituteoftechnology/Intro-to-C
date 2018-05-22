# include <cstring>
# include <iostream>
# include <fstream>
# include <vector>
# include <conio.h>
# include <ctime>
# include <iomanip>
# include <stdlib.h>
# include <windows.h>
using namespace std;
void mainMenu(int&);  //functions
void hangMan(int);
void mainTitle();
void loose();
void win();
void categories(int &);
void instruct();
void gamePlay(string, int);
void cntrsToVector(vector<string>&, string &);
void frtsToVector(vector<string>&, string &);
void jobsToVector(vector<string>&, string &);
void displayAlphabet(char []);
int main ()
{   char guess, tryAgain;
    int check, choice, choice2,i=0, error;
    string word, secretWord;
    vector <string> data;
    
    mainTitle();
    cout<<"\n\n\n\t\t\t\tPress Any Key";
    getch();
    do{ 
    
    system("cls");
    mainMenu(choice);              //main menu choices
    system("cls");  
    switch(choice) 
    {
       case 1:                     //new game
            categories(choice2); 
            error=0;
            switch(choice2)      
              {case 1: //fruits and veggies
                   do  {
                       frtsToVector(data, secretWord);//get secret word from a list
                        
                        gamePlay(secretWord,choice2 );
                       cin>>tryAgain;
                       tryAgain=toupper(tryAgain);
                       } while(tryAgain=='Y');
                        break;
              case 2:  //countries
                   do  {    
                       cntrsToVector(data, secretWord);
                       gamePlay(secretWord, choice2);
                       cin>>tryAgain;
                       tryAgain=toupper(tryAgain);
                       } while(tryAgain=='Y');
                       break;
              case 3:  //occupations
                   do  {    
                       jobsToVector(data, secretWord);
                       gamePlay(secretWord, choice2);
                       cin>>tryAgain;
                       tryAgain=toupper(tryAgain);
                       } while(tryAgain=='Y');
                       break;
              case 4:
                       cout<<"\nBack to Main Menu\nPress any key";
                       getch();
                       break;
              }     
          break;
       case 2: { //Instructions
            instruct(); 
            getch();
            break;}
       case 3:{ //Quit
            cout<<"\nQuitting";
            break;}
       default: cout<<"Invalid Input";     
     }
}while(choice!=3);
   
  
cout<<"\n\n";
system("pause");
return 0;
}
 
  
  void mainMenu(int &x)
  { 
       cout<<"\n\n\n"
           <<"\t\t\t\t******************\n"
           <<"\t\t\t\t*  HANGMAN GAME  *\n" 
           <<"\t\t\t\t******************\n"
           <<"\n\n"
           <<"\t\t\t\t1. NEW GAME\n"
           <<"\t\t\t\t2. INSTRUCTIONS\n"
           <<"\t\t\t\t3. QUIT\n";
       cout<<"\nEnter: ";
       cin>>x;
       while((x<1) ||(x>3))
       {                
       cout<<"\nInvalid Input. Enter Again: ";
       cin>>x;
       }
       
   }
   
   void hangMan(int x)  //picture of hangman
   {   system ("color 5F"); 
      cout<<"\n\n\n"; 
      cout<<"\t\t\t      _______\n"
          <<"\t\t\t    |/      |\n";
          switch(x)
          {
             case 0:           //no errors
      cout<<"\t\t\t    |      \n"
          <<"\t\t\t    |      \n"
          <<"\t\t\t    |      \n"
          <<"\t\t\t    |      \n";
                break;
             case 1:           // 1 error
      cout<<"\t\t\t    |      (_)\n"
          <<"\t\t\t    |      \n"
          <<"\t\t\t    |      \n"
          <<"\t\t\t    |      \n";
                break;
             case 2:          // 2 errors
      cout<<"\t\t\t    |      (_)\n"
          <<"\t\t\t    |       |\n"
          <<"\t\t\t    |       |\n"
          <<"\t\t\t    |      \n";
                break;
             case 3:          // 3 errors
      cout<<"\t\t\t    |      (_)\n"
          <<"\t\t\t    |      \\|\n"
          <<"\t\t\t    |       |\n"
          <<"\t\t\t    |      \n";
                break;
             case 4:          // 4 errors
      cout<<"\t\t\t    |      (_)\n"
          <<"\t\t\t    |      \\|/\n"
          <<"\t\t\t    |       |\n"
          <<"\t\t\t    |      \n";
                break;
             case 5:          // 5 errors
      cout<<"\t\t\t    |      (_)\n"
          <<"\t\t\t    |      \\|/\n"
          <<"\t\t\t    |       |\n"
          <<"\t\t\t    |      / \n";
                break;
             case 6:          // 6 errors
      cout<<"\t\t\t    |      (_)\n"
          <<"\t\t\t    |      \\|/\n"
          <<"\t\t\t    |       |\n"
          <<"\t\t\t    |      / \\\n";
                break;       // if 7 errors - then the player lose
          }
      cout<<"\t\t\t    |\n"
          <<"\t\t\t   _|___\n";
      cout<<"\n\n\n\n";

    }
    
  
    
    void loose() //if player lose
    {
        cout<<"\n\n\n";  
        cout<<"\t\t\t        _______\n"
            <<"\t\t\t       /       \\\n"
            <<"\t\t\t      |   YOU   |\n"
            <<"\t\t\t      |  LOSE!  |\n"
            <<"\t\t\t    __|_________|__\n"
            <<"\t\t\t   |__ TRY AGAIN?__|\n";
	   cout<<"\nENTER Y/N: ";
     }
     
     void win()  //if player won
     {
          cout<<"\n\n\n"
              <<"\t\t\tCONGRATULATIONS\n\n"
              <<"\t\t\tYOU WON!\n\n"
              <<"\t\t\t      _______\n"
              <<"\t\t\t    |/ \n"
              <<"\t\t\t    | \n"
              <<"\t\t\t    |       _\n"
              <<"\t\t\t    |      (_)\n"
              <<"\t\t\t    |      \\|/ \n"
              <<"\t\t\t    |       | \n"
              <<"\t\t\t   _|___   / \\ \n"
              <<"\nWOULD YOU LIKE TO PLAY AGAIN?\n"
              <<"ENTER Y/N: ";
       }
      
    void categories(int &y) 
    {
          cout<<"\n\n\n"
           <<"\t\t\t\t********************\n"
           <<"\t\t\t\t*  CHOOSE CATEGORY  *\n" 
           <<"\t\t\t\t********************\n"
           <<"\n\n"
           <<"\t\t\t\t1. FRUITS AND VEGGIES\n"
           <<"\t\t\t\t2. COUNTRIES\n"
           <<"\t\t\t\t3. OCCUPATIONS\n"
           <<"\t\t\t\t4. BACK TO MAIN MENU\n";
       cout<<"\nEnter: ";
       cin>>y;
       while((y<1) ||(y>4))
       {                
       cout<<"\nInvalid Input. Enter Again: ";
       cin>>y;
       }
     } 
     
void instruct()
{
    cout<<"\n\n\n\n\t\t\t\tINSTRUCTIONS"
                <<"\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
                <<"\n\t* How To Play: Player tries to guess a letter. If that letter *"
                <<"\n\t* is in  the  word then  the letter will be  displayed  in it *"
                <<"\n\t* everywhere it would appear, and that letter will be crossed *"
                <<"\n\t* out in the  alphabet. If the letter is not in the word then *"
                <<"\n\t* a body part will be added to the gallows  (head, body, left *"
                <<"\n\t* arm, right arm, left leg, right leg). Player  will continue *"
                <<"\n\t* guessing letters until he/she can either solve  the word or *"
                <<"\n\t* all six body parts are on the gallows. The player has total *"
                <<"\n\t* of 7 guesses to play, otherwise he/she loose                 *"
                <<"\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";  
   cout<<"\n\nPress any key to continue";

 }  
 
 void cntrsToVector(vector<string>&x, string &word) //load words and get random word from a list
 {    x.clear();
      ifstream file1("countries.txt");
      if (file1.is_open())
        {
          while ( !file1.eof())
          {
                file1 >> word;
                x.push_back(word);
        
                
          }  } else 
                  cout<<"\nCouldn't load the library";   
                  
                   srand( time(0));
                  int random=rand()%x.size()+1;
                   word=x[random];
               file1.close();    
  }   
  
  void frtsToVector(vector<string>&x, string &word) //load words and get random word from a list
 {    x.clear();
      ifstream file1("fruits.txt");
      if (file1.is_open())
        {
          while ( !file1.eof())
          {
                file1 >> word;
                x.push_back(word);
        
                
          }  } else 
                   cout<<"\nCouldn't load the library";   
          
                   srand( time(0));
                  int random=rand()%x.size()+1;
                   word=x[random];
               file1.close();
                  
  }   
  
  void jobsToVector(vector<string>&x, string &word) //load words and get random word from a list
 {    x.clear();
      ifstream file1("occupations.txt");
      if (file1.is_open())
        {
          while ( !file1.eof())
          {
                file1 >> word;
                x.push_back(word);
        
                
          }  } else cout<<"\nCouldn't load the library";   
                  
                   srand( time(0));
                  int random=rand()%x.size()+1;
                   word=x[random];
               file1.close();    
  }   
  
  void gamePlay(string word, int num)// main function to check letters, display hangman
  {    
       char alphabet[27]={0,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
       int error = 0,totalGuess=7, guessed=0; 
       int length=word.length();
       char hiddenWord[length],copyWord[length];
       
       for(int k=0; k<length; k++)
       {
       hiddenWord[k]='?';  //populate hidden word with ? for length of word
       copyWord[k]=word[k]; //copy secret word in string to character array
        }
        
       while(guessed<length && error<7) {  //check if no more than 7 errors of all letters are guessed
       system("cls");
       cout<<"\n\tCategory: ";
       if(num==1) cout<<"FRUITS AND VEGGIES";
       else if(num==2) cout<<"COUNTRIES";
       else cout<<"OCCUPATIONS";
       cout<<"\n\n\n\t\t\t\t";
        for(int k=0; k<length; k++)
       cout<<hiddenWord[k]<<" ";   //display hidden word
       hangMan(error);             //run function hangman to display picture according to number of errors
       displayAlphabet(alphabet);  //print out alphabet
       cout<<"\n\nYou have "<<totalGuess-error<<" guess/es left!"; //calculate how many guesses player can make before loose
                 
       char guess;
    int check=1;
    int check2=1;
      do
    {
    label1:  //if the same letter choosen again, go back here
    cout<<"\n\nEnter your guess letter: ";
    cin>>guess;
    guess=toupper(guess);
    for(int j=0; j<27; j++)//take out guessed letters
    if(alphabet[j]==guess)
    {alphabet[j]=' ';
    check=0;
    for(int h=0; h<length; h++) //if letter is guessed, then copy it to hidden word
    if(guess==copyWord[h])
    {hiddenWord[h]=copyWord[h];//guess;
    guessed++;
    check2++;
    }
     }
    if(check!=0) { //if letter were choosen more than 1
                 cout<<"\nYou used that letter already! Try again\n";
                 goto label1;
                 }
    if(check2==1)//count how many errors player made
    {error++;
    
    }
}while(check==1);

            if(check==1)//if it is error, then display 
            {
            cout<<"\nNo letter "<<guess<<" in the word";
            }
       
       }
       system("cls");
       cout<<"\n\n\n\t\t\tThe hidden word was "<<word;//after finishing game, display hidden word
       if(error==7)    //if loose, display loose function       
       loose();
       if(guessed==length)  //if win, then display congratulations           
       win();
         
     }
     

    void displayAlphabet(char alpha[])//print out content of alphabet
    {
     for(int i=1; i<27; i++)
     cout<<alpha[i]<<" ";
     }  

void mainTitle()         //main title
{    system ("color 5F"); 
cout<<"\n\n\n\n"
    <<"\t __    __  ______  __    __  ______  __       __  ______  __    __ \n"
    <<"\t/  |  /  |/      \\/  \\  /  |/      \\/  \\     /  |/      \\/  \\  /  |\n"
    <<"\t$$ |  $$ /$$$$$$  $$  \\ $$ /$$$$$$  $$  \\   /$$ /$$$$$$  $$  \\ $$ |\n"
    <<"\t$$ |__$$ $$ |__$$ $$$  \\$$ $$ | _$$/$$$  \\ /$$$ $$ |__$$ $$$  \\$$ |\n"
    <<"\t$$    $$ $$    $$ $$$$  $$ $$ |/    $$$$  /$$$$ $$    $$ $$$$  $$ |\n"
    <<"\t$$$$$$$$ $$$$$$$$ $$ $$ $$ $$ |$$$$ $$ $$ $$/$$ $$$$$$$$ $$ $$ $$ |\n"
    <<"\t$$ |  $$ $$ |  $$ $$ |$$$$ $$ \\__$$ $$ |$$$/ $$ $$ |  $$ $$ |$$$$ |\n"
    <<"\t$$ |  $$ $$ |  $$ $$ | $$$ $$    $$/$$ | $/  $$ $$ |  $$ $$ | $$$ |\n"
    <<"\t$$/   $$/$$/   $$/$$/   $$/ $$$$$$/ $$/      $$/$$/   $$/$$/   $$/ \n\n";
 }
