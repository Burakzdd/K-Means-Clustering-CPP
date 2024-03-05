#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
/// @brief Class representing a point in a two-dimensional space.
class Point
{
public:
    /// @brief Constructor creating a point with a specified ID and associated line information.
    /// This constructor is specialized for creating a Point object with a specified ID and additional information
    /// about the line to which the point belongs (e.g., from a file).
    /// @param id The ID of the point.
    /// @param line A string containing information about the line associated with the point (e.g., from a file).
    Point(int, string);

    /// @brief Constructor creating a point with specified coordinates.
    /// This constructor creates a Point object with specified x and y coordinates.
    /// @param x The x-coordinate of the point.
    /// @param y The y-coordinate of the point.
    Point(double, double);

    /// @brief Retrieves the number of dimensions of the point.
    /// This member function returns the number of dimensions of the point. For a two-dimensional point,
    /// the value will typically be 2.
    /// @return The number of dimensions of the point.
    int getDimensions();

    /// @brief Retrieves the ID of the cluster to which the point belongs.
    /// This member function returns the ID of the cluster to which the point has been assigned.
    /// @return The ID of the cluster to which the point belongs.
    int getCluster();

    /// @brief Retrieves the ID of the point.
    /// This member function returns the unique ID of the point.
    /// @return The ID of the point.
    int getID();
    void setID(int);
    /// @brief Sets the ID of the cluster to which the point belongs.
    /// This member function sets the ID of the cluster to which the point is assigned.
    /// @param clusterID The ID of the cluster to set for the point.
    void setCluster(int);

    /// @brief Retrieves the value at the specified position.
    /// This member function returns the value at the specified position (dimension) of the point.
    /// @param pos The position (dimension) for which the value should be retrieved.
    /// @return The value at the specified position.
    double getVal(int pos);



    ~Point();

private:
    /// @brief Vector storing the values of the point in each dimension.
    /// This vector stores the values of the point in each dimension. For example, for a two-dimensional point,
    /// the vector may contain the x and y coordinates in that order.
    vector<double> values;

    /// @brief ID of the cluster to which the point belongs.
    /// This member variable stores the ID of the cluster to which the point has been assigned.
    int clusterId;

    /// @brief Unique ID assigned to the point.
    /// This member variable stores a unique identifier assigned to the point.
    int pointId;

    /// @brief Number of dimensions for the point.
    /// This member variable stores the number of dimensions for the point. It represents the size of the vector
    /// storing the values of the point in each dimension.
    int dimensions;

    /// @brief Convert a string representation to a vector of doubles.
    /// This member function converts a string representation of point values to a vector of doubles.
    /// @param line A string containing the point values (comma-separated or space-separated).
    /// @return A vector of doubles representing the point values.
    vector<double> lineToVec(string&);
};