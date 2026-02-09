//******************************************************************************
//Author : Evelyn Zuniga
// Assignment: GameStat Console App (Part 2)
//Description: This program debugged the part 1 program to ensure that only 
//             valid input is accepted, that everything is displayed correctly.
// *******************************************************************************

#include <iostream>
#include <string>

using namespace std;

 
int main() {
    // these are the variables used in the program
    int choice;
    bool keepRunning = true;
    string characterName;
    string characterClass;
    int classChoice;
    bool completedCharacter = false;
    
    double strength;
    double intelligence;
    double dexterity;
    double constitution; 
    int level = 0;
    
   double combatStats[4] = {0};
   string combatStatsNames[4] = {"Health Points", "Mana Points", "Attack Power", "Defense"};
    
    const int MAX_LEVEL = 10;
    const int MAX_STAT = 20;
    
    // Main menu loop
    do {
        // Display menu
        cout << "\n=== GAMESTAT CHARACTER MANAGER ===" << endl;
        cout << "1. Create New Character" << endl;
        cout << "2. View Character Stats" << endl;
        cout << "3. Calculate Combat Ratings" << endl;
        cout << "4. Level Up Character" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
         if (cin.fail()) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Please eneter valid choice(1-5): ";
            cin>>choice;
        }
        
        // Process menu choice
        switch (choice) {
            case 1:
                cout << "\n[Create Character]" << endl;
                
                cout << "Enter the name of your character: "; // allows user to enter name
                cin >> characterName;
                cout << endl; 
                
               
                cout << "Choose a Character Class: " << endl;
                cout << "1. Warrior" << endl;
                cout << "2. Mage" << endl;
                cout << "3. Rogue" << endl;
                cout << "4. Cleric" << endl;
                cout << "Enter your choice (1-4) : "; // allows user to enter a number to select a class
                cin >> classChoice;
                cout << endl;
                
                // while loop to ensure user enters a number between 1-4
                // numbers were used to be able to use switch
                while (cin.fail()|| classChoice < 1 || classChoice > 4) 
                    {
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Invalid Character Choice, please choose again." << endl;
                        
                        // getting new input
                        
                        cout << "Choose a Character Class: " << endl;
                        cout << "1. Warrior" << endl;
                        cout << "2. Mage" << endl;
                        cout << "3. Rogue" << endl;
                        cout << "4. Cleric" << endl;
                        cout << "Please enter a valid choice (1-4) : " << endl;
                        cin >> classChoice;
                        cout << endl;
                    }
                // corresponds the class choice number with a character class
                if (classChoice == 1)
                    characterClass = "Warrior";
                else if (classChoice == 2)
                    characterClass = "Mage";
                else if (classChoice == 3)
                    characterClass = "Rogue";
                else
                    characterClass = "Cleric";
                
                // getting the base stats
               
               cout << "Enter your character's Base Stats(1-20)" << endl;
               
               cout << "Enter Character Strength (1-20): " ;
               cin >> strength; 
               cout << endl;
               
               //ensures stats are between 1-20 and that non numeric input is entered
               if (strength < 1 || strength > 20 ) 
               {
                   cout << "Invalid Strength"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Strength";
                   cout << endl;
               }
                
                while (cin.fail() || strength < 1 || strength >20)
                {
                   cin.clear();
                   cin.ignore(200, '\n');
                   cout << "Please enter a valid character Strength (1-20): " ;
                   cin >> strength; 
                   cout << endl;
               
               }
               
               cout << "Enter Character Intelligence (1-20): " ;
               cin >> intelligence; 
               
               if (intelligence < 1 || intelligence > 20 ) 
               {
                   cout << "Invalid Intelligence"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Intelligence";
                   cout << endl;
               }
                
                while (cin.fail()||intelligence < 1 || intelligence >20)
                {
                   cin.clear();
                   cin.ignore(200, '\n');
                   cout << "Please enter a valid character intelligence (1-20): " ;
                   cin >> intelligence; 
                   cout << endl;
               
               }
               cout << endl;
               
               cout << "Enter Character Dexterity (1-20): " ;
               cin >> dexterity; 
               
               if (dexterity < 1 || dexterity > 20 ) 
               {
                   cout << "Invalid Dexterity"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Dexterity";
                   cout << endl;
               }
                
                while (cin.fail()||dexterity < 1 || dexterity >20)
                {
                   cin.clear();
                   cin.ignore(200, '\n');
                   cout << "Please enter a valid character Dexterity (1-20): " ;
                   cin >> dexterity; 
                   cout << endl;
               
               }
               
               cout << "Enter Character Constitution (1-20): " ;
               cin >> constitution; 
               
               if (constitution < 1 || constitution > 20 ) 
               {
                   cout << "Invalid Constitution"; 
                   cout << endl;
               } else 
               
               {
                   cout << "Valid Constitution";
                   cout << endl;
               }
                
                while (cin.fail()||constitution < 1 || constitution > 20)
                {
                   cin.clear();
                   cin.ignore(200, '\n');  
                   cout << "Please enter a valid character Constitution (1-20): " ;
                   cin >> constitution; 
                   cout << endl;
               
               }
               
               // Class Bonuses Calculations
               
               switch (classChoice) {
                   case 1: 
                    strength += 3; // bonus for warrior class
                    break;
                   
                   case 2:
                    intelligence += 3; // bonus for mage class
                    break;
                   
                   case 3: 
                    dexterity += 3; // bonus for rougue class
                    break;
                   
                   case 4:
                    constitution += 3; // bonus for cleric class
                    break; 
               }
                level = 1; // automatically sets a created character to level 1
                completedCharacter = true;
                   
                cout << "Congrats!! You have created a character." << endl;
                break;
               
                
            case 2:
            // ensures that user chooses choice 1 (create a character) before anything else
                if (!completedCharacter) {
                cout << "Please create a character first!" << endl;
                break;
                    
                }

            // calculations so combat stats can be displayed
            combatStats[0] = (constitution * 10) + (level * 5); // calculating the hp
            combatStats[1] = (intelligence * 10) + (level * 3); // calculating the mp
            combatStats[3] = (constitution + dexterity) / 2; // calculating the defense
            
                switch (classChoice) {
                    
                    // combat stats for warrior
                    case 1: 
                        combatStats[0] += 20; // calculating the hp for warrior class
                        combatStats[2] = strength * 1.5; // calculating attack power for warrior class
                        break;
                    
                    // combat stats for mage
                    case 2:
                        combatStats[1] += 30; // calculating mp for mage class
                        combatStats[2] = intelligence * 1.3; // calculating attack power for mage class
                        break;
                    
                    // combat stats for rogue
                    case 3:
                        combatStats[2] = dexterity * 1.4; // calculating attack power for rogue class
                        break;
                    
                    // combat stats for cleric 
                    case 4:
                    combatStats[2] = (strength + intelligence) * 0.8; // calculating attack power for cleric class
                    break;
                }
                
                // allows for all chaarcter info to be displayed
                cout << "\n[View Stats]" << endl;
                
                cout << "\n=== CHARACTER PROFILE ===" << endl;
                cout << "Name: " << characterName << endl;
                cout << "Class: " << characterClass << endl;
                cout << "Level: " << level << endl;
                
                cout << "\n=== Base Stats=== " << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
                
                cout << "\n=== COMBAT STATS ===" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << combatStatsNames[i] << ": " << combatStats[i] << endl;
                }
                break;
                
                break;
                
            case 3:
            
            if (!completedCharacter) {
                cout << "Please create a character first!" << endl;
                break;
            }
           // only displays the combat stats
                cout << "\n=== COMBAT STATS ===" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << combatStatsNames[i] << ": " << combatStats[i] << endl;
                }
                
                break;
                
            case 4:
             
            if (!completedCharacter) {
                cout << "Please create a character first!" << endl;
                break;
            }
                cout << "\n[Level Up]" << endl;
                
                if (level >= MAX_LEVEL) {
                    cout << "Congrats!!, you have reached the maximum level" << endl;
                } 
                
                cout << "\n=== Before Stats ===" << endl;
                cout << "Level: " << level << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
                
                // each base stat goes up by on each time user levels up
                if (strength < MAX_STAT) {
                    strength++;
                }
                if (intelligence < MAX_STAT) {
                    intelligence++;
                }
                if (dexterity < MAX_STAT) {
                    dexterity++;
                }
                if (constitution < MAX_STAT) {
                    constitution++;
                }
                if (level < MAX_LEVEL) { 
                    level++;
                }
                
                // recalculating the Stats
                combatStats[0] = (constitution * 10) + (level * 5); // calculating the hp
            combatStats[1] = (intelligence * 10) + (level * 3); // calculating the mp
            combatStats[3] = (constitution + dexterity) / 2; // calculating the defense
            
                switch (classChoice) {
                    
                    // combat stats for warrior
                    case 1: 
                        combatStats[0] += 20; // calculating the hp for warrior class
                        combatStats[2] = strength * 1.5; // calculating attack power for warrior class
                        break;
                    
                    // combat stats for mage
                    case 2:
                        combatStats[1] += 30; // calculating mp for mage class
                        combatStats[2] = intelligence * 1.3; // calculating attack power for mage class
                        break;
                    
                    // combat stats for rogue
                    case 3:
                        combatStats[2] = dexterity * 1.4; // calculating attack power for rogue class
                        break;
                    
                    // combat stats for cleric 
                    case 4:
                    combatStats[2] = (strength + intelligence) * 0.8; // calculating attack power for cleric class
                    break;
                }
                
                cout << "\n=== After Stats === " << endl;
                cout << "Level: " << level << endl;
                cout << "Strength: " << strength << endl;
                cout << "Intelligence: " << intelligence << endl;
                cout << "Dexterity: " << dexterity << endl;
                cout << "Constitution: " << constitution << endl;
                
                cout << "\n=== New Combat Stats === " << endl;
                for (int i = 0; i < 4; i++) {
                    cout << combatStatsNames[i] << ": " << combatStats[i] << endl;
                }
                break;
            
                
                break;
                
            case 5:
                cout << "\nThanks for using GameStat! Goodbye!" << endl;
                keepRunning = false;
                break;
                
            default:
                cout << "\nInvalid choice! Please enter 1-5." << endl;
                break;
        }
        
    } while (keepRunning);
    
    return 0;
}