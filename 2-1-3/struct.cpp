// Zachary Palko

#include<iostream>
#include<cmath>
using namespace std;

// Creates the CartesianCoordinate structure.
struct CartesianCoordinate{
	float x;
	float y;
};

// Calculates the distance between two points on a graph.
float calculateDistance(CartesianCoordinate *pointOne, CartesianCoordinate *pointTwo){
	float xCalc = pow(((*pointTwo).x - (*pointOne).x), 2);
	float yCalc = pow(((*pointTwo).y - (*pointOne).y), 2);
	return sqrt(xCalc + yCalc);
}

// Prompts the user for two coordinates and outputs their distance.
int main() {
	CartesianCoordinate p1, p2;
	cout << "Enter the first x coordinate:" << endl;
	cin >> p1.x;
	cout << "Enter the first y coordinate:" << endl;
	cin >> p1.y;
	cout << "Enter the second x coordinate:" << endl;
	cin >> p2.x;
	cout << "Enter the second y coordinate:" << endl;
	cin >> p2.y;
	cout << "Total distance between the two points:" << endl;
	cout << calculateDistance(&p1, &p2) << endl;
}
