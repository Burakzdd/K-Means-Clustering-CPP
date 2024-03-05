#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;
/// @brief Cluster class representing a cluster in the K-means algorithm.
class Cluster
{
public:
    /// @brief Constructor for the Cluster class with a specified cluster ID and centroid.
    /// This constructor initializes a Cluster object with the given cluster ID and centroid.
    /// @param clusterID The ID of the cluster.
    /// @param centroid The centroid of the cluster.
    Cluster(int, Point);

    /// @brief Adds a point to the cluster.
    /// This member function adds the specified point to the vector of points belonging to the cluster.
    /// @param point The point to add to the cluster.
    void addPoint(Point);

    /// @brief Removes a point from the cluster.
    /// This member function removes the point with the specified ID from the vector of points belonging to the cluster.
    /// @param pointID The ID of the point to remove.
    /// @return True if the point is successfully removed, false otherwise.
    bool removePoint(int);

    /// @brief Removes all points from the cluster.
    /// This member function clears the vector of points belonging to the cluster, effectively removing all points.
    /// The points vector is emptied using the clear() function.
    void removeAllPoints();

    /// @brief Retrieves the ID of the cluster.
    /// This member function returns the ID of the cluster.
    /// @return The ID of the cluster.
    int getId();

    /// @brief Retrieves a point at the specified position in the cluster.
    /// This member function returns a Point object representing the point at the specified position in the cluster.
    /// @param pos The position of the point to retrieve.
    /// @return Point object representing the specified point in the cluster.
    
    Point getPoint(int pos);

    /// @brief Retrieves the number of points in the cluster.
    /// This member function returns the number of points currently stored in the cluster.
    /// @return The number of points in the cluster.
    int getSize();

    /// @brief Retrieves the coordinate of the cluster centroid at the specified position.
    /// This member function returns the coordinate of the cluster centroid at the specified position.
    /// @param pos The position of the coordinate to retrieve (0 for x, 1 for y, etc.).
    /// @return The coordinate of the cluster centroid at the specified position.
    double getCentroidByPos(int);

    /// @brief Sets the coordinate of the cluster centroid at the specified position.s
    /// This member function sets the coordinate of the cluster centroid at the specified position.
    /// @param pos The position of the coordinate to set (0 for x, 1 for y, etc.).
    /// @param val The value to set for the specified coordinate.
    void setCentroidByPos(int pos, double val);

    ~Cluster();

private:
    /// @brief ID of the cluster.
    int clusterId;

    /// @brief Centroid coordinates of the cluster.
    vector<double> centroid;

    /// @brief Points belonging to the cluster.
    vector<Point> points;
};
