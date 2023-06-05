/*Final Project Rubric
Final Project Rubric
Criteria

Loop 20 pts Uses multiple loops check

Conditional 20 pts Uses multiple conditionals check

Function 20 pts Uses multiple non-class based functions  check

Class/Object 20 pts Makes proper use of at least one Class with resulting Objects what to do for this one?

Array or Vector 20 pts Uses multiple arrays or vectors check

Conforms to initial project plan 10 pts Submission is clearly linked as the end result of the initial Project Plan maybe 

Evaluation of Quality 80 pts High Quality Work hopefully

Turned in Correctly 10 pts Full Marks*/

// based on Feral people HUNT teen hiker by MrBallen. https://www.youtube.com/watch?v=Vx6YxG8SD_A&t=1644s
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

//Multiple funtions not in a class
    //func for start
    bool beginning();
    //func to continue story
    bool yesContinue();
    //introduction
    bool introduction();
    //int passmiles(MilesHIKED, int);
    //second intro first choice
    bool secondinto();
    //main story line start
    void mainStory();
    //continue main story
    void mainStoryContinued();
    //second choice splits story line.//results in first ending
    bool secondNight();
    void firstEnding(); //#1 ending
    //start of third night
    void newforest();
    bool thirdNight();
    void secondEnding(); //#2 ending
    //escape sequence
    bool escape(int es[]);
    //did not escape ending
    void didnotEscape(); //#3 ending
    //last ending with survival
    void lastending(); //#4 ending

// to count endings
    void showContents(fstream&);
    bool openFileIn(fstream&, string);
    bool createFile(fstream&, string);

    void addending(int);

//class function
    class MilesHIKED
    {
    public:
        //variable storage
        int beginningmiles;
        string name;
        int speed;
        int milestogo;
        int averagemiles;
        int dayslefttogo;
   

        //variable assignment
        void setBEGIN(int);
        void setNAME(string);
        void setSPEED(int);
        void setMilestoGO(int);

        void averageMilesHiked();
        void daysLeft();
        //display
        void Display();




    };

    //set variables accessors
    void MilesHIKED::setBEGIN(int y)
    {
        beginningmiles = y;

    }

    void MilesHIKED::setSPEED(int s)
    {
        speed = s;

    }

    void MilesHIKED::setNAME(string t)
    {
        name = t;

    }

    void MilesHIKED::setMilestoGO(int t)
    {
        milestogo = t;

    }

    void MilesHIKED::averageMilesHiked()
    {
        //walking for an average of 10 hours a day
        averagemiles = speed * 10;
        
    }
    void MilesHIKED::daysLeft()
    {
        dayslefttogo = milestogo / averagemiles; 
    }
    //display
    void MilesHIKED::Display()
    {

        cout << "Miles Hiked\n";
        cout << "****************\n";
        cout << "Name " << this->name << endl;
        cout << "Miles Hiked:"<< this->beginningmiles << " miles\n";
        cout << "Starting miles per hour: " << this->speed << endl;
        cout << "Average miles per day: " << this->averagemiles << endl;
        cout << "Estimated Days to go: " << this->dayslefttogo << endl;
        cout << "****************\n\n\n";

    }




