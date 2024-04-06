#include "hospital.hh"
#include "utils.hh"
#include <iostream>
#include <set>

Hospital::Hospital()
{
}

Hospital::~Hospital()
{
    // Deallocating staff
    for( std::map<std::string, Person*>::iterator
         iter = staff_.begin();
         iter != staff_.end();
         ++iter )
    {
        delete iter->second;
    }

    // Remember to deallocate patients also
}

void Hospital::set_date(Params params)
{
    std::string day = params.at(0);
    std::string month = params.at(1);
    std::string year = params.at(2);
    if( not utils::is_numeric(day, false) or
        not utils::is_numeric(month, false) or
        not utils::is_numeric(year, false) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    utils::today.set(stoi(day), stoi(month), stoi(year));
    std::cout << "Date has been set to ";
    utils::today.print();
    std::cout << std::endl;
}

void Hospital::advance_date(Params params)
{
    std::string amount = params.at(0);
    if( not utils::is_numeric(amount, true) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    utils::today.advance(stoi(amount));
    std::cout << "New date is ";
    utils::today.print();
    std::cout << std::endl;
}

void Hospital::recruit(Params params)
{
    std::string specialist_id = params.at(0);
    if( staff_.find(specialist_id) != staff_.end() )
    {
        std::cout << ALREADY_EXISTS << specialist_id << std::endl;
        return;
    }
    Person* new_specialist = new Person(specialist_id);
    staff_.insert({specialist_id, new_specialist});
    std::cout << STAFF_RECRUITED << std::endl;
}

void Hospital::print_all_staff(Params)
{
    if( staff_.empty() )
    {
        std::cout << "None" << std::endl;
        return;
    }
    for( std::map<std::string, Person*>::const_iterator iter = staff_.begin();
         iter != staff_.end();
         ++iter )
    {
        std::cout << iter->first << std::endl;
    }
}

void Hospital::add_medicine(Params params)
{
    std::string medicine = params.at(0);
    std::string strength = params.at(1);
    std::string dosage = params.at(2);
    std::string patient = params.at(3);
    if( not utils::is_numeric(strength, true) or
        not utils::is_numeric(dosage, true) )
    {
        std::cout << NOT_NUMERIC << std::endl;
        return;
    }
    std::map<std::string, Person*>::const_iterator
            patient_iter = current_patients_.find(patient);
    if( patient_iter == current_patients_.end() )
    {
        std::cout << CANT_FIND << patient << std::endl;
        return;
    }
    patient_iter->second->add_medicine(medicine, stoi(strength), stoi(dosage));
    std::cout << MEDICINE_ADDED << patient << std::endl;
}

void Hospital::remove_medicine(Params params)
{
    std::string medicine = params.at(0);
    std::string patient = params.at(1);
    std::map<std::string, Person*>::const_iterator
            patient_iter = current_patients_.find(patient);
    if( patient_iter == current_patients_.end() )
    {
        std::cout << CANT_FIND << patient << std::endl;
        return;
    }
    patient_iter->second->remove_medicine(medicine);
    std::cout << MEDICINE_REMOVED << patient << std::endl;
}

void Hospital::enter(Params params)
{
    // Add a new patient to the hospital
        std::string patient_id = params.at(0);
        // Check if the patient already exists
        if (current_patients_.find(patient_id) != current_patients_.end()) {
            std::cout << ALREADY_EXISTS << patient_id << std::endl;
            return;
        }

        // Create a new patient object
        Person* new_patient = nullptr;
        // Check if the patient is already in the database
        if (all_patients.find(patient_id) == all_patients.end()) {
            new_patient = new Person(patient_id);
            current_patients_.insert({patient_id, new_patient});
        } else {
            new_patient = all_patients.at(patient_id);
            current_patients_.insert({patient_id, new_patient});
        }

        // Add the patient to the all_patients map
        all_patients.insert({patient_id, new_patient});

        // Print confirmation message
        std::cout << PATIENT_ENTERED << std::endl;

        // Create a new care period for the patient
        std::shared_ptr<CarePeriod> new_period(new CarePeriod(utils::today, new_patient));

        // Add the care period to the care_periods map
        if (care_periods.find(patient_id) == care_periods.end()) {
            care_periods.insert({patient_id, {}});
            care_periods[patient_id].push_back(new_period);
        } else {
            care_periods[patient_id].push_back(new_period);
        }
}

void Hospital::leave(Params params)
{
    // Remove a patient from the hospital
        std::string patient_id = params.at(0);

        // Check if the patient exists
        if (current_patients_.find(patient_id) == current_patients_.end()) {
            std::cout << CANT_FIND << patient_id << std::endl;
            return;
        }

        // End the care period for the patient
        for (auto care_period : care_periods[patient_id]) {
            if (!care_period->is_closed()) {
                care_period->end_period(utils::today);
                break;
            }
        }

        // Remove the patient from the current_patients map
        current_patients_.erase(patient_id);

        // Print confirmation message
        std::cout << PATIENT_LEFT << std::endl;
}

void Hospital::assign_staff(Params params)
{
    // Assign a staff member to a patient
        std::string staff_id = params.at(0);
        std::string patient_id = params.at(1);

        // Check if the staff member exists
        if (staff_.find(staff_id) == staff_.end()) {
            std::cout << CANT_FIND << staff_id << std::endl;
            return;
        }

        // Check if the patient exists
        if (current_patients_.find(patient_id) == current_patients_.end()) {
            std::cout << CANT_FIND << patient_id << std::endl;
            return;
        }

        // Add the staff member to the patient's care period
        for (auto care_period : care_periods[patient_id]) {
            if (!care_period->is_closed()) {
                care_period->add_staff(staff_id);
                break;
            }
        }

        // Print confirmation message
        std::cout << STAFF_ASSIGNED << patient_id << std::endl;
}

void Hospital::print_patient_info(Params params)
{
    // Print information about a specific patient
        std::string patient_id = params.at(0);

        // Check if the patient exists
        if (all_patients.find(patient_id) == all_patients.end()) {
            std::cout << CANT_FIND << patient_id << std::endl;
            return;
        }

        // Print the care periods for the patient
        for (auto care_period : care_periods[patient_id]) {
            care_period->print_care_period_for_patient();
        }

        // Print the medicines prescribed to the patient
        std::cout << "* Medicines:";
        Person* patient = all_patients[patient_id];
        patient->print_medicines("  - ");
}

void Hospital::print_care_periods(Params params)
{
    // Print care periods for a specific staff member
        std::string staff_id = params.at(0);

        // Check if the staff member exists
        if (staff_.find(staff_id) == staff_.end()) {
            std::cout << CANT_FIND << staff_id << std::endl;
            return;
        }

        // Store the care periods assigned to the staff member
        std::vector<std::shared_ptr<CarePeriod>> care_periods_staff = {};

        // Iterate through all care periods to find those assigned to the staff member
        for (auto item : care_periods) {
            for (auto care_period : item.second) {
                if (care_period->check_staff(staff_id)) {
                    care_periods_staff.push_back(care_period);
                }
            }
        }

        // Print the care periods for the staff member
        if (care_periods_staff.size() == 0) {
            std::cout << "None" << std::endl;
        } else {
            std::sort(care_periods_staff.begin(), care_periods_staff.end(),
                      compare_CarePeriod_StartDates);
            for (auto care_period : care_periods_staff) {
                care_period->print_care_period_for_staff();
            }
        }
}

void Hospital::print_all_medicines(Params)
{
    // Print all medicines prescribed to patients
        std::map<std::string, std::set<std::string>> medicines_map = get_Medicines_Info();

        // Check if there are any medicines prescribed
        if (medicines_map.empty()) {
            std::cout << "None" << std::endl;
            return;
        }

        // Print each medicine and the patients prescribed with it
        for (auto iter : medicines_map) {
            std::cout << iter.first << " prescribed for" << std::endl;
            for (std::string patient_id : iter.second) {
                std::cout << "* " << patient_id << std::endl;
            }
        }
}

void Hospital::print_all_patients(Params)
{

}

void Hospital::print_current_patients(Params)
{

}
