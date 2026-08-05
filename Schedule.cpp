#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Schedule {
    int scheduleID;
    string date;         // Format: YYYY-MM-DD
    int startTime;       // 24-hour format e.g., 1400 (2:00 PM)
    int endTime;         // 24-hour format e.g., 1500 (3:00 PM)
    string className;
    string trainerName;
    bool isCanceled;
};

void addschedule(vector<Schedule>& schedules);
void displayschedule(vector<Schedule>& schedules);

int main() {
    vector<Schedule> schedules; // Vector to store schedules
    int choice;

    addschedule(schedules);
    displayschedule(schedules);

    do {
        cout << "\n=== Gym Schedule Management ===\n";
        cout << "1. Add Schedule\n";
        cout << "2. Display Schedules\n";
        cout << "3. Search Schedule by Date\n";
        cout << "4. Update Schedule\n";
        cout << "5. Cancel Schedule\n";
        cout << "6. Assign Trainer\n";
        cout << "7. Check System Conflicts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

    } while (choice != 0);

    return 0;
}

void addschedule(vector<Schedule>& schedules) {
    Schedule newschedule;

    static int nextID = 100;
    newschedule.scheduleID = nextID;
    nextID++;

    cout << "---- ADD NEW SCHEDULE ----";
    cout << "Enter schedule name: ";
    getline(cin, newschedule.className);

    cout << "Enter schedule date (YYYY/MM/DD): ";
    getline(cin, newschedule.date);

    cout << "Enter start time ( eg. 1400 ): ";
    cin >> newschedule.startTime;

    cout << "Enter end time ( eg. 1600 ): ";
    cin >> newschedule.endTime;

    if (newschedule.startTime >= newschedule.endTime) {
        cout << "Error: Start time must be before end time.\n";
        return;
    }

    newschedule.trainerName = "Unassigned";
    newschedule.isCanceled = false;

    schedules.push_back(newschedule);

    cout << "Schedule added successfully!\n";

}

void displayschedule(vector<Schedule>& schedules) {
    cout << "\n--- Gym Class Schedules ---\n";

    if (schedules.empty()) {
        cout << "No schedules available right now. Please add one first.\n";
        return;
    }

    // Print the Table Header
    cout << left << setw(5) << "ID"
        << setw(15) << "Date"
        << setw(15) << "Class Name"
        << setw(10) << "Start"
        << setw(10) << "End"
        << setw(15) << "Trainer"
        << "Status\n";

    cout << "-------------------------------------------------------------------------------\n";

    // Loop through the vector and print each schedule
    for (Schedule& s : schedules) {
        cout << left << setw(5) << s.scheduleID
            << setw(15) << s.date
            << setw(15) << s.className
            << setw(10) << s.startTime
            << setw(10) << s.endTime
            << setw(15) << s.trainerName
            << (s.isCanceled ? "Canceled" : "Active") << "\n";
    }
}


