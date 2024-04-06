/* Class CarePeriod
 * ----------
 * COMP.CS.110 SPRING 2024
 * ----------
 * Class for describing a patient's care period in hospital.
 *
 * Note: Students need to implement almost all of this class by themselves.
 *
 * This class defines a hospital stay for a patient.
 * It includes information such as the patient's details, start and end dates,
 * assigned staff, and the status of the stay (open or closed).
 * The Hospital class encapsulates a single stay of a patient in the hospital.
 * It holds essential information about the stay:
 * Patient details
 * start and end dates
 * List of assigned staff
 * Status of the stay (open or closed)
 *
 * Student: Pradip Neupane
 * Student number: 150426327
 * Email: pradip.neupane@tuni.fi
 * */





#ifndef CAREPERIOD_HH
#define CAREPERIOD_HH

#include "person.hh"
#include "date.hh"
#include <string>
#include <set>


class CarePeriod
{
public:
    /**
      * @brief CarePeriod
      * @param start date given as a string (ddmmyyyy)
      * @param patient whose care period will be created
      */
    CarePeriod(const std::string& start, Person* patient);

    /**
      * @brief CarePeriod
      * @param start date given as a Date object
      * @param patient whose care period will be created
      */
    CarePeriod(const Date& start, Person* patient);

    /**
      * @brief destructor
      */
    ~CarePeriod();

    // Accessor method to retrieve the patient's ID.
       std::string patient_id() const;

       // Accessor method to retrieve the start date of the care period.
       Date start_date() const;

       // Mark the end of the care period by providing the end date.
       void end_period(const Date& end);

       // Include a specialist to the care period staff.
       void add_staff(std::string staff_id);

       // Display details of the care period for the patient.
       void print_care_period_for_patient();

       // Display details of the care period for staff members.
       void print_care_period_for_staff();

       // Verify if the care period has been concluded.
       bool is_closed();

       // Confirm if a specific staff member is assigned to this care period.
       bool check_staff(std::string staff_id);

       // Display the start and possibly end dates of the care period.
       void print_dates();

       // Output the staff members assigned to the care period.
       void print_staff();

private:
    Person* patient_;
    Date start_;
    Date end_;

    // More attributes and methods
    // Container to store the assigned staff members.
    std::set<std::string> staff_;

    // Indicator for the closure status of the care period.
    bool is_closed_;

};

#endif // CAREPERIOD_HH
