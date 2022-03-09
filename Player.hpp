#include <string>
#include <iomanip>
using namespace std;
class Player
{
private:
    string firstName;
    string secondName;
    int points;
    public:
    	Player();
    	friend istream &operator>>(istream & ,Player &);
    	friend ostream &operator<<(ostream & ,Player &);
    	int get_points();
    	void set_points(int p);
    
};

