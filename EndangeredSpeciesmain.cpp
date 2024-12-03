#include "BST.hpp"
#include "Interface.hpp"
#include <iostream>
using namespace std;

void readInTree(BST *tree);

int main() {
	BST *tree = new BST(false);
	Interface interface("PracticeSpecies.txt", false);
	interface.Menu();

	interface.tree->clearTree();

	Interface interface("EndangeredSpecies.txt", false);
	interface.Menu();
	tree->clearTree();

	return 0;
}



void readInTree(BST *tree){
	string animal[] = {"Tiger","Orangutan","Giant Panda","Blue Whale","Asian Elephant","Gorilla","Snow Leopard","Rhinoceros","Sea Turtle","Sea Otter","African Wild Dog","Amur Leopard","Axolotl","Black-footed Ferrets","Chimpanzees","Galapagos Penguins","Golden Lion Tamarins"};
	string threat[] = {"T1","T2","VU","T2","T1","VU","T1","T1","VU","T1","T1","T1","T2","T2","VU","T2","VU"};
	string info[] = {"The tigers are critically threatened.  It's not good.",
			"Orangutans are also in trouble.  Because of the whole habitat loss thing.",
		  "Yep, Giant Pandas are threatened too, although less so now.  They're very cute.",
		   "Blue Whales are in trouble - they eat a lot, they live in the sea, seas are kind of a mess right now.",
		   "These are the elephants with the tiny ears.  Everyone wants their tusks.  Very sad.",
		   "They were on the list of endangered species, so I have to believe it is true.  Jane Goodall is not happy.",
		   "Makes sense that these are endangered.  They have snow in their name, and there's the whole global warming thing.",
		   "These are also endangered because of their tusks.  What is it about tusks??  Just let the animal that grew 'em keep 'em!",
		   "These animals have been around for 100 million years, and, yep, we're about to wipe that out.  Quite an accomplishment, in a bad way...",
		   "They live near Alaska mostly.  There used to be 300,000.  Now?  3000.",
		   "Okay, so this particular dog isn't terribly cute, but it is really seriously endangered, and I don't wish for it to be extinct!",
		   "This animal is seriously hurting because it has a beautiful coat, and people keep hunting it for its coat.  Like the leopard doesn't need its coat.  Let the leopard keep its coat, people!",
		   "No idea what this is.  But it was on the list of endangered species.  Should probably google it.",
		   "Get this - this ferret is only found in North America and eats animals its own size. ",
		   "Yep, we're wiping out the habitat of the species most closely related to us.  Good job humans!",
		   "My guess is that the Galapagos Islands are going to be under water shortly, so any animal with the word 'Galapagos' in their name is probably in trouble.",
		   "Poor Golden Lion Tamarins.  Their habitat is going away.  Poor, poor Golden Lion Tamarins."};

	for (int i = 0; i < 17; i++) {
		tree->insert(animal[i],threat[i],info[i]);
	}
	cout << endl;
}

