#include <iostream>
#include "KMeans.h"
#include <string>
#include <fstream>
#include "matplotlibcpp.h"
#include "KMeansCluster.h"

using namespace std;
namespace plt = matplotlibcpp;

int main()
{
    int K;
    cout << "Enter the K value:";
    cin >> K;

    string filename = "C:\\Users/burak/Desktop/OOP/40.txt";

    //ifstream infile(filename.c_str());
    //int pointId = 1;
    //vector<Point> all_points;
    //string line;

    //while (getline(infile, line)){
    //    Point point(pointId, line);
    //    all_points.push_back(point);
    //    pointId++;
    //}
    //infile.close();

    vector<Point> points = KMeansCluster::readFile(filename);

    KMeansCluster k_obj1(K, points);
    k_obj1.visualizeClusters();

    string path2 = "C:\\Users/burak/Desktop/OOP/5.txt";
    KMeansCluster k_obj2(K, path2);
    k_obj2.visualizeClusters();

    k_obj1 + k_obj2;
    k_obj1.visualizeClusters();

    k_obj1.saveClusters();
    k_obj1.savePointsCluster();

    k_obj1 + Point(10000, 20000);
    k_obj1.visualizeClusters();

    k_obj1 - 3;
    k_obj1.visualizeClusters();
     



    cout << "Enter Point Coordinate";
    cin >> k_obj1;
    k_obj1.visualizeClusters();
    cout << k_obj1;
    return 0;
}
