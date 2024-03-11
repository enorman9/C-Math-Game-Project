#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{

    std:: cout<< "\n\n~ Welcome Agent.\n";
    std:: cout<< "~ For this mission we will need you to infiltrate a level " <<Difficulty;
    std:: cout<< " server base...To proceed, we will need you to enter the correct three digits.\n\n";
   
}
    

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
// This is my first game. Please, go easy on me :3

    // Declare 3 number code. These are const int because, these are the ANSWERS
    const int CodeAlpha = rand() % Difficulty + Difficulty;
    const int CodeBeta  =  rand() % Difficulty + Difficulty;
    const int CodeDelta = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeAlpha + CodeBeta + CodeDelta;
    const int CodeProduct = CodeAlpha * CodeBeta * CodeDelta;

    /* Here I shall post
    a multi-line comment.
    HaHa this is quite fun eh?
    */ 

    //Present or print CodeSum and CodeProduct to the terminal
    std:: cout<< std:: endl;
    std:: cout<< "\n~ There are 3 numbers in the code...\n"; 
    std:: cout<< "~ The codes add-up to: " << CodeSum << std:: endl;
    std:: cout<< "~ The codes multiply to give: " << CodeProduct << std:: endl;

    //store player guess
    int GuessA, GuessB, GuessC;
    std:: cin >> GuessA >> GuessB >> GuessC;

    // We declare GuessSum and initialize it by adding and multiplying the variables together
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
     std:: cout<< "\n~ Excellent job, Agent. Another file extracted. Keep Going.\n";
     return true;
    }
    else
    {
    std:: cout<< "\n ** You entered the wrong code Agent! Try again. **\n";
    
    return false;
    }
    
}

int main()
{
    srand(time(NULL)); //Creates new random sequence based on the time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop will continue until all game levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); //Discards any buffer
        if (bLevelComplete)
        {
           //Increase level difficulty here
        ++LevelDifficulty; 
        }
        
    }

    std:: cout << "\nGreat stuff out there today Agent. Come back next time for more Virtual Missions!\n";

    return 0;
}