int main()
{
    cout << "Hello World!\n";
        
    //correct answers
    int ending1 = 0;
    int ending2 = 0;
    int ending3 = 0;
    int ending4 = 0;

    // array for keeping number of endings
    int endingsfound[100];

    fstream dataFile;//to input file
    string input;


    if (openFileIn(dataFile, "endings.txt"))
    {

        cout << "File opened successfully\n";

        if (dataFile)
        {
            //for loop to read data
            for (int i = 0; i < 100; i++)
            {
                // inputFile >> correctExam[i];
                dataFile >> endingsfound[i];
                //dataFile.get(array[i]);
            }

            //add endings together
            for (int j = 0; j < 100; j++)
            {
                if (endingsfound[j] == 1)
                {
                    ending1++;
                }
                if (endingsfound[j] == 2)
                {
                    ending2++;
                }
                if (endingsfound[j] == 3)
                {
                    ending3++;
                }
                if (endingsfound[j] == 4)
                {
                    ending4++;
                }
                                
            }
            //tell user how many of each ending he/she has found
            cout << "You have found ending 1 out of 4: " << ending1 << " times.\n";
            cout << "You have found ending 1 out of 4: " << ending2 << " times.\n";
            cout << "You have found ending 1 out of 4: " << ending3 << " times.\n";
            cout << "You have found ending 1 out of 4: " << ending4 << " times.\n";

            //close file
            dataFile.close();
        }

    }
    else
    {
        cout << "File open error.\n";

    }
    //call class
    MilesHIKED user;
    int miles = 0;
    string name;
    int fast;
    // to start game
    if (beginning())
    {
        cout << "start it already\n"; //this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
        cout << "What is your name?";
        cin >> name;
        cout << endl << endl;
        user.setNAME(name);
    }
    else
    {
        cout << "quit\n";//this could probably be edited out but I didn't
        return 0;
    }

    cout << "so it begins\n";//this could probably be edited out but I didn't
    if (introduction())
    {   
        
        
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
        cout << "How many miles per hour do you hike? If you don't know, give an approximation. ";
        cin >> fast;
        cout << endl << endl;
        user.setSPEED(fast);
        user.setMilestoGO(160);
        user.setBEGIN(1600);
        user.averageMilesHiked();
        user.daysLeft();
        user.Display();
        
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    if (secondinto())
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    mainStory();
    if (yesContinue())
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    mainStoryContinued();   
    if (yesContinue())
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    if (secondNight())
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    newforest();
    if (yesContinue())
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
        user.setMilestoGO(100);
        user.averageMilesHiked();
        user.daysLeft();
        user.Display();
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    if (thirdNight())
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
    }
    else
    {
        cout << "end game";//this could probably be edited out but I didn't
        return 0;
    }
    //escape array left left right left // #1 array
    int es[4] = { 1, 1, 2, 1 };
    if (escape(es))
    {
        cout << "continue\n";//this could probably be edited out but I didn't
        cout << "************************************************************************************************************\n\n";
    }
    else
    {
        cout << "end game";
        return 0;
    }
    lastending();
    cout << "end game";
    return 0;

}

//validation for start successfullly
bool beginning()
{
    char start = 0;
    bool status;
    while (start != 'y' && start != 'Y' && start != 'q' && start != 'Q')
    {
        cout << "Would you like to start the story? Y for yes. Q for quit. ";
        cin >> start;
        if (start == 'y' || start == 'Y')
        {
            status = true; // to continue story
        }
        if (start == 'q' || start == 'Q')
        {
            status = false; // to quit
        }
    }
    return status;

}

bool yesContinue()
{
    char start = 0;
    bool status;
    while (start != 'y' && start != 'Y' && start != 'q' && start != 'Q')
    {
        cout << "Would you like to continue the story? Y for yes. Q for quit. ";
        cin >> start;
        if (start == 'y' || start == 'Y')
        {
            status = true; // to continue story
        }
        if (start == 'q' || start == 'Q')
        {
            status = false; // to quit
        }
    }
    return status;
}

