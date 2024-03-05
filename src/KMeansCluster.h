#pragma once
#include "KMeans.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/// @brief KMeansCluster class inherits from KMeans.
/// The KMeansCluster class is derived from the KMeans class, inheriting its functionality and properties.
class KMeansCluster : public KMeans 
{
    /// @brief Friend function to input coordinates for a point into KMeansCluster.
    /// This function is a friend function to input x and y coordinates for a point into the KMeansCluster object.
    /// @param is The input stream from which the coordinates are read.
    /// @param kMeansCluster The KMeansCluster object to which the coordinates are input.
    /// @return The input stream after reading the coordinates.
    friend istream& operator>>(istream&, KMeansCluster&);

    /// @brief Friend function to output Cluster and points to the output stream.
    /// This function is a friend function to output Cluster and points to the specified output stream.
    /// @param os The output stream to which the Cluster and points are written.
    /// @param kMeansCluster The KMeansCluster object containing the Cluster and points to be output.
    /// @return The output stream after writing the Cluster and points.
    friend ostream& operator<<(ostream&, KMeansCluster&);

public:
    /// @brief Constructor for KMeansCluster with default values for cluster ID and points.
    /// This constructor initializes a KMeansCluster object with the specified cluster ID and vector of points.
    /// It run the KMeansAlgorithm.
    /// Default values are provided for the parameters.
    /// @param k The cluster ID for the KMeansCluster object.
    /// @param points A vector of points for the KMeansCluster object. 
    KMeansCluster(int = 0, vector<Point> = vector<Point>());

    /// @brief Constructor for KMeansCluster with default values for cluster ID and output directory.
    /// This constructor initializes a KMeansCluster object with the specified cluster ID and output directory.
    /// It run the KMeansAlgorithm.
    /// Default values are provided for the parameters.
    /// @param k The cluster ID for the KMeansCluster object.
    /// @param output_dir The output directory for the KMeansCluster object.
    KMeansCluster(int = 0, string = "");

    /// @brief Visualizes the clusters using the matplotlib library.
    ///
    /// This member function visualizes the points and clusters using the matplotlib library.
    /// The visualization includes the display of points and their respective clusters.
    ///
    void visualizeClusters();

    /// @brief Saves cluster coordinates to a file.
    /// This member function saves the coordinates of clusters to a file in the specified directory.
    /// The file is named based on the cluster count.
    /// @param directory The directory path where the file will be saved (default is current directory).
    void saveClusters(string = "./");

    /// @brief Saves points and their assigned clusters to a specified directory.
    ///
    /// This member function saves the coordinates of points and their assigned clusters to a file in the specified directory.
    ///
    /// @param directory The directory path where the file will be saved (default is current directory).
    void savePointsCluster(string = "./");

    /// @brief Adds points from another KMeansCluster and re-runs the clustering algorithm.
    /// This member function adds points from another KMeansCluster to the current KMeansCluster,
    /// updates point IDs, and re-runs the clustering algorithm.
    /// @param kMeansCluster Another KMeansCluster whose points will be added to the current KMeansCluster.
    /// @return Reference to the modified current KMeansCluster.
    KMeansCluster& operator+(KMeansCluster&);

    /// @brief Adds a new point to the KMeansCluster and re-runs the clustering algorithm.
    /// This member function adds a new point to the current KMeansCluster,
    /// updates point IDs, and re-runs the clustering algorithm.
    /// @param point The new point to be added to the KMeansCluster.
    /// @return Reference to the modified current KMeansCluster.
    KMeansCluster& operator+(Point);

    /// @brief Removes a point by ID from the KMeansCluster and re-runs the clustering algorithm.
    /// This member function removes a point with the specified ID from the current KMeansCluster,
    /// updates the point IDs, and re-runs the clustering algorithm.
    /// @param pos The ID of the point to be removed from the KMeansCluster.
    /// @return Reference to the modified current KMeansCluster.
    KMeansCluster& operator-(int);


    ~KMeansCluster();

};
