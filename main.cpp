#include "FEHLCD.h"
#include "FEHUtility.h"
#include "Text.h"
#include <string>
#include "FEHImages.h"
#include <math.h>
using namespace std;

//prototypes for all methods. Explanation of all methods are above the method header
void mainMenu(class Stats *, class Stats *);
void statsMenu(class Stats *, class Stats *);
void creditsMenu(class Stats *, class Stats *);
void themeMenu(class Stats *, class Stats *);
void instructionsMenu(class Stats *, class Stats *);
void theme(FEHImage , FEHImage , FEHImage );
void tugOfWarDisplay(int *, int *);
void displayQues(class Questions *); 
void moveTOW(string , int , int *, int *);
void analyzeAns(class Stats *, class Stats *, int , int *, int *);
int doStatsStuff(class Stats *, class Stats *, int , float , int, int, int );
void celebrateMenu(int *, int *, class Stats *, class Stats *);
void countdownMenu(int *, int *, FEHImage , FEHImage , FEHImage );

//created global variable to keep track of what theme the user selects
int choice = 3;

//template for Questions class. An instance of this class represents one question
class Questions{
    public:
    string question;
    string a1;
    string a2;
    string a3;
    string a4;
    //this number is the index of the option that is correct, where index 0 represents the FIRST OPTION
    //ex: if correctIndex = 2, then the third answer option is correct
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

//template for Stats class. An instance of this class represents the stats for one player
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
    //Sets background to black / clears screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //initializes questionBank array. Will hold the questions that relate to theme selected by user
    Questions questionBank[8];

    /*creates instance of Stats class called Player1. Represents stats for Player 1
    *   
    *   public :
    *       int cAnswers;
    *       int wAnswers;
    *       float avgTime;
    *       float howMany;
    *       float totTime;
    * 
    *       Stats() {
    *           cAnswers = 0;
    *           wAnswers = 0;
    *           avgTime = 0;
    *           howMany = 0;
    *           totTime = 0;
    *       }      
    */
    class Stats Player1;

    /*creates instance of Stats class called Player2. Represents stats for Player 2
    *   
    *   public :
    *       int cAnswers;
    *       int wAnswers;
    *       float avgTime;
    *       float howMany;
    *       float totTime;
    * 
    *       Stats() {
    *           cAnswers = 0;
    *           wAnswers = 0;
    *           avgTime = 0;
    *           howMany = 0;
    *           totTime = 0;
    *       }      
    */
    class Stats Player2;

    
    
    /*each question is an instance of Questions class and are given names (like fehQX, geoQX, osuQX).
    * Each instance represents a question in each theme. 
    * NOTE: Only listing private/public attributes once for simplicity; this applies to all questions created
    *   
    *       public:
    *           string question;
    *           string a1;
    *           string a2;
    *           string a3;
    *           string a4;
    *           //this number is the index of the option that is correct, where index 0 represents the FIRST OPTION
    *           //ex: if correctIndex = 2, then the third answer option is correct
    *           int correctIndex;
    *
    *       Questions(string ques = "Question 1", string ans1 = "Ans 1", string ans2 = "Ans 2", string ans3 = "Ans 3", string ans4 = "Ans 4", int correct = 0){
    *           question = ques;
    *           a1 = ans1;
    *           a2 = ans2;
    *           a3 = ans3;
    *           a4 = ans4;
    *           correctIndex = correct;
    *       }    
    */
    //Questions for FEH Theme. Questions are stored in fehQuestions array of Questions type
    class Questions fehQ1("What is the first index of an array?", "1", "2", "0", "i", 2);
    class Questions fehQ2("What is Paul Clingans middle name?", "Arthur", "Andrew", "Anthony", "Alan", 3);
    class Questions fehQ3("What is the standard output in C++?", "stdout", "stdin", "out", "sout", 0);
    class Questions fehQ4("What is the most asked question in Hitchcock 216 at 12:40pm?", "What are we learning today?", "What is for breakfast?", "When is the APP due?", "How much progress have you made on your mulch pile?", 1);
    class Questions fehQ5("What is a pointer in C?", "The address of another variable", "A variable that has as it value the address of another variable", "A variable that has its address as its value", "* and &", 1);
    class Questions fehQ6("What is the name of the simulator used in FEH?", "Proteus", "Prometheus", "Apollo", "Chronos", 0);
    class Questions fehQ7("How many labs are there?", "9", "5", "12", "11", 3);
    class Questions fehQ8("How many times did we have guest speakers this year in FEH?", "0", "3", "2", "5", 2);
    Questions fehQuestions[8] = {fehQ1, fehQ2, fehQ3, fehQ4, fehQ5, fehQ6, fehQ7, fehQ8};

