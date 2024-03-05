#include "KMeans.h"

KMeans::KMeans(int k, vector<Point> p)
{
    setK(k);
    setPoints(p);

    count += 1;
    cout << "KMeans Class Constructor with " << getK() << " Clusters" << endl;

}

KMeans::KMeans(int k, string path)
{
    setK(k);
    vector<Point> p = readFile(path);
    setPoints(p);

    count += 1;
    cout << "KMeans Class Constructor with " << getK() << " Clusters, Count is ="<<count << endl;
}
KMeans::~KMeans() {
    count -= 1;
    cout << "KMeans Class Destructor with " << getK() << " Clusters, Count is =" << count << endl;
}

void KMeans::setPoints(vector<Point>& all_points) {
    points = all_points;
}
vector<Point> KMeans::getPoints() const{
    return points;
}

vector<Cluster> KMeans::getClusters() const{
    return clusters;
}
void KMeans::setK(int k) {
    K = k;
}
int KMeans::getK() const{
    return K;
}
void KMeans::run()
{
    vector<Point> all_p = getPoints();
    total_points = all_p.size();
    dimensions = all_p[0].getDimensions();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, total_points - 1);
    vector<int> used_pointIds;

    for (int i = 1; i <= K; i++) {
        while (true) {
            int index = distribution(gen);
            if (find(used_pointIds.begin(), used_pointIds.end(), index) == used_pointIds.end())
            {
                used_pointIds.push_back(index);
                all_p[index].setCluster(i);
                Cluster cluster(i, all_p[index]);
                clusters.push_back(cluster);
                break;
            }
        }
    }

    cout << "Clusters initialized = " << clusters.size() << endl << endl;
    cout << "Running K-Means Clustering.." << endl;

    int iter = 1;

    while (true)
    {
        std::cout << "Iter - " << iter << "/" << iters << endl;

        bool done = true;

#pragma omp parallel for reduction(&&: done) num_threads(16)
        for (int i = 0; i < total_points; i++)
        {
            int currentClusterId = all_p[i].getCluster();
            int nearestClusterId = getNearestClusterId(all_p[i]);

            if (currentClusterId != nearestClusterId) {
                all_p[i].setCluster(nearestClusterId);
                done = false;
            }
        }

        clearClusters();

        #pragma omp parallel for num_threads(16)
        for (int i = 0; i < total_points; i++) {
            clusters[all_p[i].getCluster() - 1].addPoint(all_p[i]);
        }

        #pragma omp parallelfor num_threads(16)
        for (int i = 0; i < K; i++) {
            int ClusterSize = clusters[i].getSize();

            if (ClusterSize > 0) {
                for (int j = 0; j < dimensions; j++) {
                    double sum = 0.0;

                    #pragma omp parallel for reduction(+: sum) num_threads(16)
                    for (int p = 0; p < ClusterSize; p++) {
                        sum += clusters[i].getPoint(p).getVal(j);
                    }

                    clusters[i].setCentroidByPos(j, sum / ClusterSize);
                }
            }
        }

        if (done || iter >= iters)
        {
            std::cout << "Clustering completed in iteration : " << iter << std::endl << std::endl;
            break;
        }

        iter++;
    }

    setPoints(all_p);
}

void KMeans::clearClusters()
{
    for (int i = 0; i < getK(); i++)
    {
        clusters[i].removeAllPoints();
    }
}

int KMeans::getNearestClusterId(Point point) {
    double min_dist = numeric_limits<double>::max();
    int nearestClusterId = -1;
    for (int i = 0; i < K; i++) {
        double dist = 0.0;
        for (int j = 0; j < dimensions; j++) {
            // Eðer Öklidyen mesafesi yerine manhattan mesafesi (L1 norm) kullanmak istiyorsanýz, karekök alýnmasý adýmý atlanabilir ve doðrudan farklarýnýn mutlak deðerleri toplanabilir.
            double diff = clusters[i].getCentroidByPos(j) - point.getVal(j);
            dist += diff * diff;
        }
        if (dist < min_dist) {
            min_dist = dist;
            nearestClusterId = clusters[i].getId();
        }
    }
    return nearestClusterId;
}

vector<Point> KMeans::readFile(string path) {
    ifstream infile(path.c_str());
    string line;
    int id = 1;
    vector<Point> p;
    while (getline(infile, line))
    {
        Point point(id, line);
        p.push_back(point);
        id++;
    }
    infile.close();
    return p;
}


int KMeans::count = 0;

int KMeans::getCount() const{
    return count;
}