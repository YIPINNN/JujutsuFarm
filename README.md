# CPT113 Hackthon 2 Jujutsu Farm

## Description of the game
Jujutsu Farm, a relaxing farming simulation game in which players begin on an exciting agricultural adventure. In this fascinating environment, players are responsible for growing abundant crops and rearing a wide variety of adorable animals. In the Jujutsu Farm, players can plant crops such as corn, tomatoes, potatoes, paddy, and soybeans. Players also can rear animals such as chickens, cows, sheep and fish to get animal products which are eggs, milk, wool and fish. There are many levels created in the game. In order to complete each level, players need to complete the order given in each level. Players are only able to complete the order given at every level when they have enough amount of crops and animal products in the inventory of their farm. When each level is completed, a certain amount of coins can be earned. 


## Features of the game
Planting Crops: Players can grow a variety of crops such as corn, tomatoes, potatoes, paddy, and soybeans. Each planting of seeds will harvest 5 crops.

Rearing Animals: Players can raise animals like chickens, cows, sheep, and fish. These animals will turn into valuable animal products such as eggs, milk, wool, and fish. For example 1 chicken can produce 5 eggs.

Level System: The game includes multiple levels, each with its own set of objectives. To progress to the next level, players must complete the given orders. These orders may involve specific crops or animal products that need to be harvested or produced.

Inventory Management: Players need to manage the storage of crops and animal products. To fulfill the orders at each level, players must ensure they have enough resources available. Managing the inventory effectively becomes crucial for progressing in the game.

Coins and Rewards: Completing each level rewards players with a certain amount of coins.


## How to play the game
First, players need to enter their names. Next, players need to enter if are they ready to start their farming journey. If players are ready, players are able to choose the task they want to do among the menu list which are 1. Plant new crops and rear new animals, 2. Complete customers' order, 3. Check inventory, 4. Check the amount of coins earned, 5. Quit. 

In choice number 1. Plant new crops and rear new animals. Players need to enter the keyword plant to plant new crops and enter the keywords rear to rear animals to get the animal products. 

In choice number 2. Complete customers' order. Each order will involve a specific amount of crops and animal products. Hence, players need to ensure that they have enough crops and animal products in their inventory to complete the order. Each level of the game is completed when players complete each order. After complete the order, the left amount of crops or animal products will be updated in the inventory.

In choice number 3. Check inventory. Players are able to check the available storage of every crop and animal product by checking their inventory.

In choice number 4. Check the amount of coins earned. While every order given is completed, players are able to earn a certain amount of coins. The total amount of coins earned for all level are calculated and stored here.

In choice number 5. Restore the game progress. It will restore the previous game progress from txt file.

In choice number 6. Quit. Players can quit the game by selecting choice number 5. All the progress of the game including the latest amount of inventory, incomplete order and total coins earned.


## How object-oriented concepts were used to develop the game.
In Jujutsu Farm, the composition is the primary mechanism for building the game's entities and structures. 

For example:
plantAndRear Class: The "plantAndRear" class is the core class of Jujutsu Farm which represents how the player's farm works. The "plantAndRear" class is composed of various objects that collectively create the farm's functionality and structure. The "planAndRear" class is composed of these various objects, allowing for a flexible and modular design.

PlantStack Class: The "PlantStack" class encapsulates properties and behaviors specific to each type of crop, such as the total amount harvested of crops and display the amount of harvested crops. Instances of the "PlantStack" class such as "Corn", "Paddy", "Soybean", "Tomato" and "Potato" are composed within the "plantAndRear" class to represent the different crops grown on the farm. Each object created is represented as one stack of that specific type of crop.

AnimalProduct Class: The "AnimalProduct" class encapsulates properties and behaviors specific to each type of animal product, such as the total amount of animal products and display of the amount of animal products. Instances of the Animal class are composed within the Farm class to represent the animals reared on the farm. Each object created is represented as one queue of that specific type of animal's product.


## How linked lists/stacks/queues play a role in the game.
**Stack is used in a class called "PlantStack".** 

**In "PlantStack" class, stack is used to store and manage the number of crops.**
1. Stack Constructor and Destructor:
   - The constructor PlantStack::PlantStack() initializes the stack by setting the stackTop pointer to nullptr, indicating an empty stack.
   - The destructor PlantStack::~PlantStack() is responsible for freeing the memory allocated to the stack nodes. It iterates through the stack and deletes each node until the stack is empty.

2. Push and Pop Operations:
   - The PlantStack::push(int n) function adds a new plant count to the top of the stack. It creates a new stack node and assigns the numPlant to it. Value of n is push into the stack.
   - The PlantStack::pop(int &n) function removes the top numPlant from the stack and returns it through the reference parameter n. It updates the stack pointers and deletes the previous top node.

3. Stack State and Display:
   - The PlantStack::isEmptyStack() const function checks if the stack is empty by examining the stackTop pointer. It returns true if the stack is empty else false.
   - The PlantStack::displayStack() function iterates through the stack and displays the numPlant stored in each node.

4. Stack Operations:
   - The PlantStack::countHarvest() function calculates the total harvest by traversing the stack and summing up the numPlant. The total harvest is stored in the totalHarvest variable.
   - The PlantStack::clear() function is used to delete all stack nodes.
   - The PlantStack::setTotalHarvest(int t) function sets the value of the total harvest.
   - The PlantStack::getTotalHarvest() function retrieves the total harvest value.
   - The PlantStack::subtract(int amt) function subtracts the specified amount (amt) from the top numPlant in the stack.
   - The PlantStack::compare(int amt) function compares the specified amount (amt) with the sum of the numPlant in the stack and returns the difference.
   - The PlantStack::stackTop_value() function returns the value of the numPlant stored in the top node of the stack.