bool introduction()
{
    cout << "You are an experienced hiker and are walking along"
            "a famous hiking Trail in California. It is the summer after you graduated high school, "
            "and you wanted to do a long hiking trip alone before you started university in the fall. "
            "You have been walking every day for the last few weeks and by your maps you estimate "
            "that you only have 160 miles to go before you reach the end of the trail.You are content "
            "with your progress and even though it has been lonely,you are proud with how far you’ve come.  "
            "You can’t wait to see your family at the end of the trail.\n\n";
    cout << "You passed the last town about five days ago where "
            "you had gathered supplies for the next leg of the journey. You estimate you should be at the next town "
            "in about six days. You don’t see many people walking along this trail, in fact, you and other hikers who "
            "walk this trail usually don’t see another person for days. You yourself haven’t seen a person since you "
            "visited the last town for supplies.\n\n";

    if (yesContinue())
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool secondinto()
{
    char choice;

    cout << "The Trail alternates between areas with large, dense trees and wide-open areas"
        "where you can see for a long way in most directions. As you come around a bend in the dirt trail in a forested area, "
        "you notice two people sitting on a large boulder.\nNot seeing many people on the trail, you wave at them. "
        "They do not wave back.\n"
        "As you get closer you see that both people, a man and a woman are dressed from head to toe in white. An odd color "
        "to see in the mountains on hikers. The two people look dirty, and the man has a long beard. You think that they may "
        "not have seen you the first time\n\n"
        "Do you wave at them again? Y for yes. N for no\n";
    cin >> choice;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        cout << "Do you wave at them again? Y for yes. N for no.\n";
        cin >> choice;

    }
    if (choice == 'y' || choice == 'Y')
    {
        cout << "You wave again.Again, they do not wave back, and you notice that they are glaring as you get closer. "
            "You call out a helloand they do not respond. They continue to glare at you.The situation makes you feel uncomfortable, "
            "and awkwardly you continue faster down the Trail.\nYou don’t want to look back because you know they are staring daggers at you. ";
            if (yesContinue())
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    else
    {
        cout << "You don't wave again. You notice that they are glaring as you get closer.\n"
            "You call out a hello and they do not respond.They continue to glare at you. The situation makes you feel uncomfortable, "
            "and awkwardly you continue faster down the Trail. You don’t want to look back because you know they are staring daggers at you.\n";
        if (yesContinue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

void mainStory()
{
    cout << "As you continue down the Trail and start to notice the beauty around you again, "
        "you start to get less uncomfortable and more irritated. Why didn’t they at least wave? "
        "How rude they didn’t even react? As you walk a little more, you start to think that you really didn’t know those people "
        "or their story. Maybe they were foreign and didn’t understand what you said and that is why they didn’t say hello.\n"
        "In any case, it is none of your business and so you carry on.\n\n";
    cout << "A few hours later, the sun is going down. You look for a place to make a campsite. "
        "Because the trees are so densely populated, you can’t make your camp by the Trail or else you would completely block the Trail. "
        "So, you walk a few hundred feet off the Trai nuntil you find a little clearing and there you set up your camp. You put up your tent "
        "and you make some dinner on your tiny camp stove. Afterwards, you tie a cord to your waterproof food bag with most of the food "
        "you have with you, and you walk towards a tree near your tent. Then you throw your food over a branch of the tree. "
        "This is something you have done every night to make sure nighttime creatures don’t get into your food. Then you go to your tent and sleep.\n\n";
    cout << "When you wake up, the sun is just starting to rise. "
        "You climb out of your tent and the first thing you notice is that your bag of food is gone. Did a bear take it? you wonder. "
        "You didn’t hear anything while you slept. You walk over to the tree, but it is not there. As you walk closer to the tree "
        "you notice something disturbing. There are tracks around the tree. "
        "They are two sets of HUMAN bootprints and neither of them are yours. "
        "Then you notice that these bootprints are not just by the tree, they are all over your camp including around your tent.\n\n";
    cout << "You wonder how this can be happening!\n"
        "Those two people had followed you down the trail and then watched where you had gone off to make your camp. "
        "They must have waited for you to fall asleep to sneak silently into your camp to rob you. "
        "You realize that they could still be watching you, so you look around. "
        "You don’t see anyone, but you get a feeling like you are being watched.\n\n";

}
void mainStoryContinued()
{
    cout << "You pack up your campsite and quickly walk towards the Trail.\n"
        "You imagine someone grabbing you from behind or you will find someone behind a tree. As soon as you get to the Trail "
        "you look back and forth and don’t see anyone. You take a deep breath, hope they are gone and continue to walk down the trail.\n\n";
    cout << "As you walk that day, you occasionally look over your shoulder.\n"
        "Eventually the trail opens into a large open area. You can see in all directions, and you can feel the sunshine on your face and arms. "
        "The area is beautiful, and you start to relax. You think to yourself that as bad as it is to contemplate that those people snuck up on you "
        "and stole your food, perhaps they needed it more than you do. If they need food that badly then they can have it. "
        "You think that now that they have your food, that you probably won’t have to deal with the people in white ever again.\n\n";
    cout << "For the next three days, you continue hiking the Trail through the forest.\n"
        "The trail weaves through dense trees and open areas. Every night as a precaution, you set up a perimeter around the area of your campsite "
        "with sticks and leaves. These sticks will snap if anyone steps on them and so you will hear if any animal or any person sneaks up on you "
        "during the night.\n\n";
    cout << "On the fourth day, you are walking in a densely forested area when it starts to get dark. "
        "You walk several hundred feet off trail to a little clearing to set up camp. You set up the perimeter around the area of your campsite "
        "with sticks. After that, you have dinner. After eating, you climb into your tent, into your sleeping bag and fall asleep.\n\n";
   
}

bool secondNight()
{
    cout << "A few hours later, you wake up suddenly in your tent. It is so dark within your tent, you can’t see your hand in front of your face. You stare at nothing. You listen very carefully. An instant later, you hear the distinct sound of something stepping on one of the sticks around the perimeter. Your heart starts to race. Something is only a few feet away from you.\n\n";
    cout << "You slowly pull your arm out of your sleeping bag and reach for your hunting knife. As you grab it and pull it towards you, you hear more footsteps. Whatever is out there doesn’t care about the sound it's making and you can hear it coming closer to your tent. You realize it could be an animal but just three days ago, two people were stalking around your campsite. You lay back down tense, thinking that at any moment you will need to slash out with the knife. The sound of footsteps come closer and closer until they are a foot away from your head. Then you start to hear whispering. The whispering is not coming from the person standing by your head, it is coming from every direction in the forest around you. The whispering becomes more and more frantic. The person that was standing by your head starts circling your tent.\n\n";
    cout << "You are terrified.\n\n";
    cout << "The person walks slowly all around your tent then when he almost reaches the place where he was standing before, all you hear is sudden silence. The footsteps stop. The whispers stop.\n\n";
    cout << "You are frozen in fear. What you want to hear is the footsteps retreating back into the forest. Leaving you behind. You don’t hear anything though, so you think that the person who was walking around your tent must still be out there.\n\n";
    cout << "Do you want go see if the person or persons are out there right now? Y for yes. N for no.\n";
    char choice;
    cin >> choice;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        cout << "Do you want go see if the person or persons are out there right now? N for no.\n";
        cin >> choice;

    }
    //first ending with death
    if (choice == 'y' || choice == 'Y')
    {
        firstEnding();
        return false;
    }
    //carry on with main story
    else
    {
        cout << "You lay like that the rest of the night until the sun comes out the next morning. Are they still out there? You wonder.\n";
        if (yesContinue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

void firstEnding()
{
    cout << "Full of adrenaline and scared out of your mind you jump out the tent and start yelling at these people to get away from you. You stop to take another breath and in that moment you hear a stick break right behind you. As you turn to look at what is behind you, you are grabbed from behind by a huge man in a bear hug. You start screaming at the top of your lungs and you are frantically waving your knife around. You think you might have connected with something but you are so scared you aren’t sure. You try to ram the back of your head into the man's face but he is taller than you. You do feel bits of beard on the back of your neck. In a few seconds, the man wrestles you to the ground and he has taken the knife from you. You have lost all control and now lay panting.\n\n";
    cout << "The whispers in the forest get louder. Soon you hear a woman chanting. When she turns on the flashlight for just an instance you can see that she is wearing dirty white clothes. The last thing you see is her kneeling above you before you are hit very hard in the head and everything goes dark.\n\n";
    cout << "Your family will search for you but finding no trace eventually they have to give up. You are never found.\n\n";
    cout << "Ending 1 out of 4\n\n";
    addending(1);
}

void newforest()
{
    cout << "You decide now that it is light outside you must see. With your hunting knife in one hand, you quickly unzip the tent flap with the other. You don’t see anyone. You hurriedly jump out the tent ready to confront anyone you didn’t see. There is no one there. You look all around your campsite expecting a person dressed in white to be around a bend of trees. You still don’t see anyone.\n\n";
    cout << "How could that have happened? You feel like last night occurred in some nightmare, however you know that can’t be true because as you were looking around your campsite, you also noticed the clear set of boot prints that had circled your tent the night before. \n\n";
    cout << "You quickly pack up your campsite and start running. You run back toward the trail. You look around. You then keep running down the trail. You think to yourself, I just need to get out of this national forest. I need to get away from here. \n\n";
    cout << "The whole day, you move as quickly as you can. Running when it is possible and by early evening you reach one of the little towns that are close to the edge of this forest. That night you sleep right outside this little town, wanting to be as close to civilization as possible. \n\n";
    cout << "As you lay there you think that the people in white you saw that day on the boulder have to be behind these nighttime occurrences. The first one, you can understand. They followed you for a little while and stole your food. But the second time you still don’t understand how they could have followed you without you noticing. You were very observant and were consistently looking behind you. It means they would have followed you for days and tracked you to your campsite in the dark. Also what was behind all the whispers and why didn’t you hear footsteps retreating?\n\n";
    cout << "You wake up the next morning and pack up your camp. It does occur to you that you could stop right now. You could call your family to come and get you. However, this hike is really important to you. Plus, you are close to the end with only 100 miles left. You have walked over 1600 miles already and you do not want to quit.\n\n";
    cout << "That day you leave the little town behind and walk into another forest. This new forest is a lot like the forest you were just walking in for the last few days. Little do you know, that this new forest is known for many disappearances and many of them go missing under baffling circumstances.\n\n";
    cout << "You make it your goal to walk as far as you possibly can. \n\n";

}
bool thirdNight()
{

    cout << "You walk for three days. On the fourth day, you find yourself on an open part of the trail that is on the side of a mountain. Because it is higher on the mountain there are few trees to shield your view. You can see miles ahead of you and miles behind you. Around midday, as is your custom, you look behind you.\n\n";
    cout << "This time you look, you see two little white dots miles and miles back. You can see that they are making good time walking up the same Trail you are. They have to be the people in white. At this point, you are at least fifty miles past where you first encountered the people in white, which means they are most certainly responsible for the night time occurrences. For some reason, they are still following you. \n\n";
    cout << "You suddenly don’t care about finishing the hike at all. You just want to get home and away from these people. You quickly pull out your map and to your horror, you realize you are in one of the most isolated portions of the entire hike. You are at least 25 miles away from the nearest town. Without much choice, you put the map in your pocket. You look at the people in white again slowly gaining on you. Then you turn around and start running as fast as you can down the trail. You run for hours and hours without stopping. You don’t stop when you don’t see the people behind you anymore. You don’t stop when the sun is going down.\n\n";
    cout << "You finally have to stop when you can’t see the ground in front of you because it is too dark outside. You then make your way from the trail. You walk hundreds of feet deep into the forest.\t\t";
    cout << "You set up your tent in a small clearing and make your perimeter. You climb inside your tent, but keep all of your clothes on. You wait without the expectation that you will sleep. As time wears on, you start to get sleepy. After all, you have been running all day.\n\n";
    cout << "As you start to doze off, you hear someone stepping on your perimeter. Immediately after it breaks, you again hear the whispering from the forest all around you. Before you can do anything, someone shines a light on your tent. Then they click off the light and the whispering stops. \n\n";
    cout << "Full of adrenaline and scared out of your mind, you grab your knife and you jump out the tent and start yelling at these people to get away from you. You stop to take another breath and in that moment you hear a stick break right behind you. As you turn to look at what is behind you, you see out of your peripheral vision a dark figure running toward you.\n\n";
    cout << "Do you attack the man? Y for yes, N for no.\n";
    char choice;
    cin >> choice;
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
        cout << "Do you want go see if the person or persons are out there right now? N for no.\n";
        cin >> choice;

    }
    //third night ending with death
    if (choice == 'y' || choice == 'Y')
    {
        secondEnding();
        return false;
    }
    //carry on with main story
    else
    {
        cout << "You don’t have to think about it. You start running away from the campsite.\nThe forest is pitch black and trees are everywhere. You are running into trees and branches\n";
        if (yesContinue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }


}
void secondEnding()
{
    cout << "Your instincts kick in. The man is in a fast full run. When he gets close you slide to your right nearer to the edge of the clearing and at the same time try to reach out your foot to trip him. The man doesn’t trip but he does end up running right past you. He slows down immediately and you follow him and stab him with your knife while his back is turned. You notice that he is taller than you.\n\n";
    cout << "Unfortunately, your luck is running out. Despite being fairly athletic, you have never been in a fight before. The man turns around quickly and you see that he has a long beard. The knife wound seems to have done nothing. The man pulls back his fist and although you try to dodge you are too slow. You are knocked to the ground. He attacks you and starts to punch you in the face over and over. You eventually black out.\n\n";
    cout << "Your family will search for you but finding no trace eventually they have to give up. You are never found.\n\n";
    cout << "Ending 2 out of 4\n\n";
    addending(2);

}

bool escape(int es[])
{
    int array[4]; //#2 array 
    char firstchoice;
    char choice;
    int correct = 0;
    cout << "You must choose the direction that you wish to go to get away from the people in white.\n"
        "L for left; R for right\n"
        "Choose carefully.\n\n";

    for (int index = 0; index < 4; index++)
    {
        cout << "L or R: ";
        cin >> firstchoice;
        while (firstchoice != 'l' && firstchoice != 'L' && firstchoice != 'r' && firstchoice != 'R')
        {
            cout << "L for left; R for right\n";
            cin >> firstchoice;
        }
            if (firstchoice == 'l' || firstchoice == 'L')
            {
                array[index] = 1;
            }
            else
            {
                array[index] = 2;
            }
   
    }
    for (int ind = 0; ind < 4; ind++) //compare arrays
    {
        if (array[ind] == es[ind])
        {
            correct++;
        }

    }

    if (correct == 4)
    {
        cout << "You stumble and fall right in front of a tree that had fallen over a rock. The tree and rock are positioned to where you can squeeze in between them.\n";
        cout << "Do you hide there? Y for yes. N for no.\n";
        cin >> choice;
        //carry on with main story
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            cout << "Do you want go see if the person or persons are out there right now?  Y for yes. N for no.\n";
            cin >> choice;

        }
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Thinking quickly, you hide there.\n"
                    "In the distance you can see a light bobbing around.These people are looking for you in the forest.You watch as they move closer and closer but they do not find you.\n\n";

                if (yesContinue())
                {
                    return true;
                }
                else
                {
                    return false;
                }
          
            }
            //not choosing to hide under the tree.
            else
            {
                cout << "second return\n";
               
                didnotEscape();
                return false;

            }


    }
    //not getting all directions correct
    else
    {
        cout << "first return\n";

        didnotEscape();
        return false;
    }
}

void didnotEscape()
{
    cout << "You look back and don’t see anyone. You are hoping you have lost them. Just then you trip over another log, however your foot is caught in it. As you fall, your leg breaks. The pain is absolutely excruciating and you almost pass out.\n\n";
    cout << "Adrenaline keeps you awake. You try to look to see where your foot is caught in the log but it is so dark you can’t see much of anything. You try to sit up but your leg is at an awkward angle. You shimmy around, gritting your teeth against the pain. You reach up, grab your ankle and with a big tug, your leg comes loose. Because your balance is off, when your leg springs free, it comes crashing down on the ground beside you. The pain is too much and you black out.\n\n";
    cout << "When you wake up, you are being dragged on the ground. You look up. You see a woman in dirty white clothes. The moment you look up and she sees you are awake, she grins a toothless grin and starts to sing. You immediately try to move your arms and legs to get out of the grip of whoever’s holding you. The person lets go and you drop on your side.\n\n";
    cout << "You try to stand up but with your broken leg and pain, you can't do it . You try to quickly find your balance on one leg. As soon as you think you can continue, you are tripped and you fall on your back. The man is on top of you and you are trying to fight him off. For a split second you see the dirty, toothless grinning face of the woman. She is holding something above her head. Is that a tree branch? She swings it down at your head and everything goes black.\n\n";
    cout << "Your family will search for you but finding no trace eventually they have to give up. You are never found.\n\n";
    cout << "Ending 3 out of 4\n\n";
    addending(3);
}

void lastending()
{
    cout << "In the distance you can see a light bobbing around. These people are looking for you in the forest. You watch as they move closer and closer but they do not find you.\n\n"
        "You stay under the log the rest of the night, into the morning until it is early afternoon. You slowly crawl out and look around but you don’t see anyone.\n\n"
        "Instead of going back to your campsite and getting your gear, you abandon it. You think that those people last night might still be there waiting for you. \n\n"
        "You run away from your campsite back out to the trail. Once on the trail you continue to run all the way to the next town. \n\n"
        "Once in the town you tell the police about your experience. They write it down and get a hotel room for you to stay in for the night. The next day your family comes to get you to take you back home.\n\n"
        "Months later, you call the police and ask for an update. They tell you that even though people have reported food being stolen from their camps, no one else has reported being terrorized. To this day, you still have no idea why those two people in white were following you\n\n";
    cout << "Ending 4 out of 4\n\n";
    addending(4);
}

bool openFileIn(fstream& file, string name)
{
    file.open(name, ios::in);
    if (file.fail())
        return false;
    else
        return true;
}

bool createFile(fstream& file, string name)
{
    file.open(name, ios::out | ios::app);
    if (file.fail())
        return false;
    else
        return true;
}

void showContents(fstream& file)
{
    string line;
    while (file >> line)
    {
        cout << line << endl;
    }

}

void addending(int number)
{
    fstream inFile;//to output to a file

    //open studentanswer file to put in recently aquired student information
    if (createFile(inFile, "endings.txt"))
    {

        cout << " endings opened successfully\n";

        if (inFile)
        {
            inFile << number;
            inFile << endl;
            //close file
            inFile.close();
        }

    }
    else
    {
        cout << "File open error.\n";

    }
}