    //Questions for Geograph Theme. Questions are stored in geoQuestions array of Questions type
    class Questions geoQ1("What is the only country that starts with an O?", "Oman", "Omaha", "Okayama", "Oslo", 0);
    class Questions geoQ2("What river is the longest in the world?", "The Amazon River", "The Mississippi River", "The Ob River", "The Nile River", 3);
    class Questions geoQ3("Which country has the longest coastline?", "Chile", "Canada", "Japan", "Russia", 1);
    class Questions geoQ4("What is the perimeter of the Vatican?", "1 mile", "3.2 kilometers", "4.6 miles", "15.3 kilometers", 1);
    class Questions geoQ5("What is the largest desert?", "Sahara desert", "Arabian desert", "Gobi desert", "Antarctic desert", 3);
    class Questions geoQ6("What do you call a piece of land that is surrounded by water on two sides?", "Peninsula", "Isthmus", "Cape", "Cove", 2);
    class Questions geoQ7("What of the following countries has a non-rectangular flag?", "Switzerland", "Chad", "Sudan", "Norway", 0);
    class Questions geoQ8("What is the capital of Australia?", "Brisbaine", "Sydney", "Canberra", "Melbourne", 2);
    Questions geoQuestions[8] = {geoQ1, geoQ2, geoQ3, geoQ4, geoQ5, geoQ6, geoQ7, geoQ8};

    //Questions for OSU Theme. Questions are stored in osuQuestions array of Questions type
    class Questions osuQ1("What year was OSU founded?", "1864", "1892", "1902", "1870", 3);
    class Questions osuQ2("Who was the two-time Heisman trophy winner at Ohio State?", "Archie Griffin", "Woody Hayes", "Will Howard", "David Boston", 0);
    class Questions osuQ3("How many majors does OSU offer?", "Less than 100", "175-200", "More than 200", "100-150", 2);
    class Questions osuQ4("What is the nickname for the Ohio State football stadium?", "The Big House", "The Horseshoe", "The Woodshed", "The Flats", 1);
    class Questions osuQ5("What is the name of the OSU student-run newspaper?", "The Lantern", "The Chronicle", "Perspective", "Prospective", 0);
    class Questions osuQ6("What is the building that has a garden on top?", "Hitckcock Hall", "Orton Hall", "Knowlton Hall", "Hamilton Hall", 2);
    class Questions osuQ7("How many years are you required to live on campus?", "None", "2 years", "1.5 years", "1 year", 1);
    class Questions osuQ8("Which of the following is not a Traditions Dining Hall?", "Scott", "Morrill", "Kennedy", "Lincoln", 3);
    Questions osuQuestions[8] = {osuQ1, osuQ2, osuQ3, osuQ4, osuQ5, osuQ6, osuQ7, osuQ8};
    

    //calls mainMenu method to begin the game
    mainMenu(&Player1, &Player2);

    //creates and opens backgrounds for all three themes
    FEHImage feh;
    feh.Open("FEH - SDP FEH Theme.png");
    FEHImage geo;
    geo.Open("FEH - SDP Geo Theme.png");
    FEHImage osu;
    osu.Open("FEH - SDP OSU Theme.png");
    
    
    //rest of the game occurs here
    while (1){
        //this is x and y coordinates of tug of war characters initialized to 0
        int currentPosX = 0;
        int currentPosY = 0;

        //after user selects theme choice (occurs when mainMenu method was called), questionBank is 
        //given the questions for that theme
        if (choice == 0){
            for (int i = 0; i < 8; i++){
                questionBank[i] = fehQuestions[i];
            }
        } else if (choice == 1){
            for (int i = 0; i < 8; i++){
                questionBank[i] = geoQuestions[i];
            }
        } else if (choice == 2){
            for (int i = 0; i < 8; i++){
                questionBank[i] = osuQuestions[i];
            }
        }

        //declares variable to store correct option for the question that is displayed
        int correctNum;
        //while loop allows game to run until one of the tug of war players pull the opponent 
        //close enough to the center (this is marked by markers/dots on the rope)
        while (currentPosX < 30 && currentPosX > -30) {
            //calls countdownMenu to let players know quesiton is about to appear
            countdownMenu(&currentPosX, &currentPosY, feh, geo, osu);
            //sets correctNum to correctIndex of the question being displayed on screen
            correctNum = questionBank[0].correctIndex;
            //displays question, answer choices, and buttons to select an answer
            displayQues(questionBank);
            //waits for player 1 or 2 to answer, and analyzes answer (explained above the method header)
            analyzeAns(&Player1, &Player2, correctNum, &currentPosX, &currentPosY);
            //clears screen and redisplays theme and tug of war display
            LCD.Clear();
            theme(feh, geo, osu);
            tugOfWarDisplay(&currentPosX, &currentPosY);
        }
        //once a player wins (pulls opponent close enough to center), calls celebration menu
        celebrateMenu(&currentPosX, &currentPosY, &Player1, &Player2);
    }
    return 0;
}

