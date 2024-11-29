#include "FEHLCD.h"
#include "FEHUtility.h"
#include "Text.h"
#include <string>
#include "FEHImages.h"
#include <math.h>
using namespace std;

void mainMenu(class Stats *, class Stats *);
void statsMenu(class Stats *, class Stats *);
void creditsMenu(class Stats *, class Stats *);
void themeMenu(class Stats *, class Stats *);
void instructionsMenu(class Stats *, class Stats *);
void theme(int choice, FEHImage , FEHImage , FEHImage );
void tugOfWarDisplay(int , int );
void displayQues(class Questions *); 
//this takes who answered first and if they answered correct/wrong, and calls the tugOfWarDisplay() method to move the character appropriately. This will repeatedly call the tugOfWarDisplay() for every pixel, so it looks like it is moving, until it moves the number of pixels it needs to
//this must take the Player1 or Player2 object, so it can update cAnswers / wAnswers accordingly 
//void moveTugOfWar(class Stats *, bool );
//this takes the coordinates of where the sprite of the characters should end up

void checkAns(class Stats *, class Stats *, int );
int doStatsStuff(class Stats *, class Stats *, int , float , int, int );

int choice = 3;

class Questions{
    public:
    string question;
    string a1;
    string a2;
    string a3;
    string a4;
    int correctIndex;
    
    //constructor
    Questions(string ques = "Question 1", string ans1 = "Ans 1", string ans2 = "Ans 2", string ans3 = "Ans 3", string ans4 = "Ans 4", int correct = 0){
        question = ques;
        a1 = ans1;
        a2 = ans2;
        a3 = ans3;
        a4 = ans4;
        correctIndex = correct;
    }
};

class Stats{
    public:
    int cAnswers;
    int wAnswers;
    float avgTime;
    float howMany;
    float totTime;

    //constructor
    Stats(){
        cAnswers = 0;
        wAnswers = 0;
        avgTime = 0;
        howMany = 0;
        totTime = 0;
    }
};

