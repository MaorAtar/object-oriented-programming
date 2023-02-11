/* Assignment: 3
Author: Maor Atar, ID: 318301231
*/

#include "Text.h"

class EncryptedText {
private:
	Text* encryptedText;
	bool status;
	int* key;
	int keySize;

public:
	EncryptedText(); // Default c'tor
	EncryptedText(string, int); // Customized c'tor
	~EncryptedText(); // D'tor
	// Overloading Functions:
	EncryptedText& operator += (int*);
	EncryptedText& operator ! ();
	EncryptedText& operator & ();
	friend ostream& operator << (ostream&, const EncryptedText&);
};