/*
*(Clayton created) This method sets up the main menu page for the user to toggle / continue into the game
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (sent from main menu)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (sent from main menu)
*/
void mainMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;
    
    //clear screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //displays the game's general background
    FEHImage back;
    back.Open("FEH - SDP Background Image (1).png");
    back.Draw(0, 0);
    back.Close();

    //writes title
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Tug-o'-Trivia", 85, 30);

    //set up button options for user (Start, Stats, Credits, Instructions)
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(115, 60, 90, 25);
    LCD.WriteAt("Start", 130, 65);

    LCD.DrawRectangle(115, 90, 90, 25);
    LCD.WriteAt("Stats", 130, 95);

    LCD.DrawRectangle(115, 120, 90, 25);
    LCD.WriteAt("Credits", 118, 125);

    LCD.DrawRectangle(85, 150, 150, 25);
    LCD.WriteAt("Instructions", 86, 155);

    //wait for user to click a button
    while(!LCD.Touch(&x,&y)){}

    //takes user touch input and sends them to respective menu
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

/*
*(Clayton created) Sets up the theme menu page when the user clicks "Theme" in the
* main menu. Allows user to select theme / level and type of questions
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (sent from main menu)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (sent from main menu)
*/
void themeMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;

    //creates instance of Text header file to write smaller font 
    //(credits to Junhao Lin for small font library)
    class Text smallFont;

    //clear screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //displays the game's general background
    FEHImage back;
    back.Open("FEH - SDP Background Image (1).png");
    back.Draw(0, 0);
    back.Close();

    //writes title
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Tug-o'-Trivia", 85, 30);
    smallFont.display("Choose Your Theme", 0xffffff, 110, 50);

    //set up button options for user (FEH, Geography, OSU)
    LCD.DrawRectangle(20, 90, 90, 25);
    LCD.WriteAt("FEH", 45, 95);

    LCD.DrawRectangle(115, 90, 90, 25);
    smallFont.display("Geography", 0xffffff, 133, 98);

    LCD.DrawRectangle(210, 90, 90, 25);
    LCD.WriteAt("OSU", 235, 95);

    LCD.DrawRectangle(115, 175, 90, 25);
    LCD.WriteAt("Menu", 135, 180);

    
    //wait for user to select a button
    while(!LCD.Touch(&x,&y)){}

    //takes user touch input and sets theme of the game
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

/*
*(Clayton created) Sets up the credits menu page when the user clicks "Credits" in the
* main menu. Allows user to see who created / helped to create the program
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (sent from main menu)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (sent from main menu)
*/
void creditsMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;

    //creates instance of Text file to write smaller font 
    class Text smallFont;

    //clears page
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //lists credits
    LCD.WriteAt("Tug-o'-Trivia", 85, 30);
    LCD.WriteAt("Coded by:", 70, 70);
    LCD.WriteAt("Harsha Kalivarapu", 70, 90);
    LCD.WriteAt("Clayton Oldham", 70, 110);
    smallFont.display("Small Font library provided by Junhao Liu.11305", 0xffffff, 25, 135);

    //set up button options for user (Menu)
    LCD.DrawRectangle(115, 175, 90, 25);
    LCD.WriteAt("Menu", 135, 180);

    //wait for user to select a button
    while(!LCD.Touch(&x,&y)){}

    //takes user touch input and sends them to respective menu
    if (x >= 115 && x <= 205 && y >= 180 && y <= 200){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //this calls function again to ensure player can misclick and not break game
        creditsMenu(Player1, Player2);
    }
}

