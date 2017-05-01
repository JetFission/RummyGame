private:
	vector<Card> deck;
	Card c;//used as an intermediary
	vector<Card> set; //stores sets belonging to both person and computer
	vector<Card> temp; //used to temporarily hold Card objects
	int deadPoints; //used to keep track of the deadwood points for both player and computer

public:
	void printSet(); //testing 
	void printCard(); //used to print a single card
	int getSizeOfStock(); //returns the size of the stock 
	void shuffle();
	void addCard(Deck& card);
	void addCardFromSpot(Deck& card, int place); //used to add a card from anywhere in the vector
	void deleteCardFromSpot(int place); //gets rid of card at a certain position 
	void populateDeck();
	void dealHands(Deck&, Deck&); //initializes both the computers and players decks with 10 cards each
	void deleteDeck(); // called only once. used to delete 10 cards from the deck
	void printHand(); //used to verify stuff
	void printDeck();
	void scanSet(); //checks hand for sets
	void deleteCard(); //used to only delete one card
	int calculateDeadwood(); //used to get the deadwood score after each turn
};

#endif
