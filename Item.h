#ifndef ITEM_H
#define ITEM_H

#include <cmath>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Item {

	private:
	double latitude;
	double longitude;
	string id;
	int seconds;

	public:
	Item(const double latitudeIn, const double longitudeIn, const string idIn, const int secondsIn)
	: latitude(latitudeIn), longitude(longitudeIn), id(idIn), seconds(secondsIn) {}

	double getLat() {
		return latitude;
	}

	double getLon() {
		return longitude;
	}

	string getID() {
		return '"'+id+'"';
	}

	int getSeconds() {
		return seconds;
	}

	// & is for a reference.
	// Passing references to a and b instead of copying a and b to entirely new objects.
	// This avoids creating too many access objects (causes memory leaks).

	double distanceTo(Item & destination) {

		const double PI = 2*acos(0.0); // 3.14159265 rad

		double lat1 = latitude*(PI/180);
		double lat2 = destination.getLat()*(PI/180);
		double lon1 = longitude*(PI/180);
		double lon2 = destination.getLon()*(PI/180);

		double dlon = lon2 - lon1;
		double dlat = lat2 - lat1;

		double a = pow((sin(dlat/2.0)), 2.0) + cos(lat1) * cos(lat2) * pow((sin(dlon/2.0)), 2.0);
		double c = 2.0 * atan2(sqrt(a), sqrt(1.0-a) );

		double distance = 6373000 * c;

		return distance;
	}
};

	ostream & operator<<(ostream & o, Item & item) {
		o << "{"
		<< item.getLat()
		<< ", "
		<< item.getLon()
		<< ", "
		<< item.getID()
		<< ", "
		<< item.getSeconds()
		<<"}";

		return o;
		}

// don't write any code below this line
#endif
