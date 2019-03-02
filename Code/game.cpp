#include "game.h"

using namespace std; //cin.ignore() works with strings, not so much other stuff.

Game::Game()
{
    defualtDate = Date(); //Here is where I am intitializing defuatDate equal to the defualt contructor of the class. This is done automatically. So, is optional.
    customDate = Date(); //Optional too. Dont have to include anything here.
    counter = 0;
    mult = .25; //I incrememented price in store by doing mult * counter, witch counter initially being 0.
    playerCount = 5;
    quit = false;
}

void Game::makeNewPlayer() //Makes instances of 5 players.
{
    string name;
    for (int x = 0; x < 5; x++)
    {
        if (x == 0)
        {
            cout << "What is the name of your first character? He will be the leader: " << endl;
        }
        else
        {
            cout << "Please enter the names of the four other characters: " << endl;
        }
        getline(cin, name); //Gets the name from the user.
        Players player(name); //Declares the object. Is of the Players class. Have to declare object first. Same thing as initilizing a variable. When declaring, have to give it input parameter of constructor.
        playersArray[x] = player; //Then sets the array equal to the object.
    }
}

void Game::storeInterface()
{
    string response;
    if (playersArray[0].getPlayerPosition() == 0)
    {
        cout << "YOU HAD SAVED $1200 TO SPEND FOR THE TRIP, AND YOU'VE JUST PAID $200 FOR A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:" << endl;
        cout << "OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS." << endl;
        cout << "FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK." << endl;
        cout << "AMMUNITION - YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD." << endl;
        cout << "MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS." << endl;
        cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD." << endl;
    }
    cout << "Press any character to continue to store. Press (L) to leave the store." << endl;
    getline(cin, response);
    if (playersArray[0].getPlayerPosition() == 0)
    {
        cout << "How many oxen would you like to purchase? You must purchase between $100-200." << endl; //Oxen Part
        cout << "The price for one ox is $20." << endl;
        getline(cin, response);
        while (stoi(response) < 5 || stoi(response) > 10)
        {
            cout << "Oxen purchase must be between $100-200!" << endl;
            getline(cin, response);
        }
        cout << "The price of your purchase is: " << store.getOxenPrice(stoi(response)) << "$" << endl;
        for (int x = 0; x < 5; x++)
        {
            playersArray[x].setOxen(stoi(response), 0); //Is going to set each player's oxen count to the number of oxen. Accesses the private data member of the array of players and accesses a function in there called getOxen with that input parameter.
            playersArray[x].setMoney(store.getOxenPrice(stoi(response)), 1.0); //Sets each players money to how much they will have left. setMoney takes input parameter of cost, in order to get cost, need to get the oxen price which is a member of the store class. So, do .store and then the getOxenPrice which takes input parameter of how many oxen.
        }
        cout << "You have $" << playersArray[0].getMoney() << " left." << endl;
    }
    while (response != "L")
    {
        cout << "Press (1) to purchase food, press (2) to purchase bullets, press (3) to purchase wagon parts, or press (4) to purchase medical kits. Or press (L) to leave." << endl;
        getline(cin, response); //It wasnt working when I pressed L because it was trying to convert a string to an integer and was breaking the program.
        if (response == "1")
        {
            cout << "It is recommended to purchase at least 200 pounds of food per person. It is 50 (increases by a factor of 25 percent) cents per pound." << endl; //Food part
            cout << "How many pounds of food would you like to purchase?" << endl;
            getline(cin, response);
            if (playersArray[0].getMoney() >= store.getFoodPrice(stoi(response)))
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(stoi(response), 0); //Sets the players food. And one underneath sets the players new money.
                    playersArray[x].setMoney(store.getFoodPrice(stoi(response)), (1 + (counter * mult))); //getFoodPrice will return the price and setMoney takes input parameter of cost and updates current money.
                }
                //cout << "You have $" << playersArray[0].getMoney() << " left." << endl;
            }
            else 
            {
                if ((playersArray[0].getMoney() < store.getFoodPrice(stoi(response))))
                {
                    cout << "You do not have enough money!" << endl;
                    /*cout << "Please enter a valid amout." << endl;
                    getline(cin, response);*/
                }
            }
            cout << "You have $" << playersArray[0].getMoney() << " left." << endl;
        }
        else if (response == "2")
        {
            cout << "A box of bullets cost $2 (increases by a factor of 25 percent)." << endl; //Bullets part.
            cout << "How many boxes of bullets would you like to purchase?" << endl;
            getline(cin, response);
            if (playersArray[0].getMoney() >= store.getBulletsPrice(stoi(response)))
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setBullets(stoi(response));
                    playersArray[x].setMoney(store.getBulletsPrice(stoi(response)),(1 + (counter * mult)));
                }
            }
            else
            {
                if (playersArray[0].getMoney() < store.getBulletsPrice(stoi(response)))
                {
                    cout << "You do not have enough money!" << endl;
 /*                   cout << "Please enter a valid amout." << endl;
                    getline(cin, response);*/
                }
            }
            cout << "You have $" << playersArray[0].getMoney() << " left." << endl;
        }
        else if (response == "3")
        {
            cout << "Would you like to purchase wagon parts. It is $20 per part (increases by a factor of 25 percent)." << endl; //Wagon parts.
            cout << "If so, how many?" << endl;
            getline(cin, response);
            if (playersArray[0].getMoney() >= store.getWagonPartsPrice(stoi(response)))
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setWagonParts(stoi(response), 0);
                    playersArray[x].setMoney(store.getWagonPartsPrice(stoi(response)), (1 + (counter * mult)));
                }
            }
            else
            {
                if (playersArray[0].getMoney() < store.getWagonPartsPrice(stoi(response)))
                {
                    cout << "You do not have enough money!" << endl;
       /*             cout << "Please enter a valid amount." << endl;
                    getline(cin, response);*/
                }
            }
            cout << "You have $" << playersArray[0].getMoney() << " left." << endl;
        }
        else if (response == "4")
        {
            cout << "Would you like to purchase medical kits? One kit costs $25 (increases by a factor of 25 percent)." << endl; //Medical kits
            cout << "If so, how many?" << endl;
            getline(cin, response);
            if (playersArray[0].getMoney() >= store.getMedicalKitPrice(stoi(response)))
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setMedicalKit(stoi(response));
                    playersArray[x].setMoney(store.getMedicalKitPrice(stoi(response)), (1 + (counter * mult)));
                }
            }
            else
            {
                if (playersArray[0].getMoney() < store.getMedicalKitPrice(stoi(response)))
                {
                    cout << "You do not have enough money!" << endl;
                    /*cout << "Please enter a valid amount." << endl;
                    getline(cin, response);*/
                }
            }
            cout << "You have $" << playersArray[0].getMoney() << " left." << endl;
        }
    }
}