int main() {
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();
    Questions questionBank[6];

    //initalize stats
    class Stats Player1;
    class Stats Player2;

    //question bank FEH
    //index starts at 0, so correct answer 3 is index 2
    class Questions fehQ1("What is the first index of an array?", "1", "2", "0", "i", 2);
    class Questions fehQ2("What is Paul Clingans middle name?", "Arthur", "Andrew", "Anthony", "Alan", 3);
    class Questions fehQ3("What is the standard output in C++?", "stdout", "stdin", "out", "sout", 0);
    class Questions fehQ4("What is the most asked question in Hitchcock 216 at 12:40pm?", "What are we learning today?", "What is for breakfast?", "When is the APP due?", "How much progress have you made on your mulch pile?", 1);
    class Questions fehQ5("What is a pointer in C?", "The address of another variable", "A variable that has as it value the address of another variable", "A variable that has its address as its value", "* and &", 1);
    class Questions fehQ6("What is the name of the simulator used in FEH?", "Proteus", "Prometheus", "Apollo", "Chronos", 0);
    Questions fehQuestions[6] = {fehQ1, fehQ2, fehQ3, fehQ4, fehQ5, fehQ6};

    //question bank Geography
    class Questions geoQ1("What is the only country that starts with an O?", "Oman", "Omaha", "Okayama", "Oslo", 0);
    class Questions geoQ2("What river is the longest in the world?", "The Amazon River", "The Mississippi River", "The Ob River", "The Nile River", 3);
    class Questions geoQ3("Which country has the longest coastline?", "Chile", "Canada", "Japan", "Russia", 1);
    class Questions geoQ4("What is the perimeter of the Vatican?", "1 mile", "3.2 kilometers", "4.6 miles", "15.3 kilometers", 1);
    class Questions geoQ5("What is the largest desert?", "Sahara desert", "Arabian desert", "Gobi desert", "Antarctic desert", 3);
    class Questions geoQ6("What do you call a piece of land that is surrounded by water on two sides?", "Peninsula", "Isthmus", "Cape", "Cove", 2);
    Questions geoQuestions[6] = {geoQ1, geoQ2, geoQ3, geoQ4, geoQ5, geoQ6};

    //question bank OSU
    class Questions osuQ1("What year was OSU founded?", "1864", "1892", "1902", "1870", 3);
    class Questions osuQ2("Who was the two-time Heisman trophy winner at Ohio State?", "Archie Griffin", "Woody Hayes", "Will Howard", "David Boston", 0);
    class Questions osuQ3("How many majors does OSU offer?", "Less than 100", "175-200", "More than 200", "100-150", 2);
    class Questions osuQ4("What is the nickname for the Ohio State football stadium?", "The Big House", "The Horseshoe", "The Woodshed", "The Flats", 1);
    class Questions osuQ5("What is the name of the OSU student-run newspaper?", "The Lantern", "The Chronicle", "Perspective", "Prospective", 0);
    class Questions osuQ6("What is the building that has a garden on top?", "Hitckcock Hall", "Orton Hall", "Knowlton Hall", "Hamilton Hall", 2);
    Questions osuQuestions[6] = {osuQ1, osuQ1, osuQ3, osuQ4, osuQ5, osuQ6};
    

    mainMenu(&Player1, &Player2);

    //creates and opens photos for use (backgrounds)
    FEHImage feh;
    feh.Open("FEH - SDP FEH Theme (1).png");
    FEHImage geo;
    geo.Open("FEH - SDP Geo Theme.png");
    FEHImage osu;
    osu.Open("FEH - SDP OSU Theme.png");


/* This was all testing for sprites and images. Remember to also get better backgrounds by using AI to generate these sprites. Can also create a game backgorund for the game
    FEHImage test;
        test.Open("New Piskel (6).png");
        LCD.SetBackgroundColor(WHITE);
        LCD.Clear();
        test.Draw(0, 0);
        
        FEHImage test2;
        test2.Open("New Piskel (7).png");
        test2.Draw(0, 0);

            LCD.WriteAt("Tug-o'-Triva", 85, 30);
            //test.Draw(0, 0);

*/

    
    while (1){
        theme(choice, feh, geo, osu);

        if (choice == 0){
            for (int i = 0; i < 6; i++){
                questionBank[i] = fehQuestions[i];
            }
        } else if (choice == 1){
            for (int i = 0; i < 6; i++){
                questionBank[i] = geoQuestions[i];
            }
        } else if (choice == 2){
            for (int i = 0; i < 6; i++){
                questionBank[i] = osuQuestions[i];
            }
        }

        int correctNum;
        for (int d = 0; d < 6; d++){
            correctNum = questionBank[0].correctIndex;
            displayQues(questionBank);
            checkAns(&Player1, &Player2, correctNum);
            LCD.Clear();
            theme(choice, feh, geo, osu);
        }
        statsMenu(&Player1, &Player2);
    }
    return 0;
}

void mainMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;
    
    //clear screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //added this and changed font color to black
    FEHImage back;
    back.Open("FEH - SDP Background Image (1).png");
    back.Draw(0, 0);
    back.Close();

    //title
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Tug-o'-Triva", 85, 30);

    //set up rectangles, add text
    LCD.DrawRectangle(115, 60, 90, 25);
    LCD.WriteAt("Start", 130, 65);

    LCD.DrawRectangle(115, 90, 90, 25);
    LCD.WriteAt("Stats", 130, 95);

    LCD.DrawRectangle(115, 120, 90, 25);
    LCD.WriteAt("Credits", 118, 125);

    LCD.DrawRectangle(85, 150, 150, 25);
    LCD.WriteAt("Instructions", 86, 155);

    //wait for touch
    while(!LCD.Touch(&x,&y)){}

    //buttons!
    if (x >= 115 && x <= 205 && y >= 60 && y <= 85){
        LCD.Clear();
        themeMenu(Player1, Player2);
    } else if(x >= 115 && x <= 205 && y >= 90 && y <= 115){
        LCD.Clear();
        statsMenu(Player1, Player2);
    } else if(x >= 115 && x <= 205 && y >= 120 && y <= 145){
        LCD.Clear();
        creditsMenu(Player1, Player2);
    } else if(x >= 85 && x <= 235 && y >= 150 && y <= 175) {
        LCD.Clear();
        instructionsMenu(Player1, Player2);
    } else {
        //this calls function again to ensure player can misclick and not break game
        mainMenu(Player1, Player2);
    }
}

void themeMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;
    class Text smallFont;
    //clear screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //added this and changed font color to black
    FEHImage back;
    back.Open("FEH - SDP Background Image (1).png");
    back.Draw(0, 0);
    back.Close();

    //title
    LCD.SetFontColor(BLACK);

    LCD.WriteAt("Tug-o'-Triva", 85, 30);
    smallFont.display("Choose Your Theme", 0xffffff, 110, 50);

    //set up rectangles, add text
    LCD.DrawRectangle(20, 90, 90, 25);
    LCD.WriteAt("FEH", 45, 95);

    LCD.DrawRectangle(115, 90, 90, 25);
    smallFont.display("Geography", 0xffffff, 133, 98);

    LCD.DrawRectangle(210, 90, 90, 25);
    LCD.WriteAt("OSU", 235, 95);

    LCD.DrawRectangle(115, 175, 90, 25);
    LCD.WriteAt("Menu", 135, 180);

    

    //wait for touch
    while(!LCD.Touch(&x,&y)){}

    //check if buttons pressed
    //FEH theme
    if (x >= 20 && x <= 110 && y >= 90 && y <= 115){
        LCD.Clear();
        choice = 0;
    //Geography theme
    } else if(x >= 115 && x <= 205 && y >= 90 && y <= 115){
        LCD.Clear();
        choice = 1;
    //OSU theme
    } else if(x >= 210 && x <= 300 && y >= 90 && y <= 115){
        LCD.Clear();
        choice = 2;
    } else if(x >= 115 && x <= 205 && y >= 180 && y <= 200){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //this calls function again to ensure player can misclick and not break game
        themeMenu(Player1, Player2);
    }

}

void creditsMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;
    class Text smallFont;

    //clear page
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //actual credits
    LCD.WriteAt("Tug-o'-Triva", 85, 30);
    LCD.WriteAt("Coded by:", 70, 70);
    LCD.WriteAt("Harsha Kalivarapu", 70, 90);
    LCD.WriteAt("Clayton Oldham", 70, 110);
    smallFont.display("Small Font library provided by Junhao Liu.11305", 0xffffff, 25, 135);

    //menu button
    LCD.DrawRectangle(115, 175, 90, 25);
    LCD.WriteAt("Menu", 135, 180);

    //wait for touch
    while(!LCD.Touch(&x,&y)){}

    //check if touching button
    if (x >= 115 && x <= 205 && y >= 180 && y <= 200){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //if not touching button call this function again so misclicks can happen
        creditsMenu(Player1, Player2);
    }
}

