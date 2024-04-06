#include "careperiod.hh"
#include <iostream>

CarePeriod::CarePeriod(const std::string& start, Person* patient):
    patient_(patient), start_(start)
{
    is_closed_ = false;
}


CarePeriod::CarePeriod(const Date &start, Person* patient):
    patient_(patient), start_(start)
{
    is_closed_ = false;
}


CarePeriod::~CarePeriod()
{
}



// Get the start date of the care period
Date CarePeriod::start_date() const {
    return start_;
}

// Get the ID of the patient associated with the care period
std::string CarePeriod::patient_id() const {
    return patient_->get_id();
}

// Check if the care period is closed
bool CarePeriod::is_closed() {
    return is_closed_;
}

// Check if a staff member with the given ID is assigned to the care period
bool CarePeriod::check_staff(std::string staff_id) {
    return (staff_.find(staff_id) != staff_.end());
}

// Mark the end of the care period and set the closing date
void CarePeriod::end_period(const Date& end) {
    end_ = end;
    is_closed_ = true;
}

// Add a staff member with the given ID to the care period
void CarePeriod::add_staff(std::string staff_id) {
    staff_.insert(staff_id);
}

// Print the details of the care period for the patient, including dates and staff
void CarePeriod::print_care_period_for_patient() {
    // Print the dates of the care period
    std::cout << "* Care period: ";
    print_dates();
    std::cout << std::endl;

    // Print the staff of the care period
    std::cout << "  - Staff: ";
    print_staff();
    std::cout << std::endl;
}

// Print the details of the care period for the staff, including dates and patient ID
void CarePeriod::print_care_period_for_staff() {
    // Print the dates of the care period
    print_dates();
    std::cout << std::endl;

    // Print the name of the patient
    std::cout << "* Patient: " << patient_id() << std::endl;
}

// Print the staff assigned to the care period
void CarePeriod::print_staff() {
    if (staff_.size() == 0) {
        std::cout << "None";
    } else {
        // Create a string of staff
        std::string staff_string = "";
        for (std::string staff_id : staff_) {
            staff_string += (staff_id + " ");
        }
        staff_string = staff_string.substr(0, staff_string.length()-1);

        // Print the string
        std::cout << staff_string;
    }
}

// Print the start and end dates of the care period. If closed, print end date.
void CarePeriod::print_dates() {
    // Print the start date
    start_.print();
    std::cout << " -";

    // If the care period is closed, print the end date
    if (is_closed()) {
        std::cout << " ";
        end_.print();
    }
}


