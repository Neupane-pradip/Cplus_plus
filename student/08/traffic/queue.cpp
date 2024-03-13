#include "queue.hh"
#include <iostream>
#include <string>

using namespace std;

// Constructor for the Queue class, initializes the cycle_ and sets the light to red
Queue::Queue(unsigned int cycle)
{
    cycle_ = cycle;
    is_green_ = false;
}

// Destructor for the Queue class, deallocates memory for all vehicles in the queue
Queue::~Queue()
{
    Vehicle* current_vehicle = first_;
    while (current_vehicle != nullptr) {
        Vehicle* next_vehicle = current_vehicle->next;
        delete current_vehicle;
        current_vehicle = next_vehicle;
    }
    last_ = nullptr;
}

// Adds a new vehicle to the queue if the light is red
void Queue::enqueue(const string &reg)
{
    if(!is_green_){
        Vehicle* new_vehicle = new Vehicle{reg, nullptr};
        if(first_ == nullptr){
            first_ = new_vehicle;
            last_ = new_vehicle;
        }
        else{
            last_->next = new_vehicle;
            last_ = new_vehicle;
        }
    }
    else{
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
    }
}

// Switches the traffic light color and processes vehicles based on the cycle
void Queue::switch_light()
{
    if(!is_green_){
        is_green_ = true; // Light turns green
        unsigned int vehicle_count = getQueueSize();
        if(vehicle_count == 0){
            print();
        }
        else{
            if(vehicle_count < cycle_){
                cout << "GREEN: Vehicle(s) ";
                while(vehicle_count != 0){
                    displayQueue();
                    vehicle_count--;
                }
                cout << "can go on" << endl;
            }
            else{
                unsigned int i = 1;
                cout << "GREEN: Vehicle(s) ";
                while(i <= cycle_){
                    displayQueue();
                    i++;
                }
                cout << "can go on" << endl;
            }
            is_green_ = false;
        }
    }
    else{
        is_green_ = false;
        displayQueue();
    }
}

// Resets the cycle for the traffic light
void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

//print the result
void Queue::print() const
{
    Vehicle* current_vehicle = first_;

    if(first_ == nullptr){
        if(is_green_)
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;
        else
           cout << "RED: No vehicles waiting in traffic lights " << endl;
    }
    else{
        cout << "RED: Vehicle(s) ";
        while (current_vehicle != nullptr) {
            cout << current_vehicle->reg_num << " ";
            current_vehicle = current_vehicle->next;
        }
        cout << "waiting in traffic lights" << endl;
    }
}

// Displays the vehicles in the queue
void Queue::displayQueue()
{
    if(first_ == nullptr)
        return;

    Vehicle* temp_vehicle = first_;
    first_ = first_->next;
    if(first_ == nullptr){
        last_ = nullptr;
    }
    cout << temp_vehicle->reg_num << " ";
    delete temp_vehicle;
}

// Returns the size of the queue
unsigned int Queue::getQueueSize()
{
    Vehicle* current_vehicle = first_;
    unsigned int count = 0;
    while(current_vehicle != nullptr){
        ++count;
        current_vehicle = current_vehicle->next;
    }
    return count;
}
