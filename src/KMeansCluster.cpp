#include "KMeansCluster.h"

KMeansCluster::KMeansCluster(int k, vector<Point> p)
    :KMeans(k, p)
{
    run();
    cout << "KMeansCluster Class Constructor with " << getK() << " Clusters, Count is =" << getCount() << endl;
}

KMeansCluster::KMeansCluster(int k, string path)
    :KMeans(k, path)
{
    run();
    cout << "KMeansCluster Class Constructor with " << getK() << " Clusters, Count is =" << getCount() << endl;
}
KMeansCluster::~KMeansCluster() {
    cout << "KMeansCluster Class Destructor with "<<getK() <<" Clusters, Count is =" << getCount() << endl;
}

void KMeansCluster::visualizeClusters() {
    vector<string> colors = {"y", "b", "g", "r", "c", "m" };
    for (Point& point : getPoints()) {
        plt::plot({ point.getVal(0) }, { point.getVal(1) }, { {"color", colors[point.getCluster()]}, {"marker", "o"}});
        plt::text(point.getVal(0), point.getVal(1), to_string(point.getID()));
    }
    cout << endl;
    for (int i = 0; i < getK(); i++)
    {
        cout << "Cluster " << getClusters()[i].getId() << " centroid : ("<< getClusters()[i].getCentroidByPos(0)<<","<< getClusters()[i].getCentroidByPos(1)<<")"<<endl;
        plt::plot({ getClusters()[i].getCentroidByPos(0) }, { getClusters()[i].getCentroidByPos(1) }, { {"color","r"}, {"marker", "x"} });
    }
    plt::show();
}

void KMeansCluster::saveClusters(string opath) {
    ofstream file;
    file.open(opath + to_string(getK()) + "_cluster_coordinate.txt");
    if (file.is_open())
    {
        for (int i = 0; i < getK(); i++)
        {
            file << "Cluster" << i + 1 << " (x,y) = ("
                << getClusters()[i].getCentroidByPos(0) << ","
                << getClusters()[i].getCentroidByPos(1) << ")"
                << endl;
        }
        file.close();
    }
}

void KMeansCluster::savePointsCluster(string  opath) {
    ofstream file;
    file.open(opath + to_string(getK()) + "_pointsCluster.txt", ios::out);

    for (int i = 0; i < getPoints().size(); i++)
    {
        file << "Point" << i + 1 << " (x,y) = ("
            << getPoints()[i].getVal(0) << ","
            << getPoints()[i].getVal(1) << ") -> Cluster "
            << getPoints()[i].getCluster() << endl;
    }
    file.close();
}
KMeansCluster& KMeansCluster::operator+(KMeansCluster& kobj) {
    vector<Point> kpoints = this->getPoints();

    int current_last_id = this->getPoints().back().getID();
    for (Point point : kobj.getPoints())
    {
        point.setID(current_last_id + 1);
        kpoints.push_back(point);
        current_last_id += 1;
    }
    this->setPoints(kpoints);
    this->run();
    return (*this);
}

KMeansCluster& KMeansCluster::operator+(Point p) {
    vector<Point> kpoints = this->getPoints();
    p.setID(this->getPoints().back().getID() + 1);

    kpoints.push_back(p);
    this->setPoints(kpoints);
    this->run();

    return (*this);
}
KMeansCluster& KMeansCluster::operator-(int pos) {

    vector<Point> kpoints = this->getPoints();

    vector<Point>::iterator it = remove_if(kpoints.begin(), kpoints.end(), [pos](Point& p) {
        return (p.getID() == pos);
    });
    //kpoints.erase(it, kpoints.end());
    kpoints.pop_back();
    this->setPoints(kpoints);
    this->run();
    return (*this);
}
istream& operator>>(istream& input, KMeansCluster& kobj) {
    double x, y;
    input >> x >> y;

    Point p(x, y);
    kobj + p;
    kobj.run();
    return input;
}
ostream& operator<<(ostream& output, KMeansCluster& kobj) {

    for (int i = 0; i < kobj.getK(); i++)
    {
        cout << "Cluster" << i + 1 << " (x,y) = ("
            << kobj.getClusters()[i].getCentroidByPos(0) << ","
            << kobj.getClusters()[i].getCentroidByPos(1) << ")"
            << endl;
    }
    cout << endl << endl;
    for (int i = 0; i < kobj.getPoints().size(); i++)
    {
        output << "Point" << i + 1 << " (x,y) = ("
            << kobj.getPoints()[i].getVal(0) << ","
            << kobj.getPoints()[i].getVal(1) << ") -> Cluster "
            << kobj.getPoints()[i].getCluster() << endl;
    }
    return output;
}