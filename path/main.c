#include <stdio.h>
#include <stdbool.h>

#define NUM_CITIES 7

typedef struct {
    int city;
    int distance;
} Edge;

typedef struct {
    int city;
    Edge edges[NUM_CITIES];
    int num_edges;
} Node;

Node cities[NUM_CITIES];
const char* cityNames[NUM_CITIES] = {"Prague", "Helsinki", "Beijing", "Tokyo", "Jakarta", "London", "New York"};

void addEdge(int fromCity, int toCity, int distance) {
    Edge edge = {toCity, distance};
    cities[fromCity].edges[cities[fromCity].num_edges++] = edge;
}

void initializeCities() {
    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        cities[i].city = i;
        cities[i].num_edges = 0;
    }

    // Prague
    addEdge(0, 1, 1845);
    addEdge(0, 5, 1264);

    // Helsinki
    addEdge(1, 3, 7815);

    // Beijing
    addEdge(2, 6, 11550);
    addEdge(2, 3, 1303);
    addEdge(2, 5, 8132);

    // Tokyo
    addEdge(3, 6, 10838);
    addEdge(3, 4, 5782);

    // Jakarta
    addEdge(4, 2, 4616);

    // London

    // New York
    addEdge(6, 5, 5567);
}

bool findPath(int source, int destination, int distance, int path[], int pathLength) {
    if (source == destination) {
        printf("Distance: %d km\nYol: ", distance);
        int i;
        for (i = 0; i < pathLength; i++) {
            printf("%s ", cityNames[path[i]]);
        }
        printf("%s\n", cityNames[destination]);
        return true;
    }

    path[pathLength++] = source;

    int i;
    for (i = 0; i < cities[source].num_edges; i++) {
        int nextCity = cities[source].edges[i].city;
        int nextDistance = cities[source].edges[i].distance;
        if (findPath(nextCity, destination, distance + nextDistance, path, pathLength)) {
            return true;
        }
    }

    return false;
}

void findPaths(int source, int destination) {
    int path[NUM_CITIES];
    int pathLength = 0;
    if (!findPath(source, destination, 0, path, pathLength)) {
        printf("No path Found.\n");
    }
}

int main() {
    int source, destination;

    initializeCities();

    printf("City Numbers:\nPrague = 0, Helsinki = 1, Beijing = 2, Tokyo = 3, Jakarta = 4, London = 5, New York = 6\n");

    printf("Enter the starting city number: ");
    scanf("%d", &source);

    printf("Enter destination city number: ");
    scanf("%d", &destination);

    if (source < 0 || source >= NUM_CITIES || destination < 0 || destination >= NUM_CITIES) {
        printf("Invalid city number!\n");
        return 0;
    }

    findPaths(source, destination);
	return 0;
	}