void Game::startingDate() //For each of the top 2 conditionals have to make an instance of date class.
{
    cout << "You have been given the default start date of: 03/28/1847. However, you may choose any date between 03/01/1847 and 05/01/1847." << endl;
    cout << "Please enter a your starting date in the following format: mm/dd/yyyy" << endl;
    string response; //Is total response, even with slashes.
    getline(cin, response);
    
    string month; //Month is only first part.
    string day; //Day is second part.
    string year;
    stringstream ss(response); //Makes a string stream of the user's response.
    getline(ss, month, '/'); //Everything before the '/' is stored in variable month.
    getline(ss, day, '/'); //Everything afterward, up until the next slash, is in variable day.
    getline(ss, year);
    
    int y = stoi(year); 
    
    while (y != 1847 || (stoi(day) < 1 || stoi(day) > 30) || (stoi(month) < 3 || stoi(month) > 5))
    {
        cout << "You have entered an invalid starting date!" << endl;
        cout << "Please enter a valid starting date: " << endl;
        response = ""; //Right above getline everytime in a while loop. Clears the cache. Works will with string, not so much other stuff.
        getline(cin, response);
        stringstream ss(response); //Makes a string stream of the user's response.
        getline(ss, month, '/'); //Everything before the '/' is stored in variable month.
        getline(ss, day, '/'); //Everything afterward , up until the next slash, is in variable day.
        getline(ss, year);
        y = stoi(year); 
    }
    if ((month == "3" || month == "03") && day == "28") //Will set the starting date for each player equal to the defualt starting date.
    {
        cout << "Congratulations, you have chosen the default date of: " << response << "." << endl;
        defualtDate; //Already declared with date class in private. So, now, can just call it.
        for (int x = 0; x < 5; x++)
        {
            playersArray[x].setCurrentDate(defualtDate); //Takes input paramter of Date type for starting date.
        }
    }
    else
    {
        cout << "Congratulations, you have chosen " << response << "." << endl;
        customDate = Date(stoi(month), stoi(day)); //Here is where I set the object customDate of date class equal to the cosntructor. Before it was equal to the defualt constructor.
        for (int x = 0; x < 5; x++)
        {
            playersArray[x].setCurrentDate(customDate);
        }
    }
}
//playersArray accesses the information for a certain player at the given index. Can use all of the private data members and functions of the given player.
void Game::turns() //This is in the class Game, so I can access (call) private data members. Can only call private data members from within class.
{
    if (playersArray[0].getPlayerPosition() == 0)
    {
        cout << "STATUS:" << endl;
        cout << "The current date is: " << playersArray[0].getCurrentDate().getMonth() << "/" << playersArray[0].getCurrentDate().getDay() << "/1847." << endl; //Accesses the player class, then current date function returns a value from the date class, so can use function from the date class.
        cout << "Miles traveled: " << playersArray[0].getPlayerPosition() << "." << endl;
        playersArray[0].setDistanceToLandmark(playersArray[0].getPlayerPosition(), "milestones.txt");
        cout << "Distance to next landmark: " << playersArray[0].getDistanceToLandmark() << " miles." << endl;
        cout << "You currently have: " << playersArray[0].getFood() << " pounds of food." << endl;
        cout << "You currently have: " << playersArray[0].getBullets() << " bullets." << endl;
        cout << "You currently have: " << "$" << playersArray[0].getMoney() << " left." << endl;
        cout << endl;
        cout << "You have began your journey..." << endl;
        cout << "Each turn you have the option to (r)est, (c)ontinue on trail, (h)unt for food, or (q)uit." << endl;
        cout << endl;
        cout << "Resting will take between 1 and 3 days (your choice on duration) and each person will consume 3 pounds of food per day." << endl;
        cout << "If anyone is sick, they will heal fully in 2 days." << endl;
        cout << endl;
        cout << "Continue on the trail will take 2 weeks, each person will consume 3 pounds of food per day, and you get to choose to travel any (integer) distance from 70-140 miles." << endl;
        cout << endl;
        cout << "Hunt for food takes one day." << endl;
        cout << "You have a chance to encounter a rabbit (2 pounds of meet and costs 10 bullets), a fox (5 pounds of meat and 8 bullets), a deer (40 pounds and 5 bullets), a bear (175 pounds and 10 bullets), or a moose (450 pounds and 12 bullets)." << endl;
        cout << "At the end of the hunting day, you can choose to eat poorly (2 pounds of food per person), moderately (3 pounds of food per person), or well (5 pounds of food per person)." << endl;
        cout << endl;
    }
    string response = "";
    //getline(cin, response);
    
    //Start of turns pretty much.
    while (response != "q" && quit != true && playersArray[0].getFood() > 0 && playersArray[0].getOxen() > 0 && playersArray[0].getAlive() == true) //Will response is not equal to q and quit, do below.
    {
        if ((playersArray[0].getCurrentDate().getDay() > 30 && playersArray[0].getCurrentDate().getMonth() >= 11) || playersArray[0].getCurrentDate().getMonth() > 11 || playersArray[0].getCurrentDate().getYear() != 1847) //Will quit game if they dont make it in time.
        {
            cout << "Game over! You lose." << endl;
            cout << "Group leader's name: " << playersArray[0].getName() << endl;
            cout << "Miles traveled: " << playersArray[0].getPlayerPosition() << "." << endl;
            cout << "Food remaining: " << playersArray[0].getFood() << " pounds of food." << endl;
            cout << "Money remaining: " << "$" << playersArray[0].getMoney() << " left." << endl;
            ofstream resultsStream;
            resultsStream.open("results.txt");
            if (resultsStream.is_open())
            {
                resultsStream << "Group leader's name: " << playersArray[0].getName() << endl;
                resultsStream << "Miles traveled: " << playersArray[0].getPlayerPosition() << "." << endl;
                resultsStream << "Food remaining: " << playersArray[0].getFood() << " pounds of food." << endl;
                resultsStream << "Money remaining: " << "$" << playersArray[0].getMoney() << " left." << endl;
                resultsStream.close();
            }
            else
            {
                cout << "Something went wrong!" << endl;
                return;
            }
            break; //Will exit out and end code.
        }
        if (playersArray[0].getPlayerPosition() != 0)
        {
            cout << "STATUS" << endl;
            cout << "The current date is: " << playersArray[0].getCurrentDate().getMonth() << "/" << playersArray[0].getCurrentDate().getDay() << "/1847." << endl; //Accesses the player class, then current date function returns a value from the date class, so can use function from the date class.
            cout << "Miles traveled: " << playersArray[0].getPlayerPosition() << "." << endl;
            playersArray[0].setDistanceToLandmark(playersArray[0].getPlayerPosition(), "milestones.txt");
            cout << "Distance to next landmark: " << playersArray[0].getDistanceToLandmark() << " miles." << endl;
            cout << "You currently have: " << playersArray[0].getFood() << " pounds of food." << endl;
            cout << "You currently have: " << playersArray[0].getBullets() << " bullets." << endl;
            cout << "You currently have: " << "$" << playersArray[0].getMoney() << " left." << endl;
            cout << endl;
            //cout << "Would you like to (r)est, (c)ontinue on trail, (h)unt for food, or (q)uit?" << endl;
        }
        cout << "Would you like to (r)est, (c)ontinue on trail, (h)unt for food, or (q)uit?" << endl;
        getline(cin, response);
        if (response == "r") //Done, just need to fix date issue.
        {
            cout << "How many days would you like to rest? Value must be between 1 and 3." << endl;
            getline(cin, response);
            while (stoi(response) > 3 || stoi(response) < 1)
            {
                cout << "You have entered an invalid number! Please try again." << endl;
                getline(cin, response);
            }
            cout << "You have chosen to rest for " << response << " days." << endl;
             //want to increase date by a number, increase turn by 1, and subtract 3 each day from the food count. Also, if 2 or more days, want to increase health to 100.
            for (int x = 0; x < 5; x++)
            {
                playersArray[x].setFood(playersArray[0].getFood(), (3 * stoi(response))); //Decreases food by a factor of 3 for each day.
                playersArray[x].increasePlayerTurnCount(1); //Will add one to the turn.
                Date d = playersArray[x].getCurrentDate();
                d.restTurnAddDate(stoi(response)); //Will add how many days they chose to the date.
                playersArray[x].setCurrentDate(d); //Will set the date equal to what the user chooses.
            }
                if (stoi(response) >= 2) //Will set the player's health equal to 100 if they rest for 2 or more days.
                {
                    for (int x = 0; x < 5; x++)
                    {
                        playersArray[x].setPlayerHealth(100, 0, 0);
                    }
                    cout << "Player health has been restored to 100 percent!" << endl;
                }
        }
        if (response == "c") //For this option, I want to decrease food by 21, add 7 to the date, add one to the turn. Also, it needs to detect milestones, give the user the option to go to that milestone or not, if it is a certain type of milestone then do something
        {
            for (int x = 0; x < 5; x++)
            {
                playersArray[x].setPlayerHealth(playersArray[x].getPlayerHealth(), 0, 100);
            }
            cout << "You have chosen to continue on the trial! It will take 2 weeks and you must travel 70 to 140 miles." << endl;
            for (int x = 0; x < 5; x++)
            {
                playersArray[x].setFood(playersArray[0].getFood(), 21); //Decreases food by 21.
                playersArray[x].increasePlayerTurnCount(1); //Will add one to the turn.
                Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                d.continueTurnAddDate(); //Will add how many days they chose to the date.
                playersArray[x].setCurrentDate(d); //Will set the date equal to what the user chooses.
            }
            playersArray[0].setDistanceToLandmark(playersArray[0].getPlayerPosition(), "milestones.txt"); //Sets this value using current information.
            if (playersArray[0].getDistanceToLandmark() < 140 && playersArray[0].getDistanceToLandmark() > 70) //If there is an oppertunity to go to a particular landmark.
            {
                cout << "There is a landmark " << playersArray[0].getDistanceToLandmark() << " miles away. Would you like to travel there? Enter (y)es or (n)o" << endl;
                getline(cin, response);
                while (response != "y" && response != "n") //Handle edge cases before rest of code.
                {
                    cout << "You have entered an invalid input! Try again." << endl;
                    response = ""; //Essentially clears the cache.
                    getline(cin, response);
                }
                if (response == "y")
                {
                    cout << "You will travel to " << playersArray[0].getMileStone(playersArray[0].getMileStonePosition()).getName() << endl;
                    for (int x = 0; x < 5; x++)
                    {
                        playersArray[x].setPlayerPosition(playersArray[0].getDistanceToLandmark());
                    }
                    if (playersArray[0].getMileStone(playersArray[0].getMileStonePosition()).getType() == "River") //Here is where I am going to handle the different types of milestones. There are rivers, forts, and landmarks. So 3 conditions.
                    {
                        if (playersArray[0].getMileStone(playersArray[0].getMileStonePosition()).getDepth() > 3) //Costs money if river depth is greater than 3.
                        {
                            cout << "Oh no! The river is " << playersArray[0].getMileStone(playersArray[0].getMileStonePosition()).getDepth() << " feet deep. This requires you to pay $10 per person." << endl;
                            for (int x = 0; x < 5; x++)
                            {
                                //cout << "count: " << alivePlayerCounter() << endl; 
                                
                                playersArray[x].setMoney((alivePlayerCounter() * 10), 1); //Input parameter is what it subtracts it by. alivePlayerCounter will return the amount of alive players.
                            }
                        }
                        continue;
                    }
                    else if (playersArray[0].getMileStone(playersArray[0].getMileStonePosition()).getType() == "Fort") //Here I am accessing leader's functions/information, then I am calling a function that takes input parameter of element of nearest milestone, and returns a value of the position class, then since im in the position class, I can now call the getName function on that function which returns a string value for the milestone.
                    {
                        
                        cout << "Congratulations, you have reached a fort! Here you have the oppertunity to purchase additional supplies." << endl;
                        cout << "Beware, as you progress, the items become more expensive!" << endl;
                        cout << "Would you like to (b)uy supplies or (c)ontinue on with the journey?" << endl;
                        getline(cin, response);
                        //cout << "user entered " << response << endl;
                        while (response != "b" && response != "c") //Not or because if it is equal to "b" it would still enter loop because it is not equal to "c".
                        {
                            cout << "Please input a valid response!" << endl;
                            response = "";
                            getline(cin, response);
                        }
                        if (response == "b")
                        {//P stands for purchase.
                            //cout << "It went to store." << endl;
                            counter++; //For increasing the price at each store. Increased price by doing a set money multiplyer.
                            storeInterface();
                        }
                        else if (response == "c")
                        {
                            //cout << "Didnt work." << endl;
                        }
                    }
                    else if (playersArray[0].getMileStone(playersArray[0].getMileStonePosition()).getType() == "Landmark") //Accessing indiviudal player, takes input of element that we want, so we access the player function getMileStonePosition which returns the element position which is a private data member. Then, access position class, through the array and gets the name.
                    {
                        continue;
                    }
                    
                }
                    if (response == "n") //Done. Will move the player along.
                    {
                        cout << "How many miles would you like to travel? Must be between 70 and 140." << endl;
                        getline(cin, response);
                        while (stoi(response) > 140 || stoi(response) < 70)
                        {
                            cout << "Please enter a valid number!" << endl;
                            response = "";
                            getline(cin, response);
                        }
                        for (int x = 0; x < 5; x++)
                        {
                            playersArray[x].setPlayerPosition(stoi(response));
                        }
                    }
            }
                else //If the landmark is not between 70 and 140 miles away. Also done.
                {   
                    cout << "How many miles would you like to travel? Must be between 70 and 140." << endl;
                    getline(cin, response);
                    while (stoi(response) > 140 || stoi(response) < 70)
                    {
                        cout << "Please enter a valid number!" << endl;
                        response = "";
                        getline(cin, response);
                    }
                    for (int x = 0; x < 5; x++)
                    {
                        playersArray[x].setPlayerPosition(stoi(response));
                    }
                }
        }
        if (response == "h")
        {
            string intResponse;
            int counter = 1;
            for (int x = 0; x < 5; x++)
            {
                playersArray[x].increasePlayerTurnCount(1); //Will add one to the turn.
                Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                d.huntTurnAddDate(); //Will add how many days they chose to the date.
                playersArray[x].setCurrentDate(d); //Will set the date equal to what the user chooses.
            }
            if (randomNumbers(1, 100) <= 50)
            {
                cout << "Wow! you encountered a rabbit! Do you want to hunt? (y)es or (n)o." << endl; 
                getline(cin, response);
                while (response != "y" && response != "n")
                {
                    cout << "Please enter a valid response." << endl;
                    response = "";
                    getline(cin, response);
                }
                if (response == "y")
                {
                    if (playersArray[0].getBullets() >= 10)
                    {
                        cout << "You have 3 tries to guess a number between 1 and 10, if you guess correctly, your hunt will be successful!" << endl;
                        if (quiz() == true)
                        {
                            for (int x = 0; x < 5; x++)
                            {
                                playersArray[x].setFoodAdding(playersArray[0].getFood(), 2); //Sets the food
                                playersArray[x].setBulletsSubtraction(playersArray[0].getBullets(), 10); //Will set the bullets to current number - 10.
                            }
                            cout << "Hunt successful, you have gained 2 pounds of food and lost 10 bullets!" << endl;
                        }
                        else
                        {
                            cout << "You didnt guess the right number, hunt failed." << endl;
                        }
                    }
                }
                else if (response == "n")
                {
                    cout << "You have chosen not to hunt!" << endl;
                    continue; //should just do nothing.
                }
            }
            if (randomNumbers(1, 100) <= 25)
            {
                cout << "Wow! you encountered a fox! Do you want to hunt? (y)es or (n)o." << endl; 
                getline(cin, response);
                while (response != "y" && response != "n")
                {
                    cout << "Please enter a valid response." << endl;
                    response = "";
                    getline(cin, response);
                }
                if (response == "y")
                {
                    if (playersArray[0].getBullets() >= 10)
                    {
                        cout << "You have 3 tries to guess a number between 1 and 10, if you guess correctly, your hunt will be successful!" << endl;
                        if (quiz() == true)
                        {
                            for (int x = 0; x < 5; x++)
                            {
                                playersArray[x].setFoodAdding(playersArray[0].getFood(), 5); //Sets the food to plus 5.
                                playersArray[x].setBulletsSubtraction(playersArray[0].getBullets() ,8); //Will set the bullets to current number - 8.
                            }
                            cout << "Hunt successful, you have gained 5 pounds of food and lost 8 bullets!" << endl;
                        }
                        else
                        {
                            cout << "You didnt guess the right number, hunt failed." << endl;
                        }
                    }
                }
                else if (response == "n")
                {
                    cout << "You have chosen not to hunt!" << endl;
                    continue; //should just do nothing.
                }
            }
            if (randomNumbers(1, 100) <= 15)
            {
                cout << "Wow! you encountered a deer! Do you want to hunt? (y)es or (n)o." << endl; 
                getline(cin, response);
                while (response != "y" && response != "n")
                {
                    cout << "Please enter a valid response." << endl;
                    response = "";
                    getline(cin, response);
                }
                if (response == "y")
                {
                    if (playersArray[0].getBullets() >= 10)
                    {
                        cout << "You have 3 tries to guess a number between 1 and 10, if you guess correctly, your hunt will be successful!" << endl;
                        if (quiz() == true)
                        {
                            int i = randomNumbers(30, 55);
                            for (int x = 0; x < 5; x++)
                            {
                                playersArray[x].setFoodAdding(playersArray[0].getFood(), i); //Sets the food
                                playersArray[x].setBulletsSubtraction(playersArray[0].getBullets() ,5); //Will set the bullets to current number - 5.
                            }
                            cout << "Hunt successful, you have gained" << i << " pounds of food and lost 5 bullets!" << endl;
                        }
                        else
                        {
                            cout << "You didnt guess the right number, hunt failed." << endl;
                        }
                    }
                }
                else if (response == "n")
                {
                    cout << "You have chosen not to hunt!" << endl;
                    continue; //should just do nothing.
                }
            }
            if (randomNumbers(1, 100) <= 7)
            {
                cout << "Wow! you encountered a bear! Do you want to hunt? (y)es or (n)o." << endl; 
                getline(cin, response);
                while (response != "y" && response != "n")
                {
                    cout << "Please enter a valid response." << endl;
                    response = "";
                    getline(cin, response);
                }
                if (response == "y")
                {
                    if (playersArray[0].getBullets() >= 10)
                    {
                        cout << "You have 3 tries to guess a number between 1 and 10, if you guess correctly, your hunt will be successful!" << endl;
                        if (quiz() == true)
                        {
                            int i = randomNumbers(100, 250);
                            for (int x = 0; x < 5; x++)
                            {
                                playersArray[x].setFoodAdding(playersArray[0].getFood(), i); //Sets the food
                                playersArray[x].setBulletsSubtraction(playersArray[0].getBullets() ,10); //Will set the bullets to current number - 10.
                            }
                            cout << "Hunt successful, you have gained" << i << " pounds of food and lost 10 bullets!" << endl;
                        }
                        else
                        {
                            cout << "You didnt guess the right number, hunt failed." << endl;
                        }
                    }
                }
                else if (response == "n")
                {
                    cout << "You have chosen not to hunt!" << endl;
                    continue; //should just do nothing.
                }
            }
            if (randomNumbers(1, 100) <= 5) //will only work if returned value is less than or equal to the probability of encountering a moose.
            {
                cout << "Wow! you encountered a moose! Do you want to hunt? (y)es or (n)o." << endl; 
                getline(cin, response);
                while (response != "y" && response != "n")
                {
                    cout << "Please enter a valid response." << endl;
                    response = "";
                    getline(cin, response);
                }
                if (response == "y")
                {
                    if (playersArray[0].getBullets() >= 10)
                    {
                        cout << "You have 3 tries to guess a number between 1 and 10, if you guess correctly, your hunt will be successful!" << endl;
                        if (quiz() == true)
                        {
                            int i = randomNumbers(300, 600);
                            for (int x = 0; x < 5; x++)
                            {
                                playersArray[x].setFoodAdding(playersArray[0].getFood(), i); //Adds to the food value.
                                playersArray[x].setBulletsSubtraction(playersArray[0].getBullets() ,12); //Will set the bullets to current number - 10.
                            }
                            cout << "Hunt successful, you have gained" << i << " pounds of food and lost 12 bullets!" << endl;
                        }
                        else
                        {
                            cout << "You didnt guess the right number, hunt failed." << endl;
                        }
                    }
                }
                else if (response == "n")
                {
                    cout << "You have chosen not to hunt!" << endl;
                    continue; //should just do nothing.
                }
            }
            cout << "Would you like to eat (w)ell (5 pounds per person), (m)oderately (3 pounds per person), or (p)oorly (2 pounds per person)?" << endl;
            getline(cin, response);
            while (response != "w" && response != "m" && response != "p")
            {
                cout << "You have entered an invalid response!" << endl;
                response = "";
                getline(cin, response);
            }
            if (response == "w")
            {
                for (int x = 0; x < 5; x++)
                {
                    if (playersArray[x].getPlayerHealth() != 100) //Might need to take out later.
                    {
                        if (playersArray[x].getPlayerHealth() > 0) //If less than 0 they are dead.
                        {
                            playersArray[x].setPlayerHealth(100, 0, 0);
                        }
                    }
                    playersArray[x].setFood(playersArray[0].getFood(), 5); //Decreases food by 5.
                }
                cout << "Your health has been restored to 100 percent." << endl;
            }
            if (response == "m")
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 3); //Decreases food by 3.
                }
            }
            if (response == "p") //Eating poorly.
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 2); //Dec food by 2.
                }
            }
            if (playersArray[0].getFood() > 1000)
            {
                cout << "Your wagon can only hold 1000 pounds of food! You had to leave behind " << (playersArray[0].getFood() - 1000) << " pounds of food." << endl;
                playersArray[0].setFood(playersArray[0].getFood(), (playersArray[0].getFood() - 1000));
            }
        }
        raiderAttack(); //Will run this code at the start of everyturn.
        misfortunes(); //Will also run this code at the start of every turn. Can call it because it is a function in the same class.
    }
    if (response == "q" || quit == true || playersArray[0].getFood() <= 0 || playersArray[0].getOxen() <= 0 || playersArray[0].getAlive() == false)
        {
            cout << "Game over! You lose." << endl;
            cout << "Group leader's name: " << playersArray[0].getName() << endl;
            cout << "Miles traveled: " << playersArray[0].getPlayerPosition() << "." << endl;
            cout << "Food remaining: " << playersArray[0].getFood() << " pounds of food." << endl;
            cout << "Money remaining: " << "$" << playersArray[0].getMoney() << " left." << endl;
            ofstream resultsStream;
            resultsStream.open("results.txt");
            if (resultsStream.is_open())
            {
                resultsStream << "Group leader's name: " << playersArray[0].getName() << endl;
                resultsStream << "Miles traveled: " << playersArray[0].getPlayerPosition() << "." << endl;
                resultsStream << "Food remaining: " << playersArray[0].getFood() << " pounds of food." << endl;
                resultsStream << "Money remaining: " << "$" << playersArray[0].getMoney() << " left." << endl;
                resultsStream.close();
            }
            else
            {
                cout << "Something went wrong!" << endl;
            }
            return;
        }
}