void instructionsMenu(class Stats *Player1, class Stats *Player2){

    //variables for touch
    int x, y;

    //clear page
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //title
    LCD.WriteAt("Tug-o'-Triva", 85, 30);

    //instructions
    class Text smallFont;
    smallFont.display("This is a two player-game. Each player will be ", 0xffffff, 0, 50);
    smallFont.display("assigned as Player 1 (P1) or Player 2 (P2). Each ", 0xffffff, 0, 59);
    smallFont.display("player will also have a designated person in the tug-", 0xffffff, 0, 68);
    smallFont.display("of-war game (P1 is orange, P2 is blue). The goal of ", 0xffffff, 0, 77);
    smallFont.display("the game is to pull the opposite player to the center", 0xffffff, 0, 86);
    smallFont.display("", 0xffffff, 0, 95);
    smallFont.display("To pull the opposite player, you must answer trivia ", 0xffffff, 0, 104);
    smallFont.display("questions. A question and answwer options will be ", 0xffffff, 0, 113);
    smallFont.display("displayed. The first player to answer the question ", 0xffffff, 0, 122);
    smallFont.display("will be considered. If the player answers right, ", 0xffffff, 0, 131);
    smallFont.display("the opposite player's character will be moved a few", 0xffffff, 0, 140);
    smallFont.display("spaces towards the center. If the player answers ", 0xffffff, 0, 149);
    smallFont.display("wrong, then their player will be moved a few spaces ", 0xffffff, 0, 158);
    smallFont.display("toward the center. Questions will be asked until one ", 0xffffff, 0, 167);
    smallFont.display("player's character reaches the center. ", 0xffffff, 0, 176);
    smallFont.display("", 0xffffff, 0, 185);
    smallFont.display("Double click on the screen to interact with buttons.", 0xffffff, 0, 194);

    //menu button
    LCD.DrawRectangle(115, 210, 90, 25);
    LCD.WriteAt("Menu", 135, 215);

    //waiting for touch
    while(!LCD.Touch(&x,&y)){}

    //check if touching button
    if (x >= 115 && x <= 205 && y >= 210 && y <= 235){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //if not touching button call this function again so misclicks can happen
        instructionsMenu(Player1, Player2);
    }
}

void statsMenu(class Stats *Player1, class Stats *Player2){
    //declare small font
    class Text smallFont;
    
    //variables for touch
    int x, y;
    
    //clear screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //title
    LCD.WriteAt("Tug-o'-Triva", 85, 30);

    //player 1 stats
    LCD.WriteAt("Player 1:", 0, 50);
    smallFont.display("Correct Answer:", 0xffffff, 2, 73);
    LCD.WriteAt(Player1->cAnswers, 93, 70);

    smallFont.display("Incorect Answer:", 0xffffff, 1, 93);
    LCD.WriteAt(Player1->wAnswers, 93, 90);

    smallFont.display("Average Time:", 0xffffff, 2, 113);
    LCD.WriteAt(Player1->avgTime, 93, 110);

    //player 2 stats
    LCD.WriteAt("Player 2:", 166, 50);
    smallFont.display("Correct Answer:", 0xffffff, 168, 73);
    LCD.WriteAt(Player2->cAnswers, 259, 70);

    smallFont.display("Incorect Answer:", 0xffffff, 167, 93);
    LCD.WriteAt(Player2->wAnswers, 259, 90);

    smallFont.display("Average Time:", 0xffffff, 168, 113);
    LCD.WriteAt(Player2->avgTime, 259, 110);

    //menu button
    LCD.DrawRectangle(115, 175, 90, 25);
    LCD.WriteAt("Menu", 135, 180);

    //waiting for touch
    while(!LCD.Touch(&x,&y)){}

    //check if touching button
    if (x >= 115 && x <= 205 && y >= 175 && y <= 200){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //if not touching button call this function again so misclicks can happen
        statsMenu(Player1, Player2);
    }
}

void theme(int choice, FEHImage feh, FEHImage geo, FEHImage osu) {
    if (choice == 0) {
        feh.Draw(0, 0);
    }
    else if (choice == 1) {
        geo.Draw(0, 0);
    }
    else if (choice == 2) {
        osu.Draw(0, 0);
    }
}

void tugOfWarDisplay(int xCoor, int yCoor, FEHImage towDisplay) {
    towDisplay.Draw(xCoor, yCoor);
}

