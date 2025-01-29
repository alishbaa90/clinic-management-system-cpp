#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_APPOINTMENTS = 100; // maximum number of appointments that can be stored
// appointment structure
struct Appointment
{
	string patientName;
	string patientaddress;
	string mobileNumber;
	bool pastHospitalVisit;
	string symptoms;
	string doctorName;
	string date;
	string time;
};
// doctor structure
struct Doctor
{
	string doctorName;
	string specialty;
};
// array to store doctor information
Doctor doctorinfo[4];
string doctorinformation(string x)
{
	string ans;
	doctorinfo[0].doctorName = "Alishba Siraj";
	doctorinfo[1].doctorName = "Hamza Altaf";
	doctorinfo[2].doctorName = "Nahin Fatima";
	doctorinfo[3].doctorName = "Abeeha Konain";
	doctorinfo[0].specialty = "Ophthalmologists";
	doctorinfo[1].specialty = "Orthopedic";
	doctorinfo[2].specialty = "Pediatrician";
	doctorinfo[3].specialty = "Dermatologist";
	for (int i = 0; i < 4; i++)
	{
		if (x == doctorinfo[i].doctorName)
		{
			ans = doctorinfo[i].specialty;
		}
	}
	return ans;
}
// array to store appointments
Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0; // current number of appointments
// function to book an appointment
void bookAppointment()
{
	if (appointmentCount >= MAX_APPOINTMENTS)
	{
		cout << "Sorry, no more appointments can be booked." << endl;
		return;
	}
	string answer;
	cout << "Enter Patient`s name: ";
	getline(cin, appointments[appointmentCount].patientName);
	getline(cin, appointments[appointmentCount].patientName);
	cout << "Enter Patient`s Address: ";
	getline(cin, appointments[appointmentCount].patientaddress);
	cout << "Enter Patient`s Mobile Number: ";
	cin >> appointments[appointmentCount].mobileNumber;
	cout << "Have you visited any past hospitals/clinics (yes(1)/no(0)): ";
	cin >> appointments[appointmentCount].pastHospitalVisit;
	answer = appointments[appointmentCount].pastHospitalVisit;
	if (answer == "yes")
	{
		appointments[appointmentCount].pastHospitalVisit = true;
	}
	else
	{
		appointments[appointmentCount].pastHospitalVisit = false;
	}
	cout << "What symptoms are you currently experiencing?: ";
	getline(cin, appointments[appointmentCount].symptoms);
	getline(cin, appointments[appointmentCount].symptoms);
	cout << "Enter Doctor`s name: ";
	getline(cin, appointments[appointmentCount].doctorName);
	cout << "Enter date (DD/MM/YYYY): ";
	getline(cin, appointments[appointmentCount].date);
	cout << "Enter time (HH:MM): ";
	getline(cin, appointments[appointmentCount].time);
	appointmentCount++;
	cout << "Appointment booked successfully." << endl;
}
// function to cancel an appointment
void cancelAppointment()
{
	string patientName;
	cout << "Enter Patient`s name: ";
	getline(cin, patientName);
	getline(cin, patientName);
	// search for the appointment
	int index = -1;
	for (int i = 0; i < appointmentCount; i++)
	{
		if (appointments[i].patientName == patientName)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		cout << "Appointment not found." << endl;
	}
	else
	{
		// remove the appointment by shifting the array
		for (int i = index; i < appointmentCount - 1; i++)
		{
			appointments[i] = appointments[i + 1];
		}
		appointmentCount--;
		cout << "Appointment cancelled successfully." << endl;
	}
}
// function to save appointments to a file
void saveAppointments()
{
	string s;
	ofstream file("appointments.txt");
	for (int i = 0; i < appointmentCount; i++)
	{
		s = doctorinformation(appointments[appointmentCount].doctorName);
		file << "Patient`s Name: " << appointments[i].patientName << "Doctor`s Name: " << appointments[i].doctorName << " Appointment`s Date : "
			<< appointments[i].date << " Appointment`s Time:" << appointments[i].time
			<< " Doctor`s Specialty: " << s << endl;
	}
	file.close();
}
// function to load appointments from a file
void loadAppointments()
{
	ifstream file("appointments.txt");
	appointmentCount = 0;
	while (file >> appointments[appointmentCount].patientName) {
		file >> appointments[appointmentCount].doctorName >>
			appointments[appointmentCount].date >> appointments[appointmentCount].time;
		appointmentCount++;
	}
	file.close();
}
// Generate bill
void Generatebill(Appointment appointments[MAX_APPOINTMENTS])
{
	string specialty =
		doctorinformation(appointments[appointmentCount].doctorName);
	cout << "Bill: " << endl;
	cout << "Patient`s Name: " << appointments[appointmentCount].patientName
		<< endl;
	cout << "Address: " << appointments[appointmentCount].patientaddress <<
		endl;
	cout << "Mobile Number: " << appointments[appointmentCount].mobileNumber
		<< endl;
	cout << "Doctor`s Name: " + appointments[appointmentCount].doctorName <<
		"Speciality of the doctor is: " << specialty << endl;
	cout << "Appointment Time: " + appointments[appointmentCount].time <<
		endl;
	cout << "Appointment Date: " + appointments[appointmentCount].date <<
		endl;
	cout << "Price: $150 \n" << "\t Get well soon =D \n";
}
int main() {
	int option;
	while (true)
	{
		cout << " Welcome To NHA's CLINICAL WEBSITE " << endl << endl;
			cout << "To book an Appointment,press \"1\"" << endl;
		cout << "To cancel an Appointment,press \"0\"" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			bookAppointment();
			saveAppointments();
			loadAppointments();
			Generatebill(appointments);
			break;
		case 0:
			cancelAppointment();
			loadAppointments();
			break;
		default:
			cout << "Invalid Input" << endl;
		}
		cout << "Thank you!";
		return 0;
	}
}