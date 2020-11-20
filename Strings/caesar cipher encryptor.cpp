using namespace std;

string caesarCypherEncryptor(string str, int key) {
  for ( auto& c : str ) 
		c = (char)(((int)c + key - 'a')%26 + 'a');
  return str;
}
