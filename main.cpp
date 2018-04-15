/*
 * --------------------------------
 *  Yet Another Password Generator
 *  by Phoenix1747
 *  Github: https://github.com/phoenix1747/yapg
 * --------------------------------
 */

#include <iostream> // Used for user input
#include <string> // Used for string operations
#include <vector> // Used for the whole character pools operations
#include <random> // Used for random operations
#include <algorithm> // Used to trim whitespace for user input


int main() {

	unsigned int pwLength = 10; // standard password length

	// CHAR ARRAYS
	std::vector<char> lowercase_vector = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	std::vector<char> uppercase_vector = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	std::vector<char> number_vector = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	std::vector<char> special_vector = {'!', '$', '%', '&', '?', '*', '+', '#', '-', '_', '@', '.', ';', '|', '<', '>', '~', '=', '/'};

	// USER INPUT
	std::string a, b, c, d, e;
	std::cout << ":: How long should your password be? [Default:" << pwLength << "] ";
	std::getline(std::cin, a);
	std::cout << ":: May contain lowercase letters? [Y/n] ";
	std::getline(std::cin, b);
	std::cout << ":: May contain uppercase letters? [Y/n] ";
	std::getline(std::cin, c);
	std::cout << ":: May contain numbers? [Y/n] ";
	std::getline(std::cin, d);
	std::cout << ":: May contain special characters? [Y/n] ";
	std::getline(std::cin, e);

	// trim all whitespace
	remove(begin(a), end(a), ' ');
	remove(begin(b), end(b), ' ');
	remove(begin(c), end(c), ' ');
	remove(begin(d), end(d), ' ');
	remove(begin(e), end(e), ' ');

	// check if length input is empty
	if (a!="") {

		// check if length input is not 0 or less
		if (stoi(a) <= 0) {
			std::cout << "The password length cannot be 0 or less. Impossible!\n";
			return 1;
		} else {
			pwLength = stoi(a);
		}
	}

	// check if all questions were answered with "no"
	if (b=="n" and c=="n" and d=="n" and e=="n") {
		std::cout << "You deselected all elements of the character pool. This is pointless!\n";
		return 1;
	}

	// declare character pool vector and add the corresponding characters
	std::vector<char> charPool;

	if (b!="n") {
		charPool.insert(end(charPool), begin(lowercase_vector), end(lowercase_vector));
	}
	if (c!="n") {
		charPool.insert(end(charPool), begin(uppercase_vector), end(uppercase_vector));
	}
	if (d!="n") {
		charPool.insert(end(charPool), begin(number_vector), end(number_vector));
	}
	if (e!="n") {
		charPool.insert(end(charPool), begin(special_vector), end(special_vector));
	}

	// get pool size
	unsigned int charPoolSize = charPool.size() - 1;

	// password string for later output
	std::string password;

	// Randomness
	std::uniform_int_distribution<int> distribution(0, charPoolSize);
	std::random_device rd;
	std::default_random_engine generator(rd());

	// get a random character and append it to the password string
	for(unsigned int i=0; i<pwLength; i++) {
		unsigned int index = distribution(generator);
		password += charPool[index];
	}

	std::cout << "Finished! Your password is: " << password << "\n";

	return 0;

}

