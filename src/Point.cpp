#include "Point.h"

Point::Point(int id,string line){
    pointId = id;
    values = lineToVec(line);
    dimensions = values.size();
    clusterId = 0;
    //cout << "Point Class Constructor"<< endl;
}
Point::Point(double x, double y) {
    pointId = -1;
    values.push_back(x);
    values.push_back(y);
    dimensions = values.size();
    clusterId = 0;
    //cout << "Point Class Constructor" << endl;
}
Point::~Point() {
    //cout << "Point Class Destructor" << endl;
}
int Point::getDimensions(){
    return dimensions;
}
int Point::getCluster(){
    return clusterId;
}
int Point::getID(){
    return pointId;
}
void Point::setID(int id) {
    pointId = id;
}
void Point::setCluster(int val){
    clusterId = val;
}

double Point::getVal(int pos){
    return values[pos];
}
vector<double> Point::lineToVec(string& line) {

    istringstream iss(line);
    double num;
    while (iss >> num) {
        values.push_back(num);
    }
    return values;
}