int Game::randomNumbers(int min, int max)
{
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

bool Game::quiz() //Will ask them to enter a number 3 times. They will get 3 times.
{
    string n; 
    for(int x = 0; x < 3; x++)
    {
        cout << "Guess a number between 1 and 10: " << endl; 
        getline(cin, n);
        
        if (stoi(n) == randomNumbers(1, 10))
        {
            cout << "Guess correct." << endl; 
            return true; 
        }
    }
    return false; 
}

void Game::raiderAttack()
{
    string response;
    float n = pow(((playersArray[0].getPlayerPosition()/100.0) - 4), 2) + 72; //Has to be integer because that's what my random numbers function uses. Returns an integer value.
    float d = pow(((playersArray[0].getPlayerPosition()/100.0) - 4), 2) + 12;
    int probability = (((n/d) - 1) / 10) * 100;
    
    //cout << "probability: " << probability << endl; 
    
    if (randomNumbers(1, 100) <= probability) //Means: if a random number is less than, or just as probable.
    {
        cout << "People ahead! They look hostile!" << endl;
        cout << "Would you like to (r)un, (a)ttack, or (s)urrender?" << endl;
        getline(cin, response);
        while (response != "r" && response != "a" && response != "s")
        {
            cout << "Please enter a valid response!" << endl;
            response = "";
            getline(cin, response);
        }
        if (response == "r")
        {
            if (playersArray[0].getFood() >= 10 && playersArray[0].getOxen() >= 1 && playersArray[0].getWagonParts() >= 1)
            {
                cout << "You have survived this time, but your party has lost: 1 ox, 10 pounds of food, and 1 wagon part." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setOxen(playersArray[0].getOxen(), 1);
                    playersArray[x].setFood(playersArray[0].getFood(), 10);
                    playersArray[x].setWagonParts(playersArray[0].getWagonParts(), 1);
                }
            }
            else
            {
                cout << "You lose because you do not have enough resources!" << endl;
                quit = true; //Will set quit equal to true so it wont go into the while loop and will go to the quit function.
                return; //Will end the program.
            }
        }
        else if (response == "a")
        {
            cout << "In order to win an attack, you must pass a puzzle. You have 3 tries to guess a number between 1 and 10." << endl;
            if (quiz() == true)
            {
                cout << "You have gained 50 pounds of food and 50 bullets." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFoodAdding(playersArray[0].getFood(), 50);
                    playersArray[x].setBulletsAdding(playersArray[0].getBullets(), 50);
                }
            }
            else
            {
                cout << "You didn't guess the right number, attack failed." << endl;
                if (playersArray[0].getBullets() >= 50 && playersArray[0].getMoney() > 0)
                {
                    cout << "You have lost 50 bullets and a quarter of your money." << endl;
                    for (int x = 0; x < 5; x++)
                    {
                        playersArray[x].setBulletsSubtraction(playersArray[0].getBullets(), 50);
                        playersArray[x].setMoneyProbability(playersArray[0].getMoney(), (playersArray[0].getMoney() / 4));
                    }
                }
                else
                {
                    cout << "You lose because you do not have enough resources!" << endl;
                    quit = true;
                    return;
                }
            }
        }
        else if (response == "s")
        {
            cout << "Since you surrendered, they took a quarter of your money!" << endl;
            if (playersArray[0].getMoney() > 0)
            {
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setMoneyProbability(playersArray[0].getMoney(), (playersArray[0].getMoney() / 4));
                }
            }
            else
            {
                cout << "You lose because you do not have enough resources!" << endl;
                quit = true;
                return;
            }
        }
    }
    
}

