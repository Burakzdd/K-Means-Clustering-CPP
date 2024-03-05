#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Cluster.h"
#include "matplotlibcpp.h"
#include <vector>
#include <limits>
#include <random>
using namespace std;
namespace plt = matplotlibcpp;


/// @brief KMeans class for clustering points into clusters using the K-Means algorithm.
/// The KMeans class provides functionality to cluster a set of points into a specified number of clusters
/// using the K-Means clustering algorithm.
class KMeans
{
public:
    /// @brief Constructor for the KMeans class with default values for cluster count and points.
    /// This constructor initializes a KMeans object with the specified cluster count and vector of points.
    /// Default values are provided for the parameters.
    /// @param k The number of clusters for the KMeans object.
    /// @param points A vector of points for the KMeans object.
    KMeans(int=0, vector<Point> = vector<Point>());

    /// @brief Constructor for the KMeans class with default values for cluster count and file path.
    /// This constructor initializes a KMeans object with the specified cluster count and file path that includes points.
    /// Default values are provided for the parameters.
    /// @param k The number of clusters for the KMeans object.
    /// @param filePath The file path that includes points for the KMeans object.
    KMeans(int = 0, string ="");

    /// @brief Runs the K-means clustering algorithm.
    /// This member function executes the K-means clustering algorithm on the set of points.
    /// It assigns each point to the nearest cluster centroid and updates the centroids iteratively.
    void run();

    static vector<Point> readFile(string);

    /// @brief Retrieves information about the clusters.
    /// This member function returns a vector of Cluster objects containing information about each cluster,
    /// including cluster centroids and assigned points.
    /// @return Vector of Cluster objects representing information about the clusters.
    vector<Cluster> getClusters() const;

    /// @brief Sets the data points for the K-means algorithm.
    /// This member function sets the data points that will be used in the K-means clustering algorithm.
    /// @param points A vector of Point objects representing the data points.
    void setPoints(vector<Point>&);

    /// @brief Retrieves the data points used in the K-means algorithm.
    /// This member function returns a vector of Point objects representing the data points used in the K-means clustering algorithm.
    /// @return Vector of Point objects representing the data points.
    vector<Point> getPoints() const;

    /// @brief Sets the number of clusters for the K-means algorithm.
    /// This member function sets the number of clusters that will be used in the K-means clustering algorithm.
    /// @param k The number of clusters.
    void setK(int);

    /// @brief Retrieves the number of clusters used in the K-means algorithm.
    /// This member function returns the number of clusters that are set for the K-means clustering algorithm.
    /// @return The number of clusters.
    int getK() const;

    int getCount() const;

    ~KMeans();

private:
    /// @brief Number of clusters for the K-means algorithm.
    int K;
    /// @brief Dimensions of the data points.
    int dimensions;
    /// @brief Total number of data points.
    int total_points;
    /// @brief Vector storing information about each cluster.
    vector<Cluster> clusters;
    /// @brief Vector storing the data points for the K-means algorithm.
    vector<Point> points;
    /// @brief Number of iterations for the K-means algorithm.
    const int iters = 10;
    /// @brief Clears information about clusters.
    void clearClusters();
    /// @brief Gets the ID of the nearest cluster for a given point.
    /// @param point Point for which the nearest cluster ID will be determined.
    /// @return ID of the nearest cluster.
    int getNearestClusterId(Point);

    static int count;
};