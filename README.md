# K-Means Clustering Algorithm Implementation in C++

## Description
This project is developed in C++ to cluster data points into groups using the K-Means Clustering Algorithm.

### Overview
This project is designed to cluster a specific dataset into a specified number of clusters (K) using the K-Means algorithm. It is implemented in C++ and utilizes the matplotlibcpp library for visualizing the results.

## File Structure
- Point.h, Point.cpp: Contains the class and functions representing data points.
- Cluster.h, Cluster.cpp: Contains the class and functions used for clustering operations.
- KMeans.h, KMeans.cpp: Contains the class and functions implementing the K-Means algorithm and clustering operations.
- KMeansCluster.h, KMeansCluster.cpp: Contains the class and functions extending the KMeans class and performing visualization operations.
- matplotlibcpp.h: Library used for visualization.
- main.cpp: Main program file. It interacts with the user and executes the K-Means algorithm.

<p align="center">
    <img src="https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/UML_kmeans.jpg" width="800" height="400">
    <br>
    <em>Figure 1: Project UML</em>
</p>

## Functions and Operator

- **visualizeClusters Function:** This function visualizes clusters and points using the matplotlib library. For example, the visualization output is shown in Figure 1 above.
    <p align="center">
        <img src="https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/fig1.jpg" width="600" height="400">
        <br>
        <em>Figure 2</em>
    </p>
- **saveClusters Function:** This function saves the coordinates of clusters to a text file.

- **savePoints Function:** This function saves the coordinates of points and the clusters they belong to a text file.

- **operator+ (KMeansCluster):** This operator adds the points of the object at the end of the points of the passed object and updates the clusters. For instance, when there are 5 points as shown in Figure 2, this operator adds them to the points of the object in Figure 1 and updates the clusters. The result is shown in Figure 3.
    <p align="center">
        <img src="https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/fig2.jpg" width="600" height="400">
        <br>
        <em>Figure 3</em>
    </p>
    <p align="center">
        <img src="https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/fig3.jpg" width="600" height="400">
        <br>
        <em>Figure 4</em>
    </p>

- **operator+ (Point):** This operator adds the specified point to the points of the cluster and updates the clusters. For example, a point has been added at the position 10000-20000, and it is now in Figure 4.
    <p align="center">
        <img src="https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/fig4.jpg" width="600" height="400">
        <br>
        <em>Figure 5</em>
    </p>

- **operator- (int ID):** This operator removes the point with the specified ID from the points of the object and updates the clusters. For example, in the output of Figure 5, the point with ID:3 has been removed.
    <p align="center">
        <img src="https://github.com/Burakzdd/K-Means-Clustering-CPP/blob/main/img/fig5.jpg" width="600" height="400">
        <br>
        <em>Figure 6</em>
    </p>

- **Additionally, it also has operator<< and operator>> friend functions:** With the >> operator, it adds the entered point to the object. With the << operator, it prints point and cluster information to the screen.

## Usage Example

Below is an example code snippet demonstrating the usage of the KMeansCluster class:

```cpp
KMeansCluster k_obj1(3, "data1.txt");
KMeansCluster k_obj2(3, "data2.txt");

// Two KMeansCluster objects are merged
KMeansCluster k_obj3 = k_obj1 + k_obj2;

// A specific point is added
Point newPoint(10000, 20000);
k_obj3 + newPoint;

// A point with a specific ID is removed
k_obj3 - 3;

// Clustering results are visualized
k_obj3.visualizeClusters();

// Clustering results and the status of points are printed
cout << k_obj3;
```
## Contact

If you have any questions or feedback regarding the project, please contact us at burak67ozd@outlook.com.

## License

This project is licensed under the MIT License. For more information, see the [LICENSE](link/to/LICENSE) file.