void Game::misfortunes() //Here is where the leader can die.
{
    string response;
    if (randomNumbers(1, 100) <= 40) //This will only be true if the random number is less than or equal to 40, meaning just as probable or less probable than 40.
    {
        if (randomNumbers(1, 5) == 1) //If the random number is equal to 1, will make someone sick.
        {
            int i = randomNumbers(1, 5);
            cout << "Oh no!" << playersArray[i].getName() << " has became sick." << endl;
            playersArray[i].setPlayerHealth(playersArray[i].getPlayerHealth(), 100, 0); //Sets the players health equal to their current health, minus 100, plus 0. If that value is less than 0, it will make them dead.
            if (playersArray[0].getAlive() == false)
            {
                cout << "The leader has died, so you lose!" << endl;
                quit = true; //quit is a private variable. Since I am in same class and function is member of class, I can directly alter the value of it without creating a setter function.
                return;
            }
            if (playersArray[0].getMedicalKit() > 0)
            {
                cout << "You can use a medical kit and go back to full health, (u)se or (n)o?" << endl;
                getline(cin, response);
                while (response != "u" && response != "n")
                {
                    cout << "You have entered an invalid input! Please try again." << endl;
                    response = "";
                    getline(cin, response);
                }
                if (response == "u")
                {
                    cout << playersArray[i].getName() << " now has 100 percent health!" << endl;
                    playersArray[i].setPlayerHealth(playersArray[i].getPlayerHealth(), 0, 100);
                }
                else if (response == "n")
                {
                    cout << "You have selected not to heal." << endl;
                    return; //Will effectively end the function.
                }
            }
        }
        if (randomNumbers(1, 5) == 2) //If = 2, will make oxen die.
        {
            cout << "One of the oxen have died! You have " << playersArray[0].getOxen() << " left." << endl;
            for (int x = 0; x < 5; x++)
            {
                playersArray[x].setOxen(playersArray[0].getOxen(), 1); //Since they all share the same amount of oxen, can just use the leader's amount of oxen.
            }
            if (playersArray[0].getOxen() < 1)
            {
                cout << "You have no oxen left! Game over." << endl;
                quit = true;
                return; //Pretty sure this is optional. But I think I like it.
            }
        }
        if (randomNumbers(1, 5) == 3) //So on.
        {
            cout << "Oh no! Last night you got attacked by a thief!" << endl;
            int f = randomNumbers(10, 25);
            for (int x = 0; x < 5; x++)
            {
                playersArray[x].setFood(playersArray[0].getFood(), f);
            }
            cout << "You lost " << f << " pounds of food." << endl;
            if (playersArray[0].getFood() <= 0)
            {
                cout << "You have lost because you ran out of food!" << endl;
                quit = true;
                return;
            }
        }
        if (randomNumbers(1, 5) == 4)
        {
            cout << "Uh oh! One of your wagon parts has broken!" << endl;
            cout << "You must fix it to continue. It will take 1 day and you will spend 1 wagon part." << endl;
            cout << "If you have no more wagon parts left, you will lose!" << endl;
            if (playersArray[0].getWagonParts() > 0)
            {
                for (int x = 0; x < 5; x++)
                {
                    Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                    d.huntTurnAddDate(); //Will increase by 1.
                    playersArray[x].setCurrentDate(d); //Will set the current date for all of the players.
                    playersArray[x].setWagonParts(playersArray[0].getWagonParts(), 1);
                    playersArray[x].setFood(playersArray[0].getFood(), 3);
                }
            }
            else
            {
                cout << "You lose because you don't have enough wagon parts!" << endl;
                quit = true;
                return; //I think that this is optional. I should ask.
            }
        }
        if (randomNumbers(1, 5) == 5)
        {
            int s = randomNumbers(1, 5);
            if (s == 1)
            {
                cout << "Oh no! There is heavy rain. This storm is going to last for 1 day." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 3);
                    Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                    d.huntTurnAddDate(); //Will increase by 1.
                    playersArray[x].setCurrentDate(d);
                }
            }
            else if (s == 2)
            {
                cout << "Oh no! There is hail. This storm is going to last for 1 day." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 3); //Will subtract player's current food by 3.
                    Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                    d.huntTurnAddDate(); //Will increase by 1.
                    playersArray[x].setCurrentDate(d);
                }
            }
            else if (s == 3)
            {
                cout << "Oh no! There is storm. This storm is going to last for 3 days." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 9);
                    Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                    d.restTurnAddDate(3); //Will increase by 1.
                    playersArray[x].setCurrentDate(d);
                }
            }
            else if (s == 4)
            {
                cout << "Oh no! There is blizzard. This storm is going to last for 3 days." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 9);
                    Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                    d.restTurnAddDate(3); //Will increase by 1.
                    playersArray[x].setCurrentDate(d);
                }
            }
            else if (s == 5)
            {
                cout << "Oh no! There is a hurricane. This storm is going to last for 7 days." << endl;
                for (int x = 0; x < 5; x++)
                {
                    playersArray[x].setFood(playersArray[0].getFood(), 21); //Food, then date below.
                    Date d = playersArray[x].getCurrentDate(); //Here I am setting an object equal to another object. Since getCurrent date returns object of same class, it works.
                    d.continueTurnAddDate(); //Will increase by 1.
                    playersArray[x].setCurrentDate(d);
                    playersArray[x].setPlayerHealth(playersArray[x].getPlayerHealth(), 0, 100);
                }
            }
        }
    }
}

int Game::alivePlayerCounter() //Will start at a value of 5 and decrement for how many dead players there are.
{
    for (int x = 0; x < 5; x++)
    {
        if (playersArray[x].getAlive() == false)
        {
            playerCount--;
        }
    }
    return playerCount;
}