**Queue is used in classes such as "AnimalProduct" and "Order".**

**In "AnimalProduct" class, queue is used to store and manage the number of animal products in the game.**
1. Queue Constructor and Destructor:
   - The constructor AnimalProduct::AnimalProduct() initializes the queue by setting the front and rear pointers point to nullptr, indicating an empty queue. The numItems variable is set to 0.
   - The destructor AnimalProduct::~AnimalProduct() is responsible for freeing the memory allocated to the queue nodes. It calls the clear() function to dequeue and delete each node until the queue is empty.

2. Enqueue and Dequeue Operations:
   - The AnimalProduct::enqueue(int n) function adds a new animal productNum to the rear of the queue. It creates a new queue node, assigns the productNum to it, updates the pointers, and increments the numItems variable.
   - The AnimalProduct::dequeue(int &n) function removes the front animal productNum from the queue and returns it through the reference parameter n. It updates the front pointer, deletes the previous front node, decrements the numItems variable.

3. Queue State and Display:
   - The AnimalProduct::isEmpty() const function checks if the queue is empty by examining the numItems variable. It returns true if the queue is empty else false.
   - The AnimalProduct::displayProduct() function iterates through the queue and displays the animal productNum stored in each node.

4. Queue Operations:
   - The AnimalProduct::countProduct() function calculates the total number of animal products by traversing the queue and summing up the productNum. The number of total product is stored in the totalProduct variable.
   - The PlantStack::clear() function is used to delete all queue nodes.
   - The AnimalProduct::setTotalProduct(int t) function sets the value of the totalProduct.
   - The AnimalProduct::getTotalProduct() function retrieves the value of totalProduct.
   - The AnimalProduct::subtract_2(int amt) function subtracts the specified amount (amt) from the front of productNum in the queue.
   - The AnimalProduct::front_value() function returns the value of the productNum stored in the front node of the queue.
   - The AnimalProduct::compare_2(int amt) function compares the specified amount (amt) with the sum of productNum in the queue. When the amount in the first node of the queue is less than the specified amount needed for the order (amt), this function will sum up the value of the previous node with the next node until the amount is bigger than the specified amount then return the difference.

**In "Order" class, queue is used to manage orders in the game.**
1. Queue Constructor:
   - The constructor Order::Order() initializes the queue by setting the front and rear pointers to nullptr, indicating an empty queue. The numItems variable is set to 0.

2. Input File:
   - The Order::inputFile() function reads order data from an input file (inputFile.txt) and appends the orders to the rear of the queue. Each order consists of a level, the amount of crops or animal products needed and the total coin earned. 
     
3. Append Operation:
   - The Order::append(int l, int c, string t, int a) function adds a new order to the rear of the queue. It creates a new node, assigns the level, the amount of crops or animal products needed and the total coin earned to it then updates the queue and increments the numItems variable.

4. Dequeue Operation:
   - The Order::displayOrder() const function displays the details of the front order in the queue. It prints the details of the order. If the queue is empty, it displays a message indicating no order available.

5. Print to File:
   - The Order::printToFile() function writes the latest order data from the queue back to the input file (inputFile.txt). It iterates through the queue, retrieves the order details, and writes them to the file. Hence, the progress of the order can be saved.

6. Order Processing:
   - The Order::calculate() function calculates the total coins earned by adding the coin earned of every order to the totalCoinEarned variable.
   - The Order::deleteNode() function deletes the front order from the queue after calculating the coins earned. It updates the front pointer, deletes the previous front node and decrements the numItems variable.

7. Financial Information:
   - The Order::displayfinancial() function returns the total price which is the total coin earned.

8. Queue State:
   - The Order::isEmpty() const function checks if the queue is empty by checking the numItems variable. It returns true if the queue is empty else returns false.

9. Order Details Retrieval:
   - The Order::getTask() function retrieves the first task of the front order in the queue and returns it as a string.
   - The Order::getAmount() function retrieves the first amount of the front order in the queue and returns it as an integer.
   - The Order::getTask1() function retrieves the second task of the front order in the queue and returns it as a string.
   - The Order::getAmount1() function retrieves the second amount of the front order in the queue and returns it as an integer.


## Screenshot of the game

![JF1](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/d0b41ef7-f42c-4f1c-bdaf-ef6f5b99b677)
![JF2](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/ec4ed083-7a5d-4dca-99fc-9970e2ad890f)
![JF3](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/85c7fb15-d015-425a-960e-058b277a38b6)
![JF4](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/0cc6c586-2fb1-4372-a631-5fa074a5ff2e)
![JF5](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/598cca59-70c8-4671-9ac1-394a77674053)
![JF6](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/8abbd785-2a18-4a5a-8084-e43b7239770b)
![JF7](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/386f0f23-2c8b-4bd2-89fe-e06168a10a60)
![JF8](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/a6fdbe50-048a-4717-a3bf-7f73a75f5bfe)
![JF2 1](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/5ffea754-a4d5-4eb0-8040-148d2431832f)
![JF2 2](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/04cf7ff4-0147-475d-8454-74e61a8bd0e3)
![JF2 3](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/03ecaa1b-7f28-4bfc-958c-15c2e3f18372)
![JF2 4](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/4dfadb9d-2720-4458-a77a-1fe15ba1eb44)
![JF2 5](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/4116439a-cfc5-4cb2-b158-757ea2064cdb)
![JF2 6](https://github.com/YIPINNN/JujutsuFarm/assets/116947179/c6554b63-72f2-4176-b033-ecb5d1561e1f)


## Link to the game  demo video
https://drive.google.com/file/d/1r1M-EYQWLQ7xY2GelK43swRq_uYYsSdP/view?usp=sharing