/*
*(Harsha created) Sets up the instructions menu page when the user clicks "Instructions" in the
* main menu. Allows user to view steps to play the game
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (sent from main menu)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (sent from main menu)
*/
void instructionsMenu(class Stats *Player1, class Stats *Player2){
    //variables for touch
    int x, y;

    //clear page
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //writes title
    LCD.WriteAt("Tug-o'-Trivia", 85, 30);

    //lists instructions for the game by creating instance of Text class for small font
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

    //set up button options for user (Menu)
    LCD.DrawRectangle(115, 210, 90, 25);
    LCD.WriteAt("Menu", 135, 215);

    //wait for user to select a button
    while(!LCD.Touch(&x,&y)){}

    //takes user touch input and sends them to respective menu
    if (x >= 115 && x <= 205 && y >= 210 && y <= 235){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //this calls function again to ensure player can misclick and not break game
        instructionsMenu(Player1, Player2);
    }
}

/*
*(Clayton created) Sets up the stats menu page when the user clicks "Stats" in the
* main menu. Allows user to view statistics of Player 1 and 2
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (sent from main menu)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (sent from main menu)
*/
void statsMenu(class Stats *Player1, class Stats *Player2){
    //creates instance of Text header file to write smaller font 
    class Text smallFont;
    
    //variables for touch
    int x, y;
    
    //clear screen
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //writes title
    LCD.WriteAt("Tug-o'-Trivia", 85, 30);

    //lists player 1's stats
    LCD.WriteAt("Player 1:", 0, 50);
    smallFont.display("Correct Answer:", 0xffffff, 2, 73);
    LCD.WriteAt(Player1->cAnswers, 93, 70);

    smallFont.display("Incorect Answer:", 0xffffff, 1, 93);
    LCD.WriteAt(Player1->wAnswers, 93, 90);

    smallFont.display("Average Time:", 0xffffff, 2, 113);
    LCD.WriteAt(Player1->avgTime, 93, 110);

    //lists player 2's stats
    LCD.WriteAt("Player 2:", 166, 50);
    smallFont.display("Correct Answer:", 0xffffff, 168, 73);
    LCD.WriteAt(Player2->cAnswers, 259, 70);

    smallFont.display("Incorect Answer:", 0xffffff, 167, 93);
    LCD.WriteAt(Player2->wAnswers, 259, 90);

    smallFont.display("Average Time:", 0xffffff, 168, 113);
    LCD.WriteAt(Player2->avgTime, 259, 110);

    //set up button options for user (Menu)
    LCD.DrawRectangle(115, 175, 90, 25);
    LCD.WriteAt("Menu", 135, 180);

    //wait for user to select a button
    while(!LCD.Touch(&x,&y)){}

    //takes user touch input and sends them to respective menu
    if (x >= 115 && x <= 205 && y >= 175 && y <= 200){
        //back to main menu
        mainMenu(Player1, Player2);
    } else {
        //this calls function again to ensure player can misclick and not break game
        statsMenu(Player1, Player2);
    }
}