void displayQues(class Questions *questionBank){
    class Text smallFont;

    //get question and answers
    string ques = (*questionBank).question;
    string ans1 = (*questionBank).a1;
    string ans2 = (*questionBank).a2;
    string ans3 = (*questionBank).a3;
    string ans4 = (*questionBank).a4;

    //create strings for each part of ques/ans
    string quesPart;
    string ans1Part;
    string ans2Part;
    string ans3Part;
    string ans4Part;

    //get length of string
    int quesLength = ques.length(); 
    int ans1Length = ans1.length(); 
    int ans2Length = ans2.length(); 
    int ans3Length = ans3.length(); 
    int ans4Length = ans4.length(); 

    int i = 0;
    int k = 70;
    int j;
    int d;

    //allows multiple lines to be displayed from one string
    while (quesLength > 0){

        //add background box so text pops
        LCD.SetFontColor(BLACK);
        LCD.FillRectangle(67, k-1, 183, 10);

        //get 30 characters of question string, display
        quesPart = ques.substr(i, 30);
        smallFont.display(quesPart, 0xffffff, 70, k);

        //increment each variable accordingly
        i = i + 30;
        k = k + 10;
        quesLength = quesLength - 30;
    }

    i = 0;
    k = 100;
    j = 1;

    while (ans1Length > 0){
        //add background box so text pops
        LCD.SetFontColor(BLACK);
        LCD.FillRectangle(52, k-1, 215, 10);

        //add symbol before first line
        //rest of line are normal
        if (j == 1){
            FEHImage circle;
            circle.Open("FEH - circle.png");
            circle.Draw(55,k);
            circle.Close();
            d = 7;
            j = 0;

            //get 34 characters of question string, display
            //accounts for the extra character thats used on line 1
            ans1Part = ans1.substr(i, 34);
            smallFont.display(ans1Part, 0xffffff, 55 + d, k);
            i = i + 34;
            ans1Length = ans1Length - 34;
        } else {
            //get 35 characters of question string, display
            ans1Part = ans1.substr(i, 35);
            smallFont.display(ans1Part, 0xffffff, 55, k);
            i = i + 35;
            ans1Length = ans1Length - 35;
        }

        //increment each variable accordingly
        k = k + 10;
        d = 0;
    }

    i = 0;
    k = 130;
    j = 1;

    while (ans2Length > 0){
        //add background box so text pops
        LCD.SetFontColor(BLACK);
        LCD.FillRectangle(52, k-1, 215, 10);

        //add symbol before first line
        //rest of line are normal
        if (j == 1){
            FEHImage square;
            square.Open("FEH - square.png");
            square.Draw(55,k);
            square.Close();
            d = 7;
            j = 0;

            //get 34 characters of question string, display
            //accounts for the extra character thats used on line 1
            ans2Part = ans2.substr(i, 34);
            smallFont.display(ans2Part, 0xffffff, 55 + d, k);
            i = i + 34;
            ans2Length = ans2Length - 34;
        } else {
            //get 35 characters of question string, display
            ans2Part = ans2.substr(i, 35);
            smallFont.display(ans2Part, 0xffffff, 55, k);
            i = i + 35;
            ans2Length = ans2Length - 35;
        }

        //increment each variable accordingly
        k = k + 10;
        d = 0;
    }

    i = 0;
    k = 160;
    j = 1;

     while (ans3Length > 0){
        //add background box so text pops
        LCD.SetFontColor(BLACK);
        LCD.FillRectangle(52, k-1, 215, 10);

        //add symbol before first line
        //rest of line are normal
        if (j == 1){
            FEHImage triangle;
            triangle.Open("FEH - triangle.png");
            triangle.Draw(55,k);
            triangle.Close();
            d = 7;
            j = 0;

            //get 34 characters of question string, display
            //accounts for the extra character thats used on line 1
            ans3Part = ans3.substr(i, 34);
            smallFont.display(ans3Part, 0xffffff, 55 + d, k);
            i = i + 34;
            ans3Length = ans3Length - 34;
        } else {
            //get 35 characters of question string, display
            ans3Part = ans3.substr(i, 35);
            smallFont.display(ans3Part, 0xffffff, 55, k);
            i = i + 35;
            ans3Length = ans3Length - 35;
        }

        //increment each variable accordingly
        k = k + 10;
        d = 0;
    }

    i = 0;
    k = 190;
    j = 1;

    while (ans4Length > 0){
        //add background box so text pops
        LCD.SetFontColor(BLACK);
        LCD.FillRectangle(52, k-1, 215, 10);

        //add symbol before first line
        //rest of line are normal
        if (j == 1){
            FEHImage diamond;
            diamond.Open("FEH - diamond.png");
            diamond.Draw(55,k);
            diamond.Close();
            d = 7;
            j = 0;

            //get 34 characters of question string, display
            //accounts for the extra character thats used on line 1
            ans4Part = ans4.substr(i, 34);
            smallFont.display(ans4Part, 0xffffff, 55 + d, k);
            i = i + 34;
            ans4Length = ans4Length - 34;
        } else {
            //get 35 characters of question string, display
            ans4Part = ans4.substr(i, 35);
            smallFont.display(ans4Part, 0xffffff, 55, k);
            i = i + 35;
            ans4Length = ans4Length - 35;
        }

        //increment each variable accordingly
        k = k + 10;
        d = 0;
    }

    //display answer buttons


    //move question to back of array
    class Questions temp;
    temp = questionBank[0];
    questionBank[0] = questionBank[1];
    questionBank[1] = questionBank[2];
    questionBank[2] = questionBank[3];
    questionBank[3] = questionBank[4];
    questionBank[4] = questionBank[5];
    questionBank[5] = temp;
}

