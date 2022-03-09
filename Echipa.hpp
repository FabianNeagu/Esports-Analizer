#include "Player.hpp"
class Echipa
{
	int nr_playeri;
	string nume_echipa;
	Player *v;
	float points_echipa;
	public:
		friend istream &operator>>(istream & ,Echipa & );
		friend ostream &operator<<(ostream &,Echipa &);
		Echipa &operator=(const Echipa &);
		string get_nume_echipa();
		int get_nr_playeri();
		float get_points_echipa();
		void set_points_echipa(float p);
		Player *get_player();
};

