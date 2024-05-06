#include <iostream>
#include <stdexcept>

using namespace std;

class Room {
protected:
    double area;
    double height;
    int windows;

public:
    Room(double area, double height, int windows) {
        if (area <= 0 || height <= 0 || windows < 0) {
            throw invalid_argument("Invalid room parameters");
        }
        this->area = area;
        this->height = height;
        this->windows = windows;
    }

    double getArea() const {
        return area;
    }

    double getHeight() const {
        return height;
    }

    int getWindows() const {
        return windows;
    }

    double calculateVolume() const {
        return area * height;
    }

    double calculateWallpaperRolls() const {

        return windows;
    }
};

class Bedroom : public Room {
public:
    Bedroom(double area, double height, int windows) : Room(area, height, windows) {}


    double calculateWallpaperRolls() const {

        return windows * 2;
    }
};

int main() {
    try {

        Room room(20.5, 2.7, 3);


        cout << "Room area: " << room.getArea() << " sq.m" << endl;
        cout << "Room height: " << room.getHeight() << " m" << endl;
        cout << "Number of windows: " << room.getWindows() << endl;
        cout << "Room volume: " << room.calculateVolume() << " cubic meters" << endl;
        cout << "Number of wallpaper rolls needed: " << room.calculateWallpaperRolls() << endl;


        Bedroom bedroom(15, 2.7, 2);


        cout << "\nBedroom area: " << bedroom.getArea() << " sq.m" << endl;
        cout << "Bedroom height: " << bedroom.getHeight() << " m" << endl;
        cout << "Number of windows: " << bedroom.getWindows() << endl;
        cout << "Bedroom volume: " << bedroom.calculateVolume() << " cubic meters" << endl;
        cout << "Number of wallpaper rolls needed for bedroom: " << bedroom.calculateWallpaperRolls() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