void checkAns(class Stats *Player1, class Stats *Player2, int correctNum){
    int x, y;
    class Text smallFont;
    float timeAns, time;
    //will be 1 for correct, 0 for incorrect
    int correct;
    string who;
    //allow for click to finish registering, has stroke otherwise
    Sleep(0.1);
    timeAns = TimeNow();
    //check for touch
    while(!LCD.Touch(&x,&y)){}
    time = TimeNow() - timeAns;
     if (x >= 0 && x <= 50 && y >= 60 && y <= 100){
        //Player 1 button 1
        who = "Player 1";
       correct = doStatsStuff(Player1, Player2, 1, time, correctNum, correct);
        //add 3 more

     } else if (x >= 280 && x <= 320 && y >= 60 && y <= 100) { 
        //player 2 buttons
        who = "Player 2";
       correct = doStatsStuff(Player1, Player2, 2, time, correctNum, correct);
        //add 3
     } else {
        //if not touching button call this function again so misclicks can happen
        checkAns(Player1, Player2, correctNum);
     }

    //if correct, screen green, else screen red
    if (correct == 1){
        LCD.SetFontColor(GREEN);
        LCD.FillRectangle(0, 69, 320, 171);
        smallFont.display(who + " Answered Correctly", 0xffffff, 80, 100);
    } else {
        LCD.SetFontColor(RED);
        LCD.FillRectangle(0, 69, 320, 171);
        smallFont.display(who + " Answered Incorrectly", 0xffffff, 70, 100);
    }
    Sleep(1.5);

}

int doStatsStuff(class Stats *Player1, class Stats *Player2, int player, float time, int correctNum, int correct){
    float temp, timeAvg, howMuch;
    if (player == 1){
        //check wether correct or not
        if(correctNum == 0){
            correct = 1;
            Player1->cAnswers += 1;
            
        } else {
            correct = 0;
            Player1->wAnswers += 1;
        }
        //calculate average time to answer
        temp = Player1->totTime;
        Player1->howMany += 1.0;
        howMuch = Player1->howMany;
        timeAvg = (time + temp) / howMuch;
        Player1->avgTime = timeAvg;
        Player1->totTime += time;
    } else {
        //check whether correct or not
        if(correctNum == 0){
            correct = 1;
            Player2->cAnswers += 1;
            
        } else {
            correct = 0;
            Player2->wAnswers += 1;
        }
        //calculate average time to answer
        temp = Player2->totTime;
        Player2->howMany += 1.0;
        howMuch = Player2->howMany;
        timeAvg = (time + temp) / howMuch;
        Player2->avgTime = timeAvg;
        Player2->totTime += time;
    }
    return correct;
}