/*
*(Harsha created) Sets game background to the theme selected by the user
*
*   param : FEHImage feh
*       This input holds object that contains background for feh theme
*   param : FEHImage geo
*       This input holds object that contains background for geography theme
*   param : FEHImage osu
*       This input holds object that contains background for osu theme
*/
void theme(FEHImage feh, FEHImage geo, FEHImage osu) {
    //uses global variable choice (which was set to user's theme of choice), and displays the 
    //background for that theme
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

/*
*(Harsha created) Displays who answered first AND if they are correct or wrong. Makes entire screen 
*green/red (based on correct or wrong answer) while maintaining tug of war display. Moves Tug of War 
* display with animation
*
*   param : string who
*       This input holds the player that answered first (comes from analyzeAns)
*   param : int correct
*       This input holds whether or not player answered correct (1) or wrong (0) (comes from analyzeAns)
*   param : int *currentPosX
*       This input holds the address of current X position of the tug of war character display
*   param : int *currentPosY
*       This input holds the address of current Y position of the tug of war character display
*/
void moveTOW(string who, int correct, int *currentPosX, int *currentPosY) {
    LCD.Clear();

    //if player was correct, sets background to green, states who answered correctly, and moves tug of war characters five pixels in the player's direction
    if (correct == 1) {
        //sets background to green
        LCD.SetBackgroundColor(GREEN);
        LCD.Clear();

        //displays tug of war characters
        tugOfWarDisplay(currentPosX, currentPosY);

        //states who answered and that they were correct
        LCD.WriteAt(who, 110, 100);
        LCD.WriteAt("Answered Correctly!", 43, 130);
        Sleep(1.0);
        
        //draws an arrow pointing to tug of war character display (to tell them that it is changing)
        LCD.WriteAt("^", 153, 59);
        LCD.WriteAt("|", 153, 59);
        LCD.WriteAt("|", 153, 69);
        Sleep(0.8);

        //this part moves the tug of war display five pixels towards player who got it right
        if (who == "Player 1") {
            for (int i = 0; i < 5; i++) {
                (*currentPosX)--;
                tugOfWarDisplay(currentPosX, currentPosY);
                Sleep(0.15);
            }
        }
        else {
            for (int i = 0; i < 5; i++) {
                (*currentPosX)++;
                tugOfWarDisplay(currentPosX, currentPosY);
                Sleep(0.15);
            }
        }
    }
    else {
        //sets background to red
        LCD.SetBackgroundColor(RED);
        LCD.Clear();

        //displays tug of war characters
        tugOfWarDisplay(currentPosX, currentPosY);

        //states who answered and that they were wrong
        LCD.WriteAt(who, 110, 100);
        LCD.WriteAt("Answered Incorrectly!", 43, 130);
        Sleep(1.0);

        //draws an arrow pointing to tug of war character display (to tell them that it is changing)
        LCD.WriteAt("^", 153, 59);
        LCD.WriteAt("|", 153, 59);
        LCD.WriteAt("|", 153, 69);
        Sleep(0.8);

        //this part moves the tug of war display five pixels towards player who got it wrong
        if (who == "Player 1") {
            for (int i = 0; i < 5; i++) {
                (*currentPosX)++;
                tugOfWarDisplay(currentPosX, currentPosY);
                Sleep(0.15);
            }
        }
        else {
            for (int i = 0; i < 5; i++) {
                (*currentPosX)--;
                tugOfWarDisplay(currentPosX, currentPosY);
                Sleep(0.15);
            }
        }
    }
}

/*
*(Harsha created) Displays tug of war characters and outer box at the given coordinates
*
*   param : int *xCoor
*       This input holds x coordinate that tug of war character display should be placed in
*   param : int *yCoor
*       This input holds y coordinate that tug of war character display should be placed in
*/
void tugOfWarDisplay(int *xCoor, int *yCoor) {
    //creates instance of FEHImage called towBox. Represents the outer box around tug of war characters
    FEHImage towBox;
    towBox.Open("TOW Box.png");
    //draws outer box
    towBox.Draw(0, 0);

    //creates instance of FEHImage called towBox. Represents the tug of war characters
    FEHImage towChar;
    towChar.Open("TOW Characters.png");
    //draws characters at given coordinates
    towChar.Draw(*xCoor, *yCoor);
}

/*
*(Clayton created) Displays question and answer options, buttons to select an answer. Moves 
*question to back of array once displayed
*
*   param : class Questions *questionBank
*       This input holds the address to the question bank being used (premade based on theme selected by user)
*/
void displayQues(class Questions *questionBank){
    //creates instance of Text header file to write smaller font 
    class Text smallFont;

    //gets question and answers of first question in questionBank
    string ques = (*questionBank).question;
    string ans1 = (*questionBank).a1;
    string ans2 = (*questionBank).a2;
    string ans3 = (*questionBank).a3;
    string ans4 = (*questionBank).a4;

    //create strings for each part of ques/ans (needed to display the question in lines / proper format)
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

    //creates / variables to set width / height for each part of questions and answers
    int i = 0;
    int k = 70;
    int j;
    int d;

    //each while loop below allows multiple lines to be displayed from one string
    //this is for question
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

    //this is for answer 1
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

    //this is for answer 2
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

    //this is for answer 3
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

    //this is for answer 4
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
    FEHImage buttons;
    buttons.Open("Buttons Display.png");
    buttons.Draw(0, 0);


    //moves question to back of array
    class Questions temp;
    temp = questionBank[0];
    questionBank[0] = questionBank[1];
    questionBank[1] = questionBank[2];
    questionBank[2] = questionBank[3];
    questionBank[3] = questionBank[4];
    questionBank[4] = questionBank[5];
    questionBank[5] = questionBank[6];
    questionBank[6] = questionBank[7];
    questionBank[7] = temp;
}

/*
*(Harsha created) Checks and records the user selected option, who answered first, and time they took to answer. 
* Sends the selected option to doStatsStuff. Calls moveTOW to move tug of war display accordingly
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (needed for doStatsStuff method)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (needed for doStatsStuff method)
*   param : int correctNum
*       This input holds number / index of the correct option out of all four choices
*   param : int *currentPosX
*       This input holds the address of current X position of the tug of war character display (needed for moveTOW method)
*   param : int *currentPosY
*       This input holds the address of current Y position of the tug of war character display (needed for moveTOW method)
*/
void analyzeAns(class Stats *Player1, class Stats *Player2, int correctNum, int *currentPosX, int *currentPosY){
    //variables for touch
    int x, y;

    //creates instance of Text header file to write smaller font 
    class Text smallFont;

    //creates variables to store and find time it too to answer the question
    float timeAns, time;

    //option the user selected
    int option;

    //this will record if the option user put is correct/wrong with 1/0;
    int correct;

    //records who answered first
    string who;

    //allow for click to finish registering, program has issues otherwise
    Sleep(0.1);
    
    //begins recording time
    timeAns = TimeNow();

    //wait for user to select a button
    while(!LCD.Touch(&x,&y)){}

    //once there is a touch, stops time
    time = TimeNow() - timeAns;

    //sets who to which player and option to the option they selected based on location of user touch
    if (x >= 0 && x <= 40){
        //Player 1 button 1
        who = "Player 1";
        if (y >= 60 && y <= 100) {
            option = 0;
        }
        else if (y >= 101 && y <= 140) {
            option = 1;
        }
        else if (y >= 141 && y <= 180) {
            option = 2;
        }
        else if (y >= 181 && y <= 220) {
            option = 3;
        }
        //sends details to doStatsStuff
        correct = doStatsStuff(Player1, Player2, 1, time, correctNum, option, correct);
    } else if (x >= 279 && x <= 319) { 
        //player 2 buttons
        who = "Player 2";
        if (y >= 60 && y <= 100) {
            option = 0;
        }
        else if (y >= 101 && y <= 140) {
            option = 1;
        }
        else if (y >= 141 && y <= 180) {
            option = 2;
        }
        else if (y >= 181 && y <= 220) {
            option = 3;
        }
        //sends details to doStatsStuff
        correct = doStatsStuff(Player1, Player2, 2, time, correctNum, option, correct);
    } else {
        //if not touching button call this function again so misclicks can happen
        analyzeAns(Player1, Player2, correctNum, currentPosX, currentPosY);
    }
    //calls moveTOW to move tug of war display correctly
    moveTOW(who, correct, currentPosX, currentPosY);
}

/*
*(Clayton created) Checks if user selected option was correct or wrong. Updates the player's (who answered first) stats.
* Returns if answer was correct / wrong as an integer
*
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (needed for doStatsStuff method)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (needed for doStatsStuff method)
*   param : int player
*       This input holds value of which player answered first (1 for Player 1, 2 for Player 2) (sent from analyzeAns)
*   param : float time
*       This input holds the time it took for first player to answer (sent from analyzeAns)
*   param : int correctNum
*       This input holds number / index of the correct option out of all four choices (sent from analyzeAns)
*   param : int option
*       This input holds the option the user selected (sent from analyzeAns)
*   param : int correct
*       This input holds value of whether or not the user answered correct / wrong (this will be updated in this method)
*       (sent from analyzeAns)
*/
int doStatsStuff(class Stats *Player1, class Stats *Player2, int player, float time, int correctNum, int option, int correct){
    //variables to calculate average time to answer
    float temp, timeAvg, howMuch;
    
    //updates stats for player 1 or player 2
    if (player == 1){
        //check wether correct or not
        if(correctNum == option){
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
        if(correctNum == option){
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
    //returns whether or not the player that answered first answered correctly (1 for correct, 0 for wrong)
    return correct;
}

/*
*(Harsha created) Sets up the celebration menu once one of the players win the game. Allows user to go back to 
*main menu page to replay the game or do other activities (such as view instructions, credits, or stats)
*
*   param : int *currentPosX
*       This input holds the address of current X position of the tug of war character display
*   param : int *currentPosY
*       This input holds the address of current Y position of the tug of war character display
*   param : class Stats *Player1
*       This input holds the address of the Player1 object (needed for mainMenu method)
*   param : class Stats *Player2
*       This input holds the address of the Player2 object (needed for mainMenu method)
*/
void celebrateMenu(int *currentPosX, int *currentPosY, class Stats *Player1, class Stats *Player2) {
    //variables for touch
    int x, y;

    //sets background for celebration menu
    LCD.Clear();
    FEHImage starBack;
    starBack.Open("Star Background.png");
    starBack.Draw(0, 0);

    //displays tug of war characters and outer box near center of screen (doesn't call tugOfWarDisplay method since the 
    //outer box won't be drawn at (0, 0))
    FEHImage towBox;
    towBox.Open("TOW Box.png");
    towBox.Draw(0, 60);

    FEHImage towChar;
    towChar.Open("TOW Characters.png");
    towChar.Draw(*currentPosX, (*currentPosY) + 60);

    //displays which player won. Sets up process to make the message blink (for effects)
    for (int i = 0; i < 4; i++) {
        LCD.SetFontColor(WHITE);

        if ((*currentPosX) == 30) {
            LCD.WriteAt("Player 2 Won!", 86, 140);
        }
        else {
            LCD.WriteAt("Player 1 Won!", 86, 140);
        }

        Sleep(0.4);

        LCD.SetFontColor(BLACK);
        LCD.FillRectangle(80, 130, 180, 30);

        Sleep(0.4);
    }

    //makes sure message appears after blinking of message is done
    LCD.SetFontColor(WHITE);
    if ((*currentPosX) == 30) {
        LCD.WriteAt("Player 2 Won!", 86, 140);
    }
    else {
        LCD.WriteAt("Player 1 Won!", 86, 140);
    }

    //set up button options for user (Menu)
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(115, 190, 90, 25);
    LCD.WriteAt("Menu", 135, 195);

    //wait for user to select a button
    while(!LCD.Touch(&x,&y)){}

    //takes user touch input and sends them to respective menu
    if (x >= 115 && x <= 205 && y >= 190 && y <= 215) {
        //back to main menu
        mainMenu(Player1, Player2);
    }
    else {
        //this calls function again to ensure player can misclick and not break game
        celebrateMenu(currentPosX, currentPosY, Player1, Player2);
    }
}

/*
*(Harsha created) Sets up the countdown menu page that will be played before every question. 
*
*   param : int *currentPosX
*       This input holds the address of current X position of the tug of war character display
*   param : int *currentPosY
*       This input holds the address of current Y position of the tug of war character display
*   param : FEHImage feh
*       This input holds object that contains background for feh theme (needed for theme method)
*   param : FEHImage geo
*       This input holds object that contains background for geography theme (needed for theme method)
*   param : FEHImage osu
*       This input holds object that contains background for osu theme (needed for theme method)
*/
void countdownMenu(int *currentPosX, int *currentPosY, FEHImage feh, FEHImage geo, FEHImage osu) {
    //sets up countdown menu. Makes the menu change color / alternate between certain color patter (for effect)
    for (int i = 3; i > 0; i--) {
        //sets background and font if countdown is currently at 3 or 1
        if (i % 2 != 0) {
            LCD.SetBackgroundColor(LIGHTGOLDENRODYELLOW);
            LCD.Clear();
            tugOfWarDisplay(currentPosX, currentPosY); 
            LCD.SetFontColor(OLIVE);
            LCD.WriteAt(i, 154, 110);
            Sleep(0.7);
            LCD.SetFontColor(LIGHTGOLDENRODYELLOW);
            LCD.FillRectangle(150, 105, 20, 20);
        }
        //sets background and font if countdown is currently at 2
        else {
            LCD.SetBackgroundColor(OLIVE);
            LCD.Clear();
            tugOfWarDisplay(currentPosX, currentPosY); 
            LCD.SetFontColor(LIGHTGOLDENRODYELLOW);
            LCD.WriteAt(i, 154, 110);
            Sleep(0.7);
            LCD.SetFontColor(OLIVE);
            LCD.FillRectangle(150, 105, 20, 20);
        }
    }

    //displays theme background and tug of war display after countdown
    theme(feh, geo, osu);
    tugOfWarDisplay(currentPosX, currentPosY);
}