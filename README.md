# Jujutsu Farm CPT113 Hackthon 2

## Description of the game
Jujutsu Farm, a relaxing farming simulation game in which players begin on an exciting agricultural adventure. In this fascinating environment, players are responsible for growing abundant crops and rearing a wide variety of adorable animals. In the Jujutsu Farm, players can plant crops such as corn, tomatoes, potatoes, paddy, and soybeans. Players also can rear animals such as chickens, cows, sheep and fish to get animal products which are eggs, milk, wool and fish. There are many levels created in the game. In order to complete each level, players need to complete the order given in each level. Players are only able to complete the order given at every level when they have enough amount of crops and animal products in the inventory of their farm. When each level is completed, a certain amount of coins can be earned. 

## Features of the game
Planting Crops: Players can grow a variety of crops such as corn, tomatoes, potatoes, paddy, and soybeans. Each planting of seeds will harvest 5 crops.

Rearing Animals: Players can raise animals like chickens, cows, sheep, and fish. These animals will turn into valuable animal products such as eggs, milk, wool, and fish.

Level System: The game includes multiple levels, each with its own set of objectives. To progress to the next level, players must complete the given orders. These orders may involve specific crops or animal products that need to be harvested or produced.

Inventory Management: Players need to manage the storage of crops and animal products. To fulfill the orders at each level, players must ensure they have enough resources available. Managing the inventory effectively becomes crucial for progressing in the game.

Coins and Rewards: Completing each level rewards players with a certain amount of coins.

## How to play the game
First, players need to enter their names. Next, players need to enter if are they ready to start their farming journey. If players are ready, players are able to choose the task they want to do among the menu list which are 1. Plant new crops and rear new animals, 2. Complete customers' order, 3. Check inventory, 4. Check the amount of coins earned, 5. Quit. 

In choice number 1. Plant new crops and rear new animals. Players need to enter the keyword plant to plant new crops and enter the keywords rear to rear animals to get the animal products. 

In choice number 2. Complete customers' order. Each order will involve a specific amount of crops and animal products. Hence, players need to ensure that they have enough crops and animal products in their inventory to complete the order. Each level of the game is completed when players complete each order. After complete the order, the left amount of crops or animal products will be updated in the inventory.

In choice number 3. Check inventory. Players are able to check the available storage of every crop and animal product by checking their inventory.

In choice number 4. Check the amount of coins earned. While every order given is completed, players are able to earn a certain amount of coins. The total amount of coins earned for all level are calculated and stored here.

In choice number 5. Quit. Players can quit the game by selecting choice number 5. All the progress of the game including the latest amount of inventory, incomplete order and total coins earned.

## How object-oriented concepts were used to develop the game.
In Jujutsu Farm, the composition is the primary mechanism for building the game's entities and structures. 

For example:
plantAndRear Class: The "plantAndRear" class is the core class of Jujutsu Farm which represents how the player's farm works. The "plantAndRear" class is composed of various objects that collectively create the farm's functionality and structure. The "planAndRear" class is composed of these various objects, allowing for a flexible and modular design.

PlantStack Class: The "PlantStack" class encapsulates properties and behaviors specific to each type of crop, such as the total amount harvested of crops and display the amount of harvested crops. Instances of the "PlantStack" class such as "Corn", "Paddy", "Soybean", "Tomato" and "Potato" are composed within the "plantAndRear" class to represent the different crops grown on the farm.

AnimalProduct Class: The "AnimalProduct" class encapsulates properties and behaviors specific to each type of animal product, such as the total amount of animal products and display of the amount of animal products. Instances of the Animal class are composed within the Farm class to represent the animals reared on the farm.


## How linked lists/stacks/queues play a role in the game.
**Stack is used in a class called "PlantStack".** 

**In "PlantStack" class, stack is used to store and manage the number of crops.**
1. Stack Constructor and Destructor:
   - The constructor PlantStack::PlantStack() initializes the stack by setting the stackTop pointer to nullptr, indicating an empty stack.
   - The destructor PlantStack::~PlantStack() is responsible for freeing the memory allocated to the stack nodes. It iterates through the stack and deletes each node until the stack is empty.

2. Push and Pop Operations:
   - The PlantStack::push(int n) function adds a new plant count to the top of the stack. It creates a new stack node, assigns the plant count to it, and updates the pointers to maintain the stack order.
   - The PlantStack::pop(int &n) function removes the top plant count from the stack and returns it through the reference parameter n. It updates the stack pointers and deletes the old top node.

3. Stack State and Display:
   - The PlantStack::isEmptyStack() const function checks if the stack is empty by examining the stackTop pointer. It returns true if the stack is empty else false.
   - The PlantStack::displayStack() function iterates through the stack and displays the plant counts stored in each node.

4. Stack Operations:
   - The PlantStack::countHarvest() function calculates the total harvest by traversing the stack and summing up the plant counts. The total harvest is stored in the totalHarvest member variable.
   - The PlantStack::setTotalHarvest(int t) function sets the value of the total harvest.
   - The PlantStack::getTotalHarvest() function retrieves the total harvest value.
   - The PlantStack::subtract(int amt) function subtracts the specified amount (amt) from the top plant count in the stack.
   - The PlantStack::compare(int amt) function compares the specified amount (amt) with the sum of the plant counts in the stack and returns the difference.
   - The PlantStack::stackTop_value() function returns the value of the plant count stored in the top node of the stack.

**Queue is used in classes such as "AnimalProduct" and "Order".**

**In "AnimalProduct" class, queue is used to store and manage the number of animal products in the game.**


## Screenshot of the game
![Screenshot 2023-06-21 174056](https://github.com/YIPINNN/JujutsuFarm/assets/117891859/a1110d27-1b20-4c9c-825e-1716e1fcf454)
## Link to the game  demo video
